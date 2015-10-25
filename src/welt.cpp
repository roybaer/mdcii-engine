
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

#include <string.h>
#include "welt.hpp"

Welt::Welt(std::istream& f)
{
  bebauung = new Bebauung("bebauung.txt");
  
  while (!f.eof())
  {
    bloecke.push_back(new Block(f));
  }
  std::vector<Block *>::iterator i = bloecke.begin();
  while (i < bloecke.end())
  {
    if (strcmp((*i)->kennung, Insel5::kennung) == 0)
    {
      inseln.push_back(new Insel(*i, *(i + 1)));
      i++;
    }
    else if (strcmp((*i)->kennung, Kontor::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Kontor); j++)
	kontore.push_back(new Kontor((Kontor&)(*i)->daten[j * sizeof(Kontor)]));
    }
    else if (strcmp((*i)->kennung, Ship::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Ship); j++)
	schiffe.push_back(new Ship((Ship&)(*i)->daten[j * sizeof(Ship)]));
    }
    else if (strcmp((*i)->kennung, Soldat::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Soldat); j++)
	soldaten.push_back(new Soldat((Soldat&)(*i)->daten[j * sizeof(Soldat)]));
    }
    else if (strcmp((*i)->kennung, Prodlist::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Prodlist); j++)
	prodlist.push_back(new Prodlist((Prodlist&)(*i)->daten[j * sizeof(Prodlist)]));
    }
    else if (strcmp((*i)->kennung, Player::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Player); j++)
	spieler.push_back(new Player((Player&)(*i)->daten[j * sizeof(Player)]));
    }
    i++;
  }
}

Insel* Welt::insel_an_pos(uint16_t x, uint16_t y)
{
  for (Insel* insel : inseln)
  {
    if ((x >= insel->xpos) && (y >= insel->ypos) && (x < insel->xpos + insel->breite) && (y < insel->ypos + insel->hoehe))
      return insel;
  }
  return NULL;
}

void Welt::simulationsschritt()
{
  ani = (ani + 1) % 12;
  for (Insel *insel : inseln)
  {
    insel->bewege_wasser();
  }
  for (Prodlist *prod : prodlist)
  {
    if (prod->modus & 1 && prod->rohstoff1_menge >= 16 && prod->produkt_menge < 320)
      inseln[prod->inselnummer]->animiere_gebaeude(prod->x_pos, prod->y_pos);
  }
}

void Welt::feld_an_pos(inselfeld_t& feld, int x, int y)
{
  Insel* insel = insel_an_pos(x, y);
  if (insel != NULL)
    insel->inselfeld_bebauung(feld, x - insel->xpos, y - insel->ypos);
  else
  {
    memset(&feld, 0, sizeof(inselfeld_t));
    feld.bebauung = 1201;
    feld.ani = (0x80000000 + y + x * 3 + ani) % meer.ani_schritte;
  }
}
