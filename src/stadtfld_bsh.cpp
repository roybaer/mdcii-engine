
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

#include "stadtfld_bsh.hpp"

g_t gras0_gruen = {4, 1, 1, 4, 1, 1, 0};
g_t gras1_gruen = {8, 1, 1, 4, 1, 1, 0};
g_t gras2_gruen = {4, 1, 1, 4, 1, 1, 0};
g_t gras3_gruen = {4, 1, 1, 4, 1, 1, 0};
g_t gras4_gruen = {12, 1, 1, 4, 1, 1, 0};
g_t gras5_gruen = {12, 1, 1, 4, 1, 1, 0};
g_t sand0 = {16, 1, 1, 4, 1, 1, 0};

g_t gras0 = {80, 1, 1, 4, 1, 1, 0};
g_t gras1 = {84, 1, 1, 4, 1, 1, 0};
g_t gras2 = {88, 1, 1, 4, 1, 1, 0};
g_t gras3 = {92, 1, 1, 4, 1, 1, 0};
g_t gras4 = {96, 1, 1, 4, 1, 1, 0};
g_t gras5 = {100, 1, 1, 4, 1, 1, 0};
g_t gras6 = {104, 1, 1, 4, 1, 1, 0};
g_t gras7 = {108, 1, 1, 4, 1, 1, 0};
g_t gras8 = {112, 1, 1, 4, 1, 1, 0};
g_t gras9 = {116, 1, 1, 4, 1, 1, 0};

g_t gras0b = {120, 1, 1, 4, 1, 1, 0};
g_t gras1b = {124, 1, 1, 4, 1, 1, 0};
g_t gras2b = {128, 1, 1, 4, 1, 1, 0};
g_t gras3b = {132, 1, 1, 4, 1, 1, 0};
g_t gras4b = {136, 1, 1, 4, 1, 1, 0};
g_t gras5b = {140, 1, 1, 4, 1, 1, 0};
g_t gras6b = {144, 1, 1, 4, 1, 1, 0};
g_t gras7b = {148, 1, 1, 4, 1, 1, 0};
g_t gras8b = {152, 1, 1, 4, 1, 1, 0};
g_t gras9b = {156, 1, 1, 4, 1, 1, 0};

g_t pflanzen0b = {160, 1, 1, 4, 1, 1, 0};
g_t pflanzen1b = {164, 1, 1, 4, 1, 1, 0};
g_t pflanzen2b = {168, 1, 1, 4, 1, 1, 0};
g_t pflanzen3b = {172, 1, 1, 4, 1, 1, 0};
g_t pflanzen4b = {176, 1, 1, 4, 1, 1, 0};
g_t pflanzen5b = {180, 1, 1, 4, 1, 1, 0};
g_t pflanzen6b = {184, 1, 1, 4, 1, 1, 0};
g_t pflanzen7b = {188, 1, 1, 4, 1, 1, 0};
g_t pflanzen8b = {192, 1, 1, 4, 1, 1, 0};
g_t pflanzen9b = {196, 1, 1, 4, 1, 1, 0};

g_t pflanzen0 = {200, 1, 1, 4, 1, 1, 0};
g_t pflanzen1 = {204, 1, 1, 4, 1, 1, 0};
g_t pflanzen2 = {208, 1, 1, 4, 1, 1, 0};
g_t pflanzen3 = {212, 1, 1, 4, 1, 1, 0};
g_t pflanzen4 = {216, 1, 1, 4, 1, 1, 0};
g_t pflanzen5 = {220, 1, 1, 4, 1, 1, 0};
g_t pflanzen6 = {224, 1, 1, 4, 1, 1, 0};
g_t pflanzen7 = {228, 1, 1, 4, 1, 1, 0};
g_t pflanzen8 = {232, 1, 1, 4, 1, 1, 0};
g_t pflanzen9 = {236, 1, 1, 4, 1, 1, 0};

