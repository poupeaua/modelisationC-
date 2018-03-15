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

class WaveModel
{
  public:

  virtual double& operator()(Dvector v, double t)=0;
  double getDirection();
  double getAlignement();
  int getIntensite();
  double getLongueurOnde();
  double getHauteurVague();
  virtual ~WaveModel();

  protected:
  WaveModel(double direction, double alignement, int intensite,
              double longueurOnde, double hauteurVague);

  private:

  WaveModel(const WaveModel & other);
  WaveModel& operator=(const WaveModel&);
  double direction;
  double alignement;
  int intensite;
  double longueurOnde;
  double hauteurVague;
};
