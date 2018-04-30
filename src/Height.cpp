#include "Height.h"

/**
 * Constructeur par defaut placant des values (par défaut zero) partout
 **/
Height::Height(int nx, int ny, double value, double length, double width)
{
  this->nx = nx;
  this->ny = ny;
  Dvector height(nx*ny);
  for (int i = 0 ; i < ny ; i++)
  {
    for (int j = 0 ; j < nx ; j++)
    {
      height[i*nx + j] = value;
    }
  }
  this->height = height;
  this->width = width;
  this->length = length;
}


/**
 * Constructeur par recopie
 **/
Height::Height(const Height &other)
{
  this->nx = other.nx;
  this->ny = other.ny;
  Dvector height(nx*ny);
  for (int i = 0 ; i < ny ; i++)
  {
    for (int j = 0 ; j < nx ; j++)
    {
      height[i*nx + j] = other.height[i*nx + j];
    }
  }
  this->height = height;
  this->width = other.width;
  this->length = other.length;
}


/**
 * Constructeur placant les valeurs contenues dans le tableau valeurs
 BEWARE length et width doivent correspondre au tableau valeur
 **/
Height::Height(int nx, int ny, double **valeurs, double length, double width)
{
  /**
  * rajouter les boucles if
  **/
  this->nx = nx;
  this->ny = ny;
  Dvector height(nx*ny);
  for (int i = 0; i < ny; i++)
  {
      for (int j =0; j < nx; j++)
      {
          height[i*nx + j] = valeurs[i][j];
      }
  }
  this->height = height;
  this->width = width;
  this->length = length;
}


/**
 * Constructeur par recopie
 **/
Height::~Height()
{
  /** no new so there are nothing to delete ! **/
}


/**
 getter for nx
**/
int Height::getNx()
{
  return nx;
}


/**
 getter for ny
**/
int Height::getNy()
{
  return ny;
}

/**
 getter for Lx
**/
double Height::getLength()
{
  return length;
}

/**
 getter for Lx
**/
double Height::getWidth()
{
  return this->width;
}

/**
 operator () to access a element
**/
double& Height::operator()(int x, int y)
{
  return height(y*nx + x);
}

ostream& operator<<(ostream &Out, Height &h) {
  for (int i = 0 ; i < h.getNy() ; i++)
  {
    for (int j = 0 ; j < h.getNx() ; j++)
    {
      Out << h(j, i) << " ";
    }
    Out << endl;
  }
  return Out;
}
