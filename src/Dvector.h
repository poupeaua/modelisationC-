#ifndef DVECTOR_H
#define DVECTOR_H
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
#include <stdexcept>    // used to use classic exceptions such as domain_error
#include <math.h>       // used for pow in norm method (TP3)

using namespace std;


class Dvector
{

  public:

  /*!
   * [Dvector::Dvector constructeur par défaut]
   */
  Dvector();

  /*!
   * [Dvector::Dvector constructeur précisant la taille et une option val
     permettant d'initialiser toute les coordonnées du vecteur à val]
   * @param taille [int définissant la taille du Dvector]
   * @param val    [double valeur qui sera associé à tous les éléments du Dvector]
   */
  Dvector(int taille, double val = 0.0);

  /*!
   * [Dvector::Dvector constructeur par copie]
   * @param other [Dvector autre Dvector élément dont chaque caractéristique
   *               sera copiée]
   */
  Dvector(const Dvector & other);

  /*!
   * [Dvector::Dvector constructeur utilisant un fichier pour lire les
   * coordonnées]
   * @param src [string désignant le nom d'un fichier. Le contenu de ce fichier
   *  sera ensuite copié dans le Dvector]
   */
  Dvector(string src);

  /*!
   * [Dvector Destructeur libérant la memoire]
   */
  ~Dvector();

  /*!
   * [Dvector::display Methode permettant d'afficher le contenu d'un vecteur
   *  sur la sortie demandée]
   * @param str [ostream& objet définissant sur quelle sortie le contenu du
   *  Dvector sera copié]
   */
  void display(ostream& str);

  /*!
   * [Dvector::size Getter classique pour la taille du Dvector]
   * @return [int définissant le taille du Dvector]
   */
  int size();

  /* p-norm added for the TP3 */
  /*!
   * [Dvector::norm Retourne la p-norme du Dvector.
   * Si p = 2, c'est la norme Euclidienne => qu'on utilisera mais on permet
   * une souplesse au cas où.]
   * @param  p [int définissant ainsi la p-norme. La norme Euclidienne se définit
   * pour p=2]
   * @return   [p-norme du Dvector]
   */
  double norm(int p);

  /*!
   * [Dvector::fillRandomly Methode permettant de remplir toutes les coordonnées
   * d'un vecteur avec des double compris entre 0 et 1]
   */
  void fillRandomly();

  /*!
   * [Dvector::resize Méthode permettant de redimensionner un Dvector]
   * @param new_taille [int définissant la nouvelle taille du Dvector qui peut
   *                    être plus grande ou plus petite que celle initiale]
   * @param new_ele    [double définissant la valeur des nouveaux éléments
   *                    dans le Dvector si la nouvelle taille est plus grande.]
   */
  void resize(int taille, double new_ele = 0.0);

  /*!
   * [Dvector::operator[] opérateur d'accession [] à un élément du vecteur]
   * @param  i [description]
   * @return   [description]
   */
  double& operator[](int i);

  /*!
   * [Dvector::operator[] opérateur d'accession [] à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
  const double& operator[](int i) const;

  /*!
   * [Dvector::operator[] opérateur d'accession () à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
  double& operator()(int i);

  /*!
   * [Dvector::operator[] opérateur d'accession () à un élément du vecteur]
   * @param  i [int définissant l'indice]
   * @return   [double représentant la valeur de l'objet à l'indice i]
   */
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
