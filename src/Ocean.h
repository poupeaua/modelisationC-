#ifndef OCEAN_H
#define OCEAN_H

#include "Height.h"
#include "WaveModel.h"

#include <list>     // needed to create a list of GerstnerWaves init
#include <ctime>    // needed to make the main_computation method (use clock_t)


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
   * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
   * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
   *                          d'alignement des vagues avec le vent]
   * @param intensite        [double définissant l'intensité des vagues]
   * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
   * @param hauteurVague     [double définissant la hauteur maximale des vagues]
   */
  Ocean(int nx, int ny, double length, double width, char * model,
              Dvector windDirection,
              double averageAlignment, double intensite, double longueurOnde,
              double hauteurVague, Height h, int nbWaves = 1);

  /*!
   * [initializeOceanTypeGerstner Methode de construction pour mieux
   * comprendre le fonctionnement de création de l'objet Ocean suivant le modèle,
   *  icie celui de Gerstner.]
   * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
   * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
   *                          d'alignement des vagues avec le vent]
   * @param intensite        [double définissant l'intensité des vagues]
   * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
   * @param hauteurVague     [double définissant la hauteur maximale des vagues]
   */
  void initializeOceanTypeGerstner(Dvector windDirection,
              double averageAlignment, double intensite, double longueurOnde,
              double hauteurVague, int nbWaves);


  /*!
   * [initializeOceanTypePhilips Methode de construction pour mieux
   * comprendre le fonctionnement de création de l'objet Ocean suivant le modèle,
   *  icie celui de Philips.]
   * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
   * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
   *                          d'alignement des vagues avec le vent]
   * @param intensite        [double définissant l'intensité des vagues]
   * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
   * @param hauteurVague     [double définissant la hauteur maximale des vagues]
   */
  void initializeOceanTypePhilips(Dvector windDirection,
              double averageAlignment, double intensite, double longueurOnde,
              double hauteurVague);

  /*!
   * [Destructeur classique]
   */
  ~Ocean();

  /*!
   * [generateHeight Méthode permettant de changer la hauteur de l'objet Height
   * H, attribut de cette classe.]
   */
   void generateHeight(double setHeight = 0.0);

  /*!
   * [compute Methode permettant de générer la hauteur en fonction du temps t]
   */
  void main_computation();

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
  double get_lx();

  /*!
   * [getWidth description]
   * @return [Retourne l'attribut width]
   */
  double get_ly();

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


  /* -------------------------- GIVEN METHODS ----------------------------- */

  void init_gl_VertexArrayX(const int y, double* const vertices);

  /** Initialise la grille dans la direction y
   *  param[in]   x        abscisse de la ligne à parcourir
   *  param[out]  vertices buffer contenant les coordonnées des noeuds
   */
  void init_gl_VertexArrayY(const int x, double* const vertices);

  /** Convertit le champs de hauteur en tabeau directement utilisable
   *  par OpenGL pour un y donné
   *  param[in]   y        abscisse de la colonne à parcourir
   *  param[out]  vertices buffer contenant les valeurs aux noeuds
   */
  void gl_VertexArrayX(const int y, double* const vertices);

  /** Convertit le champs de hauteur en tabeau directement utilisable
   *  par OpenGL pour un x donné
   *  param[in]   x        abscisse de la ligne à parcourir
   *  param[out]  vertices buffer contenant les valeurs aux noeuds
   */
  void gl_VertexArrayY(const int x, double* const vertices);

  private:

  double temps;
  double length; // Lx
  double width; // Ly
  int nx;
  int ny;
  double intensite;
  Height H;
  WaveModel *Model;

};


#endif
