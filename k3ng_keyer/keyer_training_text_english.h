// English word list originally from gen_cw_words.pl - a program that generates words in a random order, 
//   intended to be used during morse code practice.
// Original gen_cw_words.pl code Copyright (C) 2015,2017 Andy Stewart (KB1OIQ)
// https://sourceforge.net/projects/kb1oiq-k1ig-wordsworth/

// two letter word array
const char s2_1[] PROGMEM = "to";
const char s2_2[] PROGMEM = "in";
const char s2_3[] PROGMEM = "it";
const char s2_4[] PROGMEM = "is";
const char s2_5[] PROGMEM = "be";
const char s2_6[] PROGMEM = "as";
const char s2_7[] PROGMEM = "at";
const char s2_8[] PROGMEM = "so";
const char s2_9[] PROGMEM = "we";
const char s2_10[] PROGMEM = "he";
const char s2_11[] PROGMEM = "by";
const char s2_12[] PROGMEM = "or";
const char s2_13[] PROGMEM = "on";
const char s2_14[] PROGMEM = "do";
const char s2_15[] PROGMEM = "if";
const char s2_16[] PROGMEM = "me";
const char s2_17[] PROGMEM = "my";
const char s2_18[] PROGMEM = "up";
const char s2_19[] PROGMEM = "an";
const char s2_20[] PROGMEM = "go";
const char s2_21[] PROGMEM = "no";
const char s2_22[] PROGMEM = "us";
const char s2_23[] PROGMEM = "am";
const char s2_24[] PROGMEM = "of";
const byte s2_size = 24;
const char* const s2_table[] PROGMEM = 
  {s2_1,s2_2,s2_3,s2_4,s2_5,s2_6,s2_7,s2_8,s2_9,s2_10,
   s2_11,s2_12,s2_13,s2_14,s2_15,s2_16,s2_17,s2_18,s2_19,s2_20,
   s2_21,s2_22,s2_23,s2_24};

// three letter word array
const char s3_1[] PROGMEM = "the";
const char s3_2[] PROGMEM = "and";
const char s3_3[] PROGMEM = "for";
const char s3_4[] PROGMEM = "are";
const char s3_5[] PROGMEM = "but";
const char s3_6[] PROGMEM = "not";
const char s3_7[] PROGMEM = "you";
const char s3_8[] PROGMEM = "all";
const char s3_9[] PROGMEM = "any";
const char s3_10[] PROGMEM = "can";
const char s3_11[] PROGMEM = "had";
const char s3_12[] PROGMEM = "her";
const char s3_13[] PROGMEM = "was";
const char s3_14[] PROGMEM = "one";
const char s3_15[] PROGMEM = "our";
const char s3_16[] PROGMEM = "out";
const char s3_17[] PROGMEM = "day";
const char s3_18[] PROGMEM = "get";
const char s3_19[] PROGMEM = "has";
const char s3_20[] PROGMEM = "him";
const char s3_21[] PROGMEM = "his";
const char s3_22[] PROGMEM = "how";
const char s3_23[] PROGMEM = "man";
const char s3_24[] PROGMEM = "new";
const char s3_25[] PROGMEM = "now";
const char s3_26[] PROGMEM = "old";
const char s3_27[] PROGMEM = "see";
const char s3_28[] PROGMEM = "two";
const char s3_29[] PROGMEM = "way";
const char s3_30[] PROGMEM = "who";
const char s3_31[] PROGMEM = "boy";
const char s3_32[] PROGMEM = "did";
const char s3_33[] PROGMEM = "its";
const char s3_34[] PROGMEM = "let";
const char s3_35[] PROGMEM = "put";
const char s3_36[] PROGMEM = "say";
const char s3_37[] PROGMEM = "she";
const char s3_38[] PROGMEM = "too";
const char s3_39[] PROGMEM = "use";
const byte s3_size = 39;
const char* const s3_table[] PROGMEM = 
  {s3_1,s3_2,s3_3,s3_4,s3_5,s3_6,s3_7,s3_8,s3_9,s3_10,
   s3_11,s3_12,s3_13,s3_14,s3_15,s3_16,s3_17,s3_18,s3_19,s3_20,
   s3_21,s3_22,s3_23,s3_24,s3_25,s3_26,s3_27,s3_28,s3_29,s3_30,
   s3_31,s3_32,s3_33,s3_34,s3_35,s3_36,s3_37,s3_38,s3_39};

