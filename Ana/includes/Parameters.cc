#define Parameters_cxx
#include "Parameters.h"
using namespace std;

float M2miss_min, M2miss_max, Mmiss_min, Mmiss_max;
int M2miss_bins, Mmiss_bins;

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
  abs_time_min = 0; abs_time_max = 200; rel_time_bins = 600;
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
  


  return;

}

