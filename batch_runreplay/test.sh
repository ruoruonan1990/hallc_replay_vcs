#! /bin/bash                                                                                                                                                                                                      

##### A batch submission script by Richard, insert the required script you want to batch run on line 51                                                                                                           
##### Modify required resources as needed!                                                                                                                                   

echo "Running as ${USER}"

##Output history file##                                                                                                                                                                                           
historyfile=hist.$( date "+%Y-%m-%d_%H-%M-%S" ).log

##Output batch script##                                                                                                                                                                                           
batch="${USER}_Job.txt"

##Input run numbers##                                                                                                                                                                                             
#inputFile="/group/c-kaonlt/USERS/${USER}/hallc_replay_lt/UTIL_BATCH/InputRunLists/ProductionLH2_ALL"
inputFile="/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/batch_runreplay/replay.runlist"
## Tape stub                                                                                                                                                                                                      
MSSstub='/mss/hallc/alphaE/raw/coin_all_%05d.dat'
raw='coin_all_%05d.dat'
auger="augerID.tmp"
runNum=8896

                tape_file=`printf $MSSstub $runNum`
				echo $tape_file
               ## tape_file=48762126336
                raw_file=`printf $raw $runNum`
				TapeFileSize=$(($(sed -n '3 s/^[^=]*= *//p' < $tape_file)))
	##	TapeFileSize=`expr 30275076096 / 1000000000`##
##	TapeFileSize=$(wc -c "$tape_file" | awk '{print $1}')
##	TapeFileSize=$(wc -c "/mss/hallc/alphaE/raw/coin_all_08896.dat" | awk '{print $1}')
##printf "%d\n" $TapeFileSize
#	TapeFileSize=$(($(wc -c < "$tape_file")))
##	TapeFileSize=`expr $TapeFileSize / 1000000000`
	echo "$TapeFileSize"