g_t wueste0 = {280, 1, 1, 4, 1, 1, 0};
g_t wueste1 = {284, 1, 1, 4, 1, 1, 0};
g_t wueste2 = {288, 1, 1, 4, 1, 1, 0};
g_t wueste3 = {292, 1, 1, 4, 1, 1, 0};
g_t wueste4 = {296, 1, 1, 4, 1, 1, 0};
g_t wueste5 = {300, 1, 1, 4, 1, 1, 0};
g_t wueste6 = {304, 1, 1, 4, 1, 1, 0};
g_t wueste7 = {308, 1, 1, 4, 1, 1, 0};
g_t wueste8 = {312, 1, 1, 4, 1, 1, 0};
g_t wueste9 = {316, 1, 1, 4, 1, 1, 0};

g_t gras0_braun = {320, 1, 1, 4, 1, 1, 0};
g_t gras1_braun = {324, 1, 1, 4, 1, 1, 0};
g_t gras2_braun = {328, 1, 1, 4, 1, 1, 0};
g_t gras3_braun = {332, 1, 1, 4, 1, 1, 0};
g_t gras4_braun = {336, 1, 1, 4, 1, 1, 0};
g_t gras5_braun = {340, 1, 1, 4, 1, 1, 0};
g_t gras6_braun = {344, 1, 1, 4, 1, 1, 0};
g_t gras7_braun = {348, 1, 1, 4, 1, 1, 0};
g_t gras8_braun = {352, 1, 1, 4, 1, 1, 0};
g_t gras9_braun = {356, 1, 1, 4, 1, 1, 0};


g_t truemmer0 = {400, 1, 1, 1, 1, 1, 0};
g_t truemmer1 = {401, 1, 1, 1, 1, 1, 0};
g_t truemmer2 = {402, 1, 1, 1, 1, 1, 0};
g_t truemmer3 = {403, 1, 1, 1, 1, 1, 0};
g_t truemmer4 = {404, 1, 1, 1, 1, 1, 0};
g_t truemmer5 = {405, 1, 1, 1, 1, 1, 0};
g_t truemmer6 = {406, 1, 1, 1, 1, 1, 0};
g_t truemmer7 = {407, 1, 1, 1, 1, 1, 0};
g_t truemmer8 = {408, 1, 1, 1, 1, 1, 0};
g_t truemmer9 = {409, 1, 1, 1, 1, 1, 0};
g_t truemmer10 = {410, 1, 1, 1, 1, 1, 0};
g_t truemmer11 = {411, 1, 1, 1, 1, 1, 0};

g_t truemmer0_kueste = {412, 1, 1, 1, 1, 0, 0};
g_t truemmer1_kueste = {413, 1, 1, 1, 1, 0, 0};


g_t wegreste0 = {426, 1, 1, 1, 1, 1, 0};
g_t wegreste1 = {427, 1, 1, 1, 1, 1, 0};
g_t wegreste2 = {428, 1, 1, 1, 1, 1, 0};
g_t wegreste3 = {429, 1, 1, 1, 1, 1, 0};
g_t wegreste4 = {430, 1, 1, 1, 1, 1, 0};
g_t wegreste5 = {431, 1, 1, 1, 1, 1, 0};


g_t hang0 = {432, 1, 1, 4, 1, 1, 1};
g_t hang1 = {436, 1, 1, 4, 1, 1, 1};
g_t hang2 = {440, 1, 1, 4, 1, 1, 1};
g_t hang3 = {444, 1, 1, 4, 1, 1, 1};
g_t hang4 = {448, 1, 1, 4, 1, 1, 1};
g_t hang5 = {452, 1, 1, 4, 1, 1, 1};
g_t hang6 = {456, 1, 1, 4, 1, 1, 1};
g_t hang7 = {460, 1, 1, 4, 1, 1, 1};
g_t hang8 = {464, 1, 1, 4, 1, 1, 1};
g_t hang9 = {468, 1, 1, 4, 1, 1, 1};

g_t hang0_1_4 = {472, 1, 1, 4, 1, 1, 1};
g_t hang1_1_4 = {476, 1, 1, 4, 1, 1, 1};

