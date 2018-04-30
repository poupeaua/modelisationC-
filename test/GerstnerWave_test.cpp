#include "GerstnerWave.h"

int main()
{
  /* creation de la premiere onde */
  Dvector direction1(1, 1);
  double amplitude1 = 10;
  double frequence1 = 0.2;
  double phase1 = 5;
  GerstnerWave G1(direction1, amplitude1, frequence1, phase1);

  /* test basique */
  assert(G1.getFrequence() == 0.2);

  /* creation de la seconde one : test de constructeur par copie */
  GerstnerWave G2(G1);

  /* creation de la deuxieme onde */
  Dvector direction2(2, 1);
  double amplitude2 = 20;
  double frequence2 = 0.5;
  double phase2 = 3;
  GerstnerWave G3(direction2, amplitude2, frequence2, phase2);

  /* test de l'utilisation de l'operateur egal */
  G2 = G3;

  /* initialise 3 GerstnerWaves de paramètres differents
  utilisation d'une ecriture differente de :
  GerstnerWave *list*/
  Dvector direction3(7/6, 8.666);
  double amplitude3 = 56.15484;
  double frequence3 = 64684.216;
  double phase3 = 4.56889;
  GerstnerWave *ListGerstnerWave = new GerstnerWave[3]{
      {direction1, amplitude1, frequence1, phase1},
      {direction2, amplitude2, frequence2, phase2},
      {direction3, amplitude3, frequence3, phase3}
  };

  cout << "OK" << endl;


}
