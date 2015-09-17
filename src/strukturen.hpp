
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

#ifndef STRUKTUREN_HPP
#define STRUKTUREN_HPP

#include <inttypes.h>

extern char insel3_kennung[];
extern char insel5_kennung[];
extern char inselhaus_kennung[];
extern char hirsch2_kennung[];
extern char prodlist2_kennung[];
extern char werft_kennung[];
extern char militar_kennung[];
extern char siedler_kennung[];
extern char rohwachs2_kennung[];
extern char stadt4_kennung[];
extern char kontor2_kennung[];
extern char markt2_kennung[];
extern char player4_kennung[];
extern char auftrag2_kennung[];
extern char handler_kennung[];
extern char ship4_kennung[];
extern char soldat3_kennung[];
extern char turm_kennung[];
extern char timers_kennung[];
extern char wiff_kennung[];

struct Ware// 20 bytes
{
  uint8_t verkaufswert;
  uint8_t einkaufswert;
  uint16_t einheit;
  uint32_t unbekannt; // i.d.R. 0, einmal 0x80
  uint32_t lagerstand_soll;
  uint32_t lagerstand_ist;
  uint32_t ware; //0x6109 0x6509 0xe105 0xe705 0xe305 0xe905 0xdf05 0xf501 0x0902 0x0502 0x1102 0x0f02 0x3304 0x0d02 0xdd05 0xe505 0x0702 0xfb01 0xf901 0x1502 0x0302 0xd107 0x0102
} __attribute__((packed));



struct Insel3
{
  uint8_t inselnummer;  ///< Identifikationsnummer für diese Insel (pro Spiel)
  uint8_t breite;       ///< Breite der Insel in Feldern
  uint8_t hoehe;        ///< Höhe der Insel in Feldern
  uint8_t a;
  uint16_t x_pos;       ///< X-Position der Insel auf der Karte
  uint16_t y_pos;       ///< Y-Position der Insel auf der Karte
  uint16_t b;
  uint16_t c;
  uint8_t bytes1[28];
} __attribute__((packed));

struct Insel5
{
  uint8_t inselnummer;  ///< Identifikationsnummer für diese Insel (pro Spiel)
  uint8_t breite;       ///< Breite der Insel in Feldern
  uint8_t hoehe;        ///< Höhe der Insel in Feldern
  uint8_t a;
  uint16_t x_pos;       ///< X-Position der Insel auf der Karte
  uint16_t y_pos;       ///< Y-Position der Insel auf der Karte
  uint16_t b;
  uint16_t c;
  uint8_t bytes1[80];
  uint8_t fruchtbarkeit;   ///< Zeigt an, was auf dieser Insel wie gut wächst
  uint8_t d; // immer 0x11?
  uint16_t e;
  uint16_t basis;       ///< Nummer der Basisinsel (in ihrer Größenordnung)
  uint16_t f;
  uint8_t sued;         ///< 0x00 = nord, 0x01 = süd
  uint8_t diff;         ///< 0x00 = eigenständig, 0x01 = basiert auf "basis"
  uint8_t bytes2[14];
} __attribute__((packed));

struct Hirsch2 // 8 bytes
{
  uint8_t inselnummer;
  uint8_t x_pos;        ///< X-Position auf der Insel
  uint8_t y_pos;        ///< Y-Position auf der Insel
  uint8_t a; // 0x00
  uint32_t typ; // 0x00000561
};

struct Siedler // 16 bytes
{
  uint8_t inselnummer;  ///< Insel, auf der dieses Wohnhaus steht
  uint8_t x_pos;        ///< X-Position auf der Insel
  uint8_t y_pos;        ///< Y-Position auf der Insel
  uint8_t b; // 0x00 bis 0x07 ?
  uint8_t c; // 0x00 bis 0x07 ?
  uint8_t stufe;        ///< Entwicklungsstufe (0 bis 4)
  uint16_t nummer; //der Grafik? (eher nicht); 0x01 bis 0x06
  uint32_t flags;       ///< Zeigt den Zustand der Bewohner an und welche Bedürfnisse befriedigt werden
  uint32_t leer;
} __attribute__((packed));