g_t hang0_3_4 = {512, 1, 1, 4, 1, 1, 1};
g_t hang1_3_4 = {516, 1, 1, 4, 1, 1, 1};

g_t quelle = {552, 1, 1, 4, 6, 1, 1};
g_t felshang0 = {576, 1, 1, 4, 1, 1, 1};
g_t felshang1 = {580, 1, 1, 4, 1, 1, 1};

g_t weizenfeld = {584, 1, 1, 1, 6, 1, 0};
g_t weizenfeld_fertig = {589, 1, 1, 1, 1, 1, 0};
g_t baumwollfeld = {590, 1, 1, 1, 6, 1, 0};
g_t baumwollfeld_fertig = {595, 1, 1, 1, 1, 1, 0};
g_t grasfeld = {596, 1, 1, 1, 6, 1, 0};
g_t grasfeld_fertig = {601, 1, 1, 1, 1, 1, 0};
g_t tabakfeld = {602, 1, 1, 1, 6, 1, 0};
g_t tabakfeld_fertig = {607, 1, 1, 1, 1, 1, 0};
g_t kakaofeld = {608, 1, 1, 1, 6, 1, 0};
g_t kakaofeld_fertig = {613, 1, 1, 1, 1, 1, 0};
g_t zuckerrohrfeld = {614, 1, 1, 1, 6, 1, 0};
g_t zuckerrohrfeld_fertig = {619, 1, 1, 1, 1, 1, 0};
g_t gewuerzfeld = {620, 1, 1, 1, 6, 1, 0};
g_t gewuerzfeld_fertig = {625, 1, 1, 1, 1, 1, 0};
g_t weinfeld = {626, 1, 1, 1, 6, 1, 0};
g_t weinfeld_fertig = {631, 1, 1, 1, 1, 1, 0};

g_t weizenfeld_trocken = {632, 1, 1, 1, 6, 1, 0};
g_t baumwollfeld_trocken = {638, 1, 1, 1, 6, 1, 0};
g_t grasfeld_trocken = {644, 1, 1, 1, 6, 1, 0};
g_t tabakfeld_trocken = {650, 1, 1, 1, 6, 1, 0};
g_t kakaofeld_trocken = {656, 1, 1, 1, 6, 1, 0};
g_t zuckerrohrfeld_trocken = {662, 1, 1, 1, 6, 1, 0};
g_t gewuerzfeld_trocken = {668, 1, 1, 1, 6, 1, 0};
g_t weinfeld_trocken = {674, 1, 1, 1, 6, 1, 0};

g_t verbranntes_feld0 = {664, 1, 1, 4, 1, 1, 0};
g_t verbranntes_feld1 = {669, 1, 1, 4, 1, 1, 0};

g_t meer_flach = {680, 1, 1, 1, 12, 0, 0};
g_t meer_flach_fischgruende = {692, 1, 1, 4, 12, 0, 0};
g_t fischgruende = {740, 1, 1, 1, 12, 0, 0};
g_t meer = {752, 1, 1, 1, 12, 0, 0};
g_t fischgruende_meer = {764, 1, 1, 4, 12, 0, 0};

g_t strand0_1_2 = {812, 1, 1, 4, 6, 0, 0};
g_t strand0_3_4 = {836, 1, 1, 4, 6, 0, 0};
g_t strand0_1_4 = {860, 1, 1, 4, 6, 0, 0};
g_t strand0_muendung = {884, 1, 1, 4, 6, 0, 0};

g_t strand1_1_2 = {908, 1, 1, 4, 6, 0, 0};
g_t strand2_1_2 = {932, 1, 1, 4, 6, 0, 0};
g_t strand3_1_2 = {956, 1, 1, 4, 6, 0, 0};
g_t strand4_1_2 = {980, 1, 1, 4, 6, 0, 0};
g_t strand5_1_2 = {1004, 1, 1, 4, 6, 0, 0};

g_t strand1_3_4 = {1028, 1, 1, 4, 6, 0, 0};

