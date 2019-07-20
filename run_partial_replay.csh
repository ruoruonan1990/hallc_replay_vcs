#!/bin/tcsh

foreach a ($argv)
      if (( $a == '-h' ) || ( $a == '--help' )) then
        echo "Use this script to run only the coincidence analyzer without running a full replay" 
      endif
end
if ( $# < 4 ) then
  echo "provide arguments: "
  echo "1) run number"
  echo "2) number of events"
  echo "3) process: vcs, elastic, pi0, pi+LT..."
  echo "4) target: LH2 or dummy"
  exit
endif

set run=$1
set ev=$2
set proc=$3
set target=$4
set dir=`pwd`
echo "pwd: $dir"
source setup.csh

echo "start replaying the run, full replay"
if ( "${proc}" == "pi+LT" || "${proc}" == "K+LT" || "${proc}" == "vcsLT" || "${proc}" == "elasticLT" || "${proc}" == "pi0LT" ) then
  echo "run replay with electron in HMS and proton in SHMS"
  ./hcana -b -q ${dir}/SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C\(`echo $run`\,`echo $ev`\) | tee ${dir}/REPORT_OUTPUT/COIN/PRODUCTION/printed_coin_production_${run}_${ev}.report
else 
  echo "run replay with electron in SHMS and proton in HMS"
  ./hcana -b -q ${dir}/SCRIPTS/COIN/PRODUCTION/replay_production_coin_pElec_hProt.C\(`echo $run`\,`echo $ev`\) | tee ${dir}/REPORT_OUTPUT/COIN/PRODUCTION/printed_coin_production_${run}_${ev}.report
endif

echo "read report files and build temporary database"
${dir}/Ana/datainfo/get_runinfo.csh ${run} ${ev}
${dir}/Online/bin/monitor_singles -r ${run} -n ${ev}

echo "start analysis"
${dir}/Ana/HallCana "${proc}" "ana" "${target}" "$1" -f "${dir}/ROOTfiles/coin_replay_production_${run}_${ev}.root"

echo "\n* more lumi_${run}.dat: [runID, lumi HMS (nb), lumi SHMS (nb), time HMS, time SHMS, current HMS, current SHMS]"
more ${dir}/Ana/files/lumi_${run}.dat
printf ">>> check if lumi HMS = lumi SHMS "
more ${dir}/Ana/files/lumi_${run}.dat | awk '{printf $2 " = " $3 " ?\n"}'
echo ">>> if not, check other numbers + database entry, if difference >1%, why?"

echo "\n* more timing_${run}.dat: lines = main peak, secondary, third"
echo "  | columns: runID time-delay (ns), N= integral with bkg subtracted, tot in peak, bkg t>tpeak, bkg t<tpeak, max peak"
more ${dir}/Ana/files/timing_${run}.dat
echo ">>> check if time-delay (ns) = 0 (up to .1): "
more ${dir}/Ana/files/timing_${run}.dat  | awk 'NR=1{printf "abs(" $2 ") < " 0.1 " ?\n"; exit}'
echo "If not: reset the delay and run once more Ana code"
printf ">>> check N>>bkg: " 
more ${dir}/Ana/files/timing_${run}.dat  | awk 'NR=1{printf $3 " >> 0 ?"; exit}'
printf "\ntot in peak>>bkg: "
more ${dir}/Ana/files/timing_${run}.dat  | awk 'NR=1{printf $4 " >> " $5 " (average bkg below) ? ; " $4 " >> " $6 " (average bkg above) ?"; exit}'
printf "\n>>> check stability of N/lumi (vs other runs for same kinematics): "
more ${dir}/Ana/files/timing_${run}.dat  | awk 'NR=1{printf $8 ;exit}'

echo "\n\n* more missmass2_${run}.dat: [runID, M2, fit integral, N at 3sigma, N/lumi]"
more ${dir}/Ana/files/missmass2_${run}.dat
echo ">>> check peak positions: "
more ${dir}/Ana/files/missmass2_${run}.dat | awk '{printf $2 " "}'
echo ">>>check if integral VCS/pi0 make sense for this kinematics, there is 2 peaks and no 3d peak (M2=-1 if no peak)"

echo "\n pop-up ana monitoring figures: "
evince ${dir}/Ana/Results/ana_monitor_${run}.pdf &
echo "reconstruction is done"

