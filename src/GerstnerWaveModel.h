#include <stdio.h>
#include <stdlib.h>
#include <cassert>      // assert
#include <string>       // std::string & atof
#include <cstring>      // memcpy
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <iomanip>      // setprecision
#include <time.h>       // used for rand() random
#include <fstream>      // used to read in a file
#include "WaveModel.h"

using namespace std;

class GerstnerWaveModel:public GestnerWave
{
 private:

  GestnerWave **ListGestnerWave;
};
