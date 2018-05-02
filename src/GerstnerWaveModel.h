#ifndef GERSTNER_WAVE_MODEL_H
#define GERSTNER_WAVE_MODEL_H
#include "GerstnerWave.h"
#include "WaveModel.h"


using namespace std;

/* class that inherits from WaveModel */
class GerstnerWaveModel : public WaveModel
{
  public:

  /* not obliged to write virtual but it is to remind that they are special */
  virtual double operator()(int x, int y, double t);
  GerstnerWaveModel(Dvector windDirection, double averageAlignment,
              double intensite, double longueurOnde, double hauteurVague,
              GerstnerWave *list, int nbWaves);
  GerstnerWave *getListGerstnerWaves();
  int getNbWaves();
  virtual ~GerstnerWaveModel();


  private:

  /* list of Gerstner Wave */
  GerstnerWave *ListGerstnerWaves;
  /* number of wave in the list / model */
  int nbWaves;
};

#endif
