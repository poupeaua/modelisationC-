#include "WaveModel.h"


/* ---------------------------- CONSTRUCTORS ------------------------------- */


/*!
 * [WaveModel::WaveModel Constructeur d'un objet (abstrait) WaveModel]
 * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
 * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
 * d'alignement des vagues avec le vent]
 * @param intensite        [double définissant l'intensité des vagues]
 * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
 * @param hauteurVague     [double définissant la hauteur maximale des vagues]
 */
WaveModel::WaveModel(Dvector windDirection, double averageAlignment,
                  double intensite, double longueurOnde, double hauteurVague) {
  if (windDirection.size() != 2) {
    throw invalid_argument("Argument invalide : la direction du vent doit"
      " être précisément de deux.");
  } else if (averageAlignment > 1 || averageAlignment < 0) {
    throw invalid_argument("Argument invalide : L'alignement moyen doit être"
      " un double compris entre 0 et 1.");
  } else if (intensite < 0 || longueurOnde < 0 || hauteurVague < 0) {
    throw invalid_argument("Argument invalide : l'intensité, la longueur d'onde"
      " ainsi que la hauteur des vagues doit être positive.");
  }
  this->windDirection = windDirection;
  this->averageAlignment = averageAlignment;
  this->intensite = intensite;
  this->longueurOnde = longueurOnde;
  this->hauteurVague = hauteurVague;
}


/*!
 * [WaveModel::WaveModel Constructeur par copie]
 * @param other [WaveModel other étant un autre objet WaveModel]
 */
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
