
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

#ifndef BILDSPEICHER_HPP
#define BILDSPEICHER_HPP

#include <inttypes.h>
#include "bsh_leser.hpp"

class Bildspeicher
{
  uint8_t *puffer;
  uint8_t puffer_freigeben;
  uint32_t pufferbreite;
  uint32_t format;
  uint32_t farbe;
  
  void zeichne_bsh_bild_ganz(bsh_bild_t *bild, int x, int y);
  void zeichne_bsh_bild_partiell(bsh_bild_t *bild, int x, int y);
public:
  uint32_t breite;
  uint32_t hoehe;
  
  Bildspeicher(uint32_t breite, uint32_t hoehe, uint32_t format = 1, uint32_t farbe = 0, uint8_t *puffer = NULL, uint32_t pufferbreite = 0);
  ~Bildspeicher();
  void zeichne_bsh_bild(bsh_bild_t *bild, int x, int y, int ausrichtung);
  void exportiere_pnm(const char *pfadname);
  void exportiere_bmp(const char *pfadname);
  void bild_loeschen();
};

#endif