g_t dreck0 = {1052, 1, 1, 4, 1, 0, 1};
g_t dreck1 = {1056, 1, 1, 4, 1, 0, 1};
g_t wrack = {1060, 1, 1, 4, 1, 0, 1};
g_t skelett = {1064, 1, 1, 4, 1, 0, 1};
g_t felsbogen0 = {1068, 1, 1, 4, 1, 0, 1};
g_t felsbogen1 = {1072, 1, 1, 4, 1, 0, 1};
g_t felsformation = {1076, 1, 1, 4, 1, 0, 1};

g_t wasser = {1080, 1, 1, 1, 12, 0, 0};

g_t kueste0_1_2 = {1092, 1, 1, 4, 1, 0, 1};
g_t kueste1_1_2 = {1096, 1, 1, 4, 1, 0, 1};
g_t kueste2_1_2 = {1100, 1, 1, 4, 1, 0, 1};
g_t kueste3_1_2 = {1104, 1, 1, 4, 1, 0, 1};
g_t kueste4_1_2 = {1108, 1, 1, 4, 1, 0, 1};
g_t kueste5_1_2 = {1112, 1, 1, 4, 1, 0, 1};
g_t kueste6_1_2 = {1116, 1, 1, 4, 1, 0, 1};
g_t kueste7_1_2 = {1120, 1, 1, 4, 1, 0, 1};
g_t kueste8_1_2 = {1124, 1, 1, 4, 1, 0, 1};
g_t kueste9_1_2 = {1128, 1, 1, 4, 1, 0, 1};

g_t kueste0_3_4 = {1132, 1, 1, 4, 1, 0, 1};
g_t kueste1_3_4 = {1136, 1, 1, 4, 1, 0, 1};
g_t kueste2_3_4 = {1140, 1, 1, 4, 1, 0, 1};
g_t kueste3_3_4 = {1144, 1, 1, 4, 1, 0, 1};

g_t kueste0_1_4 = {1164, 1, 1, 4, 1, 0, 1};
g_t kueste1_1_4 = {1168, 1, 1, 4, 1, 0, 1};
g_t kueste2_1_4 = {1172, 1, 1, 4, 1, 0, 1};

g_t kueste_muendung = {1196, 1, 1, 4, 6, 0, 1};

g_t kueste0_felsig = {1220, 1, 1, 4, 1, 0, 1};
g_t kueste1_felsig = {1224, 1, 1, 4, 1, 0, 1};
g_t kueste2_felsig = {1228, 1, 1, 4, 1, 0, 1};
g_t kueste3_felsig = {1232, 1, 1, 4, 1, 0, 1};

g_t strasse_gerade = {1260, 1, 1, 4, 1, 1, 0};
g_t strasse_ecke = {1264, 1, 1, 4, 1, 1, 0};
g_t strasse_t = {1268, 1, 1, 4, 1, 1, 0};
g_t strasse_kreuzung = {1272, 1, 1, 1, 1, 1, 0};

g_t steinbruecke = {1276, 1, 1, 4, 1, 1, 0};
g_t weg_gerade = {1280, 1, 1, 4, 1, 1, 0};
g_t weg_ecke = {1284, 1, 1, 4, 1, 1, 0};
g_t weg_t = {1288, 1, 1, 4, 1, 1, 0};
g_t weg_kreuzung = {1292, 1, 1, 1, 1, 1, 0};

g_t holzbruecke = {1296, 1, 1, 4, 1, 1, 0};
g_t platz1 = {1300, 1, 1, 4, 1, 1, 0};
g_t platz2 = {1304, 1, 1, 4, 1, 1, 0};
g_t platz3 = {1308, 1, 1, 4, 1, 1, 0};
g_t zierbaum = {1312, 1, 1, 4, 1, 1, 1};
g_t anlegestelle = {1316, 1, 1, 4, 1, 0, 0};
g_t fischer = {1320, 1, 1, 4, 1, 0, 1};

