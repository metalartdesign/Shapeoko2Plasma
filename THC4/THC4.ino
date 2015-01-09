/*
 * Timer 3 counts the 1Mhz reference from the THCAD (Port E bit 6)
 * Timer 4 counts the signal from the THCAD (Port H bit 7)
 * Timer 5 controls the output to the stepper driver (pins 45-46)
 * Int4 is the input from the parallel port (pin 2) counting pulses
 * Int5 is the input from the parallel port (pin 3) reading direction
 * Int7 is the input from the parallel port (Port E bit 7) THC ON
 *
 * Created: 5/30/2014 2:10:21 PM
 * Author: owner
 */
 #include <avr/pgmspace.h>
 
 
 
PROGMEM  prog_uint16_t stepToOCR[] = {1830,1828,1826,1824,1822,1820,1818,1816,1814,1812,1810,1808,1806,1804,1802,1800,1798,1796,1794,1792,1790,1789,1787,1785,1783,1781,1779,1777,1775,1773,1771,1769,1767,1765,1763,1762,1760,1758,1756,1754,1752,1750,1748,1746,1744,1743,1741,1739,1737,1735,1733,1731,1729,1728,1726,1724,1722,1720,1718,1716,1715,1713,1711,1709,1707,1705,1703,1702,1700,1698,1696,1694,1692,1691,1689,1687,1685,1683,1682,1680,1678,1676,1674,1673,1671,1669,1667,1665,1664,1662,1660,1658,1657,1655,1653,1651,1649,1648,1646,1644,1642,1641,1639,1637,1635,1634,1632,1630,1628,1627,1625,1623,1621,1620,1618,1616,1615,1613,1611,1609,1608,1606,1604,1603,1601,1599,1598,1596,1594,1592,1591,1589,1587,1586,1584,1582,1581,1579,1577,1576,1574,1572,1571,1569,1567,1566,1564,1562,1561,1559,1557,1556,1554,1552,1551,1549,1548,1546,1544,1543,1541,1539,1538,1536,1535,1533,1531,1530,1528,1527,1525,1523,1522,1520,1519,1517,1515,1514,1512,1511,1509,1507,1506,1504,1503,1501,1500,1498,1496,1495,1493,1492,1490,1489,1487,1486,1484,1482,1481,1479,1478,1476,1475,1473,1472,1470,1469,1467,1466,1464,1463,1461,1459,1458,1456,1455,1453,1452,1450,1449,1447,1446,1444,1443,1441,1440,1438,1437,1435,1434,1432,1431,1430,1428,1427,1425,1424,1422,1421,1419,1418,1416,1415,1413,1412,1410,1409,1408,1406,1405,1403,1402,1400,1399,1397,1396,1395,1393,1392,1390,1389,1387,1386,1385,1383,1382,1380,1379,1378,1376,1375,1373,1372,1371,1369,1368,1366,1365,1364,1362,1361,1359,1358,1357,1355,1354,1352,1351,1350,1348,1347,1346,1344,1343,1342,1340,1339,1337,1336,1335,1333,1332,1331,1329,1328,1327,1325,1324,1323,1321,1320,1319,1317,1316,1315,1313,1312,1311,1309,1308,1307,1305,1304,1303,1301,1300,1299,1298,1296,1295,1294,1292,1291,1290,1288,1287,1286,1285,1283,1282,1281,1279,1278,1277,1276,1274,1273,1272,1271,1269,1268,1267,1265,1264,1263,1262,1260,1259,1258,1257,1255,1254,1253,1252,1250,1249,1248,1247,1245,1244,1243,1242,1241,1239,1238,1237,1236,1234,1233,1232,1231,1230,1228,1227,1226,1225,1223,1222,1221,1220,1219,1217,1216,1215,1214,1213,1211,1210,1209,1208,1207,1206,1204,1203,1202,1201,1200,1198,1197,1196,1195,1194,1193,1191,1190,1189,1188,1187,1186,1184,1183,1182,1181,1180,1179,1178,1176,1175,1174,1173,1172,1171,1170,1168,1167,1166,1165,1164,1163,1162,1160,1159,1158,1157,1156,1155,1154,1153,1152,1150,1149,1148,1147,1146,1145,1144,1143,1142,1140,1139,1138,1137,1136,1135,1134,1133,1132,1131,1130,1128,1127,1126,1125,1124,1123,1122,1121,1120,1119,1118,1117,1116,1114,1113,1112,1111,1110,1109,1108,1107,1106,1105,1104,1103,1102,1101,1100,1099,1098,1097,1096,1094,1093,1092,1091,1090,1089,1088,1087,1086,1085,1084,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1054,1053,1052,1051,1050,1049,1048,1047,1046,1045,1044,1043,1042,1041,1040,1039,1038,1037,1036,1035,1035,1034,1033,1032,1031,1030,1029,1028,1027,1026,1025,1024,1023,1022,1021,1020,1019,1018,1017,1016,1016,1015,1014,1013,1012,1011,1010,1009,1008,1007,1006,1005,1004,1003,1003,1002,1001,1000,999,998,997,996,995,994,993,993,992,991,990,989,988,987,986,985,984,984,983,982,981,980,979,978,977,976,976,975,974,973,972,971,970,969,968,968,967,966,965,964,963,962,962,961,960,959,958,957,956,956,955,954,953,952,951,950,950,949,948,947,946,945,944,944,943,942,941,940,939,939,938,937,936,935,934,934,933,932,931,930,929,929,928,927,926,925,925,924,923,922,921,920,920,919,918,917,916,916,915,914,913,912,912,911,910,909,908,908,907,906,905,904,904,903,902,901,901,900,899,898,897,897,896,895,894,893,893,892,891,890,890,889,888,887,887,886,885,884,883,883,882,881,880,880,879,878,877,877,876,875,874,874,873,872,871,871,870,869,868,868,867,866,865,865,864,863,862,862,861,860,860,859,858,857,857,856,855,854,854,853,852,852,851,850,849,849,848,847,847,846,845,844,844,843,842,842,841,840,839,839,838,837,837,836,835,835,834,833,832,832,831,830,830,829,828,828,827,826,826,825,824,823,823,822,821,821,820,819,819,818,817,817,816,815,815,814,813,813,812,811,811,810,809,809,808,807,807,806,805,805,804,803,803,802,801,801,800,799,799,798,797,797,796,795,795,794,794,793,792,792,791,790,790,789,788,788,787,786,786,785,785,784,783,783,782,781,781,780,780,779,778,778,777,776,776,775,775,774,773,773,772,771,771,770,770,769,768,768,767,767,766,765,765,764,763,763,762,762,761,760,760,759,759,758,757,757,756,756,755,754,754,753,753,752,752,751,750,750,749,749,748,747,747,746,746,745,744,744,743,743,742,742,741,740,740,739,739,738,738,737,736,736,735,735,734,734,733,732,732,731,731,730,730,729,729,728,727,727,726,726,725,725,724,723,723,722,722,721,721,720,720,719,719,718,717,717,716,716,715,715,714,714,713,713,712,711,711,710,710,709,709,708,708,707,707,706,706,705,705,704,703,703,702,702,701,701,700,700,699,699,698,698,697,697,696,696,695,695,694,694,693,693,692,692,691,690,690,689,689,688,688,687,687,686,686,685,685,684,684,683,683,682,682,681,681,680,680,679,679,678,678,677,677,676,676,675,675,674,674,674,673,673,672,672,671,671,670,670,669,669,668,668,667,667,666,666,665,665,664,664,663,663,662,662,661,661,661,660,660,659,659,658,658,657,657,656,656,655,655,654,654,654,653,653,652,652,651,651,650,650,649,649,648,648,648,647,647,646,646,645,645,644,644,644,643,643,642,642,641,641,640,640,639,639,639,638,638,637,637,636,636,636,635,635,634,634,633,633,632,632,632,631,631,630,630,629,629,629,628,628,627,627,626,626,626,625,625,624,624,623,623,623,622,622,621,621,621,620,620,619,619,618,618,618,617,617,616,616,616,615,615,614,614,613,613,613,612,612,611,611,611,610,610,609,609,609,608,608,607,607,607,606,606,605,605,605,604,604,603,603,603,602,602,601,601,601,600,600,599,599,599,598,598,597,597,597,596,596,596,595,595,594,594,594,593,593,592,592,592,591,591,591,590,590,589,589,589,588,588,588,587,587,586,586,586,585,585,585,584,584,583,583,583,582,582,582,581,581,580,580,580,579,579,579,578,578,578,577,577,576,576,576,575,575,575,574,574,574,573,573,573,572,572,571,571,571,570,570,570,569,569,569,568,568,568,567,567,567,566,566,565,565,565,564,564,564,563,563,563,562,562,562,561,561,561,560,560,560,559,559,559,558,558,558,557,557,557,556,556,556,555,555,555,554,554,554,553,553,553,552,552,552,551,551,551,550,550,550,549,549,549,548,548,548,547,547,547,546,546,546,545,545,545,544,544,544,544,543,543,543,542,542,542,541,541,541,540,540,540,539,539,539,538,538,538,538,537,537,537,536,536,536,535,535,535,534,534,534,534,533,533,533,532,532,532,531,531,531,531,530,530,530,529,529,529,528,528,528,528,527,527,527,526,526,526,525,525,525,525,524,524,524,523,523,523,523,522,522,522,521,521,521,520,520,520,520,519,519,519,518,518,518,518,517,517,517,516,516,516,516,515,515,515,515,514,514,514,513,513,513,513,512,512,512,511,511,511,511,510,510,510,510,509,509,509,508,508,508,508,507,507,507,507,506,506,506,505,505,505,505,504,504,504,504,503,503,503,503,502,502,502,501,501,501,501,500,500,500,500,499,499,499,499,498,498,498,498,497,497,497,497,496,496,496,495,495,495,495,494,494,494,494,493,493,493,493,492,492,492,492,491,491,491,491,490,490,490,490,489,489,489,489,488,488,488,488,487,487,487,487,486,486,486,486,486,485,485,485,485,484,484,484,484,483,483,483,483,482,482,482,482,481,481,481,481,480,480,480,480,480,479,479,479,479,478,478,478,478,477,477,477,477,477,476,476,476,476,475,475,475,475,474,474,474,474,474,473,473,473,473,472,472,472,472,472,471,471,471,471,470,470,470,470,470,469,469,469,469,468,468,468,468,468,467,467,467,467,466,466,466,466,466,465,465,465,465,464,464,464,464,464,463,463,463,463,463,462,462,462,462,461,461,461,461,461,460,460,460,460,460,459,459,459,459,459,458,458,458,458,458,457,457,457,457,457,456,456,456,456,455,455,455,455,455,454,454,454,454,454,453,453,453,453,453,452,452,452,452,452,451,451,451,451,451,450,450,450,450,450,450,449,449,449,449,449,448,448,448,448,448,447,447,447,447,447,446,446,446,446,446,445,445,445,445,445,445,444,444,444,444,444,443,443,443,443,443,442,442,442,442,442,442,441,441,441,441,441,440,440,440,440,440,439,439,439,439,439,439,438,438,438,438,438,437,437,437,437,437,437,436,436,436,436,436,436,435,435,435,435,435,434,434,434,434,434,434,433,433,433,433,433,433,432,432,432,432,432,432,431,431,431,431,431,430,430,430,430,430,430,429,429,429,429,429,429,428,428,428,428,428,428,427,427,427,427,427,427,426,426,426,426,426,426,425,425,425,425,425,425,424,424,424,424,424,424,424,423,423,423,423,423,423,422,422,422,422,422,422,421,421,421,421,421,421,420,420,420,420,420,420,420,419,419,419,419,419,419,418,418,418,418,418,418,418,417,417,417,417,417,417,416,416,416,416,416,416,416,415,415,415,415,415,415,414,414,414,414,414,414,414,413,413,413,413,413,413,413,412,412,412,412,412,412,412,411,411,411,411,411,411,411,410,410,410,410,410,410,410,409,409,409,409,409,409,409,408,408,408,408,408,408,408,407,407,407,407,407,407,407,406,406,406,406,406,406,406,405,405,405,405,405,405,405,404,404,404,404,404,404,404,404,403,403,403,403,403,403,403,402,402,402,402,402,402,402,402,401,401,401,401,401,401,401,400,400,400,400,400,400,400,400,399,399,399,399,399,399,399,398,398,398,398,398,398,398,398,397,397,397,397,397,397,397,397,396,396,396,396,396,396,396,396,395,395,395,395,395,395,395,395,394,394,394,394,394,394,394,394,393,393,393,393,393,393,393,393,393,392,392,392,392,392,392,392,392,391,391,391,391,391,391,391,391,390,390,390,390,390,390,390,390,390,389,389,389,389,389,389,389,389,388,388,388,388,388,388,388,388,388,387,387,387,387,387,387,387,387,387,386,386,386,386,386,386,386,386,386,385,385,385,385,385,385,385,385,385,384,384,384,384,384,384,384,384,384,383,383,383,383,383,383,383,383,383,382,382,382,382,382,382,382,382,382,381,381,381,381,381,381,381,381,381,381,380,380,380,380,380,380,380,380,380,379,379,379,379,379,379,379,379,379,379,378,378,378,378,378,378,378,378,378,378,377,377,377,377,377,377,377,377,377,377,376,376,376,376,376,376,376,376,376,376,375,375,375,375,375,375,375,375,375,375,374,374,374,374,374,374,374,374,374,374,373,373,373,373,373,373,373,373,373,373,373,372,372,372,372,372,372,372,372,372,372,371,371,371,371,371,371,371,371,371,371,371,370,370,370,370,370,370,370,370,370,370,370,369,369,369,369,369,369,369,369,369,369,369,368,368,368,368,368,368,368,368,368,368,368,367,367,367,367,367,367,367,367,367,367,367,367,366,366,366,366,366,366,366,366,366,366,366,365,365,365,365,365,365,365,365,365,365,365,365,364,364,364,364,364,364,364,364,364,364,364,364,363,363,363,363,363,363,363,363,363,363,363,363,362,362,362,362,362,362,362,362,362,362,362,362,362,361,361,361,361,361,361,361,361,361,361,361,361,360,360,360,360,360,360,360,360,360,360,360,360,360,359,359,359,359,359,359,359,359,359,359,359,359,359,358,358,358,358,358,358,358,358,358,358,358,358,358,357,357,357,357,357,357,357,357,357,357,357,357,357,356,356,356,356,356,356,356,356,356,356,356,356,356,356,355,355,355,355,355,355,355,355,355,355,355,355,355,355,354,354,354,354,354,354,354,354,354,354,354,354,354,354,353,353,353,353,353,353,353,353,353,353,353,353,353,353,353,352,352,352,352,352,352,352,352,352,352,352,352,352,352,351,351,351,351,351,351,351,351,351,351,351,351,351,351,351,350,350,350,350,350,350,350,350,350,350,350,350,350,350,350,350,349,349,349,349,349,349,349,349,349,349,349,349,349,349,349,348,348,348,348,348,348,348,348,348,348,348,348,348,348,348,348,347,347,347,347,347,347,347,347,347,347,347,347,347,347,347,347,346,346,346,346,346,346,346,346,346,346,346,346,346,346,346,346,346,345,345,345,345,345,345,345,345,345,345,345,345,345,345,345,345,345,344,344,344,344,344,344,344,344,344,344,344,344,344,344,344,344,344,343,343,343,343,343,343,343,343,343,343,343,343,343,343,343,343,343,343,342,342,342,342,342,342,342,342,342,342,342,342,342,342,342,342,342,342,341,341,341,341,341,341,341,341,341,341,341,341,341,341,341,341,341,341,341,340,340,340,340,340,340,340,340,340,340,340,340,340,340,340,340,340,340,340,339,339,339,339,339,339,339,339,339,339,339,339,339,339,339,339,339,339,339,339,338,338,338,338,338,338,338,338,338,338,338,338,338,338,338,338,338,338,338,338,337,337,337,337,337,337,337,337,337,337,337,337,337,337,337,337,337,337,337,337,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,336,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,335,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,334,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,332,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,331,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,330,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,329,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,328,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,325,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,324,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,321,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,320,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,318,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,317,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,315,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,314,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,313,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,311,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,310,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,309,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,308,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,307,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,306,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,305,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,304,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,303,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,302,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,301,300,300,300,300};

