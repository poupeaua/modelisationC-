#include "GerstnerWaveModel.h"



/*
-------------------------------- CONSTRUCTORS ---------------------------------
*/


/*!
 * [GerstnerWaveModel::GerstnerWaveModel Constructeur principal pour la
 * classe GerstnerWaveModel.]
 * @param windDirection    [windDirection est un paramètre pour la classe mère
 *  WaveModel]
 * @param averageAlignment [averageAlignment est un paramètre pour la classe mère]
 * @param intensite        [intensite est un paramètre pour la classe mère]
 * @param longueurOnde     [longueurOnde est un paramètre pour la classe mère]
 * @param hauteurVague     [hauteurVague est un paramètre pour la classe mère]
 * @param list             [list est un tableau d'objets GerstnerWave]
 */
GerstnerWaveModel::GerstnerWaveModel(Dvector windDirection,
            double averageAlignment, double intensite, double longueurOnde,
            double hauteurVague, GerstnerWave *list) :

            WaveModel(windDirection, averageAlignment, intensite, longueurOnde,
                      hauteurVague)
{
  this->nbWaves = sizeof(list)/sizeof(GerstnerWave);
  this->ListGerstnerWaves = list;
}


/*
----------------------------------- METHODS -----------------------------------
*/


/*!
 * [GerstnerWaveModel Destructeur pour GerstnerWaveModel]
 */
GerstnerWaveModel::~GerstnerWaveModel()
{

}

/*!
 * [GerstnerWaveModel::operator permettant de calculer la hauteur total z
 * au point (x, y) à l'instant t]
 * @return [double définissant la hauteur total de la vague]
 */
double GerstnerWaveModel::operator()(int x, int y, double t) {
  double total_h = 0;
  for (int i = 0 ; i < nbWaves ; i++)
  {
      total_h += ListGerstnerWaves[i](x, y, t, getWindDirection(), getAverageAlignment());
  }
  return total_h;
}
