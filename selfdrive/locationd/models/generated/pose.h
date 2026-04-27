#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6858265802359206836);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_683644921736672263);
void pose_H_mod_fun(double *state, double *out_1422952877034374174);
void pose_f_fun(double *state, double dt, double *out_7318212543475994456);
void pose_F_fun(double *state, double dt, double *out_4738803203701710697);
void pose_h_4(double *state, double *unused, double *out_9186185830648437017);
void pose_H_4(double *state, double *unused, double *out_6678588961938038376);
void pose_h_10(double *state, double *unused, double *out_8470309336446010421);
void pose_H_10(double *state, double *unused, double *out_7519655911766019576);
void pose_h_13(double *state, double *unused, double *out_6902459031457256651);
void pose_H_13(double *state, double *unused, double *out_932042246378662553);
void pose_h_14(double *state, double *unused, double *out_7617576218549159782);
void pose_H_14(double *state, double *unused, double *out_2715348105598553847);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}