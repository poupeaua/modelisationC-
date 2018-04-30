#include "GerstnerWaveModel.h"



/*
-------------------------------- CONSTRUCTORS ---------------------------------
*/

// Constructeur le plus simple pour un objet GerstnerWaveModel.


GerstnerWaveModel::GerstnerWaveModel(Dvector windDirection,
            double averageAlignment, double intensite, double longueurOnde,
            double hauteurVague, GerstnerWave *list) :

            WaveModel(windDirection, averageAlignment, intensite, longueurOnde,
                      hauteurVague)
{
  this->nbWaves = sizeof(list)/sizeof(GerstnerWave);
  for (int i = 0 ; i < nbWaves ; i++)
  {

  }
  this->ListGerstnerWaves = list;
}


/*
-------------------------------- METHODS ---------------------------------
*/

/*!
 * [GerstnerWaveModel::operator description]
 * @return [description]
 */
double GerstnerWaveModel::operator()(int x, int y, double t) {
  double total_h = 0;
  for (int i = 0 ; i < nbWaves ; i++)
  {
      total_h += ListGerstnerWaves[i](x, y, t, getWindDirection(), getAverageAlignment());
  }
  return total_h;
}
