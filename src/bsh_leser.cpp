
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

#include <stdexcept>

#include "bsh_leser.hpp"
#include "block.hpp"

Bsh_leser::Bsh_leser(std::string pfadname)
{
  bsh = boost::iostreams::mapped_file_source(pfadname);
  
  // Ist die Datei groß genug für einen BSH-Header?
  if (bsh.size() < 20)
    throw std::range_error("bsh header too small");
  
  Block *bsh_header = (Block *)bsh.data();
  
  // Trägt der Header die Kennung "BSH"?
  if (strcmp(bsh_header->kennung, "BSH") != 0)
    throw std::invalid_argument("not a bsh file");
  
  // Ist die Datei groß genug?
  if (bsh.size() < bsh_header->laenge + 20)
    throw std::range_error("bsh structure exceeds end of file");
  
  // Enthält die Datei überhaupt Bilder?
  if (bsh_header->laenge < 4)
  {
    anzahl_bilder = 0;
    return;
  }
  
  bilderindex = (uint32_t *)(bsh.data() + 20);
  anzahl_bilder = bilderindex[0] / 4;
  
  // prüfe, ob der Indexblock groß genug ist
  if (bsh.size() < anzahl_bilder * 4 + 20)
    throw std::range_error("bsh index block exceeds end of file");
  
  // Der erste Indexeintrag gibt indirekt die Größe des Index an.
  for (uint32_t i = 1; i < anzahl_bilder; i++)
  {
    if (bilderindex[i] < bilderindex[0])
      throw std::logic_error("bsh: first index entry does not have smallest offset");
  }
  
  // Liegen alle Bilder innerhalb der Datei?
  const char *ptr = bsh.data();
  for (uint32_t i = 0; i < anzahl_bilder; i++)
  {
    uint32_t offs = bilderindex[i] + 20;
    if (offs + 16 > bsh.size() || offs + ((bsh_bild_t *) (ptr + offs))->laenge > bsh.size())
      throw std::range_error("picture exceeds end of file");
  }
  
  // prüfe Integrität der einzelnen Bilder
  for (uint32_t i = 0; i < anzahl_bilder; i++)
  {
    if (!ist_bild_fehlerfrei(i))
      throw std::logic_error("picture bytestream contains errors");
  }
}

bsh_bild_t *Bsh_leser::gib_bsh_bild(uint32_t index)
{
  if (index >= anzahl_bilder)
    throw std::range_error("index out of range");
  const char *ptr = bsh.data();
  uint32_t offs = bilderindex[index] + 20;
  return (bsh_bild_t *) (ptr + offs);
}

bool Bsh_leser::ist_bild_fehlerfrei(uint32_t index)
{
  bsh_bild_t *bild = gib_bsh_bild(index);
  
  if (bild->breite == 0 || bild->hoehe == 0)
    return false;
  
  uint8_t ch;
  int i = 0;
  int x = 0;
  int y = 0;
  
  while (i < bild->laenge - 16)
  {
    ch = bild->puffer[i++];
    
    if (ch == 0xff)
    {
      return true;
    }
    else if (ch == 0xfe)
    {
      x = 0;
      y++;
      if (y == bild->hoehe)
	return false;
    }
    else
    {
      x += ch;
      if (x > bild->breite)
	return false;
      
      if (i >= bild->laenge - 16)
	return false;
      ch = bild->puffer[i++];
      
      x += ch;
      if (x > bild->breite)
	return false;
      i += ch;
      if (i > bild->laenge - 16)
	return false;
    }
  }
  return false;
}

uint32_t Bsh_leser::anzahl()
{
  return anzahl_bilder;
}