struct Rohwachs // 8 bytes
{
  uint8_t inselnummer;  ///< Insel, auf der dieses Feld liegt
  uint8_t x_pos;        ///< X-Position auf der Insel
  uint8_t y_pos;        ///< Y-Position auf der Insel
  uint8_t schritt;      ///< Wachstumsschritt (sichtbar)
  uint32_t ani; //+Typ des Feldes?   0x01/0x07  0x00 bis 0x04   im szenario immer 0x00000000
} __attribute__((packed));

struct Prodlist // 24 bytes
{
  uint8_t inselnummer;      ///< Insel, auf der dieser Betrieb steht
  uint8_t x_pos;            ///< X-Position auf der Insel
  uint8_t y_pos;            ///< Y-Position auf der Insel
  uint8_t b; // 0x00
  uint8_t c; // 0x07, 0x05, 0x00 irgendetwas, pro prodlist konstant
  uint16_t produkt;         ///< Das von diesem Betrieb hergestellte Produkt
  uint8_t d; // 0x00
  uint16_t warteschritt; //? 0x00 bis 0x17
  uint16_t rohstoff2;       ///< Der zweite Rohstoff dieses Betriebes
  uint16_t rohstoff;        ///< Der erste Rohstoff dieses Betriebes
  uint8_t f; // 0x00
  uint8_t arbeitsschritt;
  uint32_t g; // 2 shorts, Auslastung
  uint8_t modus; // 0x00, 0x01, 0x05, 0x15, 0x2d, 0x35, 0x25, 0x19, 0x03, 0x11, 0x29, 0x21, 0x31, 0x39, 0x28
  uint8_t ani; // vermutlich auch Modus ? 0x00 bis 0x0f  Animationsschritt??? angezeigter Lagerstand???
  uint16_t h; // 0x0000
} __attribute__((packed));

struct Werft // 24 bytes
{
  uint8_t inselnummer;  ///< Insel, auf der die Werft steht
  uint8_t x_pos;        ///< X-Position auf der Insel
  uint8_t y_pos;        ///< Y-Position auf der Insel
  uint8_t a;
  uint32_t b; // 0x00ff0000
  uint32_t c; // short 0x0000 short rohstoff
  uint32_t d; // 0x0000ffff
  uint32_t e; // 0x00000000
  uint32_t f; // 0x00000000
} __attribute__((packed));

struct Militar // 112 bytes
{
  uint8_t inselnummer;
  uint8_t x_pos; //Vermutung
  uint8_t y_pos;
  uint8_t unbekannt[109];
} __attribute__((packed));

struct Stadt // 168 bytes
{
  uint8_t inselnummer;      ///< Insel, auf der die Stadt steht
  uint8_t spieler;          ///< Spieler, dem die Stadt gehört
  uint8_t a; // 0x00, 0x02, 0x06
  uint8_t b; // 0x00
  uint8_t unbekannt1[88];
  uint32_t einwohner[5];    ///< Anzahl der Einwohner mit entsprechender Entwicklungsstufe
  uint8_t unbekannt2[15];
  uint8_t steuersatz[5];    ///< Steuersatz für jede Entwicklungsstufe (jeweils zwischen 0x40 und 0xc0)
  uint8_t unbekannt3[3];
  char name[33];            ///< Name der Stadt
} __attribute__((packed));

struct Kontor // 1004 bytes
{
  uint8_t inselnummer;  ///< Insel, auf der dieses Kontor steht
  uint8_t x_pos;        ///< X-Position auf der Insel
  uint8_t y_pos;        ///< Y-Position auf der Insel
  uint8_t spieler;
  Ware waren[50]; // 23 Waren ab index 2
} __attribute__((packed));

