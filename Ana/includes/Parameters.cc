#define Parameters_cxx
#include "Parameters.h"
using namespace std;

int M2miss_bins, Mmiss_bins, miss_mom_bins, Emiss_bins, PT2miss_bins, PTmiss_bins, abs_time_bins, rel_time_bins, trig_time_bins;
int hms_mom_bins, shms_mom_bins, Q2_bins, eps_bins, xbj_bins, costh_bins, th_bins, mt_bins, W_bins, nu_bins, phi_bins, hms_beta_bins, shms_beta_bins;
int hms_en_bins, shms_en_bins, hms_delta_bins, shms_delta_bins, hms_th_bins, shms_th_bins, hms_phi_bins, shms_phi_bins;
float M2miss_min, Mmiss_min, Emiss_min, miss_mom_min, PTmiss_min, PT2miss_min, M2miss_max, Mmiss_max, miss_mom_max, Emiss_max, PTmiss_max, PT2miss_max;
float rel_time_min, abs_time_min, trig_time_min, rel_time_max, abs_time_max, trig_time_max;
float hms_mom_min, shms_mom_min, Q2_min, eps_min, xbj_min, costh_min, th_min, mt_min, W_min, nu_min, phi_min, hms_beta_min, shms_beta_min;
float hms_mom_max, shms_mom_max, Q2_max, eps_max, xbj_max, costh_max, th_max, mt_max, W_max, nu_max, phi_max, hms_beta_max, shms_beta_max;
float hms_en_min, hms_en_max, shms_en_min, shms_en_max, hms_cer_npe_min, shms_hg_npe_min, shms_aero_npe_min, hms_cer_npe_max, shms_hg_npe_max, shms_aero_npe_max;
float hms_delta_min, shms_delta_min, hms_th_min, shms_th_min, hms_phi_min, shms_phi_min, hms_delta_max, shms_delta_max, hms_th_max, shms_th_max, hms_phi_max, shms_phi_max;

void InitBins(string process){

  // here change histogram limits and binning for your process
  // "missing" distributions
  M2miss_min=-0.5; M2miss_max = 1.5; M2miss_bins=100;
  Mmiss_min=-0.5; Mmiss_max=1.5; Mmiss_bins=100;
  miss_mom_min=0; miss_mom_max=2; miss_mom_bins=100; 
  Emiss_min=-0.5; Emiss_max=1.5;Emiss_bins=100;
  PTmiss_min=0; PTmiss_max=1; PTmiss_bins=100;
  PT2miss_min=0; PT2miss_max=1; PT2miss_bins=100;

  // coincidence time distributions
  rel_time_min=-30; rel_time_max = 30; rel_time_bins =600;
  abs_time_min = 0; abs_time_max = 200; abs_time_bins = 600;
  trig_time_min = -500; trig_time_max= 500; trig_time_bins = 500;

  // momentum and kinematics
  hms_mom_min = 0; hms_mom_max=4.5; hms_mom_bins =100;
  shms_mom_min = 0; shms_mom_max=4.5; shms_mom_bins =100;
  Q2_min=0; Q2_max=1.5; Q2_bins = 100;
  eps_min=0; eps_max=1; eps_bins=100;
  xbj_min=0; xbj_max=1; xbj_bins=100;
  costh_min=-1; costh_max=1; costh_bins=100;
  th_min=0; th_max=180; th_bins=100;
  mt_min=0; mt_max=3; mt_bins=100;
  W_min=0.5; W_max=2.5; W_bins=100;
  nu_min=0; nu_max=4.5; nu_bins=100;
  phi_min=0; phi_max=360; phi_bins=100;
  hms_beta_min=0.7; hms_beta_max=1.3; hms_beta_bins=100;
  shms_beta_min=0.7; shms_beta_max=1.3; shms_beta_bins=100;

  // cherenkov and calorimeter deposit
  hms_en_min=0; hms_en_max=1.25; hms_en_bins=100;
  shms_en_min=0; shms_en_max=1.25; shms_en_bins=100;
  
  hms_cer_npe_min=0; hms_cer_npe_max=30; 
  shms_hg_npe_min=0; shms_hg_npe_max=30; 
  shms_aero_npe_min=0; shms_aero_npe_max=30; 
  
  // acceptance
  hms_delta_min=-30; hms_delta_max=30; hms_delta_bins=120;
  shms_delta_min=-30; shms_delta_max=50; shms_delta_bins=120;
  hms_th_min=-12; hms_th_max=12; hms_th_bins=120;
  shms_th_min=-12; shms_th_max=12; shms_th_bins=120;
  hms_phi_min=-12; hms_phi_max=12; hms_phi_bins=120;
  shms_phi_min=-12; shms_phi_max=12; shms_phi_bins=120;


  return;

}

