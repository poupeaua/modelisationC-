#include "Height.h"


/*!
 * [Height::Height Constructeur par défaut plaçant des valeurs (par défaut zero)]
 * @param nx     [int définisant le nombre de discrétisation selon l'axe x]
 * @param ny     [int définisant le nombre de discrétisation selon l'axe y]
 * @param value  [double définissant la value à associer à chaque éléments de
 *                l'attribut height de l'objet Height]
 * @param length [double caractérisant la longueur physique de la surface]
 * @param width  [double caractérisant la largeur physique de la surface]
 */
Height::Height(int nx, int ny, double value, double length, double width)
{
  if (nx <= 0 || ny <= 0) {
    throw ErreurAllocation();
  } else if (length <= 0 || width <= 0) {
    throw invalid_argument("Erreur paramètre length ou width négatif ou nul.");
  }
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


/*!
 * [Height::Height Constructeur par copie]
 * @param other [Height objet qui est utilisé pour la copie]
 */
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


 /*!
  * [Height::Height Constructeur placant les valeurs contenues dans le tableau
  * valeurs BEWARE length et width doivent correspondre au tableau valeur]
  * @param valeurs  [tableau de double définissant la value à associer à chaque
  *                  éléments de l'attribut height de l'objet Height]
  * @param length [double caractérisant la longueur physique de la surface]
  * @param width  [double caractérisant la largeur physique de la surface]
  */
Height::Height(int nx, int ny, double **valeurs, double length, double width)
{
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


/*!
 * [Height destructeur]
 */
Height::~Height()
{
  /** no new so there are nothing to delete ! **/
}


/*!
 * [Height::getNx accesseur classique pour nx]
 * @return [int attribut nx]
 */
int Height::getNx()
{
  return nx;
}


/*!
 * [Height::getNx accesseur classique pour ny]
 * @return [int attribut ny]
 */
int Height::getNy()
{
  return ny;
}


/*!
 * [Height::getNx accesseur classique pour Lx]
 * @return [double attribut Lx]
 */
double Height::getLength()
{
  return length;
}


/*!
 * [Height::getNx accesseur classique pour Ly]
 * @return [int attribut Ly]
 */
double Height::getWidth()
{
  return this->width;
}


/*!
 * [Height::operator () permettant d'accéder à l'élément situer à la ligne x
 * et à la colonne y]
 * @return [double représentant la valeur au point x et y]
 */
double& Height::operator()(int x, int y)
{
  int indice = y*nx + x;
  if (indice < 0 || indice > nx*ny-1) {
    throw ErreurAcces();
  }
  return height(indice);
}


/*!
 * [Height::operator << permettant d'afficher un objet Height sur la sortie
 * souhaitée Out]
 * @return [ostream& où est copié le contenu de l'attibut height de l'objet
 * Height]
 */
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
