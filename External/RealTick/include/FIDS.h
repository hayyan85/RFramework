#ifndef FIDDEF_FIDS_H
#define FIDDEF_FIDS_H

// This file was generated on 9/17/2012 11:25:44 AM
// by FIDManager application.
// Do not modify it manually.

#define T_PROD_CATG             1001  // INT, IDN Product Code
#define T_RDNDISPLAY            1002  // INT, IDN Display Type
#define T_DISP_NAME             1003  // STRING, Symbol
#define T_EXCHID                1004  // STRING, Exch ID
#define T_TIMACT                1005  // TIME, TimeAct
#define T_TRDPRC_1              1006  // LPACK, Last Price
#define T_TRDPRC_2              1007  // LPACK, Prev. Price
#define T_TRDPRC_3              1008  // LPACK, Prev. 2
#define T_TRDPRC_4              1009  // LPACK, Prev. 3
#define T_TRDPRC_5              1010  // LPACK, Prev. 4
#define T_NETCHNG_1             1011  // LPACK, Net Chg.
#define T_HIGH_1                1012  // LPACK, High
#define T_LOW_1                 1013  // LPACK, Low
#define T_PRCTCK_1              1014  // STRING, Up/Down
#define T_CURRENCY              1015  // STRING, Currency
#define T_TRD_DATE              1016  // DATE, Trade Date
#define T_ACTIV_DATE            1017  // DATE, Active Date
#define T_TRDTIM_1              1018  // TIME, Trade Time
#define T_OPEN_PRC              1019  // LPACK, Open
#define T_HST_CLOSE             1021  // LPACK, Hist Close
#define T_BID                   1022  // LPACK, Bid
#define T_BID_1                 1023  // LPACK, Bid 1
#define T_ASK                   1025  // LPACK, Ask
#define T_ASK_1                 1026  // LPACK, Ask 1
#define T_NEWS_PAGE             1028  // STRING, News Page
#define T_NEWS_TIME             1029  // TIME, News Time
#define T_BIDSIZE               1030  // LONG, Bid Size
#define T_ASKSIZE               1031  // LONG, Ask Size
#define T_ACVOL_1               1032  // LONG, Tot. Vol.
#define T_EARNINGS              1034  // LPACK, Earnings
#define T_YIELD                 1035  // DOUBLE, Yield
#define T_PERATIO               1036  // LPACK, P/E Ratio
#define T_DIVIDENDTP            1037  // STRING, Last Dividend Type
#define T_DIVPAYDATE            1038  // DATE, Div Pay Date
#define T_EXDIVDATE             1039  // DATE, Ex-Div Date
#define T_CTS_QUAL              1040  // INT, CTS Qualifier
#define T_CONTR_MONTH           1041  // STRING, Contract Month
#define T_BLKCOUNT              1042  // LONG, Block Trade Count
#define T_BLKVOLUM              1043  // LONG, Block Trade Total Volume
#define T_TRDXID_1              1044  // STRING, Trd Exch ID
#define T_BIDEXID               1045  // STRING, Bid Exch ID
#define T_ASKEXID               1046  // STRING, Ask Exch ID
#define T_OPEN1                 1047  // LPACK, Open 1
#define T_OPEN2                 1048  // LPACK, Open 2
#define T_OPNRNGTP              1049  // STRING, Open Range Type
#define T_CLOSE1                1050  // LPACK, Close1
#define T_CLOSE2                1051  // LPACK, Close2
#define T_CLSRNGTP              1052  // STRING, Close Range Type
#define T_TRD_UNITS             1053  // STRING, Trade Units
#define T_LOTSZUNITS            1054  // STRING, Lot Size Units
#define T_LOT_SIZE              1055  // LONG, Lot Size
#define T_PCTCHNG               1056  // DOUBLE, Percentage Change in Price
#define T_OPEN_BID              1057  // LPACK, Open Bid
#define T_OPEN_ASK              1059  // LPACK, Open Ask Price
#define T_CLOSE_BID             1060  // LPACK, Close Bid
#define T_CLOSE_ASK             1061  // LPACK, Close Ask
#define T_LOCHIGH               1062  // LPACK, Contract Life High
#define T_LOCLOW                1063  // LPACK, Contract Life Low
#define T_OPINT_1               1064  // LONG, Open Interest
#define T_OPINTNC               1065  // LONG, Open Interest Net Change
#define T_STRIKE_PRC            1066  // LPACK, Strike
#define T_EXPIR_DATE            1067  // DATE, Expir Date
#define T_MATUR_DATE            1068  // DATE, Maturity Date
#define T_COUPN_RATE            1069  // DOUBLE, Coupon Rate
#define T_SETTLE                1070  // LPACK, Settle
#define T_DIVIDEND              1071  // LPACK, Dividend
#define T_NAVOLCODE             1072  // STRING, NASD Volume Code
#define T_NOMINAL               1073  // LPACK, Nominal
#define T_UPLIMIT               1075  // LPACK, Upper Limit
#define T_LOLIMIT               1076  // LPACK, Lower Limit
#define T_NUM_MOVES             1077  // LONG, No. Trades
#define T_OFFCL_CODE            1078  // STRING, Dealer Code
#define T_HSTCLSDATE            1079  // DATE, Hist Close Date
#define T_TOT_VOLUME            1080  // LONG, Total Vol
#define T_VOLUME_ADV            1081  // LONG, Vol Adv
#define T_VOLUME_DEC            1082  // LONG, Vol Dec
#define T_VOLUME_UNC            1083  // LONG, Vol Unch
#define T_ISSUES_ADV            1084  // LONG, Issues Adv
#define T_ISSUES_DEC            1085  // LONG, Issues Dec
#define T_ISSUES_UNC            1086  // LONG, Issues Unch
#define T_MOVES_ADV             1087  // LONG, Moves Adv
#define T_MOVES_DEC             1088  // LONG, Moves Dec
#define T_MOVES_UNC             1089  // LONG, Moves Unch
#define T_YRHIGH                1090  // LPACK, Yr High
#define T_YRLOW                 1091  // LPACK, Yr Low
#define T_PRV_YRHIGH            1092  // LPACK, Previous Year High
#define T_PRV_YRLOW             1093  // LPACK, Previous Year Low
#define T_LIFE_HIGH             1094  // LPACK, Life High
#define T_LIFE_LOW              1095  // LPACK, Life Low
#define T_HIGH_52               1096  // LPACK, High 52
#define T_LOW_52                1097  // LPACK, Low 52
#define T_EPYHSTCLOS            1098  // LPACK, EPY Hist Close
#define T_LIMIT_IND             1099  // STRING, Limit Indicator
#define T_TURNOVER              1100  // DOUBLE, Turnover
#define T_NEW_LOWS              1101  // LONG, #New Lows
#define T_COUPN_DATE            1102  // DATE, Coupon Date
#define T_RATING                1103  // STRING, Bond Rating
#define T_BOND_TYPE             1104  // STRING, Bond Type
#define T_BCKGRNDPAG            1105  // STRING, BackPage
#define T_TOT_ISSUES            1106  // LONG, Total Issues
#define T_ISSUE_DATE            1107  // DATE, Issue Date
#define T_NEW_HIGHS             1108  // LONG, #New Highs
#define T_PUTCALLIND            1109  // STRING, Put/Call
#define T_YCHIGH_IND            1110  // STRING, Year High Flag
#define T_YCLOW_IND             1111  // STRING, Year Low Flag
#define T_CALL_DATE             1112  // DATE, Bond Call Date
#define T_RATING_ID             1113  // STRING, Rating ID
#define T_BID_NET_CH            1114  // LPACK, Bid Net Change
#define T_BID_TICK_1            1115  // STRING, Bid Tick
#define T_DAYS_MAT              1116  // INT, Days to Maturity
#define T_CUM_EX_MKR            1117  // STRING, Cum/Ex Marker
#define T_PRC_QL_CD             1118  // INT, Price Code
#define T_NASDSTATUS            1119  // STRING, NASD Status
#define T_NAVALUE               1120  // LPACK, NAV
#define T_NAV_NETCHN            1121  // LPACK, NAV Net Change
#define T_ASSETS                1122  // DOUBLE, Assets
#define T_AV_MATRTY             1123  // INT, Avg Maturity
#define T_YLD_7DAY              1124  // DOUBLE, Yield 7 Day
#define T_EFF7DYLD              1125  // DOUBLE, Eff 7-Day Yield
#define T_YLD_DATE              1127  // DATE, Yield Date
#define T_DURATION              1130  // INT, Duration
#define T_PRC_QL2               1131  // INT, Price Code 2
#define T_YLD_MATURITY          1132  // DOUBLE, Bond Yield
#define T_MKT_ST_IND            1133  // INT, Mkt Status
#define T_MID_PRICE             1134  // LPACK, Mid Price
#define T_MID_NET_CH            1135  // LPACK, Mid-Price Net Change
#define T_MID_CLOSE             1136  // LPACK, Mid-Price Close
#define T_TDY_UN_CLS            1137  // LPACK, Unofficial CLS
#define T_EUROCLR_NO            1140  // LONG, Euroclear Number
#define T_CEDEL_NO              1141  // LONG, CEDEL Number
#define T_TDY_OF_CLS            1143  // LPACK, Off. Close
#define T_CASH_AVG              1146  // LPACK, Cash Avg
#define T_FOOTNOTE1             1148  // STRING, Footnote No. 1
#define T_FOOTNOTE2             1149  // STRING, Footnote No. 2
#define T_NAVDATE               1150  // DATE, NAV Date
#define T_MUTFUND_OFFER         1151  // LPACK, Offer Price
#define T_CAPGAIN_1             1152  // LPACK, Capital Gains
#define T_SPLTDIV_1             1153  // LPACK, Split/Dividend
#define T_NAVALUE_1             1154  // LPACK, Previous Day NAV
#define T_NAVDAT_1              1155  // DATE, NAV Previous Date
#define T_YTM_BID               1156  // DOUBLE, Bid Yield
#define T_YTM_ASK               1157  // DOUBLE, Ask Yield
#define T_UP_LIMIT              1160  // LPACK, Up Limit
#define T_DOWN_LIMIT            1161  // LPACK, Down Limit
#define T_BUYER_ID              1162  // INT, Buyer ID
#define T_SELLER_ID             1163  // INT, Seller ID
#define T_KASS_PRC              1164  // LPACK, KASS Price
#define T_PRTY_PRICE            1165  // LPACK, Parity Price
#define T_KERB_PRC1             1173  // LPACK, Kerb 1st Price
#define T_TRDVOL_1              1178  // LONG, Trade Volume
#define T_BASISVALUE            1179  // DOUBLE, Basis Value
#define T_NO_BUYERS             1183  // LONG, Number of Buyers
#define T_NO_SELLERS            1184  // LONG, Number of Sellers
#define T_RISKFACTOR            1185  // DOUBLE, Risk Factor
#define T_SHORTADDON            1186  // DOUBLE, Short Additional
#define T_TOT_MOVES             1187  // LONG, Total Moves
#define T_STATUS_1              1188  // LONG, Status 1
#define T_STATUS_2              1189  // LONG, Status 2
#define T_STATUS_3              1190  // LONG, Status 3
#define T_STATUS_4              1191  // LONG, Status 4
#define T_STATUS_5              1192  // LONG, Status 5
#define T_STATUS_6              1193  // LONG, Status 6
#define T_STATUS_7              1194  // LONG, Status 7
#define T_HIGHTP_1              1196  // STRING, High Price Type
#define T_LOWTP_1               1197  // STRING, Low Price Type
#define T_LOT_SIZE_A            1198  // DOUBLE, Lot Size
#define T_OPENEXID              1199  // STRING, Open Exchange ID
#define T_CLSEXID               1200  // STRING, Close Exchange ID
#define T_LF_HGH_DAT            1201  // DATE, Life High Date
#define T_LF_LOW_DAT            1202  // DATE, Life Low Date
#define T_BID_HIGH_1            1203  // LPACK, High Bid
#define T_BID_LOW_1             1204  // LPACK, Low Bid
#define T_YRBIDHIGH             1205  // LPACK, Year High Bid
#define T_YRBIDLOW              1206  // LPACK, Year Low Bid
#define T_HST_CLSBID            1207  // LPACK, Historic Closing Bid
#define T_HSTCLBDDAT            1208  // DATE, Historic Closing Bid Date
#define T_YRBDHI_IND            1209  // STRING, Year Bid High *
#define T_YRBDLO_IND            1210  // STRING, Year Bid Low  *
#define T_NUM_BIDS              1211  // INT, No. Bids
#define T_MKT_MKR_ID            1212  // STRING, MktMkr ID
#define T_MKT_SOURCE            1213  // STRING, Market Maker Quote Source
#define T_MKT_MKR_NM            1214  // STRING, Market Maker Name
#define T_SPECRLDATE            1229  // DATE, Special Date
#define T_SP_NAVALUE            1230  // LPACK, Special Open NAV
#define T_SPNAVALUE1            1231  // LPACK, Special Close NAV
#define T_SPEC_CAP              1232  // LPACK, Special Capital Gains
#define T_SPECDIV               1233  // LPACK, Special Dividend
#define T_PRV_KASSA             1234  // LPACK, Previous Kassa Price
#define T_PNAC                  1235  // STRING, PNAC
#define T_PREV_LR               1237  // STRING, Previous LR
#define T_NEXT_LR               1238  // STRING, Next LR
#define T_REF_COUNT             1239  // INT, Reference Count
#define T_1ST_RIC               1240  // STRING, 1st Sym
#define T_2ND_RIC               1241  // STRING, 2nd Sym
#define T_3RD_RIC               1242  // STRING, 3rd Sym
#define T_4TH_RIC               1243  // STRING, 4th Sym
#define T_5TH_RIC               1244  // STRING, 5th Sym
#define T_6TH_RIC               1245  // STRING, 6th Sym
#define T_7TH_RIC               1246  // STRING, 7th Sym
#define T_8TH_RIC               1247  // STRING, 8th Sym
#define T_9TH_RIC               1248  // STRING, 9th Sym
#define T_10TH_RIC              1249  // STRING, 10th Sym
#define T_11TH_RIC              1250  // STRING, 11th Sym
#define T_12TH_RIC              1251  // STRING, 12th Sym
#define T_13TH_RIC              1252  // STRING, 13th Sym
#define T_14TH_RIC              1253  // STRING, 14th Sym
#define T_UNIQUE_SN             1254  // STRING, UNIQUE SN
#define T_PROC_DATE             1255  // DATE, Process. Date
#define T_SEG_TEXT              1258  // STRING, SEG TEXT
#define T_RECORDTYPE            1259  // INT, RecType
#define T_BCAST_TEXT            1264  // STRING, BCAST TEXT
#define T_BID_TIME              1266  // TIME, Bid Time
#define T_ASK_TIME              1267  // TIME, Ask Time
#define T_ACT_TP_1              1270  // STRING, Activity Type 1
#define T_SEC_ACT_1             1275  // LPACK, Second Activity 1
#define T_SC_ACT_TP1            1280  // STRING, Second Activity Type 1
#define T_OPEN_TIME             1285  // TIME, Open Time
#define T_HIGH_TIME             1286  // TIME, High Time
#define T_SETTLEDATE            1287  // DATE, Settle Date
#define T_LOW_TIME              1288  // TIME, Low Time
#define T_ASK_VOLUME            1289  // LONG, Ask Volume
#define T_FORWARD_DATE          1290  // STRING, Forward Date
#define T_NO_BIDMMKR            1291  // LONG, No. Bid MMKR 1
#define T_NO_ASKMMKR            1292  // LONG, No. Ask MMKR 1
#define T_BID_MMID1             1293  // STRING, Bid MM ID1
#define T_BID_MMID2             1294  // STRING, Bid MM ID2
#define T_BID_MMID3             1295  // STRING, Bid MM ID3
#define T_ASK_MMID1             1296  // STRING, Ask MM ID1
#define T_ASK_MMID2             1297  // STRING, Ask MM ID2
#define T_ASK_MMID3             1298  // STRING, Ask MM ID3
#define T_RIC_CODE              1299  // STRING, Reuters Instrument Code
#define T_BLOOMBERG_CODE        1300  // STRING, Bloomberg Code
#define T_BLOOMBERG_CODE_FULL   1301  // STRING, Full Bloomberg Code
#define T_SYMBOL_SOURCE         1302  // STRING, Symbol Source
#define T_BLOOMBERG_CODE_FULL_REGIONAL  1303  // STRING, Bloomberg Code (Full Rgnl)
#define T_BBG_EXCH_CODE         1304  // STRING, Bloomberg Exch Code
#define T_VOR_CODE              1305  // INT, VOR Code
#define T_OPTION_XID            1340  // STRING, Option Exchange ID
#define T_TRADE_TONE            1344  // STRING, Last Trade Tone
#define T_BID_TONE              1345  // STRING, Bid Tone
#define T_ASK_TONE              1346  // STRING, Ask Tone
#define T_CLOSE_TONE            1347  // STRING, Close Tone
#define T_STOP_HIGH             1348  // STRING, Stop High
#define T_STOP_LOW              1349  // STRING, Stop Low
#define T_YRHIGHDAT             1350  // DATE, Yr High Date
#define T_YRLOWDAT              1351  // DATE, Yr Low Date
#define T_HIGH52_DATE           1352  // DATE, High52 Date
#define T_LOW52_DATE            1353  // DATE, Low52 Date
#define T_VOL_FLAG              1355  // STRING, Volume Flag
#define T_RT_YIELD_1            1356  // LPACK, Real Time Yield
#define T_YLD_NETCHG            1361  // LPACK, Yield Net Change
#define T_BID_YIELD             1362  // DOUBLE, Bid Yield
#define T_ASK_YIELD             1363  // DOUBLE, Ask Yield
#define T_OPEN_YLD              1364  // DOUBLE, Open Yield
#define T_HIGH_YLD              1365  // DOUBLE, High Yield
#define T_LOW_YLD               1366  // DOUBLE, Low Yield
#define T_HST_CLSYLD            1367  // DOUBLE, Historic Close Yield
#define T_OPINT_DATE            1369  // DATE, Open Interest Date
#define T_IRGPRC                1372  // LPACK, Irreg. Price
#define T_IRGVOL                1373  // LONG, Irreg. Vol
#define T_IRGCOND               1374  // INT, Sale Condition
#define T_TIMCOR                1375  // TIME, Price Correction Time
#define T_INSPRC                1376  // LPACK, Insert Price
#define T_INSVOL                1377  // LONG, Insert volume
#define T_INSCOND               1378  // INT, Insert Condition
#define T_SALTIM                1379  // TIME, Last Time
#define T_TNOVER_SC             1380  // STRING, Turnover Scale
#define T_PARITY99              1381  // LPACK, Parity >= 100
#define T_PARITY100             1382  // LPACK, Parity < 100
#define T_HST_VOL               1383  // LONG, Hist Vol
#define T_SESS_HIFLG            1384  // STRING, Session High Flag
#define T_SESS_LOFLG            1385  // STRING, Session Low Flag
#define T_SSPRNG1               1386  // LPACK, Suspension Range 1
#define T_SSPRNG2               1387  // LPACK, Suspension Range 2
#define T_SSPRNGTP              1388  // STRING, Suspension Type
#define T_RSMRNG1               1389  // LPACK, Resumption Range 1
#define T_RSMRNG2               1390  // LPACK, Resumption Range 2
#define T_RSMRNGTP              1391  // STRING, Resumption Type
#define T_VOL_DATE              1392  // DATE, Vol Date
#define T_PRIMACT_1             1393  // LPACK, Primary Activity 1
#define T_PRIMACT_2             1394  // LPACK, Primary Activity 2
#define T_PRIMACT_3             1395  // LPACK, Primary Activity 3
#define T_PRIMACT_4             1396  // LPACK, Primary Activity 4
#define T_PRIMACT_5             1397  // LPACK, Primary Activity 5
#define T_EXERCISED             1412  // LONG, Number Exercised
#define T_CONTRIB_1             1416  // INT, Contributor
#define T_ORDER_BID             1431  // LPACK, Order Bid
#define T_ORDER_ASK             1432  // LPACK, Order Ask
#define T_BEST_BID1             1436  // LPACK, Best Bid
#define T_BEST_BID2             1437  // LPACK, Second Best Bid
#define T_BEST_BID3             1438  // LPACK, Third Best Bid
#define T_BEST_BID4             1439  // LPACK, Fourth Best Bid
#define T_BEST_BID5             1440  // LPACK, Fifth Best Bid
#define T_BEST_ASK1             1441  // LPACK, Best Ask
#define T_BEST_ASK2             1442  // LPACK, Second Best Ask
#define T_BEST_ASK3             1443  // LPACK, Third Best Ask
#define T_BEST_ASK4             1444  // LPACK, Fourth Best Ask
#define T_BEST_ASK5             1445  // LPACK, Fifth Best Ask
#define T_REG_ID1               1456  // BLOB, Permission Register ID
#define T_REG_FIELD1            1457  // BLOB, Permission Register Field
#define T_SEQNO                 1720  // INT, Sequence No.
#define T_TABTEXT               1723  // INT, TABTEXT
#define T_NEWS_SOURCE           1725  // STRING, News Source
#define T_BCAST_REF             1728  // STRING, Broadcast Cross-Reference
#define T_BEST_BSIZ1            1730  // LONG, Best Bid Size
#define T_BEST_BSIZ2            1731  // LONG, Best Bid2 Size
#define T_BEST_BSIZ3            1732  // LONG, Best Bid3 Size
#define T_BEST_BSIZ4            1733  // LONG, Best Bid4 Size
#define T_BEST_BSIZ5            1734  // LONG, Best Bid5 Size
#define T_BEST_ASIZ1            1735  // LONG, Best Ask Size
#define T_BEST_ASIZ2            1736  // LONG, Best Ask2 Size
#define T_BEST_ASIZ3            1737  // LONG, Best Ask3 Size
#define T_BEST_ASIZ4            1738  // LONG, Best Ask4 Size
#define T_BEST_ASIZ5            1739  // LONG, Best Ask5 Size
#define T_NO_BIDMKR2            1740  // LPACK, Number Bid MMKR 2
#define T_NO_BIDMKR3            1741  // LPACK, Number Bid MMKR 3
#define T_NO_BIDMKR4            1742  // LPACK, Number Bid MMKR 4
#define T_NO_BIDMKR5            1743  // LPACK, Number Bid MMKR 5
#define T_NO_ASKMMKR2           1744  // LPACK, Number Ask MMKR 2
#define T_NO_ASKMMKR3           1745  // LPACK, Number Ask MMKR 3
#define T_NO_ASKMMKR4           1746  // LPACK, Number Ask MMKR 4
#define T_NO_ASKMMKR5           1747  // LPACK, Number Ask MMKR 5
#define T_NEWS_DATE             1748  // DATE, News Date
#define T_PROD_CODE             1749  // VECTOR_STRING, Prod Code
#define T_TOPIC_CODE            1750  // VECTOR_STRING, Topic Code
#define T_CO_IDS                1751  // VECTOR_STRING, CO IDS
#define T_HST_SESVOL            1758  // LONG, Previous Session Volume
#define T_PRV_HIGH              1759  // LPACK, Previous High
#define T_PRV_LOW               1760  // LPACK, Previous Low
#define T_PRV_OPEN              1761  // LPACK, Previous Open
#define T_PRV_LAST              1762  // LPACK, Previous Last
#define T_DEALT_VL1             1791  // LPACK, Dealt Volume 1
#define T_LONGLINK1             1800  // STRING, LONGLINK1
#define T_LONGLINK2             1801  // STRING, LONGLINK2
#define T_LONGLINK3             1802  // STRING, LONGLINK3
#define T_LONGLINK4             1803  // STRING, LONGLINK4
#define T_LONGLINK5             1804  // STRING, LONGLINK5
#define T_LONGLINK6             1805  // STRING, LONGLINK6
#define T_LONGLINK7             1806  // STRING, LONGLINK7
#define T_LONGLINK8             1807  // STRING, LONGLINK8
#define T_LONGLINK9             1808  // STRING, LONGLINK9
#define T_LONGLINK10            1809  // STRING, LONGLINK10
#define T_LONGLINK11            1810  // STRING, LONGLINK11
#define T_LONGLINK12            1811  // STRING, LONGLINK12
#define T_LONGLINK13            1812  // STRING, LONGLINK13
#define T_LONGLINK14            1813  // STRING, LONGLINK14
#define T_LONGPREVLR            1814  // STRING, Long PREV_LR
#define T_LONGNEXTLR            1815  // STRING, Long NEXT_LR
#define T_DVOL1_SC              1820  // STRING, Dealt Vol Scale
#define T_CROSS_SC              1825  // STRING, Cross Rates Scale
#define T_DLG_CODE1             1826  // STRING, Dealing Code 1
#define T_CTBTR_1               1831  // STRING, Contributor Name 1
#define T_CTB_LOC1              1836  // STRING, Contributor Location 1
#define T_CTB_PAGE1             1841  // STRING, Contributor Page Code 1
#define T_AMT_OS                1850  // LPACK, Amount Outstanding
#define T_AMT_OS_SC             1851  // STRING, Amount Outstanding Scale
#define T_NRG_CMT               1857  // STRING, Energy Comment
#define T_PRC_AREA              1858  // STRING, Price Location
#define T_DATE_RANGE            1859  // STRING, Date Range
#define T_BENCH_PRC             1860  // LPACK, Bench Price
#define T_BENCH_DATE            1861  // DATE, Bench Date
#define T_PAY_FREQ              1868  // STRING, Payment Frequency
#define T_OFF_CD_IND            1869  // STRING, Official Code Indicator
#define T_VALUE_DT1             1875  // DATE, Value Date 1
#define T_MOD_DURTN             1885  // LPACK, Modified Duration
#define T_PRC_VOLTY             1886  // LPACK, Price Volatility
#define T_ANNC_DATE             1887  // DATE, Announcement Date
#define T_THEO_AUCTION_PRICE    1888  // LPACK, Theoretical Auction Price
#define T_THEO_AUCTION_VOL      1889  // LONG, Theoretical Auction Vol
#define T_THEO_HIGH             1890  // LPACK, Theoretical High
#define T_THEO_LOW              1891  // LPACK, Theoretical Low
#define T_THEO_YRHI             1892  // LPACK, Theoretical Year High
#define T_THEO_YRLO             1893  // LPACK, Theoretical Year Low
#define T_THEO_LFHI             1894  // LPACK, Theoretical Life High
#define T_THEO_LFLO             1895  // LPACK, Theoretical Life Low
#define T_THEO_LHDAT            1896  // DATE, Theoretical Life High
#define T_THEO_LLDAT            1897  // DATE, Theoretical Life Low
#define T_FLOOR_VOL             1899  // LONG, Floor Volume
#define T_IA_DATE               1900  // DATE, Interest Adjustment Date
#define T_AMT_OS_DAT            1901  // DATE, Amount Outstanding Date
#define T_QTE_CNT1              1955  // LPACK, Quote Count 1
#define T_QTE_CNT2              1956  // LPACK, Quote Count 2
#define T_SEC_HIGH              1957  // LPACK, Secondary High
#define T_SEC_HI_TP             1958  // STRING, Sec High Type
#define T_SEC_LOW               1959  // LPACK, Secondary Low
#define T_SEC_LO_TP             1960  // STRING, Sec Low Type
#define T_OPEN_PRC2             1961  // LPACK, Open Price 2
#define T_OPEN_TYPE             1962  // STRING, Open Type
#define T_HST_CLOSE2            1963  // LPACK, Historic Close 2
#define T_CLOSE_TYPE            1964  // STRING, Close Type
#define T_RATING_2              1965  // STRING, A Generic Rating Field
#define T_RATING_ID2            1966  // STRING, Rating Agency Identifier
#define T_BKGD_REF              1967  // STRING, Background Reference
#define T_CTBTR_BKGD            1968  // STRING, Contributor Background
#define T_YIELD_TP              1969  // STRING, Yield Type
#define T_SEC_YLD_1             1970  // LPACK, Second Yield
#define T_ACT_FLAG1             1975  // STRING, Activity Flag 1
#define T_SC_AFLAG1             1980  // STRING, Secondary Activity Flag 1
#define T_SEC_VOL1              1985  // LPACK, Secondary Volume 1
#define T_VOL_TP1               1990  // STRING, Volume Type 1
#define T_GEN_TEXT16            1995  // STRING, General Text
#define T_GEN_VAL1              1996  // LPACK, General Value 1
#define T_GEN_VAL2              1997  // LPACK, General Value 2
#define T_GEN_VAL3              1998  // LPACK, General Value 3
#define T_GEN_VAL4              1999  // LPACK, General Value 4
#define T_STYP                  2000  // INT, Sec. Type
#define T_GV2_TEXT              2001  // STRING, Generic Text 2
#define T_GV3_TEXT              2002  // STRING, Generic Text 3
#define T_GV4_TEXT              2003  // STRING, Generic Text 4
#define T_QCNT1_IND             2004  // STRING, Quote Count Indicator 1
#define T_QCNT2_IND             2005  // STRING, Quote Count Indicator 2
#define T_NM_IND                2006  // STRING, Num Moves Indicator
#define T_VALUE_TS1             2010  // TIME, Activity Value Time 1
#define T_BS_FLAG               2016  // STRING, BS Flag
#define T_AS_FLAG               2017  // STRING, AS Flag
#define T_IRGXID                2018  // STRING, IRG Exch ID
#define T_IRGBUY                2019  // STRING, IRGBUY
#define T_IRGSELL               2020  // STRING, IRGSELL
#define T_SEQNUM                2021  // LONG, SeqNum
#define T_PRNTYP                2022  // STRING, Print type
#define T_PRNTBCK               2023  // LONG, Trades back
#define T_QUOTIM                2025  // TIME, Quote time
#define T_STOCK_RIC             2026  // STRING, Stock RIC
#define T_GV1_DATE              2028  // DATE, GV1 Date
#define T_GEN_VAL5              2029  // LPACK, Generic Value 5
#define T_GEN_VAL6              2030  // LPACK, Generic Value 6
#define T_GEN_VAL7              2031  // LPACK, Generic Value 7
#define T_GEN_VAL8              2032  // LPACK, Generic Value 8
#define T_GEN_VAL9              2033  // LPACK, Generic Value 9
#define T_GEN_VAL10             2034  // LPACK, Generic Value 10
#define T_GV5_TEXT              2035  // STRING, Generic Text 5
#define T_GV6_TEXT              2036  // STRING, Generic Text 6
#define T_GV7_TEXT              2037  // STRING, Generic Text 7
#define T_GV8_TEXT              2038  // STRING, Generic Text 8
#define T_GV9_TEXT              2039  // STRING, Generic Text 9
#define T_GV10_TEXT             2040  // STRING, Generic Text 10
#define T_GV1_FLAG              2041  // STRING, Generic Flag 1
#define T_GV2_FLAG              2042  // STRING, Generic Flag 2
#define T_GV3_FLAG              2043  // STRING, Generic Flag 3
#define T_GV4_FLAG              2044  // STRING, Generic Flag 4
#define T_GV5_FLAG              2045  // STRING, Generic Flag 5
#define T_GV6_FLAG              2046  // STRING, Generic Flag 6
#define T_GV7_FLAG              2047  // STRING, Generic Flag 7
#define T_GV8_FLAG              2048  // STRING, Generic Flag 8
#define T_GV9_FLAG              2049  // STRING, Generic Flag 9
#define T_GV10_FLAG             2050  // STRING, Generic Flag 10
#define T_GV2_DATE              2051  // DATE, Generic Date Field
#define T_GN_TXT16_2            2052  // STRING, Generic Text 2
#define T_GN_TXT16_3            2053  // STRING, Generic Text 3
#define T_GN_TXT16_4            2054  // STRING, Generic Text 4
#define T_OFF_CD_IN2            2055  // STRING, Official Code Indicator
#define T_OFFC_CODE2            2056  // STRING, Official Code 2
#define T_CURR_COUPN            2058  // LPACK, Current Coupon
#define T_GV1_TIME              2061  // TIME, Generic Time 1
#define T_GV2_TIME              2062  // TIME, Generic Time 2
#define T_O_BID_TONE            2065  // STRING, Order Bid Tone
#define T_O_ASK_TONE            2066  // STRING, Order Ask Tone
#define T_EXCHTIM               2067  // TIME, Exchange Time
#define T_CONDCODE_1            2068  // STRING, Condition Code 1
#define T_CONDCODE_2            2069  // STRING, Condition Code 2
#define T_YRHI_IND              2075  // STRING, Year High Indicator
#define T_YRLO_IND              2076  // STRING, Year Low Indicator
#define T_BETA_VAL              2077  // LPACK, Beta Value
#define T_CONV_FAC              2078  // DOUBLE, Conversion Factor
#define T_PREF_DISP             2080  // INT, Preferred Display Template
#define T_PREF_LINK             2081  // STRING, Preferred Link Record
#define T_RESTRICT              2082  // STRING, Restricted Security
#define T_BORROW                2083  // STRING, Borrowable Security
#define T_EXCHDATE              2084  // DATE, Exchange date
#define T_EXCHZONE              2085  // STRING, Exchange time zone
#define T_EXCHZONE_2            2086  // STRING, Alt. exchange time zone
#define T_HOLIDAY_CALENDAR      2087  // STRING, Holiday calendar
#define T_STATUS                3001  // STRING, Quote Condition
#define T_NEWSCOUNT             3002  // INT, Obsolete
#define T_OFFER                 3004  // LPACK, Offer
#define T_FUNDDAY               3005  // INT, Fund Day
#define T_MKT_MKR_STATUS        3006  // STRING, MM Status
#define T_MG_STATE              3590  // STRING, State
#define T_DELAY                 3597  // INT, Delay amount
#define T_NOMINAL_CURRENCY      3622  // STRING, Nom. Currency
#define T_DIVIDEND_CURRENCY     3623  // STRING, Div. Currency
#define T_ISSUERS_DOMICILE      3624  // STRING, Domicile
#define T_ISSUERS_SECTOR        3625  // INT, Sector
#define T_INTEREST_FREQ_N       3626  // INT, Int. Freq.
#define T_SPREAD_DATE           3627  // DATE, Spread Date
#define T_LIBERIERUNG           3628  // DATE, Liberierung
#define T_JOUISSANCE            3629  // DATE, Jouissance
#define T_REDEMPTION_DATE       3630  // DATE, Red. Date
#define T_EARLIEST_REDEMPTION_DATE  3631  // DATE, Earl. Red. Date
#define T_NEXT_REDEMPTION_DATE  3632  // DATE, Next Red. Date
#define T_LAST_COUPON_DATE      3633  // DATE, Last Coupon Date
#define T_EARLIEST_EXERCISE_DATE  3634  // DATE, Earl. Exer. Date
#define T_SHARES_PER_CONTRACT   3635  // LPACK, Shares/contract
#define T_NOMINAL_CAPITAL       3636  // LPACK, Nom. Capital
#define T_NOMINAL_VALUE         3637  // LPACK, Nom. Value
#define T_INTEREST_RATE         3638  // LPACK, Interest Rate
#define T_ISSUE_PRICE           3639  // LPACK, Issue Price
#define T_REDEMPTION_PRICE      3640  // LPACK, Red. Price
#define T_WARRANT_CONV_NUM      3641  // LPACK, Warrant Conv. 1
#define T_WARRANT_CONV_DENOM    3642  // LPACK, Warrant Conv. 2
#define T_DIVIDEND_1_DATE       3643  // DATE, Div. Date 1
#define T_DIVIDEND_2_DATE       3644  // DATE, Div. Date 2
#define T_DIVIDEND_3_DATE       3645  // DATE, Div. Date 3
#define T_DIVIDEND_4_DATE       3646  // DATE, Div. Date 4
#define T_NSIN_1                3647  // STRING, NSIN 1
#define T_NSIN_2                3648  // STRING, NSIN 2
#define T_NSIN_3                3649  // STRING, NSIN 3
#define T_NSIN_4                3650  // STRING, NSIN 4
#define T_NSIN_5                3651  // STRING, NSIN 5
#define T_NSIN_6                3652  // STRING, NSIN 6
#define T_NSIN_7                3653  // STRING, NSIN 7
#define T_NSIN_8                3654  // STRING, NSIN 8
#define T_IN_VOLUME             3655  // LONG, In Volume
#define T_OUT_VOLUME            3656  // LONG, Out Volume
#define T_STRIKE_VOLUME         3657  // LONG, Strike Volume
#define T_REMAIN_VOLUME         3658  // LONG, Remain Volume
#define T_ISSUERS_SECTOR_STR    3659  // STRING, Sector
#define T_EXCUM_CODE            3660  // INT, Ex/cum Code
#define T_TRADING_STATE         3661  // INT, Trading State
#define T_EXCUM_DATE            3662  // DATE, Ex/cum Date
#define T_SHORT_CAPITAL_GAINS   3663  // LPACK, Short CapGains
#define T_MEDIUM_CAPITAL_GAINS  3664  // LPACK, Medium CapGains
#define T_LONG_CAPITAL_GAINS    3665  // LPACK, Long CapGains
#define T_UNALLOC_DISTRIBUTION  3666  // LPACK, Unalloc Distrib
#define T_PERIOD_CODE           3667  // STRING, Period Code
#define T_THEO_OPEN             3668  // LPACK, Theo Open
#define T_Z_BIDASK              3669  // STRING, Bid/Ask
#define T_Z_BIDASK_SIZE         3670  // STRING, Z Bid/Ask Size
#define T_Z_BIDASK_YIELD        3671  // STRING, Bid/Ask Yield
#define T_GENERIC_FLAG          3672  // STRING, Flag
#define T_BEST_BID_FLAG1        3674  // STRING, Best Bid Flag
#define T_BEST_BID_FLAG2        3675  // STRING, Best Bid2 Flag
#define T_BEST_BID_FLAG3        3676  // STRING, Best Bid3 Flag
#define T_BEST_BID_FLAG4        3677  // STRING, Best Bid4 Flag
#define T_BEST_BID_FLAG5        3678  // STRING, Best Bid5 Flag
#define T_BEST_BID_USER1        3679  // LONG, Best Bid User
#define T_BEST_BID_USER2        3680  // LONG, Best Bid2 User
#define T_BEST_BID_USER3        3681  // LONG, Best Bid3 User
#define T_BEST_BID_USER4        3682  // LONG, Best Bid4 User
#define T_BEST_BID_USER5        3683  // LONG, Best Bid5 User
#define T_TRDVOL_2              3684  // LONG, Trade2 Volume
#define T_TRDVOL_3              3685  // LONG, Trade3 Volume
#define T_TRDVOL_4              3686  // LONG, Trade4 Volume
#define T_TRDVOL_5              3687  // LONG, Trade5 Volume
#define T_TRDTIM_2              3688  // TIME, Trade2 Time
#define T_TRDTIM_3              3689  // TIME, Trade3 Time
#define T_TRDTIM_4              3690  // TIME, Trade4 Time
#define T_TRDTIM_5              3691  // TIME, Trade5 Time
#define T_BEST_ASK_FLAG1        3692  // STRING, Best Ask Flag
#define T_BEST_ASK_FLAG2        3693  // STRING, Best Ask2 Flag
#define T_BEST_ASK_FLAG3        3694  // STRING, Best Ask3 Flag
#define T_BEST_ASK_FLAG4        3695  // STRING, Best Ask4 Flag
#define T_BEST_ASK_FLAG5        3696  // STRING, Best Ask5 Flag
#define T_BEST_ASK_USER1        3697  // LONG, Best Ask User
#define T_BEST_ASK_USER2        3698  // LONG, Best Ask2 User
#define T_BEST_ASK_USER3        3699  // LONG, Best Ask3 User
#define T_BEST_ASK_USER4        3700  // LONG, Best Ask4 User
#define T_BEST_ASK_USER5        3701  // LONG, Best Ask5 User
#define T_IMBALANCE             3702  // LONG, Imbalance
#define T_SPREAD                3703  // LPACK, Spread
#define T_DIFF_THEO_REF         3704  // LPACK, Theo-Ref
#define T_DIFF_LAST_REF         3705  // LPACK, Last-Ref
#define T_ACCEPTABILITY         3706  // LPACK, Acceptability
#define T_SUSPENSIBILITY        3707  // LPACK, Suspensibility
#define T_NEGOTIABILITY         3708  // LPACK, Negotiability
#define T_MAX_LOTS_APE          3709  // LONG, Max Lots APE
#define T_MAX_LOTS_ECO          3710  // LONG, Max Lots ECO
#define T_CONTRACTS             3711  // LONG, No. Contracts
#define T_COUNTERVALUE          3712  // LPACK, Countervalue
#define T_OPENING_VOL           3713  // LONG, Opening Volume
#define T_OPENING_CONTRACTS     3714  // LONG, Opening Contracts
#define T_OPENING_NUMBER        3715  // LONG, Opening No.
#define T_PREOPEN_START         3716  // TIME, Preopening
#define T_VALIDATION_START      3717  // TIME, Validation
#define T_OPENING_START         3718  // TIME, Opening
#define T_CLOSING_START         3719  // TIME, Closing
#define T_SUSP_TIME             3720  // TIME, Susp Time
#define T_MINIMUM_SIZE          3721  // LONG, Minimum Size
#define T_SETTLE_CASH           3722  // LPACK, Cash
#define T_SETTLE_SYM_1          3723  // STRING, Symbol1
#define T_SETTLE_SYM_2          3724  // STRING, Symbol2
#define T_SETTLE_SYM_3          3725  // STRING, Symbol3
#define T_SETTLE_SYM_4          3726  // STRING, Symbol4
#define T_SETTLE_SYM_5          3727  // STRING, Symbol5
#define T_SETTLE_SYM_6          3728  // STRING, Symbol6
#define T_SETTLE_SYM_7          3729  // STRING, Symbol7
#define T_SETTLE_SYM_8          3730  // STRING, Symbol8
#define T_SETTLE_TYPE_1         3731  // STRING, Type1
#define T_SETTLE_TYPE_2         3732  // STRING, Type2
#define T_SETTLE_TYPE_3         3733  // STRING, Type3
#define T_SETTLE_TYPE_4         3734  // STRING, Type4
#define T_SETTLE_TYPE_5         3735  // STRING, Type5
#define T_SETTLE_TYPE_6         3736  // STRING, Type6
#define T_SETTLE_TYPE_7         3737  // STRING, Type7
#define T_SETTLE_TYPE_8         3738  // STRING, Type8
#define T_SETTLE_SIZE_1         3739  // LONG, Qty1
#define T_SETTLE_SIZE_2         3740  // LONG, Qty2
#define T_SETTLE_SIZE_3         3741  // LONG, Qty3
#define T_SETTLE_SIZE_4         3742  // LONG, Qty4
#define T_SETTLE_SIZE_5         3743  // LONG, Qty5
#define T_SETTLE_SIZE_6         3744  // LONG, Qty6
#define T_SETTLE_SIZE_7         3745  // LONG, Qty7
#define T_SETTLE_SIZE_8         3746  // LONG, Qty8
#define T_SETTLE_STRIKE_1       3747  // LPACK, Strike%1
#define T_SETTLE_STRIKE_2       3748  // LPACK, Strike%2
#define T_SETTLE_STRIKE_3       3749  // LPACK, Strike%3
#define T_SETTLE_STRIKE_4       3750  // LPACK, Strike%4
#define T_SETTLE_STRIKE_5       3751  // LPACK, Strike%5
#define T_SETTLE_STRIKE_6       3752  // LPACK, Strike%6
#define T_SETTLE_STRIKE_7       3753  // LPACK, Strike%7
#define T_SETTLE_STRIKE_8       3754  // LPACK, Strike%8
#define T_TICK_SIZE             3755  // LPACK, Tick Size
#define T_SUBMARKET             3756  // STRING, Submarket
#define T_ASHTON_VWAP           3757  // LPACK, Ashton VWAP
#define T_MG_SICM               3765  // LPACK, cur mo short interest
#define T_CG_HOT_ACVOL_1        3941  // DOUBLE, Recent Volume Ratio
#define T_CG_HOT_NUM_MOVES      3942  // DOUBLE, Recent Trades Ratio
#define T_SOES_TIER_SIZE        3943  // LONG, SOES Tier Size
#define T_ARCA_VOL              3944  // LONG, ARCA Vol.
#define T_OPT_VOL               3945  // LONG, Opt. Vol.
#define T_PUT_VOL               3946  // LONG, Put Vol.
#define T_CALL_VOL              3947  // LONG, Call Vol.
#define T_INDICATIVE_SIZE       3948  // LONG, Ind. Size
#define T_AUCTION_PRICE         3949  // LPACK, Auction Price
#define T_AUCTION_SIZE          3950  // LONG, Auction Size
#define T_AUCTION_TIME          3951  // TIME, Auction Time
#define T_ORIG_STRIKE_PRICE     3952  // LPACK, Orig. Strike
#define T_AUCTION_SURPLUS_IND   3953  // STRING, Auc. Surplus
#define T_ODR_INTERRUPTION_IND  3954  // STRING, Ord. Interrupt
#define T_VOL_INTERRUPTION_IND  3955  // STRING, Vlt. Interrupt
#define T_INTEREST_DATE         3956  // STRING, Interest Date
#define T_SP_MID400             3957  // INT, S&P Midcap 400
#define T_SP_SMALL600           3958  // INT, S&P Smallcap 600
#define T_MKT_CAP               3959  // LPACK, Market Capitalization
#define T_WEB_ADDR              3960  // STRING, Web Addr
#define T_SHSPERADR             3961  // LPACK, Shares/ADR
#define T_NSIN_TRADING          3962  // STRING, Trading Id
#define T_TRADE_ROOT            3963  // STRING, Trade Root
#define T_SUSP_DATE             3964  // DATE, Susp Date
#define T_AUCTION_END           3965  // TIME, Auction Random Time
#define T_BID_TICK_2            3966  // STRING, Natl Bid Tick
#define T_FUT_FIXED             3967  // LPACK, Future Fixed Price
#define T_MKT_SEGMENT           3968  // INT, Market Segment Legal
#define T_NAS_CROSS_TYPE        3969  // STRING, NAS Cross
#define T_NAS_IMBALANCE         3970  // LONG, NAS Imbalance
#define T_NAS_PAIRED            3971  // LONG, NAS Paired Shares
#define T_NAS_REFERENCE_PRICE   3972  // LPACK, NAS Ref Price
#define T_NAS_FAR_IND_CLEARING  3973  // LPACK, NAS Far Clearing
#define T_NAS_NEAR_IND_CLEARING 3974  // LPACK, NAS Near Clearing
#define T_NYSE_IMBAL_TYPE       3975  // STRING, NYSE Imbal Type
#define T_NYSE_IMBALANCE        3976  // LONG, NYSE Imbalance
#define T_QUOTE_ID              3977  // STRING, Quote Id
#define T_ADR_UNDERLIER         3978  // STRING, ADR Underlier
#define T_AUCTION_TRADES        3979  // LONG, Auction Trades
#define T_BASKET_CODE           3980  // STRING, Basket Code
#define T_COUNTRY               3981  // STRING, Country
#define T_EXCHANGE_RATE         3982  // DOUBLE, Exchange Rate
#define T_INSTRUMENT_GROUP      3983  // STRING, Instrument Group
#define T_MARKET_CODE           3984  // STRING, Market Code
#define T_MAX_LOTS              3985  // LONG, Max Lots
#define T_MAX_PD_ORDER_CONTROL  3986  // DOUBLE, Max%diff Order Control
#define T_MAX_PD_TRADE_CONTROL  3987  // DOUBLE, Max%diff Trade Control
#define T_MAX_PD_TRADE_LAST     3988  // DOUBLE, Max%diff Trade Last
#define T_MISALIGNMENT_RATIO    3989  // DOUBLE, Misalignment Ratio
#define T_PCT_TRADED            3990  // DOUBLE, Percent Traded
#define T_POOL_FACTOR           3991  // DOUBLE, Pool Factor
#define T_PR_COUNTERVALUE       3992  // LPACK, Progressive Countervalue
#define T_SEGMENT               3993  // STRING, Segment
#define T_SUBTYPE               3994  // STRING, Subtype
#define T_TAX_RATE              3995  // DOUBLE, Tax Rate
#define T_CL_AUC_START          3996  // TIME, Closure Auction Start Time
#define T_CL_VAL_START          3997  // TIME, Closure Validation Start Time
#define T_MANAGEMENT_START      3998  // TIME, Management Start Time
#define T_PRECLOSURE_START      3999  // TIME, Preclosure Start Time
#define T_TRADING_START         4000  // TIME, Trading Start Time
#define T_TAH_CLOSE_START       4001  // TIME, TAH Close Start Time
#define T_TAH_OPEN_START        4002  // TIME, TAH Open Start Time
#define T_ALT_VOL1              4003  // LONG, Alternate Volume 1
#define T_ALT_VOL2              4004  // LONG, Alternate Volume 2
#define T_CLEARING_TYPE         4005  // STRING, Clearing Type
#define T_NEWS_SEARCH_FLAG      4006  // STRING, Flags for news queries
#define T_ALT_VWAP              4007  // DOUBLE, VWAP (Alt)
#define T_NMS                   4008  // LONG, NMS
#define T_TRDPRC_1_TYP          4009  // STRING, Last (Price Type)
#define T_HEDGE_RATIO           4010  // DOUBLE, Delta
#define T_LIBOR_OAS             4011  // DOUBLE, LIBOR OAS
#define T_BENCH_PRC_TYP         4012  // STRING, Bench Price Type
#define T_BARRIER_PCT           4013  // DOUBLE, Barrier Lvl
#define T_BARRIER_PRC           4014  // LPACK, Barrier Prc
#define T_UNDERLIER_CURRENCY    4015  // STRING, Underlier Currency
#define T_SECURITY_SUBTYPE      4016  // LONG, Security Subtype
#define T_AGG_BIDSIZE           4017  // LONG, Aggregate bid size
#define T_AGG_ASKSIZE           4018  // LONG, Aggregate ask size
#define T_REGION                4019  // STRING, Region
#define T_EXCH_DESCRIPTION      4020  // STRING, Exchange Description
#define T_W_PUT_VOL             4021  // DOUBLE, Weighted put volume
#define T_W_CALL_VOL            4022  // DOUBLE, Weighted call volume
#define T_TICKSZTBL             4023  // STRING, Tick Size Table ID
#define T_NYS_PAIRED            4024  // LONG, NYS Paired Shares
#define T_NYS_REFERENCE_PRICE   4025  // LPACK, NYS Ref Price
#define T_NYS_CLEARING          4026  // LPACK, NYS Clearing
#define T_NYS_BOOK_CLEARING     4027  // LPACK, NYS Book Clearing
#define T_VAB_SYMBOL            4028  // STRING, VAB Symbol
#define T_STATIC_REF_PRC        4029  // LPACK, Static Ref Price
#define T_DYNAMIC_REF_PRC       4030  // LPACK, Dynamic Ref Price
#define T_PRICE_BAND_PCT        4031  // DOUBLE, Price Band Tolerances
#define T_CIRCUIT_BREAKER_S_PCT 4032  // DOUBLE, Static Circuit Breaker Tolerances
#define T_CIRCUIT_BREAKER_D_PCT 4033  // DOUBLE, Dynamic Circuit Breaker Tolerances
#define T_NAS_AUCTION_TIME      4034  // TIME, NASDAQ Auction Time
#define T_NYS_AUCTION_TIME      4035  // TIME, NYSE Auction Time
#define T_INSTRUMENT_ID         4036  // STRING, INSTR ID
#define T_INSTRUMENT_ID2        4037  // STRING, INSTR ID2
#define T_NOTES                 5003  // STRING, Notes
#define T_PRV_LISTINO           5005  // LPACK, Yest Listino
#define T_OFFICIAL_PRICE        5006  // LPACK, Official Price
#define T_TELEB_CORR_TYPE       5007  // INT, Teleb Corr Type
#define T_ARCA_MATCH_PRICE      5100  // LPACK, Match Price
#define T_ARCA_IMBALANCE_VOLUME 5101  // LONG, Imbalance Volume
#define T_ARCA_MATCH_VOLUME     5102  // LONG, Match Volume
#define T_ARCA_IMBALANCE_SIG    5103  // INT, Imbalance Sig
#define T_ARCA_IMBALANCE_SESSION  5104  // STRING, Imbalance Session
#define T_ARCA_AOT              5105  // TIME, Anticipated Open Time
#define T_UNDERSYM              6000  // STRING, Under Sym
#define T_NEWS_SYM              6001  // STRING, News Sym
#define T_SYMBOL_DESC           6002  // STRING, Description
#define T_SYMBOL_ROOT           6003  // STRING, Symbol root
#define T_OPTCSIZE              6005  // DOUBLE, Option Cont. Size
#define T_NEWS_STORY_ID         6007  // STRING, News Story ID
#define T_NEWS_HEADLINE         6008  // STRING, News Headline
#define T_COMPANY_NAME          6009  // STRING, Company Name
#define T_NEWS_STORY            6010  // STRING, News Story
#define T_MINMOVE               6011  // INT, Min Move
#define T_MAXMOVE               6012  // INT, Max Move
#define T_NEWS_CAT              6013  // VECTOR_STRING, News Cat
#define T_OPTSYM                6014  // STRING, Option Symbol
#define T_OPTSYM_2              6015  // STRING, Option Symbol 2
#define T_OPTSYM_3              6016  // STRING, Option Symbol 3
#define T_SPLIT_SOURCE          6017  // INT, Split source
#define T_CHANGE_LAST           6018  // LPACK, Chg Last
#define T_TABLE_ID              6019  // LONG, Table ID
#define T_STARTTIME             6021  // TIME, Start Time
#define T_STOPTIME              6022  // TIME, StopTime
#define T_EXCH_NAME             6023  // STRING, Exch Name
#define T_COMMODITY_NAME        6024  // STRING, Commodity Name
#define T_MONEY_FLOW            6025  // LONG, Money Flow
#define T_STARTSESS2            6026  // TIME, Session 2 start
#define T_ENDSESS1              6027  // TIME, Session 1 end
#define T_CURRENT_SESSION       6028  // INT, Curr. Session
#define T_EXCH_CLOSE_TIME       6029  // TIME, Exch Close Time
#define T_DELTA_TRADES          6030  // INT, Delta Trades
#define T_CANCEL_PRICE          6031  // LPACK, Cancel Price
#define T_INSERT_PRICE          6032  // LPACK, Insert Price
#define T_CORRECTION_VOLUME     6033  // LONG, Correction Vol
#define T_AUTO_ACCEPT           6034  // INT, Order Entry Control Fid
#define T_CANCEL_VOLUME         6035  // LONG, Cancel size
#define T_CORRECTION_XID        6036  // STRING, Correction Exchange
#define T_VWAP                  6037  // DOUBLE, VWAP
#define T_SUM_PV                6038  // DOUBLE, Sum of price*volume
#define T_VWAP_VOL              6039  // LONG, VWAP volume
#define T_SALE_CONDITION        6040  // INT, Sale Condition
#define T_SALE_CONDITION_PRICE  6041  // LPACK, Irg trade price
#define T_SALE_CONDITION_VOLUME 6042  // LONG, Irg trade volume
#define T_SALE_CONDITION_TIME   6043  // TIME, Irg trade time
#define T_SALE_CONDITION_XID    6044  // STRING, Irg trade exch ID
#define T_BID_CONTRIB           6045  // INT, Bid Contrib
#define T_ASK_CONTRIB           6046  // INT, Ask Contrib
#define T_SALE_CONDITION_DATE   6047  // DATE, Irg trade date
#define T_STARTSESS1            6048  // TIME, Session 1 start
#define T_ENDSESS2              6049  // TIME, Session 2 end
#define T_OPTION_ROOT           6050  // STRING, Option Root
#define T_NO_UPDATES            6051  // INT, No Updates
#define T_DISPLAY_EXPIR_DATE    6052  // DATE, Contract Date
#define T_REGIONAL_BID          6053  // LPACK, Rgnl Bid
#define T_REGIONAL_BID_TIME     6054  // TIME, Rgnl Bid Time
#define T_REGIONAL_BIDEXID      6055  // STRING, Rgnl Bid Exch ID
#define T_REGIONAL_BIDSIZE      6056  // LONG, Rgnl Bid Size
#define T_REGIONAL_ASK          6057  // LPACK, Rgnl Ask
#define T_REGIONAL_ASK_TIME     6058  // TIME, Rgnl Ask Time
#define T_REGIONAL_ASKEXID      6059  // STRING, Rgnl Ask Exch ID
#define T_REGIONAL_ASKSIZE      6060  // LONG, Rgnl Ask Size
#define T_USE_STD_UPDATE        6062  // INT, Use Std Update
#define T_OPTION_SERIES_ROOT    6063  // STRING, Option Series Root
#define T_MAX_ROWS              6064  // LONG, Max Rows
#define T_CANCEL_CONDITION      6065  // INT, Cancelled Sale Condition
#define T_REGIONAL_TRDPRC_1     6071  // LPACK, Rgnl Price
#define T_REGIONAL_TRDTIM_1     6072  // TIME, Rgnl Trd Time
#define T_REGIONAL_TRDVOL_1     6073  // LONG, Rgnl Trd Vol
#define T_REGIONAL_EXCHID       6074  // STRING, Rgnl Exch ID
#define T_REGIONAL_TRDXID_1     6075  // STRING, Rgnl Trd XID
#define T_REGIONAL_TRD_DATE     6076  // DATE, Rgnl Trd Date
#define T_REGIONAL_OPEN_PRC     6077  // LPACK, Rgnl Open
#define T_REGIONAL_HST_CLOSE    6078  // LPACK, Rgnl Hst Close
#define T_REGIONAL_HIGH_1       6079  // LPACK, Rgnl High
#define T_REGIONAL_LOW_1        6080  // LPACK, Rgnl Low
#define T_REGIONAL_ACVOL_1      6081  // LONG, Rgnl AcVol
#define T_BID_CONDITION         6082  // STRING, Bid condition
#define T_ASK_CONDITION         6083  // STRING, Ask condition
#define T_REGIONAL_STATUS       6084  // STRING, Regional quote condition
#define T_REGIONAL_ASK_DATE     6085  // DATE, Regional ask date
#define T_REGIONAL_BID_DATE     6086  // DATE, Regional bid date
#define T_REGIONAL_NETCHNG_1    6087  // LPACK, Regional net change
#define T_REGIONAL_SALE_CONDITION  6088  // INT, Regional sale condition
#define T_REGIONAL_CHANGE_LAST  6089  // LPACK, Regional last change
#define T_TRADING_INDICATOR     6090  // STRING, Trading Indicator
#define T_BID_1WK               6091  // LPACK, Bid 1WK
#define T_ASK_1WK               6092  // LPACK, Ask 1WK
#define T_BID_2WK               6093  // LPACK, Bid 2WK
#define T_ASK_2WK               6094  // LPACK, Ask 2WK
#define T_BID_1MO               6095  // LPACK, Bid 1MO
#define T_ASK_1MO               6096  // LPACK, Ask 1MO
#define T_BID_2MO               6097  // LPACK, Bid 2MO
#define T_ASK_2MO               6098  // LPACK, Ask 2MO
#define T_BID_3MO               6099  // LPACK, Bid 3MO
#define T_ASK_3MO               6100  // LPACK, Ask 3MO
#define T_BID_6MO               6101  // LPACK, Bid 6MO
#define T_ASK_6MO               6102  // LPACK, Ask 6MO
#define T_BID_1YR               6103  // LPACK, Bid 1YR
#define T_ASK_1YR               6104  // LPACK, Ask 1YR
#define T_SYMBOL_ID             6105  // LONG, Symbol Id
#define T_IS_BEST_BID           6106  // INT, Is best bid
#define T_IS_BEST_ASK           6107  // INT, Is best ask
#define T_CORRECTION_DATE       6108  // DATE, Correction date
#define T_HIGH_2                6112  // LPACK, High 2
#define T_LOW_2                 6113  // LPACK, Low 2
#define T_OPTIMARK_START_TIME   6150  // TIME, Optimark Start Time
#define T_OPTIMARK_AUCTION_INTERVAL  6151  // INT, Optimark Interval
#define T_WEEK_VOL              6152  // LONG, Week volume
#define T_MONTH_VOL             6153  // LONG, Month volume
#define T_EXIT_VWAP_VOL         6154  // LONG, VWAP volume on exit
#define T_EXIT_VWAP             6155  // DOUBLE, VWAP on exit
#define T_EXIT_TRDPRC_1         6156  // LPACK, Last Price staged exit
#define T_YRHIGH_2              6190  // LPACK, Yr High 2
#define T_YRLOW_2               6191  // LPACK, Yr Low 2
#define T_BEST_BID1_TIME        6195  // TIME, Best Bid Time
#define T_BEST_BID1_DATE        6196  // DATE, Best Bid Date
#define T_BEST_ASK1_TIME        6197  // TIME, Best Ask Time
#define T_BEST_ASK1_DATE        6198  // DATE, Best Ask Date
#define T_MKT_MKR_COND          6199  // STRING, MktMkr Cond
#define T_BID_DATE              6200  // DATE, Bid Date
#define T_ASK_DATE              6201  // DATE, Ask Date
#define T_OPT_CALC_TYPE         6202  // STRING, Opt Calc Type
#define T_OPT_EXPIR_INDEX       6203  // INT, Opt Exp Index
#define T_SESSION               6204  // INT, Session
#define T_TRD_UNITS_FROMFEED    6205  // STRING, Trade Units (Feed)
#define T_LEAPSYM               6206  // STRING, LEAP Sym
#define T_LEAPSYM_2             6207  // STRING, LEAP Sym 2
#define T_QUOTE_UPDATE_TYPE     6208  // INT, Quote Update Type
#define T_FIXEDINCOME_DESCR     6211  // STRING, Fixed Income Desc.
#define T_TOTAL_VALUE           6212  // LONG, Total Value
#define T_DIVIDEND_12           6213  // LPACK, Div12
#define T_DIVIDEND_12_footnote  6214  // STRING, Div12 footnote
#define T_IMO_MARKER            6215  // STRING, IMO
#define T_RECORD_DATE           6216  // DATE, Rec Date
#define T_DIVIDEND_MARKER       6217  // STRING, Div Marker
#define T_DIVIDEND_TEXT         6218  // STRING, Div Text
#define T_GV1_TEXT              6219  // STRING, Generic Text 1
#define T_TRANSACTIONS          6220  // LONG, Trans
#define T_TOP_1                 6221  // STRING, Top1
#define T_TOP_2                 6222  // STRING, Top2
#define T_TOP_3                 6223  // STRING, Top3
#define T_TOP_4                 6224  // STRING, Top4
#define T_TOP_5                 6225  // STRING, Top5
#define T_TOP_6                 6226  // STRING, Top6
#define T_TOP_7                 6227  // STRING, Top7
#define T_TOP_8                 6228  // STRING, Top8
#define T_TOP_9                 6229  // STRING, Top9
#define T_TOP_10                6230  // STRING, Top10
#define T_MKT_MKR_BID           6231  // LPACK, MktMkr Bid
#define T_MKT_MKR_ASK           6232  // LPACK, MktMkr Ask
#define T_MKT_MKR_BIDEXID       6233  // STRING, MktMkr Bid Exch
#define T_MKT_MKR_ASKEXID       6234  // STRING, MktMkr Ask Exch
#define T_MKT_MKR_DATE          6235  // DATE, MktMkr Date
#define T_MKT_MKR_BID_TIME      6236  // TIME, MktMkr Time
#define T_MKT_MKR_BIDSIZE       6237  // LONG, MktMkr BidSize
#define T_MKT_MKR_ASKSIZE       6238  // LONG, MktMkr AskSize
#define T_SG_CURSOR             6240  // STRING, SymGuide Cursor
#define T_SG_MAX_MATCHES        6241  // INT, SymGuide Max
#define T_SG_SEARCH_DIRECTION   6242  // INT, SymGuide Search Dir
#define T_SG_TRUNCATED          6243  // INT, SymGuide Truncated
#define T_MKT_MKR_BEST_BID      6244  // LPACK, Best Bid
#define T_MKT_MKR_BEST_ASK      6245  // LPACK, Best Offer
#define T_MKT_MKR_ASK_TIME      6246  // TIME, Mkt Mkr Ask Time
#define T_MKT_MKR_BEST_BID_COUNT  6247  // LONG, # best bids
#define T_MKT_MKR_BEST_ASK_COUNT  6248  // LONG, # best offers
#define T_MKT_MKR_DISPLAY       6249  // STRING, MktMkr Display
#define T_LAST_YIELD            6250  // LPACK, Last Yield
#define T_YTM_INDICATIVE        6251  // DOUBLE, YTM Ind.
#define T_INDICATIVE_PRICE      6254  // LPACK, Ind. Price
#define T_SMALLCAP              6255  // STRING, Small Cap indicator
#define T_MKT_MKR_CHANGE_LAST_BID  6265  // LPACK, Bid Chg.
#define T_MKT_MKR_CHANGE_LAST_ASK  6266  // LPACK, Ask Chg.
#define T_15TH_RIC              6268  // STRING, 15th Sym
#define T_TOTAL_RETURN_INDEX    6269  // DOUBLE, TRI Level
#define T_BASE_FOR_INDEX        6270  // LONG, Index Base
#define T_QUOTED_MARKET_VALUE   6271  // LONG, Quoted Value
#define T_FLOAT                 6272  // LONG, Float Value
#define T_INDEX_ID              6273  // STRING, Index Id
#define T_MARKER                6274  // STRING, Markers
#define T_CATS_IND              6275  // STRING, CATS Indicator
#define T_OPTION_INDICATOR      6276  // STRING, Option Indic
#define T_DIVIDEND_INDIC_RATE   6277  // LPACK, Div IndicRate
#define T_YR_DIVIDEND_MISSED    6278  // INT, Yr DivMissed
#define T_EPS_CURRENT_INTERIM   6279  // LPACK, Interim EPS
#define T_ADR_SHARES            6280  // LONG, ADR shares
#define T_SP_FILE_DATE          6281  // DATE, File date
#define T_PRIMARY_EXCHANGE      6282  // STRING, Primary Exch
#define T_EXDIVDATE_ALT         6283  // DATE, ExDivDate(a)
#define T_MG_TICKER             6285  // STRING, Ticker Symbol
#define T_SYMBOL_ERROR          6331  // INT, Symbol Error
#define T_SYMBOL_ERROR_TEXT     6332  // STRING, Symbol Error text
#define T_DIVIDEND_FREQ_N       6333  // INT, Dividend freq
#define T_SECURITY_CATEGORY     6334  // INT, Security category
#define T_ISIN_NO               6335  // STRING, ISIN Number
#define T_SUSPENDED_INDICATOR   6336  // INT, Suspended Indicator
#define T_LVL2_BID1             6337  // LPACK, Best Level2 Bid
#define T_LVL2_BID1_SIZE        6338  // LONG, Best Level2 Bid Size
#define T_LVL2_BID1_TIME        6339  // TIME, Best Level2 Bid Time
#define T_LVL2_BID1_ID          6340  // STRING, Best Level2 Bid ID
#define T_LVL2_ASK1             6341  // LPACK, Best Level2 Offer
#define T_LVL2_ASK1_SIZE        6342  // LONG, Best Level2 Offer Size
#define T_LVL2_ASK1_TIME        6343  // TIME, Best Level2 Offer Time
#define T_LVL2_ASK1_ID          6344  // STRING, Best Level2 Offer ID
#define T_LVL2_BID_SIZE         6345  // LONG, Best Bids
#define T_LVL2_ASK_SIZE         6346  // LONG, Best Offers
#define T_LVL2_INSIDE_BID_ID    6347  // STRING, Inside Bid ID
#define T_LVL2_INSIDE_ASK_ID    6348  // STRING, Inside Ask ID
#define T_MKT_MKR_BID_ORDERS    6349  // LONG, MktMkr BidOrders
#define T_MKT_MKR_ASK_ORDERS    6350  // LONG, MktMkr AskOrders
#define T_BEST_BID1_SIZE        6351  // LONG, Best bid size
#define T_BEST_ASK1_SIZE        6352  // LONG, Best offer size
#define T_BEST_BID1_EXID        6353  // STRING, Best bid exchange
#define T_BEST_ASK1_EXID        6354  // STRING, Best offer exchange
#define T_FEED_NAME             6355  // STRING, Datafeed name
#define T_FEED_CLASS            6356  // STRING, Datafeed class
#define T_PARTY1_NAME           6357  // STRING, Party1 name
#define T_PARTY2_NAME           6358  // STRING, Party2 name
#define T_SESS_CLOSE_DATE       6359  // DATE, Session close date
#define T_SEDOL                 6360  // STRING, Sedol #
#define T_DISPTRDXID_1          6390  // STRING, Displayed TRDXID_1
#define T_DISPBIDEXID           6391  // STRING, Displayed BIDEXID
#define T_DISPASKEXID           6392  // STRING, Displayed ASKEXID
#define T_STEMPLATE_ID          6393  // LONG, Stemplate ID
#define T_PERMEXCHSECTYPE       6394  // LONG, Coded perm/exch/sectype
#define T_ORIG_TICKER           6395  // STRING, Original Ticker
#define T_LINE                  6396  // LONG, Line number
#define T_PREVDAY               6400  // STRING, Prev. Day
#define T_CORNAV                6401  // LPACK, NAV Correction
#define T_CAT                   6402  // STRING, Category Code
#define T_YECGD                 6403  // LPACK, Gains Distrib.
#define T_YEFN                  6404  // STRING, Distrib. Footnotes
#define T_CC                    6405  // INT, Condition Code
#define T_RELIND                6406  // STRING, Release Indicator
#define T_CDIV                  6407  // LPACK, Cash Dividends
#define T_NETCHNG               6408  // LPACK, Net Change
#define T_LBATE                 6410  // STRING, Last Price BATE
#define T_LOBATE                6411  // STRING, Low Price BATE
#define T_HIBATE                6412  // STRING, High Price BATE
#define T_RPTDBATE              6413  // STRING, Reported BATE
#define T_RANKTYP               6418  // INT, Ranking Type
#define T_RANKING               6419  // INT, Ranking
#define T_FEED_ACTION           6420  // INT, Feed action
#define T_SERVER_VERSION        6421  // STRING, Version number
#define T_SERVER_ID             6422  // STRING, Server ID
#define T_MCAST_ADDRESS         6423  // STRING, Multicast address
#define T_SERVER_TIME_OFFSET    6424  // LONG, Server time offset
#define T_SEQNUM_2              6431  // LONG, 2nd Sequence number
#define T_INTRADAY_HIGH_COUNT   6432  // LONG, #Highs
#define T_INTRADAY_LOW_COUNT    6433  // LONG, #Lows
#define T_TICK_SEQNUM           6434  // LONG, Tick sequence number
#define T_TICK_PRNTBCK          6435  // LONG, Seq number to cancel
#define T_ACVOL_1_64            6436  // INT64, Tot. Vol.
#define T_OPINT_1_64            6437  // INT64, Open Interest
#define T_HST_VOL_64            6438  // INT64, Hist Vol
#define T_MONEY_FLOW_64         6439  // INT64, Money Flow
#define T_VWAP_VOL_64           6440  // INT64, VWAP volume
#define T_REGIONAL_ACVOL_1_64   6441  // INT64, Rgnl AcVol
#define T_BAR_DATA_FLAGS        6450  // LONG, Bar Data Flags
#define T_LRP_BID               6460  // LPACK, LRP Bid
#define T_LRP_ASK               6461  // LPACK, LRP Ask
#define T_LRP_TIME              6462  // TIME, LRP Time
#define T_RINGAM1_BID           6500  // LPACK, Ring AM1 Bid
#define T_RINGAM1_BID_TIME      6501  // TIME, Ring AM1 Bid Time
#define T_RINGAM1_ASK           6502  // LPACK, Ring AM1 Ask
#define T_RINGAM1_ASK_TIME      6503  // TIME, Ring AM1 Ask Time
#define T_RINGAM1_TRADE_PRICE   6504  // LPACK, Ring AM1 Price
#define T_RINGAM1_TRADE_TIME    6505  // TIME, Ring AM1 Trade Time
#define T_RINGAM2_BID           6506  // LPACK, Ring AM2 Bid
#define T_RINGAM2_BID_TIME      6507  // TIME, Ring AM2 Bid Time
#define T_RINGAM2_ASK           6508  // LPACK, Ring AM2 Ask
#define T_RINGAM2_ASK_TIME      6509  // TIME, Ring AM2 Ask Time
#define T_RINGAM2_TRADE_PRICE   6510  // LPACK, Ring AM2 Price
#define T_RINGAM2_TRADE_TIME    6511  // TIME, Ring AM2 Trade Time
#define T_KERBAM_BID            6512  // LPACK, Kerb AM Bid
#define T_KERBAM_BID_TIME       6513  // TIME, Kerb AM Bid Time
#define T_KERBAM_ASK            6514  // LPACK, Kerb AM Ask
#define T_KERBAM_ASK_TIME       6515  // TIME, Kerb AM Ask Time
#define T_KERBAM_TRADE_PRICE    6516  // LPACK, Kerb AM Price
#define T_KERBAM_TRADE_TIME     6517  // TIME, Kerb AM Trade Time
#define T_RINGPM1_BID           6518  // LPACK, Ring PM1 Bid
#define T_RINGPM1_BID_TIME      6519  // TIME, Ring PM1 Bid Time
#define T_RINGPM1_ASK           6520  // LPACK, Ring PM1 Ask
#define T_RINGPM1_ASK_TIME      6521  // TIME, Ring PM1 Ask Time
#define T_RINGPM1_TRADE_PRICE   6522  // LPACK, Ring PM1 Trade Price
#define T_RINGPM1_TRADE_TIME    6523  // TIME, Ring PM1 Trade Time
#define T_RINGPM2_BID           6524  // LPACK, Ring PM2 Bid
#define T_RINGPM2_BID_TIME      6525  // TIME, Ring PM2 Bid Time
#define T_RINGPM2_ASK           6526  // LPACK, Ring PM2 Ask
#define T_RINGPM2_ASK_TIME      6527  // TIME, Ring PM2 Ask Time
#define T_RINGPM2_TRADE_PRICE   6528  // LPACK, Ring PM2 Trade Price
#define T_RINGPM2_TRADE_TIME    6529  // TIME, Ring PM2 Trade Time
#define T_KERBPM_BID            6530  // LPACK, Kerb PM Bid
#define T_KERBPM_BID_TIME       6531  // TIME, Kerb PM Bid Time
#define T_KERBPM_ASK            6532  // LPACK, Kerb PM Ask
#define T_KERBPM_ASK_TIME       6533  // TIME, Kerb PM Ask Time
#define T_KERBPM_TRADE_PRICE    6534  // LPACK, Kerb PM Price
#define T_KERBPM_TRADE_TIME     6535  // TIME, Kerb PM Trade Time
#define T_LATENCY_1             6600  // LONG, Latency1
#define T_LATENCY_2             6601  // LONG, Latency2
#define T_LATENCY_3             6602  // LONG, Latency3
#define T_LATENCY_4             6603  // LONG, Latency4
#define T_LATENCY_5             6604  // LONG, Latency5
#define T_LATENCY_6             6605  // DOUBLE, Latency6
#define T_LATENCY_DEST          6606  // DOUBLE, LatencyDest
#define T_GATEWAY_FORWARD_LATENCY  6630  // DOUBLE, GatewayForwardLatency
#define T_TRADESRV_FORWARD_LATENCY  6631  // DOUBLE, TradesrvForwardLatency
#define T_HANDLER_FORWARD_LATENCY  6632  // DOUBLE, HandlerForwardLatency
#define T_EXCHANGE_LATENCY      6633  // DOUBLE, ExchangeLatency
#define T_HANDLER_REVERSE_LATENCY  6634  // DOUBLE, HandlerReverseLatency
#define T_TRADESRV_REVERSE_LATENCY  6635  // DOUBLE, TradesrvReverseLatency
#define T_GATEWAY_REVERSE_LATENCY  6636  // DOUBLE, GatewayReverseLatency
#define T_HANDLER_EXCHANGE_LATENCY  6640  // DOUBLE, HandlerExchangeLatency
#define T_SCAN_TYPE             6700  // LONG, Scan Type
#define T_THEMIS_SERVER         6800  // STRING, Themis Server
#define T_THEMIS_TABLE          6801  // STRING, Themis Table
#define T_THEMIS_DELETE         6802  // INT, Themis Delete
#define T_THEMIS_STATUS         6803  // INT, Themis Status
#define T_THEMIS_KEY            6804  // STRING, Themis Key
#define T_THEMIS_CONNECTION_TYPE  6805  // INT, Themis Connection Type
#define T_THEMIS_PEER           6806  // STRING, Themis Peer
#define T_THEMIS_COL_1          6807  // STRING, Themis Col 1
#define T_THEMIS_COL_2          6808  // STRING, Themis Col 2
#define T_THEMIS_COL_3          6809  // STRING, Themis Col 3
#define T_THEMIS_COL_4          6810  // STRING, Themis Col 4
#define T_THEMIS_COL_5          6811  // STRING, Themis Col 5
#define T_THEMIS_COL_6          6812  // STRING, Themis Col 6
#define T_THEMIS_COL_7          6813  // STRING, Themis Col 7
#define T_THEMIS_COL_8          6814  // STRING, Themis Col 8
#define T_THEMIS_COMMAND        6815  // STRING, Themis Command
#define T_THEMIS_COMMAND_ARGS   6816  // VECTOR_STRING, Themis Command Args
#define T_THEMIS_COMMAND_TEXT   6817  // STRING, Themis Command Text
#define T_THEMIS_COMMAND_ARGS_TEXT  6818  // VECTOR_STRING, Themis Command Args Text
#define T_THEMIS_COMMAND_ARGS_TYPE  6819  // VECTOR_INT, Themis Command Args Type
#define T_THEMIS_COMMAND_ARGS_SOURCE  6820  // VECTOR_STRING, Themis Command Args Source
#define T_THEMIS_COMMAND_WARNING  6821  // STRING, Themis Command Warning
#define T_THEMIS_TITLE          6822  // STRING, Themis Title
#define T_THEMIS_COLUMNS        6823  // VECTOR_STRING, Themis Columns
#define T_THEMIS_STATUS_TYPE    6824  // INT, Themis Status Type
#define T_THEMIS_STAT_NAME      6825  // STRING, Themis Stat Name
#define T_THEMIS_STAT_VALUE     6826  // STRING, Themis Stat Value
#define T_THEMIS_MODULE         6827  // STRING, Themis Module
#define T_THEMIS_VERSION        6828  // STRING, Themis Version
#define T_AVG_VOL               7000  // LONG, Avg Vol
#define T_DIVIDEND_YIELD        7001  // LPACK, Div Yield
#define T_DIVIDEND_RATE         7002  // LPACK, Div Rate
#define T_INT_EARN_PERIOD       7003  // STRING, Int. Earn. Period
#define T_EPS_INTERIM           7004  // LPACK, EPS Interim
#define T_EARNINGS_12           7005  // LPACK, Earnings 12
#define T_EARNINGS_YEAR         7006  // INT, Earnings Year
#define T_EARNINGS_NEXT         7007  // LPACK, Earnings Next
#define T_EARNINGS_COMMENT      7008  // STRING, Earnings Comment
#define T_INT_EARN_COMMENT      7009  // STRING, Int. Earn. Comment
#define T_5YEAR_GROWTH          7010  // LPACK, 5-Year Growth
#define T_FISCAL_YEAR_END       7011  // STRING, Fisc. Year End
#define T_CUSIP                 7012  // STRING, CUSIP
#define T_SP500                 7013  // INT, S&P 500
#define T_SP_RANK               7014  // STRING, S&P Rank
#define T_PERC_HELD             7015  // INT, Percent Held
#define T_SP_STARS              7016  // INT, S&P Stars
#define T_BETA                  7017  // LPACK, Beta
#define T_CURRENT_ASSETS        7018  // LPACK, Curr. Assets
#define T_CURRENT_LIABILITIES   7019  // LPACK, Curr. Liabilities
#define T_BALANCE_SHEET_DATE    7020  // DATE, Balance Sheet Date
#define T_LONG_DEBT             7021  // LPACK, LongTerm Debt
#define T_COMMON_SHARES_OUT     7022  // LONG, Common Shares Out
#define T_PREFERRED_SHARES_OUT  7023  // LONG, Pref. Shares Out
#define T_FINANCIAL_COMMENT     7024  // STRING, Fin. Comment
#define T_REF_YEAR_HIGH_LOW     7025  // INT, Ref Year High/Low
#define T_HIGH_52_1             7026  // LPACK, High 52 1
#define T_LOW_52_1              7027  // LPACK, Low 52 1
#define T_HIGH_52_2             7028  // LPACK, High 52 2
#define T_LOW_52_2              7029  // LPACK, Low 52 2
#define T_HIGH_52_3             7030  // LPACK, High 52 3
#define T_LOW_52_3              7031  // LPACK, Low 52 3
#define T_HIGH_52_4             7032  // LPACK, High 52 4
#define T_LOW_52_4              7033  // LPACK, Low 52 4
#define T_REF_YEAR_DIVIDENDS    7034  // INT, Ref Year Div
#define T_DIVIDEND_1            7035  // LPACK, Div 1
#define T_DIVIDEND_2            7036  // LPACK, Div 2
#define T_DIVIDEND_3            7037  // LPACK, Div 3
#define T_DIVIDEND_4            7038  // LPACK, Div 4
#define T_REF_YEAR_ER_EQ_RV_NI  7039  // INT, Ref Year ER EQ RV NI
#define T_EARNINGS_1            7040  // LPACK, Earnings 1
#define T_EARNINGS_2            7041  // LPACK, Earnings 2
#define T_EARNINGS_3            7042  // LPACK, Earnings 3
#define T_EARNINGS_4            7043  // LPACK, Earnings 4
#define T_EQUITY_1              7044  // LPACK, Equity 1
#define T_EQUITY_2              7045  // LPACK, Equity 2
#define T_EQUITY_3              7046  // LPACK, Equity 3
#define T_EQUITY_4              7047  // LPACK, Equity 4
#define T_REVENUE_1             7048  // LPACK, Revenue 1
#define T_REVENUE_2             7049  // LPACK, Revenue 2
#define T_REVENUE_3             7050  // LPACK, Revenue 3
#define T_REVENUE_4             7051  // LPACK, Revenue 4
#define T_NET_INCOME_1          7052  // LPACK, Net Income 1
#define T_NET_INCOME_2          7053  // LPACK, Net Income 2
#define T_NET_INCOME_3          7054  // LPACK, Net Income 3
#define T_NET_INCOME_4          7055  // LPACK, Net Income 4
#define T_SPLIT_FACTOR_1        7056  // DOUBLE, Split Factor 1
#define T_SPLIT_DATE_1          7057  // DATE, Split Date 1
#define T_SPLIT_FACTOR_2        7058  // DOUBLE, Split Factor 2
#define T_SPLIT_DATE_2          7059  // DATE, Split Date 2
#define T_SPLIT_FACTOR_3        7060  // DOUBLE, Split Factor 3
#define T_SPLIT_DATE_3          7061  // DATE, Split Date 3
#define T_EPS_V_PRIOR_YEAR      7062  // LPACK, EPS V Prior Year
#define T_DIVIDEND_YIELD_footnote  7200  // STRING, Div Yield footnote
#define T_DIVIDEND_footnote     7201  // STRING, Div footnote
#define T_DIVIDEND_RATE_footnote  7202  // STRING, Div Rate footnote
#define T_EPS_INTERIM_footnote  7203  // STRING, EPS Interim footnote
#define T_EARNINGS_12_footnote  7204  // STRING, Earnings 12 footnote
#define T_EARNINGS_footnote     7205  // STRING, Earnings footnote
#define T_EARNINGS_NEXT_footnote  7206  // STRING, Earnings Next footnote
#define T_LONG_DEBT_footnote    7207  // STRING, Long Term Debt footnote
#define T_COMMON_SHARES_OUT_footnote  7208  // STRING, Common Shares Out Footnote
#define T_PREFERRED_SHARES_OUT_footnote  7209  // STRING, Pref. Shares Out footnote
#define T_DIVIDEND_1_footnote   7210  // STRING, Div 1 footnote
#define T_DIVIDEND_2_footnote   7211  // STRING, Div 2 footnote
#define T_DIVIDEND_3_footnote   7212  // STRING, Div 3 footnote
#define T_DIVIDEND_4_footnote   7213  // STRING, Div 4 footnote
#define T_EARNINGS_1_footnote   7214  // STRING, Earnings 1 footnote
#define T_EARNINGS_2_footnote   7215  // STRING, Earnings 2 footnote
#define T_EARNINGS_3_footnote   7216  // STRING, Earnings 3 footnote
#define T_EARNINGS_4_footnote   7217  // STRING, Earnings 4 footnote
#define T_EPS_V_PRIOR_YEAR_footnote  7218  // STRING, EPS V Prior Year footnote
#define T_SPECIAL_DIVIDEND      7300  // LPACK, Special Div
#define T_MATURITY_DIVIDEND     7301  // LPACK, Matur. Div
#define T_SPECIAL_DIVDATE       7302  // DATE, Special DivDate
#define T_MATURITY_DIVDATE      7303  // DATE, Mat. DivDate
#define T_SHARES_OUT            7304  // LONG, Shares Out
#define T_SP_INDUSTRY_CODE      7305  // INT, S&P Ind. Code
#define T_SP_CATEGORY_CODE      7306  // INT, S&P cat. code
#define T_BOOK_VALUE            7307  // LPACK, Book Val
#define T_DIVIDEND_FREQ         7308  // STRING, Div Freq
#define T_YEAR_DIV_LAST_MISSED  7309  // INT, Year Div Last Missed
#define T_INTERIM_PERIOD_END    7310  // INT, Interim period start
#define T_INTERIM_PERIOD_DURATION  7311  // INT, Interim period duration
#define T_EPS_LAST_INTERIM      7312  // LPACK, EPS prev interim
#define T_EPS_GROWTH_RATE       7313  // LPACK, EPS growth  rate
#define T_INST_OWNERS           7314  // LONG, Inst Holders
#define T_INST_SHARES_HELD      7315  // LONG, Inst Shares
#define T_BETA_WO_DIV           7316  // LPACK, Beta w/o dividends
#define T_SALES                 7317  // LPACK, Annual sales
#define T_INCOME                7318  // LPACK, Annual income
#define T_FISCAL_PERIOD         7319  // INT, Fiscal Period
#define T_ISSUE_TYPE            7320  // STRING, Issue type
#define T_SP_INDUSTRY_CODE_2    7321  // INT, SP Ind. Code
#define T_CLOSE50DAVG_1D        7322  // DOUBLE, Avg Price 50d
#define T_CLOSE200DAVG_1D       7323  // DOUBLE, Avg Price 200d
#define T_RSI14D_1D             7324  // DOUBLE, RSI 14d
#define T_STOCH_K10D_D3_1D      7325  // DOUBLE, Stochastic
#define T_MACD_1D               7326  // DOUBLE, MACD
#define T_MACDSIGNAL_1D         7327  // DOUBLE, MACD Signal
#define T_VOLUME20DAVG_1D       7328  // DOUBLE, Avg Vol 20d
#define T_VOLUME50DAVG_1D       7329  // DOUBLE, Avg Vol 50d
#define T_VOLUME200DAVG_1D      7330  // DOUBLE, Avg Vol 200d
#define T_VOLUME5DAVG_1D        7331  // DOUBLE, Avg Vol 5d
#define T_VOLUME10DAVG_1D       7332  // DOUBLE, Avg Vol 10d
#define T_CLOSE5DAVG_1D         7333  // DOUBLE, Avg Price 5d
#define T_CLOSE10DAVG_1D        7334  // DOUBLE, Avg Price 10d
#define T_CLOSE20DAVG_1D        7335  // DOUBLE, Avg Price 20d
#define T_RSI9D_1D              7336  // DOUBLE, RSI 9d
#define T_RSI25D_1D             7337  // DOUBLE, RSI 25d
#define T_BOLLINGER_UPPER21D_1D 7338  // DOUBLE, Bollinger U 21d
#define T_BOLLINGER_LOWER21D_1D 7339  // DOUBLE, Bollinger L 21d
#define T_ADX14D_1D             7340  // DOUBLE, ADX 14d
#define T_PLUSDI14D_1D          7341  // DOUBLE, PDI 14d
#define T_MINUSDI14D_1D         7342  // DOUBLE, MDI 14d
#define T_HIGH15DMAX_1D         7343  // DOUBLE, 15d High
#define T_LOW15DMIN_1D          7344  // DOUBLE, 15d Low
#define T_HLVOLATILITY10D_1D    7345  // DOUBLE, HL Volatility 10d
#define T_SHORT_INTEREST        7346  // LONG, Short Interest
#define T_GICS_SECTOR           7347  // STRING, GICS Sector Code
#define T_GICS_INDUSTRY         7348  // STRING, GICS Industry Code
#define T_GICS_SUBINDUSTRY      7349  // STRING, GICS Sub-Industry Code
#define T_SRSI9D_1D             7350  // DOUBLE, sRSI 9d
#define T_SRSI14D_1D            7351  // DOUBLE, sRSI 14d
#define T_SRSI25D_1D            7352  // DOUBLE, sRSI 25d
#define T_CLOSE_1W              7353  // LPACK, 1 wk close
#define T_CLOSE_1M              7354  // LPACK, 1 mon close
#define T_CLOSE_1Q              7355  // LPACK, 1 Qtr close
#define T_CLOSE_1Y              7356  // LPACK, 1 Yr close
#define T_CLOSE_1W_TD           7357  // LPACK, TD wk close
#define T_CLOSE_1M_TD           7358  // LPACK, TD mon close
#define T_CLOSE_1Q_TD           7359  // LPACK, TD Q close
#define T_CLOSE_1Y_TD           7360  // LPACK, TD Yr close
#define T_NETCHNG_1W            7361  // LPACK, NetChg1W
#define T_NETCHNG_1M            7362  // LPACK, NetChg1M
#define T_NETCHNG_1Q            7363  // LPACK, NetChg1Q
#define T_NETCHNG_1Y            7364  // LPACK, NetChg1Y
#define T_NETCHNG_1W_TD         7365  // LPACK, NetChgWTD
#define T_NETCHNG_1M_TD         7366  // LPACK, NetChgMTD
#define T_NETCHNG_1Q_TD         7367  // LPACK, NetChgQTD
#define T_NETCHNG_1Y_TD         7368  // LPACK, NetChgYTD
#define T_PCTCHNG_1W            7369  // LPACK, PctChg1W
#define T_PCTCHNG_1M            7370  // LPACK, PctChg1M
#define T_PCTCHNG_1Q            7371  // LPACK, PctChg1Q
#define T_PCTCHNG_1Y            7372  // LPACK, PctChg1Y
#define T_PCTCHNG_1W_TD         7373  // LPACK, PctChgWTD
#define T_PCTCHNG_1M_TD         7374  // LPACK, PctChgMTD
#define T_PCTCHNG_1Q_TD         7375  // LPACK, PctChgQTD
#define T_PCTCHNG_1Y_TD         7376  // LPACK, PctChgYTD
#define T_VOL_PER_SHARE         8100  // LONG, Vol Per Share
#define T_BID_REGIS_NO          8101  // LONG, Bid Reg. No.
#define T_ASK_REGIS_NO          8102  // LONG, Ask Reg. No.
#define T_BROKER_BID_NO         8103  // LONG, Broker Bid No
#define T_BROKER_ASK_NO         8104  // LONG, Broker Ask No
#define T_BROKER_BUY_NO         8105  // LONG, Broker Buy No
#define T_BROKER_SELL_NO        8106  // LONG, Broker Sell No
#define T_AVG_PRICE             8107  // DOUBLE, Avg Price
#define T_NUM_ASKS              8108  // LONG, No. Asks
#define T_TENOR                 8109  // STRING, Tenor
#define T_GROUP                 9000  // STRING, Group
#define T_COLLECT_STATUS        9001  // INT, Collect Status
#define T_QUOTE_STATUS          9002  // INT, Internal Quote Status
#define T_SYNTHETIC             9003  // INT, Synthetic?
#define T_DAYS_BACK             9004  // INT, Days Back
#define T_BARINTERVAL           9005  // INT, Bar Interval
#define T_STARTONBOUND          9006  // INT, Start on Bound
#define T_STARTDATE             9007  // DATE, Start Date
#define T_STOPDATE              9008  // DATE, Stop Date
#define T_CHART_STARTTIME       9009  // TIME, Chart Start Time
#define T_CHART_STOPTIME        9010  // TIME, Chart Stop Time
#define T_CHART_ALL_TICKS       9011  // INT, Chart All Tick
#define T_CHART_FILL_BARS       9012  // INT, Chart Fill Bars
#define T_IS_ACTIVE             9013  // INT, Is Active
#define T_CHART_FLAGS           9014  // INT, Chart Flags
#define T_MINUTES_BACK          9015  // INT, Minutes Back
#define T_TICK_TYPE             9020  // INT, Tick Type
#define T_UPDATE_TYPE           9021  // INT, Update Type
#define T_CHART_TABLES          9022  // STRING, Chart Tables
#define T_TABLE                 9023  // STRING, Table
#define T_NEW_NAME              9031  // STRING, New Name
#define T_RENAME_DATE           9032  // DATE, Rename Date
#define T_PASSTHRU              9033  // INT, PASSTHRU
#define T_LISTNAME              9034  // STRING, List Name
#define T_AUTOADD               9035  // INT, Auto Add
#define T_FIDGROUP_NAME         9036  // STRING, Template name
#define T_FIDGROUP_FIDS         9037  // VECTOR_INT, Fields in template
#define T_ADVISE_UNCH_FIELDS    9038  // INT, Send Unchanged fields
#define T_REQUEST_ID            9039  // LONG, Request Id
#define T_RECORD_STATUS         9041  // INT, Record status
#define T_ADVISE_ID             9042  // LONG, Advise ID
#define T_SERVER_CLASS          9050  // STRING, Server Class
#define T_SERVER_CLASS_ATTRIBUTES  9051  // STRING, Server Class Attributes
#define T_SERVER_CLASS_MACHINE  9052  // STRING_VECTOR, Server Class Machine
#define T_UTC_OFFSET            9053  // INT, UTC Offset
#define T_USER_SYMBOL           9054  // STRING, User Symbol
#define T_SYMBOLOGY             9055  // INT, Symbology
#define T_EXCHANGE_UTC_OFFSET   9056  // LONG, Exchange UTC Offset
#define T_SERVER_STATUS         9201  // INT, Server status
#define T_SERVER_RANK           9202  // INT, Server rank
#define T_STATUS_INTERVAL       9203  // INT, Server status interval
#define T_NEXT_RESET_TIME       9204  // LONG, Next reset time
#define T_NEXT_SETTLE_TIME      9205  // LONG, Next settle time
#define T_MSG_TIMER_HIGH        9998  // LONG, NULL
#define T_MSG_TIMER_LOW         9999  // LONG, NULL
#define T_C_SYMBOL              10000  // STRING, Symbol
#define T_C_UPDATE              10001  // INT, Update Flags
#define T_C_CHSETT              10002  // LPACK, Chg. Settle
#define T_C_CHOPEN              10003  // LPACK, Chg. Open
#define T_C_CHPREV              10004  // LPACK, Chg. Prev
#define T_C_CHSETTP             10005  // DPACK, Net Chg. %
#define T_C_CHOPENP             10006  // DPACK, Chg. Open %
#define T_C_CHOVER              10007  // LPACK, Chg. Over
#define T_C_CHOVERP             10008  // DPACK, Chg. Over %
#define T_C_POSITION            10009  // DOUBLE, Position
#define T_C_PL                  10010  // DOUBLE, P&L Total
#define T_C_PL_TODAY            10011  // DOUBLE, P&L Intraday pos
#define T_C_PL_OPNPOS           10012  // DOUBLE, P&L Overnight Pos
#define T_C_PL_PERSHARE         10013  // DOUBLE, P&L per share
#define T_C_HIST_PL             10014  // DOUBLE, Overnight Hist P&L
#define T_C_HIST_NET_PL         10015  // DOUBLE, Hist P&L
#define T_C_HIST_NET_PL_PERSHARE  10016  // DOUBLE, Hist P&L per Share
#define T_C_NETPOS_TODAY        10020  // DOUBLE, Pos Today
#define T_C_NETPOS_OVERNIGHT    10021  // DOUBLE, Pos Overnight
#define T_C_TOTAL_PROFIT        10022  // DOUBLE, Total Profit
#define T_C_VWAP_EFFICIENCY     10023  // DOUBLE, VWAP Efficiency
#define T_C_NEW_HIGH52          10024  // INT, New High52
#define T_C_NEW_LOW52           10025  // INT, New Low52
#define T_C_INTRADAY_CASH_BALANCE  10026  // DOUBLE, Intraday Cash
#define T_C_NETCHNG_POST        10027  // LPACK, Irg NetChg
#define T_C_52_WEEK_PCT         10028  // DOUBLE, 52-Week Pct
#define T_C_NETCHNG_POST2       10029  // LPACK, Irg NetChg Today
#define T_C_PCTCHNG_POST        10030  // LPACK, Irg %Chg
#define T_C_PCTCHNG_POST2       10031  // LPACK, Irg %Chg Today
#define T_C_SYMBOL_GROUP        10032  // LONG, Symbol Group
#define T_C_CUSIP_OR_ISIN       10033  // STRING, CUSIP/ISIN
#define T_C_BBO_MID             10034  // DOUBLE, Midpoint
#define T_C_BUYORSELL_DISP      10035  // STRING, Buy/Sell Disp
#define T_C_NET_PROFIT          10036  // DOUBLE, Net Profit
#define T_C_HIST_TOTAL_PROFIT   10037  // DOUBLE, Hist Total Profit
#define T_C_HIST_NET_PROFIT     10038  // DOUBLE, Hist Net Profit
#define T_C_FX_BID_DIGITS       10039  // LONG, Fx Bid Digits
#define T_C_FX_ASK_DIGITS       10040  // LONG, Fx Ask Digits
#define T_C_LONG_SHORT_POS_IND  10041  // LONG, Long/Short Indicator
#define T_C_LAST_PRICE_REF      10042  // LPACK, Last Price Ref
#define T_C_COUNTRY_FLAG        10043  // STRING, Country Flag
#define T_C_ORDER_GROSS_MARKET_VALUE  10044  // DOUBLE, Order Gross Mkt Value
#define T_C_ORDER_NET_MARKET_VALUE  10045  // DOUBLE, Order Net Mkt Value
#define T_C_UNDERLIER_NET_PNL   10046  // DOUBLE, Underlier Net P&L
#define T_C_PNL_MKT_PRICE_L     10047  // DOUBLE, P&L Mkt Prc (Long)
#define T_C_PNL_MKT_PRICE_S     10048  // DOUBLE, P&L Mkt Prc (Short)
#define T_C_DAY_PNL             10049  // DOUBLE, Day P&L
#define T_C_DIR                 10110  // INT, Dir. Last
#define T_C_NEWSPRESENT         10111  // INT, News Present
#define T_C_NEWSTODAY           10112  // TIME, News Time Today
#define T_C_DIRNET              10113  // INT, Dir. Net
#define T_C_USER_TEXT           10114  // STRING, User Text
#define T_C_DIRNAS              10115  // INT, Dir. Nasdaq
#define T_C_PERATIO             10116  // DOUBLE, P/E Ratio (Live)
#define T_C_YIELD               10117  // DOUBLE, Yield
#define T_C_BIDASK_SPREAD       10118  // LPACK, Bid-Ask Spread
#define T_C_LOWER_BOUND         10119  // DOUBLE, Lower Bound
#define T_C_UPPER_BOUND         10120  // DOUBLE, Upper Bound
#define T_C_USER_ALERT          10121  // INT, User Alert
#define T_C_BIDASK              10122  // STRING, Bid/Ask
#define T_C_BIDASK_SIZE         10123  // STRING, Bid/Ask Size
#define T_C_RANGE_TODAY         10124  // LPACK, Range Today
#define T_C_PCT_WEEK_VOL        10125  // DOUBLE, Week Vol %
#define T_C_GAP_OPEN            10126  // LPACK, Gap Open
#define T_C_RANGE_TODAY_PCT     10127  // DOUBLE, Range Today Pct.
#define T_C_BIDASK_LOCK_CROSS   10128  // INT, Locked/Crossed Indicator
#define T_C_HIGH_LOW_INDICATOR  10129  // INT, High/Low Indicator
#define T_C_BIDASK_SPREAD_PCT   10130  // DOUBLE, Bid-Ask Spread %
#define T_C_PUT_CALL_RATIO      10131  // DOUBLE, Put/Call Ratio
#define T_C_AG_BIDASK_SIZE      10132  // STRING, Ag Bid/Ask Size
#define T_C_BOND_YTM_BID        10138  // DOUBLE, YTM - Bid
#define T_C_BOND_YTM_ASK        10139  // DOUBLE, YTM - Ask
#define T_C_BOND_ACCRUED_INTEREST  10140  // DOUBLE, Acc. Interest
#define T_C_BOND_INVOICE_PRICE  10141  // DOUBLE, Net Price
#define T_C_BOND_YIELD          10142  // DOUBLE, Bond Yield
#define T_C_BOND_NEXT_COUPON    10143  // DATE, Next Coupon
#define T_C_BOND_ORDER_INVOICE_PRICE  10144  // DOUBLE, Net Order Price
#define T_C_SETTLE_DATE         10145  // DATE, Settle Date
#define T_C_NET_POS_COST        10146  // DOUBLE, Cost of Net Pos
#define T_C_DIFF5DAVG           10147  // LPACK, Diff 5d Avg
#define T_C_DIFF10DAVG          10148  // LPACK, Diff 10d Avg
#define T_C_DIFF20DAVG          10149  // LPACK, Diff 20d Avg
#define T_C_DIFF50DAVG          10150  // LPACK, Diff 50d Avg
#define T_C_DIFF200DAVG         10151  // LPACK, Diff 200d Avg
#define T_C_DIFF_VOL_200_50     10152  // LPACK, Diff Vol 200/50
#define T_C_DIFF_VOL20_PCT      10153  // LPACK, %Diff Vol20
#define T_C_CURR_BID_YIELD      10154  // DOUBLE, Current bid yield
#define T_C_CURR_ASK_YIELD      10155  // DOUBLE, Current ask yield
#define T_C_ORDER_LIQ_INDICATOR 10156  // DOUBLE, Liquidity Indicator
#define T_C_NETCHNG_AUCTION     10157  // LPACK, Auction NetChg
#define T_C_PCTCHNG_AUCTION     10158  // LPACK, Auction %Chg
#define T_C_NETCHNG_AUCTION2    10159  // LPACK, Auction NetChg2
#define T_C_PCTCHNG_AUCTION2    10160  // LPACK, Auction %Chg2
#define T_C_INDEX_COMPONENT_PRICE  10161  // LPACK, Pricing for Index
#define T_C_PREF_SYMBOL         10162  // STRING, Preferred Symbol
#define T_C_TARGET_PCT_ADV_5    10163  // DOUBLE, Target 5-day ADV Percent
#define T_C_TARGET_PCT_ADV_10   10164  // DOUBLE, Target 10-day ADV Percent
#define T_C_TARGET_PCT_ADV_20   10165  // DOUBLE, Target 20-day ADV Percent
#define T_C_TARGET_PCT_ADV_50   10166  // DOUBLE, Target 50-day ADV Percent
#define T_C_TARGET_PCT_ADV_200  10167  // DOUBLE, Target 200-day ADV Percent
#define T_C_ORDER_PROFIT_REAL   10168  // DOUBLE, Order Realized P&L
#define T_C_ORDER_PROFIT_REAL_CPS  10169  // DOUBLE, Order Realized P&L CPS
#define T_C_ORDER_PROFIT_REAL_BPS  10170  // DOUBLE, Order Realized P&L BPS
#define T_C_ORDER_PROFIT_UNREAL 10171  // DOUBLE, Order Unrealized P&L
#define T_C_ORDER_PROFIT_UNREAL_CPS  10172  // DOUBLE, Order Unrealized P&L CPS
#define T_C_ORDER_PROFIT_UNREAL_BPS  10173  // DOUBLE, Order Unrealized P&L BPS
#define T_C_ORDER_PROFIT_NET    10174  // DOUBLE, Order Net P&L
#define T_C_ORDER_PROFIT_NET_CPS  10175  // DOUBLE, Order Net P&L CPS
#define T_C_ORDER_PROFIT_NET_BPS  10176  // DOUBLE, Order Net P&L BPS
#define T_C_ORDER_BENCHMARK_VALUE  10177  // DOUBLE, Order Benchmark Value
#define T_C_UNALLOCATED_SHARES  10178  // DOUBLE, Unallocated Shares
#define T_C_FX_RATE             10179  // DOUBLE, Local Fx Cross Rate
#define T_C_NETCHNG_POST3       10180  // LPACK, Irg NetChg Present
#define T_C_PCTCHNG_POST3       10181  // LPACK, Irg % Chg Present
#define T_C_MOST_RECENT_PRICE   10182  // LPACK, Most Recent Price
#define T_C_EXECUTED_VALUE      10183  // DOUBLE, Executed value of trade
#define T_C_MOST_RECENT_PRICE_CHANGE  10184  // LPACK, Most Recent Price Change
#define T_C_MOST_RECENT_PRICE_CHANGE_PCT  10185  // DOUBLE, Most Recent Price Change %
#define T_C_NET_IMBALANCE       10186  // LONG, Net Imbalance
#define T_C_W_PUT_CALL_RATIO    10187  // DOUBLE, Weighted put/call ratio
#define T_C_OPT_VOL             10188  // LONG, Option Volume (calculated)
#define T_C_PCT_TRADED_TO_MKT_VOL  10189  // DOUBLE, Exec % of Mkt Vol
#define T_C_SPREAD_MARKET       10190  // DOUBLE, Market Spread
#define T_C_SPREAD_PASSIVE      10191  // DOUBLE, Passive Spread
#define T_C_SPREAD_LL           10192  // DOUBLE, Spread Last-Last
#define T_C_SPREAD_BA           10193  // DOUBLE, Spread Bid-Ask
#define T_C_SPREAD_BB           10194  // DOUBLE, Spread Bid-Bid
#define T_C_SPREAD_AA           10195  // DOUBLE, Spread Ask-Ask
#define T_C_SPREAD_AB           10196  // DOUBLE, Spread Ask-Bid
#define T_C_TRADER_GROUP        10197  // STRING, Trader Group
#define T_C_IS_ALLOCATED        10198  // INT, Is Allocated
#define T_C_IS_LINKED           10199  // INT, Is Linked
#define T_C_EXTERNAL_CUST_DESC  10200  // STRING, Ext Cust Desc
#define T_C_NETCHNG_1W          10201  // LPACK, Wk chg
#define T_C_NETCHNG_1M          10202  // LPACK, mon chg
#define T_C_NETCHNG_1Q          10203  // LPACK, Qtr chg
#define T_C_NETCHNG_1Y          10204  // LPACK, Yr chg
#define T_C_NETCHNG_1W_TD       10205  // LPACK, TD wk chg
#define T_C_NETCHNG_1M_TD       10206  // LPACK, TD mon chg
#define T_C_NETCHNG_1Q_TD       10207  // LPACK, TD Qtr chg
#define T_C_NETCHNG_1Y_TD       10208  // LPACK, TD Yr Chg
#define T_C_PCTCHNG_1W          10209  // LPACK, Wk % Chg
#define T_C_PCTCHNG_1M          10210  // LPACK, Mon % Chg
#define T_C_PCTCHNG_1Q          10211  // LPACK, Qtr % Chg
#define T_C_PCTCHNG_1Y          10212  // LPACK, Yr % Chg
#define T_C_PCTCHNG_1W_TD       10213  // LPACK, TD Wk % Chg
#define T_C_PCTCHNG_1M_TD       10214  // LPACK, TD Mon % Chg
#define T_C_PCTCHNG_1Q_TD       10215  // LPACK, TD Qtr % Chg
#define T_C_PCTCHNG_1Y_TD       10216  // LPACK, TD Yr % Chg
#define T_C_CANDLESTICK         10217  // LPACK, Daily Candle
#define T_C_MKT_CAP_GROUP       10218  // STRING, Mkt Cap Group
#define T_C_SPREAD_MM           10219  // DOUBLE, Spread Mid-Mid
#define T_C_SPREAD_CLOSE        10220  // DOUBLE, Spread Close
#define T_C_SPREAD_PERCENT_CHANGE  10221  // DOUBLE, Spread % Change
#define T_C_AUTO_ROUTED_ORDER   10222  // LONG, Auto Routed Order
#define T_C_ADR_CONVERT_ELIGIBLE  10223  // LONG, ADR Convert Eligible
#define T_C_COMMISSION_DETAILS  10224  // STRING, Commission Details
#define T_C_BUSTED              10225  // STRING, Trade Busted
#define T_C_CONVERT_AVAIL       10226  // LONG, Convert Avail.
#define T_C_IS_DISMISSED        10227  // INT, Is Dismissed
#define T_C_TODAY_VOLUME_TRADED 10228  // LONG, Volume Traded Today
#define T_C_TODAY_TRADE_AVG_PRC 10229  // DOUBLE, Today's Avg Price
#define T_NYLQ_QUOTE_STATUS     11000  // STRING, NYLQ Quote Status
#define T_NYLQ_UPDATE_TYPE      11001  // LONG, NYLQ Update Type
#define T_NYLQ_BID              11005  // LPACK, NYLQ Bid
#define T_NYLQ_BID_SIZE         11006  // LONG, NYLQ Bid Size
#define T_NYLQ_BID_TIME         11007  // TIME, NYLQ Bid Time
#define T_NYLQ_ASK              11010  // LPACK, NYLQ Ask
#define T_NYLQ_ASK_SIZE         11011  // LONG, NYLQ Ask Size
#define T_NYLQ_ASK_TIME         11012  // TIME, NYLQ Ask Time
#define T_NEWS_DISP_DATE        13019  // DATE, "Display Date" sent by datafeed
#define T_NEWS_DISP_TIME        13020  // TIME, "Display Time" sent by datafeed
#define T_NEWS_RCV_DATE         13021  // DATE, receipt date
#define T_NEWS_RCV_TIME         13022  // TIME, receipt time
#define T_NEWS_TEMPORARY        13023  // INT, Temporary Story Indicator
#define T_NEWS_RECNUM           13024  // LONG, News Record Number
#define T_DJNEWS_ACCESSION_NUMBER  13025  // STRING, Accession Number
#define T_NEWS_ORIG_SOURCE      13026  // STRING, Original Source
#define T_NEWS_SOURCE_2         13027  // STRING, Alternate News Source
#define T_STAT_NAME             13050  // STRING, Stat Name
#define T_STAT_DESC             13051  // STRING, Stat Desc
#define T_STAT_VALUE            13052  // STRING, Stat Value
#define T_P_USERNAME            13100  // STRING, User Name
#define T_P_APPNAME             13101  // STRING, App Name
#define T_P_PROPERTY            13102  // STRING, Property
#define T_P_VALUE               13103  // STRING, Value
#define T_P_SUBTABLE            13104  // STRING, Subtable.
#define T_P_SYMBOL              13105  // STRING, Symbol
#define T_P_DESCRIPTION         13106  // STRING, Description
#define T_P_MACHINENAME         13107  // STRING, Machine Name
#define T_P_DOMAINNAME          13108  // STRING, Domain Name
#define T_P_ISLOCAL             13109  // INT, TALIPC flag
#define T_P_SERVICEADDR         13110  // STRING, ServiceAddress
#define T_P_USERPASSWD          13111  // STRING, Password given during permission
#define T_COMPRESSION_TYPES_SEND  13112  // INT_VECTOR, Compression types sendable
#define T_COMPRESSION_TYPES_RECV  13113  // INT_VECTOR, Compression types we can receive
#define T_P_TALUSER             13114  // STRING, TAL user name
#define T_P_TALDOMAIN           13115  // STRING, TAL domain name
#define T_P_USERID_RANDNO       13116  // STRING, Internal only
#define T_P_COOKIE              13117  // INT, Internal use
#define T_CRYPT_TYPES_SEND      13118  // INT_VECTOR, internal
#define T_CRYPT_TYPES_RECV      13119  // INT_VECTOR, internal
#define T_CRYPT_CERT            13120  // STRING_VECTOR, Internal
#define T_P_BUILD_VERSION       13121  // STRING, Build Version
#define T_P_LOGON_TIME          13122  // STRING, Logon Time
#define T_P_APPNAMES            13123  // STRING_VECTOR, App Names
#define T_P_APPTIMES            13124  // STRING_VECTOR, App Times
#define T_P_USER_MSG            13125  // STRING, Message from Perms
#define T_P_MSG_DISP_TIME       13126  // INT, Message Display Time
#define T_P_PERMITS             13127  // STRING_VECTOR, Permits for Property
#define T_P_SEND_DNS_NAME       13128  // INT, Send DNS Names
#define T_P_SALT                13129  // STRING_VECTOR, permissions salt
#define T_P_CHALLENGE           13130  // STRING_VECTOR, permissions challenge
#define T_P_CHANGE_TYPE         13131  // SHORT, pw change type
#define T_P_CHANGE_REASON       13132  // STRING, pw change reason
#define T_P_FEATURES            13133  // LONG, perms server features
#define T_P_PASSCODE            13134  // STRING, SecurID Passcode
#define T_P_PIN                 13135  // STRING, PIN
#define T_P_NEW_PIN_STATUS      13136  // SHORT, New PIN Status
#define T_P_NEW_PIN_TYPE        13137  // SHORT, New PIN Type
#define T_P_PIN_MINLEN          13138  // SHORT, Minimum PIN Length
#define T_P_PIN_MAXLEN          13139  // SHORT, Maximum PIN Length
#define T_P_PIN_ALPHA           13140  // SHORT, Alphanumeric PINs?
#define T_P_TTNODES             13141  // STRING_VECTOR, Talk-To Nodes
#define T_P_PRIMARY             13142  // STRING, Primary Node
#define T_P_TT_MODE             13143  // SHORT, Talk-To Mode
#define T_P_AUTH_TYPE           13144  // INT, Auth type
#define T_P_PKCS10_REQUEST      13145  // STRING_VECTOR, PKCS#10 Request
#define T_P_PKCS10_HASH         13146  // STRING_VECTOR, Hash of PKCS#10 Request
#define T_P_USER_ID             13147  // LONG, Immutable user-id
#define T_P_PKCS7_CERT          13148  // STRING_VECTOR, Certificate in PKCS#7 format
#define T_P_CERTREQTYPE         13149  // LONG, Certificate type to request
#define T_P_UID                 13150  // STRING, User's UID
#define T_ELF_ROUTE             13151  // STRING, ELF Route
#define T_ELF_RANGE_LOW         13152  // STRING, ELF Range LOW
#define T_ELF_RANGE_HIGH        13153  // STRING, ELF Range HIGH
#define T_ELF_INCLUDE_SYMS      13154  // VECTOR_STRING, ELF Symbol List
#define T_ELF_EXCLUDE_SYMS      13155  // VECTOR_STRING, ELF Symbols Excluded
#define T_ELF_MOD_ACTION        13156  // SHORT, ELFMod Action
#define T_ECN_ELF_MACHINE       13157  // STRING, ELF machine
#define T_ECN_SPLIT_MACHINE     13158  // STRING, Split machine
#define T_ECN_CLIENT            13159  // STRING, ECN Client (user id)
#define T_ECN_CLIENT_ELF_STATE  13160  // SHORT, Client connection state
#define T_USER_TAG1             13161  // STRING, UserTag1 field in Task
#define T_USER_TAG2             13162  // STRING, UserTag2 field in Task
#define T_OATS_ID               13163  // STRING, OATS ID
#define T_ELFX_ORDER_FLAGS      13164  // LONG, ElfX Order Properties
#define T_PREF_XML              13165  // STRING, Pending Preferences
#define T_VOLUME_LOCKED         13166  // LONG, Locked Volume
#define T_PERF_OBJECT_NAME      13501  // STRING, Performance Object Name
#define T_PERF_COUNTER_NAME     13502  // STRING, Performance Counter Name
#define T_PERF_INSTANCE_NAME    13503  // STRING, Performance Instance Name
#define T_PERF_VALUE            13504  // DOUBLE, Performance Value
#define T_MSGAPP_SEVERITY       13505  // LONG, Message App Severity
#define T_MSGAPP_TIME           13506  // TIME, Message App Time
#define T_MSGAPP_DATE           13507  // DATE, Message App Date
#define T_MSGAPP_TEXT           13508  // STRING, Message App Message
#define T_PROCESS_IMAGE_NAME    13509  // STRING, Process Image Name
#define T_PROCESS_PID           13510  // LONG, Process PID
#define T_PROCESS_USERNAME      13511  // STRING, Process Username
#define T_PROCESS_CPU_TIME      13512  // LONG, Process CPU Time
#define T_PROCESS_MEMORY        13513  // LONG, Process Memory
#define T_PROCESS_FLAGS         13514  // LONG, Process Flags
#define T_PERF_MACHINE          13515  // STRING, Machine to monitor
#define T_RESV14000             14000  // INT, NULL
#define T_CA_MKT                14116  // STRING, sub-exch disp code
#define T_CA_PREV_SYMBOL        14200  // STRING, Prev Symbol
#define T_CA_PREV_CUSIP         14201  // STRING, Prev CUSIP
#define T_CA_PREV_COMPANY_NAME  14202  // STRING, Prev Co. Name
#define T_CA_IPO_SYMBOL         14203  // STRING, IPO Symbol
#define T_CA_DELISTED_SYMBOL    14204  // STRING, Delisted Symbol
#define T_CA_DIV_AMOUNT         14205  // DOUBLE, Div Amount
#define T_CA_SPLIT_RATIO        14206  // STRING, Split Amount
#define T_CA_SPLIT_FACTOR       14207  // DOUBLE, Split Factor
#define T_CA_ADJ_FACTOR         14208  // DOUBLE, Adj Factor
#define T_CA_DIV_PERCENT        14209  // STRING, Div %
#define T_CA_EFF_DATE           14210  // DATE, Effective Date
#define T_CA_EXCH_NAME          14211  // STRING, Exch Name
#define T_CA_PREV_EXCH_NAME     14212  // STRING, Prev Exch Name
#define T_CA_RESUMED_SYMBOL     14213  // STRING, Resumed Symbol
#define T_CA_SUSPENDED_SYMBOL   14214  // STRING, Susp. Symbol
#define T_CA_PREV_MKT           14216  // STRING, Prev Market
#define T_CA_TYPE               14217  // INT, Corp. action type
#define T_CA_VALIDATED          14218  // INT, Action Validated
#define T_RESV15000             15000  // INT, NULL
#define T_ALGO_START_TIME       15500  // STRING, Algo Time 1
#define T_ALGO_END_TIME         15501  // STRING, Algo Time 2
#define T_ALGO_MIN_VOL          15502  // LONG, Algo Vol 1
#define T_ALGO_MAX_VOL          15503  // LONG, Algo Vol 2
#define T_FIX_BOOK_TYPE         15504  // STRING, FIX Booking Type
#define T_FIX_ORDER             15505  // STRING, FIX Order
#define T_FIX_CLORD_ID          15506  // STRING, FIX ClOrdID
#define T_FIX_MSG               15507  // STRING, FIX Msg
#define T_GENERIC_FOOTNOTE      16998  // STRING, Generic Footnote
#define T_GENERIC_COMMENT       16999  // STRING, Generic Comment
#define T_MACHINE_NAME          17000  // STRING, Machine Name
#define T_SERVICE_NAME          17001  // STRING, Service Name
#define T_TOPIC_NAME            17002  // STRING, Topic Name
#define T_TN_DESIRABILITY       17003  // INT, TN DESIRABILITY
#define T_TN_FLAGS              17004  // INT, TN FLAGS
#define T_TALIPC_CONVS          17005  // LONG, Talipc Convs
#define T_TALIPC_LAST_OUT       17006  // LONG, Time since send
#define T_TALIPC_LAST_IN        17007  // LONG, Time since recv
#define T_TALIPC_IDLE_TIMEOUT   17008  // LONG, Idle timeout
#define T_TALIPC_TX_MSG_BUF     17009  // LONG, Tx msgs buffered
#define T_TALIPC_TX_DISCARD     17010  // LONG, Tx discarding flag
#define T_TALIPC_TX_BYTES_BUF   17011  // LONG, Tx bytes buffered
#define T_TALIPC_TX_COMP_TYPE   17012  // LONG, Tx compress type
#define T_TALIPC_TX_COMP_RATIO  17013  // LONG, Tx compress ratio
#define T_TALIPC_RX_MSG_BUF     17014  // LONG, Rx msgs buffered
#define T_TALIPC_RX_STALLED     17015  // LONG, Rx stalled
#define T_TALIPC_RX_BYTES_BUF   17016  // LONG, Rx bytes buffered
#define T_TALIPC_RX_COMP_TYPE   17017  // LONG, Rx compress type
#define T_TALIPC_RX_COMP_RATIO  17018  // LONG, Rx compress ratio
#define T_TALIPC_PARTNER_CUR_BUF  17019  // LONG, Current Buffer Usage
#define T_TALIPC_PARTNER_MAX_BUF  17020  // LONG, Max Buffer Size
#define T_TALIPC_RX_BPS         17021  // LONG, Rx Bps
#define T_TALIPC_ACTIVE_SERVICES  17022  // STRING, Active Services
#define T_TALIPC_MSG_LATENCY    17023  // LONG, Rx Msg Latency
#define T_TALIPC_LATENCY_SPAN   17024  // LONG, Rx Latency Span
#define T_TALCA_INBOUND_UPDATES 17100  // LONG, CA Inbound Updates
#define T_TALCA_OUTBOUND_UPDATES  17101  // LONG, CA Outbound Updates
#define T_TALCA_REQUESTS        17102  // LONG, CA Requests
#define T_TALCA_INBOUND_RESPONSES  17103  // LONG, CA Inbound Responses
#define T_TALCA_OUTBOUND_RESPONSES  17104  // LONG, CA Outbound Responses
#define T_IOI_ID                17200  // STRING, IOI ID
#define T_IOI_REF_ID            17201  // STRING, IOI Ref ID
#define T_IOI_ACTION_TYPE       17202  // INT, IOI Action Type
#define T_IOI_FROM_ID           17203  // STRING, IOI From ID
#define T_IOI_TO_ID             17204  // STRING, IOI To ID
#define T_IOI_DATE              17205  // DATE, IOI Date
#define T_IOI_TIME              17206  // TIME, IOI Time
#define T_IOI_EXPIR_DATE        17207  // DATE, IOI Exp Date
#define T_IOI_EXPIR_TIME        17208  // TIME, IOI Exp Time
#define T_IOI_SIZE_TYPE         17209  // INT, IOI Size Type
#define T_IOI_NATURAL_FLAG      17210  // INT, IOI Natural Flag
#define T_IOI_NOTES             17211  // STRING, IOI Notes
#define T_IOI_URL               17212  // STRING, IOI URL
#define T_IOI_STATUS            17213  // INT, IOI Status
#define T_IOI_DESCRIPTION       17214  // STRING, IOI Description
#define T_Q_ID                  17300  // STRING, Quote ID
#define T_Q_USER_ID             17301  // STRING, User ID
#define T_Q_REQUESTOR_ID        17302  // STRING, Requestor ID
#define T_Q_ROUTE_TO            17303  // STRING, Route To
#define T_Q_COMMENT_TEXT        17304  // STRING, Comment
#define T_Q_QUOTE_ACTION        17305  // LONG, Action
#define T_Q_DATE                17306  // DATE, Date
#define T_Q_TIME                17307  // TIME, Time
#define T_Q_SIDE                17308  // LONG, Side
#define T_Q_VALIDITY            17309  // LONG, Validity
#define T_Q_INDICATIVE          17310  // INT, Indicative
#define T_Q_VENDOR_REF_ID       17311  // STRING, Vendor Quote Ref ID
#define T_Q_BUY_SELL_TYPE       17312  // LONG, Buy / Sell
#define T_Q_RAW_PRICE           17313  // LPACK, Raw Price
#define T_Q_PRICE               17314  // LPACK, Price
#define T_Q_CURRENCY1           17315  // STRING, Currency 1
#define T_Q_CURRENCY2           17316  // STRING, Currency 2
#define T_Q_AMOUNT              17317  // DOUBLE, Amount
#define T_Q_QUOTE_BASIS         17318  // INT, Inverse
#define T_Q_QUOTE_UNIT          17319  // LONG, Quote Unit
#define T_Q_TYPE                17320  // LONG, Quote Type
#define T_Q_VALUE_DATE          17321  // DATE, Value Date
#define T_Q_VALUE_TIME          17322  // TIME, Value Time
#define T_Q_VALUE_PERIOD        17323  // STRING, Value Period
#define T_Q_ALLOW_DATE_ROLL     17324  // INT, Allow Date Roll
#define T_Q_FAR_VALUE_DATE      17325  // DATE, Far Value Date
#define T_Q_FAR_VALUE_TIME      17326  // TIME, Far Value Time
#define T_Q_FAR_VALUE_PERIOD    17327  // STRING, Far Value Period
#define T_Q_VENDOR_SERIAL_NO    17328  // INT, Vendor Serial No.
#define T_Q_WARNING             17329  // STRING, Warning
#define T_Q_CLIENT_ID           17330  // STRING, Client ID
#define T_Q_TAG                 17331  // STRING, Client supplied tag
#define T_Q_STATUS              17332  // LONG, RFQ Status
#define T_Q_RAW_BID             17333  // DOUBLE, Raw Bid
#define T_Q_RAW_ASK             17334  // DOUBLE, Raw Ask
#define T_Q_BID                 17335  // LPACK, Bid
#define T_Q_ASK                 17336  // LPACK, Ask
#define T_Q_REQUESTOR_REF       17337  // STRING, Requestor Reference
#define T_Q_NEAR_PERIOD         17338  // STRING, Near Period
#define T_Q_COUNTERPARTY_ID     17339  // STRING, Counterparty ID
#define T_Q_NEAR_DATE           17440  // DATE, Near Date
#define T_Q_NEAR_TIME           17441  // TIME, Near Time
#define T_Q_TIME_STAMP_DATE     17442  // DATE, Timestamp Date
#define T_Q_TIME_STAMP_TIME     17443  // TIME, Timestamp Time
#define T_Q_SPOT_DATE           17444  // DATE, Spot Date
#define T_Q_SPOT_TIME           17445  // TIME, Spot Time
#define T_Q_SPOT_BID            17446  // LPACK, Spot Bid
#define T_Q_SPOT_ASK            17447  // LPACK, Spot Ask
#define T_Q_SWAP_POINT_FACTOR   17448  // LPACK, Swap Point Factor
#define T_Q_COUNTER_AMT_BID     17449  // LPACK, Counter Amt. Bid
#define T_Q_COUNTER_AMT_ASK     17450  // LPACK, Counter Amt. Ask
#define T_Q_NEAR_COUNTER_AMT_BID  17451  // LPACK, Near Counter Amt. Bid
#define T_Q_NEAR_COUNTER_AMT_ASK  17452  // LPACK, Near Counter Amt. Ask
#define T_Q_NEAR_BID            17453  // LPACK, Near Bid
#define T_Q_NEAR_ASK            17454  // LPACK, Near Ask
#define T_Q_RATE                17455  // DOUBLE, Rate
#define T_Q_COUNTER_AMT         17456  // DOUBLE, Counter Amount
#define T_Q_NEAR_COUNTER_AMT    17457  // DOUBLE, Near Counter Amount
#define T_Q_SPOT_RATE           17458  // DOUBLE, Spot Rate
#define T_Q_NEAR_RATE           17459  // DOUBLE, Near Rate
#define T_Q_DEALT_CURRENCY      17460  // STRING, The dealt currency
#define T_Q_SWAP_AMOUNT         17461  // DOUBLE, The volume of dealt currency
#define T_ALLOCATED_ORDER_IDS   17462  // STRING, Orders allocated to bulk order
#define T_ALLOCATED_ORDER_TAGS  17463  // STRING, OrderTags allocd to bulk order
#define T_Q_BID_FORWARD_PTS     17464  // DOUBLE, Bid Forward Pts
#define T_Q_ASK_FORWARD_PTS     17465  // DOUBLE, Ask Forward Pts
#define T_Q_BID_SWAP_PTS        17466  // DOUBLE, Bid Swap Pts
#define T_Q_ASK_SWAP_PTS        17467  // DOUBLE, Ask Swap Pts
#define T_Q_SWAP_COUNTER_AMT    17468  // DOUBLE, Forex Swap/Far Amount 2
#define T_Q_NEAR_TENOR          17469  // STRING, Forex Forward/Near Tenor
#define T_Q_FAR_TENOR           17470  // STRING, Forex Swap/Far Tenor
#define T_ALLOCATED_ACCOUNTS    17471  // STRING, Allocated account
#define T_ALLOCATED_QUANTITIES  17472  // STRING, Allocated quantity
#define T_ALLOCATED_COMMISSIONS 17473  // STRING, Allocated commissions
#define T_ALLOCATED_COMMISSION_TYPES  17474  // STRING, Allocated commission types
#define T_ALLOCATED_PROCESS_CODES  17475  // STRING, Allocated process codes
#define T_SETTLE_TYPE           17476  // LONG, Settlement type
#define T_Q_FORWARD_PTS         17477  // DOUBLE, Forward Pts
#define T_Q_SETTLE_CURRENCY     17478  // STRING, Settlement currency
#define T_Q_CUMULATIVE_QTY      17479  // DOUBLE, Cumulative quantity
#define T_Q_LEAVES_QTY          17480  // DOUBLE, Leaves quantity
#define T_Q_SETTLE_QTY          17481  // DOUBLE, Settlement quantity
#define T_Q_AVG_ALL_IN_RATE     17482  // DOUBLE, Average all-in rate
#define T_ADMIN_RESERVED_FIRST  18000  // STRING, Reserved
#define T_ADMIN_RESERVED_LAST   18999  // STRING, Reserved
#define T_BANK                  20001  // STRING, Bank
#define T_BRANCH                20003  // STRING, Branch
#define T_STRIKEBASE            20007  // STRING, Strike Base
#define T_CUSTOMER              20008  // STRING, Customer
#define T_REAL_BANK             20010  // STRING, Real Bank
#define T_REAL_BRANCH           20011  // STRING, Real Branch
#define T_GATEWAY_TRADER_ID     20012  // STRING, Gateway Trader ID
#define T_USER_ORD_NUM          20013  // STRING, User Ord Num
#define T_HANDLER_ORDER_ID      20014  // STRING, Handler Order ID
#define T_HANDLER_CL_ORD_ID     20015  // STRING, Handler ClOrdID
#define T_LARGE_TRADER_ID       20020  // STRING, Large Trader ID
#define T_CUSTOMER_CURRENCY     20040  // STRING, Customer Currency
#define T_DEPOSIT               20052  // STRING, Deposit
#define T_CUSTODIAN             20053  // STRING, Custodian
#define T_SCALPED_BALANCE       20058  // DOUBLE, Balance
#define T_SCALPED_UNITS         20059  // DOUBLE, Price Units Scalped
#define T_CONV_PROFIT           20060  // STRING, Conv Profit
#define T_CONV_LEDGER           20061  // STRING, Conv Ledger
#define T_TBO_IS_USER_ACTIVE    20062  // LONG, User Active
#define T_TBO_IS_ACCOUNT_ACTIVE 20063  // LONG, Acct Active
#define T_TBO_ACCOUNT_ID        20064  // LONG, Acct ID
#define T_TBO_USER_ID           20065  // LONG, User ID
#define T_TBO_EXCH_HANDLER_ID   20066  // LONG, Exch Handler ID
#define T_ORIGINAL_BANK         20070  // STRING, Orig Bank
#define T_ORIGINAL_BRANCH       20071  // STRING, Orig Branch
#define T_ORIGINAL_CUSTOMER     20072  // STRING, Orig Cust
#define T_ORIGINAL_DEPOSIT      20073  // STRING, Orig Deposit
#define T_LAST_DIVIDEND_AMT     20124  // STRING, Last Div Amt
#define T_LAST_DIVIDEND_DT      20125  // STRING, Last Div Date
#define T_LAST_XDIVIDEND_AMT    20126  // STRING, Last X-Div Amt
#define T_LAST_XDIVIDEND_DT     20127  // STRING, Last X-Div Date
#define T_NEXT_DIVIDEND_AMT     20128  // STRING, Next Div Amount
#define T_NEXT_DIVIDEND_DT      20129  // STRING, Next Div Date
#define T_NEXT_XDIVIDEND_AMT    20130  // STRING, Next X-Div Amount
#define T_NEXT_XDIVIDEND_DT     20131  // STRING, Next X-Div Date
#define T_MRU_ROUTING_BBCD      20140  // STRING, MRU Sub Acct
#define T_TRADE_MOMENTUM        20141  // DOUBLE, Trade Momentum
#define T_LONGPOS               20165  // DOUBLE, Pos Long
#define T_SHORTPOS              20166  // DOUBLE, Pos Short
#define T_SETTLEMENT            20167  // STRING, Settlement
#define T_AVERAGE               20168  // STRING, Avg
#define T_POS_STATUS            20169  // STRING, Pos Status
#define T_AVERAGE_LONG          20170  // DOUBLE, Avg Prc Long
#define T_AVERAGE_SHORT         20171  // DOUBLE, Avg Prc Short
#define T_TARGET_POSITION       20172  // LONG, Target Position
#define T_NET_AVERAGE_PRICE     20173  // DOUBLE, Net Avg Prc
#define T_NET_POS_ACCT_TYPE     20174  // LONG, Net Pos Type
#define T_NET_MARKET_VALUE      20175  // DOUBLE, Mkt Value
#define T_LONG_MARKET_VALUE     20176  // DOUBLE, Long Mkt Value
#define T_SHORT_MARKET_VALUE    20177  // DOUBLE, Short Mkt Value
#define T_HIST_LONG_PRC         20178  // DOUBLE, Hist Long Prc
#define T_HIST_SHORT_PRC        20179  // DOUBLE, Hist Short Prc
#define T_HIST_LONG_PRC_0       20180  // DOUBLE, Hist Long Prc0
#define T_HIST_SHORT_PRC_0      20181  // DOUBLE, Hist Short Prc0
#define T_NET_HIST_PRICE        20182  // DOUBLE, Net Hist Price
#define T_GROSS_MARKET_VALUE    20183  // DOUBLE, Gross Mkt Value
#define T_HIST_SCALPED_PROFIT   20184  // DOUBLE, Hist Scalped Profit
#define T_ORIG_LONGPOS0         20185  // DOUBLE, Original Pos Long0
#define T_ORIG_SHORTPOS0        20186  // DOUBLE, Original Pos Short0
#define T_NET_FEES              20187  // DOUBLE, Net Fees
#define T_TYPE                  20200  // STRING, Event Type
#define T_BLOCK_ID              20201  // STRING, Block ID
#define T_VERSION_NO            20204  // INT, Version No.
#define T_VOLATIL_INTRVL_UP     20217  // STRING, Volatil Intrvl Up
#define T_VOLATIL_INTRVL_DN     20218  // STRING, Volatil Intrvl Dn
#define T_PRICE_INTRVL_UP       20219  // STRING, Price Intrvl Up
#define T_PRICE_INTRVL_DN       20220  // STRING, Price Intrvl Dn
#define T_RISK_FAC              20221  // STRING, Risk Fac
#define T_SPREAD_RISK_FAC       20222  // STRING, Spread Risk Fac
#define T_SCALPED_PROFIT        20223  // DOUBLE, Scalped Profit
#define T_COST                  20226  // DOUBLE, Cost
#define T_NET_BALANCE           20227  // STRING, Net Balance
#define T_LONGPOS0              20229  // DOUBLE, Pos Long0
#define T_SHORTPOS0             20230  // DOUBLE, Pos Short0
#define T_AVERAGE_LONG0         20231  // DOUBLE, Avg Prc Long0
#define T_AVERAGE_SHORT0        20232  // DOUBLE, Avg Prc Short0
#define T_LEDGER_BALANCE        20233  // STRING, Ledger Balance
#define T_NET_LIQ_NOW           20234  // STRING, Net Liq
#define T_TOTAL_POS_VALUE       20235  // STRING, Total Value
#define T_TOTAL_EQUITY_NOW      20236  // STRING, Total Equity
#define T_OPNFUT_PFTATOPN       20238  // STRING, Fut Profit at Open
#define T_OPNOPT_VALATOPN       20239  // STRING, Opt Value at Open
#define T_OPNPOS_PFTTODAY       20240  // STRING, Profit Today
#define T_TRDPOS_PFTNET         20241  // STRING, TrdPos Net Profit
#define T_NETPOS_PFTTODAY       20242  // STRING, NetPos Profit Today
#define T_OPNFUT_POSPFTATOPN    20243  // STRING, Open Fut: +Pft at open
#define T_OPNFUT_NEGPFTATOPN    20244  // STRING, Open Fut: -Pft at open
#define T_OPNEQU_POSPFTATOPN    20245  // STRING, Open Stk: +Pft at open
#define T_OPNEQU_NEGPFTATOPN    20246  // STRING, Open Stk: -Pft at open
#define T_RISK_MARGIN_REQ       20250  // DOUBLE, Risk Margin Requirement
#define T_RISK_MARGIN_REQ_PENDING  20251  // DOUBLE, Risk Margin Req. Pending
#define T_RISK_NET_LIQ          20252  // DOUBLE, Risk Margin Net Liq
#define T_RISK_NET_LIQ_PENDING  20253  // DOUBLE, Risk Margin Net Liq Pending
#define T_RISK_EXCESS_EQUITY    20254  // DOUBLE, Risk Excess Equity
#define T_ALARM_LIMIT1          20300  // STRING, Alarm Limit 1
#define T_ALARM_LIMIT2          20301  // STRING, Alarm Limit 2
#define T_ALARM_LIMIT3          20302  // STRING, Alarm Limit 3
#define T_ALARM_CODE1           20303  // STRING, Alarm Code 1
#define T_ALARM_CODE2           20304  // STRING, Alarm Code 2
#define T_ALARM_CODE3           20305  // STRING, Alarm Code 3
#define T_EXCHANGE              20400  // STRING, Exchange
#define T_VOLUME                20401  // LONG, Vol
#define T_BLOCK_SIZE            20402  // STRING, Block Size
#define T_PRICE                 20403  // LPACK, Price
#define T_ORDER_ID              20404  // STRING, Order ID
#define T_TRADER_ID             20405  // STRING, Trader ID
#define T_CLIENT_GROUP          20406  // STRING, Client Group
#define T_VALID                 20407  // STRING, Valid
#define T_UNTIL                 20408  // STRING, Until
#define T_RANK                  20409  // STRING, Rank
#define T_OPPOSITE_PARTY        20410  // STRING, Opp Party
#define T_BROKER_ID             20411  // STRING, Broker ID
#define T_REMOTE_ID             20412  // STRING, Remote ID
#define T_ACTION                20413  // STRING, Action
#define T_TIME_STAMP            20414  // STRING, Time Stamp
#define T_SOLSRV_STATUS         20415  // STRING, Solsrv Status
#define T_ORDER_STATUS          20416  // STRING, Order Status
#define T_LEDGER                20417  // DOUBLE, Ledger
#define T_OTE_NOW               20418  // DOUBLE, OTE Now
#define T_NOV                   20419  // DOUBLE, NOV
#define T_OTE                   20420  // DOUBLE, OTE
#define T_TOTAL_EQUITY          20421  // DOUBLE, Total Eq
#define T_NET_LIQ               20422  // DOUBLE, Net Liq
#define T_SECURITY              20423  // DOUBLE, Security
#define T_NAV_NOW               20424  // DOUBLE, NAV Now
#define T_NAV                   20425  // DOUBLE, NAV
#define T_FUT_PFT_TODAY         20426  // DOUBLE, Fut Pft Today
#define T_OPT_PFT_TODAY         20427  // DOUBLE, Opt Pft Today
#define T_NET_LIQ_CHANGE        20428  // DOUBLE, Net Liq Change
#define T_USER_NAV              20429  // DOUBLE, User NAV
#define T_LMV                   20430  // DOUBLE, LMV
#define T_LMV_NOW               20431  // DOUBLE, LMV Now
#define T_SMV                   20432  // DOUBLE, SMV
#define T_SMV_NOW               20433  // DOUBLE, SMV Now
#define T_LUV                   20434  // DOUBLE, LUV
#define T_LUV_NOW               20435  // DOUBLE, LUV Now
#define T_SUV                   20436  // DOUBLE, SUV
#define T_SUV_NOW               20437  // DOUBLE, SUV Now
#define T_SMA_0                 20438  // DOUBLE, Morning SMA
#define T_SMA_NOW               20439  // DOUBLE, Intraday SMA
#define T_ORQ_0                 20440  // DOUBLE, Morning ORQ
#define T_ORQ                   20441  // DOUBLE, Current ORQ
#define T_SPAN_RISK_0           20442  // DOUBLE, Morning Span Risk
#define T_SPAN_RISK             20443  // DOUBLE, Current Span Risk
#define T_HOUSE_EXCESS_0        20444  // DOUBLE, Overnight House Excess
#define T_HOUSE_EXCESS          20445  // DOUBLE, House Excess
#define T_CASH_AVAIL            20446  // DOUBLE, Cash Available
#define T_SMA_0_ADJ             20447  // DOUBLE, SMA_0 Adjust
#define T_PENDING_SMA_REQ       20448  // DOUBLE, Pending SMA Req
#define T_AVAIL_EXCESS          20449  // DOUBLE, Avail Excess
#define T_AVAIL_HOUSE_EXCESS    20450  // DOUBLE, Avail House Excess
#define T_AVAIL_SMA             20451  // DOUBLE, Avail SMA
#define T_PENDING_CASH_REQ      20452  // DOUBLE, Pending Cash Req
#define T_AVAIL_CASH            20453  // DOUBLE, Available Cash
#define T_HOUSE_EXCESS_NOW      20454  // DOUBLE, Intraday House Excess
#define T_INDICATED_CONTRA      20455  // STRING, Preferenced Party
#define T_ORIGINAL_PRICE        20456  // LPACK, Original Price
#define T_EXTENDED_STATE_FLAGS  20457  // LONG, Extended State Flags
#define T_SECOND_ORDER_TAG      20458  // STRING, 2nd Order Tag
#define T_ORIGINAL_CHANGE_ID    20459  // STRING, OrigChangeID
#define T_ORIGINAL_CANCEL_ID    20460  // STRING, OrigCancelId
#define T_ORIGINAL_ORDER_TAG    20461  // STRING, Original ClOrdId
#define T_MARKUP_RULESET_ID     20462  // STRING, Markup Ruleset ID
#define T_REMOTE_TRADER_ID      20463  // STRING, Remote Trader ID
#define T_PORTFOLIO_NAME        20464  // STRING, Portfolio
#define T_STARTING_MKT_VOL      20465  // LONG, Starting Mkt Vol
#define T_STARTING_MKT_VWAP     20466  // DOUBLE, Starting Mkt VWAP
#define T_ORDER_VWAP_DELTA      20467  // DOUBLE, Order VWAP Delta
#define T_ORDER_MKT_VOL_DELTA   20468  // LONG, Order Mkt Vol Delta
#define T_OPT_DELIVERABLE       20469  // INT, Option Deliverable
#define T_EXCHANGE_CROSS_FLAGS  20470  // LONG, Exchange Cross Flags
#define T_EXTERNAL_CUSTOMER     20471  // STRING, External Customer
#define T_EXTERNAL_TRADER       20472  // STRING, External Trader
#define T_EXTERNAL_CUST_ID      20473  // STRING, External Cust ID
#define T_SELLSHORT_EXEMPT_REASON  20480  // STRING, Short Exempt Reason
#define T_RISK                  20601  // DOUBLE, Risk
#define T_DATE_OF_MGN           20602  // STRING, Date of Mgn
#define T_PLDG_MGN              20603  // STRING, PLDG Mgn
#define T_VRTN_MGN              20604  // STRING, VRTN Mgn
#define T_PRV_RISK              20605  // STRING, Prv Risk
#define T_PRV_PLDG_MGN          20606  // STRING, Prv PLDG Mgn
#define T_PRV_VRTN_MGN          20607  // STRING, Prv VRTN Mgn
#define T_PRV_DATE_OF_MGN       20608  // STRING, Prv Date of Mgn
#define T_PRV_TIME_OF_MGN       20609  // STRING, Prv Time of Mgn
#define T_TIME_OF_MGN           20610  // STRING, Time of Mgn
#define T_ACCOUNT_STATUS        20611  // STRING, Acct. Status
#define T_NAME_1                20612  // STRING, Name 1
#define T_NAME_2                20613  // STRING, Name 2
#define T_EQUITY_BALANCE        20614  // DOUBLE, Equity Balance
#define T_CASH_BALANCE          20615  // DOUBLE, Cash Balance
#define T_VRTN_MGN_FUT          20616  // STRING, VRTN Mgn Fut
#define T_VRTN_MGN_EQU          20617  // STRING, VRTN Mgn Equ
#define T_NET_VALUE             20618  // STRING, Net Value
#define T_NET_VALUE_FUT         20619  // STRING, Net Value Fut
#define T_NET_VALUE_EQU         20620  // STRING, Net Value Equ
#define T_PRV_VRTN_MGN_FUT      20621  // STRING, PRV VRTN Mgn Fut
#define T_PRV_VRTN_MGN_EQU      20622  // STRING, PRV VRTN Mgn Equ
#define T_PRV_NET_VALUE         20623  // STRING, PRV Net Value
#define T_PRV_NET_VALUE_FUT     20624  // STRING, PRV Net Value Fut
#define T_PRV_NET_VALUE_EQU     20625  // STRING, PRV Net Value Equ
#define T_PROFIT_EQU            20626  // STRING, Profit - Equ
#define T_LOSS_EQU              20627  // STRING, Loss - Equ
#define T_PROFIT_FUT            20628  // STRING, Profit - Fut
#define T_LOSS_FUT              20629  // STRING, Loss - Fut
#define T_NET_CALLS             20630  // STRING, Net Calls
#define T_NET_PUTS              20631  // STRING, Net Puts
#define T_NET_UND               20632  // STRING, Net Und
#define T_NET_FUT               20633  // STRING, Net Fut
#define T_NET_DELTA             20634  // DOUBLE, Net Delta
#define T_NET_VEGA              20635  // DOUBLE, Net Vega
#define T_NET_GAMMA             20636  // DOUBLE, Net Gamma
#define T_NET_THETA             20637  // DOUBLE, Net Theta
#define T_PRV_PROFIT_EQU        20640  // STRING, Prv Profit Equ
#define T_PRV_LOSS_EQU          20641  // STRING, Prv Loss Equ
#define T_PRV_PROFIT_FUT        20642  // STRING, Prv Profit Fut
#define T_PRV_LOSS_FUT          20643  // STRING, Prv Loss Fut
#define T_ORDER_ASSIGNMENT      20644  // STRING, Order Assign
#define T_NET_POS               20645  // DOUBLE, Net Pos
#define T_POS_COUNT             20646  // DOUBLE, Pos Count
#define T_DEP_COUNT             20647  // DOUBLE, Dep Count
#define T_ERR_COUNT             20648  // DOUBLE, Err Count
#define T_LOV                   20649  // DOUBLE, LOV
#define T_SOV                   20650  // DOUBLE, SOV
#define T_LOV_NOW               20651  // DOUBLE, LOV Now
#define T_SOV_NOW               20652  // DOUBLE, SOV Now
#define T_NOV_NOW               20653  // DOUBLE, NOV Now
#define T_SCAN_RISK             20654  // DOUBLE, Scan Risk
#define T_SCAN_NUM              20655  // DOUBLE, Scan Num
#define T_MGN_RATIO             20656  // DOUBLE, Mgn  Ratio
#define T_MGN_CALL              20657  // DOUBLE, Mgn Call
#define T_OUTLOOK_NAME          20658  // STRING, Outlook Name
#define T_MOVE_NAME             20659  // STRING, Move Name
#define T_LONG_CALL_EQUIV_POS   20660  // DOUBLE, Long Call Equiv Pos
#define T_SHORT_CALL_EQUIV_POS  20661  // DOUBLE, Short Call Equiv Pos
#define T_LONG_PUT_EQUIV_POS    20662  // DOUBLE, Long Put Equiv Pos
#define T_SHORT_PUT_EQUIV_POS   20663  // DOUBLE, Short Put Equiv Pos
#define T_IMPLIED_MID           20669  // DOUBLE, Imp Vol - Mid
#define T_PRICE_RANGE           20670  // DOUBLE, Price Range
#define T_VLTY_RANGE            20671  // DOUBLE, Vlty Range
#define T_VLTY_MIN              20672  // DOUBLE, Vlty Min
#define T_VLTY_MAX              20673  // DOUBLE, Vlty Max
#define T_EXERCISE_TYPE         20674  // STRING, Exer. Type
#define T_ACCOUNTING_TYPE       20675  // STRING, Acc. Type
#define T_OUTLOOK               20676  // STRING, Outlook
#define T_BUYORSELL             20677  // STRING, Buy/Sell
#define T_GOOD_UNTIL            20678  // STRING, Good Until
#define T_VOLUME_TYPE           20679  // STRING, Vol Type
#define T_PRICE_TYPE            20680  // STRING, Price Type
#define T_EXIT_VEHICLE          20681  // STRING, Exit Vehicle
#define T_VOLUME_TRADED         20682  // LONG, Vol Traded
#define T_CURRENT_STATUS        20683  // STRING, Curr Status
#define T_REASON                20684  // STRING, Reason
#define T_ORIGINAL_ORDER_ID     20685  // STRING, Orig. Order ID
#define T_NEW_REMOTE_ID         20686  // STRING, New Remote ID
#define T_REFERS_TO_ID          20687  // STRING, Refers to ID
#define T_APPROVAL_1            20688  // STRING, Approv 1
#define T_APPROVAL_2            20689  // STRING, Approv 2
#define T_CLAIMED_BY_CLERK      20690  // STRING, Claimed By Clerk
#define T_USER_MESSAGE          20691  // STRING, User Msg
#define T_ORDER_TAG             20692  // STRING, Order Tag
#define T_EXIT_VEHICLE_DESC     20693  // STRING, Exit Vehicle Desc
#define T_EXIT_VEHICLE_FLAGS    20694  // LONG, Exit Vehicle Flags
#define T_ORDER_RESIDUAL        20695  // LONG, Residual Volume
#define T_ORDER_FLAGS           20696  // LONG, Order Flags
#define T_GOOD_FROM             20697  // STRING, Good From
#define T_BUYSELLTYPE           20698  // INT, Buy Sell Type
#define T_ORDER_DISP_PRICE      20699  // STRING, Order Price
#define T_ROW                   20700  // INT, Row
#define T_COL                   20701  // INT, Col
#define T_PANE                  20702  // INT, Pane
#define T_UNDERLIER_PRICE       20703  // LPACK, Und Price
#define T_UNDERLIER_CLOSE       20704  // LPACK, Und Close
#define T_VOLATILITY            20705  // DOUBLE, Volatility
#define T_DAYSLEFT              20706  // INT, Days Left
#define T_THEO                  20707  // DOUBLE, Theo
#define T_DELTA                 20708  // DOUBLE, Theo Delta
#define T_VEGA                  20709  // DOUBLE, Theo Vega
#define T_GAMMA                 20710  // DOUBLE, Theo Gamma
#define T_THETA                 20711  // DOUBLE, Theo Theta
#define T_IMPLIED               20712  // DOUBLE, Implied Vol
#define T_POSDELTA              20713  // DOUBLE, Pos Delta
#define T_POSVEGA               20714  // DOUBLE, Pos Vega
#define T_POSGAMMA              20715  // DOUBLE, Pos Gamma
#define T_POSTHETA              20716  // DOUBLE, Pos Theta
#define T_NETPOS                20717  // DOUBLE, Net Pos
#define T_RATE                  20718  // DOUBLE, Rate
#define T_IMPLIED_SETTLE        20719  // DOUBLE, Imp Vol - Settle
#define T_IMPLIED_BID           20720  // DOUBLE, Imp Vol - Bid
#define T_IMPLIED_ASK           20721  // DOUBLE, Imp Vol - Ask
#define T_PROFIT                20722  // DOUBLE, P&L
#define T_CHANGE_OPEN           20723  // LPACK, Change Open
#define T_CHANGE_CLOSE          20724  // LPACK, Change Close
#define T_CHANGE_SETTLE         20725  // LPACK, Change Settle
#define T_CALC_TIME             20726  // STRING, Calc Time
#define T_ORIGINAL_TRADER_ID    20727  // STRING, Orig Trd Id
#define T_INDEX_EQUIV           20728  // DOUBLE, S&P Equiv Delta
#define T_ECN_DATA_TYPE         20729  // INT, ECN Data Type
#define T_TRANS_PROPERTIES      20730  // LONG, Transaction Properties
#define T_EXIT_VEHICLE_IS_ROUTABLE  20731  // LONG, Exch Handler Routable
#define T_POSS_DUPE             20732  // INT, Poss Dupe
#define T_EXEC_PROCESS          20733  // STRING, Executing Process
#define T_ORDER_ROUTING_ID      20734  // STRING, Order Routing ID
#define T_ORDER_ROUTING_ID_TYPE 20735  // LONG, Order Routing ID Type
#define T_ORDER_CLEARING_ID     20736  // STRING, Order Clearing ID
#define T_ORDER_CLEARING_ID_TYPE  20737  // LONG, Order Clearing ID Type
#define T_SUITABILITY_ACCEPT    20738  // LONG, Suitability Accept Code
#define T_EFFECTIVE_GOOD_FROM   20739  // LONG, Effective Good From
#define T_EFFECTIVE_GOOD_UNTIL  20740  // LONG, Effective Good Until
#define T_TMO_CONVERSION_TIME   20741  // TIME, TMO Conversion Time
#define T_ROUTED_ORDER_TIMESTAMP  20742  // STRING, Routed Order Timestamp
#define T_DOLLAR_DELTA          20743  // DOUBLE, Dollar Delta
#define T_DOLLAR_GAMMA          20744  // DOUBLE, Dollar Gamma
#define T_ORDER_CAPACITY        20745  // STRING, Order Capacity
#define T_ORDER_RESTRICTIONS    20746  // STRING, Order Restrictions
#define T_DOLLAR_VEGA           20747  // DOUBLE, Dollar Vega
#define T_DOLLAR_THETA          20748  // DOUBLE, Dollar Theta
#define T_CURRENT_STOP_PRICE    20749  // LPACK, Current Stop Price
#define T_PRIOR_DAY_VOLUME_TRADED  20750  // LONG, Prior Day Volume Traded
#define T_PRIOR_DAY_TRADE_AVG_PRC  20751  // DOUBLE, Prior Day Avg Price
#define T_TRANS_COMPONENT       20752  // STRING, Trans Component
#define T_ORDER_NET_AMOUNT      20753  // DOUBLE, Order Net Amount
#define T_ORDER_TXN_NET_AMOUNT  20754  // DOUBLE, Txn Net Amount
#define T_ORDER_TAG_2           20755  // STRING, Order Tag 2
#define T_ORDER_RESIDUAL_PCT    20756  // DOUBLE, Residual Volume %
#define T_ACCOUNT_ROUTE_MAPPING_DATA  20757  // STRING, Acct Route Mapping Data
#define T_ORDER_COMPLETION_PCT  20758  // DOUBLE, Completion %
#define T_BOOKING_TYPE          20759  // INT, Booking Type
#define T_WORKED_ORDER_TYPE     20760  // LONG, Worked Order Type
#define T_ORDER_TRAILER_INFO    20761  // STRING, Order Trailer Info
#define T_ORDER_CMTA            20762  // STRING, CMTA
#define T_ACCOUNT_SHORT_NAME    20763  // STRING, Account Short Name
#define T_WORKING_QTY           20764  // LONG, Working Qty
#define T_FREE_QTY              20765  // LONG, Free Qty
#define T_COMMITTED_QTY         20766  // LONG, Committed Qty
#define T_TARGET_QTY            20767  // LONG, Target Qty
#define T_ORDER_TRAILER_INFO_2  20768  // STRING, Order Trailer 2
#define T_EXCHANGE_STATUS_TYPE  20769  // LONG, Exch Status Type
#define T_VIRTUAL_ORDER_STATUS  20770  // STRING, Order Status Display
#define T_CLIENT_WORKING_QTY    20771  // LONG, Client Working Qty
#define T_TOTAL_WORKING_QTY     20772  // LONG, Total Working Qty
#define T_ORDER_CHANGE_TIME     20773  // STRING, Change Timestamp
#define T_ORDER_REF_PRICE       20774  // DOUBLE, Order Ref Price
#define T_ORIG_BOND_PRICE       20775  // LPACK, Orig Bond Price
#define T_ORIG_UND_PRICE        20776  // LPACK, Orig Und Price
#define T_ORIG_HEDGE_RATIO      20777  // DOUBLE, Orig Delta
#define T_HEDGE_PRICE           20778  // DOUBLE, Hedge Price
#define T_DELTA_ADJ             20779  // DOUBLE, Delta Adj
#define T_DOLLAR_ADJ            20780  // DOUBLE, Dollar Adj
#define T_SHARE_GAMMA           20781  // DOUBLE, Share Gamma
#define T_PARENT_ORDER_TAG      20782  // STRING, Parent Tag
#define T_VOL_CHANGE            20783  // DOUBLE, Change in Volatility
#define T_CHEAPEXP_VOL          20784  // DOUBLE, Cheap/Expensive Vol
#define T_WORKING_QTY_DEST      20785  // LONG, Working Qty Dest
#define T_VOLUME_TRADED_DEST    20786  // LONG, Vol Traded Dest
#define T_ORDER_FLAGS_2         20787  // LONG, Order Flags 2
#define T_CROSS_TYPE            20788  // LONG, Cross Type
#define T_REASON_CODE           20789  // STRING, Reason Code
#define T_MAX_DELTA             20790  // DOUBLE, Max $ Delta
#define T_AUTO_HEDGE            20791  // LONG, Auto Hedge
#define T_MAX_HEDGE_ORDER       20792  // LONG, Max Hedge Order Size
#define T_TIME_TO_EXPIRATION    20793  // DOUBLE, Time To Expiration
#define T_ORDER_GROSS_AMOUNT    20794  // DOUBLE, Order Gross Amount
#define T_ORDER_TXN_GROSS_AMOUNT  20795  // DOUBLE, Txn Gross Amount
#define T_TS3_CONVERSION_RULE_FLAGS  20796  // LONG, Conversion Rule Flags
#define T_DELIVERY_INSTR        20797  // STRING, Delivery Instr
#define T_BOOK_BEST_BID         20800  // LPACK, Book best bid
#define T_BOOK_BEST_BID_VOL     20801  // LONG, Book best bid vol
#define T_BOOK_BEST_ASK         20802  // LPACK, Book best ask
#define T_BOOK_BEST_ASK_VOL     20803  // LONG, Book best ask vol
#define T_BOOK_PENDING_STATUS   20804  // STRING, Pending flag
#define T_NEWS_COUNT            20900  // INT, News Count
#define T_NEWS_START            20901  // DATE, News Start
#define T_NEWS_STOP             20902  // DATE, News Stop
#define T_NEWS_DESCRIPTION      20903  // STRING, News Description
#define T_NEWS_DEPTH            20904  // INT, News Depth
#define T_NEWS_SYM_LIST         20905  // VECTOR_STRING, News Sym List
#define T_NEWS_INSTR            20906  // INT, News Instr
#define T_NEWS_SEARCH           20907  // STRING, News Search
#define T_NEWS_KEYS             20908  // STRING, News Keys
#define T_NEWS_CAT_LIST         20909  // STRING_VECTOR, News Cat List
#define T_NEWS_SEARCH_LIST      20910  // STRING_VECTOR, News Search List
#define T_PAGED_NEWS_ROW        20911  // INT, Paged News Row
#define T_PAGED_NEWS_COL        20912  // INT, Paged News Col
#define T_PAGED_NEWS_TEXT       20913  // STRING, Paged News Text
#define T_PAGED_NEWS_ISPAGE     20914  // INT, Paged News IsPage
#define T_PAGED_NEWS_ATTRIBUTES 20915  // VECTOR_INT, Paged News Attrib
#define T_NEWS_ATTRIBUTES       20916  // VECTOR_INT, News Attrib
#define T_PAD                   20917  // EMPTY, Pad
#define T_HDLNTREE_TITLE        20918  // STRING, HldnTreeTiltle
#define T_HDLNTREE_LEVEL        20919  // INT, NodeLevel
#define T_HDLNTREE_NODETEXT     20920  // STRING, NodeText
#define T_NEWS_STORY_TRAILER    20921  // STRING, Text at end of story
#define T_NEWS_STARTTIME        20922  // TIME, Early time limit
#define T_NEWS_STOPTIME         20923  // TIME, Late time limit
#define T_NEWS_BRAND            20924  // STRING, Branding code
#define T_PARM_URL_KEY          20925  // STRING, Key
#define T_PARM_URL_URL          20926  // STRING, URL
#define T_NEWS_DATE_GMT         20927  // DATE, T_NEWS_DATE in GMT
#define T_NEWS_TIME_GMT         20928  // TIME, T_NEWS_TIME in GMT
#define T_NEWS_DISP_DATE_GMT    20929  // DATE, T_NEWS_DISP_DATE in GMT
#define T_NEWS_DISP_TIME_GMT    20930  // TIME, T_NEWS_DISP_TIME in GMT
#define T_NEWS_RCV_DATE_GMT     20931  // DATE, T_NEWS_RCV_DATE in GMT
#define T_NEWS_RCV_TIME_GMT     20932  // TIME, T_NEWS_RCV_TIME in GMT
#define T_NEWS_STARTDATE_GMT    20933  // DATE, T_NEWS_START in GMT
#define T_NEWS_STOPDATE_GMT     20934  // DATE, T_NEWS_STOP in GMT
#define T_NEWS_STARTTIME_GMT    20935  // TIME, T_NEWS_STARTTIME in GMT
#define T_NEWS_STOPTIME_GMT     20936  // TIME, T_NEWS_STOPTIME in GMT
#define T_MOVED_PRICE           21000  // STRING, Moved Price
#define T_STRATEGY_DISPLAY_TEXT_1  21001  // STRING, Strategy Parameter
#define T_STRATEGY_NAME         21002  // STRING, Strategy Name
#define T_SPREAD_LEG_BUYSELL    21010  // INT, Spread Leg Buy/Sell
#define T_SPREAD_LEG_TRADE_QTY_MULT  21011  // DOUBLE, Spread Leg Mult
#define T_SPREAD_LEG_COEFFICIENT  21012  // DOUBLE, Spread Leg Coefficient
#define T_SPREAD_EXCH_TRADABLE  21013  // INT, Spread Exch. Tradable
#define T_SPREAD_NUM_WAVES      21014  // LONG, Spread #Waves
#define T_SPREAD_LEG_PRICE_TYPE 21015  // LONG, Spread Leg Price Type
#define T_SPREAD_PAUSE          21016  // LONG, Spread Pause Time
#define T_SPREAD_LEG_LEAN_PRIORITY  21017  // LONG, Spread Leg Lean Priority
#define T_SPREAD_LEG_ORDER      21018  // LONG, Spread Leg Order
#define T_SPREAD_RESULTS        21019  // STRING, Spread Results
#define T_SPREAD_FORMULA        21020  // STRING, Spread Formula
#define T_SPREAD_FLAGS          21021  // LONG, Spread Flags
#define T_SPREAD_NUM_LEGS       21022  // LONG, Spread Number of Legs
#define T_SPREAD_LEG_NUMBER     21023  // LONG, Spread Leg Number
#define T_SPREAD_DETAILS        21024  // STRING, Spread Details
#define T_SPREAD_NON_LEAN_CANCEL_DURATION  21025  // LONG, Spread non-lean duration
#define T_SPREAD_NON_LEAN_CANCEL_START  21026  // LONG, Spread non-lean cancel start
#define T_SPREAD_ACHIEVED       21027  // DOUBLE, Spread Achieved
#define T_SPREAD_CURRENCY       21028  // STRING, Spread Currency
#define T_SPREAD_ACHIEVED_SETUP 21029  // DOUBLE, Setup Spread Achieved
#define T_SPREAD_ACHIEVED_UNWIND  21030  // DOUBLE, Unwind Spread Achieved
#define T_SPREAD_LEG_1_DESC     21031  // STRING, Spread Leg 1 Description
#define T_SPREAD_LEG_2_DESC     21032  // STRING, Spread Leg 2 Description
#define T_SPREAD_LEG_3_DESC     21033  // STRING, Spread Leg 3 Description
#define T_SPREAD_LEG_4_DESC     21034  // STRING, Spread Leg 4 Description
#define T_SPREAD_LEG_5_DESC     21035  // STRING, Spread Leg 5 Description
#define T_SPREAD_LEG_1          21041  // LONG, Spread Leg 1
#define T_SPREAD_LEG_2          21042  // LONG, Spread Leg 2
#define T_SPREAD_LEG_3          21043  // LONG, Spread Leg 3
#define T_SPREAD_LEG_4          21044  // LONG, Spread Leg 4
#define T_SPREAD_LEG_5          21045  // LONG, Spread Leg 5
#define T_SPREAD_LEG_COUNT      21046  // LONG, Spread Leg Count
#define T_SPREAD_LEG_1_SYMBOL   21050  // STRING, Spread Leg 1 Symbol
#define T_SPREAD_LEG_2_SYMBOL   21051  // STRING, Spread Leg 2 Symbol
#define T_SPREAD_LEG_3_SYMBOL   21052  // STRING, Spread Leg 3 Symbol
#define T_SPREAD_LEG_4_SYMBOL   21053  // STRING, Spread Leg 4 Symbol
#define T_SPREAD_LEG_5_SYMBOL   21054  // STRING, Spread Leg 5 Symbol
#define T_SPREAD_LEG_1_SIDE     21055  // STRING, Spread Leg 1 Side
#define T_SPREAD_LEG_2_SIDE     21056  // STRING, Spread Leg 2 Side
#define T_SPREAD_LEG_3_SIDE     21057  // STRING, Spread Leg 3 Side
#define T_SPREAD_LEG_4_SIDE     21058  // STRING, Spread Leg 4 Side
#define T_SPREAD_LEG_5_SIDE     21059  // STRING, Spread Leg 5 Side
#define T_SPREAD_LEG_1_QUANTITY 21060  // LONG, Spread Leg 1 Quantity
#define T_SPREAD_LEG_2_QUANTITY 21061  // LONG, Spread Leg 2 Quantity
#define T_SPREAD_LEG_3_QUANTITY 21062  // LONG, Spread Leg 3 Quantity
#define T_SPREAD_LEG_4_QUANTITY 21063  // LONG, Spread Leg 4 Quantity
#define T_SPREAD_LEG_5_QUANTITY 21064  // LONG, Spread Leg 5 Quantity
#define T_SPREAD_LEG_1_VOL_TRADED  21065  // LONG, Spread Leg 1 Volume Traded
#define T_SPREAD_LEG_2_VOL_TRADED  21066  // LONG, Spread Leg 2 Volume Traded
#define T_SPREAD_LEG_3_VOL_TRADED  21067  // LONG, Spread Leg 3 Volume Traded
#define T_SPREAD_LEG_4_VOL_TRADED  21068  // LONG, Spread Leg 4 Volume Traded
#define T_SPREAD_LEG_5_VOL_TRADED  21069  // LONG, Spread Leg 5 Volume Traded
#define T_SPREAD_LEG_1_AVG_PRICE  21070  // DOUBLE, Spread Leg 1 Average Price
#define T_SPREAD_LEG_2_AVG_PRICE  21071  // DOUBLE, Spread Leg 2 Average Price
#define T_SPREAD_LEG_3_AVG_PRICE  21072  // DOUBLE, Spread Leg 3 Average Price
#define T_SPREAD_LEG_4_AVG_PRICE  21073  // DOUBLE, Spread Leg 4 Average Price
#define T_SPREAD_LEG_5_AVG_PRICE  21074  // DOUBLE, Spread Leg 5 Average Price
#define T_PAIR_SPREAD           21075  // DOUBLE, Pair Spread
#define T_PAIR_SPREAD_TYPE      21076  // LONG, Pair Spread Type
#define T_PAIR_RATIO            21077  // DOUBLE, Pair Ratio
#define T_PAIR_CASH             21078  // DOUBLE, Pair Cash Component
#define T_PAIR_IMBALANCE_LIMIT  21079  // DOUBLE, Pair Imbalance Limit
#define T_PAIR_IMBALANCE_LIMIT_TYPE  21080  // LONG, Pair Imbalance Limit Type
#define T_PAIR_DIRECTION        21081  // STRING, Pair Direction
#define T_PAIR_OPERATOR         21082  // STRING, Pair Operator
#define T_PAIR_LEG_1_BENCHMARK  21083  // DOUBLE, Pair Leg 1 Benchmark
#define T_PAIR_LEG_2_BENCHMARK  21084  // DOUBLE, Pair Leg 2 Benchmark
#define T_PAIR_TARGET           21085  // DOUBLE, Pair Target
#define T_PAIR_LEG_1_RATIO      21086  // DOUBLE, Pair Leg 1 Ratio
#define T_PAIR_LEG_2_RATIO      21087  // DOUBLE, Pair Leg 2 Ratio
#define T_PAIR_CALC_TYPE        21088  // LONG, Pair Calc Type
#define T_PAIR_LEG_1_BENCHMARK_TYPE  21089  // LONG, Pair Leg 1 Benchmark Type
#define T_PAIR_LEG_2_BENCHMARK_TYPE  21090  // LONG, Pair Leg 2 Benchmark Type
#define T_PAIR_LEG_1_BENCHMARK_VALUE  21091  // DOUBLE, Pair Leg 1 Benchmark Value
#define T_PAIR_LEG_2_BENCHMARK_VALUE  21092  // DOUBLE, Pair Leg 2 Benchmark Value
#define T_PAIR_CURRENCY_HEDGE   21093  // STRING, Pair Currency Hedge
#define T_PAIR_LEG_BENCHMARK    21094  // LONG, PAIR_LEG_BENCHMARK
#define T_PAIR_LEG_BENCHMARK_VALUE  21095  // DOUBLE, PAIR_LEG_BENCHMARK_VALUE
#define T_PAIR_CASH_CURRENCY    21096  // STRING, Pair Cash Currency
#define T_BOUGHT_QTY            21100  // DOUBLE, Qty. Bought
#define T_BOUGHT_AVG_PRC        21101  // DOUBLE, Bought Avg. Price
#define T_SOLD_QTY              21102  // DOUBLE, Qty. Sold
#define T_SOLD_AVG_PRC          21103  // DOUBLE, Sold Avg. Price
#define T_SOLD_SHORT_QTY        21104  // DOUBLE, Qty. Sold Short
#define T_SOLD_SHORT_AVG_PRC    21105  // DOUBLE, Sold Short Avg. Price
#define T_PAIR_NOTIONAL         21108  // DOUBLE, Pair Notional
#define T_PAIR_NOTIONAL_SETUP   21109  // DOUBLE, Setup Pair Notional
#define T_PAIR_NOTIONAL_UNWIND  21110  // DOUBLE, Unwind Pair Notional
#define T_SPREAD_LEG_1_BID      21111  // LPACK, Spread Leg 1 Bid
#define T_SPREAD_LEG_2_BID      21112  // LPACK, Spread Leg 2 Bid
#define T_SPREAD_LEG_3_BID      21113  // LPACK, Spread Leg 3 Bid
#define T_SPREAD_LEG_4_BID      21114  // LPACK, Spread Leg 4 Bid
#define T_SPREAD_LEG_5_BID      21115  // LPACK, Spread Leg 5 Bid
#define T_SPREAD_LEG_1_ASK      21116  // LPACK, Spread Leg 1 Ask
#define T_SPREAD_LEG_2_ASK      21117  // LPACK, Spread Leg 2 Ask
#define T_SPREAD_LEG_3_ASK      21118  // LPACK, Spread Leg 3 Ask
#define T_SPREAD_LEG_4_ASK      21119  // LPACK, Spread Leg 4 Ask
#define T_SPREAD_LEG_5_ASK      21120  // LPACK, Spread Leg 5 Ask
#define T_SPREAD_LEG_1_LAST     21121  // LPACK, Spread Leg 1 Last
#define T_SPREAD_LEG_2_LAST     21122  // LPACK, Spread Leg 2 Last
#define T_SPREAD_LEG_3_LAST     21123  // LPACK, Spread Leg 3 Last
#define T_SPREAD_LEG_4_LAST     21124  // LPACK, Spread Leg 4 Last
#define T_SPREAD_LEG_5_LAST     21125  // LPACK, Spread Leg 5 Last
#define T_SPREAD_LEG_1_BASIS    21126  // DOUBLE, Spread Leg 1 Basis
#define T_SPREAD_LEG_2_BASIS    21127  // DOUBLE, Spread Leg 2 Basis
#define T_SPREAD_LEG_3_BASIS    21128  // DOUBLE, Spread Leg 3 Basis
#define T_SPREAD_LEG_4_BASIS    21129  // DOUBLE, Spread Leg 4 Basis
#define T_SPREAD_LEG_5_BASIS    21130  // DOUBLE, Spread Leg 5 Basis
#define T_SPREAD_LEG_1_CURRENCY 21131  // STRING, Spread Leg 1 Currency
#define T_SPREAD_LEG_2_CURRENCY 21132  // STRING, Spread Leg 2 Currency
#define T_SPREAD_LEG_3_CURRENCY 21133  // STRING, Spread Leg 3 Currency
#define T_SPREAD_LEG_4_CURRENCY 21134  // STRING, Spread Leg 4 Currency
#define T_SPREAD_LEG_5_CURRENCY 21135  // STRING, Spread Leg 5 Currency
#define T_SPREAD_LEG_1_FLAG     21136  // STRING, Spread Leg 1 Flag
#define T_SPREAD_LEG_2_FLAG     21137  // STRING, Spread Leg 2 Flag
#define T_SPREAD_LEG_3_FLAG     21138  // STRING, Spread Leg 3 Flag
#define T_SPREAD_LEG_4_FLAG     21139  // STRING, Spread Leg 4 Flag
#define T_SPREAD_LEG_5_FLAG     21140  // STRING, Spread Leg 5 Flag
#define T_SPREAD_LEG_1_PCT_COMPLETE  21141  // DOUBLE, Spread Leg 1 Percent Complete
#define T_SPREAD_LEG_2_PCT_COMPLETE  21142  // DOUBLE, Spread Leg 2 Percent Complete
#define T_SPREAD_LEG_3_PCT_COMPLETE  21143  // DOUBLE, Spread Leg 3 Percent Complete
#define T_SPREAD_LEG_4_PCT_COMPLETE  21144  // DOUBLE, Spread Leg 4 Percent Complete
#define T_SPREAD_LEG_5_PCT_COMPLETE  21145  // DOUBLE, Spread Leg 5 Percent Complete
#define T_SPREAD_LEG_1_ID       21146  // STRING, Spread Leg 1 ID
#define T_SPREAD_LEG_2_ID       21147  // STRING, Spread Leg 2 ID
#define T_SPREAD_LEG_3_ID       21148  // STRING, Spread Leg 3 ID
#define T_SPREAD_LEG_4_ID       21149  // STRING, Spread Leg 4 ID
#define T_SPREAD_LEG_5_ID       21150  // STRING, Spread Leg 5 ID
#define T_SPREAD_LEG_1_VALUE_TRADED  21151  // DOUBLE, Spread Leg 1 Value Traded
#define T_SPREAD_LEG_2_VALUE_TRADED  21152  // DOUBLE, Spread Leg 2 Value Traded
#define T_SPREAD_LEG_3_VALUE_TRADED  21153  // DOUBLE, Spread Leg 3 Value Traded
#define T_SPREAD_LEG_4_VALUE_TRADED  21154  // DOUBLE, Spread Leg 4 Value Traded
#define T_SPREAD_LEG_5_VALUE_TRADED  21155  // DOUBLE, Spread Leg 5 Value Traded
#define T_SPREAD_LEG_1_BUY_QUANTITY  21156  // LONG, Spread Leg 1 Buy Quantity
#define T_SPREAD_LEG_2_BUY_QUANTITY  21157  // LONG, Spread Leg 2 Buy Quantity
#define T_SPREAD_LEG_3_BUY_QUANTITY  21158  // LONG, Spread Leg 3 Buy Quantity
#define T_SPREAD_LEG_4_BUY_QUANTITY  21159  // LONG, Spread Leg 4 Buy Quantity
#define T_SPREAD_LEG_5_BUY_QUANTITY  21160  // LONG, Spread Leg 5 Buy Quantity
#define T_SPREAD_LEG_1_SELL_QUANTITY  21161  // LONG, Spread Leg 1 Sell Quantity
#define T_SPREAD_LEG_2_SELL_QUANTITY  21162  // LONG, Spread Leg 2 Sell Quantity
#define T_SPREAD_LEG_3_SELL_QUANTITY  21163  // LONG, Spread Leg 3 Sell Quantity
#define T_SPREAD_LEG_4_SELL_QUANTITY  21164  // LONG, Spread Leg 4 Sell Quantity
#define T_SPREAD_LEG_5_SELL_QUANTITY  21165  // LONG, Spread Leg 5 Sell Quantity
#define T_SPREAD_LEG_1_BUY_VOL_TRADED  21166  // LONG, Spread Leg 1 Buy Volume Traded
#define T_SPREAD_LEG_2_BUY_VOL_TRADED  21167  // LONG, Spread Leg 2 Buy Volume Traded
#define T_SPREAD_LEG_3_BUY_VOL_TRADED  21168  // LONG, Spread Leg 3 Buy Volume Traded
#define T_SPREAD_LEG_4_BUY_VOL_TRADED  21169  // LONG, Spread Leg 4 Buy Volume Traded
#define T_SPREAD_LEG_5_BUY_VOL_TRADED  21170  // LONG, Spread Leg 5 Buy Volume Traded
#define T_SPREAD_LEG_1_SELL_VOL_TRADED  21171  // LONG, Spread Leg 1 Sell Volume Traded
#define T_SPREAD_LEG_2_SELL_VOL_TRADED  21172  // LONG, Spread Leg 2 Sell Volume Traded
#define T_SPREAD_LEG_3_SELL_VOL_TRADED  21173  // LONG, Spread Leg 3 Sell Volume Traded
#define T_SPREAD_LEG_4_SELL_VOL_TRADED  21174  // LONG, Spread Leg 4 Sell Volume Traded
#define T_SPREAD_LEG_5_SELL_VOL_TRADED  21175  // LONG, Spread Leg 5 Sell Volume Traded
#define T_SPREAD_LEG_1_BUY_VALUE_TRADED  21176  // DOUBLE, Spread Leg 1 Buy Value Traded
#define T_SPREAD_LEG_2_BUY_VALUE_TRADED  21177  // DOUBLE, Spread Leg 2 Buy Value Traded
#define T_SPREAD_LEG_3_BUY_VALUE_TRADED  21178  // DOUBLE, Spread Leg 3 Buy Value Traded
#define T_SPREAD_LEG_4_BUY_VALUE_TRADED  21179  // DOUBLE, Spread Leg 4 Buy Value Traded
#define T_SPREAD_LEG_5_BUY_VALUE_TRADED  21180  // DOUBLE, Spread Leg 5 Buy Value Traded
#define T_SPREAD_LEG_1_SELL_VALUE_TRADED  21181  // DOUBLE, Spread Leg 1 Sell Value Traded
#define T_SPREAD_LEG_2_SELL_VALUE_TRADED  21182  // DOUBLE, Spread Leg 2 Sell Value Traded
#define T_SPREAD_LEG_3_SELL_VALUE_TRADED  21183  // DOUBLE, Spread Leg 3 Sell Value Traded
#define T_SPREAD_LEG_4_SELL_VALUE_TRADED  21184  // DOUBLE, Spread Leg 4 Sell Value Traded
#define T_SPREAD_LEG_5_SELL_VALUE_TRADED  21185  // DOUBLE, Spread Leg 5 Sell Value Traded
#define T_SPREAD_LEG_1_REMAINING  21186  // DOUBLE, Spread Leg 1 Remaining
#define T_SPREAD_LEG_2_REMAINING  21187  // DOUBLE, Spread Leg 2 Remaining
#define T_SPREAD_LEG_3_REMAINING  21188  // DOUBLE, Spread Leg 3 Remaining
#define T_SPREAD_LEG_4_REMAINING  21189  // DOUBLE, Spread Leg 4 Remaining
#define T_SPREAD_LEG_5_REMAINING  21190  // DOUBLE, Spread Leg 5 Remaining
#define T_SPREAD_LEG_1_CLOSE    21191  // LPACK, Spread Leg 1 Close
#define T_SPREAD_LEG_2_CLOSE    21192  // LPACK, Spread Leg 2 Close
#define T_SPREAD_LEG_3_CLOSE    21193  // LPACK, Spread Leg 3 Close
#define T_SPREAD_LEG_4_CLOSE    21194  // LPACK, Spread Leg 4 Close
#define T_SPREAD_LEG_5_CLOSE    21195  // LPACK, Spread Leg 5 Close
#define T_MOVED_VLTY            21200  // STRING, Moved vlty
#define T_MOVED_PROFIT          21300  // STRING, Moved profit
#define T_MOVED_UNIFIED_PROFIT  21400  // STRING, Moved unified profit
#define T_FIX_TRADER_ID         22000  // STRING, FIX Trader ID
#define T_FIX_SENDER_SUB_ID     22001  // STRING, FIX Sender SubID
#define T_FIX_TARGET_SUB_ID     22002  // STRING, FIX Target SubID
#define T_FIX_SECOND_CL_ORD_ID  22003  // STRING, FIX 2nd Client Order ID
#define T_FIX_DATA              22004  // STRING, FIX Data
#define T_TRANSLATOR_ID         22005  // LONG, Translator ID used by Gateway
#define T_GATEWAY_ADVISE_FILTER 22006  // LONG, Gateway advise filter
#define T_TIMS_SYMBOL           22100  // STRING, TIMS Symbol
#define T_TIMS_THEO_REFDATE     22101  // STRING, TIMS Ref Date
#define T_TIMS_THEO_YEAR        22102  // INT, TIMS Theo Year
#define T_TIMS_THEO_MONTH       22103  // INT, TIMS Theo Month
#define T_TIMS_THEO_STRIKE_PRC  22104  // DOUBLE, TIMS Theo Strike Price
#define T_TIMS_THEO_PUTCALLIND  22105  // STRING, TIMS Theo Put/Call Ind.
#define T_TIMS_THEO_PRODUCT_CODE  22106  // STRING, TIMS Theo Product Code
#define T_TIMS_THEO_MARK_PRICE  22107  // DOUBLE, TIMS Theo Mark Price
#define T_TIMS_THEO_VAL_UP1     22108  // DOUBLE, TIMS Theo Risk Up 1
#define T_TIMS_THEO_VAL_UP2     22109  // DOUBLE, TIMS Theo Risk Up 2
#define T_TIMS_THEO_VAL_UP3     22110  // DOUBLE, TIMS Theo Risk Up 3
#define T_TIMS_THEO_VAL_UP4     22111  // DOUBLE, TIMS Theo Risk Up 4
#define T_TIMS_THEO_VAL_UP5     22112  // DOUBLE, TIMS Theo Risk Up 5
#define T_TIMS_THEO_VAL_DOWN1   22113  // DOUBLE, TIMS Theo Risk Down 1
#define T_TIMS_THEO_VAL_DOWN2   22114  // DOUBLE, TIMS Theo Risk Down 2
#define T_TIMS_THEO_VAL_DOWN3   22115  // DOUBLE, TIMS Theo Risk Down 3
#define T_TIMS_THEO_VAL_DOWN4   22116  // DOUBLE, TIMS Theo Risk Down 4
#define T_TIMS_THEO_VAL_DOWN5   22117  // DOUBLE, TIMS Theo Risk Down 5
#define T_TIMS_THEO_SHORT_ADJ   22118  // DOUBLE, TIMS Theo Short Adj
#define T_TIMS_THEO_VOLATILITY  22119  // DOUBLE, TIMS Theo Vlty
#define T_TIMS_THEO_OPEN_INTEREST  22120  // LONG, TIMS Theo Open Interest
#define T_TIMS_THEO_CLEARED_VOLUME  22121  // LONG, TIMS Theo Cleared Volume
#define T_TIMS_CLASS_GROUP      22130  // STRING, TIMS Class Group
#define T_TIMS_CLASS_PRODUCT_GROUP  22131  // STRING, TIMS Class Product Group
#define T_TIMS_CLASS_TYPE       22132  // STRING, TIMS Class Type
#define T_TIMS_CLASS_PRODUCT_TYPE  22133  // STRING, TIMS Class Product Type
#define T_TIMS_CLASS_OFFSET     22134  // LONG, TIMS Class Offset
#define T_TIMS_CLASS_SPOT_SPREAD_RATE  22135  // DOUBLE, TIMS Class Spot Spread Rate
#define T_TIMS_CLASS_NON_SPOT_SPREAD_RATE  22136  // DOUBLE, TIMS Class Non-Spot Spread Rate
#define T_TIMS_CLASS_DELIVERY_RATE  22137  // DOUBLE, TIMS Class Delivery Rate
#define T_TIMS_CLASS_MULTIPLIER 22138  // DOUBLE, TIMS Class Multiplier
#define T_TIMS_CLASS_OPTION_TYPE  22139  // STRING, TIMS Class Option Type
#define T_TIMS_CLASS_MKT_VALUE  22140  // DOUBLE, TIMS Class Mkt Value
#define T_TIMS_CLASS_MARGIN_INTERVAL  22141  // DOUBLE, TIMS Class Margin Interval
#define T_TIMS_CLASS_CURRENCY   22142  // STRING, TIMS Class Currency
#define T_TIMS_CLASS_EXCH_RATE  22143  // DOUBLE, TIMS Class Exch Rate
#define T_TIMS_CLASS_CURRENCY_HAIRCUT  22144  // LONG, TIMS Class Crncy Haircut
#define T_TIMS_CLASS_MIN_MARGIN 22145  // DOUBLE, TIMS Class Min Margin
#define T_TIMS_CLASS_INTEREST_RATE  22146  // DOUBLE, TIMS Class Min Margin
#define T_TIMS_CLASS_DIVDATE    22147  // STRING, TIMS Class Div Date
#define T_TIMS_CLASS_DIVIDEND   22148  // DOUBLE, TIMS Class Dividend
#define T_TIMS_FUT_REF_DATE     22160  // STRING, TIMS Future Ref Date
#define T_TIMS_FUT_PRODUCT_TYPE 22161  // LONG, TIMS Future Product Type
#define T_TIMS_FUT_PRODUCT_CODE 22162  // STRING, TIMS Future Product Code
#define T_TIMS_FUT_EXPIR_DATE   22163  // STRING, TIMS Future Expiration
#define T_TIMS_FUT_STRIKE_PRC   22164  // DOUBLE, TIMS Future Strike Price
#define T_TIMS_FUT_PUTCALLIND   22165  // STRING, TIMS Future Put/Call Ind.
#define T_TIMS_FUT_MARK_PRICE   22166  // DOUBLE, TIMS Future Mark Price
#define T_TIMS_FUT_OPEN_INTEREST  22167  // LONG, TIMS Future Open Interest
#define T_TIMS_FUT_CLEARED_VOLUME  22168  // LONG, TIMS Future Cleared Volume
#define T_UNDER_EXPIR_DATE      22200  // DATE, Underliers expiration
#define T_POSITION_BLOB         22201  // BLOB, Embedded blob records
#define T_ORDER_BLOB            22202  // BLOB, Embedded blob orders
#define T_MGN_CALC_TRACE        22203  // LONG, enable margin record tracing
#define T_RISKSRV_IMR           22204  // DOUBLE, Risk Server Initial
#define T_RISKSRV_MMR           22205  // DOUBLE, Risk Server Maintenance
#define T_ORIG_VIRTUAL_PRICE_TYPE  22500  // INT, Orig. Virtual Prc Type
#define T_OPT_CALC_MODEL        22900  // INT, NULL
#define T_DIV_DATE_1            22901  // DATE, NULL
#define T_DIV_DATE_2            22902  // DATE, NULL
#define T_DIV_DATE_3            22903  // DATE, NULL
#define T_DIV_DATE_4            22904  // DATE, NULL
#define T_DIV_DATE_5            22905  // DATE, NULL
#define T_DIV_DATE_6            22906  // DATE, NULL
#define T_DIV_AMOUNT_1          22907  // DOUBLE, NULL
#define T_DIV_AMOUNT_2          22908  // DOUBLE, NULL
#define T_DIV_AMOUNT_3          22909  // DOUBLE, NULL
#define T_DIV_AMOUNT_4          22910  // DOUBLE, NULL
#define T_DIV_AMOUNT_5          22911  // DOUBLE, NULL
#define T_DIV_AMOUNT_6          22912  // DOUBLE, NULL
#define T_INPUT_PRICE           22913  // DOUBLE, NULL
#define T_BADGE_ID              22914  // STRING, Badge ID
#define T_ROUTE_PROPERTY_NAME   22915  // STRING, Route Property Name
#define T_ROUTE_PROPERTY_VALUE  22916  // STRING, Route Property Value
#define T_ROUTE_IS_EMULATED     22917  // LONG, Route IsEmulated Flag
#define T_ROUTE_IS_HIDDEN       22918  // LONG, Route IsHidden Flag
#define T_ROUTE_OPEN_TIME       22919  // LONG, Route Open Time
#define T_ROUTE_CLOSE_TIME      22920  // LONG, Route Close Time
#define T_MIN_ORDER_RECYCLE_TIME  22921  // LONG, MinOrderRecycleTime
#define T_ALL_SYMBOL_DATA       23000  // BLOB, All Symbol Data
#define T_UPDATE_FLAGS          23005  // BLOB, Symbol field flags
#define T_SYMBOL_BITFIELD       23010  // LONG, Symbol status bits
#define T_LVAL_PRICE            23011  // LONG, Lval of a price
#define T_WBASE_PRICE           23012  // LONG, Base of price
#define T_ACCOUNT_CBP           23013  // DOUBLE, Account CBP
#define T_EXTRA_CBP             23014  // DOUBLE, CBP Extra
#define T_USED_CBP              23015  // DOUBLE, Mgn Maint
#define T_MGN_LONG_INIT         23016  // DOUBLE, Init Mgn % L
#define T_MGN_LONG_MAINT        23017  // DOUBLE, Maint Mgn % L
#define T_MGN_SHORT_INIT        23018  // DOUBLE, Init Mgn % S
#define T_MGN_SHORT_MAINT       23019  // DOUBLE, Maint Mgn % S
#define T_SOLICITED             23020  // STRING, Solicited
#define T_ACCT_DESC             23021  // STRING, Acct Desc
#define T_REP_NAME              23022  // STRING, Rep's Name
#define T_COMMISSION            23023  // DOUBLE, Commission
#define T_REP_NO                23024  // LONG, Rep's #
#define T_STRING_1              23025  // STRING, String 1
#define T_STRING_2              23026  // STRING, String 2
#define T_STRING_3              23027  // STRING, String 3
#define T_STRING_4              23028  // STRING, String 4
#define T_STRING_5              23029  // STRING, String 5
#define T_STRING_6              23030  // STRING, String 6
#define T_STRING_7              23031  // STRING, String 7
#define T_STRING_8              23032  // STRING, String 8
#define T_STRING_9              23033  // STRING, String 9
#define T_STRING_10             23034  // STRING, String 10
#define T_SEC_TYPE              23035  // STRING, Sec Type
#define T_PENDING_MARGIN        23036  // DOUBLE, Mgn Pending
#define T_TOTAL_USED_CBP        23037  // DOUBLE, Total Used CBP
#define T_ENFORCE_5MIN          23038  // INT, Enforce 5 min Rule
#define T_ENFORCE_MARGIN        23039  // INT, Enforce Margin
#define T_ENFORCE_SHORT         23040  // INT, Enforce Short Sales
#define T_CBP_REMAINING         23041  // DOUBLE, CBP Remaining
#define T_USER_BEST_BID         23042  // LPACK, User Bid
#define T_USER_BEST_ASK         23043  // LPACK, User Ask
#define T_USER_BEST_BID_SIZE    23044  // LONG, User Bid Size
#define T_USER_BEST_ASK_SIZE    23045  // LONG, User Ask Size
#define T_USER_BEST_BID_ORDER_ID  23046  // STRING, User Bid Order ID
#define T_USER_BEST_ASK_ORDER_ID  23047  // STRING, User Ask Order ID
#define T_OPTION_COVERED        23048  // LONG, Option Covered
#define T_TO_OPEN_POS           23049  // LONG, Open/Close Pos
#define T_FOR_FIRM              23050  // LONG, Firm/Customer
#define T_IS_SOLICITED          23051  // LONG, Solicited
#define T_STOP_PRICE            23052  // LPACK, Stop Price
#define T_FIRM_NAME             23053  // STRING, Firm Name
#define T_TRD_TIME              23054  // TIME, Time of trade
#define T_SECURITY_TYPE         23055  // STRING, Order Properties
#define T_ALLOW_UNMARKED_SHORT  23056  // INT, Allow Unmarked Short
#define T_PENDING_SELL_POS      23057  // DOUBLE, Pending Sells
#define T_AVERAGE_PRICE         23058  // DOUBLE, Average price
#define T_MMR                   23059  // DOUBLE, MMR
#define T_MARKETVALUE_0         23060  // DOUBLE, Morning MV
#define T_MMR_0                 23061  // DOUBLE, Morning MMR
#define T_EXCESS_EQ_0           23062  // DOUBLE, Morning Excess Eq.
#define T_MIN_BALANCE           23063  // DOUBLE, MinBalance
#define T_POSITION              23064  // DOUBLE, Position
#define T_ACCT_TYPE             23065  // LONG, Acct Type
#define T_EXCESS_EQ             23066  // DOUBLE, Excess Equity
#define T_PENDING_BUY_POS       23067  // DOUBLE, Pending Buys
#define T_LAST_FILL_PRICE       23068  // LPACK, Last Fill Price
#define T_ORDER_DETAILS         23069  // STRING, Order Details
#define T_MAX_ORDER_SIZE        23070  // LONG, Max Order Size
#define T_USER_PERM_CUST_FLAGS  23071  // LONG, Customer Attributes
#define T_CASH_BALANCE_ADJ      23072  // DOUBLE, Cash balance adj
#define T_MMR_0_ADJ             23073  // DOUBLE, Overnight MMR Release
#define T_EXCESS_EQ_ADJ         23074  // DOUBLE, Excess Equity Adj
#define T_SCALPED_LOSS          23075  // DOUBLE, Scalped Loss
#define T_MARGIN_PRICE_LONG     23076  // DOUBLE, Mgn Prc Long
#define T_MARGIN_PRICE_SHORT    23077  // DOUBLE, Mgn Prc Short
#define T_MARGIN_PRICE_LONG0    23078  // DOUBLE, Mgn Prc Long0
#define T_MARGIN_PRICE_SHORT0   23079  // DOUBLE, Mgn Prc Short0
#define T_RAW_PRICE_LONG0       23080  // DOUBLE, Orig Prc Long0
#define T_RAW_PRICE_SHORT0      23081  // DOUBLE, Orig Prc Short0
#define T_RAW_NET_AVG_PRICE     23082  // DOUBLE, Raw Net Price
#define T_RAW_PL_TOTAL          23083  // DOUBLE, Raw Total P&L
#define T_STOP_DELTA            23084  // LPACK, Stop Delta
#define T_MARGIN_SUBRULE_TYPE   23085  // LONG, Margin Subrule Type
#define T_MARGIN_VALUE_TYPE     23086  // LONG, Margin Value Type
#define T_MARGIN_VALUE          23087  // DOUBLE, Margin Value
#define T_MARGIN_RELEASE_PCT    23088  // DOUBLE, Margin Release %
#define T_NETPOS_ORIGINAL_OVERNIGHT  23089  // DOUBLE, Orig. Position
#define T_HAS_CLOSED_OVERNIGHT_POS  23090  // INT, Has closed overnight pos
#define T_SHORTEST_INTRADAY_POSITION  23091  // DOUBLE, Lowest Position
#define T_LONGEST_INTRADAY_POSITION  23092  // DOUBLE, Highest Position
#define T_ACCOUNT_EQUITY        23093  // DOUBLE, Account Equity
#define T_ACCOUNT_EQUITY_DELTA  23094  // DOUBLE, Change in Equity
#define T_FUTURE_NET_MMR        23095  // DOUBLE, Futures MMR
#define T_FUTURE_NET_IMR        23096  // DOUBLE, Futures Init. Req.
#define T_FUTURE_MAINT_EXCESS   23097  // DOUBLE, Futures Maint. Excess
#define T_FUTURE_INITIAL_EXCESS 23098  // DOUBLE, Futures Init. Excess
#define T_DISCRETION_QTY_THRESHOLD  23099  // LONG, Disc. Qty Threshold
#define T_RESERVE_SHOWSIZE      23100  // LONG, Size to Show
#define T_RESERVE_SHOW_DELTA    23101  // LONG, Reserve Delta
#define T_RESERVE_LOWER_LIMIT   23102  // LPACK, Lower Limit
#define T_RESERVE_UPPER_LIMIT   23103  // LPACK, Upper Limit
#define T_REPLACE_ADJ_VOLUME    23104  // LONG, Adjust Volume?
#define T_REPLACE_CANCEL_ID     23105  // STRING, Cancel ID
#define T_REPLACE_NEW_ORDER     23106  // STRING, Replacement Order Blob
#define T_ORIGINAL_VOLUME       23107  // LONG, Orig Vol
#define T_WEIGHT                23108  // DOUBLE, Weight
#define T_WEIGHT_BID            23109  // DOUBLE, Weighted Bid
#define T_WEIGHT_ASK            23110  // DOUBLE, Weighted Ask
#define T_WEIGHT_PRICE          23111  // DOUBLE, Weighted Price
#define T_WEIGHT_OBSOLETE       23112  // LONG, Unused
#define T_WEIGHT_NETCHG         23113  // DOUBLE, Weighted Net Change
#define T_WEIGHT_HSTCLOSE       23114  // DOUBLE, Weighted Close
#define T_WEIGHT_POSDIVWEIGHT   23115  // DOUBLE, Integral Baskets
#define T_WEIGHT_POSMODWEIGHT   23116  // DOUBLE, Basket Excess
#define T_WEIGHT_BASKET_POSITION  23117  // DOUBLE, Basket Position
#define T_BASKET_TARGET         23118  // DOUBLE, Basket Target
#define T_BASKET_TARGET_RESIDUAL  23119  // DOUBLE, Basket Residual
#define T_EXECUTE_AMOUNT        23120  // LONG, Execute Amount
#define T_EXECUTE_COST          23121  // DOUBLE, Execute Cost
#define T_EXECUTE_PRICE_TYPE    23122  // LONG, Execute Price Type
#define T_EXECUTE_SELLSHORT     23123  // LONG, Execute Short
#define T_EXECUTE_DETAILS       23124  // STRING, Execute Details
#define T_EXECUTE_FREEZE        23125  // LONG, Freeze
#define T_MARKED_POSITION       23126  // DOUBLE, Marked Position
#define T_EXECUTE_PRICE         23127  // LPACK, Execute Price
#define T_BASKET_ORDERS         23128  // STRING, Basket Orders
#define T_BASKET_ID             23129  // STRING, Internal Basket ID
#define T_ESTIMATED_ORDER_COST  23130  // DOUBLE, Estimated Order Cost
#define T_MMR_0_NON_DAYTRADE_ADJ  23131  // DOUBLE, Overnight MMR Release (Non DT)
#define T_TOTAL_CROSSES_PLACED  23133  // DOUBLE, Total Crosses Attempted
#define T_NET_CROSS_IMBALANCE   23134  // DOUBLE, Net Cross Imbalance
#define T_BUY_COUNT_TODAY       23135  // LONG, Buys Today
#define T_SELL_COUNT_TODAY      23136  // LONG, Sells Today
#define T_TOTAL_SHARES_CROSSED  23137  // DOUBLE, Total Shares Crossed
#define T_SHARES_CROSSED_BOUGHT 23138  // DOUBLE, Shares Crossed/Bought
#define T_SHARES_CROSSED_SOLD   23139  // DOUBLE, Shares Crossed/Sold
#define T_BUY_FILLS_TODAY       23140  // DOUBLE, Shares Bought
#define T_SELL_FILLS_TODAY      23141  // DOUBLE, Shares Sold Total
#define T_BUY_VALUE_TODAY       23142  // DOUBLE, Cost of Buys
#define T_SELL_VALUE_TODAY      23143  // DOUBLE, Cost of All Sells
#define T_AVG_BUY_PRICE         23144  // DOUBLE, Avg Buy Price
#define T_AVG_SELL_PRICE        23145  // DOUBLE, Avg Sell Price
#define T_BUY_SELL_DIFF         23146  // DOUBLE, Buy/Sell Diff
#define T_SELL_FILLS_TODAY_SHORT  23147  // DOUBLE, Shares Sold Short
#define T_SELL_FILLS_TODAY_NONSHORT  23148  // DOUBLE, Shares Sold (non-Short)
#define T_SELL_VALUE_TODAY_SHORT  23149  // DOUBLE, Cost of Short Sells
#define T_SELL_VALUE_TODAY_NONSHORT  23150  // DOUBLE, Cost of Sells (non-Short)
#define T_AVG_SELL_PRICE_SHORT  23151  // DOUBLE, Avg Sell Short Price
#define T_AVG_SELL_PRICE_NONSHORT  23152  // DOUBLE, Avg Sell Price (non-Short)
#define T_FILL_ID               23153  // STRING, Fill ID assigned by TASK
#define T_TRADE_REPORT_ID       23154  // STRING, Trade Report ID
#define T_TICKET_ID             23155  // STRING, Ticket ID
#define T_SUBORDER_ID           23156  // STRING, Suborder ID
#define T_SHARES_ALLOCATED      23157  // LONG, Shares Allocated
#define T_LINKED_ORDER_ID       23158  // STRING, ID of Linked Order
#define T_LINKED_ORDER_RELATIONSHIP  23159  // LONG, Linked Order Relationship
#define T_LINKED_ORDER_CANCELLATION  23160  // LONG, Linked Order Cancellation
#define T_LINKED_ORDER_TYPE     23161  // LONG, Linked Order Type
#define T_ORDER_ALERT_PRESENT   23165  // LONG, Order Alert Indicator
#define T_EXECUTING_BROKER      23166  // STRING, Exec Broker
#define T_ALLOCATED_VALUE       23167  // DOUBLE, Allocated Value
#define T_EXECUTE_ROUTE         23168  // STRING, Execute Route
#define T_EXECUTE_STRATEGY      23169  // STRING, Execute Strategy
#define T_MAKE_MKT_BID_OFFSET   23170  // DOUBLE, Bid Offset
#define T_MAKE_MKT_OFFER_OFFSET 23171  // DOUBLE, Offer Offset
#define T_MAKE_MKT_BID_YLD_OFFSET  23172  // DOUBLE, Bid Yld Offset
#define T_MAKE_MKT_OFFER_YLD_OFFSET  23173  // DOUBLE, Offer Yld Offset
#define T_MAKE_MKT_REF_SYM      23174  // STRING, Reference Symbol
#define T_MARGIN_SOURCE         23180  // LONG, Margin Source
#define T_MARGIN_RULESET_ID     23181  // LONG, Margin Ruleset ID
#define T_MARGIN_RULESET_NAME   23182  // STRING, Margin Ruleset Name
#define T_MARGIN_RULE_RTH_DIVISOR  23183  // DOUBLE, Margin Rule RTH Divisor
#define T_ORDER_COUNT_TODAY     23189  // LONG, Number of Orders
#define T_SHORT_LOCATE_ID       23190  // STRING, Short Locate ID
#define T_ROUTED_TIME           23191  // DOUBLE, Routed Time
#define T_PENDING_ACCT_MARGIN   23192  // DOUBLE, Pending Acct Margin
#define T_TICKET_MARKUP         23193  // LPACK, Staged Order Ticket Markup
#define T_TICKET_STEPOUT_AMT    23194  // DOUBLE, Ticket Stepout Amt
#define T_TICKET_STEPOUT_AMT_TYPE  23195  // INT, Ticket Stepout Amt Type
#define T_TICKET_STEPOUT_VOL_TRADED  23196  // LONG, Ticket Stepout Vol Traded
#define T_TICKET_STEPOUT_AVG_PRICE  23197  // DOUBLE, Ticket Stepout Avg Price
#define T_WORKED_ORDER_STATUS   23198  // LONG, Worked Order Status
#define T_ROUTING_BBCD          23199  // STRING, Sub-Account
#define T_COND_SYMBOL           23200  // STRING, Cond Symbol
#define T_COND_PRICE_FIELD      23201  // LONG, Cond Price Field
#define T_COND_PRICE_RELATION   23202  // LONG, Cond Price Relation
#define T_COND_TRIGGER_VALUE    23203  // DOUBLE, Cond Trigger Value
#define T_COND_ORDER            23204  // STRING, Cond Order
#define T_CHANGE_NO             23205  // LONG, Change Number
#define T_TRADER_CAPACITY       23206  // STRING, Trader capacity
#define T_ARCA_BEST_BID1        23207  // LPACK, Arca Best Bid
#define T_ARCA_BEST_BID1_SIZE   23208  // LONG, Arca Best Bid Size
#define T_ARCA_BEST_ASK1        23209  // LPACK, Arca Best Offer
#define T_ARCA_BEST_ASK1_SIZE   23210  // LONG, Arca Best Offer Size
#define T_DEST_LOR              23211  // LONG, Dest LOR
#define T_COND_USE_PRICE        23212  // INT, Cond Use Price
#define T_COND_USE_ACTIVATE_TIME  23213  // INT, Cond Use Time
#define T_COND_ACTIVATE_TIME    23214  // TIME, Cond Activation Time
#define T_COND_PRICE_TIME_OP    23215  // LONG, Cond Operation
#define T_COND_USE_EXPIRE_TIME  23216  // INT, Cond Use Expire Time
#define T_COND_EXPIRE_TIME      23217  // TIME, Cond Expiration Time
#define T_COMPRESSION_ELIGIBILITY  23218  // LONG, Comp Eligibility
#define T_DOMAIN_NAME_FOR_GATEWAY  23219  // STRING, DomainName for Gateway
#define T_ETP_ID                23220  // STRING, ETP Id
#define T_ETP_CONTRA            23221  // STRING, ETP Contra
#define T_AUTHORIZED_TRADER_ID  23222  // STRING, Authorized Trader ID
#define T_REMAINING_VOLUME      23223  // LONG, Remaining volume
#define T_USER_NAME_FOR_GATEWAY 23224  // STRING, UserName for Gateway
#define T_TIME_IN_FORCE_DESC    23225  // STRING, Time In Force
#define T_LVAL_ARCA_BID_PRICE   23226  // LONG, LVAL of Arca Bid Price
#define T_WBASE_ARCA_BID_PRICE  23227  // LONG, WBASE of Arca Bid Price
#define T_LVAL_ARCA_OFFER_PRICE 23228  // LONG, LVAL of Arca Offer Price
#define T_WBASE_ARCA_OFFER_PRICE  23229  // LONG, WBASE of Arca Offer Price
#define T_LVAL_NATIONAL_BID_PRICE  23230  // LONG, LVAL of Nat'l Bid Price
#define T_WBASE_NATIONAL_BID_PRICE  23231  // LONG, WBASE of Nat'l Bid Price
#define T_LVAL_NATIONAL_OFFER_PRICE  23232  // LONG, LVAL of Nat'l Offer Price
#define T_WBASE_NATIONAL_OFFER_PRICE  23233  // LONG, WBASE of Nat'l Offer Price
#define T_COND_USE_ORDER_TRIGGER  23234  // INT, Cond Use Order Trigger
#define T_COND_ORDER_TRIGGER    23235  // STRING, Cond Trigger Order ID
#define T_ROUTE_PROPERTY        23236  // LONG, Route Property
#define T_PEG_LIMIT             23237  // LPACK, Peg Limit
#define T_DISCRETION_OFFSET     23238  // LPACK, Discretion Offset
#define T_GATEWAY_MACHINE       23239  // STRING, Gateway Machine
#define T_SUPER_MONTAGE_FLAGS   23240  // LONG, Super Montage flags
#define T_EXECUTION_ALGORITHM   23241  // LONG, Execution Algorithm
#define T_AS_OF_DATE            23242  // DATE, As of Date
#define T_AS_OF_TIME            23243  // TIME, As of Time
#define T_VOLUME_CROSSED        23244  // LONG, Volume Crossed
#define T_PRICE_MARKUP          23245  // DOUBLE, Price Markup
#define T_ECN_ROUTING_FLAGS     23246  // LONG, ECN Routing Flags
#define T_EXCHANGE_EVENT        23247  // LONG, Exchange Event
#define T_DATE_INDEX            23248  // LONG, Days since 1996
#define T_BOOK_ID               23249  // LONG, Book ID
#define T_GW_BOOK_SEQ_NO        23250  // LONG, Gateway Bk Seq No
#define T_EXIT_VEHICLE_SUBROUTE 23251  // STRING, Sub Route
#define T_OMS_CLIENT_TYPE       23252  // LONG, OMS Client Type
#define T_MATCHER_BEST_BID      23253  // DOUBLE, Matcher Best Bid
#define T_MATCHER_BEST_ASK      23254  // DOUBLE, Matcher Best Ask
#define T_MATCHER_BEST_BID_SIZE 23255  // LONG, Matcher Best Bid Size
#define T_MATCHER_BEST_ASK_SIZE 23256  // LONG, Matcher Best Ask Size
#define T_MATCHER_BEST_BID_EXID 23257  // STRING, Matcher Best Bid EXID
#define T_MATCHER_BEST_ASK_EXID 23258  // STRING, Matcher Best Ask EXID
#define T_AUTO_GIVEUP           23259  // INT, Automatic Giveup
#define T_MATCHER_LVAL_ARCA_BEST_BID  23260  // LONG, Matcher Arca Best Bid LVAL
#define T_MATCHER_WBASE_ARCA_BEST_BID  23261  // INT, Matcher Arca Best Bid WBASE
#define T_MATCHER_LVAL_ARCA_BEST_ASK  23262  // LONG, Matcher Arca Best Ask LVAL
#define T_MATCHER_WBASE_ARCA_BEST_ASK  23263  // INT, Matcher Arca Best Ask WBASE
#define T_MATCHER_ARCA_BEST_BID_SIZE  23264  // LONG, Matcher Arca Best Bid Size
#define T_MATCHER_ARCA_BEST_ASK_SIZE  23265  // LONG, Matcher Arca Best Ask Size
#define T_MATCHER_BEST_AWAY_BID 23266  // DOUBLE, Matcher Best Away Bid
#define T_MATCHER_BEST_AWAY_ASK 23267  // DOUBLE, Matcher Best Away Ask
#define T_MATCHER_BEST_AWAY_BID_SIZE  23268  // LONG, Matcher Best Away Bid Size
#define T_MATCHER_BEST_AWAY_ASK_SIZE  23269  // LONG, Matcher Best Away Ask Size
#define T_MATCHER_BEST_AWAY_BID_MKTS  23270  // STRING, Matcher Best Away Bid Mkts
#define T_MATCHER_BEST_AWAY_ASK_MKTS  23271  // STRING, Matcher Best Away Ask Mkts
#define T_MATCHER_LVAL_BEST_BID 23272  // LONG, Matcher Best Bid LVAL
#define T_MATCHER_WBASE_BEST_BID  23273  // INT, Matcher Best Bid WBASE
#define T_MATCHER_LVAL_BEST_ASK 23274  // LONG, Matcher Best Ask LVAL
#define T_MATCHER_WBASE_BEST_ASK  23275  // INT, Matcher Best Ask WBASE
#define T_LIQUIDITY_INDICATOR   23286  // LONG, Liquidity Indicator
#define T_SELLING_METHOD        23287  // LONG, Selling Method
#define T_VSP_DATE              23288  // STRING, VSP Date
#define T_ALLOC_TICKET_ID       23289  // STRING, Alloc Ticket ID
#define T_NUM_FILLS_BILLING_CYCLE  23290  // LONG, No. Fills in Billing Cycle
#define T_GROSS_TRADED_AMT_BILLING_CYCLE  23291  // LONG, Gross Traded in Billing Cycle
#define T_COMMISSION_CODE       23292  // STRING, Broker Code
#define T_BLOTTER_CODE          23293  // STRING, Blotter Code
#define T_ALLOC_BBCD            23294  // STRING, Destination acct for Allocation
#define T_SEC_FEE               23295  // DOUBLE, SEC Fee
#define T_ECN_FEE               23296  // DOUBLE, ECN Fee
#define T_BROKERAGE_FEE         23297  // DOUBLE, Brokerage Fee
#define T_ORDER_ERROR_CODE      23298  // LONG, Error Code
#define T_RSP_NAME              23299  // STRING, RSP Name
#define T_NYFIX_SPRD_LIMIT_MIN  23300  // DOUBLE, Min Spread
#define T_NYFIX_SPRD_LIMIT_MAX  23301  // DOUBLE, Max Spread
#define T_NYFIX_MARKET_CODE     23302  // STRING, Market Code
#define T_NYFIX_MIN_1ST_EXEC_SIZE  23303  // LONG, Min First Execution Size
#define T_NYFIX_MIN_EXEC_SIZE   23304  // LONG, Min Execution Size
#define T_NYFIX_MAX_EXEC_PER_TICK  23305  // LONG, Max Exec Per Tick
#define T_NYFIX_PCT_OF_DISP_SIZE  23306  // DOUBLE, % of Display Size
#define T_NYFIX_MAX_EXEC_SIZE   23307  // LONG, Max Exec Size
#define T_ACT_FEE               23308  // DOUBLE, ACT Fee
#define T_COMMISSION_RATE       23309  // DOUBLE, Commission Rate
#define T_COMMISSION_RATE_TYPE  23310  // INT, Commission Rate Type
#define T_ALLOC_PRETRADE_ALLOCATION_PLAN  23311  // BLOB, Pretrade Allocation Instructions
#define T_ALLOC_PERCENTAGE      23312  // LONG, Allocation Percentage
#define T_ALLOC_MIN_LOT_SIZE    23313  // LONG, Allocation Min Lot Size
#define T_ALLOC_ON_COMPLETION   23314  // LONG, Allocate On Completion
#define T_GATEWAY_MACHINE_ID    23315  // LONG, Gateway Machine ID
#define T_SRV_PENDING_MARGIN    23316  // DOUBLE, Mgn Pending (server)
#define T_EXTERNAL_ORDER_KEY    23317  // STRING, External order key
#define T_HANDLE_INSTR          23318  // LONG, Handling Instructions
#define T_STRATEGY_DETAILS      23319  // STRING, Strategy Details
#define T_STRAT_TARGET          23320  // STRING, Strategy Target
#define T_STRAT_ID              23321  // STRING, Strategy ID
#define T_STRAT_SLICE           23322  // LONG, Strategy Slice Size
#define T_STRAT_AGGRESSION      23323  // LONG, Strategy Aggression
#define T_STRAT_MOO             23324  // LONG, Strategy MOO
#define T_STRAT_MOC             23325  // LONG, Strategy MOC
#define T_STRAT_BPS_STOP        23326  // LPACK, Strategy Basis Pt. Limit
#define T_STRAT_MIN_VOL_PCT     23327  // LONG, Min Vol Pct.
#define T_STRAT_MAX_VOL_PCT     23328  // LONG, Max Vol Pct.
#define T_STRAT_PCT_PER_SLICE   23329  // LONG, Pct Per Slice
#define T_STRAT_PING            23330  // LONG, Ping Interval
#define T_STRAT_PREMIUM         23331  // DOUBLE, Premium
#define T_STRAT_RATIO           23332  // DOUBLE, Ratio
#define T_STRAT_CASH            23333  // DOUBLE, Cash
#define T_STRAT_EXTRA           23334  // STRING, Extra Strategy Field
#define T_STRAT_NAME            23335  // STRING, Strategy Name
#define T_STRAT_TIME_TYPE       23336  // STRING, Strategy Time Type
#define T_STRAT_NUM_SLICES      23337  // LONG, Strategy Num Slices
#define T_STRAT_OTHER_PRICE     23338  // LPACK, Strategy Other Price
#define T_STRAT_ROUND_LOT_SIZE  23339  // LONG, Strategy Round Lot Size
#define T_STRAT_PAIR_ID         23340  // STRING, Strategy Pair ID
#define T_STRAT_PROBE           23341  // LONG, Strategy Probe Level
#define T_STRAT_ENHANCED        23342  // LONG, Strategy Enhanced Mode
#define T_STRAT_PCT_INLINE      23344  // LONG, Strategy % Inline
#define T_STRAT_MAX_TRADE_SIZE  23345  // LONG, Strategy Max Trade Size
#define T_STRAT_IGNORE_SIZE     23346  // LONG, Strategy Ignore Print Size
#define T_STRAT_IGNORE_PCT      23347  // LONG, Strategy Ignore Print %
#define T_STRAT_PRICE_TOLERANCE 23348  // LONG, Strategy Price Tolerance
#define T_STRAT_TILT            23349  // DOUBLE, Strategy Tilt
#define T_STRAT_GTY_FILL        23350  // LONG, Strategy Guaranteed Fill
#define T_STRAT_PCT_VOLUME      23351  // DOUBLE, Strategy % Volume
#define T_STRAT_PRICE           23352  // LPACK, Strategy Price
#define T_STRAT_URGENCY         23353  // LONG, Strategy Urgency
#define T_STRAT_AUTO_CANCEL     23354  // LONG, Strategy Auto Cancel
#define T_STRAT_AVG_PRICE       23355  // LONG, Strategy Average Price Limit
#define T_STRAT_PRICE_REFERENCE 23356  // STRING, Strategy Price Reference
#define T_STRAT_MAX_PCT_CHANGE  23357  // LONG, Strategy Max Percent Change
#define T_STRAT_FINISH          23358  // LONG, Strategy Finish
#define T_STRAT_AUCTION_PCT_VOL 23359  // DOUBLE, Strategy Auction Percent Volume
#define T_STRAT_AUCTION_MAX_SHARES  23360  // LONG, Strategy Auction Max Shares
#define T_STRAT_IMBALANCE_ACTION  23361  // LONG, Strategy Act On Imbalance
#define T_STRAT_EXCLUDE_AUCTIONS  23362  // STRING, Strategy Exclude Auctions
#define T_STRAT_TRIGGER_PRICE   23363  // LPACK, Strategy Trigger Price
#define T_STRAT_TRIGGER_PRICE_REF  23364  // STRING, Strategy Trigger Price Type
#define T_STRAT_TRIGGER_PRICE_OFFSET  23365  // LPACK, Strategy Trigger Price Offset
#define T_STRAT_SUBID           23366  // STRING, Strategy Sub ID
#define T_STRAT_REF_SYMBOL      23367  // STRING, Strategy Reference Symbol
#define T_STRAT_REF_SUFFIX      23368  // STRING, Strategy Reference Suffix
#define T_STRAT_SPREAD          23369  // LPACK, Strategy Spread
#define T_STRAT_PERIOD          23370  // LONG, Strategy Period
#define T_STRAT_PRICE_OFFSET    23371  // LPACK, Strategy Price Offset
#define T_STRAT_PRICE_DIRECTION 23372  // LONG, Strategy Price Direction
#define T_STRAT_BUYBACK         23373  // LONG, Strategy Buy Back
#define T_STRAT_PERCENT_1       23374  // DOUBLE, Strategy Percent 1
#define T_STRAT_PERCENT_2       23375  // DOUBLE, Strategy Percent 2
#define T_STRAT_PERCENT_3       23376  // DOUBLE, Strategy Percent 3
#define T_STRAT_PERCENT_4       23377  // DOUBLE, Strategy Percent 4
#define T_STRAT_PERCENT_5       23378  // DOUBLE, Strategy Percent 5
#define T_STRAT_PERCENT_6       23379  // DOUBLE, Strategy Percent 6
#define T_STRAT_PERCENT_7       23380  // DOUBLE, Strategy Percent 7
#define T_STRAT_PERCENT_8       23381  // DOUBLE, Strategy Percent 8
#define T_STRAT_PERCENT_9       23382  // DOUBLE, Strategy Percent 9
#define T_STRAT_RISK_FACTOR     23383  // STRING, Strategy Risk Factor
#define T_STRAT_SPEED_RISK_FACTOR  23384  // STRING, Strategy Speed Risk Factor
#define T_STRAT_CRITERIA        23385  // LONG, Strategy Criteria
#define T_STRAT_MIN_VOL_PCT_D   23386  // DOUBLE, Strategy Min Volume Pct.
#define T_STRAT_MAX_VOL_PCT_D   23387  // DOUBLE, Strategy Max Volume Pct.
#define T_STRAT_PCT_VOLUME_L    23388  // LONG, Strategy Percent Volume
#define T_STRAT_VERSION         23389  // LONG, Strategy Version
#define T_STRAT_TYPE            23390  // STRING, Strategy Type
#define T_STRAT_PARAMETERS      23391  // STRING, Strategy Parameters
#define T_STRAT_DETAILS         23392  // STRING, Strategy Details
#define T_STRAT_REDUNDANT_DATA  23393  // STRING, Redundant Strat Field Storage
#define T_STRAT_INTENSITY       23394  // DOUBLE, Strategy Intensity
#define T_STRAT_FLAGS           23395  // LONG, Strategy Flags
#define T_STRAT_OUTSIZED        23396  // LONG, Strategy Outsized
#define T_STRAT_BENCHMARK       23397  // STRING, Strategy Benchmark
#define T_STRAT_SPREAD_LOGIC    23398  // STRING, Strategy Spread Logic
#define T_STRAT_IMPACT          23399  // STRING, Strategy Impact
#define T_STRAT_COMPLETION      23400  // LONG, Strategy Completion
#define T_STRAT_MIN_PRICE       23401  // LPACK, Strategy Min Price
#define T_STRAT_MAX_PRICE       23402  // LPACK, Strategy Max Price
#define T_STRAT_STRING_1        23403  // STRING, Strategy String 1
#define T_STRAT_STRING_2        23404  // STRING, Strategy String 2
#define T_STRAT_STRING_3        23405  // STRING, Strategy String 3
#define T_STRAT_STRING_4        23406  // STRING, Strategy String 4
#define T_STRAT_STRING_5        23407  // STRING, Strategy String 5
#define T_STRAT_STRING_6        23408  // STRING, Strategy String 6
#define T_STRAT_STRING_7        23409  // STRING, Strategy String 7
#define T_STRAT_STRING_8        23410  // STRING, Strategy String 8
#define T_STRAT_STRING_9        23411  // STRING, Strategy String 9
#define T_STRAT_STRING_10       23412  // STRING, Strategy String 10
#define T_STRAT_STRING_11       23413  // STRING, Strategy String 11
#define T_STRAT_STRING_12       23414  // STRING, Strategy String 12
#define T_STRAT_STRING_13       23415  // STRING, Strategy String 13
#define T_STRAT_STRING_14       23416  // STRING, Strategy String 14
#define T_STRAT_STRING_15       23417  // STRING, Strategy String 15
#define T_STRAT_STRING_16       23418  // STRING, Strategy String 16
#define T_STRAT_STRING_17       23419  // STRING, Strategy String 17
#define T_STRAT_STRING_18       23420  // STRING, Strategy String 18
#define T_STRAT_STRING_19       23421  // STRING, Strategy String 19
#define T_STRAT_STRING_20       23422  // STRING, Strategy String 20
#define T_STRAT_STRING_21       23423  // STRING, Strategy String 21
#define T_STRAT_STRING_22       23424  // STRING, Strategy String 22
#define T_STRAT_STRING_23       23425  // STRING, Strategy String 23
#define T_STRAT_STRING_24       23426  // STRING, Strategy String 24
#define T_STRAT_STRING_25       23427  // STRING, Strategy String 25
#define T_STRAT_STRING_26       23428  // STRING, Strategy String 26
#define T_STRAT_STRING_27       23429  // STRING, Strategy String 27
#define T_STRAT_STRING_28       23430  // STRING, Strategy String 28
#define T_STRAT_STRING_29       23431  // STRING, Strategy String 29
#define T_STRAT_STRING_30       23432  // STRING, Strategy String 30
#define T_STRAT_LONG_1          23433  // LONG, Strategy Long 1
#define T_STRAT_LONG_2          23434  // LONG, Strategy Long 2
#define T_STRAT_LONG_3          23435  // LONG, Strategy Long 3
#define T_STRAT_LONG_4          23436  // LONG, Strategy Long 4
#define T_STRAT_LONG_5          23437  // LONG, Strategy Long 5
#define T_STRAT_LONG_6          23438  // LONG, Strategy Long 6
#define T_STRAT_LONG_7          23439  // LONG, Strategy Long 7
#define T_STRAT_LONG_8          23440  // LONG, Strategy Long 8
#define T_STRAT_LONG_9          23441  // LONG, Strategy Long 9
#define T_STRAT_LONG_10         23442  // LONG, Strategy Long 10
#define T_STRAT_PRICE_1         23443  // LPACK, Strategy Price 1
#define T_STRAT_PRICE_2         23444  // LPACK, Strategy Price 2
#define T_STRAT_PRICE_3         23445  // LPACK, Strategy Price 3
#define T_STRAT_PRICE_4         23446  // LPACK, Strategy Price 4
#define T_STRAT_PRICE_5         23447  // LPACK, Strategy Price 5
#define T_STRAT_PRICE_6         23448  // LPACK, Strategy Price 6
#define T_STRAT_PRICE_7         23449  // LPACK, Strategy Price 7
#define T_STRAT_PRICE_8         23450  // LPACK, Strategy Price 8
#define T_STRAT_PRICE_9         23451  // LPACK, Strategy Price 9
#define T_STRAT_PRICE_10        23452  // LPACK, Strategy Price 10
#define T_STRAT_TIME_IN_FORCE   23453  // STRING, Strategy Time In Force
#define T_STRAT_LONG_11         23454  // LONG, Strategy Long 11
#define T_STRAT_LONG_12         23455  // LONG, Strategy Long 12
#define T_STRAT_LONG_13         23456  // LONG, Strategy Long 13
#define T_STRAT_LONG_14         23457  // LONG, Strategy Long 14
#define T_STRAT_LONG_15         23458  // LONG, Strategy Long 15
#define T_STRAT_LONG_16         23459  // LONG, Strategy Long 16
#define T_STRAT_LONG_17         23460  // LONG, Strategy Long 17
#define T_STRAT_LONG_18         23461  // LONG, Strategy Long 18
#define T_STRAT_LONG_19         23462  // LONG, Strategy Long 19
#define T_STRAT_LONG_20         23463  // LONG, Strategy Long 20
#define T_STRAT_PERCENT_10      23464  // DOUBLE, Strategy Percent 10
#define T_STRAT_PERCENT_11      23465  // DOUBLE, Strategy Percent 11
#define T_STRAT_PERCENT_12      23466  // DOUBLE, Strategy Percent 12
#define T_STRAT_PERCENT_13      23467  // DOUBLE, Strategy Percent 13
#define T_STRAT_PERCENT_14      23468  // DOUBLE, Strategy Percent 14
#define T_STRAT_PERCENT_15      23469  // DOUBLE, Strategy Percent 15
#define T_STRAT_PERCENT_16      23470  // DOUBLE, Strategy Percent 16
#define T_STRAT_PERCENT_17      23471  // DOUBLE, Strategy Percent 17
#define T_STRAT_PERCENT_18      23472  // DOUBLE, Strategy Percent 18
#define T_STRAT_PERCENT_19      23473  // DOUBLE, Strategy Percent 19
#define T_STRAT_PERCENT_20      23474  // DOUBLE, Strategy Percent 20
#define T_STRAT_TIME_ZONE       23475  // STRING, Strategy Time Zone
#define T_STRAT_TIME_TAGS       23476  // STRING, Strategy Time Tags
#define T_STRAT_STRING_31       23477  // STRING, Strategy String 31
#define T_STRAT_STRING_32       23478  // STRING, Strategy String 32
#define T_STRAT_STRING_33       23479  // STRING, Strategy String 33
#define T_STRAT_STRING_34       23480  // STRING, Strategy String 34
#define T_STRAT_STRING_35       23481  // STRING, Strategy String 35
#define T_STRAT_STRING_36       23482  // STRING, Strategy String 36
#define T_STRAT_STRING_37       23483  // STRING, Strategy String 37
#define T_STRAT_STRING_38       23484  // STRING, Strategy String 38
#define T_STRAT_STRING_39       23485  // STRING, Strategy String 39
#define T_STRAT_STRING_40       23486  // STRING, Strategy String 40
#define T_EXECUTION_STATE       23499  // LONG, Execution State
#define T_DAILY_EXEC_COUNT      23500  // LONG, Daily Execution Count
#define T_DAILY_ORDER_COUNT     23501  // LONG, Daily Order Count
#define T_DAILY_VOLUME          23502  // DOUBLE, Daily Volume
#define T_DAILY_GROSS_AMT       23503  // DOUBLE, Daily Gross Amount
#define T_SHORTABLE_CONSUMED    23504  // LONG, Shortable Volume Consumed
#define T_SHORTABLE_TEMP        23505  // LONG, Shortable Temporary Volume
#define T_SHORTABLE_AVAILABLE   23506  // LONG, Shortable Volume Available
#define T_SHORTABLE_AUTH_ID     23507  // STRING, Shortable Authorization ID
#define T_SHORTABLE_RESPOND     23508  // LONG, Shortable Auth. Response Req'd
#define T_QTD_EXEC_COUNT        23510  // LONG, Quarter to date Execution Count
#define T_QTD_ORDER_COUNT       23511  // LONG, Quarter to date Order Count
#define T_QTD_VOLUME            23512  // DOUBLE, Quarter to date Volume
#define T_QTD_GROSS_AMT         23513  // DOUBLE, Quarter to date Gross Amount
#define T_MTD_EXEC_COUNT        23520  // LONG, Month to date Execution Count
#define T_MTD_ORDER_COUNT       23521  // LONG, Month to date Order Count
#define T_MTD_VOLUME            23522  // DOUBLE, Month to date Volume
#define T_MTD_GROSS_AMT         23523  // DOUBLE, Month to date Gross Amount
#define T_YTD_EXEC_COUNT        23530  // LONG, Year to date Execution Count
#define T_YTD_ORDER_COUNT       23531  // LONG, Year to date Order Count
#define T_YTD_VOLUME            23532  // DOUBLE, Year to date Volume
#define T_YTD_GROSS_AMT         23533  // DOUBLE, Year to date Gross Amount
#define T_TIPS_INDEX_RATIO      23534  // DOUBLE, Inflation Index Ratio for TIPS
#define T_CURR_BID_YIELD        23535  // DOUBLE, Current bid yield
#define T_CURR_ASK_YIELD        23536  // DOUBLE, Current ask yield
#define T_COUPNS_PER_ANNUM      23537  // LONG, Coupons per Annum
#define T_LDB_PRICE_IMPROVEMENT_SPREAD_PCTG  23538  // DOUBLE, Price improvement percentage
#define T_TRADE_REPORT_TYPE     23539  // STRING, Trade Report Type
#define T_TRADE_REPORT_BARGAIN_COND  23540  // STRING, Trade Report Bargain Conditions
#define T_ON_BEHALF_OF_CLIENT   23541  // STRING, Client ID
#define T_ANALYSIS_PROVIDERS    23542  // LONG, Analysis Providers
#define T_RESEARCH_PROVIDERS    23543  // LONG, Research Providers
#define T_OATS_CLIENT_TYPE      23544  // LONG, OATS Client Type
#define T_ROUTING_FIRM_MPID     23545  // STRING, Routing Firm MPID
#define T_COND_ACTIVE_TRIGGER   23546  // INT, Conditional Order Active Trigger
#define T_COND_TAG_INDEX        23547  // LONG, Conditional Order Tag Index
#define T_CROSSING_ROUTE        23558  // STRING, Crossing Route
#define T_NET_VALUE_TRADED_PLUS_FEES  23559  // DOUBLE, Net Value Traded + Fees
#define T_GROSS_VALUE_TRADED    23560  // DOUBLE, Gross Value Traded
#define T_NET_VALUE_TRADED      23561  // DOUBLE, Net Value Traded
#define T_GROSS_SHARES_TRADED   23562  // DOUBLE, Gross Shares Traded
#define T_SOD_VALUE             23563  // DOUBLE, SOD Value
#define T_COMPLIANCE_ID         23564  // STRING, FIX Compliance ID
#define T_DEST_ROUTE            23565  // STRING, Sub-Route
#define T_DEST_ACCT             23566  // LONG, Acct used by TradeDesk
#define T_DEST_USER             23567  // STRING, UserID used by TradeDesk
#define T_NET_SHARES_TRADED     23568  // DOUBLE, Net Shares Traded
#define T_PRICE_IMPROVEMENT     23569  // DOUBLE, Price improvement value
#define T_PRICE_IMPROVEMENT_TYPE  23570  // LONG, Price improvement type
#define T_MIN_TRADE_SIZE_TRANS  23571  // LONG, Min trade size (transient ords)
#define T_MIN_TRADE_SIZE_RES    23572  // LONG, Min trade size (resident ords)
#define T_BUY_SIDE              23573  // STRING, Side of buy order (usually Buy)
#define T_SELL_SIDE             23574  // STRING, Side of sell order
#define T_BUYER_CAPACITY        23575  // STRING, Capacity of buy order
#define T_SELLER_CAPACITY       23576  // STRING, Capacity of sell order
#define T_BUYER_MPID            23577  // STRING, MPID of buy order
#define T_SELLER_MPID           23578  // STRING, MPID of sell order
#define T_BUY_ORDER_ID          23579  // STRING, Buy order exec ID
#define T_SELL_ORDER_ID         23580  // STRING, Sell order exec ID
#define T_BUY_ORIGINAL_ORDER_ID 23581  // STRING, Order ID of buy order
#define T_SELL_ORIGINAL_ORDER_ID  23582  // STRING, Order ID of sell order
#define T_BUYER_IS_MKT_MKR      23583  // INT, If 1, buyer is MktMkr in issue
#define T_SELLER_IS_MKT_MKR     23584  // INT, if 1, seller is MktMkr in issue
#define T_CONTRA_BANK           23585  // STRING, Bank of contra order
#define T_CONTRA_BRANCH         23586  // STRING, Branch of contra order
#define T_CONTRA_CUSTOMER       23587  // STRING, Customer of contra order
#define T_CONTRA_DEPOSIT        23588  // STRING, Deposit of contra order
#define T_CONTRA_TRADER_CAPACITY  23589  // STRING, TraderCapacity of contra order
#define T_MIN_TRADE_VOLUME      23590  // LONG, Minimum volume of trades
#define T_PCT_OF_PORTFOLIO      23591  // DOUBLE, Pct. Of Portfolio
#define T_RATE_OF_RETURN        23592  // DOUBLE, Rate of Return
#define T_CXL_REASON_CODE       23593  // LONG, Cancel reason bitmask
#define T_LAST_MARKET           23594  // STRING, Last Market
#define T_LAST_CAPACITY         23595  // STRING, Last Capacity
#define T_ACCOUNT_USE           23596  // LONG, Account Use
#define T_DTC_ELIGIBLE          23597  // LONG, DTC Eligible
#define T_LAST_MARKET_NML       23598  // STRING, Last Market (Norm)
#define T_BROKER_EXCLUSION      23599  // STRING, Broker Exclusion List
#define T_LEG_CURRENCY          23600  // STRING, Leg Currency
#define T_BROKER_INCLUSION      23601  // STRING, Broker Inclusion List
#define T_PRIME_BROKER          23602  // STRING, Prime Broker
#define T_EXEC_STRAT_1          23603  // STRING, Exec Strat1
#define T_EXEC_STRAT_2          23604  // STRING, Exec Strat2
#define T_PCT_OF_PORTFOLIO_MV   23607  // DOUBLE, Pct. Of Portfolio MV
#define T_FUTURE_APPLY_SIDE     23608  // STRING, Future Apply Side
#define T_CURRENT_SHOW_SIZE     23609  // LONG, Current Show Size
#define T_ACTION_ID             23610  // LONG, Action ID
#define T_CURRENT_STATUS_ID     23611  // LONG, Current Status ID
#define T_PRICE_TYPE_ID         23612  // LONG, Price Type ID
#define T_VOLUME_TYPE_ID        23613  // LONG, Volume Type ID
#define T_CROSS_STATUS_HINT     23619  // STRING, Cross Status Hint
#define T_CROSS_ID              23620  // LONG, Cross ID
#define T_CROSS_MIN_VOLUME      23621  // LONG, Cross Min Vol
#define T_CROSS_MAX_VOLUME      23622  // LONG, Cross Max Vol
#define T_CROSS_TABLE_ANTE      23623  // LONG, Cross Table Ante
#define T_CROSS_OFFER_TIMEOUT   23624  // LONG, Cross Offer Timeout
#define T_CROSS_FLAGS           23625  // LONG, Cross Flags
#define T_CROSS_FIRM_ID         23626  // LONG, Cross Firm ID
#define T_CROSS_STATUS_DISP     23627  // STRING, Cross Status
#define T_CROSS_STATUS_ENUM     23628  // LONG, Cross Status Enum
#define T_CROSS_ORDER_ID        23629  // STRING, Cross Order ID
#define T_CROSS_NEGOTIATE_ID    23630  // STRING, Cross Negotiation ID
#define T_CROSS_IOI_PARAM       23631  // BLOB, Cross IOI Parameters
#define T_SHORT_LOCATE_VOLUME   23632  // LONG, Short Locate Volume
#define T_SHORT_LOCATE_DATETIME 23633  // STRING, Short Locate DateTime
#define T_SHORT_LOCATE_CONTACT  23634  // STRING, Short Locate Contact
#define T_SHORT_LOCATE_LEVEL    23635  // LONG, Short Locate Level
#define T_NUM_ORDERS            23636  // LONG, Num Rows
#define T_LINKED_ORDER_TAG      23637  // STRING, Linked Order Tag
#define T_TICKET_STEPOUT_INTERVAL  23640  // LONG, Step out reporting interval 
#define T_TICKET_STEPOUT_INTERVAL_LAST  23641  // LONG, Seconds since stepout
#define T_AVERAGE_PRICE_TODAY   23642  // DOUBLE, Today's average price
#define T_TRADER_LOCATION_COUNTRY  23643  // STRING, TRADER_LOCATION_COUNTRY
#define T_TRADER_LOCATION_STATE 23644  // STRING, TRADER_LOCATION_STATE
#define T_SRV_AVAIL_EXCESS      23650  // DOUBLE, Available Excess (server)
#define T_SRV_AVAIL_HOUSE_EXCESS  23651  // DOUBLE, Available House Excess (server)
#define T_SRV_AVAIL_CASH        23652  // DOUBLE, Available Cash (server)
#define T_SRV_UNREALIZED_PL     23655  // DOUBLE, Account uP&L (server)
#define T_BLOB_HEADER           23900  // BLOB, General update header blob
#define T_BLOB_BBO              23901  // BLOB, BBO data blob
#define T_BLOB_MKTMKR           23902  // BLOB, Market maker data blob
#define T_BLOB_REGIONAL         23903  // BLOB, Regional data blob
#define T_BLOB_LIVEQUOTE_HDR    23904  // BLOB, Hdr blob for LIVEQUOTE updates
#define T_BLOB_MKTMKR_HDR       23905  // BLOB, Hdr blob for MKTMKR updates
#define T_BLOB_REGIONAL_HDR     23906  // BLOB, Hdr blob for REGIONAL updates
#define T_BLOB_TAL4             23907  // BLOB, Blob containing TAL4 block
#define T_BLOB_SCAN_HDR         23908  // BLOB, Hdr blob for SCAN updates
#define T_BLOB_TICKS_HDR        23909  // BLOB, Hdr blob for TICKS updates
#define T_BLOB_TICKS            23910  // BLOB, Tick data blob
#define T_BLOB_TRADES           23911  // BLOB, Trade data blob
#define T_BLOB_BIDTICK          23912  // BLOB, Bid Tick Indicator blob
#define T_BLOB_REGIONAL_TRADE   23913  // BLOB, Regional Trade blob
#define T_EXIT_VOLUME_TRADED    23914  // LONG, ExitVolTraded
#define T_EXIT_AVG_PRICE        23915  // DOUBLE, ExitAvgPrice
#define T_EXITSTEP_TYPE         23916  // LONG, ExitStepType
#define T_LINKED_ORDER_EXIT     23917  // BLOB, LinkedOrderExit
#define T_BRACKET_TYPE          23918  // LONG, BracketType
#define T_EXITSTEP_AMT          23919  // LONG, ExitStepAmount
#define T_DARKWHEEL_DEST_BLOCK  23920  // BLOB, DarkwheelDestBlock
#define T_DARKWHEEL_DEST_MIN_VOLUME  23921  // LONG, DarkwheelDestMinVol
#define T_DARKWHEEL_REBALANCE_THRESHOLD  23922  // LONG, DarkwheelDestRebalanceThold
#define T_DARKWHEEL_ALLOC_PCT   23923  // LONG, DarkWheelAllocPct
#define T_DARKWHEEL_PREV_VOLUME   23924  // LONG, DarkWheelPrevVol
#define T_DARKWHEEL_DEST_MIN_MOVE  23925  // LONG, DarkWheelDestMinMove
#define T_DARKWHEEL_MIN_REBALANCE_INTERVAL  23926  // LONG, DarkWheelMinRebalanceInterval
#define T_BRACKET_OVERLAY_ORDER_ID  23927  // STRING, BRACKET_OVERLAY_ORDER_ID
#define T_REQUEST_TQL           23928  // STRING, REQUEST_TQL
#define T_CLIENT_USERID         23929  // STRING, CLIENT_USERID
#define T_SYNTHETIC_ICEBERG_ORDER_SEQUENCE  23930  // LONG, SYNTHETIC_ICEBERG_ORDER_SEQUENCE
#define T_SYNTHETIC_ICEBERG_ORDER_ID  23931  // STRING, SYNTHETIC_ICEBERG_ORDER_ID
#define T_SYNTHETIC_ICEBERG_VOLUME_TARGET  23932  // LONG, SYNTHETIC_ICEBERG_VOLUME_TARGET
#define T_SYNTHETIC_ICEBERG_OTHER_ACCT_ID  23933  // LONG, SYNTHETIC_ICEBERG_OTHER_ACCT_ID
#define T_DARKWHEEL_REBALANCE_STYLE  23934  // LONG, DARKWHEEL_REBALANCE_STYLE
#define T_LAST_LIQUIDITY_INDICATOR  23955  // STRING, LAST_LIQUIDITY_INDICATOR
#define T_CLIENT_ORDER_ID       23956  // STRING, Client Order ID
#define T_COMMISSION_MGT_TYPE   23957  // LONG, Commission Mgt Type
#define T_COMMISSION_MGT_ID     23958  // STRING, Commission Mgt ID
#define T_CHILD_EXIT_VEHICLE    25001  // STRING, Child Route
#define T_CHILD_VOLUME          25002  // LONG, Child Qty
#define T_CHILD_VOLUME_TYPE     25003  // STRING, Child Volume Type
#define T_CHILD_PRICE_TYPE      25004  // STRING, Child Price Type
#define T_CHILD_PRICE           25005  // LPACK, Child Price
#define T_CHILD_GOOD_UNTIL      25006  // STRING, Child Expiration
#define T_CHILD_STRATEGY        25007  // STRING, Child Strategy
#define T_CHILD_READY_TO_SEND   25008  // LONG, Child Ready
#define T_CHILD_PRICE_OFFSET    25009  // LPACK, Child Price Offset
#define T_CHILD_DISCRETION_OFFSET  25010  // LPACK, Child Discretion Offset
#define T_CHILD_STOP_PRICE      25011  // LPACK, Child Stop Price
#define T_CHILD_PRICE_DELTA     25012  // LPACK, Child Price Delta
#define T_CHILD_PRICE_REFERENCE 25013  // LONG, Child Price Reference
#define T_CHILD_PRICE_DETAILS   25014  // STRING, Child Price Details
#define T_CHILD_SHOWSIZE        25015  // LONG, Child Show Size
#define T_CHILD_LOCATE_ID       25016  // STRING, Child Locate ID
#define T_CHILD_BOOKING_TYPE    25017  // LONG, Child Booking Type
#define T_CHILD_PEG_PRICE_REFERENCE  25018  // LONG, Child Peg Price Reference
#define T_CHILD_PEG_PRICE_OFFSET  25019  // LPACK, Child Peg Price Offset
#define T_CHILD_FIRM            25020  // STRING, Child Firm
#define T_CHILD_BBCD            25021  // STRING, Child BBCD
#define T_CHILD_MESSAGE         25022  // STRING, Child Msg
#define T_CHILD_STOP_REFERENCE  25023  // LONG, Child Stop Reference
#define T_CHILD_STOP_OFFSET     25024  // LPACK, Child Stop Offset
#define T_CHILD_TRAIL_AMOUNT    25025  // LPACK, Child Trail Amount
#define T_CHILD_TRAIL_LIMIT_OFFSET  25026  // LPACK, Child Trail Limit Offset
#define T_CHILD_STRAT_PARAM     25027  // BLOB, Child Strategy Parameters
#define T_CHILD_UNDERLIER_PRICE 25028  // LPACK, Child Underlier Price
#define T_CHILD_TRADER_CAPACITY 25029  // STRING, Child Trader Capacity
#define T_CHILD_OPPOSITE_PARTY  25030  // STRING, Child Opposite Party
#define T_CHILD_COMMISSION_TYPE 25031  // LONG, Child Commission Type
#define T_CHILD_COMMISSION      25032  // DOUBLE, Child Commission
#define T_CHILD_PRICE_OFFSET_TYPE  25033  // LONG, Child Price Offset Type
#define T_CHILD_DISCRETION_OFFSET_TYPE  25034  // LONG, Child Discretion Offset Type
#define T_CHILD_PEG_PRICE_OFFSET_TYPE  25035  // LONG, Child Peg Price Offset Type
#define T_CHILD_STOP_OFFSET_TYPE  25036  // LONG, Child Stop Offset Type
#define T_CHILD_TRAIL_AMOUNT_TYPE  25037  // LONG, Child Trail Amount Type
#define T_CHILD_TRAIL_LIMIT_OFFSET_TYPE  25038  // LONG, Child Trail Limit Offset Type
#define T_CHILD_PARAMETERS      25039  // BLOB, Child Parameters
#define T_CHILD_VOLUME_PERCENT  25040  // LONG, Child Qty Percent
#define T_CHILD_VOLUME_PERCENT_TYPE  25041  // LONG, Child Qty Percent Type
#define T_CHILD_LEG_1_QUANTITY  25042  // LONG, Child Leg 1 Qty
#define T_CHILD_LEG_2_QUANTITY  25043  // LONG, Child Leg 2 Qty
#define T_CHILD_VOLUME_RULE     25044  // STRING, Child Qty Rule
#define T_CHILD_GOOD_FROM       25045  // STRING, Child Start Time
#define T_MR_LOANSREPAID        30000  // LONG, Loans repaid
#define T_MR_LOANSRAISED        30001  // LONG, Loans raised
#define T_MR_PURCHASEOFSHARES   30002  // LONG, Purchase of shares
#define T_MR_ISSUEOFSHARES      30003  // LONG, Issue of shares
#define T_MR_FINANCING          30004  // LONG, Financing
#define T_MR_MGTLIQUIDRESOURCE  30005  // LONG, Management of liquid resources
#define T_MR_EQUITYDIVPAID      30006  // LONG, Equity Dividends Paid
#define T_MR_DISPOSALS          30007  // LONG, Disposals
#define T_MR_ACQUISITIONS       30008  // LONG, Acquisitions
#define T_MR_ACQUISITIONSDISP   30009  // LONG, Acquisitions & disposals
#define T_MR_SALEOFINVESTMENTS  30010  // LONG, Sale of investments
#define T_MR_PURCHASEOFINVEST   30011  // LONG, Purchase of investments
#define T_MR_SALEOFASSETSF      30012  // LONG, Sale of assets
#define T_MR_PURCHASEOFASSETSF  30013  // LONG, Purchase of assets
#define T_MR_CAPEXPFINANCINV    30014  // LONG, Capital expenditure & fin invest
#define T_MR_TAXATION           30015  // LONG, Taxation
#define T_MR_OTHSERVICINGPAID   30016  // LONG, Other servicing paid
#define T_MR_OTHRETURNRECEIVED  30017  // LONG, Other returns received
#define T_MR_INTERESTPAID       30018  // LONG, Interest paid
#define T_MR_INTERESTRECEIVED   30019  // LONG, Interest received
#define T_MR_RETINVESTSVCFIN    30020  // LONG, Rtrns on inv'ts &svcg of finance
#define T_MR_DIVJOINTVENTURE    30021  // LONG, Div's from assoc's & jnt vent's
#define T_MR_OTHNONCASHMOVEMT   30022  // LONG, Other non-cash movements
#define T_MR_SPECIALCHARGE      30023  // LONG, Special charges/unusual items
#define T_MR_CHANGEINCREDITORS  30024  // LONG, Change in creditors
#define T_MR_CHANGEINDEBTORS    30025  // LONG, Change in debtors
#define T_MR_CHGININVENTORIES   30026  // LONG, Change in inventories
#define T_MR_OPERATINGPROFITCF  30027  // LONG, Operating profit (CF)
#define T_MR_RETURNONINVEST     30028  // DOUBLE, Return on investment
#define T_MR_EPSCONTOPSDILUTED  30029  // DOUBLE, EPS cont ops (diluted)
#define T_MR_EPSCONTOPSBASIC    30030  // DOUBLE, EPS cont ops (basic)
#define T_MR_LTDEBTTOASSETS     30031  // DOUBLE, Long-term debt to assets
#define T_MR_EXPTOREV           30032  // LONG, Other exps directly tied to revs
#define T_MR_EPSREALGAIN        30033  // DOUBLE, EPS - realized investment gain
#define T_MR_CHANGEINCASHEQUIV  30034  // LONG, Change in cash & cash equiv's
#define T_MR_EFFECTFOREIGNEXCH  30035  // LONG, Effect of foreign exchange
#define T_MR_CFFROMFINACT       30036  // LONG, Cash flow from financing activ's
#define T_MR_OTHCFFROMFINACT    30037  // LONG, Other cash flow - financ'g activ
#define T_MR_DIVIDENDSPAID      30038  // LONG, Dividends paid
#define T_MR_EPSREALINVEST      30039  // DOUBLE, EPS-realized invest gain dilut'd
#define T_MR_OTHCASHFLOW        30040  // LONG, Other cash flow items
#define T_MR_INTEXPPAID         30041  // LONG, Interest expense paid
#define T_MR_PUTSHARES          30042  // LONG, Put shares
#define T_MR_ISSUEPAYSTDEBT     30043  // LONG, Issuance/paym't of sht-term debt
#define T_MR_CFINVESTINGACT     30044  // LONG, Cash flow from invest'g activity
#define T_MR_OTHCFINVESTINGACT  30045  // LONG, Other cash flow - invest'g activ
#define T_MR_WRRTSRIGHTS        30046  // LONG, Warrants & rights
#define T_MR_OTHCFOPERATINGACT  30051  // LONG, Other cash flow - operat'g activ
#define T_MR_DISCONTOP410       30052  // LONG, Discontinued operations (CF)
#define T_MR_CHANGEINLIAB       30053  // LONG, Change in liabilities
#define T_MR_CHANGEINASSETS     30054  // LONG, Change in assets
#define T_MR_CFOPERATINGACT     30060  // LONG, Cash flow from operat'g activ's
#define T_MR_DEFERINCTAXCF      30061  // LONG, Deferred income taxes (CF)
#define T_MR_DEPRECMORT400      30062  // LONG, Depreciation & amortization (CF)
#define T_MR_INTEXPCOSTREVENUE  30064  // LONG, Interest exp (cost of revenues)
#define T_MR_TOTALDEBT          30065  // LONG, Total debt
#define T_MR_AVGSHARESDILUTED   30066  // LONG, Average shares - diluted
#define T_MR_COMMONDIVIDENDS    30067  // LONG, Common dividends
#define T_MR_PREFERREDDIVF      30068  // LONG, Preferred dividends
#define T_MR_DEFERREDLIAB       30070  // LONG, Deferred liabilities
#define T_MR_TOTLIABSTKHLDREQ   30071  // LONG, Total liabilities&stkhldrs eq'ty
#define T_MR_STKHLDREQUITYF     30072  // LONG, Stockholders' equity
#define T_MR_OTHSTKHLDREQUITY   30073  // LONG, Other stockholders' equity
#define T_MR_FOREIGNCURRTRAN    30074  // LONG, Foreign currency translation
#define T_MR_ADDLPAIDINCAPITAL  30077  // LONG, Additional paid-in capital
#define T_MR_COMMONSTOCK        30078  // LONG, Common stock
#define T_MR_PREFERREDSTOCK     30079  // LONG, Preferred stock-income
#define T_MR_PREFERREDSTOCKASSET  30080  // LONG, Preferred stock-asset
#define T_MR_OTHERLIABILITIES   30081  // LONG, Other liabilities
#define T_MR_OTHERDEFERREDLIAB  30084  // LONG, Other deferred liabilities
#define T_MR_DEFERINCTAXBS      30085  // LONG, Deferred income taxes (BS)
#define T_MR_DEPOSITS           30089  // LONG, Deposits
#define T_MR_CURRENTLTDEBT      30090  // LONG, Curr't portion of long-term debt
#define T_MR_SHORTTERMBORROWF   30091  // LONG, Short-term borrowings
#define T_MR_NETPROPEQUIP       30098  // LONG, Net property & equipment
#define T_MR_ACCUMDEPRECAMORT   30099  // LONG, Accumulated deprec'n & amort'n
#define T_MR_GROSSPPE           30100  // LONG, Gross property - plant & equip't
#define T_MR_MACHEQUIP          30101  // LONG, Machinery & equipment
#define T_MR_BUILDINGS349       30102  // LONG, Buildings
#define T_MR_LAND               30103  // LONG, Land
#define T_MR_LOANSANDLEASEFIN   30104  // LONG, Loans & lease financing
#define T_MR_INVESTANDADVANCES  30105  // LONG, Investments & advances
#define T_MR_LTRECEIVABLES      30106  // LONG, Long-term receivables
#define T_MR_FINISHEDGOODF      30110  // LONG, Finished goods
#define T_MR_WORKINPROCESSF     30111  // LONG, Work in process
#define T_MR_RAWMATERIALSF      30112  // LONG, Raw materials
#define T_MR_RECEIVABLES        30113  // LONG, Receivables
#define T_MR_CASHEQUIVALENTS    30114  // LONG, Cash & cash equivalents
#define T_MR_EPSNETINCBASIC     30115  // DOUBLE, EPS - net income (basic)
#define T_MR_OUTSTANDINGSHARES  30116  // LONG, Outstanding shares
#define T_MR_AVGSHARESBASIC     30117  // LONG, Average shares - basic
#define T_MR_ACCOUNTINGCHANGES  30119  // LONG, Accounting changes
#define T_MR_EQUITYEARNINGS     30124  // LONG, Equity earnings
#define T_MR_REALCAPGAINSLOSS   30128  // LONG, Realized capital gains (losses)
#define T_MR_INTERESTEXPENSE    30129  // LONG, Interest expense
#define T_MR_INTERESTINCOME     30130  // LONG, Interest income
#define T_MR_TOTALINDIRECTEXP   30131  // LONG, Total indirect expenses
#define T_MR_OTHERINDIRECTEXP   30132  // LONG, Other indirect expenses
#define T_MR_RSRCHDEVELOPMENT   30134  // LONG, Research & development
#define T_MR_DEPRECAMORTIS      30135  // LONG, Depreciation & amortization (IS)
#define T_MR_GROSSMARGIN        30137  // DOUBLE, Gross margin
#define T_MR_COSTOFREVENUES     30138  // LONG, Cost of revenues
#define T_MR_PROVISIONLOANLOSS  30139  // LONG, Provision for loan losses
#define T_MR_INTERESTEXPBANKS   30140  // LONG, Interest expense (banks)
#define T_MR_INTERESTINCBANKS   30143  // LONG, Interest income (banks)
#define T_MR_WORKCAPTOTASSET2   30144  // DOUBLE, Working capital/total assets
#define T_MR_REVENUETOTALASSET  30145  // DOUBLE, Revenues/total assets
#define T_MR_REVENUEWORKINGCAP  30146  // DOUBLE, Revenues/working capital
#define T_MR_CURRENTLIABEQUITY  30147  // DOUBLE, Current liabilities/equity
#define T_MR_PRETAXINCREVENUE1  30148  // DOUBLE, Pretax income/revenues %
#define T_MR_TAXRATE            30150  // DOUBLE, Tax rate %
#define T_MR_RETURNONASSETS     30151  // DOUBLE, Return on assets %
#define T_MR_PROFITMARGIN       30152  // DOUBLE, Profit margin %
#define T_MR_OPPROFITMARGIN     30154  // DOUBLE, Operating profit margin %
#define T_MR_LTDEBTEQUITY       30155  // DOUBLE, Long-term debt/equity
#define T_MR_INTERESTCOVERAGE   30156  // DOUBLE, Interest coverage
#define T_MR_GROSSMARGINPC      30157  // DOUBLE, Gross margin %
#define T_MR_EBITDAREVENUE      30158  // DOUBLE, EBITDA/revenue %
#define T_MR_EBITDA             30159  // LONG, EBITDA
#define T_MR_ACIDTEST           30160  // DOUBLE, Acid test
#define T_MR_EPSCOMMONYEAREND   30161  // DOUBLE, EPS  -  common (year end)
#define T_MR_RETURNONEQUITY     30162  // DOUBLE, Return on equity
#define T_MR_TOTALDEBTEQUITY    30163  // DOUBLE, Total debt/equity
#define T_MR_LTDEQUITY          30164  // DOUBLE, LTD/equity
#define T_MR_DIVIDENDPAYOUT     30165  // DOUBLE, Dividend payout - %
#define T_MR_REVAVAILCOMMON     30166  // DOUBLE, % of revenue avail for common
#define T_MR_STKHLDREQUITYPC    30167  // DOUBLE, % Stockholders' equity
#define T_MR_YEARENDRISKASSETS  30168  // DOUBLE, Year-end risk assets
#define T_MR_YEARENDDEPOSITS    30169  // DOUBLE, Year-end deposits
#define T_MR_YEARENDLOANS       30170  // DOUBLE, Year-end loans
#define T_MR_YEARENDASSETS      30171  // DOUBLE, Year-end assets
#define T_MR_COMMSTKSURPHLDREQ  30172  // DOUBLE, %CommStk&Surpl(com stkhld's equ)
#define T_MR_NETTANGASSETPSPRF  30173  // DOUBLE, Net tangible assets/share-pref'd
#define T_MR_NETTANGASSETPSCM   30174  // DOUBLE, Net tangible assets/share-common
#define T_MR_DEBTDEPRPLANT      30175  // DOUBLE, % Debt of depreciated plant
#define T_MR_NETCURRNETWORTH    30176  // DOUBLE, % Net curr't assets to net worth
#define T_MR_NETCURR1000LT      30177  // DOUBLE, Net curr't assets/$1K long-t dbt
#define T_MR_NETOPINCNETUTPL    30178  // DOUBLE, %NetOp'g income of net util plnt
#define T_MR_MAINTGROSSOPREV    30179  // DOUBLE, % Maint of gross op'g revenues
#define T_MR_FUELCOSTOFREVENUE  30180  // DOUBLE, Fuel cost - % of revenue
#define T_MR_OPERATINGRATIO     30181  // DOUBLE, Operating ratio - %
#define T_MR_SALESNETPROP       30182  // DOUBLE, % Sales to net property
#define T_MR_SALESTOTOTALASSET  30183  // DOUBLE, % Sales to total assets
#define T_MR_GROSSINCLTDEBT     30184  // DOUBLE, Gross income % long-term debt
#define T_MR_BVPERSHAREINTANG   30185  // DOUBLE, Book value per shr (incl intang)
#define T_MR_INVENTCURRASSET    30186  // DOUBLE, % Inventories to current assets
#define T_MR_CASHSECCURRASSET   30187  // DOUBLE, % Cash & sec's to curr't assets
#define T_MR_CFPERSHAREDILUTED  30188  // DOUBLE, Cash flow per share (diluted)
#define T_MR_NETPROFITMARGIN    30189  // DOUBLE, Net profit margin
#define T_MR_MARGINOFSAFETY     30190  // DOUBLE, Margin of safety
#define T_MR_RDTOSALES          30191  // DOUBLE, R&D to sales
#define T_MR_SALESINVENTORIES   30192  // DOUBLE, Sales / inventories
#define T_MR_SALESRECEIVABLES   30193  // DOUBLE, Sales / receivables
#define T_MR_REVENUEPERSHARE    30194  // DOUBLE, Revenue per share
#define T_MR_RATIOGRPLANTOPREV  30195  // LONG, Gross plant to gross op'g rev
#define T_MR_CURRENTRATIO       30196  // DOUBLE, Current ratio
#define T_MR_BOOKVALUEPERSHARE  30197  // DOUBLE, Book value per share
#define T_MR_TOTALASSETS        30198  // LONG, Total assets
#define T_MR_TOTCURRENTASSETF   30199  // LONG, Total current assets
#define T_MR_NOTESRECCURRENT    30218  // LONG, Notes receiveable frm sharehldrs
#define T_MR_INVENTORIES        30226  // LONG, Inventories
#define T_MR_PREPAYMENTSOTHER   30242  // LONG, Pre-payments & other
#define T_MR_OTHCURRENTASSETS   30243  // LONG, Other current assets
#define T_MR_PPENET             30272  // LONG, Property plant & equipment net
#define T_MR_DEFERREDCHARGES    30298  // LONG, Deferred charges
#define T_MR_INTANGIBLES        30306  // LONG, Intangibles
#define T_MR_GOODWILLNET        30307  // LONG, Goodwill net
#define T_MR_OTHERASSETS        30312  // LONG, Other assets
#define T_MR_TOTALLIABILITIES   30313  // LONG, Total liabilities
#define T_MR_TOTALCURRENTLIAB   30314  // LONG, Total current liabilities
#define T_MR_ACCTSPAYABLE       30317  // LONG, Accounts payable
#define T_MR_NOTESPAYABLE       30318  // LONG, Notes payable
#define T_MR_TAXESPAYABLE       30324  // LONG, Taxes payable
#define T_MR_DIVIDENDSPAYABLE   30328  // LONG, Dividends payable
#define T_MR_ACCRUEDEXPS        30329  // LONG, Accrued expenses
#define T_MR_AIRTRAFFICLIAB     30335  // LONG, Air traffic liability
#define T_MR_OTHERPAYSACCREXP   30336  // LONG, Other payables & accrued exp's
#define T_MR_CURRENTDEBT        30337  // LONG, Current debt
#define T_MR_TOTALDEPOSITS      30350  // LONG, Total deposits
#define T_MR_OTHERCURRENTLIAB   30352  // LONG, Other current liabilities
#define T_MR_LONGTERMDEBT       30354  // LONG, Long-term debt
#define T_MR_LIABBANKRUPTCY     30372  // LONG, Liabilities subj to bankruptcy
#define T_MR_DEFLIABCREDITS     30373  // LONG, Deferred liabilities & credits
#define T_MR_MINORITYINTBS      30388  // LONG, Minority interest (BS)
#define T_MR_REDEEMPREFSTOCK    30390  // LONG, Redeemable preferred stock
#define T_MR_STKHLDREQUITY      30394  // LONG, Total stockholders' equity
#define T_MR_PREFERREDSTOCKNET  30396  // LONG, Preferred stock net
#define T_MR_OTHPAIDINCAPITAL   30397  // LONG, Other paid-in capital
#define T_MR_RETAINEDEARNINGS   30398  // LONG, Retained earnings
#define T_MR_TREASURYSTOCK      30399  // LONG, Treasury stock
#define T_MR_UNEARNEDESOPCOMP   30401  // LONG, Unearned ESOP compensation
#define T_MR_TOTPARTNERSHIPCAP  30404  // LONG, Total partnership capital
#define T_MR_TOTALREVENUES      30407  // LONG, Total revenues
#define T_MR_TOTALINTERESTINC   30410  // LONG, Total interest income
#define T_MR_OTHOPERATINGREV    30455  // LONG, Other operating revenue
#define T_MR_EXPDIRTIEDTOREV    30456  // LONG, Exp's directly tied to revenues
#define T_MR_COSTOFSALES        30457  // LONG, Cost of sales
#define T_MR_TOTINTEXPCOSTREV   30460  // LONG, Total interest exp (cost of rev)
#define T_MR_CREDITLOSSPROV     30465  // LONG, Credit loss provision
#define T_MR_GROSSPROFIT        30499  // LONG, Gross profit
#define T_MR_TOTINDIRECTOPEXP   30501  // LONG, Total indirect operat'g expenses
#define T_MR_SELLGENERALADMEXP  30502  // LONG, Selling - general & admin exp
#define T_MR_EXPLORATIONCOSTS   30537  // LONG, Exploration costs
#define T_MR_TOTRESTRUCTEXP     30538  // LONG, Total restructuring expense
#define T_MR_OPERATINGINCOME    30540  // LONG, Operating income
#define T_MR_OTHINCEXP          30541  // LONG, Other income (expense) - net
#define T_MR_OTHINTINC          30549  // LONG, Other interest income (exp) net
#define T_MR_FOREIGNEXGAINLOSS  30551  // LONG, Foreign exchange gain (loss)
#define T_MR_INCOPSBEFINCTAX    30562  // LONG, Income -cont ops before inc tax
#define T_MR_INCOMETAXES        30563  // LONG, Income taxes
#define T_MR_EQEARNLOSSAFFIL    30564  // LONG, Equity earngs (loss) -affiliates
#define T_MR_MINORITYINTIS      30566  // LONG, Minority interest (IS)
#define T_MR_INVESTGAINSLOSS    30567  // LONG, Investment gains (losses)
#define T_MR_INCCONTINUINGOP    30568  // LONG, Income - continuing operations
#define T_MR_DISCONTINUEDOP     30569  // LONG, Discontinued operations (IS)
#define T_MR_EXTRAORDINARYITEM  30574  // LONG, Extraordinary items
#define T_MR_EFFECTOFACCTGCHG   30576  // LONG, Effect of accounting changes
#define T_MR_NETINCOME          30577  // LONG, Net income (IS)
#define T_MR_NETINCOMETOCOMMON  30579  // LONG, Net income to common
#define T_MR_WGTAVGSHARESOUT    30580  // LONG, Wghtd avg shares outst'g-basic
#define T_MR_YEARENDSHARESOUT   30581  // LONG, Year end shares outstanding
#define T_MR_WGTAVGSHSOUTDIL    30582  // LONG, Wghtd avg shares outst'g-diluted
#define T_MR_EPSCONTINUINGOP2   30583  // DOUBLE, EPS - continuing operations
#define T_MR_EPSNETINC          30584  // DOUBLE, EPS - net income
#define T_MR_EPSTOTALDISCOPERS  30585  // DOUBLE, EPS - total discontinued opers
#define T_MR_EPSEXORDINARYITEM  30586  // DOUBLE, EPS - extraordinary item
#define T_MR_EPSACCOUNTINGCHG   30587  // DOUBLE, EPS - accounting change
#define T_MR_EPSOTH             30588  // DOUBLE, EPS - other
#define T_MR_EPSCONTINUINGOP1   30589  // DOUBLE, EPS - continuing ops (diluted)
#define T_MR_EPSNETINCDILUTED   30590  // DOUBLE, EPS - net income (diluted)
#define T_MR_EPSTOTDISCOPDIL    30591  // DOUBLE, EPS - total discont ops-diluted
#define T_MR_EPSEXORDITEMDIL    30592  // DOUBLE, EPS - extraord'y item (diluted)
#define T_MR_EPSACCTGCHGDIL     30593  // DOUBLE, EPS - accounting chg (diluted)
#define T_MR_EPSOTHDILUTED      30594  // DOUBLE, EPS - other (diluted)
#define T_MR_NETCFOPACTIV       30596  // LONG, Net cash flow-op'g activ (indir)
#define T_MR_NETINCCASHFLOWS    30597  // LONG, Net income (CF)
#define T_MR_PROVISIONFORLOSS   30603  // LONG, Provision for losses
#define T_MR_LOSSGAINSALEASSET  30604  // LONG, Loss (gain) on sale of assets
#define T_MR_UNDISTREARNLOSS    30610  // LONG, Undistributed (earnings) losses
#define T_MR_EXORDINARYITEMCFS  30615  // LONG, Extraordinary items
#define T_MR_CUMULEFFCHGACCTG   30616  // LONG, Cumul effect of chg in acctng
#define T_MR_RESTRUCTEXPCFS     30617  // LONG, Restructuring expense
#define T_MR_SPECCHGUNUSUAL     30618  // LONG, Special charges/unusual items
#define T_MR_INTCHGCONSTR       30619  // LONG, Interest charged to construction
#define T_MR_OTHNETINCADJ       30621  // LONG, Other net income adjustments
#define T_MR_INCDECASSET        30622  // LONG, (Increase) decrease in assets
#define T_MR_INCDECLIAB         30629  // LONG, Increase (decrease) in liabil's
#define T_MR_INCTAXESPAYCFS     30631  // LONG, Income taxes paid
#define T_MR_INCDECSTKHLDREQ    30637  // LONG, Increase (decr) stkhldrs equity
#define T_MR_OTHCFOPACTIVS      30638  // LONG, Other cash flow-op'g activ-indir
#define T_MR_SALEOFBUSINESS     30641  // LONG, Sale of business
#define T_MR_SALEPPE            30642  // LONG, Sale of property plant & equip't
#define T_MR_SALEOFINVESTEC     30643  // LONG, Sale of investment securities
#define T_MR_PURCHBUSINESS      30646  // LONG, Purchase of business
#define T_MR_CAPITALEXP         30648  // LONG, Capital expenditures
#define T_MR_PURCHINVESTEC      30649  // LONG, Purchase of investmnt securities
#define T_MR_ISSUANCEOFLTDEBT   30655  // LONG, Issuance of long-term debt
#define T_MR_ISSUECAPSTOCK      30656  // LONG, Issuance of capital stock
#define T_MR_PAYMENTSOFLTDEBT   30663  // LONG, Payments of long-term debt
#define T_MR_PAYACQTREASURYSTK  30664  // LONG, Payments to acquire treasury stk
#define T_MR_DIVIDENDS          30665  // LONG, Dividends
#define T_MR_NETINCCASHEQUIV    30668  // LONG, Net increase -cash & cash equivs
#define T_MR_CHGFOREIGNCURRTR   30669  // LONG, Change in foreign curr transl'n
#define T_MR_CASHEQUIVBEGYEAR   30670  // LONG, Cash & cash equiv - beginning
#define T_MR_CASHEQUIVENDYEAR   30671  // LONG, Cash & cash equivalents - end
#define T_MR_CFSDISCONTINUEDOP  30672  // LONG, Cash flow from discontinued ops
#define T_MR_ACCUMOTHCOMPRINC   30683  // LONG, Accumulated other comp income
#define T_MR_SHORTTERMINVEST    30697  // LONG, Short-term investments
#define T_MR_COMPANY_ABSTRACT   30698  // STRING, Company Abstract
#define T_MR_OTHERREVENUESEXP   30738  // LONG, Other revenues/(expenses) net
#define T_SHORTABLE_CONSUMED_AT_FIRM  30739  // LONG, Firm Level Consumed Vol
#define T_SHORTABLE_CONSUMED_AT_BANK  30740  // LONG, Bank Level Consumed Vol
#define T_SHORTABLE_CONSUMED_AT_BRANCH  30741  // LONG, Branch Level Consumed Vol
#define T_SHORTABLE_CONSUMED_AT_CUSTOMER  30742  // LONG, Customer Level Consumed Vol
#define T_SHORTABLE_CONSUMED_AT_DEPOSIT  30743  // LONG, Deposit Level Consumed Vol
#define T_TQS_USE_SETTINGS      30744  // LONG, Use ticket quantity settings
#define T_TQS_ROUND_LOT         30745  // LONG, Ticket quantity: round lot
#define T_TQS_VOLUME_TYPE       30746  // LONG, Ticket quantity: volume type
#define T_TQS_VOLUME            30747  // LONG, Ticket quantity: volume
#define T_TQS_PERCENTAGE        30748  // LONG, Ticket quantity: percentage
#define T_NOTIONAL_AMOUNT       30749  // DOUBLE, Notional Amount
#define T_NOTIONAL_CONSUMED     30750  // DOUBLE, Notional Consumed
#define T_MAX_OPEN_ORDERS       30751  // LONG, Max Open Orders
#define T_CURR_OPEN_ORDERS      30752  // LONG, Current Open Orders
#define T_NOTIONAL_TARGET       30753  // DOUBLE, NOTIONAL_TARGET
#define T_NOTIONAL_PROGRESS     30754  // DOUBLE, NOTIONAL_PROGRESS
#define T_NOTIONAL_RESIDUAL     30755  // DOUBLE, NOTIONAL_RESIDUAL
#define T_NOTIONAL_ORDER_FLAG   30756  // INT, T_NOTIONAL_ORDER_FLAG
#define T_LEG_ORIG_CANCEL_ID    30757  // STRING, LEG_ORIG_CANCEL_ID
#define T_RELATED_CANCEL        30758  // STRING, RELATED_CANCEL
#define T_SYNTHETIC_SPREAD_TYPE 30800  // LONG, Spread strategy
#define T_SYNTHETIC_SPREAD_CASH 30801  // DOUBLE, spread_cash
#define T_SPREAD_WAVE_PRICE_ADJ 30802  // DOUBLE, SPREAD_WAVE_PRICE_ADJ
#define T_SPREAD_LEG_IGNORE_DEPTH  30803  // LONG, SPREAD_LEG_IGNORE_DEPTH
#define T_SPREAD_LEG_ROUTE      30804  // STRING, SPREAD_LEG_ROUTE
#define T_SPREAD_LEG_OUT_ACTION 30805  // LONG, SPREAD_LEG_OUT_ACTION
#define T_SPREAD_LIQ_LEG_PAYUP_DELTA  30806  // DOUBLE, SPREAD_LIQ_LEG_PAYUP_DELTA
#define T_SPREAD_LIQ_LEG_DEPTH_MULT  30807  // DOUBLE, SPREAD_LIQ_LEG_DEPTH_MULT
#define T_SPREAD_LEG_MAX_TRADED_VOLUME_PCT  30808  // DOUBLE, SPREAD_LEG_MAX_TRADED_VOLUME_PCT
#define T_SPREAD_LEG_CONSIDER_OWN_ORDERS  30809  // LONG, SPREAD_LEG_CONSIDER_OWN_ORDERS
#define T_SPREAD_LEG_QUOTE_MAX_AGGRESSION  30810  // LONG, SPREAD_LEG_QUOTE_MAX_AGGRESSION
#define T_SPREAD_LEG_FILL_TRIG_PCT  30811  // DOUBLE, SPREAD_LEG_FILL_TRIG_PCT
#define T_SPREAD_LEG_QUOTE_TOLERANCE_PCT  30812  // DOUBLE, SPREAD_LEG_QUOTE_TOLERANCE_PCT
#define T_SPREAD_LEG_REQUOTE_THRSHLD_PCT  30813  // DOUBLE, SPREAD_LEG_REQUOTE_THRSHLD_PCT
#define T_SPREAD_CLIP           30814  // DOUBLE, SPREAD_CLIP
#define T_SPREAD_CLIP_TYPE      30815  // LONG, SPREAD_CLIP_TYPE
#define T_EXTERNAL_ACCEPTANCE_FLAG  30825  // LONG, ACCEPTANCE_FLAG
#define T_EXTERNAL_ACCEPTANCE_DEST  30826  // STRING, ACCEPTANCE_DEST
#define T_EXTERNAL_ACCEPTANCE_TIMEOUT  30827  // LONG, ACCEPTANCE_TIMEOUT
#define T_TS_WORKFLOW_FLAG      30828  // LONG, TS_WORKFLOW_FLAG
#define T_TS_CURRENCY_RATIO     30829  // DOUBLE, TS_CURRENCY_RATIO
#define T_SPREAD_LEG_ROUTE_SUBROUTE  30830  // STRING, LEG_ROOUTE_SUBRPOUTE
#define T_ADR_STATUS            30831  // STRING, ADR_STATUS
#define T_ADR_PLUS_FLAG         30832  // STRING, ADR_PLUS_FLAG
#define T_ADR_TYPE              30833  // LONG, ADR_TYPE
#define T_ADR_AVG_PRICE         30834  // LPACK, ADR_AVG_PRICE
#define T_ADR_PRINCIPAL         30835  // LPACK, ADR_PRINCIPAL
#define T_ADR_STAMP_DUTY        30836  // LPACK, ADR_STAMP_DUTY
#define T_ADR_LOCAL_FEE         30837  // LPACK, ADR_LOCAL_FEE
#define T_ADR_MARKET_FEE        30838  // LPACK, ADR_MARKET_FEE
#define T_ADR_CLIENT_FEE        30839  // LPACK, ADR_CLIENT_FEE
#define T_ADR_CLIENT_COMM       30840  // LPACK, ADR_CLIENT_COMM
#define T_ADR_NET_MONEY         30841  // LPACK, ADR_NET_MONEY
#define T_ADR_NET_PRICE         30842  // LPACK, ADR_NET_PRICE
#define T_ADR_DISPLAY_DATA      30843  // STRING, ADR_DISPLAY_DATA
#define T_ADR_FX_RATE           30844  // LPACK, ADR_FX_RATE
#define T_ADR_IS_AGG            30845  // STRING, ADR_IS_AGG
#define T_ADR_CONV_TYPE         30846  // STRING, ADR_CONV_TYPE
#define T_ADR_RATIO             30847  // STRING, ADR_RATIO
#define T_ADR_ORDER_ID          30848  // STRING, ADR_ORDER_ID
#define T_ADR_FX_ORDER_ID       30849  // STRING, ADR_FX_ORDER_ID
#define T_ADR_ORD_MKT           30850  // STRING, ADR_ORD_MKT
#define T_ADR_VOLUME            30851  // LONG, ADR_VOLUME
#define T_ORD_SYMBOL            30852  // STRING, ORD_SYMBOL
#define T_ADR_SYMBOL            30853  // STRING, ADR_SYMBOL
#define T_UI_TOKEN              30854  // STRING, UI_TOKEN
#define T_ADR_ROUND_LOT_SIZE    30855  // LONG, ADR_ROUND_LOT_SIZE
#define T_ADR_ROUND_LOT_QTY     30856  // LONG, ADR_ROUND_LOT_QTY
#define T_ADR_TO_TICKET         30857  // STRING, ADR_TO_TICKET
#define T_ADR_DELIVERY_DATE     30858  // DATE, ADR_DELIVERY_DATE
#define T_ADR_BANK_CABLE_FEE    30859  // LPACK, ADR_BANK_CABLE_FEE
#define T_FLOW_TYPE_FLAG        30861  // LONG, FLOW_TYPE_FLAG
#define T_ADR_WORKING_QTY       30862  // LONG, ADR_WORKING_QTY
#define T_ADR_COMPLETED_QTY     30863  // LONG, ADR_COMPLETED_QTY
#define T_ADR_CONVERTED_QTY     30864  // LONG, ADR_CONVERTED_QTY
#define T_FLOWTYPE_BROKER       30865  // STRING, hold flowtype and broker
#define T_FUTURE_NEAR_DATE_STRING  30866  // STRING, NEAR_MONTH
#define T_FUTURE_NEAR_SIDE      30867  // STRING, NEAR_MONTH_SIDE
#define T_FUTURE_FAR_DATE_STRING  30868  // STRING, NFAR_MONTH
#define T_FUTURE_FAR_SIDE       30869  // STRING, NFAR_MONTH_SIDE
#define T_ADR_CLIENT_ENTITLEMENT_TYPE  30870  // LONG, Client Entitlement

#endif // ifdef FIDDEF_FIDS_H
