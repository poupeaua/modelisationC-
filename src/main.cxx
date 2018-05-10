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
  double length = 15.0;
  double width = 15.0;

  /** @todo Initialiser du modèle*/
  char model[10] = "";
  strcpy(model, "Gerstner");
  Dvector windDirection(2, 1);
  double averageAlignment = 0.75;
  double intensite = 1.0;
  double longueurOnde = 5.0;
  double hauteurVague = 20.0;

  /** @todo Initialiser du champ de hauteur */

  /** @todo Initialiser de l'océan */
  Ocean tmpOcean(nx, ny, length, width, model, windDirection, averageAlignment,
                  intensite, longueurOnde, hauteurVague);
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
