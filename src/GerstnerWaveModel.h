#ifndef GERSTNER_WAVE_MODEL_H
#define GERSTNER_WAVE_MODEL_H
#include "GerstnerWave.h"
#include "WaveModel.h"

#include <list>     // needed for init for one of the constructors


/*!
 * [GerstnerWaveModel Classe héritant de WaveModel et qui permet de générer des
 * objets représentant les paramètres pour réaliser une simulation de vagues
 * selon le modèle de Gertsner.]
 */
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
   * classe GerstnerWaveModel. Cette permière version utilise un array [] pour
   * la liste de Gerstner Waves en entrée (type de l'attribut de la classe).]
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
    GerstnerWaveModel(Dvector windDirection, double averageAlignment,
                double intensite, double longueurOnde, double hauteurVague,
                list<GerstnerWave> list, int nbWaves);

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

  /*!
   * [GerstnerWaveModel::operator = afin d'associer toutes les caractéristiques de
   *  gw passée en paramètre à l'objet this]
   * @return [*this]
   */
  GerstnerWaveModel& operator=(const GerstnerWaveModel&);

  /*!
   * [GerstnerWave::GerstnerWave Constructeur par copie]
   * @param other [const GerstnerWave & est un autre objet GertsnerWave]
   */
  GerstnerWaveModel(const GerstnerWaveModel & other);

  private:

  /* list of Gerstner Wave */
  GerstnerWave *ListGerstnerWaves;
  /* number of wave in the list / model */
  int nbWaves;
};

#endif
