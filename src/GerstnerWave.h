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
#include "Dvector.h"

using namespace std;

class GerstnerWave
{
    public:

    Dvector getDirection();
    double getAmplitude();
    double getFrequence();
    double getPhase();
    ~GerstnerWave();

    GerstnerWave(Dvector direction, double amplitude,
                double frequence, double phase);

    GerstnerWave(const GerstnerWave & other);
    GerstnerWave& operator=(const GerstnerWave&);

    private:

    Dvector direction;
    double amplitude;
    double frequence;
    double phase;
};
