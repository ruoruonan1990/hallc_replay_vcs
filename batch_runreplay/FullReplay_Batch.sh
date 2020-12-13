#!/bin/bash

echo "Starting Replay script"
echo "I take as arguments the Run Number and max number of events!"
RUNNUMBER=$1
process=$2
target=$3
MAXEVENTS=-1
### Check you've provided the an argument
if [[ $1 -eq "" ]]; then
    echo "I need a Run Number!"
    echo "Please provide a run number as input"
    exit 2
fi
#if [[ ${USER} = "cdaq" ]]; then
#    echo "Warning, running as cdaq."
#    echo "Please be sure you want to do this."
#    echo "Comment this section out and run again if you're sure."
#    exit 2
#fi          
#
## Set path depending upon hostname. Change or add more as needed  
#if [[ "${HOSTNAME}" = *"farm"* ]]; then  
#    REPLAYPATH="/u/group/alphaE/analysis_apps/hallc_replay_vcs"
#    if [[ "${HOSTNAME}" != *"ifarm"* ]]; then
#	source /site/12gev_phys/softenv.csh 2.1
#    fi
#    cd "/u/group/alphaE/analysis_apps/hallc_replay_vcs/hcana/"
#    source "/u/group/alphaE/analysis_apps/hallc_replay_vcs/hcana/setup.sh"
#    cd "$REPLAYPATH"
#    source "$REPLAYPATH/setup.csh"
#elif [[ "${HOSTNAME}" = *"cdaq"* ]]; then
#    REPLAYPATH="/home/cdaq/hallc-online/hallc_replay_lt"
#elif [[ "${HOSTNAME}" = *"phys.uregina.ca"* ]]; then
#    REPLAYPATH="/home/${USER}/work/JLab/hallc_replay_lt"
#fi
    REPLAYPATH="/u/group/alphaE/analysis_apps/hallc_replay_vcs"
cd $REPLAYPATH

echo -e "\n\nStarting Replay Script\n\n"
eval "./u/group/alphaE/analysis_apps/hallc_replay_vcs/run_full_replay.csh $RUNNUMBER $process $target"
exit 0
