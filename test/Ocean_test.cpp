#include "Ocean.h"
#include "GerstnerWave.h"
#include "GerstnerWaveModel.h"

int main()
{

  /* -------------------- OCEAN TYPE = GERTSNERWAVEMODEL ------------------- */


  /* test creation ocean */
  double length = 5.5;
  double width = 56.3;
  int nx = 1.0;
  int ny = 5.0;

  Height h(nx, ny);

  /* parametres necessaire pour creer un objet gerstner wave model */
  int nbWaves = 8;
  Dvector windDirection(2, 2.2);
  double averageAlignment = 0.75;
  double intensite = 5.0;
  double longueurOnde = 6.0;
  double hauteurVague = 7.6;

  /* initialize a GerstnerWaveModel object */
  char char_model[10] = "";
  strcpy(char_model, "Gerstner");

  Ocean* oceanEleven = new Ocean(nx, ny, length, width, char_model, windDirection,
                                averageAlignment, intensite, longueurOnde,
                                hauteurVague, h, nbWaves);

  delete oceanEleven;


  /* -------------------- OCEAN TYPE = PHILIPSWAVEMODEL ------------------- */


  strcpy(char_model, "Philips");

  Ocean* ocean2 = new Ocean(nx, ny, length, width, char_model, windDirection,
                                averageAlignment, intensite, longueurOnde,
                                hauteurVague, h, nbWaves);

  delete ocean2;


  /* ----------------------------  EXCEPTIONS  ---------------------------- */

}
