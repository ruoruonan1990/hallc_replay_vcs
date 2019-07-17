#ifndef Parameters_h
#define Parameters_h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <TString.h>
using namespace std;

void InitBins(string);
// change here parameters for the code:

// missing mass and other related variable figures display
extern float M2miss_min, M2miss_max, Mmiss_min, Mmiss_max;
extern int M2miss_bins, Mmiss_bins;

//const float M2miss_min = -0.5,  M2miss_max = 1.5;
//const int M2miss_bins = 100;
//const float Mmiss_min = -0.5, Mmiss_max = 1.5;
//const int Mmiss_bins = 100;


#endif