g_t steinwall_gerade_land = {1324, 1, 1, 4, 1, 1, 1};
g_t steinwall_ecke_land = {1328, 1, 1, 4, 1, 1, 1};
g_t steinwall_turm_land = {1332, 1, 1, 4, 1, 1, 1};
g_t wachturm_stein_land = {1336, 1, 1, 4, 1, 1, 1};
g_t tor_stein = {1340, 1, 1, 4, 1, 1, 1};
g_t palisade_gerade_land = {1344, 1, 1, 4, 1, 1, 1};
g_t palisade_ecke_land = {1348, 1, 1, 4, 1, 1, 1};
g_t palisade_turm_land = {1352, 1, 1, 4, 1, 1, 1};
g_t wachturm_holz_land = {1356, 1, 1, 4, 1, 1, 1};
g_t tor_holz = {1360, 1, 1, 4, 1, 1, 1};
g_t steinwall_gerade_kueste = {1364, 1, 1, 4, 1, 0, 1};
g_t steinwall_ecke_kueste = {1368, 1, 1, 4, 1, 0, 1};
g_t steinwall_turm_kueste = {1372, 1, 1, 4, 1, 0, 1};
g_t wachturm_stein_kueste = {1376, 1, 1, 4, 1, 0, 1};
g_t palisade_gerade_kueste = {1380, 1, 1, 4, 1, 0, 1};
g_t palisade_ecke_kueste = {1384, 1, 1, 4, 1, 0, 1};
g_t palisade_turm_kueste = {1388, 1, 1, 4, 1, 0, 1};
g_t wachturm_holz_kueste = {1392, 1, 1, 4, 1, 0, 1};
g_t steinwall_gerade_fluss = {1396, 1, 1, 4, 1, 0, 1};
g_t steinwall_ecke_fluss = {1400, 1, 1, 4, 1, 0, 1};
g_t steinwall_turm_fluss = {1404, 1, 1, 4, 1, 0, 1};
g_t palisade_gerade_fluss = {1408, 1, 1, 4, 1, 0, 1};
g_t palisade_ecke_fluss = {1412, 1, 1, 4, 1, 0, 1};
g_t palisade_turm_fluss = {1416, 1, 1, 4, 1, 0, 1};

g_t stadttor = {1420, 1, 3, 4, 1, 1, 1};
g_t triumphbogen = {1432, 1, 3, 4, 1, 1, 1};

g_t baum0_nord = {1444, 1, 1, 1, 6, 1, 1};
g_t baum0_nord_fertig = {1449, 1, 1, 1, 1, 1, 1};
g_t baum1_nord = {1450, 1, 1, 1, 6, 1, 1};
g_t baum1_nord_fertig = {1455, 1, 1, 1, 1, 1, 1};
g_t baum2_nord = {1456, 1, 1, 1, 6, 1, 1};
g_t baum2_nord_fertig = {1461, 1, 1, 1, 1, 1, 1};
g_t baum3_nord = {1462, 1, 1, 1, 6, 1, 1};
g_t baum3_nord_fertig = {1467, 1, 1, 1, 1, 1, 1};
g_t baum4_nord = {1468, 1, 1, 1, 6, 1, 1};
g_t baum4_nord_fertig = {1473, 1, 1, 1, 1, 1, 1};
g_t baum5_nord = {1474, 1, 1, 1, 6, 1, 1};
g_t baum5_nord_fertig = {1479, 1, 1, 1, 1, 1, 1};
g_t baum6_nord = {1480, 1, 1, 1, 6, 1, 1};
g_t baum6_nord_fertig = {1485, 1, 1, 1, 1, 1, 1};
g_t baum7_nord = {1486, 1, 1, 1, 6, 1, 1};
g_t baum7_nord_fertig = {1491, 1, 1, 1, 1, 1, 1};
g_t baum8_nord = {1492, 1, 1, 1, 6, 1, 1};
g_t baum8_nord_fertig = {1497, 1, 1, 1, 1, 1, 1};
g_t baum9_nord = {1498, 1, 1, 1, 6, 1, 1};
g_t baum9_nord_fertig = {1503, 1, 1, 1, 1, 1, 1};
g_t baum10_nord = {1504, 1, 1, 1, 6, 1, 1};
g_t baum10_nord_fertig = {1509, 1, 1, 1, 1, 1, 1};

