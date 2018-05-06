#include "GerstnerWave.h"

int main()
{
  /* creation de la premiere onde */
  Dvector direction1(2, 1);
  double amplitude1 = 10;
  double phase1 = 5.0;
  GerstnerWave G1(direction1, amplitude1, phase1);


  /* test basique sur la premiere onde G1 */
  Dvector directionTest1(2, 1);
  assert(G1.getAmplitude() == 10);
  assert(G1.getFrequence() == sqrt(G*direction1.norm(2)));
  assert(G1.getPhase() == 5.0);
  assert(G1.getDirection() == directionTest1);


  /* creation de la seconde : test de constructeur par copie sur G2*/
  GerstnerWave G2(G1);
  assert(G2.getAmplitude() == 10);
  assert(G2.getFrequence() == sqrt(G*direction1.norm(2)));
  assert(G2.getPhase() == 5.0);
  assert(G2.getDirection() == directionTest1);


  /* creation de la troisieme onde */
  Dvector direction2(2, 1);
  double amplitude2 = 20;
  double phase2 = 3.0;
  GerstnerWave G3(direction2, amplitude2, phase2);

  /* test avec la troisieme onde */
  Dvector directionTest3(2, 1);
  assert(G3.getAmplitude() == 20);
  assert(G3.getFrequence() == sqrt(G*direction2.norm(2)));
  assert(G3.getPhase() == 3.0);
  assert(G3.getDirection() == directionTest3);


  /* test de l'utilisation de l'operateur egal pour changer G2 */
  G2 = G3;
  assert(G2.getAmplitude() == 20);
  assert(G2.getFrequence() == sqrt(G*direction2.norm(2)));
  assert(G2.getPhase() == 3.0);
  assert(G2.getDirection() == directionTest3);


  /* initialise 3 GerstnerWaves de paramètres differents
  utilisation d'une ecriture differente de :
  GerstnerWave *list = new GertsnerWave[3] => constructeur par défaut 3 fois
  En plus, utilisation de deux constructeur différents*/
  Dvector direction3(2, 8.666);
  double amplitude3 = 56.15484;
  double phase3 = 4.56889;
  GerstnerWave *ListGerstnerWave = new GerstnerWave[3]{
      {direction1, amplitude1, phase1},
      G2,
      {direction3, amplitude3, phase3}
  };

  /* test associe a la ListGerstnerWave */
  assert(ListGerstnerWave[2].getDirection() == direction3);
  assert(ListGerstnerWave[2].getAmplitude() == 56.15484);
  assert(ListGerstnerWave[2].getFrequence() == sqrt(G*direction3.norm(2)));
  assert(ListGerstnerWave[2].getPhase() == 4.56889);


  /* -------------------------- TEST EXCEPTIONS ---------------------------- */


  stringstream str1;

  /* test de l'exception pour l'amplitude */
  try
  {
    double amplitude1 = -0.5;
    GerstnerWave G4(direction1, amplitude1, phase1);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : L'amplitude, la distance au"
      " sol ainsi que la tension de surface doivent être positifs.\n");
  str1.str("");


  /* test de l'exception pour la phase */
  try
  {
    double phase1 = -0.5;
    GerstnerWave G4(direction1, amplitude1, phase1);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : L'amplitude, la distance au"
      " sol ainsi que la tension de surface doivent être positifs.\n");
  str1.str("");


  /* test de l'exception pour la direction */
  try
  {
    Dvector direction1(3, 2.5);
    GerstnerWave G4(direction1, amplitude1, phase1);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : La direction doit être de"
      " dimension deux.\n");
  str1.str("");


  /* test de l'exception pour la distance au sol */
  try
  {
    double distanceAuSol = -7.999;
    GerstnerWave G4(direction1, amplitude1, phase1, 2, distanceAuSol);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : L'amplitude, la distance au"
      " sol ainsi que la tension de surface doivent être positifs.\n");
  str1.str("");


  /* test de l'exception pour le facteur de tension de surface */
  try
  {
    double L = -1.5;
    GerstnerWave G4(direction1, amplitude1, phase1, 3, 10.5, L);
  }
  catch (exception const& e)
  {
    str1 << "ERREUR : " << e.what() << endl;
  }
  assert(str1.str() == "ERREUR : Argument invalide : L'amplitude, la distance au"
      " sol ainsi que la tension de surface doivent être positifs.\n");
  str1.str("");


  cout << "OK" << endl;
}
