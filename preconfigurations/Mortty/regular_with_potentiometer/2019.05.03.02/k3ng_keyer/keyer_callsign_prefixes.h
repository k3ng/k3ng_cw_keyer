

const char canadian_prefix_1[] PROGMEM = "VE1";
const char canadian_prefix_2[] PROGMEM = "VE2";
const char canadian_prefix_3[] PROGMEM = "VE3";
const char canadian_prefix_4[] PROGMEM = "VE4";
const char canadian_prefix_5[] PROGMEM = "VE5";
const char canadian_prefix_6[] PROGMEM = "VE6";
const char canadian_prefix_7[] PROGMEM = "VE7";
const char canadian_prefix_8[] PROGMEM = "VE8";
const char canadian_prefix_9[] PROGMEM = "VE9";
const char canadian_prefix_10[] PROGMEM = "VY0";
const char canadian_prefix_11[] PROGMEM = "VY1";
const char canadian_prefix_12[] PROGMEM = "VY2";
const char canadian_prefix_13[] PROGMEM = "VO1";
const char canadian_prefix_14[] PROGMEM = "VO2";
const byte canadian_prefix_size = 14;
const char* const canadian_prefix_table[] PROGMEM = 
  {canadian_prefix_1,canadian_prefix_2,canadian_prefix_3,canadian_prefix_4,canadian_prefix_5,canadian_prefix_6,canadian_prefix_7,canadian_prefix_8,canadian_prefix_9,canadian_prefix_10,
   canadian_prefix_11,canadian_prefix_12,canadian_prefix_13,canadian_prefix_14};

// European callsign prefix table
//
// Note 2017-05-06: This is weird.  If I put "LB" in the array, avrdude trips up with a timeout error when uploading to a Mega.  
// That's why LB isn't in this table

