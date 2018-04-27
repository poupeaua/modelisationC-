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
#include "GerstnerWave.h"
#include "WaveModel.h"
#include "Dvector.h"

using namespace std;

class GerstnerWaveModel : public WaveModel
{
  public:

  // not obliged to write virtual but it is to remind that they are special meth
  virtual double& operator()(int x, int y, double t);
  GerstnerWaveModel(Dvector direction, double alignement, double intensite,
              double longueurOnde, double hauteurVague, GerstnerWave *list);
  virtual ~GerstnerWaveModel();

  private:

  GerstnerWave *ListGerstnerWave;
  int nb_ondes;
};
