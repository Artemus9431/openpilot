#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6858265802359206836) {
   out_6858265802359206836[0] = delta_x[0] + nom_x[0];
   out_6858265802359206836[1] = delta_x[1] + nom_x[1];
   out_6858265802359206836[2] = delta_x[2] + nom_x[2];
   out_6858265802359206836[3] = delta_x[3] + nom_x[3];
   out_6858265802359206836[4] = delta_x[4] + nom_x[4];
   out_6858265802359206836[5] = delta_x[5] + nom_x[5];
   out_6858265802359206836[6] = delta_x[6] + nom_x[6];
   out_6858265802359206836[7] = delta_x[7] + nom_x[7];
   out_6858265802359206836[8] = delta_x[8] + nom_x[8];
   out_6858265802359206836[9] = delta_x[9] + nom_x[9];
   out_6858265802359206836[10] = delta_x[10] + nom_x[10];
   out_6858265802359206836[11] = delta_x[11] + nom_x[11];
   out_6858265802359206836[12] = delta_x[12] + nom_x[12];
   out_6858265802359206836[13] = delta_x[13] + nom_x[13];
   out_6858265802359206836[14] = delta_x[14] + nom_x[14];
   out_6858265802359206836[15] = delta_x[15] + nom_x[15];
   out_6858265802359206836[16] = delta_x[16] + nom_x[16];
   out_6858265802359206836[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_683644921736672263) {
   out_683644921736672263[0] = -nom_x[0] + true_x[0];
   out_683644921736672263[1] = -nom_x[1] + true_x[1];
   out_683644921736672263[2] = -nom_x[2] + true_x[2];
   out_683644921736672263[3] = -nom_x[3] + true_x[3];
   out_683644921736672263[4] = -nom_x[4] + true_x[4];
   out_683644921736672263[5] = -nom_x[5] + true_x[5];
   out_683644921736672263[6] = -nom_x[6] + true_x[6];
   out_683644921736672263[7] = -nom_x[7] + true_x[7];
   out_683644921736672263[8] = -nom_x[8] + true_x[8];
   out_683644921736672263[9] = -nom_x[9] + true_x[9];
   out_683644921736672263[10] = -nom_x[10] + true_x[10];
   out_683644921736672263[11] = -nom_x[11] + true_x[11];
   out_683644921736672263[12] = -nom_x[12] + true_x[12];
   out_683644921736672263[13] = -nom_x[13] + true_x[13];
   out_683644921736672263[14] = -nom_x[14] + true_x[14];
   out_683644921736672263[15] = -nom_x[15] + true_x[15];
   out_683644921736672263[16] = -nom_x[16] + true_x[16];
   out_683644921736672263[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1422952877034374174) {
   out_1422952877034374174[0] = 1.0;
   out_1422952877034374174[1] = 0.0;
   out_1422952877034374174[2] = 0.0;
   out_1422952877034374174[3] = 0.0;
   out_1422952877034374174[4] = 0.0;
   out_1422952877034374174[5] = 0.0;
   out_1422952877034374174[6] = 0.0;
   out_1422952877034374174[7] = 0.0;
   out_1422952877034374174[8] = 0.0;
   out_1422952877034374174[9] = 0.0;
   out_1422952877034374174[10] = 0.0;
   out_1422952877034374174[11] = 0.0;
   out_1422952877034374174[12] = 0.0;
   out_1422952877034374174[13] = 0.0;
   out_1422952877034374174[14] = 0.0;
   out_1422952877034374174[15] = 0.0;
   out_1422952877034374174[16] = 0.0;
   out_1422952877034374174[17] = 0.0;
   out_1422952877034374174[18] = 0.0;
   out_1422952877034374174[19] = 1.0;
   out_1422952877034374174[20] = 0.0;
   out_1422952877034374174[21] = 0.0;
   out_1422952877034374174[22] = 0.0;
   out_1422952877034374174[23] = 0.0;
   out_1422952877034374174[24] = 0.0;
   out_1422952877034374174[25] = 0.0;
   out_1422952877034374174[26] = 0.0;
   out_1422952877034374174[27] = 0.0;
   out_1422952877034374174[28] = 0.0;
   out_1422952877034374174[29] = 0.0;
   out_1422952877034374174[30] = 0.0;
   out_1422952877034374174[31] = 0.0;
   out_1422952877034374174[32] = 0.0;
   out_1422952877034374174[33] = 0.0;
   out_1422952877034374174[34] = 0.0;
   out_1422952877034374174[35] = 0.0;
   out_1422952877034374174[36] = 0.0;
   out_1422952877034374174[37] = 0.0;
   out_1422952877034374174[38] = 1.0;
   out_1422952877034374174[39] = 0.0;
   out_1422952877034374174[40] = 0.0;
   out_1422952877034374174[41] = 0.0;
   out_1422952877034374174[42] = 0.0;
   out_1422952877034374174[43] = 0.0;
   out_1422952877034374174[44] = 0.0;
   out_1422952877034374174[45] = 0.0;
   out_1422952877034374174[46] = 0.0;
   out_1422952877034374174[47] = 0.0;
   out_1422952877034374174[48] = 0.0;
   out_1422952877034374174[49] = 0.0;
   out_1422952877034374174[50] = 0.0;
   out_1422952877034374174[51] = 0.0;
   out_1422952877034374174[52] = 0.0;
   out_1422952877034374174[53] = 0.0;
   out_1422952877034374174[54] = 0.0;
   out_1422952877034374174[55] = 0.0;
   out_1422952877034374174[56] = 0.0;
   out_1422952877034374174[57] = 1.0;
   out_1422952877034374174[58] = 0.0;
   out_1422952877034374174[59] = 0.0;
   out_1422952877034374174[60] = 0.0;
   out_1422952877034374174[61] = 0.0;
   out_1422952877034374174[62] = 0.0;
   out_1422952877034374174[63] = 0.0;
   out_1422952877034374174[64] = 0.0;
   out_1422952877034374174[65] = 0.0;
   out_1422952877034374174[66] = 0.0;
   out_1422952877034374174[67] = 0.0;
   out_1422952877034374174[68] = 0.0;
   out_1422952877034374174[69] = 0.0;
   out_1422952877034374174[70] = 0.0;
   out_1422952877034374174[71] = 0.0;
   out_1422952877034374174[72] = 0.0;
   out_1422952877034374174[73] = 0.0;
   out_1422952877034374174[74] = 0.0;
   out_1422952877034374174[75] = 0.0;
   out_1422952877034374174[76] = 1.0;
   out_1422952877034374174[77] = 0.0;
   out_1422952877034374174[78] = 0.0;
   out_1422952877034374174[79] = 0.0;
   out_1422952877034374174[80] = 0.0;
   out_1422952877034374174[81] = 0.0;
   out_1422952877034374174[82] = 0.0;
   out_1422952877034374174[83] = 0.0;
   out_1422952877034374174[84] = 0.0;
   out_1422952877034374174[85] = 0.0;
   out_1422952877034374174[86] = 0.0;
   out_1422952877034374174[87] = 0.0;
   out_1422952877034374174[88] = 0.0;
   out_1422952877034374174[89] = 0.0;
   out_1422952877034374174[90] = 0.0;
   out_1422952877034374174[91] = 0.0;
   out_1422952877034374174[92] = 0.0;
   out_1422952877034374174[93] = 0.0;
   out_1422952877034374174[94] = 0.0;
   out_1422952877034374174[95] = 1.0;
   out_1422952877034374174[96] = 0.0;
   out_1422952877034374174[97] = 0.0;
   out_1422952877034374174[98] = 0.0;
   out_1422952877034374174[99] = 0.0;
   out_1422952877034374174[100] = 0.0;
   out_1422952877034374174[101] = 0.0;
   out_1422952877034374174[102] = 0.0;
   out_1422952877034374174[103] = 0.0;
   out_1422952877034374174[104] = 0.0;
   out_1422952877034374174[105] = 0.0;
   out_1422952877034374174[106] = 0.0;
   out_1422952877034374174[107] = 0.0;
   out_1422952877034374174[108] = 0.0;
   out_1422952877034374174[109] = 0.0;
   out_1422952877034374174[110] = 0.0;
   out_1422952877034374174[111] = 0.0;
   out_1422952877034374174[112] = 0.0;
   out_1422952877034374174[113] = 0.0;
   out_1422952877034374174[114] = 1.0;
   out_1422952877034374174[115] = 0.0;
   out_1422952877034374174[116] = 0.0;
   out_1422952877034374174[117] = 0.0;
   out_1422952877034374174[118] = 0.0;
   out_1422952877034374174[119] = 0.0;
   out_1422952877034374174[120] = 0.0;
   out_1422952877034374174[121] = 0.0;
   out_1422952877034374174[122] = 0.0;
   out_1422952877034374174[123] = 0.0;
   out_1422952877034374174[124] = 0.0;
   out_1422952877034374174[125] = 0.0;
   out_1422952877034374174[126] = 0.0;
   out_1422952877034374174[127] = 0.0;
   out_1422952877034374174[128] = 0.0;
   out_1422952877034374174[129] = 0.0;
   out_1422952877034374174[130] = 0.0;
   out_1422952877034374174[131] = 0.0;
   out_1422952877034374174[132] = 0.0;
   out_1422952877034374174[133] = 1.0;
   out_1422952877034374174[134] = 0.0;
   out_1422952877034374174[135] = 0.0;
   out_1422952877034374174[136] = 0.0;
   out_1422952877034374174[137] = 0.0;
   out_1422952877034374174[138] = 0.0;
   out_1422952877034374174[139] = 0.0;
   out_1422952877034374174[140] = 0.0;
   out_1422952877034374174[141] = 0.0;
   out_1422952877034374174[142] = 0.0;
   out_1422952877034374174[143] = 0.0;
   out_1422952877034374174[144] = 0.0;
   out_1422952877034374174[145] = 0.0;
   out_1422952877034374174[146] = 0.0;
   out_1422952877034374174[147] = 0.0;
   out_1422952877034374174[148] = 0.0;
   out_1422952877034374174[149] = 0.0;
   out_1422952877034374174[150] = 0.0;
   out_1422952877034374174[151] = 0.0;
   out_1422952877034374174[152] = 1.0;
   out_1422952877034374174[153] = 0.0;
   out_1422952877034374174[154] = 0.0;
   out_1422952877034374174[155] = 0.0;
   out_1422952877034374174[156] = 0.0;
   out_1422952877034374174[157] = 0.0;
   out_1422952877034374174[158] = 0.0;
   out_1422952877034374174[159] = 0.0;
   out_1422952877034374174[160] = 0.0;
   out_1422952877034374174[161] = 0.0;
   out_1422952877034374174[162] = 0.0;
   out_1422952877034374174[163] = 0.0;
   out_1422952877034374174[164] = 0.0;
   out_1422952877034374174[165] = 0.0;
   out_1422952877034374174[166] = 0.0;
   out_1422952877034374174[167] = 0.0;
   out_1422952877034374174[168] = 0.0;
   out_1422952877034374174[169] = 0.0;
   out_1422952877034374174[170] = 0.0;
   out_1422952877034374174[171] = 1.0;
   out_1422952877034374174[172] = 0.0;
   out_1422952877034374174[173] = 0.0;
   out_1422952877034374174[174] = 0.0;
   out_1422952877034374174[175] = 0.0;
   out_1422952877034374174[176] = 0.0;
   out_1422952877034374174[177] = 0.0;
   out_1422952877034374174[178] = 0.0;
   out_1422952877034374174[179] = 0.0;
   out_1422952877034374174[180] = 0.0;
   out_1422952877034374174[181] = 0.0;
   out_1422952877034374174[182] = 0.0;
   out_1422952877034374174[183] = 0.0;
   out_1422952877034374174[184] = 0.0;
   out_1422952877034374174[185] = 0.0;
   out_1422952877034374174[186] = 0.0;
   out_1422952877034374174[187] = 0.0;
   out_1422952877034374174[188] = 0.0;
   out_1422952877034374174[189] = 0.0;
   out_1422952877034374174[190] = 1.0;
   out_1422952877034374174[191] = 0.0;
   out_1422952877034374174[192] = 0.0;
   out_1422952877034374174[193] = 0.0;
   out_1422952877034374174[194] = 0.0;
   out_1422952877034374174[195] = 0.0;
   out_1422952877034374174[196] = 0.0;
   out_1422952877034374174[197] = 0.0;
   out_1422952877034374174[198] = 0.0;
   out_1422952877034374174[199] = 0.0;
   out_1422952877034374174[200] = 0.0;
   out_1422952877034374174[201] = 0.0;
   out_1422952877034374174[202] = 0.0;
   out_1422952877034374174[203] = 0.0;
   out_1422952877034374174[204] = 0.0;
   out_1422952877034374174[205] = 0.0;
   out_1422952877034374174[206] = 0.0;
   out_1422952877034374174[207] = 0.0;
   out_1422952877034374174[208] = 0.0;
   out_1422952877034374174[209] = 1.0;
   out_1422952877034374174[210] = 0.0;
   out_1422952877034374174[211] = 0.0;
   out_1422952877034374174[212] = 0.0;
   out_1422952877034374174[213] = 0.0;
   out_1422952877034374174[214] = 0.0;
   out_1422952877034374174[215] = 0.0;
   out_1422952877034374174[216] = 0.0;
   out_1422952877034374174[217] = 0.0;
   out_1422952877034374174[218] = 0.0;
   out_1422952877034374174[219] = 0.0;
   out_1422952877034374174[220] = 0.0;
   out_1422952877034374174[221] = 0.0;
   out_1422952877034374174[222] = 0.0;
   out_1422952877034374174[223] = 0.0;
   out_1422952877034374174[224] = 0.0;
   out_1422952877034374174[225] = 0.0;
   out_1422952877034374174[226] = 0.0;
   out_1422952877034374174[227] = 0.0;
   out_1422952877034374174[228] = 1.0;
   out_1422952877034374174[229] = 0.0;
   out_1422952877034374174[230] = 0.0;
   out_1422952877034374174[231] = 0.0;
   out_1422952877034374174[232] = 0.0;
   out_1422952877034374174[233] = 0.0;
   out_1422952877034374174[234] = 0.0;
   out_1422952877034374174[235] = 0.0;
   out_1422952877034374174[236] = 0.0;
   out_1422952877034374174[237] = 0.0;
   out_1422952877034374174[238] = 0.0;
   out_1422952877034374174[239] = 0.0;
   out_1422952877034374174[240] = 0.0;
   out_1422952877034374174[241] = 0.0;
   out_1422952877034374174[242] = 0.0;
   out_1422952877034374174[243] = 0.0;
   out_1422952877034374174[244] = 0.0;
   out_1422952877034374174[245] = 0.0;
   out_1422952877034374174[246] = 0.0;
   out_1422952877034374174[247] = 1.0;
   out_1422952877034374174[248] = 0.0;
   out_1422952877034374174[249] = 0.0;
   out_1422952877034374174[250] = 0.0;
   out_1422952877034374174[251] = 0.0;
   out_1422952877034374174[252] = 0.0;
   out_1422952877034374174[253] = 0.0;
   out_1422952877034374174[254] = 0.0;
   out_1422952877034374174[255] = 0.0;
   out_1422952877034374174[256] = 0.0;
   out_1422952877034374174[257] = 0.0;
   out_1422952877034374174[258] = 0.0;
   out_1422952877034374174[259] = 0.0;
   out_1422952877034374174[260] = 0.0;
   out_1422952877034374174[261] = 0.0;
   out_1422952877034374174[262] = 0.0;
   out_1422952877034374174[263] = 0.0;
   out_1422952877034374174[264] = 0.0;
   out_1422952877034374174[265] = 0.0;
   out_1422952877034374174[266] = 1.0;
   out_1422952877034374174[267] = 0.0;
   out_1422952877034374174[268] = 0.0;
   out_1422952877034374174[269] = 0.0;
   out_1422952877034374174[270] = 0.0;
   out_1422952877034374174[271] = 0.0;
   out_1422952877034374174[272] = 0.0;
   out_1422952877034374174[273] = 0.0;
   out_1422952877034374174[274] = 0.0;
   out_1422952877034374174[275] = 0.0;
   out_1422952877034374174[276] = 0.0;
   out_1422952877034374174[277] = 0.0;
   out_1422952877034374174[278] = 0.0;
   out_1422952877034374174[279] = 0.0;
   out_1422952877034374174[280] = 0.0;
   out_1422952877034374174[281] = 0.0;
   out_1422952877034374174[282] = 0.0;
   out_1422952877034374174[283] = 0.0;
   out_1422952877034374174[284] = 0.0;
   out_1422952877034374174[285] = 1.0;
   out_1422952877034374174[286] = 0.0;
   out_1422952877034374174[287] = 0.0;
   out_1422952877034374174[288] = 0.0;
   out_1422952877034374174[289] = 0.0;
   out_1422952877034374174[290] = 0.0;
   out_1422952877034374174[291] = 0.0;
   out_1422952877034374174[292] = 0.0;
   out_1422952877034374174[293] = 0.0;
   out_1422952877034374174[294] = 0.0;
   out_1422952877034374174[295] = 0.0;
   out_1422952877034374174[296] = 0.0;
   out_1422952877034374174[297] = 0.0;
   out_1422952877034374174[298] = 0.0;
   out_1422952877034374174[299] = 0.0;
   out_1422952877034374174[300] = 0.0;
   out_1422952877034374174[301] = 0.0;
   out_1422952877034374174[302] = 0.0;
   out_1422952877034374174[303] = 0.0;
   out_1422952877034374174[304] = 1.0;
   out_1422952877034374174[305] = 0.0;
   out_1422952877034374174[306] = 0.0;
   out_1422952877034374174[307] = 0.0;
   out_1422952877034374174[308] = 0.0;
   out_1422952877034374174[309] = 0.0;
   out_1422952877034374174[310] = 0.0;
   out_1422952877034374174[311] = 0.0;
   out_1422952877034374174[312] = 0.0;
   out_1422952877034374174[313] = 0.0;
   out_1422952877034374174[314] = 0.0;
   out_1422952877034374174[315] = 0.0;
   out_1422952877034374174[316] = 0.0;
   out_1422952877034374174[317] = 0.0;
   out_1422952877034374174[318] = 0.0;
   out_1422952877034374174[319] = 0.0;
   out_1422952877034374174[320] = 0.0;
   out_1422952877034374174[321] = 0.0;
   out_1422952877034374174[322] = 0.0;
   out_1422952877034374174[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7318212543475994456) {
   out_7318212543475994456[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7318212543475994456[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7318212543475994456[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7318212543475994456[3] = dt*state[12] + state[3];
   out_7318212543475994456[4] = dt*state[13] + state[4];
   out_7318212543475994456[5] = dt*state[14] + state[5];
   out_7318212543475994456[6] = state[6];
   out_7318212543475994456[7] = state[7];
   out_7318212543475994456[8] = state[8];
   out_7318212543475994456[9] = state[9];
   out_7318212543475994456[10] = state[10];
   out_7318212543475994456[11] = state[11];
   out_7318212543475994456[12] = state[12];
   out_7318212543475994456[13] = state[13];
   out_7318212543475994456[14] = state[14];
   out_7318212543475994456[15] = state[15];
   out_7318212543475994456[16] = state[16];
   out_7318212543475994456[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4738803203701710697) {
   out_4738803203701710697[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4738803203701710697[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4738803203701710697[2] = 0;
   out_4738803203701710697[3] = 0;
   out_4738803203701710697[4] = 0;
   out_4738803203701710697[5] = 0;
   out_4738803203701710697[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4738803203701710697[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4738803203701710697[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4738803203701710697[9] = 0;
   out_4738803203701710697[10] = 0;
   out_4738803203701710697[11] = 0;
   out_4738803203701710697[12] = 0;
   out_4738803203701710697[13] = 0;
   out_4738803203701710697[14] = 0;
   out_4738803203701710697[15] = 0;
   out_4738803203701710697[16] = 0;
   out_4738803203701710697[17] = 0;
   out_4738803203701710697[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4738803203701710697[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4738803203701710697[20] = 0;
   out_4738803203701710697[21] = 0;
   out_4738803203701710697[22] = 0;
   out_4738803203701710697[23] = 0;
   out_4738803203701710697[24] = 0;
   out_4738803203701710697[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4738803203701710697[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4738803203701710697[27] = 0;
   out_4738803203701710697[28] = 0;
   out_4738803203701710697[29] = 0;
   out_4738803203701710697[30] = 0;
   out_4738803203701710697[31] = 0;
   out_4738803203701710697[32] = 0;
   out_4738803203701710697[33] = 0;
   out_4738803203701710697[34] = 0;
   out_4738803203701710697[35] = 0;
   out_4738803203701710697[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4738803203701710697[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4738803203701710697[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4738803203701710697[39] = 0;
   out_4738803203701710697[40] = 0;
   out_4738803203701710697[41] = 0;
   out_4738803203701710697[42] = 0;
   out_4738803203701710697[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4738803203701710697[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4738803203701710697[45] = 0;
   out_4738803203701710697[46] = 0;
   out_4738803203701710697[47] = 0;
   out_4738803203701710697[48] = 0;
   out_4738803203701710697[49] = 0;
   out_4738803203701710697[50] = 0;
   out_4738803203701710697[51] = 0;
   out_4738803203701710697[52] = 0;
   out_4738803203701710697[53] = 0;
   out_4738803203701710697[54] = 0;
   out_4738803203701710697[55] = 0;
   out_4738803203701710697[56] = 0;
   out_4738803203701710697[57] = 1;
   out_4738803203701710697[58] = 0;
   out_4738803203701710697[59] = 0;
   out_4738803203701710697[60] = 0;
   out_4738803203701710697[61] = 0;
   out_4738803203701710697[62] = 0;
   out_4738803203701710697[63] = 0;
   out_4738803203701710697[64] = 0;
   out_4738803203701710697[65] = 0;
   out_4738803203701710697[66] = dt;
   out_4738803203701710697[67] = 0;
   out_4738803203701710697[68] = 0;
   out_4738803203701710697[69] = 0;
   out_4738803203701710697[70] = 0;
   out_4738803203701710697[71] = 0;
   out_4738803203701710697[72] = 0;
   out_4738803203701710697[73] = 0;
   out_4738803203701710697[74] = 0;
   out_4738803203701710697[75] = 0;
   out_4738803203701710697[76] = 1;
   out_4738803203701710697[77] = 0;
   out_4738803203701710697[78] = 0;
   out_4738803203701710697[79] = 0;
   out_4738803203701710697[80] = 0;
   out_4738803203701710697[81] = 0;
   out_4738803203701710697[82] = 0;
   out_4738803203701710697[83] = 0;
   out_4738803203701710697[84] = 0;
   out_4738803203701710697[85] = dt;
   out_4738803203701710697[86] = 0;
   out_4738803203701710697[87] = 0;
   out_4738803203701710697[88] = 0;
   out_4738803203701710697[89] = 0;
   out_4738803203701710697[90] = 0;
   out_4738803203701710697[91] = 0;
   out_4738803203701710697[92] = 0;
   out_4738803203701710697[93] = 0;
   out_4738803203701710697[94] = 0;
   out_4738803203701710697[95] = 1;
   out_4738803203701710697[96] = 0;
   out_4738803203701710697[97] = 0;
   out_4738803203701710697[98] = 0;
   out_4738803203701710697[99] = 0;
   out_4738803203701710697[100] = 0;
   out_4738803203701710697[101] = 0;
   out_4738803203701710697[102] = 0;
   out_4738803203701710697[103] = 0;
   out_4738803203701710697[104] = dt;
   out_4738803203701710697[105] = 0;
   out_4738803203701710697[106] = 0;
   out_4738803203701710697[107] = 0;
   out_4738803203701710697[108] = 0;
   out_4738803203701710697[109] = 0;
   out_4738803203701710697[110] = 0;
   out_4738803203701710697[111] = 0;
   out_4738803203701710697[112] = 0;
   out_4738803203701710697[113] = 0;
   out_4738803203701710697[114] = 1;
   out_4738803203701710697[115] = 0;
   out_4738803203701710697[116] = 0;
   out_4738803203701710697[117] = 0;
   out_4738803203701710697[118] = 0;
   out_4738803203701710697[119] = 0;
   out_4738803203701710697[120] = 0;
   out_4738803203701710697[121] = 0;
   out_4738803203701710697[122] = 0;
   out_4738803203701710697[123] = 0;
   out_4738803203701710697[124] = 0;
   out_4738803203701710697[125] = 0;
   out_4738803203701710697[126] = 0;
   out_4738803203701710697[127] = 0;
   out_4738803203701710697[128] = 0;
   out_4738803203701710697[129] = 0;
   out_4738803203701710697[130] = 0;
   out_4738803203701710697[131] = 0;
   out_4738803203701710697[132] = 0;
   out_4738803203701710697[133] = 1;
   out_4738803203701710697[134] = 0;
   out_4738803203701710697[135] = 0;
   out_4738803203701710697[136] = 0;
   out_4738803203701710697[137] = 0;
   out_4738803203701710697[138] = 0;
   out_4738803203701710697[139] = 0;
   out_4738803203701710697[140] = 0;
   out_4738803203701710697[141] = 0;
   out_4738803203701710697[142] = 0;
   out_4738803203701710697[143] = 0;
   out_4738803203701710697[144] = 0;
   out_4738803203701710697[145] = 0;
   out_4738803203701710697[146] = 0;
   out_4738803203701710697[147] = 0;
   out_4738803203701710697[148] = 0;
   out_4738803203701710697[149] = 0;
   out_4738803203701710697[150] = 0;
   out_4738803203701710697[151] = 0;
   out_4738803203701710697[152] = 1;
   out_4738803203701710697[153] = 0;
   out_4738803203701710697[154] = 0;
   out_4738803203701710697[155] = 0;
   out_4738803203701710697[156] = 0;
   out_4738803203701710697[157] = 0;
   out_4738803203701710697[158] = 0;
   out_4738803203701710697[159] = 0;
   out_4738803203701710697[160] = 0;
   out_4738803203701710697[161] = 0;
   out_4738803203701710697[162] = 0;
   out_4738803203701710697[163] = 0;
   out_4738803203701710697[164] = 0;
   out_4738803203701710697[165] = 0;
   out_4738803203701710697[166] = 0;
   out_4738803203701710697[167] = 0;
   out_4738803203701710697[168] = 0;
   out_4738803203701710697[169] = 0;
   out_4738803203701710697[170] = 0;
   out_4738803203701710697[171] = 1;
   out_4738803203701710697[172] = 0;
   out_4738803203701710697[173] = 0;
   out_4738803203701710697[174] = 0;
   out_4738803203701710697[175] = 0;
   out_4738803203701710697[176] = 0;
   out_4738803203701710697[177] = 0;
   out_4738803203701710697[178] = 0;
   out_4738803203701710697[179] = 0;
   out_4738803203701710697[180] = 0;
   out_4738803203701710697[181] = 0;
   out_4738803203701710697[182] = 0;
   out_4738803203701710697[183] = 0;
   out_4738803203701710697[184] = 0;
   out_4738803203701710697[185] = 0;
   out_4738803203701710697[186] = 0;
   out_4738803203701710697[187] = 0;
   out_4738803203701710697[188] = 0;
   out_4738803203701710697[189] = 0;
   out_4738803203701710697[190] = 1;
   out_4738803203701710697[191] = 0;
   out_4738803203701710697[192] = 0;
   out_4738803203701710697[193] = 0;
   out_4738803203701710697[194] = 0;
   out_4738803203701710697[195] = 0;
   out_4738803203701710697[196] = 0;
   out_4738803203701710697[197] = 0;
   out_4738803203701710697[198] = 0;
   out_4738803203701710697[199] = 0;
   out_4738803203701710697[200] = 0;
   out_4738803203701710697[201] = 0;
   out_4738803203701710697[202] = 0;
   out_4738803203701710697[203] = 0;
   out_4738803203701710697[204] = 0;
   out_4738803203701710697[205] = 0;
   out_4738803203701710697[206] = 0;
   out_4738803203701710697[207] = 0;
   out_4738803203701710697[208] = 0;
   out_4738803203701710697[209] = 1;
   out_4738803203701710697[210] = 0;
   out_4738803203701710697[211] = 0;
   out_4738803203701710697[212] = 0;
   out_4738803203701710697[213] = 0;
   out_4738803203701710697[214] = 0;
   out_4738803203701710697[215] = 0;
   out_4738803203701710697[216] = 0;
   out_4738803203701710697[217] = 0;
   out_4738803203701710697[218] = 0;
   out_4738803203701710697[219] = 0;
   out_4738803203701710697[220] = 0;
   out_4738803203701710697[221] = 0;
   out_4738803203701710697[222] = 0;
   out_4738803203701710697[223] = 0;
   out_4738803203701710697[224] = 0;
   out_4738803203701710697[225] = 0;
   out_4738803203701710697[226] = 0;
   out_4738803203701710697[227] = 0;
   out_4738803203701710697[228] = 1;
   out_4738803203701710697[229] = 0;
   out_4738803203701710697[230] = 0;
   out_4738803203701710697[231] = 0;
   out_4738803203701710697[232] = 0;
   out_4738803203701710697[233] = 0;
   out_4738803203701710697[234] = 0;
   out_4738803203701710697[235] = 0;
   out_4738803203701710697[236] = 0;
   out_4738803203701710697[237] = 0;
   out_4738803203701710697[238] = 0;
   out_4738803203701710697[239] = 0;
   out_4738803203701710697[240] = 0;
   out_4738803203701710697[241] = 0;
   out_4738803203701710697[242] = 0;
   out_4738803203701710697[243] = 0;
   out_4738803203701710697[244] = 0;
   out_4738803203701710697[245] = 0;
   out_4738803203701710697[246] = 0;
   out_4738803203701710697[247] = 1;
   out_4738803203701710697[248] = 0;
   out_4738803203701710697[249] = 0;
   out_4738803203701710697[250] = 0;
   out_4738803203701710697[251] = 0;
   out_4738803203701710697[252] = 0;
   out_4738803203701710697[253] = 0;
   out_4738803203701710697[254] = 0;
   out_4738803203701710697[255] = 0;
   out_4738803203701710697[256] = 0;
   out_4738803203701710697[257] = 0;
   out_4738803203701710697[258] = 0;
   out_4738803203701710697[259] = 0;
   out_4738803203701710697[260] = 0;
   out_4738803203701710697[261] = 0;
   out_4738803203701710697[262] = 0;
   out_4738803203701710697[263] = 0;
   out_4738803203701710697[264] = 0;
   out_4738803203701710697[265] = 0;
   out_4738803203701710697[266] = 1;
   out_4738803203701710697[267] = 0;
   out_4738803203701710697[268] = 0;
   out_4738803203701710697[269] = 0;
   out_4738803203701710697[270] = 0;
   out_4738803203701710697[271] = 0;
   out_4738803203701710697[272] = 0;
   out_4738803203701710697[273] = 0;
   out_4738803203701710697[274] = 0;
   out_4738803203701710697[275] = 0;
   out_4738803203701710697[276] = 0;
   out_4738803203701710697[277] = 0;
   out_4738803203701710697[278] = 0;
   out_4738803203701710697[279] = 0;
   out_4738803203701710697[280] = 0;
   out_4738803203701710697[281] = 0;
   out_4738803203701710697[282] = 0;
   out_4738803203701710697[283] = 0;
   out_4738803203701710697[284] = 0;
   out_4738803203701710697[285] = 1;
   out_4738803203701710697[286] = 0;
   out_4738803203701710697[287] = 0;
   out_4738803203701710697[288] = 0;
   out_4738803203701710697[289] = 0;
   out_4738803203701710697[290] = 0;
   out_4738803203701710697[291] = 0;
   out_4738803203701710697[292] = 0;
   out_4738803203701710697[293] = 0;
   out_4738803203701710697[294] = 0;
   out_4738803203701710697[295] = 0;
   out_4738803203701710697[296] = 0;
   out_4738803203701710697[297] = 0;
   out_4738803203701710697[298] = 0;
   out_4738803203701710697[299] = 0;
   out_4738803203701710697[300] = 0;
   out_4738803203701710697[301] = 0;
   out_4738803203701710697[302] = 0;
   out_4738803203701710697[303] = 0;
   out_4738803203701710697[304] = 1;
   out_4738803203701710697[305] = 0;
   out_4738803203701710697[306] = 0;
   out_4738803203701710697[307] = 0;
   out_4738803203701710697[308] = 0;
   out_4738803203701710697[309] = 0;
   out_4738803203701710697[310] = 0;
   out_4738803203701710697[311] = 0;
   out_4738803203701710697[312] = 0;
   out_4738803203701710697[313] = 0;
   out_4738803203701710697[314] = 0;
   out_4738803203701710697[315] = 0;
   out_4738803203701710697[316] = 0;
   out_4738803203701710697[317] = 0;
   out_4738803203701710697[318] = 0;
   out_4738803203701710697[319] = 0;
   out_4738803203701710697[320] = 0;
   out_4738803203701710697[321] = 0;
   out_4738803203701710697[322] = 0;
   out_4738803203701710697[323] = 1;
}
void h_4(double *state, double *unused, double *out_9186185830648437017) {
   out_9186185830648437017[0] = state[6] + state[9];
   out_9186185830648437017[1] = state[7] + state[10];
   out_9186185830648437017[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6678588961938038376) {
   out_6678588961938038376[0] = 0;
   out_6678588961938038376[1] = 0;
   out_6678588961938038376[2] = 0;
   out_6678588961938038376[3] = 0;
   out_6678588961938038376[4] = 0;
   out_6678588961938038376[5] = 0;
   out_6678588961938038376[6] = 1;
   out_6678588961938038376[7] = 0;
   out_6678588961938038376[8] = 0;
   out_6678588961938038376[9] = 1;
   out_6678588961938038376[10] = 0;
   out_6678588961938038376[11] = 0;
   out_6678588961938038376[12] = 0;
   out_6678588961938038376[13] = 0;
   out_6678588961938038376[14] = 0;
   out_6678588961938038376[15] = 0;
   out_6678588961938038376[16] = 0;
   out_6678588961938038376[17] = 0;
   out_6678588961938038376[18] = 0;
   out_6678588961938038376[19] = 0;
   out_6678588961938038376[20] = 0;
   out_6678588961938038376[21] = 0;
   out_6678588961938038376[22] = 0;
   out_6678588961938038376[23] = 0;
   out_6678588961938038376[24] = 0;
   out_6678588961938038376[25] = 1;
   out_6678588961938038376[26] = 0;
   out_6678588961938038376[27] = 0;
   out_6678588961938038376[28] = 1;
   out_6678588961938038376[29] = 0;
   out_6678588961938038376[30] = 0;
   out_6678588961938038376[31] = 0;
   out_6678588961938038376[32] = 0;
   out_6678588961938038376[33] = 0;
   out_6678588961938038376[34] = 0;
   out_6678588961938038376[35] = 0;
   out_6678588961938038376[36] = 0;
   out_6678588961938038376[37] = 0;
   out_6678588961938038376[38] = 0;
   out_6678588961938038376[39] = 0;
   out_6678588961938038376[40] = 0;
   out_6678588961938038376[41] = 0;
   out_6678588961938038376[42] = 0;
   out_6678588961938038376[43] = 0;
   out_6678588961938038376[44] = 1;
   out_6678588961938038376[45] = 0;
   out_6678588961938038376[46] = 0;
   out_6678588961938038376[47] = 1;
   out_6678588961938038376[48] = 0;
   out_6678588961938038376[49] = 0;
   out_6678588961938038376[50] = 0;
   out_6678588961938038376[51] = 0;
   out_6678588961938038376[52] = 0;
   out_6678588961938038376[53] = 0;
}
void h_10(double *state, double *unused, double *out_8470309336446010421) {
   out_8470309336446010421[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8470309336446010421[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8470309336446010421[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7519655911766019576) {
   out_7519655911766019576[0] = 0;
   out_7519655911766019576[1] = 9.8100000000000005*cos(state[1]);
   out_7519655911766019576[2] = 0;
   out_7519655911766019576[3] = 0;
   out_7519655911766019576[4] = -state[8];
   out_7519655911766019576[5] = state[7];
   out_7519655911766019576[6] = 0;
   out_7519655911766019576[7] = state[5];
   out_7519655911766019576[8] = -state[4];
   out_7519655911766019576[9] = 0;
   out_7519655911766019576[10] = 0;
   out_7519655911766019576[11] = 0;
   out_7519655911766019576[12] = 1;
   out_7519655911766019576[13] = 0;
   out_7519655911766019576[14] = 0;
   out_7519655911766019576[15] = 1;
   out_7519655911766019576[16] = 0;
   out_7519655911766019576[17] = 0;
   out_7519655911766019576[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7519655911766019576[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7519655911766019576[20] = 0;
   out_7519655911766019576[21] = state[8];
   out_7519655911766019576[22] = 0;
   out_7519655911766019576[23] = -state[6];
   out_7519655911766019576[24] = -state[5];
   out_7519655911766019576[25] = 0;
   out_7519655911766019576[26] = state[3];
   out_7519655911766019576[27] = 0;
   out_7519655911766019576[28] = 0;
   out_7519655911766019576[29] = 0;
   out_7519655911766019576[30] = 0;
   out_7519655911766019576[31] = 1;
   out_7519655911766019576[32] = 0;
   out_7519655911766019576[33] = 0;
   out_7519655911766019576[34] = 1;
   out_7519655911766019576[35] = 0;
   out_7519655911766019576[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7519655911766019576[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7519655911766019576[38] = 0;
   out_7519655911766019576[39] = -state[7];
   out_7519655911766019576[40] = state[6];
   out_7519655911766019576[41] = 0;
   out_7519655911766019576[42] = state[4];
   out_7519655911766019576[43] = -state[3];
   out_7519655911766019576[44] = 0;
   out_7519655911766019576[45] = 0;
   out_7519655911766019576[46] = 0;
   out_7519655911766019576[47] = 0;
   out_7519655911766019576[48] = 0;
   out_7519655911766019576[49] = 0;
   out_7519655911766019576[50] = 1;
   out_7519655911766019576[51] = 0;
   out_7519655911766019576[52] = 0;
   out_7519655911766019576[53] = 1;
}
void h_13(double *state, double *unused, double *out_6902459031457256651) {
   out_6902459031457256651[0] = state[3];
   out_6902459031457256651[1] = state[4];
   out_6902459031457256651[2] = state[5];
}
void H_13(double *state, double *unused, double *out_932042246378662553) {
   out_932042246378662553[0] = 0;
   out_932042246378662553[1] = 0;
   out_932042246378662553[2] = 0;
   out_932042246378662553[3] = 1;
   out_932042246378662553[4] = 0;
   out_932042246378662553[5] = 0;
   out_932042246378662553[6] = 0;
   out_932042246378662553[7] = 0;
   out_932042246378662553[8] = 0;
   out_932042246378662553[9] = 0;
   out_932042246378662553[10] = 0;
   out_932042246378662553[11] = 0;
   out_932042246378662553[12] = 0;
   out_932042246378662553[13] = 0;
   out_932042246378662553[14] = 0;
   out_932042246378662553[15] = 0;
   out_932042246378662553[16] = 0;
   out_932042246378662553[17] = 0;
   out_932042246378662553[18] = 0;
   out_932042246378662553[19] = 0;
   out_932042246378662553[20] = 0;
   out_932042246378662553[21] = 0;
   out_932042246378662553[22] = 1;
   out_932042246378662553[23] = 0;
   out_932042246378662553[24] = 0;
   out_932042246378662553[25] = 0;
   out_932042246378662553[26] = 0;
   out_932042246378662553[27] = 0;
   out_932042246378662553[28] = 0;
   out_932042246378662553[29] = 0;
   out_932042246378662553[30] = 0;
   out_932042246378662553[31] = 0;
   out_932042246378662553[32] = 0;
   out_932042246378662553[33] = 0;
   out_932042246378662553[34] = 0;
   out_932042246378662553[35] = 0;
   out_932042246378662553[36] = 0;
   out_932042246378662553[37] = 0;
   out_932042246378662553[38] = 0;
   out_932042246378662553[39] = 0;
   out_932042246378662553[40] = 0;
   out_932042246378662553[41] = 1;
   out_932042246378662553[42] = 0;
   out_932042246378662553[43] = 0;
   out_932042246378662553[44] = 0;
   out_932042246378662553[45] = 0;
   out_932042246378662553[46] = 0;
   out_932042246378662553[47] = 0;
   out_932042246378662553[48] = 0;
   out_932042246378662553[49] = 0;
   out_932042246378662553[50] = 0;
   out_932042246378662553[51] = 0;
   out_932042246378662553[52] = 0;
   out_932042246378662553[53] = 0;
}
void h_14(double *state, double *unused, double *out_7617576218549159782) {
   out_7617576218549159782[0] = state[6];
   out_7617576218549159782[1] = state[7];
   out_7617576218549159782[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2715348105598553847) {
   out_2715348105598553847[0] = 0;
   out_2715348105598553847[1] = 0;
   out_2715348105598553847[2] = 0;
   out_2715348105598553847[3] = 0;
   out_2715348105598553847[4] = 0;
   out_2715348105598553847[5] = 0;
   out_2715348105598553847[6] = 1;
   out_2715348105598553847[7] = 0;
   out_2715348105598553847[8] = 0;
   out_2715348105598553847[9] = 0;
   out_2715348105598553847[10] = 0;
   out_2715348105598553847[11] = 0;
   out_2715348105598553847[12] = 0;
   out_2715348105598553847[13] = 0;
   out_2715348105598553847[14] = 0;
   out_2715348105598553847[15] = 0;
   out_2715348105598553847[16] = 0;
   out_2715348105598553847[17] = 0;
   out_2715348105598553847[18] = 0;
   out_2715348105598553847[19] = 0;
   out_2715348105598553847[20] = 0;
   out_2715348105598553847[21] = 0;
   out_2715348105598553847[22] = 0;
   out_2715348105598553847[23] = 0;
   out_2715348105598553847[24] = 0;
   out_2715348105598553847[25] = 1;
   out_2715348105598553847[26] = 0;
   out_2715348105598553847[27] = 0;
   out_2715348105598553847[28] = 0;
   out_2715348105598553847[29] = 0;
   out_2715348105598553847[30] = 0;
   out_2715348105598553847[31] = 0;
   out_2715348105598553847[32] = 0;
   out_2715348105598553847[33] = 0;
   out_2715348105598553847[34] = 0;
   out_2715348105598553847[35] = 0;
   out_2715348105598553847[36] = 0;
   out_2715348105598553847[37] = 0;
   out_2715348105598553847[38] = 0;
   out_2715348105598553847[39] = 0;
   out_2715348105598553847[40] = 0;
   out_2715348105598553847[41] = 0;
   out_2715348105598553847[42] = 0;
   out_2715348105598553847[43] = 0;
   out_2715348105598553847[44] = 1;
   out_2715348105598553847[45] = 0;
   out_2715348105598553847[46] = 0;
   out_2715348105598553847[47] = 0;
   out_2715348105598553847[48] = 0;
   out_2715348105598553847[49] = 0;
   out_2715348105598553847[50] = 0;
   out_2715348105598553847[51] = 0;
   out_2715348105598553847[52] = 0;
   out_2715348105598553847[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_6858265802359206836) {
  err_fun(nom_x, delta_x, out_6858265802359206836);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_683644921736672263) {
  inv_err_fun(nom_x, true_x, out_683644921736672263);
}
void pose_H_mod_fun(double *state, double *out_1422952877034374174) {
  H_mod_fun(state, out_1422952877034374174);
}
void pose_f_fun(double *state, double dt, double *out_7318212543475994456) {
  f_fun(state,  dt, out_7318212543475994456);
}
void pose_F_fun(double *state, double dt, double *out_4738803203701710697) {
  F_fun(state,  dt, out_4738803203701710697);
}
void pose_h_4(double *state, double *unused, double *out_9186185830648437017) {
  h_4(state, unused, out_9186185830648437017);
}
void pose_H_4(double *state, double *unused, double *out_6678588961938038376) {
  H_4(state, unused, out_6678588961938038376);
}
void pose_h_10(double *state, double *unused, double *out_8470309336446010421) {
  h_10(state, unused, out_8470309336446010421);
}
void pose_H_10(double *state, double *unused, double *out_7519655911766019576) {
  H_10(state, unused, out_7519655911766019576);
}
void pose_h_13(double *state, double *unused, double *out_6902459031457256651) {
  h_13(state, unused, out_6902459031457256651);
}
void pose_H_13(double *state, double *unused, double *out_932042246378662553) {
  H_13(state, unused, out_932042246378662553);
}
void pose_h_14(double *state, double *unused, double *out_7617576218549159782) {
  h_14(state, unused, out_7617576218549159782);
}
void pose_H_14(double *state, double *unused, double *out_2715348105598553847) {
  H_14(state, unused, out_2715348105598553847);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
