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
  Dvector(int taille, double val);
  Dvector(const Dvector & other);
  Dvector(string src);
  ~Dvector();
  void display(ostream& str);
  int size();
  void fillRandomly();
  double& operator[](int i);
  double& operator()(int i);
  Dvector& operator=(const Dvector &);
  Dvector& operator+=(const Dvector&);
  Dvector& operator+=(const double d);
  Dvector& operator*=(const double d);
  Dvector& operator-=(const Dvector&);
  Dvector& operator-=(const double d);
  Dvector& operator/=(const double d);
  Dvector operator-(void);
  bool operator==(Dvector &);

  private:

  double *vect;
  int taille;
};
  Dvector operator+(const Dvector&, const double d);
  Dvector operator+(const double d, const Dvector&);
  Dvector operator-(const Dvector&, const double d);
  Dvector operator-(const double d, const Dvector&);
  Dvector operator*(const Dvector&, const double d);
  Dvector operator*(const double d, const Dvector&);
  Dvector operator/(const Dvector&, const double d);
  Dvector operator/(const double d, const Dvector&);
  Dvector operator+(const Dvector&, const Dvector&);
  Dvector operator-(const Dvector&, const Dvector&);
  ostream& operator<<(ostream &Out, Dvector &);
  istream& operator>>(istream &in, Dvector &);
