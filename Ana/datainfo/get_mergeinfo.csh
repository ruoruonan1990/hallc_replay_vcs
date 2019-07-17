#!/bin/tcsh

set rep=`pwd`
set runlist="${rep}/runlist/runlist.txt"

set run=`more $runlist | awk '{printf $1 " "}'`

set tri="${rep}/mergedruninfo/trigger_mergedruninfo.txt"
set rui="${rep}/mergedruninfo/run_mergedruninfo.txt"
set efi="${rep}/mergedruninfo/eff_mergedruninfo.txt"
rm $tri $rui $efi
touch $tri $rui $efi

foreach rr ($run)
	#if ( -z "${rep}/singleruninfo/run_info_${rr}.txt" ) then
		echo run=$rr
		cat ${rep}/singleruninfo/trigger_info_${rr}.txt >> $tri
		echo " " >> $tri
		cat ${rep}/singleruninfo/run_info_${rr}.txt >> $rui
		echo " " >> $rui
		cat ${rep}/singleruninfo/eff_info_${rr}.txt >> $efi
		echo " " >> $efi
	#endif
end
