#include "WaveModel.h"


double WaveModel::getDirection() {
  return direction;
}

double WaveModel::getAlignement() {
  return alignement;
}

int WaveModel::getIntensite() {
  return intensite;
}

double WaveModel::getLongueurOnde() {
  return longueurOnde;
}

double WaveModel::getHauteurVague(){
  return hauteurVague;
}

WaveModel::WaveModel(double direction, double alignement, int intensite,
                     double longueurOnde, double hauteurVague) {
  this->direction = direction;
  this->alignement = alignement;
  this->intensite = intensite;
  this->longueurOnde = longueurOnde;
  this->hauteurVague = hauteurVague;
}

WaveModel::WaveModel(const WaveModel &other) {
  /**
   * faire un test
  **/
  this->direction = other.direction;
  this->alignement = other.alignement;
  this->intensite = other.intensite;
  this->longueurOnde = other.longueurOnde;
  this->hauteurVague = other.hauteurVague;
}
 /**
  * implementer l'operateur ==
 **/
