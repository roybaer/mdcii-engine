
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

#include "bsh_leser.hpp"
#include "bildspeicher.hpp"
#include <boost/format.hpp>

int main(int argc, char **argv)
{
  if (argc != 2)
    exit(EXIT_FAILURE);
  
  Bsh_leser bsh(argv[1]);
  for (uint32_t i = 0; i < bsh.anzahl(); i++)
  {
    bsh_bild_t *bild = bsh.gib_bsh_bild(i);
    Bildspeicher bs(bild->breite, bild->hoehe, 3, 0xff00ff);
    bs.bild_loeschen();
    bs.zeichne_bsh_bild(bild, 0, 0, 0);
    bs.exportiere_pnm(boost::str(boost::format("g_%04d.ppm") % i).c_str());
  }
}
