#ifndef WAVE_MODEL_H
#define WAVE_MODEL_H
/* root abstract class so it has the main Dvector.h file */
#include "Dvector.h"


class WaveModel
{
  public:

  virtual double operator()(int x, int y, double t)=0;
  Dvector getWindDirection();
  double getAverageAlignment();
  double getIntensite();
  double getLongueurOnde();
  double getHauteurVague();
  virtual ~WaveModel()=0;

  protected:

  WaveModel(Dvector windDirection, double averageAlignment, double intensite,
              double longueurOnde, double hauteurVague);

  private:

  WaveModel(const WaveModel & other);
  WaveModel& operator=(const WaveModel&);
  Dvector windDirection;
  double averageAlignment;
  double intensite;
  double longueurOnde;
  double hauteurVague;
};

#endif
