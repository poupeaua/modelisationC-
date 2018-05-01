#include "GerstnerWaveModel.h"

int main()
{
  /* ------------ INITIALISATION DE SIMPLES GERTSNER WAVES ----------------- */

  /* creation de la premiere onde */
  Dvector direction1(1, 1);
  double amplitude1 = 10;
  double phase1 = 5.0;
  GerstnerWave G1(direction1, amplitude1, phase1);

  /* creation de la deuxieme onde */
  Dvector direction2(2, 1);
  double amplitude2 = 20;
  double phase2 = 3.0;
  GerstnerWave G2(direction2, amplitude2, phase2);

  /* creation de l troisieme vague */
  Dvector direction3(2, 8.666);
  double amplitude3 = 56.15484;
  double phase3 = 4.56889;
  GerstnerWave G3(direction3, amplitude3, phase3);

  /* initialise 3 GerstnerWaves  */
  GerstnerWave *ListGerstnerWaves = new GerstnerWave[3]{G1, G2, G3};



  /* ------------ CREATION D'UN L'OBJET GERTSNER WAVE MODEL ---------------- */

  /* parametres necessaire pour creer un objet gerstner wave model */
  Dvector windDirection(2, 2);
  double averageAlignment = 0.75;
  double intensite = 5.0;
  double longueurOnde = 6.0;
  double hauteurVague = 7.6;

  /* initialize a GerstnerWaveModel object */
  GerstnerWaveModel GWM1(windDirection, averageAlignment, intensite,
                         longueurOnde, hauteurVague, ListGerstnerWaves);

  cout << "OK" << endl;

}
