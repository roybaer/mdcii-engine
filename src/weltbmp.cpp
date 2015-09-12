
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

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>

#include <fstream>
#include <iostream>

#include "bsh_leser.hpp"
#include "bildspeicher.hpp"


//#include "stadtfld_bsh.hpp"
#include "insel.hpp"
#include "grafikinfo.hpp"
#include "welt.hpp"

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH
  
#define XRASTER 16
#define YRASTER 8
#define ELEVATION 10

#define KARTENBREITE 500
#define KARTENHOEHE 350


int main(int argc, char **argv)
{
  if (argc < 3)
    exit(EXIT_FAILURE);
  
  std::ifstream f;
  f.open(argv[1]);
  
  Welt welt = Welt(f);
  
  f.close();
  
  Bsh_leser *bsh_reader = new Bsh_leser("Mgfx/STADTFLD.BSH");
  
  Bildspeicher *fb = new Bildspeicher((KARTENBREITE + KARTENHOEHE) * XRASTER, (KARTENBREITE + KARTENHOEHE) * YRASTER, 1, 0);
  
  for (int y = 0; y < KARTENHOEHE; y++)
  {
    for (int x = 0; x < KARTENBREITE; x++)
    {
      Insel* insel = welt.insel_an_pos(x, y);
      feld_t feld;
      if (insel != NULL)
	insel->grafik_bebauung(&feld, x - insel->xpos, y - insel->ypos, 0);
      else
      {
	feld.index = meer.index + (y + x * 3) % 12;
	feld.grundhoehe = meer.grundhoehe;
      }
      /*feld_t feld2;
      insel->grafik_boden(&feld2, x, y, 0);*/
      if (feld.index != -1)
      {
	bsh_bild_t *bsh = bsh_reader->gib_bsh_bild(feld.index);
	uint16_t x_auf_karte = x /*- insel->breite / 2*/;
	uint16_t y_auf_karte = y /*- insel->hoehe / 2*/;
	fb->zeichne_bsh_bild(bsh, (x_auf_karte - y_auf_karte + KARTENHOEHE) * XRASTER, (x_auf_karte + y_auf_karte) * YRASTER + 2 * YRASTER - feld.grundhoehe * ELEVATION, 1);
      }
      /*else
        std::cout << insel->schicht2[y * insel->breite + x].bebauung << " ";*/
    }
  }
  
  fb->exportiere_bmp(argv[2]);
  delete fb;
  
  delete bsh_reader;
  
}
