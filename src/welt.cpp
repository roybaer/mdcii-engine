
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
      inseln.push_back(new Insel(*i, *(i + 1), *bebauung));
      i++;
    }
    else if (strcmp((*i)->kennung, Kontor::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Kontor); j++)
	kontore.push_back((Kontor&)(*i)->daten[j * sizeof(Kontor)]);
    }
    else if (strcmp((*i)->kennung, Ship::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Ship); j++)
	schiffe.push_back((Ship&)(*i)->daten[j * sizeof(Ship)]);
    }
    else if (strcmp((*i)->kennung, Soldat::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Soldat); j++)
	soldaten.push_back((Soldat&)(*i)->daten[j * sizeof(Soldat)]);
    }
    else if (strcmp((*i)->kennung, Prodlist::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Prodlist); j++)
	prodlist.push_back((Prodlist&)(*i)->daten[j * sizeof(Prodlist)]);
    }
    else if (strcmp((*i)->kennung, Player::kennung) == 0)
    {
      for (int j = 0; j < (*i)->laenge / sizeof(Player); j++)
	spieler.push_back((Player&)(*i)->daten[j * sizeof(Player)]);
    }
    i++;
  }
}

int Welt::inselnummer_an_pos(uint16_t x, uint16_t y)
{
  for (int i = 0; i < inseln.size(); i++)
  {
    if ((x >= inseln[i]->xpos) && (y >= inseln[i]->ypos) && (x < inseln[i]->xpos + inseln[i]->breite) && (y < inseln[i]->ypos + inseln[i]->hoehe))
      return i;
  }
  return -1;
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
  for (Prodlist& prod : prodlist)
  {
    if (prod.modus & 1 && prod.rohstoff1_menge >= 16 && prod.produkt_menge < 320)
      inseln[prod.inselnummer]->animiere_gebaeude(prod.x_pos, prod.y_pos);
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
    feld.ani = (0x80000000 + y + x * 3 + ani) % 12; // (12 == ani_schritte des Meeres);
  }
}

Prodlist* Welt::prodlist_an_pos(uint8_t insel, uint8_t x, uint8_t y)
{
  // Provisorium! Muss viel effizienter werden!
  for (int i = 0; i < prodlist.size(); i++)
  {
    if (prodlist[i].inselnummer == insel && prodlist[i].x_pos == x && prodlist[i].y_pos == y)
      return &prodlist[i];
  }
  return nullptr;
}

uint8_t Welt::spielerfarbe(uint8_t spieler)
{
  return this->spieler[spieler].farbe;
}
