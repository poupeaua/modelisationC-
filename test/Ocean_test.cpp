#include "Ocean.h"
#include "GerstnerWave.h"
#include "GerstnerWaveModel.h"

int main()
{
  /* test creation ocean */
  // double temps = 0.0;
  // double length = 5.5;
  // double width = 56.3;
  // int nx = 1.0;
  // int ny = 5.0;
  //
  // /* ---------------------------- HEIGHT OBJECT ---------------------------- */
  //
  // Height height(nx, ny);
  //
  // /* ----------------------- GERTSNERWAVEMODEL OBJECT ---------------------- */
  //
  // int nbWaves = 1;
  //
  // /* creation de la premiere onde GertsnerWave*/
  // Dvector direction1(2, 1.2);
  // double amplitude1 = 10;
  // double phase1 = 5.0;
  // GerstnerWave G1(direction1, amplitude1, phase1);
  //
  // GerstnerWave *ListGerstnerWaves = new GerstnerWave[1]{G1};
  //
  // /* parametres necessaire pour creer un objet gerstner wave model */
  // Dvector windDirection(2, 2.2);
  // double averageAlignment = 0.75;
  // double intensite = 5.0;
  // double longueurOnde = 6.0;
  // double hauteurVague = 7.6;
  //
  // /* initialize a GerstnerWaveModel object */
  // GerstnerWaveModel* model = new GerstnerWaveModel(windDirection, averageAlignment, intensite,
  //                 longueurOnde, hauteurVague, ListGerstnerWaves, nbWaves);
  //
  // WaveModel* model2 = (WaveModel *) (model);

  // Ocean* oceanEleven = new Ocean(temps, length, width, nx, ny, height, model2);
  //
  // delete oceanEleven;
}
