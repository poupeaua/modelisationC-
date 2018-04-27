#ifndef WAVE_MODEL_H
#define WAVE_MODEL_H
/* root abstract class so it has the main Dvector.h file */
#include "Dvector.h"


using namespace std;

class WaveModel
{
  public:

  virtual double operator()(int x, int y, double t)=0;
  Dvector getDirection();
  double getAlignement();
  double getIntensite();
  double getLongueurOnde();
  double getHauteurVague();
  virtual ~WaveModel();

  protected:
  WaveModel(Dvector direction, double alignement, double intensite,
              double longueurOnde, double hauteurVague);

  private:

  WaveModel(const WaveModel & other);
  WaveModel& operator=(const WaveModel&);
  Dvector direction;
  double alignement;
  double intensite;
  double longueurOnde;
  double hauteurVague;
};

#endif