int stepIndex = 0;
int stepIndexMax = 5000;
int newOCR = 0;


int timer4Val = 0; 
int interruptCntr = 0;
boolean porte4s = false;
boolean porte5s = false;
float voltageACT = 0.0;
float voltageSP = 1; //139.0; //70.0;  //*************************************************** for troubleshooting ***********************************************
float deadBand = 0.5;   //*************************************************** for troubleshooting ***********************************************
long thcCorrectInc = 1;
int FreqZero = 1212;
int incomingByte = 0;
long currPosACT = 1000000;
long currPosIN = 1000000;
long currPosSP = 1000000;
long thcOffset = 0;
boolean timer5ON = false;
int temp = 0;
boolean zDirIn = false;
boolean thcOn = false;
float thcKP = 0.110;  //*************************************************** for troubleshooting ***********************************************
float voltageERR = 0.0;
boolean voltageUpdated = 0;
unsigned int junkCounter = 0;
boolean returnToCmdPos = 0;


int rampMin = 230;
int rampMax = 1830;
//float rampVel = 1830;
//float rampOCR = 1830;
int rampDeltaErr = 0;
int rampErrDir = 0;
int rampMotorDir = 0;
//float rampAccelInc = 0.5;


//Only called upon startup
void setup()
{
  
        DDRB |= _BV(DDB7); // set direction for the LED
        
        
	DDRL |= _BV(DDL4) | _BV(DDL3); //set them as outputs  
	
	Serial.begin(115200);  //*************************************************** for troubleshooting ***********************************************
        Serial.println("Serial Started");   //*************************************************** for troubleshooting ***********************************************
		
//////// TIMER 3 ///////// TIMER 3 ////////
	  
	// External clock, Clear timer on Compare Match
	TCCR3A = 0x0;
	TCCR3B = _BV(WGM32)|_BV(CS32) | _BV(CS31) | _BV(CS30);
		
	//Set the top and enable the interrupt
	OCR3A = 0x285C; //A17; //This is how many counts of the 1MHz signal to count
	TIMSK3 = _BV(OCIE3A);
		
	//Set the pin as an input Port E bit 6
	DDRE &= ~_BV(DDE6);

//////// TIMER 4 ///////// TIMER 4 ////////		
			
	//Normal counter, select external Clock rising edge 
	TCCR4A = 0x0;
	TCCR4B = _BV(CS42) | _BV(CS41) | _BV(CS40);
		
	// Set Port H Bit 7 as an input
	DDRH &= ~_BV(DDH7);
	
//////// TIMER 5 ///////// TIMER 5 ////////
	
	//Set it to toggle the bit on COM5B on match (phase and freq correct	
	TCCR5A = _BV(COM5B1) | _BV(WGM50);
	TCCR5B = _BV(WGM53); //leave the clock off for now
	
	//Set the top and compare value
	//OCR5A = 0xE6; //E6=230//398=920//730=1840 is 115uS with no prescaling (top)
	//OCR5B = 0x73; //73=115//1CC=460//398=920 is 57.5uS with no prescaling (toggle bit)
        OCR5A = 0x726; //E6=230//398=920//730=1840 is 115uS with no prescaling (top)
	OCR5B = 0x393;
	
	TIMSK5 = _BV(TOIE5); //enable bottom interrupt	
	
///////////// EXTERNAL INTERRUPTS /////////////////////////

	//Set the external interrupt edge triggers	
	EICRB =  _BV(ISC70)| _BV(ISC50) | _BV(ISC41) | _BV(ISC40);
	
	//Enable the external interrupt
	EIMSK = _BV(INT7) | _BV(INT5) | _BV(INT4);
	
	//Set port E bit 4 as an input and enable pull up resistor
	DDRE &= ~_BV(DDE4);
	PORTE |= _BV(PORTE4);
	
	//Set port E bit 5 as an input and enable pull up resistor
	DDRE &= ~_BV(DDE5);
	PORTE |= _BV(PORTE5);
	
	//Set port E bit 7 as an input and enable pull up resistor
	DDRE &= ~_BV(DDE7);
	PORTE |= _BV(PORTE7);
	

	
	// Clear all timers
	TCNT3 = 0;
	TCNT4 = 0;
	TCNT5 = 0;
	
	currPosACT = 1000000;
	currPosIN = 1000000;
	currPosSP = 1000000;
	timer5ON = 0;
	
//NEED TO INITIALIZE THE PINS THAT ARE INTERRUPT DRIVEN
	temp = PINE & _BV(PINE7);
	
	if (temp != 0)
		thcOn = 1;
	else
		thcOn = 0;
		
	temp = PINE & _BV(PINE5);
			
	if (temp != 0)
		zDirIn = 1;
	else
		zDirIn = 0;
	
//thcOn = 1;   //*************************************************** for troubleshooting ***********************************************
}

