
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

#ifndef STADTFLD_BSH_HPP
#define STADTFLD_BSH_HPP

typedef struct
{
  unsigned short index;
  unsigned char breite;
  unsigned char hoehe;
  unsigned char richtungen;
  unsigned char ani_schritte;
  unsigned char grundhoehe;
  unsigned char bauhoehe;
} g_t;

extern g_t gras0_gruen;
extern g_t gras1_gruen;
extern g_t gras2_gruen;
extern g_t gras3_gruen;
extern g_t gras4_gruen;
extern g_t gras5_gruen;
extern g_t sand0;

extern g_t gras0;
extern g_t gras1;
extern g_t gras2;
extern g_t gras3;
extern g_t gras4;
extern g_t gras5;
extern g_t gras6;
extern g_t gras7;
extern g_t gras8;
extern g_t gras9;

extern g_t gras0b;
extern g_t gras1b;
extern g_t gras2b;
extern g_t gras3b;
extern g_t gras4b;
extern g_t gras5b;
extern g_t gras6b;
extern g_t gras7b;
extern g_t gras8b;
extern g_t gras9b;

extern g_t pflanzen0b;
extern g_t pflanzen1b;
extern g_t pflanzen2b;
extern g_t pflanzen3b;
extern g_t pflanzen4b;
extern g_t pflanzen5b;
extern g_t pflanzen6b;
extern g_t pflanzen7b;
extern g_t pflanzen8b;
extern g_t pflanzen9b;

extern g_t pflanzen0;
extern g_t pflanzen1;
extern g_t pflanzen2;
extern g_t pflanzen3;
extern g_t pflanzen4;
extern g_t pflanzen5;
extern g_t pflanzen6;
extern g_t pflanzen7;
extern g_t pflanzen8;
extern g_t pflanzen9;

extern g_t wueste0;
extern g_t wueste1;
extern g_t wueste2;
extern g_t wueste3;
extern g_t wueste4;
extern g_t wueste5;
extern g_t wueste6;
extern g_t wueste7;
extern g_t wueste8;
extern g_t wueste9;

extern g_t gras0_braun;
extern g_t gras1_braun;
extern g_t gras2_braun;
extern g_t gras3_braun;
extern g_t gras4_braun;
extern g_t gras5_braun;
extern g_t gras6_braun;
extern g_t gras7_braun;
extern g_t gras8_braun;
extern g_t gras9_braun;


extern g_t truemmer0;
extern g_t truemmer1;
extern g_t truemmer2;
extern g_t truemmer3;
extern g_t truemmer4;
extern g_t truemmer5;
extern g_t truemmer6;
extern g_t truemmer7;
extern g_t truemmer8;
extern g_t truemmer9;
extern g_t truemmer10;
extern g_t truemmer11;

extern g_t truemmer0_kueste;
extern g_t truemmer1_kueste;


extern g_t wegreste0;
extern g_t wegreste1;
extern g_t wegreste2;
extern g_t wegreste3;
extern g_t wegreste4;
extern g_t wegreste5;


extern g_t hang0;
extern g_t hang1;
extern g_t hang2;
extern g_t hang3;
extern g_t hang4;
extern g_t hang5;
extern g_t hang6;
extern g_t hang7;
extern g_t hang8;
extern g_t hang9;

extern g_t hang0_1_4;
extern g_t hang1_1_4;

extern g_t hang0_3_4;
extern g_t hang1_3_4;

extern g_t quelle;
extern g_t felshang0;
extern g_t felshang1;

extern g_t weizenfeld;
extern g_t weizenfeld_fertig;
extern g_t baumwollfeld;
extern g_t baumwollfeld_fertig;
extern g_t grasfeld;
extern g_t grasfeld_fertig;
extern g_t tabakfeld;
extern g_t tabakfeld_fertig;
extern g_t kakaofeld;
extern g_t kakaofeld_fertig;
extern g_t zuckerrohrfeld;
extern g_t zuckerrohrfeld_fertig;
extern g_t gewuerzfeld;
extern g_t gewuerzfeld_fertig;
extern g_t weinfeld;
extern g_t weinfeld_fertig;

extern g_t weizenfeld_trocken;
extern g_t baumwollfeld_trocken;
extern g_t grasfeld_trocken;
extern g_t tabakfeld_trocken;
extern g_t kakaofeld_trocken;
extern g_t zuckerrohrfeld_trocken;
extern g_t gewuerzfeld_trocken;
extern g_t weinfeld_trocken;

