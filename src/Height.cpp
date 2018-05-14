#include "Height.h"
#include "ErreurAcces.h"
#include "ErreurAllocation.h"

/*!
 * [Height::Height Constructeur par défaut de Height. La valeur de tous les
 * attributs sont choisis pour l'utilisateur.]
 */
Height::Height()
{
  int default_nx = 5;
  int default_ny = 5;
  double default_value = 0.0;
  double default_length = 1000.0;
  double default_width = 1000.0;
  Height(default_nx, default_ny, default_value, default_length, default_width);
}

/*!
 * [Height::Height Constructeur pour Height. L'utilisateur peut alors choisir
 * la valeur des attributs.]
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
 * [setHeightTo Set all the elements in the mono-dimentionnal Dvector
 * attribute named height to setHeight]
 * @param setHeight [double setHeight]
 */
void Height::setHeightTo(double setHeight)
{
  for (int i = 0 ; i < ny ; i++)
  {
      for (int j = 0 ; j < nx ; j++)
      {
        height[i*nx + j] = setHeight;
      }
  }
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
  // cout << nx << endl;
  // cout << ny << endl;
  if (indice < 0 || indice > nx*ny-1) {
    throw ErreurAcces("Erreur d'accès avec l'opérateur () de Height.");
  }
  return height(indice);
}


Height& Height::operator=(Height &h)
{
  this->length = h.getLength(); // Lx
  this->width = h.getWidth(); // Ly
  this->nx = h.getNx();
  this->ny = h.getNy();

  /*
  BEWARE !!! => don't forget to delete[] before making a new vect
  LONG Debug to find that !
  */

  /* met à jour le nouvel attribut height */
  this->height = Dvector(nx*ny);
  for (int i = 0 ; i < ny ; i++)
  {
    for (int j = 0 ; j < nx ; j++)
    {
      height(i*nx + j) = h(j, i);
    }
  }
  return *this;
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
