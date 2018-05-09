#ifndef WAVE_MODEL_H
#define WAVE_MODEL_H
/* root abstract class so it has the main Dvector.h file */
#include "Dvector.h"


class WaveModel
{
  public:

  virtual double operator()(int x, int y, double t)=0;

  /*!
   * [WaveModel::getWindDirection Accesseur classique pour la direction du vent]
   * @return [Dvector de dimension 2 représentant la direction du vent pour ce
   * modèle]
   */
  Dvector getWindDirection();

  /*!
   * [WaveModel::getAverageAlignment Accesseur pour l'alignement moyen des vagues
   * avec la direction du vent]
   * @return [double représentant la moyenne d'alignement]
   */
  double getAverageAlignment();

  /*!
   * [WaveModel::getIntensite Accesseur pour l'intensité]
   * @return [double représentant l'intensité]
   */
  double getIntensite();

  /*!
   * [WaveModel::getLongueurOnde Accesseur pour la longueur d'onde]
   * @return [double représentant la longueur d'onde]
   */
  double getLongueurOnde();

  /*!
   * [WaveModel::getHauteurVague Accesseur pour la hauteur maximale des vagues]
   * @return [double hauteur maximale des vagues]
   */
  double getHauteurVague();


  /*!
   * [WaveModel Destructeur classique pour les objets WaveModel]
   */
  virtual ~WaveModel()=0;

  protected:

  /*!
   * [WaveModel::WaveModel Constructeur d'un objet (abstrait) WaveModel]
   * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
   * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
   * d'alignement des vagues avec le vent]
   * @param intensite        [double définissant l'intensité des vagues]
   * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
   * @param hauteurVague     [double définissant la hauteur maximale des vagues]
   */
  WaveModel(Dvector windDirection, double averageAlignment, double intensite,
              double longueurOnde, double hauteurVague);

  protected:

  /*!
   * [WaveModel::WaveModel Constructeur par copie]
   * @param other [WaveModel other étant un autre objet WaveModel]
   */
  WaveModel(const WaveModel & other);

  private:

  WaveModel& operator=(const WaveModel&);

  Dvector windDirection;
  double averageAlignment;
  double intensite;
  double longueurOnde;
  double hauteurVague;
};

#endif
