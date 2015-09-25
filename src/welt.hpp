
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

#ifndef WELT_HPP
#define WELT_HPP

#include <vector>
#include <fstream>
#include <inttypes.h>
#include "insel.hpp"
#include "block.hpp"
#include "strukturen.hpp"

class Welt
{
  int ani;
public:
  Insel* insel_an_pos(uint16_t x, uint16_t y);
  std::vector<Block *> bloecke;
  std::vector<Insel *> inseln;
  std::vector<Kontor *> kontore;
  std::vector<Ship *> schiffe;
  std::vector<Soldat *> soldaten;
  std::vector<Prodlist *> prodlist;
  Welt(std::istream& f);
  void simulationsschritt();
  void feld_an_pos(feld_t& feld, int x, int y);
};

#endif
