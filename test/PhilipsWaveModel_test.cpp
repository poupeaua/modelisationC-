#include "PhilipsWaveModel.h"
//
int main()
{
  /* ------------ CREATION D'UN OBJET PHILIPS WAVE MODEL ---------------- */


  /* parametres necessaire pour creer un objet gerstner wave model */
  Dvector windDirection(2, 2.2);
  double averageAlignment = 0.75;
  double intensite = 5.0;
  double longueurOnde = 6.0;
  double hauteurVague = 7.6;
  int nx = 64;
  int ny = 64;

  /* initialize a GerstnerWaveModel object */
  PhilipsWaveModel PWM1(windDirection, averageAlignment, intensite,
                  longueurOnde, hauteurVague, nx, ny);

  /*Tester si le renvoi de la hauteur est bon*/
  double a = PWM1(31, 31, 1.5);
  cout<<a<<endl;

  /*---------------Test de la ifft et de la fft--------------------------*/

  /* Teste la fft en 1d */

  TemplateDvector<complex<double>> d1 = TemplateDvector<complex<double>>(8, 0);
  for (int i = 2; i<5; i++) {
    d1(i) = 1;
  }
  TemplateDvector<complex<double>> f1 = d1;
  fft(d1);
  ifft(d1);

  assert(f1 == d1);

  TemplateDvector<complex<double>> d2 = TemplateDvector<complex<double>>(16, 0);

  for(int i = 5; i<7; i++) {
    d2(i) = 1;
  }
  for(int i = 9; i<11; i++) {
    d2(i) = 1;
  }

  /* Teste la fft en 2d */

  TemplateDvector<complex<double>> f2 = d2;

  for(int i = 0; i<4; i++) {
    TemplateDvector<complex<double>> transform = TemplateDvector<complex<double>>(4);
    for (int j = 0; j<4; j++) {
      transform[j] = d2[i*4 + j];
    }
    fft(transform);
    for (int j = 0; j < 4; j++) {
      d2[i*4 + j] = transform[j];
    }
  }
  for(int j = 0; j<4; j++) {
    TemplateDvector<complex<double>> transform = TemplateDvector<complex<double>>(4);
    for (int i = 0; i<4; i++) {
      transform[i] = d2[i*4 + j];
    }
    fft(transform);
    for (int i = 0; i < 4; i++) {
      d2[i*4 + j] = transform[i];
    }
  }
  for(int i = 0; i<4; i++) {
    TemplateDvector<complex<double>> transform = TemplateDvector<complex<double>>(4);
    for (int j = 0; j<4; j++) {
      transform[j] = d2[i*4 + j];
    }
    ifft(transform);
    for (int j = 0; j < 4; j++) {
      d2[i*4 + j] = transform[j];
    }
  }
  for(int j = 0; j<4; j++) {
    TemplateDvector<complex<double>> transform = TemplateDvector<complex<double>>(4);
    for (int i = 0; i<4; i++) {
      transform[i] = d2[i*4 + j];
    }
    ifft(transform);
    for (int i = 0; i < 4; i++) {
      d2[i*4 + j] = transform[i];
    }
  }
  assert(f2 == d2);
}
