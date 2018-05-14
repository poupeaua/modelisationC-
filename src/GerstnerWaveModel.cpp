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
            double hauteurVague, GerstnerWave *list, int nbWaves) :

            WaveModel(windDirection, averageAlignment, intensite, longueurOnde,
                      hauteurVague)
{
  if (nbWaves <= 0) {
    throw invalid_argument("Argument invalide : La tableau passé en argument"
      " doit contenir au moins une GerstnerWave.");
  }
  this->nbWaves = nbWaves;
  this->ListGerstnerWaves = list;
}


/*!
 * [GerstnerWaveModel::GerstnerWaveModel Second constructeur principal pour la
 * classe GerstnerWaveModel. Cette deuxième version utilise une liste
 * de type STL list<GerstnerWave> pour la list de Gerstner Waves en entrée.]
 * @param windDirection    [windDirection est un paramètre pour la classe mère
 *  WaveModel]
 * @param averageAlignment [averageAlignment est un paramètre pour la classe mère]
 * @param intensite        [intensite est un paramètre pour la classe mère]
 * @param longueurOnde     [longueurOnde est un paramètre pour la classe mère]
 * @param hauteurVague     [hauteurVague est un paramètre pour la classe mère]
 * @param list             [list est une liste d'objets GerstnerWave
 *                          de type <list> de STL]
 */
GerstnerWaveModel::GerstnerWaveModel(Dvector windDirection, double averageAlignment,
            double intensite, double longueurOnde, double hauteurVague,
            list<GerstnerWave> list, int nbWaves) :

            WaveModel(windDirection, averageAlignment, intensite, longueurOnde,
                      hauteurVague)
{
  if (nbWaves <= 0 || list.size() <= 0) {
    throw invalid_argument("Argument invalide : La liste passée en argument"
      " doit contenir au moins une GerstnerWave.");
  }
  else if (nbWaves > 10)
  {
    throw invalid_argument("Argument invalide : La liste passée en argument"
      " contient plus de 10 vagues GerstnerWave.");
  }
  this->nbWaves = nbWaves;
  GerstnerWave *tmp_list = new GerstnerWave[11];
  for (int i = 0; i<nbWaves; i++) {
    tmp_list[i] = list.front();
    list.pop_front();
  }
  this->ListGerstnerWaves = tmp_list;
}


/*
----------------------------------- METHODS -----------------------------------
*/


/*!
 * [GerstnerWaveModel Destructeur pour GerstnerWaveModel]
 */
GerstnerWaveModel::~GerstnerWaveModel()
{
  delete[] ListGerstnerWaves;
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
      total_h += ListGerstnerWaves[i](x, y, t, getWindDirection(),
        getAverageAlignment());
  }
  return total_h;
}


/*!
 * [getListGerstnerWaves Getter classique pour accéder à l'attribut ListGerstnerWaves]
 * @return [this->ListGerstnerWaves]
 */
GerstnerWave *GerstnerWaveModel::getListGerstnerWaves() {
  return ListGerstnerWaves;
}


/*!
 * [getNbWaves Getter classique pour accéder à l'attribut nbWaves]
 * @return [this->nbWaves]
 */
int GerstnerWaveModel::getNbWaves() {
  return nbWaves;
}