//STEP counter from the PC
ISR(INT4_vect) 
{
	//porte4s = ~porte4s;

	if (zDirIn != 0)
		currPosIN--;
	else
		currPosIN++;
		
	//if(!thcOn)
	//	currPosSP = currPosIN;
}

//Direction monitor from the PC
ISR(INT5_vect) 
{
	//porte5s = ~porte5s;
	
	temp = PINE & _BV(PINE5);
	
	if (temp != 0)
		zDirIn = 1;
	else
		zDirIn = 0;	
}

//Monitors the THC ON/OFF command from the PC
ISR(INT7_vect)
{
	//This is where the THC Enable is monitored
	temp = PINE & _BV(PINE7);
		
	if (temp != 0)
        {
		voltageSP = voltageACT;
                thcOffset = 0;
                thcOn = 1;                
        }
	else
	{
                thcOn = 0;

	}
}

//Collects the counts from the V/F converter
ISR(TIMER3_COMPA_vect)
{
	timer4Val = TCNT4;
	TCNT4 = 0;
	voltageUpdated = 1;
}

// Updates the output position, issues new step, or stops stepping
// We only arrive here after a step has been completed
ISR(TIMER5_OVF_vect ) 
{
	//Sample the pin to see which direction it moved
	temp = PINL & _BV(PINL3);
	
	if (temp != 0)
		currPosACT--;
	else
		currPosACT++;

       // check if we have arrived at the SP and if we are going slow enough to stop
       if( currPosACT == currPosSP ) //&& stepIndex <= 1)
        {
            //no pulses are needed, stop the timer	
 	    TCCR5B &= 0xF8;
 	    timer5ON = 0;
            stepIndex = 0;
 	 
        }                
        else if( temp == 0 && currPosSP > currPosACT ) // if we are moving up and we should be
        {
           if( currPosSP > ( currPosACT + stepIndex )) //See if we have time to continue to speed up
           {
              stepIndex++; //Speed up
              
              if( stepIndex > stepIndexMax )
                stepIndex = stepIndexMax;
              
              //newOCR = stepToOCR[stepIndex];
              newOCR = pgm_read_word_near(stepToOCR + stepIndex);
                
              OCR5A = newOCR;
              OCR5B = newOCR/2;
           }
           else if( currPosSP <= ( currPosACT + stepIndex  )) //Do we have to start slowing down
           {
              if (stepIndex>0)
                  stepIndex--; //Slow down

              newOCR = pgm_read_word_near(stepToOCR + stepIndex); //newOCR = stepToOCR[stepIndex];
                
              OCR5A = newOCR;
              OCR5B = newOCR/2;
           }
        }
        else if( temp != 0 && currPosSP < currPosACT) //if we are moving down and we should be
        {
           if( currPosSP < ( currPosACT - stepIndex  )) //See if we have time to continue to speed up
           {
              stepIndex++; //Speed up
              
              if( stepIndex > stepIndexMax )
                stepIndex = stepIndexMax;
              
              newOCR = pgm_read_word_near(stepToOCR + stepIndex); //newOCR = stepToOCR[stepIndex];
                
              OCR5A = newOCR;
              OCR5B = newOCR/2;
           }
           else if( currPosSP >= ( currPosACT - stepIndex  )) //Do we have to start slowing down
           {
              if (stepIndex>0)
                  stepIndex--; //Slow down 

              newOCR = pgm_read_word_near(stepToOCR + stepIndex); //newOCR = stepToOCR[stepIndex];
                
              OCR5A = newOCR;
              OCR5B = newOCR/2;
           }
        } 
        else //Something went wrong or we are going the wrong way
        {
          if (stepIndex>0) //are we ready to stop?
          {
                stepIndex--; //Slow down
          }
          else if (stepIndex == 0 )//Stop this ship
          {
            TCCR5B &= 0xF8;
 	    timer5ON = 0;
            stepIndex = 0;
          }
        }
}

