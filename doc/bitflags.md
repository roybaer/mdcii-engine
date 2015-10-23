Bitflags
========

Bits im `flags`-Attribut der `Siedler`-Struktur
-----------------------------------------------

Noch einzuordnen sind:
- Gesundheit/Krankheit
- Nahrung
- Alkohol
- Tabakwaren
- Gewürze
- Kleidung
- Kakao
- Schmuck

Unbekannte benutzte Bits sind: 6, 8, 9, 11, 16, 17, 19

| Bit | Bedeutung         |
|----:|:------------------|
|   0 |                   |
|   1 |                   |
|   2 |                   |
|   3 |                   |
|   4 |                   |
|   5 |                   |
|   6 |                   |
|   7 | Stoffe            |
|   8 |                   |
|   9 |                   |
|  10 |                   |
|  11 |                   |
|  12 |                   |
|  13 |                   |
|  14 |                   |
|  15 |                   |
|  16 |                   |
|  17 |                   |
|  18 |                   |
|  19 |                   |
|  20 |                   |
|  21 | Zufrieden         |
|  22 | Markt             |
|  23 | Kirche/Kathedrale |
|  24 | Wirtshaus         |
|  25 | Badehaus          |
|  26 | Theater           |
|  27 |                   |
|  28 | Schule            |
|  29 | Hochschule        |
|  30 | Kapelle           |
|  31 | Arzt              |

Bits im `modus`-Attribut der `Prodlist`-Struktur
------------------------------------------------

- bit 0 = aktiv
- bit 6 = nicht abholen

Bits im `fruchtbarkeit`-Attribut der `Insel5`-Struktur
------------------------------------------------------

Die Bits geben an, was zu 100% statt zu 50% wächst.

| Bit | Bedeutung       |
|----:|:----------------|
|   0 | (immer 1)       |
|   1 | 100% Tabak      |
|   2 | 100% Gewürze    |
|   3 | 100% Zuckerrohr |
|   4 | 100% Baumwolle  |
|   5 | 100% Wein       |
|   6 | 100% Kakao      |
|   7 | (immer 1)       |

Bits im `freigeschaltet`-Attribut der `Player`-Struktur
-------------------------------------------------------

Ein gesetztes Bit bedeutet, dass die entsprechenden Gebäude gebaut werden können.

| Bit | Bedeutung
|----:|:------------------
|   0 | (ignoriert)
|   1 | (ignoriert)
|   2 | Schule
|   3 | Wirtshaus
|   4 | Kirche
|   5 | Badehaus
|   6 | Theater
|   7 | Hochschule
|   8 | Arzt
|   9 | Galgen
|  10 | Schloss
|  11 | Kathedrale
|  12 | (nichts)
|  13 | (nichts)
|  14 | Fleischerei, Rinderfarm
|  15 | Pflasterstraße, Steinbrücke, Steinbruch, Steinmetz, Feuerwehr
|  16 | Palisade, Holztor, Kontor II
|  17 | Tabakwarenladen, Rumbrennerei, Weingut, Weinstöcke, Zuckerrohrplantage, Zuckerrohrfeld, Tabakplantage, Tabakfeld, Gewürzplantage, Gewürzfeld
|  18 | Windmühle, Bäckerei, Getreidefarm, Getreidefeld
|  19 | Werkzeugschmiede
|  20 | Erzmine, Werft, Erzschmelze
|  21 | kleine Burg, Steinwall, Steintor, Wachturm, Stadttor, Platz I, Schwertschmiede
|  22 | Kontor III
|  23 | Goldmine
|  24 | Schneiderei, Weberei, Baumwollplantage, Baumwollfeld, Kakaoplantage, Kakaofeld
|  25 | (nichts)
|  26 | Kanonengießerei
|  27 | tiefe Erzmine
|  28 | Platz II, Platz III, Zierbaum, Goldschmiede, Kontor IV
|  29 | große Burg, Musketenbauer
|  30 | große Werft
|  31 | Festung
