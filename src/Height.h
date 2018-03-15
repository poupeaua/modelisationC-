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


class Height
{
  public:

  Height(int longueur, int largeur, int valeurs[][]);
  Height(const Height & other);
  ~Height();
  int getLongueur();
  int getLargeur();
  double& operator()(Dvector v, double t);
  Height& operator=(const Height&);

  private:
  int longueur;
  int largeur;
  int height[][];
};

ostream& operator<<(ostream &Out, Dvector &dv);
istream& operator>>(istream &in, Dvector &dv);
