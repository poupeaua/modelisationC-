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

using namespace std;

class WaveModel
{
  public:

  double getDirection();
  double getAlignement();
  int getIntensite();
  double getLongueurOnde();
  double getHauteurVague();
  virtual double& operator()(double x, double y, double t);
  WaveModel& operator=(const WaveModel&);
  ~WaveModel();
  WaveModel();
  WaveModel(const WaveModel & other);


  private:

  double direction;
  double alignement;
  int intensite;
  double longueurOnde;
  double hauteurVague;
};
