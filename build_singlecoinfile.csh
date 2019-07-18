#!/bin/csh

foreach a ($argv)
      if (( $a == '-h' ) || ( $a == '--help' )) then
        echo "Use this script for testing replay and if you want to add more commands"
        echo "deprecated replay executable"
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

set type=$1
set target=$2
set run=$3
set ev=$4
set dir=`pwd`


source setup.csh
./hcana -b -q SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C\(`echo $run`\,`echo $ev`\)
${dir}/Ana/datainfo/get_runinfo.csh ${run} ${ev}
${dir}/Ana/HallCana "${type}" "ana" "${target}" "${run}" -f "${dir}/ROOTfiles/coin_replay_production_${run}_${ev}.root"
echo "more lumi_${run}.dat: "
more ${dir}/Ana/files/lumi_${run}.dat
echo "more timing_${run}.dat: "
more ${dir}/Ana/files/timing_${run}.dat
echo "more missmass2_${run}.dat: "
more ${dir}/Ana/files/missmass2_${run}.dat
echo "pop-up ana monitoring figures: "
evince ${dir}/Ana/Results/ana_monitor_${run}.pdf
echo "reconstruction is done"
