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
void ResetBins(float (&inc)[96]);
extern int M2miss_bins, Mmiss_bins, miss_mom_bins, Emiss_bins, PT2miss_bins, PTmiss_bins, rel_time_bins, rel_time_bins, trig_time_bins;
extern int hms_mom_bins, shms_mom_bins, Q2_bins, eps_bins, xbj_bins, costh_bins, th_bins, mt_bins, W_bins, nu_bins, phi_bins, hms_beta_bins, shms_beta_bins;
extern int hms_en_bins, shms_en_bins, hms_delta_bins, shms_delta_bins, abs_time_bins, hms_th_bins, shms_th_bins, hms_phi_bins, shms_phi_bins;
extern float M2miss_min_hist, Mmiss_min_hist, Emiss_min_hist, miss_mom_min_hist, PTmiss_min_hist, PT2miss_min_hist, M2miss_max_hist, Mmiss_max_hist, miss_mom_max_hist, Emiss_max_hist, PTmiss_max_hist, PT2miss_max_hist;
extern float rel_time_min_hist, abs_time_min_hist, trig_time_min_hist, rel_time_max_hist, abs_time_max_hist, trig_time_max_hist;
extern float hms_mom_min_hist, shms_mom_min_hist, Q2_min_hist, eps_min_hist, xbj_min_hist, costh_min_hist, th_min_hist, mt_min_hist, W_min_hist, nu_min_hist, phi_min_hist, hms_beta_min_hist, shms_beta_min_hist;
extern float hms_mom_max_hist, shms_mom_max_hist, Q2_max_hist, eps_max_hist, xbj_max_hist, costh_max_hist, th_max_hist, mt_max_hist, W_max_hist, nu_max_hist, phi_max_hist, hms_beta_max_hist, shms_beta_max_hist;
extern float hms_en_min_hist, hms_en_max_hist, shms_en_min_hist, shms_en_max_hist, hms_cer_npe_min_hist, shms_hg_npe_min_hist, shms_aero_npe_min_hist, hms_cer_npe_max_hist, shms_hg_npe_max_hist, shms_aero_npe_max_hist;
extern float hms_delta_min_hist, shms_delta_min_hist, hms_th_min_hist, shms_th_min_hist, hms_phi_min_hist, shms_phi_min_hist, hms_delta_max_hist, shms_delta_max_hist, hms_th_max_hist, shms_th_max_hist, hms_phi_max_hist, shms_phi_max_hist;

#endif