const char eu_prefix_1[] PROGMEM = "3A";
const char eu_prefix_2[] PROGMEM = "4O";
const char eu_prefix_3[] PROGMEM = "4U";
const char eu_prefix_4[] PROGMEM = "9A";
const char eu_prefix_5[] PROGMEM = "9H";
const char eu_prefix_6[] PROGMEM = "C3";
const char eu_prefix_7[] PROGMEM = "CT";
const char eu_prefix_8[] PROGMEM = "CU";
const char eu_prefix_9[] PROGMEM = "DA";
const char eu_prefix_10[] PROGMEM = "DB";
const char eu_prefix_11[] PROGMEM = "DC";
const char eu_prefix_12[] PROGMEM = "DD";
const char eu_prefix_13[] PROGMEM = "DE";
const char eu_prefix_14[] PROGMEM = "DF";
const char eu_prefix_15[] PROGMEM = "DG";
const char eu_prefix_16[] PROGMEM = "DH";
const char eu_prefix_17[] PROGMEM = "DI";
const char eu_prefix_18[] PROGMEM = "DJ";
const char eu_prefix_19[] PROGMEM = "DK";
const char eu_prefix_20[] PROGMEM = "DL";
const char eu_prefix_21[] PROGMEM = "EI";
const char eu_prefix_22[] PROGMEM = "ER";
const char eu_prefix_23[] PROGMEM = "ES";
const char eu_prefix_24[] PROGMEM = "EU";
const char eu_prefix_25[] PROGMEM = "EV";
const char eu_prefix_26[] PROGMEM = "EW";
const char eu_prefix_27[] PROGMEM = "F";
const char eu_prefix_28[] PROGMEM = "G";
const char eu_prefix_29[] PROGMEM = "GX";
const char eu_prefix_30[] PROGMEM = "GD";
const char eu_prefix_31[] PROGMEM = "GT";
const char eu_prefix_32[] PROGMEM = "GI";
const char eu_prefix_33[] PROGMEM = "GN";
const char eu_prefix_34[] PROGMEM = "GJ";
const char eu_prefix_35[] PROGMEM = "GH";
const char eu_prefix_36[] PROGMEM = "GM";
const char eu_prefix_37[] PROGMEM = "GS";
const char eu_prefix_38[] PROGMEM = "GU";
const char eu_prefix_39[] PROGMEM = "GP";
const char eu_prefix_40[] PROGMEM = "GW";
const char eu_prefix_41[] PROGMEM = "GC";
const char eu_prefix_42[] PROGMEM = "HB";
const char eu_prefix_43[] PROGMEM = "HV";
const char eu_prefix_44[] PROGMEM = "I";
const char eu_prefix_45[] PROGMEM = "IS";
const char eu_prefix_46[] PROGMEM = "IM";
const char eu_prefix_47[] PROGMEM = "JW";
const char eu_prefix_48[] PROGMEM = "JX";
const char eu_prefix_49[] PROGMEM = "LX";
const char eu_prefix_50[] PROGMEM = "LY";
const char eu_prefix_51[] PROGMEM = "LZ";
const char eu_prefix_52[] PROGMEM = "OY";
const char eu_prefix_53[] PROGMEM = "OZ";
const char eu_prefix_54[] PROGMEM = "S5";
const char eu_prefix_55[] PROGMEM = "YU";
const char eu_prefix_56[] PROGMEM = "T7";
const char eu_prefix_57[] PROGMEM = "T9";
const char eu_prefix_58[] PROGMEM = "TF";
const char eu_prefix_59[] PROGMEM = "TK";
const char eu_prefix_60[] PROGMEM = "EM";
const char eu_prefix_61[] PROGMEM = "EO";
const char eu_prefix_62[] PROGMEM = "YL";
const char eu_prefix_63[] PROGMEM = "YO";
const char eu_prefix_64[] PROGMEM = "YT";
const char eu_prefix_65[] PROGMEM = "YU";
const char eu_prefix_66[] PROGMEM = "YP";
const char eu_prefix_67[] PROGMEM = "YQ";
const char eu_prefix_68[] PROGMEM = "YR";
const char eu_prefix_69[] PROGMEM = "Z3";
const char eu_prefix_70[] PROGMEM = "ZA";
const char eu_prefix_71[] PROGMEM = "YZ";
const char eu_prefix_72[] PROGMEM = "SA";
const char eu_prefix_73[] PROGMEM = "SB";
const char eu_prefix_74[] PROGMEM = "SC";
const char eu_prefix_75[] PROGMEM = "SD";
const char eu_prefix_76[] PROGMEM = "SE";
const char eu_prefix_77[] PROGMEM = "SF";
const char eu_prefix_78[] PROGMEM = "SG";
const char eu_prefix_79[] PROGMEM = "SH";
const char eu_prefix_80[] PROGMEM = "SI";
const char eu_prefix_81[] PROGMEM = "SJ";
const char eu_prefix_82[] PROGMEM = "SK";
const char eu_prefix_83[] PROGMEM = "SL";
const char eu_prefix_84[] PROGMEM = "SM";
const char eu_prefix_85[] PROGMEM = "SN";
const char eu_prefix_86[] PROGMEM = "SO";
const char eu_prefix_87[] PROGMEM = "SP";
const char eu_prefix_88[] PROGMEM = "SQ";
const char eu_prefix_89[] PROGMEM = "SR";
const char eu_prefix_90[] PROGMEM = "SS";
const char eu_prefix_91[] PROGMEM = "ST";
const char eu_prefix_92[] PROGMEM = "SU";
const char eu_prefix_93[] PROGMEM = "SV";
const char eu_prefix_94[] PROGMEM = "SW";
const char eu_prefix_95[] PROGMEM = "SX";
const char eu_prefix_96[] PROGMEM = "SY";
const char eu_prefix_97[] PROGMEM = "SZ";
const char eu_prefix_98[] PROGMEM = "OE";
const char eu_prefix_99[] PROGMEM = "OF";
const char eu_prefix_100[] PROGMEM = "OG";
const char eu_prefix_101[] PROGMEM = "OH";
const char eu_prefix_102[] PROGMEM = "OI";
const char eu_prefix_103[] PROGMEM = "OJ";
const char eu_prefix_104[] PROGMEM = "OK";
const char eu_prefix_105[] PROGMEM = "OL";
const char eu_prefix_106[] PROGMEM = "OM";
const char eu_prefix_107[] PROGMEM = "ON";
const char eu_prefix_108[] PROGMEM = "OO";
const char eu_prefix_109[] PROGMEM = "OP";
const char eu_prefix_110[] PROGMEM = "OQ";
const char eu_prefix_111[] PROGMEM = "OR";
const char eu_prefix_112[] PROGMEM = "OS";
const char eu_prefix_113[] PROGMEM = "OT";
const char eu_prefix_114[] PROGMEM = "PA";
const char eu_prefix_115[] PROGMEM = "PB";
const char eu_prefix_116[] PROGMEM = "PC";
const char eu_prefix_117[] PROGMEM = "PD";
const char eu_prefix_118[] PROGMEM = "PE";
const char eu_prefix_119[] PROGMEM = "PF";
const char eu_prefix_120[] PROGMEM = "PG";
const char eu_prefix_121[] PROGMEM = "PH";
const char eu_prefix_122[] PROGMEM = "PI";
const char eu_prefix_123[] PROGMEM = "UA";
const char eu_prefix_124[] PROGMEM = "UB";
const char eu_prefix_125[] PROGMEM = "UC";
const char eu_prefix_126[] PROGMEM = "UD";
const char eu_prefix_127[] PROGMEM = "UE";
const char eu_prefix_128[] PROGMEM = "UF";
const char eu_prefix_129[] PROGMEM = "UG";
const char eu_prefix_130[] PROGMEM = "UH";
const char eu_prefix_131[] PROGMEM = "UI";
const char eu_prefix_132[] PROGMEM = "RA";
const char eu_prefix_133[] PROGMEM = "RB";
const char eu_prefix_134[] PROGMEM = "RC";
const char eu_prefix_135[] PROGMEM = "RD";
const char eu_prefix_136[] PROGMEM = "RE";
const char eu_prefix_137[] PROGMEM = "RF";
const char eu_prefix_138[] PROGMEM = "RG";
const char eu_prefix_139[] PROGMEM = "RH";
const char eu_prefix_140[] PROGMEM = "RI";
const char eu_prefix_141[] PROGMEM = "RJ";
const char eu_prefix_142[] PROGMEM = "RK";
const char eu_prefix_143[] PROGMEM = "RL";
const char eu_prefix_144[] PROGMEM = "RM";
const char eu_prefix_145[] PROGMEM = "RN";
const char eu_prefix_146[] PROGMEM = "RO";
const char eu_prefix_147[] PROGMEM = "RP";
const char eu_prefix_148[] PROGMEM = "RQ";
const char eu_prefix_149[] PROGMEM = "RR";
const char eu_prefix_150[] PROGMEM = "RS";
const char eu_prefix_151[] PROGMEM = "RT";
const char eu_prefix_152[] PROGMEM = "RU";
const char eu_prefix_153[] PROGMEM = "RV";
const char eu_prefix_154[] PROGMEM = "RW";
const char eu_prefix_155[] PROGMEM = "RX";
const char eu_prefix_156[] PROGMEM = "RY";
const char eu_prefix_157[] PROGMEM = "RZ";
const char eu_prefix_158[] PROGMEM = "UR";
const char eu_prefix_159[] PROGMEM = "US";
const char eu_prefix_160[] PROGMEM = "UT";
const char eu_prefix_161[] PROGMEM = "UU";
const char eu_prefix_162[] PROGMEM = "UV";
const char eu_prefix_163[] PROGMEM = "UW";
const char eu_prefix_164[] PROGMEM = "UX";
const char eu_prefix_165[] PROGMEM = "UY";
const char eu_prefix_166[] PROGMEM = "UZ";
const char eu_prefix_167[] PROGMEM = "EA";
const char eu_prefix_168[] PROGMEM = "EB";
const char eu_prefix_169[] PROGMEM = "EC";
const char eu_prefix_170[] PROGMEM = "ED";
const char eu_prefix_171[] PROGMEM = "EE";
const char eu_prefix_172[] PROGMEM = "EF";
const char eu_prefix_173[] PROGMEM = "EG";
const char eu_prefix_174[] PROGMEM = "EH";
const char eu_prefix_175[] PROGMEM = "EJ";
const char eu_prefix_176[] PROGMEM = "HA";
const char eu_prefix_177[] PROGMEM = "HG";
const char eu_prefix_178[] PROGMEM = "LA";
const char eu_prefix_179[] PROGMEM = "LC";
const char eu_prefix_180[] PROGMEM = "LD";
const char eu_prefix_181[] PROGMEM = "LE";
const char eu_prefix_182[] PROGMEM = "LF";
const char eu_prefix_183[] PROGMEM = "LG";
const char eu_prefix_184[] PROGMEM = "LH";
const char eu_prefix_185[] PROGMEM = "LI";
const char eu_prefix_186[] PROGMEM = "LJ";
const char eu_prefix_187[] PROGMEM = "LK";
const char eu_prefix_188[] PROGMEM = "LL";
const char eu_prefix_189[] PROGMEM = "LM";
const char eu_prefix_190[] PROGMEM = "LN";
/*const char eu_prefix_191[] PROGMEM = "LB"; see note above about "LB"*/
const byte eu_prefix_size = 190;
const char* const eu_prefix_table[] PROGMEM = {
	eu_prefix_1,
	eu_prefix_2,
	eu_prefix_3,
	eu_prefix_4,
	eu_prefix_5,
	eu_prefix_6,
	eu_prefix_7,
	eu_prefix_8,
	eu_prefix_9,
	eu_prefix_10,
	eu_prefix_11,
	eu_prefix_12,
	eu_prefix_13,
	eu_prefix_14,
	eu_prefix_15,
	eu_prefix_16,
	eu_prefix_17,
	eu_prefix_18,
	eu_prefix_19,
	eu_prefix_20,
	eu_prefix_21,
	eu_prefix_22,
	eu_prefix_23,
	eu_prefix_24,
	eu_prefix_25,
	eu_prefix_26,
	eu_prefix_27,
	eu_prefix_28,
	eu_prefix_29,
	eu_prefix_30,
	eu_prefix_31,
	eu_prefix_32,
	eu_prefix_33,
	eu_prefix_34,
	eu_prefix_35,
	eu_prefix_36,
	eu_prefix_37,
	eu_prefix_38,
	eu_prefix_39,
	eu_prefix_40,
	eu_prefix_41,
	eu_prefix_42,
	eu_prefix_43,
	eu_prefix_44,
	eu_prefix_45,
	eu_prefix_46,
	eu_prefix_47,
	eu_prefix_48,
	eu_prefix_49,
	eu_prefix_50,
	eu_prefix_51,
	eu_prefix_52,
	eu_prefix_53,
	eu_prefix_54,
	eu_prefix_55,
	eu_prefix_56,
	eu_prefix_57,
	eu_prefix_58,
	eu_prefix_59,
	eu_prefix_60,
	eu_prefix_61,
	eu_prefix_62,
	eu_prefix_63,
	eu_prefix_64,
	eu_prefix_65,
	eu_prefix_66,
	eu_prefix_67,
	eu_prefix_68,
	eu_prefix_69,
	eu_prefix_70,
	eu_prefix_71,
	eu_prefix_72,
	eu_prefix_73,
	eu_prefix_74,
	eu_prefix_75,
	eu_prefix_76,
	eu_prefix_77,
	eu_prefix_78,
	eu_prefix_79,
	eu_prefix_80,
	eu_prefix_81,
	eu_prefix_82,
	eu_prefix_83,
	eu_prefix_84,
	eu_prefix_85,
	eu_prefix_86,
	eu_prefix_87,
	eu_prefix_88,
	eu_prefix_89,
	eu_prefix_90,
	eu_prefix_91,
	eu_prefix_92,
	eu_prefix_93,
	eu_prefix_94,
	eu_prefix_95,
	eu_prefix_96,
	eu_prefix_97,
	eu_prefix_98,
	eu_prefix_99,
	eu_prefix_100,
	eu_prefix_101,
	eu_prefix_102,
	eu_prefix_103,
	eu_prefix_104,
	eu_prefix_105,
	eu_prefix_106,
	eu_prefix_107,
	eu_prefix_108,
	eu_prefix_109,
	eu_prefix_110,
	eu_prefix_111,
	eu_prefix_112,
	eu_prefix_113,
	eu_prefix_114,
	eu_prefix_115,
	eu_prefix_116,
	eu_prefix_117,
	eu_prefix_118,
	eu_prefix_119,
	eu_prefix_120,
	eu_prefix_121,
	eu_prefix_122,
	eu_prefix_123,
	eu_prefix_124,
	eu_prefix_125,
	eu_prefix_126,
	eu_prefix_127,
	eu_prefix_128,
	eu_prefix_129,
	eu_prefix_130,
	eu_prefix_131,
	eu_prefix_132,
	eu_prefix_133,
	eu_prefix_134,
	eu_prefix_135,
	eu_prefix_136,
	eu_prefix_137,
	eu_prefix_138,
	eu_prefix_139,
	eu_prefix_140,
	eu_prefix_141,
	eu_prefix_142,
	eu_prefix_143,
	eu_prefix_144,
	eu_prefix_145,
	eu_prefix_146,
	eu_prefix_147,
	eu_prefix_148,
	eu_prefix_149,
	eu_prefix_150,
	eu_prefix_151,
	eu_prefix_152,
	eu_prefix_153,
	eu_prefix_154,
	eu_prefix_155,
	eu_prefix_156,
	eu_prefix_157,
	eu_prefix_158,
	eu_prefix_159,
	eu_prefix_160,
	eu_prefix_161,
	eu_prefix_162,
	eu_prefix_163,
	eu_prefix_164,
	eu_prefix_165,
	eu_prefix_166,
	eu_prefix_167,
	eu_prefix_168,
	eu_prefix_169,
	eu_prefix_170,
	eu_prefix_171,
	eu_prefix_172,
	eu_prefix_173,
	eu_prefix_174,
	eu_prefix_175,
	eu_prefix_176,
	eu_prefix_177,
	eu_prefix_178,
	eu_prefix_179,
	eu_prefix_180,
	eu_prefix_181,
	eu_prefix_182,
	eu_prefix_183,
	eu_prefix_184,
	eu_prefix_185,
	eu_prefix_186,
	eu_prefix_187,
	eu_prefix_188,
	eu_prefix_189,
	eu_prefix_190/*,
	eu_prefix_191*/
	};



