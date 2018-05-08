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

  /*!
   * [TemplateDvector::TemplateDvector constructeur par défaut]
   */
  TemplateDvector<T>();

  /*!
   * [TemplateDvector::TemplateDvector constructeur précisant la taille et une option val
     permettant d'initialiser toute les coordonnées du vecteur à val]
   * @param taille [int définissant la taille du TemplateDvector]
   * @param val    [double valeur qui sera associé à tous les éléments du TemplateDvector]
   */
  TemplateDvector<T>(int taille, T val = 0.0);

  /*!
   * [TemplateDvector::TemplateDvector constructeur par copie]
   * @param other [TemplateDvector autre TemplateDvector élément dont chaque caractéristique
   *               sera copiée]
   */
  TemplateDvector<T>(const TemplateDvector<T> & other);

  /*!
   * [TemplateDvector Destructeur libérant la memoire]
   */
  ~TemplateDvector<T>();

  /*!
   * [TemplateDvector::display Methode permettant d'afficher le contenu d'un vecteur
   *  sur la sortie demandée]
   * @param str [ostream& objet définissant sur quelle sortie le contenu du
   *  TemplateDvector sera copié]
   */
  void display(ostream& str);

  /*!
   * [TemplateDvector::size Getter classique pour la taille du TemplateDvector]
   * @return [int définissant le taille du TemplateDvector]
   */
  int size();

  /*!
   * [TemplateDvector::operator[] opérateur d'accession [] à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
  T& operator[](int i);

  /*!
   * [TemplateDvector::operator[] opérateur d'accession [] à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
  const T& operator[](int i) const;

  /*!
   * [TemplateDvector::operator[] opérateur d'accession () à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
  T& operator()(int i);

  /*!
   * [TemplateDvector::operator[] opérateur d'accession () à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
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
