#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3178250485678476353) {
   out_3178250485678476353[0] = delta_x[0] + nom_x[0];
   out_3178250485678476353[1] = delta_x[1] + nom_x[1];
   out_3178250485678476353[2] = delta_x[2] + nom_x[2];
   out_3178250485678476353[3] = delta_x[3] + nom_x[3];
   out_3178250485678476353[4] = delta_x[4] + nom_x[4];
   out_3178250485678476353[5] = delta_x[5] + nom_x[5];
   out_3178250485678476353[6] = delta_x[6] + nom_x[6];
   out_3178250485678476353[7] = delta_x[7] + nom_x[7];
   out_3178250485678476353[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1483572745860930452) {
   out_1483572745860930452[0] = -nom_x[0] + true_x[0];
   out_1483572745860930452[1] = -nom_x[1] + true_x[1];
   out_1483572745860930452[2] = -nom_x[2] + true_x[2];
   out_1483572745860930452[3] = -nom_x[3] + true_x[3];
   out_1483572745860930452[4] = -nom_x[4] + true_x[4];
   out_1483572745860930452[5] = -nom_x[5] + true_x[5];
   out_1483572745860930452[6] = -nom_x[6] + true_x[6];
   out_1483572745860930452[7] = -nom_x[7] + true_x[7];
   out_1483572745860930452[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_492676199757732909) {
   out_492676199757732909[0] = 1.0;
   out_492676199757732909[1] = 0.0;
   out_492676199757732909[2] = 0.0;
   out_492676199757732909[3] = 0.0;
   out_492676199757732909[4] = 0.0;
   out_492676199757732909[5] = 0.0;
   out_492676199757732909[6] = 0.0;
   out_492676199757732909[7] = 0.0;
   out_492676199757732909[8] = 0.0;
   out_492676199757732909[9] = 0.0;
   out_492676199757732909[10] = 1.0;
   out_492676199757732909[11] = 0.0;
   out_492676199757732909[12] = 0.0;
   out_492676199757732909[13] = 0.0;
   out_492676199757732909[14] = 0.0;
   out_492676199757732909[15] = 0.0;
   out_492676199757732909[16] = 0.0;
   out_492676199757732909[17] = 0.0;
   out_492676199757732909[18] = 0.0;
   out_492676199757732909[19] = 0.0;
   out_492676199757732909[20] = 1.0;
   out_492676199757732909[21] = 0.0;
   out_492676199757732909[22] = 0.0;
   out_492676199757732909[23] = 0.0;
   out_492676199757732909[24] = 0.0;
   out_492676199757732909[25] = 0.0;
   out_492676199757732909[26] = 0.0;
   out_492676199757732909[27] = 0.0;
   out_492676199757732909[28] = 0.0;
   out_492676199757732909[29] = 0.0;
   out_492676199757732909[30] = 1.0;
   out_492676199757732909[31] = 0.0;
   out_492676199757732909[32] = 0.0;
   out_492676199757732909[33] = 0.0;
   out_492676199757732909[34] = 0.0;
   out_492676199757732909[35] = 0.0;
   out_492676199757732909[36] = 0.0;
   out_492676199757732909[37] = 0.0;
   out_492676199757732909[38] = 0.0;
   out_492676199757732909[39] = 0.0;
   out_492676199757732909[40] = 1.0;
   out_492676199757732909[41] = 0.0;
   out_492676199757732909[42] = 0.0;
   out_492676199757732909[43] = 0.0;
   out_492676199757732909[44] = 0.0;
   out_492676199757732909[45] = 0.0;
   out_492676199757732909[46] = 0.0;
   out_492676199757732909[47] = 0.0;
   out_492676199757732909[48] = 0.0;
   out_492676199757732909[49] = 0.0;
   out_492676199757732909[50] = 1.0;
   out_492676199757732909[51] = 0.0;
   out_492676199757732909[52] = 0.0;
   out_492676199757732909[53] = 0.0;
   out_492676199757732909[54] = 0.0;
   out_492676199757732909[55] = 0.0;
   out_492676199757732909[56] = 0.0;
   out_492676199757732909[57] = 0.0;
   out_492676199757732909[58] = 0.0;
   out_492676199757732909[59] = 0.0;
   out_492676199757732909[60] = 1.0;
   out_492676199757732909[61] = 0.0;
   out_492676199757732909[62] = 0.0;
   out_492676199757732909[63] = 0.0;
   out_492676199757732909[64] = 0.0;
   out_492676199757732909[65] = 0.0;
   out_492676199757732909[66] = 0.0;
   out_492676199757732909[67] = 0.0;
   out_492676199757732909[68] = 0.0;
   out_492676199757732909[69] = 0.0;
   out_492676199757732909[70] = 1.0;
   out_492676199757732909[71] = 0.0;
   out_492676199757732909[72] = 0.0;
   out_492676199757732909[73] = 0.0;
   out_492676199757732909[74] = 0.0;
   out_492676199757732909[75] = 0.0;
   out_492676199757732909[76] = 0.0;
   out_492676199757732909[77] = 0.0;
   out_492676199757732909[78] = 0.0;
   out_492676199757732909[79] = 0.0;
   out_492676199757732909[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_50750306698385500) {
   out_50750306698385500[0] = state[0];
   out_50750306698385500[1] = state[1];
   out_50750306698385500[2] = state[2];
   out_50750306698385500[3] = state[3];
   out_50750306698385500[4] = state[4];
   out_50750306698385500[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_50750306698385500[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_50750306698385500[7] = state[7];
   out_50750306698385500[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8436903704575629648) {
   out_8436903704575629648[0] = 1;
   out_8436903704575629648[1] = 0;
   out_8436903704575629648[2] = 0;
   out_8436903704575629648[3] = 0;
   out_8436903704575629648[4] = 0;
   out_8436903704575629648[5] = 0;
   out_8436903704575629648[6] = 0;
   out_8436903704575629648[7] = 0;
   out_8436903704575629648[8] = 0;
   out_8436903704575629648[9] = 0;
   out_8436903704575629648[10] = 1;
   out_8436903704575629648[11] = 0;
   out_8436903704575629648[12] = 0;
   out_8436903704575629648[13] = 0;
   out_8436903704575629648[14] = 0;
   out_8436903704575629648[15] = 0;
   out_8436903704575629648[16] = 0;
   out_8436903704575629648[17] = 0;
   out_8436903704575629648[18] = 0;
   out_8436903704575629648[19] = 0;
   out_8436903704575629648[20] = 1;
   out_8436903704575629648[21] = 0;
   out_8436903704575629648[22] = 0;
   out_8436903704575629648[23] = 0;
   out_8436903704575629648[24] = 0;
   out_8436903704575629648[25] = 0;
   out_8436903704575629648[26] = 0;
   out_8436903704575629648[27] = 0;
   out_8436903704575629648[28] = 0;
   out_8436903704575629648[29] = 0;
   out_8436903704575629648[30] = 1;
   out_8436903704575629648[31] = 0;
   out_8436903704575629648[32] = 0;
   out_8436903704575629648[33] = 0;
   out_8436903704575629648[34] = 0;
   out_8436903704575629648[35] = 0;
   out_8436903704575629648[36] = 0;
   out_8436903704575629648[37] = 0;
   out_8436903704575629648[38] = 0;
   out_8436903704575629648[39] = 0;
   out_8436903704575629648[40] = 1;
   out_8436903704575629648[41] = 0;
   out_8436903704575629648[42] = 0;
   out_8436903704575629648[43] = 0;
   out_8436903704575629648[44] = 0;
   out_8436903704575629648[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8436903704575629648[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8436903704575629648[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8436903704575629648[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8436903704575629648[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8436903704575629648[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8436903704575629648[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8436903704575629648[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8436903704575629648[53] = -9.8100000000000005*dt;
   out_8436903704575629648[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8436903704575629648[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8436903704575629648[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8436903704575629648[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8436903704575629648[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8436903704575629648[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8436903704575629648[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8436903704575629648[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8436903704575629648[62] = 0;
   out_8436903704575629648[63] = 0;
   out_8436903704575629648[64] = 0;
   out_8436903704575629648[65] = 0;
   out_8436903704575629648[66] = 0;
   out_8436903704575629648[67] = 0;
   out_8436903704575629648[68] = 0;
   out_8436903704575629648[69] = 0;
   out_8436903704575629648[70] = 1;
   out_8436903704575629648[71] = 0;
   out_8436903704575629648[72] = 0;
   out_8436903704575629648[73] = 0;
   out_8436903704575629648[74] = 0;
   out_8436903704575629648[75] = 0;
   out_8436903704575629648[76] = 0;
   out_8436903704575629648[77] = 0;
   out_8436903704575629648[78] = 0;
   out_8436903704575629648[79] = 0;
   out_8436903704575629648[80] = 1;
}
void h_25(double *state, double *unused, double *out_7349873263608033439) {
   out_7349873263608033439[0] = state[6];
}
void H_25(double *state, double *unused, double *out_998010641958029621) {
   out_998010641958029621[0] = 0;
   out_998010641958029621[1] = 0;
   out_998010641958029621[2] = 0;
   out_998010641958029621[3] = 0;
   out_998010641958029621[4] = 0;
   out_998010641958029621[5] = 0;
   out_998010641958029621[6] = 1;
   out_998010641958029621[7] = 0;
   out_998010641958029621[8] = 0;
}
void h_24(double *state, double *unused, double *out_5301420497854533783) {
   out_5301420497854533783[0] = state[4];
   out_5301420497854533783[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4999722720588538254) {
   out_4999722720588538254[0] = 0;
   out_4999722720588538254[1] = 0;
   out_4999722720588538254[2] = 0;
   out_4999722720588538254[3] = 0;
   out_4999722720588538254[4] = 1;
   out_4999722720588538254[5] = 0;
   out_4999722720588538254[6] = 0;
   out_4999722720588538254[7] = 0;
   out_4999722720588538254[8] = 0;
   out_4999722720588538254[9] = 0;
   out_4999722720588538254[10] = 0;
   out_4999722720588538254[11] = 0;
   out_4999722720588538254[12] = 0;
   out_4999722720588538254[13] = 0;
   out_4999722720588538254[14] = 1;
   out_4999722720588538254[15] = 0;
   out_4999722720588538254[16] = 0;
   out_4999722720588538254[17] = 0;
}
void h_30(double *state, double *unused, double *out_7625067325892539328) {
   out_7625067325892539328[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7914700983449646376) {
   out_7914700983449646376[0] = 0;
   out_7914700983449646376[1] = 0;
   out_7914700983449646376[2] = 0;
   out_7914700983449646376[3] = 0;
   out_7914700983449646376[4] = 1;
   out_7914700983449646376[5] = 0;
   out_7914700983449646376[6] = 0;
   out_7914700983449646376[7] = 0;
   out_7914700983449646376[8] = 0;
}
void h_26(double *state, double *unused, double *out_3002881296436431014) {
   out_3002881296436431014[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2743492676916026603) {
   out_2743492676916026603[0] = 0;
   out_2743492676916026603[1] = 0;
   out_2743492676916026603[2] = 0;
   out_2743492676916026603[3] = 0;
   out_2743492676916026603[4] = 0;
   out_2743492676916026603[5] = 0;
   out_2743492676916026603[6] = 0;
   out_2743492676916026603[7] = 1;
   out_2743492676916026603[8] = 0;
}
void h_27(double *state, double *unused, double *out_5218585322542803089) {
   out_5218585322542803089[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5739937671649221465) {
   out_5739937671649221465[0] = 0;
   out_5739937671649221465[1] = 0;
   out_5739937671649221465[2] = 0;
   out_5739937671649221465[3] = 1;
   out_5739937671649221465[4] = 0;
   out_5739937671649221465[5] = 0;
   out_5739937671649221465[6] = 0;
   out_5739937671649221465[7] = 0;
   out_5739937671649221465[8] = 0;
}
void h_29(double *state, double *unused, double *out_5820003480156166643) {
   out_5820003480156166643[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8424932327764038560) {
   out_8424932327764038560[0] = 0;
   out_8424932327764038560[1] = 1;
   out_8424932327764038560[2] = 0;
   out_8424932327764038560[3] = 0;
   out_8424932327764038560[4] = 0;
   out_8424932327764038560[5] = 0;
   out_8424932327764038560[6] = 0;
   out_8424932327764038560[7] = 0;
   out_8424932327764038560[8] = 0;
}
void h_28(double *state, double *unused, double *out_216912054881957444) {
   out_216912054881957444[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1055824072289860142) {
   out_1055824072289860142[0] = 1;
   out_1055824072289860142[1] = 0;
   out_1055824072289860142[2] = 0;
   out_1055824072289860142[3] = 0;
   out_1055824072289860142[4] = 0;
   out_1055824072289860142[5] = 0;
   out_1055824072289860142[6] = 0;
   out_1055824072289860142[7] = 0;
   out_1055824072289860142[8] = 0;
}
void h_31(double *state, double *unused, double *out_2600210128837778185) {
   out_2600210128837778185[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1028656603834990049) {
   out_1028656603834990049[0] = 0;
   out_1028656603834990049[1] = 0;
   out_1028656603834990049[2] = 0;
   out_1028656603834990049[3] = 0;
   out_1028656603834990049[4] = 0;
   out_1028656603834990049[5] = 0;
   out_1028656603834990049[6] = 0;
   out_1028656603834990049[7] = 0;
   out_1028656603834990049[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_3178250485678476353) {
  err_fun(nom_x, delta_x, out_3178250485678476353);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1483572745860930452) {
  inv_err_fun(nom_x, true_x, out_1483572745860930452);
}
void car_H_mod_fun(double *state, double *out_492676199757732909) {
  H_mod_fun(state, out_492676199757732909);
}
void car_f_fun(double *state, double dt, double *out_50750306698385500) {
  f_fun(state,  dt, out_50750306698385500);
}
void car_F_fun(double *state, double dt, double *out_8436903704575629648) {
  F_fun(state,  dt, out_8436903704575629648);
}
void car_h_25(double *state, double *unused, double *out_7349873263608033439) {
  h_25(state, unused, out_7349873263608033439);
}
void car_H_25(double *state, double *unused, double *out_998010641958029621) {
  H_25(state, unused, out_998010641958029621);
}
void car_h_24(double *state, double *unused, double *out_5301420497854533783) {
  h_24(state, unused, out_5301420497854533783);
}
void car_H_24(double *state, double *unused, double *out_4999722720588538254) {
  H_24(state, unused, out_4999722720588538254);
}
void car_h_30(double *state, double *unused, double *out_7625067325892539328) {
  h_30(state, unused, out_7625067325892539328);
}
void car_H_30(double *state, double *unused, double *out_7914700983449646376) {
  H_30(state, unused, out_7914700983449646376);
}
void car_h_26(double *state, double *unused, double *out_3002881296436431014) {
  h_26(state, unused, out_3002881296436431014);
}
void car_H_26(double *state, double *unused, double *out_2743492676916026603) {
  H_26(state, unused, out_2743492676916026603);
}
void car_h_27(double *state, double *unused, double *out_5218585322542803089) {
  h_27(state, unused, out_5218585322542803089);
}
void car_H_27(double *state, double *unused, double *out_5739937671649221465) {
  H_27(state, unused, out_5739937671649221465);
}
void car_h_29(double *state, double *unused, double *out_5820003480156166643) {
  h_29(state, unused, out_5820003480156166643);
}
void car_H_29(double *state, double *unused, double *out_8424932327764038560) {
  H_29(state, unused, out_8424932327764038560);
}
void car_h_28(double *state, double *unused, double *out_216912054881957444) {
  h_28(state, unused, out_216912054881957444);
}
void car_H_28(double *state, double *unused, double *out_1055824072289860142) {
  H_28(state, unused, out_1055824072289860142);
}
void car_h_31(double *state, double *unused, double *out_2600210128837778185) {
  h_31(state, unused, out_2600210128837778185);
}
void car_H_31(double *state, double *unused, double *out_1028656603834990049) {
  H_31(state, unused, out_1028656603834990049);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
