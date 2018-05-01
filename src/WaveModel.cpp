#include "WaveModel.h"


/* ---------------------------- CONSTRUCTORS ------------------------------- */


WaveModel::WaveModel(Dvector windDirection, double averageAlignment,
                  double intensite, double longueurOnde, double hauteurVague) {
  if (windDirection.size() != 2) {
    cout << "ERROR : the length of the direction vector" << "direction has to"
        " be equal to two" << endl;
    exit(EXIT_FAILURE);
  }
  this->windDirection = windDirection;
  this->averageAlignment = averageAlignment;
  this->intensite = intensite;
  this->longueurOnde = longueurOnde;
  this->hauteurVague = hauteurVague;
}


WaveModel::WaveModel(const WaveModel &other) {
  this->windDirection = other.windDirection;
  this->averageAlignment = other.averageAlignment;
  this->intensite = other.intensite;
  this->longueurOnde = other.longueurOnde;
  this->hauteurVague = other.hauteurVague;
}


/* ---------------------------- METHODS ------------------------------------- */


/*!
 * [WaveModel Destructeur classique pour les objets WaveModel]
 */
WaveModel::~WaveModel()
{

}


/*!
 * [WaveModel::getWindDirection Accesseur classique pour la direction du vent]
 * @return [Dvector de dimension 2 représentant la direction du vent pour ce
 * modèle]
 */
Dvector WaveModel::getWindDirection() {
  return windDirection;
}


/*!
 * [WaveModel::getAverageAlignment Accesseur pour l'alignement moyen des vagues
 * avec la direction du vent]
 * @return [double représentant la moyenne d'alignement]
 */
double WaveModel::getAverageAlignment() {
  return averageAlignment;
}


/*!
 * [WaveModel::getIntensite Accesseur pour l'intensité]
 * @return [double représentant l'intensité]
 */
double WaveModel::getIntensite() {
  return intensite;
}


/*!
 * [WaveModel::getLongueurOnde Accesseur pour la longueur d'onde]
 * @return [double représentant la longueur d'onde]
 */
double WaveModel::getLongueurOnde() {
  return longueurOnde;
}


/*!
 * [WaveModel::getHauteurVague Accesseur pour la hauteur maximale des vagues]
 * @return [double hauteur maximale des vagues]
 */
double WaveModel::getHauteurVague(){
  return hauteurVague;
}
