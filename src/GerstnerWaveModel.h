#ifndef GERSTNER_WAVE_MODEL_H
#define GERSTNER_WAVE_MODEL_H
#include "GerstnerWave.h"
#include "WaveModel.h"


/* class that inherits from WaveModel */
class GerstnerWaveModel : public WaveModel
{
  public:

  /* not obliged to write virtual but it is to remind that they are special */
  /*!
   * [GerstnerWaveModel::operator permettant de calculer la hauteur total z
   * au point (x, y) à l'instant t]
   * @return [double définissant la hauteur total de la vague]
   */
  virtual double operator()(int x, int y, double t);

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
  GerstnerWaveModel(Dvector windDirection, double averageAlignment,
              double intensite, double longueurOnde, double hauteurVague,
              GerstnerWave *list, int nbWaves);

  /*!
   * [getListGerstnerWaves Getter classique pour accéder à l'attribut ListGerstnerWaves]
   * @return [this->ListGerstnerWaves]
   */
  GerstnerWave *getListGerstnerWaves();


  /*!
   * [getNbWaves Getter classique pour accéder à l'attribut nbWaves]
   * @return [this->nbWaves]
   */
  int getNbWaves();

  /*!
   * [GerstnerWaveModel Destructeur pour GerstnerWaveModel]
   */
  virtual ~GerstnerWaveModel();


  private:

  /* list of Gerstner Wave */
  GerstnerWave *ListGerstnerWaves;
  /* number of wave in the list / model */
  int nbWaves;
};

#endif
