#!/bin/bash

# in principle this is automatic, but you can change path with this executable if its not

# Do: 

# after you create your own analysis directory "/home/cdaq/YOURNAME/hallc_replay_vcs", run once this executable to change all the hardcoded path in source files. 
# don't forget to go to "Ana", then do: make clean && make

savepwd=$(pwd)
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%${savepwd}/%" Ana/datainfo/get_runinfo.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%${savepwd}/%" Ana/datainfo/get_mergeinfo.csh


