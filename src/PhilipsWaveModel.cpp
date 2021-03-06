#include "PhilipsWaveModel.h"
#include <chrono>

std::random_device rd{};
/*
-------------------------------- CONSTRUCTORS ---------------------------------
*/


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
PhilipsWaveModel::PhilipsWaveModel(Dvector windDirection, double averageAlignment,
            double intensite, double longueurOnde, double hauteurVague,
            int nx, int ny):

            WaveModel(windDirection, averageAlignment, intensite, longueurOnde,
                      hauteurVague)
{
  this->nx = nx;
  this->ny = ny;
  this->temps = -1;
  this->vitesseVent = 5;
  this->champ_hauteur = TemplateDvector<complex<double>>(nx * ny);
}

/*!
 * [GerstnerWave::GerstnerWave Constructeur par copie]
 * @param other [const GerstnerWave & est un autre objet GertsnerWave]
 */
PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel & other):
            WaveModel(other)
{
    this->nx = other.nx;
    this->ny = other.ny;
    this->temps = other.temps;
    this->champ_hauteur = other.champ_hauteur;
    this->vitesseVent = other.vitesseVent;
}

/*
----------------------------------- METHODS -----------------------------------
*/


/*!
 * [GerstnerWaveModel Destructeur pour GerstnerWaveModel]
 */
PhilipsWaveModel::~PhilipsWaveModel()
{
  //nothing to do
}

/*!
 * [getNx Getter classique pour accéder à l'attribut Nx]
 * @return [this->nx]
 */
int PhilipsWaveModel::getNx(){
  return this->nx;
}


/*!
 * [getNy Getter classique pour accéder à l'attribut Ny]
 * @return [this->ny]
 */
int PhilipsWaveModel::getNy(){
  return this->ny;
}

/*!
 * [getTemps Getter classique pour accéder à l'attribut Temps]
 * @return [this->nx]
 */
double PhilipsWaveModel::getTemps(){
  return this->temps;
}


/*!
 * [getChamp_hauteur Getter classique pour accéder à l'attribut Champ_hauteur]
 * @return [this->ny]
 */
TemplateDvector<complex<double>> PhilipsWaveModel::getChamp_hauteur(){
  return this->champ_hauteur;
}

/*!
 * [PhilipsWaveModel::actualizeHeight actualise le champs des hauteurs si t != temps actuel]
 * @param t [le temps de la boucle rendering]
 */
void PhilipsWaveModel::actualizeHeight(double t){
  if(t!=temps) {
    this->temps = t;
    std::normal_distribution<float> d(0, 1);
    for (int y = 0; y<ny; y++) {
      for (int x = 0; x<nx; x++) {
        Dvector k = Dvector(2, x);
        k[1] = y;
        complex<double> p_gauche = {0,0};
        complex<double> p_droite = {0,0};
        double p1 = philipsModel(k, getHauteurVague(), getLongueurOnde(), getWindDirection(), vitesseVent);
        double p2 = philipsModel(-k, getHauteurVague(), getLongueurOnde(), getWindDirection(), vitesseVent);
        std::mt19937 gen{rd()};
        double samplei = d(gen);
        double sampler = d(gen);
        p_gauche = exp(complex<double>(0, getLongueurOnde()*t))*p1*(complex<double>(sampler, samplei))/sqrt(2);
        p_droite = exp(complex<double>(0, getLongueurOnde()*t))*p2*(complex<double>(sampler, -samplei))/sqrt(2);
        champ_hauteur[y*ny + x] = p_gauche + p_droite;
      }
    }
    for(int i = 0; i<ny; i++) {
      TemplateDvector<complex<double>> transform = TemplateDvector<complex<double>>(nx);
      for (int j = 0; j<nx; j++) {
        transform[j] = champ_hauteur[i*nx + j];
      }
      ifft(transform);
      for (int j = 0; j < nx; j++) {
        champ_hauteur[i*nx + j] = transform[j];
      }
    }
    for(int j = 0; j<nx; j++) {
      TemplateDvector<complex<double>> transform = TemplateDvector<complex<double>>(ny);
      for (int i = 0; i<ny; i++) {
        transform[i] = champ_hauteur[i*nx + j];
      }
      ifft(transform);
      for (int i = 0; i < nx; i++) {
        champ_hauteur[i*nx + j] = transform[i];
      }
    }
  }
}

/*!
 * [philipsModel fonction auxiliaire simulant le modele de Philips]
 * @param  k             [vecteur]
 * @param  intensite     [intensite]
 * @param  longueurOnde  [longueur d'onde]
 * @param  windDirection [direction du vent]
 * @return               [Ph(k)]
 */
double philipsModel(Dvector k, double intensite, double longueurOnde, Dvector windDirection, double vitesseVent) {
  double expo = exp((-1/scalaire(k*vitesseVent, k*vitesseVent)));
  double scal = scalaire(k, windDirection);
  double dem = scalaire(k, k);
  return intensite * expo * pow(scal,2)/dem;
}

/*!
 * [PhilipsWaveModel::operator permettant de calculer la hauteur total z
 * au point (x, y) à l'instant t]
 * @return [double définissant la hauteur total de la vague]
 */
double PhilipsWaveModel::operator()(int x, int y, double t) {
  actualizeHeight(t);
  //return champ_hauteur[y*ny + x].real();
  return abs(champ_hauteur[y*ny + x]);
}

/*
---
*/

/*!
 * Fast Fourier Transform using Cooley Tukey algorithm
 * @param x The vector which will calculate the fourier transform
 */

void fft(TemplateDvector<complex<double>> x){
  if (x.size() <= 1) {
    //nothing to do
  } else {
    TemplateDvector<complex<double>> even = TemplateDvector<complex<double>>(x.size()/2);
    TemplateDvector<complex<double>> odd = TemplateDvector<complex<double>>(x.size()/2);
    for (int k = 0; k < x.size(); k++) {
      if (k%2) {
        even[k/2] = x[k];
      } else {
        odd[k/2] = x[k];
      }
    }
    fft(even);
    fft(odd);
    for (int k = 0; k < x.size()/2; k++) {
      complex<double> t = odd[k] * exp(complex<double>(0,-2.*M_PI*k/x.size()));
      x[k] = even[k] + t;
      x[k+x.size()/2] = even[k] - t;
    }
  }
}

/*!
 * [ifft compute the ifft ]
 * @param x [the parameter to transform, x shoud be a power of 2]
 */
void ifft(TemplateDvector<complex<double>> x){
  if (x.size() <= 1) {
    //nothing to do
  } else {
    for (int k = 0; k < x.size(); k++) {
      x[k] = conj(x[k]);
    }
    fft(x);
    for (int k = 0; k < x.size(); k++) {
      x[k] = conj(x[k]);
    }
    x /= x.size();
  }
};
