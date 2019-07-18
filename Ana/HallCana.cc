/*
Main for Hall C real data analysis
Created July 5th, 2019
*/

#include <iostream>
#include <string.h>
#include "includes/ReadHallCData.h"
#include "includes/Parameters.h"

using namespace std;

int main (int argc, char **argv){

	if (argc<6) {
		cout<<"HELP / use arguments: "<<endl;
		cout<<"give arguments in following order"<<endl;
		cout<<"example: ./HallCana vcs ana LH2 8585 -f /home/cdaq/mboer/hallc_replay_vcs/ROOTfiles/coin_replay_production_8585_10000000.root"<<endl;
	
		cout<<"1) Process:"<<endl;
		cout<<"	  elastic or vcs or pi0 or pi+ or K+ = setup with e- in SHMS"<<endl;
		cout<<"	  elasticLT or vcsLT or pi0LT or pi+LT or K+LT = setup with e- in HMS"<<endl;
	
		cout<<"2) What to do:"<<endl;
		cout<<"   ana (create ana histograms and root file), reduce (only create root file)"<<endl;
	
		cout<<"3) which target: "<<endl;
		cout<<"LH2 or dummy"<<endl;

		cout<<"4) run number: "<<endl;
		
		cout<<"5) -f File name(s) or file list: "<<endl;
		cout<<"   -f or -files = single file or root file list given in header"<<endl;
		cout<<"   -l or -list = name of text file containing the list of root files"<<endl;
		cout<<"   provide only one name if the run is in a single root file, "<<endl;
		cout<<"   provide a serie or list of file names if the run is split into different root files"<<endl;
	        cout<<"   example: -f file1.root (file2.root file3.root) or -l list.txt (list.txt = file1.root file2.root...)"<<endl;
		
		cout<<"then provide the list of files txt or the root file(s) names"<<endl;

		cout<<" ... \n"<<endl;
		
		return 1;
	}

	string process=argv[1];
	string what=argv[2];
	string target=argv[3];
	int runID=atoi(argv[4]);	
	string test=argv[5];
	vector <string> filesarg;
	string listoffiles;
	string content="";
	string files_princ;
  float hc[96];
	// Read arguments
	
	 if (test=="-l" || test=="-list"){
    
          listoffiles=argv[6];
          ifstream listof;
          listof.open(Form("%s",listoffiles.c_str()));
  
           string ff; 

           while (listof.good()){
               if (!(listof>>ff)) break;
               filesarg.push_back(ff);
           }
           listof.close();
                
           cout<<"name of root files in: "<<listoffiles<<endl;
           cout<<"files= "<<endl;
           for (int kk=0;kk<filesarg.size();kk++){
            	cout<< ", "<<filesarg[kk] ;
            }
            
     } else if (test=="-f" || test=="-files") {
    
            int nn = 6;
            for (char **arg=argv+6; *arg; ++arg) {
    
                string check =  string(*arg); 
				if (check.compare("-end") == 0
					|| check.compare("-f")==0
					|| check.compare("-ff")==0
					) break;
                filesarg.push_back(*arg);
                nn++;
            }
            
            if (filesarg.size()>0) cout << "list of file analyzed: " <<endl;
            for (int kk=0;kk<filesarg.size();kk++){
            	cout<< ", "<<filesarg[kk] ;
            }
     }

     cout<<" ... End of file list opening ... "<<endl;
        
        

	
	// Process the code
	cout<<"\n Start processing analyzis \n"<<endl;
	cout<<"Run number: "<<runID<<endl;
	cout<<"Parameters: \n what to do: "<<what<<" \n process: "<<process<<" \n target: "<<target<<endl;
	
	
	if (process.compare("elastic")==0 || process.compare("vcs")==0 || process.compare("pi0")==0
	    || process.compare("elasticLT")==0 || process.compare("vcsLT")==0 || process.compare("pi0LT")==0
	    || process.compare("K+LT")==0 || process.compare("K+")==0 
	    || process.compare("pi+LT")==0 || process.compare("pi+")==0
	    ) {
		cout<<"Analyze hallc coin reco data"<<endl;
		ReadHallCData RDD;
		if (what.compare("ana")==0 || what.compare("reduce")==0){
			
			cout<<">> start loop"<<endl;
			InitBins(process);
      ResetBins(hc);
      M2miss_min_hist=hc[0]; M2miss_max_hist = hc[1]; M2miss_bins=(int)hc[2]; Mmiss_min_hist=hc[3]; Mmiss_max_hist=hc[4]; Mmiss_bins=(int)hc[5];
      miss_mom_min_hist=hc[6]; miss_mom_max_hist=hc[7]; miss_mom_bins= (int) hc[8]; Emiss_min_hist=hc[9]; Emiss_max_hist=hc[10];Emiss_bins= (int) hc[11];
      PTmiss_min_hist=hc[12]; PTmiss_max_hist=hc[13]; PTmiss_bins= (int) hc[14]; PT2miss_min_hist=hc[15];; PT2miss_max_hist=hc[16]; PT2miss_bins= (int) hc[17];
      rel_time_min_hist=  hc[18]; rel_time_max_hist = hc[19]; rel_time_bins = (int) hc[20]; abs_time_min_hist = hc[21]; abs_time_max_hist = hc[22]; abs_time_bins =  (int) hc[23];
      trig_time_min_hist = hc[24]; trig_time_max_hist= hc[25]; trig_time_bins =  (int) hc[26]; hms_mom_min_hist = hc[27]; hms_mom_max_hist=hc[28]; hms_mom_bins = (int) hc[29];
      shms_mom_min_hist = hc[30]; shms_mom_max_hist=hc[31]; shms_mom_bins = (int) hc[32]; Q2_min_hist=hc[33]; Q2_max_hist=hc[34]; Q2_bins =  (int) hc[35];
      eps_min_hist=hc[36]; eps_max_hist=hc[37]; eps_bins= (int) hc[38]; xbj_min_hist=hc[39]; xbj_max_hist=hc[40]; xbj_bins= (int) hc[41];
      costh_min_hist=hc[42]; costh_max_hist=hc[43]; costh_bins= (int) hc[44]; th_min_hist=hc[45]; th_max_hist=hc[46]; th_bins= (int) hc[47];
      mt_min_hist=hc[48]; mt_max_hist=hc[49]; mt_bins= (int) hc[50]; W_min_hist=hc[51]; W_max_hist=hc[52]; W_bins= (int) hc[53];
      nu_min_hist=hc[54]; nu_max_hist=hc[55]; nu_bins= (int) hc[56]; phi_min_hist=hc[57]; phi_max_hist=hc[58]; phi_bins= (int) hc[59];
      hms_beta_min_hist=hc[60]; hms_beta_max_hist=hc[61]; hms_beta_bins= (int) hc[62]; shms_beta_min_hist=hc[63]; shms_beta_max_hist=hc[64]; shms_beta_bins= (int) hc[65];
      hms_en_min_hist=hc[66]; hms_en_max_hist=hc[67]; hms_en_bins= (int) hc[68]; shms_en_min_hist=hc[69]; shms_en_max_hist=hc[70]; shms_en_bins= (int) hc[71];
      hms_cer_npe_min_hist=hc[72]; hms_cer_npe_max_hist = hc[73]; shms_hg_npe_min_hist=hc[74]; shms_hg_npe_max_hist=  hc[75]; 
      shms_aero_npe_min_hist=hc[76]; shms_aero_npe_max_hist=  hc[77];hms_delta_min_hist=hc[78]; hms_delta_max_hist=hc[79]; hms_delta_bins= (int) hc[80];
      shms_delta_min_hist=hc[81]; shms_delta_max_hist=hc[82]; shms_delta_bins= (int) hc[83]; hms_th_min_hist=hc[84]; hms_th_max_hist=hc[85]; hms_th_bins= (int) hc[86];
      shms_th_min_hist=hc[87]; shms_th_max_hist=hc[88]; shms_th_bins= (int) hc[89]; hms_phi_min_hist=hc[90]; hms_phi_max_hist=hc[91]; hms_phi_bins= (int) hc[92];
      shms_phi_min_hist=hc[93]; shms_phi_max_hist=hc[94]; shms_phi_bins= (int) hc[95];

      RDD.InitHist();
			RDD.Loop(filesarg, runID, process, what, target) ;
			if (what.compare("ana")==0) RDD.DrawHist(process, runID);
			RDD.DeleteHist();
			cout<<">> no more options"<<endl;
		}
	
	}

	cout<<"Analysis code, done."<<	endl;	
	return 0;
}