// four letter word array
const char s4_1[] PROGMEM = "that";
const char s4_2[] PROGMEM = "with";
const char s4_3[] PROGMEM = "have";
const char s4_4[] PROGMEM = "this";
const char s4_5[] PROGMEM = "will";
const char s4_6[] PROGMEM = "your";
const char s4_7[] PROGMEM = "from";
const char s4_8[] PROGMEM = "they";
const char s4_9[] PROGMEM = "know";
const char s4_10[] PROGMEM = "want";
const char s4_11[] PROGMEM = "been";
const char s4_12[] PROGMEM = "good";
const char s4_13[] PROGMEM = "much";
const char s4_14[] PROGMEM = "some";
const char s4_15[] PROGMEM = "time";
const char s4_16[] PROGMEM = "very";
const char s4_17[] PROGMEM = "when";
const char s4_18[] PROGMEM = "come";
const char s4_19[] PROGMEM = "here";
const char s4_20[] PROGMEM = "just";
const char s4_21[] PROGMEM = "like";
const char s4_22[] PROGMEM = "long";
const char s4_23[] PROGMEM = "make";
const char s4_24[] PROGMEM = "many";
const char s4_25[] PROGMEM = "more";
const char s4_26[] PROGMEM = "only";
const char s4_27[] PROGMEM = "over";
const char s4_28[] PROGMEM = "such";
const char s4_29[] PROGMEM = "take";
const char s4_30[] PROGMEM = "than";
const char s4_31[] PROGMEM = "them";
const char s4_32[] PROGMEM = "well";
const char s4_33[] PROGMEM = "were";
const byte s4_size = 33;
const char* const s4_table[] PROGMEM = 
  {s4_1,s4_2,s4_3,s4_4,s4_5,s4_6,s4_7,s4_8,s4_9,s4_10,
   s4_11,s4_12,s4_13,s4_14,s4_15,s4_16,s4_17,s4_18,s4_19,s4_20,
   s4_21,s4_22,s4_23,s4_24,s4_25,s4_26,s4_27,s4_28,s4_29,s4_30,
   s4_31,s4_32,s4_33};

 

const char name_1[] PROGMEM = "Andy";
const char name_2[] PROGMEM = "Bob";
const char name_3[] PROGMEM = "Bill";
const char name_4[] PROGMEM = "John";
const char name_5[] PROGMEM = "George";
const char name_6[] PROGMEM = "Tom";
const char name_7[] PROGMEM = "Rich";
const char name_8[] PROGMEM = "Steve";
const char name_9[] PROGMEM = "Tim";
const char name_10[] PROGMEM = "Scott";
const char name_11[] PROGMEM = "Fred";
const char name_12[] PROGMEM = "Doug";
const char name_13[] PROGMEM = "Dave";
const char name_14[] PROGMEM = "Gary";
const char name_15[] PROGMEM = "Jim";
const char name_16[] PROGMEM = "Chris";
const char name_17[] PROGMEM = "Mike";
const char name_18[] PROGMEM = "Ed";
const char name_19[] PROGMEM = "Al";
const char name_20[] PROGMEM = "Alan";
const char name_21[] PROGMEM = "Ron";
const char name_22[] PROGMEM = "Jerry";
const char name_23[] PROGMEM = "Art";
const char name_24[] PROGMEM = "Greg";
const char name_25[] PROGMEM = "Rick";
const char name_26[] PROGMEM = "Dan";
const char name_27[] PROGMEM = "Ken";
const char name_28[] PROGMEM = "Tony";
const char name_29[] PROGMEM = "Carl";
const char name_30[] PROGMEM = "Phil";
const char name_31[] PROGMEM = "Joe";
const char name_32[] PROGMEM = "Jon";
const char name_33[] PROGMEM = "Larry";
const char name_34[] PROGMEM = "Don";
const char name_35[] PROGMEM = "Dick";
const char name_36[] PROGMEM = "Paul";
const char name_37[] PROGMEM = "Serge";
const char name_38[] PROGMEM = "Alex";
const char name_39[] PROGMEM = "Vlad";
const char name_40[] PROGMEM = "Jeff";
const char name_41[] PROGMEM = "Chas";
const char name_42[] PROGMEM = "Jack";
const char name_43[] PROGMEM = "Gene";
const char name_44[] PROGMEM = "Bert";
const char name_45[] PROGMEM = "Oleg";
const char name_46[] PROGMEM = "Pete";
const char name_47[] PROGMEM = "Pat";
const char name_48[] PROGMEM = "Juan";
const char name_49[] PROGMEM = "Gus";
const byte name_size = 49;
const char* const name_table[] PROGMEM = 
  {name_1,name_2,name_3,name_4,name_5,name_6,name_7,name_8,name_9,name_10,
   name_11,name_12,name_13,name_14,name_15,name_16,name_17,name_18,name_19,name_20,
   name_21,name_22,name_23,name_24,name_25,name_26,name_27,name_28,name_29,name_30,
   name_31,name_32,name_33,name_34,name_35,name_36,name_37,name_38,name_39,name_40,
   name_41,name_42,name_43,name_44,name_45,name_46,name_47,name_48,name_49};

