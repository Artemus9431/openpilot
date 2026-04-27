#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3178250485678476353);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1483572745860930452);
void car_H_mod_fun(double *state, double *out_492676199757732909);
void car_f_fun(double *state, double dt, double *out_50750306698385500);
void car_F_fun(double *state, double dt, double *out_8436903704575629648);
void car_h_25(double *state, double *unused, double *out_7349873263608033439);
void car_H_25(double *state, double *unused, double *out_998010641958029621);
void car_h_24(double *state, double *unused, double *out_5301420497854533783);
void car_H_24(double *state, double *unused, double *out_4999722720588538254);
void car_h_30(double *state, double *unused, double *out_7625067325892539328);
void car_H_30(double *state, double *unused, double *out_7914700983449646376);
void car_h_26(double *state, double *unused, double *out_3002881296436431014);
void car_H_26(double *state, double *unused, double *out_2743492676916026603);
void car_h_27(double *state, double *unused, double *out_5218585322542803089);
void car_H_27(double *state, double *unused, double *out_5739937671649221465);
void car_h_29(double *state, double *unused, double *out_5820003480156166643);
void car_H_29(double *state, double *unused, double *out_8424932327764038560);
void car_h_28(double *state, double *unused, double *out_216912054881957444);
void car_H_28(double *state, double *unused, double *out_1055824072289860142);
void car_h_31(double *state, double *unused, double *out_2600210128837778185);
void car_H_31(double *state, double *unused, double *out_1028656603834990049);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}