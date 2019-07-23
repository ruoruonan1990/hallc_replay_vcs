void run_replay_auto(){

  //run number
  vector<int> runs ={8842,8843};
  //target type
  TString target[2] ={"LH2","dummy"};
  //event type
  TString evtype[2] ={"vcs","elastic"};
  int nruns =runs.size();

  //run replay
  for(int i=0;i<nruns;i++){

    std::cout <<Form("replaying run number :%d, event type : %s target: %s",runs[i],evtype[0].Data(),target[0].Data())<<endl;
    gSystem->Exec(Form("./run_full_replay.csh %d  %s %s",runs[i],evtype[0].Data(),target[0].Data()));

  }
}
