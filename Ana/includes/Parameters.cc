#define Parameters_cxx
#include "Parameters.h"
using namespace std;

int M2miss_bins, Mmiss_bins, miss_mom_bins, Emiss_bins, PT2miss_bins, PTmiss_bins, abs_time_bins, rel_time_bins, trig_time_bins;
int hms_mom_bins, shms_mom_bins, Q2_bins, eps_bins, xbj_bins, costh_bins, th_bins, mt_bins, W_bins, nu_bins, phi_bins, hms_beta_bins, shms_beta_bins;
int hms_en_bins, shms_en_bins, hms_delta_bins, shms_delta_bins, hms_th_bins, shms_th_bins, hms_phi_bins, shms_phi_bins;
float M2miss_min_hist, Mmiss_min_hist, Emiss_min_hist, miss_mom_min_hist, PTmiss_min_hist, PT2miss_min_hist, M2miss_max_hist, Mmiss_max_hist, miss_mom_max_hist, Emiss_max_hist, PTmiss_max_hist, PT2miss_max_hist;
float rel_time_min_hist, abs_time_min_hist, trig_time_min_hist, rel_time_max_hist, abs_time_max_hist, trig_time_max_hist;
float hms_mom_min_hist, shms_mom_min_hist, Q2_min_hist, eps_min_hist, xbj_min_hist, costh_min_hist, th_min_hist, mt_min_hist, W_min_hist, nu_min_hist, phi_min_hist, hms_beta_min_hist, shms_beta_min_hist;
float hms_mom_max_hist, shms_mom_max_hist, Q2_max_hist, eps_max_hist, xbj_max_hist, costh_max_hist, th_max_hist, mt_max_hist, W_max_hist, nu_max_hist, phi_max_hist, hms_beta_max_hist, shms_beta_max_hist;
float hms_en_min_hist, hms_en_max_hist, shms_en_min_hist, shms_en_max_hist, hms_cer_npe_min_hist, shms_hg_npe_min_hist, shms_aero_npe_min_hist, hms_cer_npe_max_hist, shms_hg_npe_max_hist, shms_aero_npe_max_hist;
float hms_delta_min_hist, shms_delta_min_hist, hms_th_min_hist, shms_th_min_hist, hms_phi_min_hist, shms_phi_min_hist, hms_delta_max_hist, shms_delta_max_hist, hms_th_max_hist, shms_th_max_hist, hms_phi_max_hist, shms_phi_max_hist;

void InitBins(string process){

  // here change histogram limits and binning for your process
  // "missing" distributions
  M2miss_min_hist=-0.5; M2miss_max_hist = 1.5; M2miss_bins=100;
  Mmiss_min_hist=-0.5; Mmiss_max_hist=1.5; Mmiss_bins=100;
  miss_mom_min_hist=0; miss_mom_max_hist=2; miss_mom_bins=100; 
  Emiss_min_hist=-0.5; Emiss_max_hist=1.5;Emiss_bins=100;
  PTmiss_min_hist=0; PTmiss_max_hist=1; PTmiss_bins=100;
  PT2miss_min_hist=0; PT2miss_max_hist=1; PT2miss_bins=100;

  // coincidence time distributions
  rel_time_min_hist=-30; rel_time_max_hist = 30; rel_time_bins =600;
  abs_time_min_hist = 0; abs_time_max_hist = 200; abs_time_bins = 600;
  trig_time_min_hist = -500; trig_time_max_hist= 500; trig_time_bins = 500;

  // momentum and kinematics
  hms_mom_min_hist = 0; hms_mom_max_hist=4.5; hms_mom_bins =100;
  shms_mom_min_hist = 0; shms_mom_max_hist=4.5; shms_mom_bins =100;
  Q2_min_hist=0; Q2_max_hist=1.5; Q2_bins = 100;
  eps_min_hist=0; eps_max_hist=1; eps_bins=100;
  xbj_min_hist=0; xbj_max_hist=1; xbj_bins=100;
  costh_min_hist=-1; costh_max_hist=1; costh_bins=100;
  th_min_hist=0; th_max_hist=180; th_bins=100;
  mt_min_hist=0; mt_max_hist=3; mt_bins=100;
  W_min_hist=0.5; W_max_hist=2.5; W_bins=100;
  nu_min_hist=0; nu_max_hist=4.5; nu_bins=100;
  phi_min_hist=0; phi_max_hist=360; phi_bins=100;
  hms_beta_min_hist=0.7; hms_beta_max_hist=1.3; hms_beta_bins=100;
  shms_beta_min_hist=0.7; shms_beta_max_hist=1.3; shms_beta_bins=100;

  // cherenkov and calorimeter deposit
  hms_en_min_hist=0; hms_en_max_hist=1.25; hms_en_bins=100;
  shms_en_min_hist=0; shms_en_max_hist=1.25; shms_en_bins=100;
  
  hms_cer_npe_min_hist=0; hms_cer_npe_max_hist=30; 
  shms_hg_npe_min_hist=0; shms_hg_npe_max_hist=30; 
  shms_aero_npe_min_hist=0; shms_aero_npe_max_hist=30; 
  
  // acceptance
  hms_delta_min_hist=-30; hms_delta_max_hist=30; hms_delta_bins=120;
  shms_delta_min_hist=-30; shms_delta_max_hist=50; shms_delta_bins=120;
  hms_th_min_hist=-12; hms_th_max_hist=12; hms_th_bins=120;
  shms_th_min_hist=-12; shms_th_max_hist=12; shms_th_bins=120;
  hms_phi_min_hist=-12; hms_phi_max_hist=12; hms_phi_bins=120;
  shms_phi_min_hist=-12; shms_phi_max_hist=12; shms_phi_bins=120;


  return;

}

