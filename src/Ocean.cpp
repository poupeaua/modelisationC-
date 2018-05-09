#include "Ocean.h"


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
Ocean::Ocean(double temps, double length, double width, int nx, int ny,
              Height *height, WaveModel *model, double *vertices)
{
  if (temps < 0 || length <= 0 || width <= 0 || nx <= 0 || ny <= 0) {
    throw domain_error("L'attribut temps de Ocean doit être strictement positif"
        ". length, width, nx et ny doivent être positifs ou nuls.");
  }
  this->temps = temps;
  this-> length = length;
  this->width= width;
  this->nx = nx;
  this->ny = ny;
  this->height = height;
  this->model = model;
  this->vertices = vertices;
}


/*!
 * [Destructeur classique]
 */
Ocean::~Ocean()
{
  /* free the height attribute */
  delete height;
  /* free the model attribute */
  delete model;
}


/*!
 * [generateHeight Méthode permettant d'initialiser l'objet Heigth pour la
 * hauteur]
 */
void Ocean::generateHeight(double setHeight)
{
  /* method created just for this purpose */
  height->setHeightTo(setHeight);
}


/*!
 * [compute Methode permettant de générer la hauteur en fonction du temps t]
 */
void Ocean::compute()
{

}


/*!
 * [gl_vertices Méthode qui convertit la houle en un tableau contenant les
 * positions (x, y, h) pour la visualisation]
 */
void Ocean::gl_vertices()
{

}


/* ------------------------------- GETTER ---------------------------------*/


/*!
 * [getTemps Getter classique pour le temps]
 * @return [Retourne le temps actuel attribut temps]
 */
double Ocean::getTemps()
{
  return temps;
}


/*!
 * [getLength Getter classique pour la length Lx]
 * @return [Retourne l'attribut length]
 */
double Ocean::getLength()
{
  return length;
}


/*!
 * [getWidth description]
 * @return [Retourne l'attribut width]
 */
double Ocean::getWidth()
{
  return width;
}


/*!
 * [getNx description]
 * @return [Retourne l'attribut nx]
 */
int Ocean::getNx()
{
  return nx;
}


/*!
 * [getNy description]
 * @return [Retourne l'attribut ny]
 */
int Ocean::getNy()
{
  return ny;
}


/*!
 * [getHeight description]
 * @return [Retourne l'attribut height]
 */
Height* Ocean::getHeight()
{
  return height;
}


/*!
 * [getModel description]
 * @return [Retourne l'attribut model]
 */
WaveModel* Ocean::getModel()
{
  return model;
}
