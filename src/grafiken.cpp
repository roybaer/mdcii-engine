
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

#include <fstream>
#include <sstream>

#include "grafiken.hpp"

Grafiken::Grafiken(std::string dateiname)
{
  std::ifstream datei(dateiname.c_str());
  std::string zeile;
  while (datei.good())
  {
    std::getline(datei, zeile);
    std::stringstream ss(zeile, std::ios_base::in);
    uint16_t bebauung;
    uint32_t grafikindex;
    ss >> bebauung >> grafikindex;
    if (datei.good())
      index[bebauung] = grafikindex;
  }
}

int Grafiken::grafik_zu(uint16_t i)
{
  auto grafik = index.find(i);
  if (grafik != index.end())
    return grafik->second;
  else
    return -1;
}