// CW QSO word array
const char qso_1[] PROGMEM = "QRL?";
const char qso_2[] PROGMEM = "QRM";
const char qso_3[] PROGMEM = "QRN";
const char qso_4[] PROGMEM = "QRS";
const char qso_5[] PROGMEM = "QRT";
const char qso_6[] PROGMEM = "QRZ";
const char qso_7[] PROGMEM = "QSL";
const char qso_8[] PROGMEM = "QSO";
const char qso_9[] PROGMEM = "QSY";
const char qso_10[] PROGMEM = "QTH";
const char qso_11[] PROGMEM = "QRX";
const char qso_12[] PROGMEM = "ABT";
const char qso_13[] PROGMEM = "AGE";
const char qso_14[] PROGMEM = "ANT";
const char qso_15[] PROGMEM = "BEAM";
const char qso_16[] PROGMEM = "BK";
const char qso_17[] PROGMEM = "QRP";
const char qso_18[] PROGMEM = "AGN";
const char qso_19[] PROGMEM = "C";
const char qso_20[] PROGMEM = "CL";
const char qso_21[] PROGMEM = "CPY";
const char qso_22[] PROGMEM = "CQ";
const char qso_23[] PROGMEM = "CUL";
const char qso_24[] PROGMEM = "DE";
const char qso_25[] PROGMEM = "DX";
const char qso_26[] PROGMEM = "ES";
const char qso_27[] PROGMEM = "EL";
const char qso_28[] PROGMEM = "FB";
const char qso_29[] PROGMEM = "HI";
const char qso_30[] PROGMEM = "HW?";
const char qso_31[] PROGMEM = "HR";
const char qso_32[] PROGMEM = "K";
const char qso_33[] PROGMEM = "=";
const char qso_34[] PROGMEM = "<";
const char qso_35[] PROGMEM = "%";
const char qso_36[] PROGMEM = ">";
const char qso_37[] PROGMEM = "LID";
const char qso_38[] PROGMEM = "LOOP";
const char qso_39[] PROGMEM = "NAME";
const char qso_40[] PROGMEM = "OM";
const char qso_41[] PROGMEM = "OP";
const char qso_42[] PROGMEM = "PKT";
const char qso_43[] PROGMEM = "PSE";
const char qso_44[] PROGMEM = "R";
const char qso_45[] PROGMEM = "RPT";
const char qso_46[] PROGMEM = "RST";
const char qso_47[] PROGMEM = "RIG";
const char qso_48[] PROGMEM = "TEMP";
const char qso_49[] PROGMEM = "TEST";
const char qso_50[] PROGMEM = "TU";
const char qso_51[] PROGMEM = "TKS";
const char qso_52[] PROGMEM = "TNX";
const char qso_53[] PROGMEM = "VERT";
const char qso_54[] PROGMEM = "WATT";
const char qso_55[] PROGMEM = "WX";
const char qso_56[] PROGMEM = "YAGI";
const char qso_57[] PROGMEM = "YRS";
const char qso_58[] PROGMEM = "73";
const char qso_59[] PROGMEM = "88";
const char qso_60[] PROGMEM = "?";
const char qso_61[] PROGMEM = "/";
const char qso_62[] PROGMEM = "VY";
const char qso_63[] PROGMEM = "YL";
const char qso_64[] PROGMEM = "XYL";
const char qso_65[] PROGMEM = "MY";
const char qso_66[] PROGMEM = "UR";
const char qso_67[] PROGMEM = "IS";
const char qso_68[] PROGMEM = "QSB";
const char qso_69[] PROGMEM = "QRQ";
const char qso_70[] PROGMEM = "HVE";
const char qso_71[] PROGMEM = "HPE";
const char qso_72[] PROGMEM = "BEST";
const byte qso_size = 72;
const char* const qso_table[] PROGMEM = 
  {qso_1,qso_2,qso_3,qso_4,qso_5,qso_6,qso_7,qso_8,qso_9,qso_10,qso_11,qso_12,qso_13,qso_14,qso_15,qso_16,qso_17,qso_18,qso_19,qso_20,
  qso_21,qso_22,qso_23,qso_24,qso_25,qso_26,qso_27,qso_28,qso_29,qso_30,qso_31,qso_32,qso_33,qso_34,qso_35,qso_36,qso_37,qso_38,qso_39,qso_40,
  qso_41,qso_42,qso_43,qso_44,qso_45,qso_46,qso_47,qso_48,qso_49,qso_50,qso_51,qso_52,qso_53,qso_54,qso_55,qso_56,qso_57,qso_58,qso_59,qso_60,
  qso_61,qso_62,qso_63,qso_64,qso_65,qso_66,qso_67,qso_68,qso_69,qso_70,qso_71,qso_72};