g_t baum0_sued = {1510, 1, 1, 1, 6, 1, 1};
g_t baum0_sued_fertig = {1515, 1, 1, 1, 1, 1, 1};
g_t baum1_sued = {1516, 1, 1, 1, 6, 1, 1};
g_t baum1_sued_fertig = {1521, 1, 1, 1, 1, 1, 1};
g_t baum2_sued = {1522, 1, 1, 1, 6, 1, 1};
g_t baum2_sued_fertig = {1527, 1, 1, 1, 1, 1, 1};
g_t baum3_sued = {1528, 1, 1, 1, 6, 1, 1};
g_t baum3_sued_fertig = {1533, 1, 1, 1, 1, 1, 1};
g_t baum4_sued = {1534, 1, 1, 1, 6, 1, 1};
g_t baum4_sued_fertig = {1539, 1, 1, 1, 1, 1, 1};
g_t baum5_sued = {1540, 1, 1, 1, 6, 1, 1};
g_t baum5_sued_fertig = {1545, 1, 1, 1, 1, 1, 1};
g_t baum6_sued = {1546, 1, 1, 1, 6, 1, 1};
g_t baum6_sued_fertig = {1551, 1, 1, 1, 1, 1, 1};
g_t baum7_sued = {1552, 1, 1, 1, 6, 1, 1};
g_t baum7_sued_fertig = {1557, 1, 1, 1, 1, 1, 1};
g_t baum8_sued = {1558, 1, 1, 1, 6, 1, 1};
g_t baum8_sued_fertig = {1563, 1, 1, 1, 1, 1, 1};
g_t baum9_sued = {1564, 1, 1, 1, 6, 1, 1};
g_t baum9_sued_fertig = {1569, 1, 1, 1, 1, 1, 1};
g_t baum10_sued = {1570, 1, 1, 1, 6, 1, 1};
g_t baum10_sued_fertig = {1575, 1, 1, 1, 1, 1, 1};

g_t fluss0_gerade = {1576, 1, 1, 4, 6, 1, 0};
g_t fluss1_gerade = {1600, 1, 1, 4, 6, 1, 0};
g_t fluss0_gabelung = {1624, 1, 1, 4, 6, 1, 0};
g_t fluss0_biegung = {1648, 2, 2, 4, 6, 1, 0};
g_t fluss1_biegung = {1744, 2, 2, 4, 6, 1, 0};

g_t windmuehle = {1840, 2, 2, 4, 16, 1, 1};
g_t wassermuehle = {2096, 2, 2, 4, 12, 1, 1};
g_t steinbruch = {2288, 1, 2, 4, 1, 1, 1};
g_t erzmine = {2296, 1, 2, 4, 8, 1, 1};
g_t erzmine_tief = {2360, 1, 2, 4, 8, 1, 1};
g_t goldmine = {2424, 1, 2, 4, 8, 1, 1};

g_t holzfaeller = {2488, 2, 2, 4, 4, 1, 1};
g_t steinmetz = {2552, 2, 2, 4, 4, 1, 1};

g_t bauernhof = {2616, 2, 2, 4, 1, 1, 1};
g_t baumwollplantage = {2632, 2, 2, 4, 1, 1, 1};
g_t rinderfarm = {2648, 2, 2, 4, 1, 1, 1};
g_t schaffarm = {2664, 2, 2, 4, 1, 1, 1};
g_t tabakplantage = {2680, 2, 2, 4, 1, 1, 1};
g_t kakaoplantage = {2696, 2, 2, 4, 1, 1, 1};
g_t zuckerrohrplantage = {2712, 2, 2, 4, 1, 1, 1};
g_t weingut = {2728, 2, 2, 4, 1, 1, 1};
g_t gewuerzplantage = {2744, 2, 2, 4, 1, 1, 1};