//Calculates the voltage feedback
void calcVolts()
{
	/*	
	Voltage =  voltageFullScale * (FreqOut - FreqZero) / (freqFullScale - FreqZero)
                        300           timer4Val    121.2           961.1        121.2
	

	Where FreqOut (timer4Val) is the output frequency of the THCAD, VFS is the unipolar full scale
	range 10V or 300V or custom value determined by external resistors. FFS is the full scale
	output frequency on the calibration sticker, and FZERO is the 0V input output frequency
	on the calibration sticker.
	*/
	
	float tempV = timer4Val-1212;
	
	if(tempV <= 0)
	{
		voltageACT = 0;
	}else
	{
		voltageACT =  300 * tempV / 8399;
	}	
}

//Main loop
void loop()
{
       

	
	// if there is a new data point available
	if (voltageUpdated)
	{
  		voltageUpdated = 0;
  		calcVolts();
  
                if (thcOn)
                {
  		
        		//voltageERR = voltageSP - voltageACT;
        		
        		if (voltageACT < (voltageSP-deadBand))
        		{
        			thcOffset+=100; // += thcCorrectInc*voltageERR*thcKP;
        		}
        		else if (voltageACT > (voltageSP+deadBand))
        		{
        			thcOffset-=100;// += thcCorrectInc*voltageERR*thcKP;
        		} 
                }
	}

        //be sure the position setpoint is up to date
        if (thcOn)
        {
          currPosSP = currPosIN + thcOffset;
        }
        else
        {
          currPosSP = currPosIN;
        }
	
	
	//Start the output pulsing if it is not already
	if (timer5ON == 0 )
	{			
		if (currPosACT != currPosSP)
		{
			if (currPosACT > currPosSP)
				PORTL |= _BV(PORTL3);//set the direction	
			else 
				PORTL &= ~_BV(PORTL3);//set the direction

    		       //if( thcOn || returnToCmdPos )
                       //{
                        stepIndex = 1; //Speed up
                            
                        newOCR = pgm_read_word_near(stepToOCR + stepIndex);
                            
                        OCR5A = newOCR;
                        OCR5B = newOCR/2;
                       //}	
			
			//start the timer
			TCCR5B |= _BV(CS50); // | _BV(CS50);
			timer5ON = 1;
		}
	}
	
        //LED for troubleshooting
        if( thcOn )
          PORTB |= _BV(7);
        else
          PORTB &= ~_BV(7);
         
         

        
          
	debugJunk();	  //*************************************************** for troubleshooting ***********************************************	
}