struct Markt_intern // 16 bytes
{
  uint16_t a; //unbekannt
  uint16_t b; //0x0000, 0x0001, 0x0002, 0x0004 (im gleichen Markt kombinierbar)
  uint16_t c; //unbekannt
  uint16_t d; //0x0000
  uint32_t e; //0x00000000
  uint16_t f; //Ware: 0x3304 0x0d02 0xdd05 0xe505 0x0702 0xfb01 0xf901 0x1502 0x0302 0xd107 0x0102
  uint8_t g;  //0x00 oder 0x80, manchmal 0x66 oder 0x50
  uint8_t h;  //0x00
} __attribute__((packed));

struct Markt // 260 bytes
{
  uint8_t id; // fortlaufende nummerierung der marktplätze pro spieler
  uint8_t spieler;
  uint16_t a; // 0x0000
  Markt_intern unbekannt[16];
} __attribute__((packed));

struct Player // 1072 bytes
{
  int32_t kontostand;           ///< Kontostand dieses Spielers
  uint8_t b;
  uint8_t spieler;              ///< Spielernummer? (0 bis 3)
  uint8_t c;
  uint8_t farbe;                ///< Spielerfarbe? (0 bis 3)
  uint8_t unbekannt1[8];
  uint32_t a; // Anzahl besiegter Spieler?
  uint16_t soldaten_besiegt;    ///< Anzahl Soldaten, die dieser Spieler besiegt hat
  uint16_t soldaten_gefallen;   ///< Anzahl gefallener Soldaten
  uint16_t schiffe_gesunken;    ///< Anzahl gesunkener Schiffe
  uint16_t schiffe_versenkt;    ///< Anzahl Schiffe, die dieser Spieler versenkt hat
  uint8_t unbekannt2[28];
  uint16_t zufriedenheit;       ///< Zufriedenheit der Bevölkerung (Anzahl Denkmäler)
  uint8_t unbekannt3[902];
  char name[112];               ///< Name dieses Spielers
} __attribute__((packed));

struct Auftrag // 1684
{
  uint32_t spieler;     ///< Spieler, für den dieser Auftrag bestimmt ist
  char text[13][128];   ///< 13 Zeilen Text
  char padding[16];
};

struct Ware_handler
{
  uint32_t ware;        ///< Warenkennung
  uint32_t unbekannt1;  ///< Verkaufs- oder Einkaufspreis? (Vermutung)
  uint32_t unbekannt2;  ///< Verkaufs- oder Einkaufspreis? (Vermutung)
};

struct Handler // 604 bytes
{
  uint32_t unbekannt;
  uint32_t leer[5];
  Ware_handler waren[24];
  uint8_t leer2[292];
};

struct Handelsroute // 36 bytes
{
  uint8_t id; // 0x35, 0x36, 0x37
  uint8_t kontornummer;
  uint16_t a; // 0x0000
  uint16_t ware1;
  uint16_t menge1;
  uint16_t aktion1; // 0x0000 = einladen, 0x0001 = ausladen
  uint16_t b; // 0x0000
  uint16_t ware2;
  uint16_t menge2;
  uint16_t aktion2;
  uint8_t c[18]; // 0
} __attribute__((packed));

struct Ware_schiff
{
  uint16_t ware;        ///< Warenkennung
  uint16_t menge;
  uint32_t unbekannt; // 0
};

