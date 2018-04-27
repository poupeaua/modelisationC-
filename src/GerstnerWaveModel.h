#ifndef GERSTNER_WAVE_MODEL_H
#define GERSTNER_WAVE_MODEL_H
#include "GerstnerWave.h"
#include "WaveModel.h"


using namespace std;

class GerstnerWaveModel : public WaveModel
{
  public:

  // not obliged to write virtual but it is to remind that they are special meth
  virtual double operator()(int x, int y, double t);
  GerstnerWaveModel(Dvector direction, double alignement, double intensite,
              double longueurOnde, double hauteurVague, GerstnerWave *list);
  virtual ~GerstnerWaveModel();

  private:

  // list of Gerstner Wave
  GerstnerWave *ListGerstnerWave;
  // number of wave in the list / model
  int nb_ondes;
};

#endif
