#ifndef OCEAN_H
#define OCEAN_H

#include "Height.h"
#include "WaveModel.h"


class Ocean
{
  public:

  /* ---------------------------- NEEDED METHODS --------------------------- */

  /*!
   * [Ocean Constructeur de base pour la classe ocean]
   * @param temps    [double définissant le temps courant]
   * @param length   [double définissant la longueur de Lx de la plateforme]
   * @param width    [double définissant la largeur de Ly de la plateforme]
   * @param nx       [int représentant le nombre de découpages discrets sur l'axe x]
   * @param ny       [int représentant le nombre de découpages discrets sur l'axe y]
   * @param height   [Height objet tableau mono-dimentionnel pour les hauteurs]
   * @param model    [WaveModel model utilisé]
   * @param vertices [double * tableau dynamique de nombres en double précision
   *                  permettant d'interfacer les vecteurs de calculs
                      avec le système de visualisation.]
   */
  Ocean(double temps, double length, double width, int nx, int ny,
        Height* height, WaveModel* model, double *vertices);

  /*!
   * [Destructeur classique]
   */
  ~Ocean();

  /*!
   * [generateHeight Méthode permettant d'initialiser l'objet Heigth pour la
   * hauteur]
   */
  void generateHeight(double setHeight = 0.0);

  /*!
   * [compute Methode permettant de générer la hauteur en fonction du temps t]
   */
  void compute();

  /*!
   * [gl_vertices Méthode qui convertit la houle en un tableau contenant les
   * positions (x, y, h) pour la visualisation]
   */
  void gl_vertices();

  /* ------------------------------- GETTER ---------------------------------*/

  /*!
   * [gettemps Getter classique pour le temps]
   * @return [Retourne le temps actuel attribut temps]
   */
  double getTemps();

  /*!
   * [getLength Getter classique pour la length Lx]
   * @return [Retourne l'attribut length]
   */
  double getLength();

  /*!
   * [getWidth description]
   * @return [Retourne l'attribut width]
   */
  double getWidth();

  /*!
   * [getNx description]
   * @return [Retourne l'attribut nx]
   */
  int getNx();

  /*!
   * [getNy description]
   * @return [Retourne l'attribut ny]
   */
  int getNy();

  /*!
   * [getHeight description]
   * @return [Retourne l'attribut height]
   */
  Height* getHeight();

  /*!
   * [getModel description]
   * @return [Retourne l'attribut model]
   */
  WaveModel* getModel();

  private:

  double temps;
  double length; // Lx
  double width; // Ly
  int nx;
  int ny;
  Height *height;
  WaveModel *model;
  double *vertices;

};

#endif
