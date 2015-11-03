
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

#ifndef ITERATOREN_HPP
#define ITERATOREN_HPP

#include <iterator>

class Nordostiterator : public std::iterator<std::forward_iterator_tag, inselfeld_t>
{
  Welt *welt;
  int x, y;
  inselfeld_t temp_feld;  // wird von den Methoden initialisiert, die es benutzen
  
public:
  Nordostiterator() : welt(nullptr), x(0), y(0) { }
  Nordostiterator(const Nordostiterator& it) : welt(it.welt), x(it.x), y(it.y) { }
  Nordostiterator(Welt& welt, int x, int y) : welt(&welt), x(x), y(y) { }
  Nordostiterator& operator=(const Nordostiterator it) { welt = it.welt; x = it.x; y = it.y; }
  void swap(Nordostiterator& it) { Nordostiterator temp = it; *this = it; it = temp; }
  Nordostiterator& operator++() { ++x; --y; return *this; }
  Nordostiterator operator++(int) { Nordostiterator temp(*this); operator++(); return temp; }
  bool operator==(const Nordostiterator& r) { return welt == r.welt && x == r.x && y == r.y; }
  bool operator!=(const Nordostiterator& r) { return welt != r.welt || x != r.x || y != r.y; }
  const inselfeld_t& operator*() { welt->feld_an_pos(temp_feld, x, y); return temp_feld; }
  const inselfeld_t* operator->() { return &**this; }
  
  int gib_x() { return x; }
  int gib_y() { return y; }
};

void swap(Nordostiterator& it1, Nordostiterator& it2)
{
  it1.swap(it2);
}

class Nordoststreifen
{
  Nordostiterator anfang, ende;
  
public:
  Nordoststreifen(Welt& welt, int x, int y, int laenge) : anfang(welt, x, y), ende(welt, x + laenge, y - laenge) { }
  Nordostiterator begin() { return anfang; }
  Nordostiterator end() { return ende; }
};

#endif