extern g_t verbranntes_feld0;
extern g_t verbranntes_feld1;

extern g_t meer_flach;
extern g_t meer_flach_fischgruende;
extern g_t fischgruende;
extern g_t meer;
extern g_t fischgruende_meer;

extern g_t strand0_1_2;
extern g_t strand0_3_4;
extern g_t strand0_1_4;
extern g_t strand0_muendung;

extern g_t strand1_1_2;
extern g_t strand2_1_2;
extern g_t strand3_1_2;
extern g_t strand4_1_2;
extern g_t strand5_1_2;

extern g_t strand1_3_4;

extern g_t dreck0;
extern g_t dreck1;
extern g_t wrack;
extern g_t skelett;
extern g_t felsbogen0;
extern g_t felsbogen1;
extern g_t felsformation;

extern g_t wasser;

extern g_t kueste0_1_2;
extern g_t kueste1_1_2;
extern g_t kueste2_1_2;
extern g_t kueste3_1_2;
extern g_t kueste4_1_2;
extern g_t kueste5_1_2;
extern g_t kueste6_1_2;
extern g_t kueste7_1_2;
extern g_t kueste8_1_2;
extern g_t kueste9_1_2;

extern g_t kueste0_3_4;
extern g_t kueste1_3_4;
extern g_t kueste2_3_4;
extern g_t kueste3_3_4;

extern g_t kueste0_1_4;
extern g_t kueste1_1_4;
extern g_t kueste2_1_4;

extern g_t kueste_muendung;

extern g_t kueste0_felsig;
extern g_t kueste1_felsig;
extern g_t kueste2_felsig;
extern g_t kueste3_felsig;

extern g_t strasse_gerade;
extern g_t strasse_ecke;
extern g_t strasse_t;
extern g_t strasse_kreuzung;

extern g_t steinbruecke;
extern g_t weg_gerade;
extern g_t weg_ecke;
extern g_t weg_t;
extern g_t weg_kreuzung;

extern g_t holzbruecke;
extern g_t platz1;
extern g_t platz2;
extern g_t platz3;
extern g_t zierbaum;
extern g_t anlegestelle;
extern g_t fischer;

extern g_t steinwall_gerade_land;
extern g_t steinwall_ecke_land;
extern g_t steinwall_turm_land;
extern g_t wachturm_stein_land;
extern g_t tor_stein;
extern g_t palisade_gerade_land;
extern g_t palisade_ecke_land;
extern g_t palisade_turm_land;
extern g_t wachturm_holz_land;
extern g_t tor_holz;
extern g_t steinwall_gerade_kueste;
extern g_t steinwall_ecke_kueste;
extern g_t steinwall_turm_kueste;
extern g_t wachturm_stein_kueste;
extern g_t palisade_gerade_kueste;
extern g_t palisade_ecke_kueste;
extern g_t palisade_turm_kueste;
extern g_t wachturm_holz_kueste;
extern g_t steinwall_gerade_fluss;
extern g_t steinwall_ecke_fluss;
extern g_t steinwall_turm_fluss;
extern g_t palisade_gerade_fluss;
extern g_t palisade_ecke_fluss;
extern g_t palisade_turm_fluss;

extern g_t stadttor;
extern g_t triumphbogen;

extern g_t baum0_nord;
extern g_t baum0_nord_fertig;
extern g_t baum1_nord;
extern g_t baum1_nord_fertig;
extern g_t baum2_nord;
extern g_t baum2_nord_fertig;
extern g_t baum3_nord;
extern g_t baum3_nord_fertig;
extern g_t baum4_nord;
extern g_t baum4_nord_fertig;
extern g_t baum5_nord;
extern g_t baum5_nord_fertig;
extern g_t baum6_nord;
extern g_t baum6_nord_fertig;
extern g_t baum7_nord;
extern g_t baum7_nord_fertig;
extern g_t baum8_nord;
extern g_t baum8_nord_fertig;
extern g_t baum9_nord;
extern g_t baum9_nord_fertig;
extern g_t baum10_nord;
extern g_t baum10_nord_fertig;

