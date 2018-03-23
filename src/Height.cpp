#include "Height.h"


/**
 * Constructeur par defaut placant les valeurs contenues dans le tableau valeurs
 BEWARE longueur et largeur doivent correspondre au tableau valeur
 **/
Height::Height(int longueur, int largeur, int **valeurs)
{
  /**
  * rajouter les boucles if
  **/
  this->longueur = longueur;
  this->largeur = largeur;
  height = new int*[largeur];
  for (int i = 0; i < largeur; i++)
  {
      height[i] = new int[longueur];
      for (int j =0; j < longueur; j++)
      {
          height[i][j] = valeurs[i][j];
      }
  }
}


/**
 * Constructeur par defaut placant des zeros partout
 **/
Height::Height(int longueur, int largeur)
{
  this->longueur = longueur;
  this->largeur = largeur;
  height = new int*[largeur];
  for (int i = 0; i < largeur; i++)
  {
      height[i] = new int[longueur];
      for (int j =0; j < longueur; j++)
      {
          height[i][j] = 0;
      }
  }
}


/**
 * Constructeur par recopie
 **/
Height::Height(const Height &other)
{
  this->longueur = other.longueur;
  this->largeur = other.largeur;
  height = new int*[largeur];
  for (int i = 0 ; i < largeur ; i++)
  {
    height[i] = new int[longueur];
    for (int j = 0 ; j < longueur ; j++)
    {
      height[i][j] = other.height[i][j];
    }
  }
}


/**
 * Constructeur par recopie
 **/
Height::~Height()
{
  for (int i = 0 ; i < largeur ; i++)
  {
    delete[] height[i];
  }
  delete[] height;
}
