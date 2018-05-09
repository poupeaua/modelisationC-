#ifndef PHILIPS_WAVE_MODEL_H
#define PHILIPS_WAVE_MODEL_H
#include "WaveModel.h"
#include "TemplateDvector.h"
#include "Dvector.h"
#include <math.h>


/* class that inherits from WaveModel */
class PhilipsWaveModel : public WaveModel
{
  public:

  /* not obliged to write virtual but it is to remind that they are special */
  /*!
   * [PhilipsWaveModel::operator permettant de calculer la hauteur total z
   * au point (x, y) à l'instant t]
   * @return [double définissant la hauteur total de la vague]
   */
  virtual double operator()(int x, int y, double t);

  /*!
   * [PhilipsWaveModel::PhilipsWaveModel Constructeur principal pour la
   * classe PhilipsWaveModel.]
   * @param windDirection    [windDirection est un paramètre pour la classe mère
   *  WaveModel]
   * @param averageAlignment [averageAlignment est un paramètre pour la classe mère]
   * @param intensite        [intensite est un paramètre pour la classe mère]
   * @param longueurOnde     [longueurOnde est un paramètre pour la classe mère]
   * @param hauteurVague     [hauteurVague est un paramètre pour la classe mère]
   */
  PhilipsWaveModel(Dvector windDirection, double averageAlignment,
              double intensite, double longueurOnde, double hauteurVague);

  /*!
   * [PhilipsWaveModel Destructeur pour PhilipsWaveModel]
   */
  virtual ~PhilipsWaveModel();

  /*!
   * [PhilipsWaveModel::operator = afin d'associer toutes les caractéristiques de
   *  gw passée en paramètre à l'objet this]
   * @return [*this]
   */
  PhilipsWaveModel& operator=(const PhilipsWaveModel&);

  /*!
   * [PhilipsWave::PhilipsWave Constructeur par copie]
   * @param other [const PhilipsWave & est un autre objet GertsnerWave]
   */
   PhilipsWaveModel(const PhilipsWaveModel & other);


  private:


};

  void fft(TemplateDvector<complex<double>> x);

  void ifft(TemplateDvector<complex<double>> x);

#endif