extern g_t baum0_sued;
extern g_t baum0_sued_fertig;
extern g_t baum1_sued;
extern g_t baum1_sued_fertig;
extern g_t baum2_sued;
extern g_t baum2_sued_fertig;
extern g_t baum3_sued;
extern g_t baum3_sued_fertig;
extern g_t baum4_sued;
extern g_t baum4_sued_fertig;
extern g_t baum5_sued;
extern g_t baum5_sued_fertig;
extern g_t baum6_sued;
extern g_t baum6_sued_fertig;
extern g_t baum7_sued;
extern g_t baum7_sued_fertig;
extern g_t baum8_sued;
extern g_t baum8_sued_fertig;
extern g_t baum9_sued;
extern g_t baum9_sued_fertig;
extern g_t baum10_sued;
extern g_t baum10_sued_fertig;

extern g_t fluss0_gerade;
extern g_t fluss1_gerade;
extern g_t fluss0_gabelung;
extern g_t fluss0_biegung;
extern g_t fluss1_biegung;

extern g_t windmuehle;
extern g_t wassermuehle;
extern g_t steinbruch;
extern g_t erzmine;
extern g_t erzmine_tief;
extern g_t goldmine;

extern g_t holzfaeller;
extern g_t steinmetz;

extern g_t bauernhof;
extern g_t baumwollplantage;
extern g_t rinderfarm;
extern g_t schaffarm;
extern g_t tabakplantage;
extern g_t kakaoplantage;
extern g_t zuckerrohrplantage;
extern g_t weingut;
extern g_t gewuerzplantage;

extern g_t feuerwehr;
extern g_t arzt;
extern g_t haus_kaputt;


extern g_t pionier1;
extern g_t pionier2;
extern g_t pionier3;
extern g_t pionier4;
extern g_t pionier5;
extern g_t pionier6;
extern g_t pionier7;
extern g_t siedler1;
extern g_t siedler2;
extern g_t siedler3;
extern g_t siedler4;
extern g_t siedler5;
extern g_t buerger1;
extern g_t buerger2;
extern g_t buerger3;
extern g_t buerger4;
extern g_t buerger5;
extern g_t buerger6;
extern g_t kaufleute1;
extern g_t kaufleute2;
extern g_t kaufleute3;
extern g_t kaufleute4;
extern g_t kaufleute5;
extern g_t aristokraten1;
extern g_t aristokraten2;
extern g_t aristokraten3;
extern g_t aristokraten4;
extern g_t aristokraten5;
extern g_t aristokraten6;

extern g_t haeuptlingshuette_stein;
extern g_t kriegerhuette_stein;
extern g_t eingeborenenhuette_stein;
extern g_t haeuptlingshuette;
extern g_t eingeborenenhuette;
extern g_t kriegerhuette;
extern g_t gewuerzlager_stein;
extern g_t tabaklager_stein;
extern g_t gewuerzlager;
extern g_t tabaklager;


extern g_t pyramide;
extern g_t piratenhaus1;
extern g_t piratenhaus2;
extern g_t piratenwirtshaus;

extern g_t piratenturm_land;
extern g_t piratenturm_kueste;

extern g_t baeckerei;
extern g_t schneiderei;
extern g_t webstube;
extern g_t weberei;
extern g_t rumbrennerei;
extern g_t metzger;
extern g_t tabakwarenladen;
extern g_t goldschmiede;

extern g_t erzschmelze;
extern g_t werkzeugschmiede;
extern g_t musketenbauer;
extern g_t kanonengiesserei;
extern g_t schwertschmiede;

extern g_t jagdhuette;

extern g_t kontor1;
extern g_t kontor2;
extern g_t kontor3;
extern g_t kontor4;

extern g_t wirtshaus;
extern g_t piratenkontor;
extern g_t kontor1_kaputt;
extern g_t kontor2_kaputt;
extern g_t kontor3_kaputt;
extern g_t kontor4_kaputt;
extern g_t badehaus;
extern g_t marktplatz;
extern g_t marktplatz_kaputt;
extern g_t werft_gross;
extern g_t werft;
extern g_t kathedrale;
extern g_t kirche;
extern g_t kapelle;
extern g_t theater;
extern g_t schloss;
extern g_t hochschule;
extern g_t schule;
extern g_t galgen;
extern g_t denkmal;

extern g_t burg;
extern g_t burg_gross;
extern g_t festung;

extern g_t vulkan;
extern g_t berg0;
extern g_t berg1;
extern g_t berg2;
extern g_t berg3;
extern g_t berg4;
extern g_t berg5;
extern g_t berg6;

#endif