struct Ship // 436 bytes
{
  char name[28];        ///< Name des Schiffs, NULL-terminiert
  uint16_t x_pos;       ///< X-Position des Schiffs auf der Karte
  uint16_t y_pos;       ///< Y-Position des Schiffs auf der Karte
  uint32_t a[3]; // 0x00000000 0x00000000 0x00000000
  uint32_t kurs_start; // Y-Koordinate: Byte2[4:7]Byte3, X-Koordinate: Byte2[0:3]Byte4
  uint32_t kurs_ziel; // Byte1: 0x00 für stehen, 0x37 für fahren
  uint32_t kurs_aktuell;
  uint32_t b;
  uint16_t lp;          ///< Zustand (Lebenspunkte) des Schiffes
  uint16_t c; // 0x0000, 0x000c, 0x0010, 0x0011
  uint8_t d1; // 0, 1, 2, 3, 5, 6
  uint8_t d2; // 0x50
  uint8_t bewaffnung;   ///< Anzahl Kanonen
  uint8_t e; // 0x00, 0x02, 0x08, 0x0a
  uint32_t f;
  uint16_t typ;         ///< Schiffstyp
  uint8_t spieler;      ///< Spieler, dem das Schiff gehört, z.B. 0x01, 0x02, 0x05
  uint8_t g; // 0, 1, 2, 4
  uint8_t h1; // 0 bis 6
  uint8_t h2; // 0xff, 0x10, 0x0d, 0x01, 0x06, 0x0e, 0x0b, 0x11, 0x07, 0x0a
  uint8_t h3; // 0, selten 1
  uint8_t h4; // 0 bis 3
  uint16_t richtung;    ///< Gegenwärtige Fahrtrichtung (0 bis 7)
  
  // nach 82 bytes je 36 bytes pro eintrag
  
  Handelsroute handelsrouten[8];
  uint16_t j;
  Ware_schiff ladung[8];
} __attribute__((packed));

struct Soldat // 68 bytes
{
  uint16_t x_pos_2;     ///< X-Position auf der Karte in 1/2 Feldern
  uint16_t y_pos_2;     ///< Y-Position auf der Karte in 1/2 Feldern
  uint16_t lp;          ///< Zustand (Lebenspunkte) der Einheit, z.B. 0x0240, 0x0280, 0x01e0, 0x0180
  uint16_t typ;         ///< Typ und Uniformfarbe. 1-4: Infanterist, 5-8: Kavallerist, 9-12: Musketier, 13-16: Kanonier, 33: Eingeborener
  uint16_t id;          ///< ID (fortlaufend nummeriert)
  uint8_t kurs1[4]; // Byte1: 0x33, 0x34, 0x38
  uint16_t d; // 0x0000
  uint16_t e; // 0x0000
  uint8_t f; // 0x00
  uint8_t unbekannt1; // Nicht die Inselnummer
  uint8_t unbekannt2[4];
  uint8_t spieler;      ///< Spieler, dem die Einheit gehört (0 bis 3 bzw. 6 für Eingeborene)
  uint8_t h; // 1, 4, 5, 6, 7
  uint8_t i; // 0x2d (45)
  uint8_t richtung;     ///< Gegenwärtige Blickrichtung (0 bis 7)
  uint8_t leer1;
  uint8_t patrouille;   ///< Einheit ist auf Patrouille (0 = nein, 1 = ja)
  uint8_t kurs2[4];     ///< 4 Bytes Kurs
  uint8_t kurs3[4];     ///< 4 Bytes Kurs
  uint8_t leer[30];     ///< Füllbytes
};

struct Turm // 36 bytes
{
  uint16_t x_pos_global;    ///< X-Position des Turmes auf der Karte (?)
  uint16_t y_pos_global;    ///< Y-Position des Turmes auf der Karte (?)
  uint32_t c1; // 0x00260300 spiel-id?
  uint16_t id;              ///< Fortlaufende Nummerierung inkl. zerstörte Türme
  uint8_t c; // 0x33
  uint8_t inselnummer;      ///< Nummer der Insel, auf der der Turm steht
  uint8_t x_pos;            ///< X-Position des Turmes auf der Insel
  uint8_t y_pos;            ///< Y-Position des Turmes auf der Insel
  uint16_t d; // 0x0000
  uint32_t e; // 0x00000000
  uint16_t f; // 0x0000
  uint8_t g; // 0x06
  uint8_t inselnummer2;
  uint32_t spieler;         ///< Spieler, dem der Turm gehört
  uint32_t h; // 0x00000000
  uint32_t i; // 0x00000000
};

// struct Timer // (Vielfaches von) 4 bytes
// {
//   uint32_t a;
// };

#endif