g_t feuerwehr = {2760, 2, 2, 4, 6, 1, 1};
g_t arzt = {2856, 2, 2, 4, 1, 1, 1};
g_t haus_kaputt = {2872, 2, 2, 4, 1, 1, 1};


g_t pionier1 = {2952, 2, 2, 4, 1, 1, 1};
g_t pionier2 = {2968, 2, 2, 4, 1, 1, 1};
g_t pionier3 = {2984, 2, 2, 4, 1, 1, 1};
g_t pionier4 = {3000, 2, 2, 4, 1, 1, 1};
g_t pionier5 = {3016, 2, 2, 4, 1, 1, 1};
g_t pionier6 = {3032, 2, 2, 4, 1, 1, 1};
g_t pionier7 = {3048, 2, 2, 4, 1, 1, 1};
g_t siedler1 = {3064, 2, 2, 4, 1, 1, 1};
g_t siedler2 = {3080, 2, 2, 4, 1, 1, 1};
g_t siedler3 = {3096, 2, 2, 4, 1, 1, 1};
g_t siedler4 = {3112, 2, 2, 4, 1, 1, 1};
g_t siedler5 = {3128, 2, 2, 4, 1, 1, 1};
g_t buerger1 = {3144, 2, 2, 4, 1, 1, 1};
g_t buerger2 = {3160, 2, 2, 4, 1, 1, 1};
g_t buerger3 = {3176, 2, 2, 4, 1, 1, 1};
g_t buerger4 = {3192, 2, 2, 4, 1, 1, 1};
g_t buerger5 = {3208, 2, 2, 4, 1, 1, 1};
g_t buerger6 = {3224, 2, 2, 4 ,1, 1, 1};
g_t kaufleute1 = {3240, 2, 2, 4, 1, 1, 1};
g_t kaufleute2 = {3256, 2, 2, 4, 1, 1, 1};
g_t kaufleute3 = {3272, 2, 2, 4, 1, 1, 1};
g_t kaufleute4 = {3288, 2, 2, 4, 1, 1, 1};
g_t kaufleute5 = {3304, 2, 2, 4, 1, 1, 1};
g_t aristokraten1 = {3320, 2, 2, 4, 1, 1, 1};
g_t aristokraten2 = {3336, 2, 2, 4, 1, 1, 1};
g_t aristokraten3 = {3352, 2, 2, 4, 1, 1, 1};
g_t aristokraten4 = {3368, 2, 2, 4, 1, 1, 1};
g_t aristokraten5 = {3384, 2, 2, 4, 1, 1, 1};
g_t aristokraten6 = {3400, 2, 2, 4, 1, 1, 1};

g_t haeuptlingshuette_stein = {3416, 2, 2, 4, 1, 1, 1};
g_t kriegerhuette_stein = {3432, 2, 2, 4, 1, 1, 1};
g_t eingeborenenhuette_stein = {3448, 2, 2, 4, 1, 1, 1};
g_t haeuptlingshuette = {3464, 2, 2, 4, 1, 1, 1};
g_t eingeborenenhuette = {3480, 2, 2, 4, 1, 1, 1};
g_t kriegerhuette = {3496, 2, 2, 4, 1, 1, 1};
g_t gewuerzlager_stein = {3528, 2, 2, 4, 1, 1, 1};
g_t tabaklager_stein = {3544, 2, 2, 4, 1, 1, 1};
g_t gewuerzlager = {3576, 2, 2, 4, 1, 1, 1};
g_t tabaklager = {3592, 2, 2, 4, 1, 1, 1};


g_t pyramide = {3640, 4, 4, 4, 1, 1, 1};
g_t piratenhaus1 = {3704, 2, 2, 4, 1, 1, 1};
g_t piratenhaus2 = {3720, 2, 2, 4, 1, 1, 1};
g_t piratenwirtshaus = {3736, 2, 2, 4, 1, 1, 1};

g_t piratenturm_land = {3752, 1, 1, 4, 1, 1, 1};
g_t piratenturm_kueste = {3756, 1, 1, 4, 1, 0, 1};

