#!/bin/tcsh

foreach a ($argv)
      if (( $a == '-h' ) || ( $a == '--help' )) then
        echo "Use this script to run only the coincidence analyzer without running a full replay" 
      endif
end
if ( $# < 3 ) then
  echo "provide arguments: "
  echo "1) run number"
  echo "2) process: vcs, elastic, pi0, pi+LT..."
  echo "3) target: LH2 or dummy"
  exit
endif

set run=$1
set ev="-1"
set proc=$2
set target=$3
set dir=`pwd`

source setup.csh

echo "start replaying the run, full replay"
if ( "${proc}" == "pi+LT" || "${proc}" == "K+LT" || "${proc}" == "vcsLT" || "${proc}" == "elasticLT" || "${proc}" == "pi0LT" ) then
  echo "run replay with electron in HMS and proton in SHMS"
  ./hcana -b -q ${dir}/SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C\(`echo $run`\,`echo $ev`\) | tee ${dir}/REPORT_OUTPUT/COIN/PRODUCTION/printed_coin_production_${run}_${ev}.report
else 
  echo "run replay with electron in SHMS and proton in HMS"
  ./hcana -b -q ${dir}/SCRIPTS/COIN/PRODUCTION/replay_production_coin_pElec_hProt.C\(`echo $run`\,`echo $ev`\) | tee ${dir}/REPORT_OUTPUT/COIN/PRODUCTION/printed_coin_production_${run}_${ev}.report
endif

echo "save and read report files"
echo "build database"
/bin/cp ${dir}/REPORT_OUTPUT/COIN/PRODUCTION/replay_coin_production_${run}_${ev}.report ${dir}/Ana/datainfo/savedreports/ 
/bin/cp ${dir}/REPORT_OUTPUT/COIN/PRODUCTION/printed_coin_production_${run}_${ev}.report ${dir}/Ana/datainfo/savedreports/ 
${dir}/Online/bin/monitor_singles -r ${run} -n ${ev}

echo $run >> ${dir}/Ana/datainfo/runlist/runlist.txt
${dir}/Ana/datainfo/get_runinfo.csh ${run} ${ev}

echo "start analysis"
${dir}/Ana/HallCana "${proc}" "ana" "${target}" "${run}" -f "${dir}/ROOTfiles/coin_replay_production_${run}_${ev}.root"

echo "missing reference time: "
more ${dir}/Ana/datainfo/singleruninfo/missref_info_${run}.txt
echo "more lumi_${run}.dat: "
more ${dir}/Ana/files/lumi_${run}.dat
echo "more timing_${run}.dat: "
more ${dir}/Ana/files/timing_${run}.dat
echo "more missmass2_${run}.dat: "
more ${dir}/Ana/files/missmass2_${run}.dat
echo "pop-up ana monitoring figures: "
evince ${dir}/Ana/Results/ana_monitor_${run}.pdf &
echo "reconstruction is done"

