
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
#include "grafiken.hpp"

#define SGFX std::string("Sgfx/")
#define MGFX std::string("Mgfx/")
#define GFX std::string("Gfx/")

const int Kamera::x_raster[3] = {8, 16, 32};
const int Kamera::y_raster[3] = {4, 8, 16};
const int Kamera::grundhoehe[3] = {5, 10, 20};
  
Kamera::Kamera()
{
  xpos = Welt::KARTENBREITE / 2;
  ypos = Welt::KARTENHOEHE / 2;
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
  
  stadtfld_grafiken = new Grafiken("grafiken.txt");
}

void Kamera::gehe_zu(uint16_t x, uint16_t y)
{
  xpos = (x < 0) ? 0 : ((x >= Welt::KARTENBREITE) ? Welt::KARTENBREITE - 1 : x);
  ypos = (y < 0) ? 0 : ((y >= Welt::KARTENHOEHE) ? Welt::KARTENHOEHE - 1 : y);
}

void Kamera::nach_links()
{
  switch (drehung)
  {
    case 0:
      if (xpos > 0)
	xpos--;
      if (ypos < Welt::KARTENHOEHE - 1)
	ypos++;
      break;
    case 1:
      if (xpos < Welt::KARTENBREITE - 1)
	xpos++;
      if (ypos < Welt::KARTENHOEHE - 1)
	ypos++;
      break;
    case 2:
      if (xpos < Welt::KARTENBREITE - 1)
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
      if (xpos < Welt::KARTENBREITE - 1)
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
      if (ypos < Welt::KARTENHOEHE - 1)
	ypos++;
      break;
    case 3:
      if (xpos < Welt::KARTENBREITE - 1)
	xpos++;
      if (ypos < Welt::KARTENHOEHE - 1)
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
      if (ypos < Welt::KARTENHOEHE - 1)
	ypos++;
      break;
    case 2:
      if (xpos < Welt::KARTENBREITE - 1)
	xpos++;
      if (ypos < Welt::KARTENHOEHE - 1)
	ypos++;
      break;
    case 3:
      if (xpos < Welt::KARTENBREITE - 1)
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
      if (xpos < Welt::KARTENBREITE - 1)
	xpos++;
      if (ypos < Welt::KARTENHOEHE - 1)
	ypos++;
      break;
    case 1:
      if (xpos < Welt::KARTENBREITE - 1)
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
      if (ypos < Welt::KARTENHOEHE - 1)
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


void Kamera::zeichne_bild(Bildspeicher& bs, Welt& welt, int maus_x, int maus_y)
{
  Nordostiterator feld_unter_maus;
  
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
	for (Nordostiterator it = nos.begin(); it != nos.end(); ++it)
	{
	  inselfeld_t feld = *it;
	  feld_t feld2;
	  Insel::grafik_bebauung_inselfeld(feld2, feld, 0, *welt.bebauung, *stadtfld_grafiken);
	  if (feld2.index != -1)
	  {
	    Bsh_bild& bsh = stadtfld_bsh[vergroesserung]->gib_bsh_bild(feld2.index);
	    bool ist_unter_maus;
	    bs.zeichne_bsh_bild_sp_oz(bsh, start_x, start_y - feld2.grundhoehe * grundhoehe[vergroesserung], maus_x, maus_y, ist_unter_maus);
	    if (ist_unter_maus)
	    {
	      feld_unter_maus = it;
	    }
	  }
	  
	  Bebauungsinfo* info = welt.bebauung->info_zu(feld.bebauung);
	  if (info != nullptr)
	  {
	    int max_x = (((feld.rot & 1) == 0) ? info->breite : info->hoehe) - 1;
	    int max_y = (((feld.rot & 1) == 0) ? info->hoehe : info->breite) - 1;
	    if (info->kategorie == 4 && feld.x_pos == max_x && feld.y_pos == max_y)
	    {
	      int x = it.gib_x() - feld.x_pos;
	      int y = it.gib_y() - feld.y_pos;
	      int insel = welt.inselnummer_an_pos(x, y);
	      if (insel != -1)
	      {
		x -= welt.inseln[insel]->xpos;
		y -= welt.inseln[insel]->ypos;
		Prodlist* prod = welt.prodlist_an_pos(insel, x, y);
		if (prod != nullptr)
		{
		  int versatz = info->breite + info->hoehe;
		  versatz += versatz & 2;
		  if (! ((prod->modus & 1) != 0))  // Betrieb ist geschlossen
		  {
		    Bsh_bild& bsh = effekte_bsh[vergroesserung]->gib_bsh_bild(350);
		    bs.zeichne_bsh_bild_oz(bsh, start_x, start_y - versatz * y_raster[vergroesserung] - grundhoehe[vergroesserung]);
		  }
		  if ((prod->ani & 0x0f) == 0x0f)  // Betrieb hat Rohstoffmangel
		  {
		    Bsh_bild& bsh = effekte_bsh[vergroesserung]->gib_bsh_bild(382);
		    bs.zeichne_bsh_bild_oz(bsh, start_x, start_y - versatz * y_raster[vergroesserung] - grundhoehe[vergroesserung]);
		  }
		}
	      }
	    }
	  }
	  
	  start_x += 2 * x_raster[vergroesserung];
	}
	start_y += y_raster[vergroesserung];
      }
      
      for (Ship& schiff : welt.schiffe)
      {
	int index;
	switch (schiff.typ)
	{
	  case 0x15: index = 0;  break;  // kleines Handelsschiff
	  case 0x17: index = 32; break;  // großes Handelsschiff
	  case 0x1b: index = 48; break;  // großes Kriegsschiff
	  case 0x1d: index = 16; break;  // fliegender Händler
	  case 0x19: index = 64; break;  // kleines Kriegsschiff
	  case 0x25: index = 80; break;  // Piratenschiff (?)
	  default:   index = 0;
	}
	Bsh_bild& bsh = ship_bsh[vergroesserung]->gib_bsh_bild(index + schiff.richtung);  // FIXME
	int x_auf_karte = schiff.x_pos - xpos;
	int y_auf_karte = schiff.y_pos - ypos;
	bs.zeichne_bsh_bild_oz(bsh, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] + bs.hoehe / 2);
	if (schiff.spieler != 4)
	{
	  uint8_t nummer = (schiff.spieler < 4) ? welt.spielerfarbe(schiff.spieler) : schiff.spieler;
	  Bsh_bild& flagge = ship_bsh[vergroesserung]->gib_bsh_bild(192 + nummer * 8);
	  bs.zeichne_bsh_bild_oz(flagge, (x_auf_karte - y_auf_karte - 1) * x_raster[vergroesserung] + bs.breite / 2, (x_auf_karte + y_auf_karte) * y_raster[vergroesserung] + bs.hoehe / 2);
	}
      }
      
      for (Soldat& soldat : welt.soldaten)
      {
	int index;
	switch (soldat.typ)
	{
	  case 1:  index = 0;    break;  // Infanterist, rot
	  case 2:  index = 280;  break;  // Infanterist, blau
	  case 3:  index = 560;  break;  // Infanterist, gelb
	  case 4:  index = 840;  break;  // Infanterist, grau
	  case 5:  index = 1120; break;  // Kavallerist, rot
	  case 6:  index = 1424; break;  // Kavallerist, blau
	  case 7:  index = 1728; break;  // Kavallerist, gelb
	  case 8:  index = 2032; break;  // Kavallerist, grau
	  case 9:  index = 3200; break;  // Musketier, rot
	  case 10: index = 3336; break;  // Musketier, blau
	  case 11: index = 3472; break;  // Musketier, gelb
	  case 12: index = 3608; break;  // Musketier, grau
	  case 13: index = 2336; break;  // Kanonier, rot
	  case 14: index = 2552; break;  // Kanonier, blau
	  case 15: index = 2768; break;  // Kanonier, gelb
	  case 16: index = 2984; break;  // Kanonier, grau
	  case 33: index = 3744; break;  // Eingeborener
	  default: index = 0;
	}
	Bsh_bild& bsh = soldat_bsh[vergroesserung]->gib_bsh_bild(index + soldat.richtung * 8);  // FIXME
	int x_auf_karte_mal_2 = soldat.x_pos_2 - 2 * xpos;
	int y_auf_karte_mal_2 = soldat.y_pos_2 - 2 * ypos;
	bs.zeichne_bsh_bild_oz(bsh, (x_auf_karte_mal_2 - y_auf_karte_mal_2 - 1) * (x_raster[vergroesserung] / 2) + bs.breite / 2, (x_auf_karte_mal_2 + y_auf_karte_mal_2) * (y_raster[vergroesserung] / 2) - grundhoehe[vergroesserung] + bs.hoehe / 2);
      }
      
    }
  }
      
  bs.setze_schriftfarbe(245, 0);
  bs.zeichne_string(*zei, "aktuelle Position:", 10, 10);
  bs.zeichne_string(*zei, "(" + std::to_string(xpos) + ", " + std::to_string(ypos) + ")", 10, 30);
  Nordostiterator leer;
  if (feld_unter_maus != leer)
  {
    bs.zeichne_string(*zei, "Bebauung unter Mauszeiger:", 10, 60);
    bs.zeichne_string(*zei, std::to_string(feld_unter_maus->bebauung), 10, 80);
    bs.zeichne_string(*zei, "Position und Insel unter Mauszeiger:", 10, 110);
    bs.zeichne_string(*zei, "(" + std::to_string(feld_unter_maus.gib_x()) + ", " + std::to_string(feld_unter_maus.gib_y()) + ")  Insel " + std::to_string(welt.inselnummer_an_pos(feld_unter_maus.gib_x(), feld_unter_maus.gib_y())), 10, 130);
  }
}