//Just for debugging
void debugJunk()
{
  junkCounter++;
  String message = "                             \n";
/*	
	if (Serial.available() )//> 0 && timer5ON == 0)
	{
		incomingByte = Serial.read();
			
		if(incomingByte == '0')
		{
			thcOn = 0;
		}
		else if (incomingByte == '1')
		{
			thcOn = 1;
		}
	}
	
	
*/	
	
		//Serial.print(temp2,BIN);
	
	if (!(junkCounter % 2500))
	{
           
  0        1.00   1.21      0

            //Serial.print(message);
  	  Serial.print(thcOn);
  	  Serial.print("        ");
  	  Serial.print(voltageSP);
          Serial.print("   ");  
          Serial.print(voltageACT);
          Serial.print("      "); 
          Serial.println(thcOffset);
          
        /*Serial.print(thcOn,BIN);
		Serial.print(" ");
		//Serial.print(returnToCmdPos,BIN);
		//Serial.print(" ");		
                Serial.print(voltageSP,2);
		Serial.print(" ");
		Serial.print(voltageACT,2);
		Serial.print(" ");
		Serial.print(thcOffset);
		Serial.print(" ");
		//Serial.print(currPosSP);
		//Serial.print(" ");
		Serial.print(currPosACT);
		Serial.print(" ");
		Serial.println(stepIndex);
*/
	}
	

	//delay(50);
	


	/*
	
	
	temp2 = PINL & _BV(PINL4);
	
	if (temp2 > 0)
	{
		Serial.print("UP");
	}
	else
	{
		Serial.print("DN");
	}
	
	

	//Serial.print(temp2,BIN);
	

		Serial.print(" ");
	Serial.print(timer5ON);
	Serial.print(" ");
	Serial.println(currPos);
	
	delay(10);
	
	*/
	//digitalWrite(13, porte5s);
	



	
	/* 	
	Serial.print(voltage);
	Serial.print("\t ");
	Serial.println(timer4Val);
	Serial.println();
	delay(100);


	digitalWrite(13, HIGH);
	Serial.println("High");
	delay(250);
	digitalWrite(13,LOW);
	Serial.println("Low");
	delay(250);
	*/
}