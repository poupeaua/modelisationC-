#ifndef HEIGHT_H
#define HEIGHT_H
#include "Dvector.h"
#endif

using namespace std;


/*
Model of heigth object
Convention of axis x and y in informatics used

  L O N G U E U R  = x
L
A
R
G
E
U
R
=
y

*/

class Height
{
  public:

  Height(int nx, int ny, double value = 0.0, double length = 1.0, double width = 1.0);
  Height(const Height & other);
  Height(int nx, int ny, double **height, double length = 1.0, double width = 1.0);
  ~Height();
  /* accessor */
  double getLength();
  double getWidth();
  int getNx();
  int getNy();
  double& operator()(int x, int y);

  private:

  double length; // Lx
  double width; // Ly
  int nx;
  int ny;
  Dvector height;
};

ostream& operator<<(ostream &Out, Height &h);
istream& operator>>(istream &in, Height &h);
