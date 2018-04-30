#ifndef DVECTOR_H
#define DVECTOR_H
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
  void resize(int taille, double new_ele = 0.0);
  double& operator[](int i);
  const double& operator[](int i) const;
  double& operator()(int i);
  const double& operator()(int i) const;
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

#endif
