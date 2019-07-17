#ifndef Parameters_h
#define Parameters_h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <TString.h>
using namespace std;

void InitBins(string);

extern int M2miss_bins, Mmiss_bins, miss_mom_bins, Emiss_bins, PT2miss_bins, PTmiss_bins, rel_time_bins, rel_time_bins, trig_time_bins;
extern int hms_mom_bins, shms_mom_bins, Q2_bins, eps_bins, xbj_bins, costh_bins, th_bins, mt_bins, W_bins, nu_bins, phi_bins, hms_beta_bins, shms_beta_bins;
extern int hms_en_bins, shms_en_bins, hms_delta_bins, shms_delta_bins, abs_time_bins, hms_th_bins, shms_th_bins, hms_phi_bins, shms_phi_bins;
extern float M2miss_min, Mmiss_min, Emiss_min, miss_mom_min, PTmiss_min, PT2miss_min, M2miss_max, Mmiss_max, miss_mom_max, Emiss_max, PTmiss_max, PT2miss_max;
extern float rel_time_min, abs_time_min, trig_time_min, rel_time_max, abs_time_max, trig_time_max;
extern float hms_mom_min, shms_mom_min, Q2_min, eps_min, xbj_min, costh_min, th_min, mt_min, W_min, nu_min, phi_min, hms_beta_min, shms_beta_min;
extern float hms_mom_max, shms_mom_max, Q2_max, eps_max, xbj_max, costh_max, th_max, mt_max, W_max, nu_max, phi_max, hms_beta_max, shms_beta_max;
extern float hms_en_min, hms_en_max, shms_en_min, shms_en_max, hms_cer_npe_min, shms_hg_npe_min, shms_aero_npe_min, hms_cer_npe_max, shms_hg_npe_max, shms_aero_npe_max;
extern float hms_delta_min, shms_delta_min, hms_th_min, shms_th_min, hms_phi_min, shms_phi_min, hms_delta_max, shms_delta_max, hms_th_max, shms_th_max, hms_phi_max, shms_phi_max;

#endif

