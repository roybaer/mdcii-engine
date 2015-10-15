
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
#include "iteratoren.hpp"

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
  
  effekte_bsh[0] = new Bsh_leser(SGFX + "effekte.bsh");
  effekte_bsh[1] = new Bsh_leser(MGFX + "EFFEKTE.BSH");
  effekte_bsh[2] = new Bsh_leser(GFX + "EFFEKTE.BSH");
  
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
  
  soldat_bsh[0] = new Bsh_leser(SGFX + "soldat.bsh");
  soldat_bsh[1] = new Bsh_leser(MGFX + "SOLDAT.BSH");
  soldat_bsh[2] = new Bsh_leser(GFX + "SOLDAT.BSH");
  
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
  
  zei = new Zei_leser("TOOLGFX/ZEI16G.ZEI");
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
    case 1:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
    case 2:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos > 0)
	ypos--;
      break;
    case 3:
      if (xpos > 0)
	xpos--;
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
    case 1:
      if (xpos > 0)
	xpos--;
      if (ypos > 0)
	ypos--;
      break;
    case 2:
      if (xpos > 0)
	xpos--;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
    case 3:
      if (xpos < KARTENBREITE - 1)
	xpos++;
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
    case 1:
      if (xpos > 0)
	xpos--;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
    case 2:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
      break;
    case 3:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos > 0)
	ypos--;
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
    case 1:
      if (xpos < KARTENBREITE - 1)
	xpos++;
      if (ypos > 0)
	ypos--;
      break;
    case 2:
      if (xpos > 0)
	xpos--;
      if (ypos > 0)
	ypos--;
      break;
    case 3:
      if (xpos > 0)
	xpos--;
      if (ypos < KARTENHOEHE - 1)
	ypos++;
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

void Kamera::auf_bildschirm(Bildspeicher& bs, int karte_x, int karte_y, int& bildschirm_x, int& bildschirm_y)
{
  // Für Drehung 0
  bildschirm_x = bs.breite / 2 + ((karte_x - xpos) - (karte_y - ypos) - 1) * x_raster[vergroesserung];
  bildschirm_y = bs.hoehe / 2 + ((karte_x - xpos) + (karte_y - ypos)) * y_raster[vergroesserung];
}

void Kamera::auf_karte(Bildspeicher& bs, int bildschirm_x, int bildschirm_y, int& karte_x, int& karte_y)
{
  // Für Drehung 0
  int temp1 = (bildschirm_x - (int)bs.breite / 2) / x_raster[vergroesserung];
  int temp2 = (bildschirm_y - (int)bs.hoehe / 2) / y_raster[vergroesserung];
  int temp3 = (temp2 - temp1 + 1) / 2;
  karte_x = temp1 + temp3 + xpos;
  karte_y = temp3 + ypos;
}


