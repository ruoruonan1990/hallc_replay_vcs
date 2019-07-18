## Get the absolute path to this replay directory
REPLAY_DIR = "$(realpath $(abspath $(shell pwd))/..)"

## Communicate the absolute path the this replay directory as preprocessor define
## This is necessary to locate the correct database file
FLAGS = -g -fPIC -Wno-conversion -Wno-narrowing -DVCS_REPLAY_PATH=\"$(REPLAY_DIR)\" -ansi -std=c++0x -Wno-overloaded-virtual -Wno-long-long -fno-common -g
QMAKE_CC = g++

export ROOTLIB=`root-config --glibs`
export ROOTINC=`root-config --incdir`

ifdef OPT 
  OPTM=$(OPT)
else
  OPTM=-O1
  #OPTM=-O2
endif

ANA_C = includes/ReadHallCData.cc includes/Utils.cc includes/Constants.cc includes/ReadTextFiles.cc includes/Database.cc includes/Parameters.cc
ANA_O =  $(ANA_C:.cc=.o)
ANA_H =  $(ANA_C:.cc=.h)

default:        HallCana

clean:                                
	@echo "Remove files: " ./*.o ./*~ ./main ./includes/*.o ./*.o
	@rm -f ./*.o ./*~ ./main ./includes/*.o ./*.o
	@echo "make clean, done... "

./%.o:  ./%.cc ./%.h
	@echo "Compilation: "$(OPTM) $<  $@
	@g++ $(OPTM) $(FLAGS) -I$(ROOTINC) -c $< -o $@
        
./%.o:  ./%.c ./%.h
	@echo "Compilation: "$(OPTM) $<  $@
	@g++ $(OPTM) $(FLAGS) -I$(ROOTINC) -c $< -o $@

./%.o:  ./%.C ./%.h
	@echo "Compilation: "$(OPTM) $(ROOTINC)  $<  $@
	@g++ $(OPTM) $(FLAGS) -I$(ROOTINC) -c $< -o $@

HallCana.o:$(ANA_H) HallCana.cc
	@echo "Compile:   $(ROOTINC) $(OPTM) $@"
	@g++ $(OPTM) $(FLAGS) -I $(ROOTINC) -I includes/ -c HallCana.cc -o HallCana.o

HallCana:  HallCana.o $(ANA_O) $(ANAc_O) $(ANAC_O)
	@echo "Link fit"
	@echo g++ $(FLAGS) $(OPTM)  -I $(ROOTINC) -I lib/ -I includes/ -o HallCana $(ANA_O) $(ANAc_O) $(ANAC_O) HallCana.o $(ROOTLIB) -lSpectrum

	@g++ $(FLAGS) $(OPTM)  -I $(ROOTINC) -I lib/ -I includes/ -o HallCana $(ANA_O) $(ANAc_O) $(ANAC_O) HallCana.o $(ROOTLIB) -lSpectrum
	@echo "Compilation done..."








