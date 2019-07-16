#!/bin/csh

echo "provide 1) run number 2) which process (vcs, elastic...) 3) target (LH2 or dummy)"

set run=$1
set ev="-1"
set proc=$2
set target=$3

source setup.csh
./hcana -b -q SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C\(`echo $run`\,`echo $ev`\)
/bin/cp REPORT_OUTPUT/COIN/PRODUCTION/replay_coin_production_${run}_${ev}.report Ana/datainfo/savedreports/ 
/home/cdaq/vcs2019/hallc_replay_vcs/Online/bin/monitor_singles -r ${run} -n ${ev}
echo $run >> Ana/datainfo/runlist/runlist.txt
/home/cdaq/vcs2019/hallc_replay_vcs/Ana/datainfo/get_runinfo.csh ${run} ${ev}
/home/cdaq/vcs2019/hallc_replay_vcs/Ana/HallCana "${proc}" "ana" "${target}" "${run}" -f "/home/cdaq/vcs2019/hallc_replay_vcs/ROOTfiles/coin_replay_production_${run}_${ev}.root"
echo "more lumi_${run}.dat: "
more /home/cdaq/vcs2019/hallc_replay_vcs/Ana/files/lumi_${run}.dat
echo "more timing_${run}.dat: "
more /home/cdaq/vcs2019/hallc_replay_vcs/Ana/files/timing_${run}.dat
echo "more missmass2_${run}.dat: "
more /home/cdaq/vcs2019/hallc_replay_vcs/Ana/files/missmass2_${run}.dat
echo "pop-up ana monitoring figures: "
evince /home/cdaq/vcs2019/hallc_replay_vcs/Ana/Results/ana_monitor_${run}.pdf
echo "reconstruction is done"