void Kamera::zeichne_bild(Bildspeicher& bs, Welt& welt)
{
  switch (drehung)
  {
    case 0:
    {
      int karte_x, karte_y;
      auf_karte(bs, -x_raster[vergroesserung], -2 * y_raster[vergroesserung], karte_x, karte_y);
      int bildschirm_x, bildschirm_y;
      auf_bildschirm(bs, karte_x, karte_y, bildschirm_x, bildschirm_y);
      int felder_horizontal = bs.breite / x_raster[vergroesserung] / 2 + 2;
      int felder_vertikal = bs.hoehe / y_raster[vergroesserung] / 2 + 8;
      int start_y = bildschirm_y;
      for (int y = 0; y < felder_vertikal * 2; y++)
      {
	Nordoststreifen nos(welt, karte_x + (y & 1) + (y >> 1), karte_y + (y >> 1), felder_horizontal);
	int start_x = bildschirm_x + ((y & 1) ? x_raster[vergroesserung] : 0);
	for (inselfeld_t *feld : nos)
	{
	  feld_t feld2;
	  Insel::grafik_bebauung_inselfeld(feld2, *feld, 0);
	  if (feld2.index != -1)
	  {
	    Bsh_bild& bsh = stadtfld_bsh[vergroesserung]->gib_bsh_bild(feld2.index);
	    bs.zeichne_bsh_bild_oz(bsh, start_x, start_y - feld2.grundhoehe * grundhoehe[vergroesserung]);
	  }
	  start_x += 2 * x_raster[vergroesserung];
	}
	start_y += y_raster[vergroesserung];
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
	Bsh_bild& bsh = ship_bsh[vergroesserung]->gib_bsh_bild(index + schiff->richtung);  // FIXME
	int x_auf_karte = schiff->x_pos - xpos;
	int y_auf_karte = schiff->y_pos - ypos;
	bs.zeichne_bsh_bild_oz(bsh, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] + bs.hoehe / 2);
	Bsh_bild& flagge = ship_bsh[vergroesserung]->gib_bsh_bild(192 + (schiff->spieler - 1) * 8);
	bs.zeichne_bsh_bild_oz(flagge, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] + bs.hoehe / 2);
      }
      
      for (Soldat *soldat : welt.soldaten)
      {
	int index = 0;
	if (soldat->typ == 1)
	  index = 0;
	else if (soldat->typ == 2)
	  index = 280;
	else if (soldat->typ == 3)
	  index = 560;
	else if (soldat->typ == 4)
	  index = 840;
	else if (soldat->typ == 5)
	  index = 1120;
	else if (soldat->typ == 6)
	  index = 1424;
	else if (soldat->typ == 7)
	  index = 1728;
	else if (soldat->typ == 8)
	  index = 2032;
	else if (soldat->typ == 13)
	  index = 2336;
	else if (soldat->typ == 14)
	  index = 2552;
	else if (soldat->typ == 15)
	  index = 2768;
	else if (soldat->typ == 16)
	  index = 2984;
	else if (soldat->typ == 9)
	  index = 3200;
	else if (soldat->typ == 10)
	  index = 3336;
	else if (soldat->typ == 11)
	  index = 3472;
	else if (soldat->typ == 12)
	  index = 3608;
	else if (soldat->typ == 33)
	  index = 3744;
	Bsh_bild& bsh = soldat_bsh[vergroesserung]->gib_bsh_bild(index + soldat->richtung * 8);  // FIXME
	int x_auf_karte_mal_2 = soldat->x_pos_2 - 2 * xpos;
	int y_auf_karte_mal_2 = soldat->y_pos_2 - 2 * ypos;
	bs.zeichne_bsh_bild_oz(bsh, (x_auf_karte_mal_2 - y_auf_karte_mal_2 - 1) * (x_raster[vergroesserung] / 2) + bs.breite / 2, (x_auf_karte_mal_2 + y_auf_karte_mal_2) * (y_raster[vergroesserung] / 2) - grundhoehe[vergroesserung] + bs.hoehe / 2);
      }
      
      for (Prodlist *prod : welt.prodlist)
      {
	int x, y;
	auf_bildschirm(bs, prod->x_pos + welt.inseln[prod->inselnummer]->xpos, prod->y_pos + welt.inseln[prod->inselnummer]->ypos, x, y);
	if (! ((prod->modus & 1) != 0))
	{
	  Bsh_bild& bsh = effekte_bsh[vergroesserung]->gib_bsh_bild(350);
	  bs.zeichne_bsh_bild_oz(bsh, x, y - grundhoehe[vergroesserung]);
	}
	if ((prod->ani & 0x0f) == 0x0f)
	{
	  Bsh_bild& bsh = effekte_bsh[vergroesserung]->gib_bsh_bild(382);
	  bs.zeichne_bsh_bild_oz(bsh, x, y - grundhoehe[vergroesserung]);
	}
      }
      
      bs.setze_schriftfarbe(245, 0);
      bs.zeichne_string(*zei, "aktuelle Position:", 10, 10);
      bs.zeichne_string(*zei, "(" + std::to_string(xpos) + ", " + std::to_string(ypos) + ")", 10, 30);
      
    }
  }
}
