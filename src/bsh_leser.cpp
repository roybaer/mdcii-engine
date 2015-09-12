
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

Bsh_leser::Bsh_leser ( std::string pfadname )
{
  bsh = boost::iostreams::mapped_file_source(pfadname);
}

bsh_bild_t *Bsh_leser::gib_bsh_bild ( uint32_t index )
{
  const char *ptr = bsh.data();
  uint32_t offs = (((uint32_t *)ptr)[index + 5]) + 20; //FIXME
  if (offs + 16 >= bsh.size())
    return NULL;
  if (offs + 16 + ((bsh_bild_t *) (ptr + offs))->laenge >= bsh.size())
    return NULL;
  return (bsh_bild_t *) (ptr + offs);
}
