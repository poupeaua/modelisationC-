#include "GerstnerWaveModel.h"

int main()
{
  /* ------------ INITIALISATION DE SIMPLES GERTSNER WAVES ----------------- */


  /* creation de la premiere onde */
  Dvector direction1(2, 1.2);
  double amplitude1 = 10;
  double phase1 = 5.0;
  GerstnerWave G1(direction1, amplitude1, phase1);

  /* creation de la deuxieme onde */
  Dvector direction2(2, 1.3);
  double amplitude2 = 20;
  double phase2 = 3.0;
  GerstnerWave G2(direction2, amplitude2, phase2);

  /* creation de l troisieme vague */
  Dvector direction3(2, 2.666);
  double amplitude3 = 56.15484;
  double phase3 = 4.56889;
  GerstnerWave G3(direction3, amplitude3, phase3);

  /* initialise 3 GerstnerWaves  */
  int nbWaves = 3;
  GerstnerWave *ListGerstnerWaves = new GerstnerWave[3]{G1, G2, G3};


  /* ------------ CREATION D'UN OBJET GERTSNER WAVE MODEL ---------------- */


  /* parametres necessaire pour creer un objet gerstner wave model */
  Dvector windDirection(2, 2.2);
  double averageAlignment = 0.75;
  double intensite = 5.0;
  double longueurOnde = 6.0;
  double hauteurVague = 7.6;

  /* initialize a GerstnerWaveModel object */
  GerstnerWaveModel GWM1(windDirection, averageAlignment, intensite,
                  longueurOnde, hauteurVague, ListGerstnerWaves, nbWaves);

  /* test calcul h ou z */
  // for (int t = 0 ; t < 100 ; t++) {
  //   double hauteur = GWM1(1, 2, t*0.1);
  //   cout << hauteur << endl;
  // }
  //
  stringstream str1;
  double hauteur = GWM1(1, 2, 0.33);
  str1 << hauteur << endl;
  assert(str1.str() == "-37.4427\n");


  /* --------------------------- TEST EXCEPTIONS --------------------------- */


  str1.str("");

  /* test de l'exception pour le tableau de GerstnerWave */
  GerstnerWave *ListGerstnerWaves2 = new GerstnerWave[0];

  try
  {
    GerstnerWaveModel * GWM2 = new GerstnerWaveModel(windDirection,
                    averageAlignment, intensite,
                    longueurOnde, hauteurVague, ListGerstnerWaves2, 0);
    delete[] GWM2; // just to make GWM2 be called once (avoid warning)
  }
  catch (exception const& e)
  /* faire attention au free => corriger : pb d'avant est que comme on catch
  on ne free pas en suivant, il a fallu donc sortir la création de la
  ListGerstnerWaves2 en dehors du try ainsi que le delete[] associé */
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : La tableau passé en argument"
    " doit contenir au moins une GerstnerWave.\n");
  str1.str("");

  delete[] ListGerstnerWaves2;

  /* ----------------- TEST EXCEPTIONS GENERAUX : WAVE MODEL --------------- */




  /* test de l'exception pour la direction du vent */
  try
  {
    Dvector windDirection(1, 5);
    GerstnerWaveModel GWM1(windDirection, averageAlignment, intensite,
                    longueurOnde, hauteurVague, ListGerstnerWaves, nbWaves);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : la direction du vent doit"
    " être précisément de deux.\n");
  str1.str("");


  /* test de l'exception pour l'alignement moyen */
  try
  {
    double averageAlignment = 5.3;
    GerstnerWaveModel GWM1(windDirection, averageAlignment, intensite,
                    longueurOnde, hauteurVague, ListGerstnerWaves, nbWaves);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : L'alignement moyen doit être"
    " un double compris entre 0 et 1.\n");
  str1.str("");


  /* test de l'exception pour l'intensite */
  try
  {
    double intensite = -0.5;
    GerstnerWaveModel GWM1(windDirection, averageAlignment, intensite,
                    longueurOnde, hauteurVague, ListGerstnerWaves, nbWaves);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : l'intensité, la longueur d'onde"
    " ainsi que la hauteur des vagues doit être positive.\n");
  str1.str("");


  cout << "OK" << endl;

}