g_t baeckerei = {3760, 2, 2, 4, 1, 1, 1};
g_t schneiderei = {3776, 2, 2, 4, 1, 1, 1};
g_t webstube = {3792, 2, 2, 4, 1, 1, 1};
g_t weberei = {3808, 2, 2, 4, 1, 1, 1};
g_t rumbrennerei = {3824, 2, 2, 4, 1, 1, 1};
g_t metzger = {3840, 2, 2, 4, 1, 1, 1};
g_t tabakwarenladen = {3856, 2, 2, 4, 1, 1, 1};
g_t goldschmiede = {3872, 2, 2, 4, 1, 1, 1};

g_t erzschmelze = {3904, 2, 2, 4, 5, 1, 1};
g_t werkzeugschmiede = {3984, 2, 2, 4, 5, 1, 1};
g_t musketenbauer = {4064, 2, 2, 4, 5, 1, 1};
g_t kanonengiesserei = {4144, 3, 3, 4, 5, 1, 1};
g_t schwertschmiede = {4324, 2, 2, 4, 5, 1, 1};

g_t jagdhuette = {4408, 1, 1, 4, 1, 1, 1};

g_t kontor1 = {4412, 2, 3, 4, 1, 1, 1};
g_t kontor2 = {4436, 2, 3, 4, 1, 1, 1};
g_t kontor3 = {4460, 2, 3, 4, 1, 1, 1};
g_t kontor4 = {4484, 2, 3, 4, 1, 1, 1};

g_t wirtshaus = {4508, 2, 3, 4, 1, 1, 1};
g_t piratenkontor = {4532, 2, 3, 4, 1, 1, 1};
g_t kontor1_kaputt = {4556, 2, 3, 4, 1, 1, 1};
g_t kontor2_kaputt = {4580, 2, 3, 4, 1, 1, 1};
g_t kontor3_kaputt = {4604, 2, 3, 4, 1, 1, 1};
g_t kontor4_kaputt = {4628, 2, 3, 4, 1, 1, 1};
g_t badehaus = {4652, 4, 3, 4, 1, 1, 1};
g_t marktplatz = {4700, 4, 3, 4, 1, 1, 1};
g_t marktplatz_kaputt = {2844, 4, 3, 4, 1, 1, 1};
g_t werft_gross = {4892, 4, 4, 4, 1, 0, 1};
g_t werft = {4956, 3, 3, 4, 1, 0, 1};
g_t kathedrale = {4992, 6, 4, 4, 1, 1, 1};
g_t kirche = {5088, 4, 3, 4, 1, 1, 1};
g_t kapelle = {5136, 2, 1, 4, 1, 1, 1};
g_t theater = {5144, 3, 3, 4, 1, 1, 1};
g_t schloss = {5180, 5, 7, 4, 1, 1, 1};
g_t hochschule = {5320, 3, 3, 4, 1, 1, 1};
g_t schule = {5356, 2, 2, 4, 1, 1, 1};
g_t galgen = {5372, 1, 1, 4, 6, 1, 1};
g_t denkmal = {5396, 1, 1, 4, 1, 1, 1};

g_t burg = {5400, 2, 2, 4, 1, 1, 1};
g_t burg_gross = {5416, 3, 3, 4, 1, 1, 1};
g_t festung = {5452, 5, 5, 4, 1, 1, 1};

g_t vulkan = {5552, 4, 4, 4, 1, 1, 1};
g_t berg0 = {5616, 4, 4, 4, 1, 1, 1};
g_t berg1 = {5680, 6, 6, 4, 1, 1, 1};
g_t berg2 = {5824, 3, 3, 4, 1, 1, 1};
g_t berg3 = {5860, 3, 3, 4, 1, 1, 1};
g_t berg4 = {5896, 3, 3, 4, 1, 1, 1};
g_t berg5 = {5932, 2, 2, 4, 1, 1, 1};
g_t berg6 = {5948, 2, 2, 4, 1, 1, 1};
