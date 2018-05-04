#ifndef TEMPLATE_DVECTOR_H
#define TEMPLATE_DVECTOR_H
#include <stdio.h>      // classic include used everywhere
#include <stdlib.h>     // classic include used everywhere
#include <cassert>      // assert
#include <string>       // std::string & atof
#include <cstring>      // memcpy
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <iomanip>      // setprecision
#include <time.h>       // used for rand() random
#include <fstream>      // used to read in a file
#include <exception>    // used for creating special exceptions
#include <stdexcept>    // used to use classic exceptions such as domain_error
#include <math.h>       // used for pow in norm method (TP3)
#include <complex>      // used in order to handle complex numbers (TP4)

using namespace std;


/* initialise le template à T par défaut */
template<typename T = double>
class TemplateDvector
{
  public:

  TemplateDvector<T>();
  TemplateDvector<T>(int taille, T val = 0.0);
  TemplateDvector<T>(const TemplateDvector<T> & other);
  ~TemplateDvector<T>();
  void display(ostream& str);
  int size();

  T& operator[](int i);
  const T& operator[](int i) const;
  T& operator()(int i);
  const T& operator()(int i) const;
  TemplateDvector& operator=(const TemplateDvector &);
  TemplateDvector& operator+=(const TemplateDvector&);
  TemplateDvector& operator+=(const T d);
  TemplateDvector& operator*=(const T d);
  TemplateDvector& operator-=(const TemplateDvector&);
  TemplateDvector& operator-=(const T d);
  TemplateDvector& operator/=(const T d);
  TemplateDvector operator-(void);
  bool operator==(TemplateDvector &);

  class ErreurAllocation: public exception {
  public:
    virtual const char* what(void) const throw () {
      return "Erreur d'allocation mémoire.";
    }
  };

  class ErreurAcces: public exception {
  public:
    virtual const char* what(void) const throw () {
      return "Erreur d'accés aux données du TemplateDvector<T>.";
    }
  };

  private:

  T *vect;
  int taille;

};
  
  template<typename T>
  TemplateDvector<T> operator+(const TemplateDvector<T>&, const T d);
  template<typename T>
  TemplateDvector<T> operator+(const T d, const TemplateDvector<T>&);
  template<typename T>
  TemplateDvector<T> operator-(const TemplateDvector<T>&, const T d);
  template<typename T>
  TemplateDvector<T> operator-(const double d, const TemplateDvector<T>&);
  template<typename T>
  TemplateDvector<T> operator*(const TemplateDvector<T>&, const T d);
  template<typename T>
  TemplateDvector<T> operator*(const double d, const TemplateDvector<T>&);
  template<typename T>
  TemplateDvector<T> operator/(const TemplateDvector<T>&, const T d);
  template<typename T>
  TemplateDvector<T> operator/(const T d, const TemplateDvector<T>&);
  template<typename T>
  TemplateDvector<T> operator+(const TemplateDvector<T>&, const TemplateDvector<T>&);
  template<typename T>
  TemplateDvector<T> operator-(const TemplateDvector<T>&, const TemplateDvector<T>&);
  template<typename T>
  ostream& operator<<(ostream &Out, TemplateDvector<T> &);
  template<typename T>
  istream& operator>>(istream &in, TemplateDvector<T> &);

#include "TemplateDvectorMethods.h"

#endif
