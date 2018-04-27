#include "GerstnerWaveModel.h"


double GerstnerWaveModel::operator()(int x, int y, double t) {
  double total_h = 0;
  for (int i = 0 ; i < nb_ondes ; i++)
  {
      total_h += ListGerstnerWave[i](x, y, t);
  }
  return total_h;
}


GerstnerWaveModel::GerstnerWaveModel(Dvector direction, double alignement,
            double intensite, double longueurOnde, double hauteurVague,
            GerstnerWave *list) :

            WaveModel(direction, alignement, intensite, longueurOnde,
                      hauteurVague)
{
  this->nb_ondes = sizeof(list)/sizeof(GerstnerWave);
  this->ListGerstnerWave = list;
}
