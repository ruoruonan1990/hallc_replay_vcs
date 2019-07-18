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


