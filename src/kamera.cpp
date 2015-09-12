
// This file is part of the MDCII Game Engine.
// Copyright (C) 2015  Benedikt Freisen
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

#include <string>
#include "kamera.hpp"

#define KARTENBREITE 500
#define KARTENHOEHE 350

#define SGFX std::string("Sgfx/")
#define MGFX std::string("Mgfx/")
#define GFX std::string("Gfx/")

const int Kamera::x_raster[3] = {8, 16, 32};
const int Kamera::y_raster[3] = {4, 8, 16};
const int Kamera::grundhoehe[3] = {5, 10, 20};
  
Kamera::Kamera()
{
  xpos = KARTENBREITE / 2;
  ypos = KARTENHOEHE / 2;
  drehung = 0;
  vergroesserung = 1;
  
//   effekte_bsh[0] = new Bsh_leser(SGFX + "effekte.bsh");
//   effekte_bsh[1] = new Bsh_leser(MGFX + "EFFEKTE.BSH");
//   effekte_bsh[2] = new Bsh_leser(GFX + "EFFEKTE.BSH");
//   
//   maeher_bsh[0] = new Bsh_leser(SGFX + "maeher.bsh");
//   maeher_bsh[1] = new Bsh_leser(MGFX + "MAEHER.BSH");
//   maeher_bsh[2] = new Bsh_leser(GFX + "MAEHER.BSH");
//   
//   numbers_bsh[0] = new Bsh_leser(SGFX + "numbers.bsh");
//   numbers_bsh[1] = new Bsh_leser(MGFX + "NUMBERS.BSH");
//   numbers_bsh[2] = new Bsh_leser(GFX + "NUMBERS.BSH");
  
  ship_bsh[0] = new Bsh_leser(SGFX + "ship.bsh");
  ship_bsh[1] = new Bsh_leser(MGFX + "SHIP.BSH");
  ship_bsh[2] = new Bsh_leser(GFX + "SHIP.BSH");
  
//   soldat_bsh[0] = new Bsh_leser(SGFX + "soldat.bsh");
//   soldat_bsh[1] = new Bsh_leser(MGFX + "SOLDAT.BSH");
//   soldat_bsh[2] = new Bsh_leser(GFX + "SOLDAT.BSH");
  
  stadtfld_bsh[0] = new Bsh_leser(SGFX + "stadtfld.bsh");
  stadtfld_bsh[1] = new Bsh_leser(MGFX + "STADTFLD.BSH");
  stadtfld_bsh[2] = new Bsh_leser(GFX + "STADTFLD.BSH");
  
//   tiere_bsh[0] = new Bsh_leser(SGFX + "tiere.bsh");
//   tiere_bsh[1] = new Bsh_leser(MGFX + "TIERE.BSH");
//   tiere_bsh[2] = new Bsh_leser(GFX + "TIERE.BSH");
//   
//   traeger_bsh[0] = new Bsh_leser(SGFX + "traeger.bsh");
//   traeger_bsh[1] = new Bsh_leser(MGFX + "TRAEGER.BSH");
//   traeger_bsh[2] = new Bsh_leser(GFX + "TRAEGER.BSH");
}

void Kamera::gehe_zu(uint16_t x, uint16_t y)
{
  xpos = (x < 0) ? 0 : ((x >= KARTENBREITE) ? KARTENBREITE - 1 : x);
  ypos = (y < 0) ? 0 : ((y >= KARTENHOEHE) ? KARTENHOEHE - 1 : y);
}

void Kamera::nach_links()
{
  switch (drehung)
  {
    case 0:
      if (xpos > 0)
	xpos--;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
    case 2:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos > 0)
	ypos--;
      break;
  }
}

void Kamera::nach_rechts()
{
  switch (drehung)
  {
    case 0:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos > 0)
	ypos--;
      break;
    case 2:
      if (xpos > 0)
	xpos--;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
  }
}

void Kamera::nach_oben()
{
  switch (drehung)
  {
    case 0:
      if (xpos > 0)
	xpos--;
      if (ypos > 0)
	ypos--;
      break;
    case 2:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
  }
}

void Kamera::nach_unten()
{
  switch (drehung)
  {
    case 0:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
    case 2:
      if (xpos > 0)
	xpos--;
      if (ypos > 0)
	ypos--;
      break;
  }
}

void Kamera::vergroessern()
{
  if (vergroesserung < 2)
    vergroesserung++;
}

void Kamera::verkleinern()
{
  if (vergroesserung > 0)
    vergroesserung--;
}

void Kamera::setze_vergroesserung(uint8_t vergroesserung)
{
  this->vergroesserung = vergroesserung;
}

void Kamera::links_drehen()
{
  drehung = (drehung + 3) % 4;
}

void Kamera::rechts_drehen()
{
  drehung = (drehung + 1) % 4;
}


void Kamera::zeichne_bild(Bildspeicher& bs, Welt& welt)
{
  switch (drehung)
  {
    case 0:
    {
      int radius = bs.breite / x_raster[vergroesserung] / 2 + bs.hoehe / y_raster[vergroesserung] / 2;
      for (int y = ypos - radius; y < ypos + radius; y++)
      {
	for (int x = xpos - radius; x < xpos + radius; x++)
	{
	  feld_t feld;
	  welt.feld_an_pos(feld, x, y);
	  /*feld_t feld2;
	  insel->grafik_boden(&feld2, x, y, 0);*/
	  if (feld.index != -1)
	  {
	    bsh_bild_t *bsh = stadtfld_bsh[vergroesserung]->gib_bsh_bild(feld.index);
	    int x_auf_karte = x - xpos;
	    int y_auf_karte = y - ypos;
	    bs.zeichne_bsh_bild(bsh, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] - feld.grundhoehe * grundhoehe[vergroesserung] + bs.hoehe / 2, 1);
	  }
	  /*else
	    std::cout << insel->schicht2[y * insel->breite + x].bebauung << " ";*/
	}
      }
      
      for (Ship *schiff : welt.schiffe)
      {
	int index = 0;
	if (schiff->typ == 0x15)
	  index = 0;
	if (schiff->typ == 0x1b)
	  index = 48;
	if (schiff->typ == 0x1d)
	  index = 32;
	if (schiff->typ == 0x19)
	  index = 64;
	if (schiff->typ == 0x25)
	  index = 80;
	bsh_bild_t *bsh = ship_bsh[vergroesserung]->gib_bsh_bild(index + schiff->richtung);  // FIXME
	int x_auf_karte = schiff->x_pos - xpos;
	int y_auf_karte = schiff->y_pos - ypos;
	bs.zeichne_bsh_bild(bsh, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] + bs.hoehe / 2, 1);
	bsh_bild_t *flagge = ship_bsh[vergroesserung]->gib_bsh_bild(192 + (schiff->spieler - 1) * 8);
	bs.zeichne_bsh_bild(flagge, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] + bs.hoehe / 2, 1);
      }
      
    }
  }
}
