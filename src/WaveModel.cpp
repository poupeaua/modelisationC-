#include "WaveModel.h"


Dvector WaveModel::getDirection() {
  return direction;
}


double WaveModel::getAlignement() {
  return alignement;
}


double WaveModel::getIntensite() {
  return intensite;
}


double WaveModel::getLongueurOnde() {
  return longueurOnde;
}


double WaveModel::getHauteurVague(){
  return hauteurVague;
}


WaveModel::WaveModel(Dvector direction, double alignement, double intensite,
                     double longueurOnde, double hauteurVague) {
  if (direction.size() != 2) {
    cout << "ERROR : the length of the direction vector" << "direction has to"
        " be equal to two" << endl;
    exit(EXIT_FAILURE);
  }
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
