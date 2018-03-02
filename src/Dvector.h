#include <stdio.h>
#include <stdlib.h>
#include <cassert>      // assert
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <iomanip>      // setprecision
#include <time.h>       // used for rand() random
#include <fstream>      // used to read in a file

using namespace std;

class Dvector
{

  public:

  Dvector();
  Dvector(int taille, double val = 0.0);
  Dvector(const Dvector & other);
  Dvector(string src);
  ~Dvector();
  void display(ostream& str);
  int size();
  void fillRandomly();


  private:

  double *vect;
  int taille;
};
