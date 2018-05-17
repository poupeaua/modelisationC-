#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */
#include "window.hxx" // appel Ocean.h =>
Ocean *ocean;
int mainwindow;

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */
  int nx;
  int ny;
  double length = 1000;
  double width = 1000;

  /** @todo Initialiser du modèle*/
  if (argc <= 1 || argc > 2)
  {
    throw invalid_argument("./Main_Visualisation doit avoir un argument :"
                           " Gerstner ou Philips");
  }
  char model[10] = "";
  strcpy(model, argv[1]);
  // number of waves (just for GerstnerWave)
  int nbWaves;
  // wind direction
  Dvector windDirection(2);
  // average alignement number in [0, 1]
  double averageAlignment;
  // change the speed of the wave (bigger jump for update in time)
  double intensite;
  // height of the wave
  double hauteurVague;
  // change the frenquency of the wave based on the amplitude
  double longueurOnde;

  if (strcmp(model, "Philips") == 0) {
    /* differents parametres que l'utilisateur peut choisir pour Gerstner et Philips */
    nx = 64; // multiple de 2
    ny = 64; // multiple de 2
    windDirection(0) = 1;
    windDirection(1) = 1;
    averageAlignment = 0.5;
    intensite = 0.8;
    longueurOnde = 2;
    hauteurVague = .4;
  } else if (strcmp(model, "Gerstner") == 0) {
    nx = 200;
    ny = 200;
    nbWaves = 1;
    windDirection(0) = 1;
    windDirection(1) = 1;
    averageAlignment = 0.0;
    intensite = 0.4;
    hauteurVague = 6;
    longueurOnde = hauteurVague;
  } else {
    throw invalid_argument("Argument de type de vague inconnu. Arguments possible :"
                           " Gerstner ou Philips");
  }

  /** @todo Initialiser du champ de hauteur */
  double hauteur_initiale = 0.0;
  Height tmph(nx, ny, hauteur_initiale, length, width);

  /** @todo Initialiser de l'océan */
  Ocean tmpOcean(nx, ny, length, width, model, windDirection, averageAlignment,
                  intensite, longueurOnde, hauteurVague, tmph, nbWaves);
  /* extern ocean value used in windows.hxx */
  ocean = &tmpOcean;
  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);
  /* Execute la simulation */
  Window::launch();
  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;
}
