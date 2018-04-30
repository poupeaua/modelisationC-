#include "WaveModel.h"


Dvector WaveModel::getWindDirection() {
  return windDirection;
}


double WaveModel::getAverageAlignment() {
  return averageAlignment;
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
