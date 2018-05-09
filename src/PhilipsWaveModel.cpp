#include "PhilipsWaveModel.h"



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
 * @param list             [list est un tableau d'objets GerstnerWave]
 */
PhilipsWaveModel::PhilipsWaveModel(Dvector windDirection, double averageAlignment,
            double intensite, double longueurOnde, double hauteurVague):

            WaveModel(windDirection, averageAlignment, intensite, longueurOnde,
                      hauteurVague)
{

}

/*!
 * [GerstnerWave::GerstnerWave Constructeur par copie]
 * @param other [const GerstnerWave & est un autre objet GertsnerWave]
 */
PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel & other):
            WaveModel(other)
{

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

double philips_model(Dvector k, double intensite, double longueurOnde, Dvector windDirection) {
  double expo = exp((-1/scalaire(k*longueurOnde, k*longueurOnde));
  double scalaire = pow(,2) 
}

/*!
 * [PhilipsWaveModel::operator permettant de calculer la hauteur total z
 * au point (x, y) à l'instant t]
 * @return [double définissant la hauteur total de la vague]
 */
double PhilipsWaveModel::operator()(int x, int y, double t) {
  for(int i = 0; i<Lx; i++) {
    ifft(ligne)
  }
  for (int j = 0; j<Ly; j++){
    ifft(colonne)
  }
  Dvector k = Dvector(2, x);
  k[1] = y;
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
    for (size_t k = 0; k < x.size(); k++) {
      if (k%2) {
        even[k/2] = x[k];
      } else {
        odd[k/2] = x[k];
      }
    }
    fft(even);
    fft(odd);
    for (size_t k = 0; k < x.size()/2; k++) {
      complex<double> t = odd[k] * exp(complex<double>(0,-2.*M_PI*k/x.size()));
      x[k] = even[k] + t;
      x[k+x.size()/2] = even[k] - t;
    }
  }
}

void ifft(TemplateDvector<complex<double>> x){
  if (x.size() <= 1) {
    //nothing to do
  } else {
    for (size_t k = 0; k < x.size(); k++) {
      x[k] = conj(x[k]);
    }
    fft(x);
    for (size_t k = 0; k < x.size(); k++) {
      x[k] = conj(x[k]);
    }
    x /= x.size();
  }
}
