
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

#ifndef BSH_SCHREIBER_HPP
#define BSH_SCHREIBER_HPP

#include <cstdint>
#include <vector>
#include <fstream>
#include <string>

class Bsh_schreiber
{
  std::fstream bsh;
  int anzahl;
  int genutzt;
  int transp_farbe;
  uint32_t groesse;
  uint32_t* index;

public:
  Bsh_schreiber(std::string pfadname, int anzahl, int transp_farbe = 0);
  ~Bsh_schreiber();
  void schreib_bsh(uint8_t* bild, int breite, int hoehe, std::vector<uint8_t>& ziel);
  void lies_pgm(const char* pfadname, uint8_t*& bild, int& breite, int& hoehe);
  void pgm_anhaengen(const char* pfadname);

};

#endif
