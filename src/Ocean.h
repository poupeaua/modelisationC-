#include "Height.h"
#include "WaveModel.h"
class Ocean
{
  public:

  Ocean(double temps, double length, double width, int nx, int ny, Height height, WaveModel model, double *vertices);

  ~Ocean();

  void generateHeight();

  void compute();

  void gl_vertices();

  double getTemps();

  double getLength();

  double getWidth();

  int getNx();

  int getNy();

  *Height getHeight();

  *WaveModel getModel();



  private:

  double temps;
  double length; // Lx
  double width; // Ly
  int nx;
  int ny;
  Height *height;
  WaveModel *model;
  double *vertices;
};
