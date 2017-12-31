
// This file is part of the MDCII Game Engine.
// Copyright (C) 2017  Benedikt Freisen
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#include "bsh_schreiber.hpp"

using namespace std;

istream& operator>>(istream& is, const char* str)
{
  string temp;
  is >> temp;
  if (temp != str)
    throw new istream::failure("unexpected string constant in input");
  return is;
}

Bsh_schreiber::Bsh_schreiber(string pfadname, int anzahl, int transp_farbe, int extra_spalten, bool ist_zei)
{
  bsh.open(pfadname.c_str(), fstream::in | fstream::out | fstream::trunc);
  this->anzahl = anzahl;
  this->transp_farbe = transp_farbe;
  this->extra_spalten = extra_spalten;
  genutzt = 0;
  char signatur_bsh[16] = {'B', 'S', 'H', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
  char signatur_zei[16] = {'Z', 'E', 'I', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
  if (ist_zei)
    bsh.write(signatur_zei, sizeof(signatur_zei));
  else
    bsh.write(signatur_bsh, sizeof(signatur_bsh));
  groesse = anzahl * sizeof(uint32_t);
  bsh.write(reinterpret_cast<char*>(&groesse), sizeof(groesse));
  index = new uint32_t[anzahl];
  for (int i = 0; i < anzahl; i++)
    index[i] = 0;
  bsh.write(reinterpret_cast<char*>(index), anzahl * sizeof(uint32_t));
}

Bsh_schreiber::~Bsh_schreiber()
{
  delete[] index;
  bsh.close();
}

enum zustand_t
{
  TRANSPARENT,
  PIXEL,
};

#define ist_transparent(a) ((a) == transp_farbe)

void Bsh_schreiber::schreib_bsh(uint8_t* bild, int breite, int hoehe, vector<uint8_t>& ziel)
{
  int tz = 0;
  int zz = 0;
  int pixel_index = 0;
  zustand_t zustand = TRANSPARENT;

  for (int y = 0; y < hoehe; y++)
  {
    for (int x = 0; x < breite; x++)
    {
      if (zustand == TRANSPARENT)
      {
	if (x == 0 && y != 0)
	{
	  zz++;
	  tz = 0;
	}
	if (ist_transparent(bild[y * breite + x]))
	{
	  tz++;
	}
	else
	{
	  for (int i = 0; i < zz; i++)
	  {
	    ziel.push_back(0xfe);
	  }
	  zz = 0;
	  while (tz > 253)
	  {
	    ziel.push_back(253);
	    ziel.push_back(0);
	    tz -= 253;
	  }
	  ziel.push_back(tz);
	  tz = 1;
	  pixel_index = y * breite + x;
	  zustand = PIXEL;
	}
      }
      else
      {
	if (x == 0 || ist_transparent(bild[y * breite + x]))
	{
	  // tz Pixel ausgeben
	  while (tz > 253)
	  {
	    ziel.push_back(253);
	    for (int i = 0; i < 253; i++)
	    {
	      ziel.push_back(bild[pixel_index]);
	      pixel_index++;
	    }
	    ziel.push_back(0);
	    tz -= 253;
	  }
	  ziel.push_back(tz);
	  for (int i = 0; i < tz; i++)
	  {
	    ziel.push_back(bild[pixel_index]);
	    pixel_index++;
	  }
	  tz = 1;
	  if (x == 0 && !ist_transparent(bild[y * breite + x]))
	  {
	    ziel.push_back(0xfe);
	    ziel.push_back(0);
	  }
	  else
	    if (ist_transparent(bild[y * breite + x]))
	    {
	      zustand = TRANSPARENT;
	    }
	}
	else
	{
	  tz++;
	}
      }
    }
  }
  if (zustand == PIXEL)
  {
    // tz Pixel ausgeben
    while (tz > 253)
    {
      ziel.push_back(253);
      for (int i = 0; i < 253; i++)
      {
	ziel.push_back(bild[pixel_index]);
	pixel_index++;
      }
      ziel.push_back(0);
      tz -= 253;
    }
    ziel.push_back(tz);
    for (int i = 0; i < tz; i++)
    {
      ziel.push_back(bild[pixel_index]);
      pixel_index++;
    }
  }
  ziel.push_back(0xff);
}

void Bsh_schreiber::lies_pgm(const char* pfadname, uint8_t*& bild, int& breite, int& hoehe)
{
  ifstream pgm;
  pgm.open(pfadname);
  pgm.unsetf(ios::skipws);
  pgm >> "P5";
  pgm.setf(ios::skipws);
  pgm >> breite >> hoehe >> "255";
  pgm.get();
  bild = new uint8_t[breite * hoehe];
  pgm.read(reinterpret_cast<char*>(bild), breite * hoehe);
  pgm.close();
}

void Bsh_schreiber::pgm_anhaengen(const char* pfadname)
{
  int breite, hoehe;
  uint8_t* bild;
  lies_pgm(pfadname, bild, breite, hoehe);
  vector<uint8_t> ziel;
  schreib_bsh(bild, breite, hoehe, ziel);
  delete[] bild;
  while (ziel.size() % 4 != 0)
    ziel.push_back(0);
  bsh.seekp(0, ios::end);
  int versatz = (int)bsh.tellp() - 20;
  int typ = 1;
  int laenge = ziel.size() + 16;
  int angegebene_breite = breite - extra_spalten;
  if (angegebene_breite <  1)
    angegebene_breite = 1;
  bsh.write(reinterpret_cast<char*>(&angegebene_breite), sizeof(angegebene_breite));
  bsh.write(reinterpret_cast<char*>(&hoehe), sizeof(hoehe));
  bsh.write(reinterpret_cast<char*>(&typ), sizeof(typ));
  bsh.write(reinterpret_cast<char*>(&laenge), sizeof(laenge));
  bsh.write(reinterpret_cast<char*>(ziel.data()), ziel.size());
  int blockgroesse = (int)bsh.tellp() - 20;
  bsh.seekp(genutzt * 4 + 20);
  bsh.write(reinterpret_cast<char*>(&versatz), sizeof(versatz));
  bsh.seekp(16);
  bsh.write(reinterpret_cast<char*>(&blockgroesse), sizeof(blockgroesse));
  genutzt++;
}
