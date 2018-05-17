#ifndef HEIGHT_H
#define HEIGHT_H

#include "Dvector.h"


/*
Model of heigth object
Convention of axis x and y in informatics used

  L O N G U E U R  = x
L
A
R
G
E
U
R
=
y

*/

/*!
 * [Height Classe permettant de générer un objet représentant la surface de
 * l'océan étant comme un tableau 2D avec une hauteur par case.]
 */
class Height
{
  public:

  /*!
   * [Height::Height Constructeur par défaut de Height. La valeur de tous les
   * attributs sont choisis pour l'utilisateur.]
   */
  Height();


  /*!
   * [Height::Height Constructeur par défaut plaçant des valeurs (par défaut zero)]
   * @param nx     [int définisant le nombre de discrétisation selon l'axe x]
   * @param ny     [int définisant le nombre de discrétisation selon l'axe y]
   * @param value  [double définissant la value à associer à chaque éléments de
   *                l'attribut height de l'objet Height]
   * @param length [double caractérisant la longueur physique de la surface]
   * @param width  [double caractérisant la largeur physique de la surface]
   */
  Height(int nx, int ny, double value = 0.0, double length = 1.0, double width = 1.0);

  /*!
   * [Height::Height Constructeur par copie]
   * @param other [Height objet qui est utilisé pour la copie]
   */
  Height(const Height & other);

  /*!
   * [Height::Height Constructeur placant les valeurs contenues dans le tableau
   * valeurs BEWARE length et width doivent correspondre au tableau valeur]
   * @param valeurs  [tableau de double définissant la value à associer à chaque
   *                  éléments de l'attribut height de l'objet Height]
   * @param length [double caractérisant la longueur physique de la surface]
   * @param width  [double caractérisant la largeur physique de la surface]
   */
  Height(int nx, int ny, double **height, double length = 1.0, double width = 1.0);


  /*!
   * [Height destructeur]
   */
  ~Height();


  /*!
   * [setHeightTo Set tous les éléments dans le tableau mono-dimentionnel Dvector
   * attribut nommé height à setHeight. Fonction créée au TP4 pour faciliter
   * l'implémentation de la méthode generateHeight.]
   * @param setHeight [double setHeight valeur à placer dans tous les éléments
   * du tableau.]
   */
  void setHeightTo(double setHeight);


  /*!
   * [Height::getNx accesseur classique pour Lx]
   * @return [double attribut Lx]
   */
  double getLength();


  /*!
   * [Height::getNx accesseur classique pour Ly]
   * @return [int attribut Ly]
   */
  double getWidth();

  /*!
   * [Height::getNx accesseur classique pour nx]
   * @return [int attribut nx]
   */
  int getNx();

  /*!
   * [Height::getNx accesseur classique pour ny]
   * @return [int attribut ny]
   */
  int getNy();

  /*!
   * [Height::operator () permettant d'accéder à l'élément situer à la ligne x
   * et à la colonne y]
   * @return [double représentant la valeur au point x et y]
   */
  double& operator()(int x, int y);

  Height& operator=( Height &);

  private:

  double length; // Lx
  double width; // Ly
  int nx;
  int ny;
  Dvector height;
};

ostream& operator<<(ostream &Out, Height &h);
istream& operator>>(istream &in, Height &h);

#endif
