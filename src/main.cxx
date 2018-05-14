#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */
#include "window.hxx" // appel Ocean.h =>
Ocean *ocean;
int mainwindow;

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */
  int nx = 100;
  int ny = 100;
  double length = 200.0;
  double width = 200.0;

  /** @todo Initialiser du modèle*/
  char model[10] = "";
  strcpy(model, "Gerstner");
  int nbWaves = 1;
  Dvector windDirection(2, 1);
  double averageAlignment = 0.75;
  double intensite = 0.5;
  double longueurOnde = 10;
  double hauteurVague = 2;

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
