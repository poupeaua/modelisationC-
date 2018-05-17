#ifndef PHILIPS_WAVE_MODEL_H
#define PHILIPS_WAVE_MODEL_H
#include "WaveModel.h"
#include "TemplateDvector.h"
#include "Dvector.h"
#include <math.h>
#include <random>



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
              double intensite, double longueurOnde, double hauteurVague,
              int nx, int ny);

  /*!
   * [PhilipsWaveModel Destructeur pour PhilipsWaveModel]
   */
  virtual ~PhilipsWaveModel();

  // /*!
  //  * [PhilipsWaveModel::operator = afin d'associer toutes les caractéristiques de
  //  *  gw passée en paramètre à l'objet this]
  //  * @return [*this]
  //  */
  // PhilipsWaveModel& operator=(const PhilipsWaveModel&);

  /*!
   * [PhilipsWave::PhilipsWave Constructeur par copie]
   * @param other [const PhilipsWave & est un autre objet GertsnerWave]
   */
   PhilipsWaveModel(const PhilipsWaveModel & other);

   /*!
    * [getNx Getter classique pour accéder à l'attribut Nx]
    * @return [this->nx]
    */
   int getNx();


   /*!
    * [getNy Getter classique pour accéder à l'attribut Ny]
    * @return [this->ny]
    */
   int getNy();

   /*!
    * [getTemps Getter classique pour accéder à l'attribut Temps]
    * @return [this->nx]
    */
   double getTemps();


   /*!
    * [getCahmp_hauteur Getter classique pour accéder à l'attribut Champ_hauteur]
    * @return [this->ny]
    */
   TemplateDvector<complex<double>> getChamp_hauteur();

   /*!
    * [PhilipsWaveModel::actualizeHeight actualise le champs des hauteurs si t != temps actuel]
    * @param t [le temps de la boucle rendering]
    */
   void actualizeHeight(double t);

  private:

  int nx;
  int ny;
  TemplateDvector<complex<double>> champ_hauteur;
  double temps;
  double vitesseVent;

};

  double philipsModel(Dvector k, double intensite, double longueurOnde, Dvector windDirection, double vitesseVent);

  void fft(TemplateDvector<complex<double>> x);

  void ifft(TemplateDvector<complex<double>> x);

#endif
