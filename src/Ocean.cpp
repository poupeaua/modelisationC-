#include "Ocean.h"
#include "GerstnerWaveModel.h"
#include "PhilipsWaveModel.h"


/* ---------------------------- NEEDED METHODS --------------------------- */


/*!
 * [Ocean Constructeur de base pour la classe ocean]
 * @param temps    [double définissant le temps courant]
 * @param length   [double définissant la longueur de Lx de la plateforme]
 * @param width    [double définissant la largeur de Ly de la plateforme]
 * @param nx       [int représentant le nombre de découpages discrets sur l'axe x]
 * @param ny       [int représentant le nombre de découpages discrets sur l'axe y]
 * @param height   [Height objet tableau mono-dimentionnel pour les hauteurs]
 * @param model    [WaveModel model utilisé]
 * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
 * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
 *                          d'alignement des vagues avec le vent]
 * @param intensite        [double définissant l'intensité des vagues]
 * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
 * @param hauteurVague     [double définissant la hauteur maximale des vagues]
 */
Ocean::Ocean(int nx, int ny, double length, double width, char * model,
              Dvector windDirection,
              double averageAlignment, double intensite, double longueurOnde,
              double hauteurVague)
{
  if (length <= 0 || width <= 0 || nx <= 0 || ny <= 0) {
    throw domain_error(" Les attibuts length, width, nx et ny doivent être"
                       " positifs ou nuls.");
  }
  clock_t temps = clock();
  this->temps = (double) (temps);
  this->nx = nx;
  this->ny = ny;
  this-> length = length;
  this->width= width;
  /* initialize the H attribute in the Ocean object */
  generateHeight(0.0);

  if (strcmp(model, "Gerstner") == 0)
  {
    /* in case the user want a Gerstner Model for the Ocean */
    initializeOceanTypeGerstner(windDirection, averageAlignment, intensite,
                                longueurOnde, hauteurVague);
  }
  else if (strcmp(model, "Philips") == 0)
  {
    /* in case the user want a Philips Model for the Ocean */
    initializeOceanTypePhilips(windDirection, averageAlignment, intensite,
                                longueurOnde, hauteurVague);
  }
  else
  {
    throw runtime_error("Le modèle choisi n'existe pas. Vous pouvez soit"
                        " choisir Gerstner ou Philips.");
  }
}


/*!
 * [Ocean::initializeOceanTypeGerstner Methode de construction pour mieux
 * comprendre le fonctionnement de création de l'objet Ocean suivant le modèle,
 *  ici celui de Gerstner. Facilite la vie de l'utilisateur en créant dans
 *  cette étape les objets adéquats.]
 * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
 * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
 *                          d'alignement des vagues avec le vent]
 * @param intensite        [double définissant l'intensité des vagues]
 * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
 * @param hauteurVague     [double définissant la hauteur maximale des vagues]
 */
void Ocean::initializeOceanTypeGerstner(Dvector windDirection,
            double averageAlignment, double intensite, double longueurOnde,
            double hauteurVague)
{
  int nbWaves = 1;

  /* creation de la premiere onde GertsnerWave*/
  Dvector direction1(2, 1.2);
  double amplitude1 = 10;
  double phase1 = 5.0;
  GerstnerWave G1(direction1, amplitude1, phase1);

  GerstnerWave *ListGerstnerWaves = new GerstnerWave[1]{G1};

  /* initialize a GerstnerWaveModel object */
  this->Model = new GerstnerWaveModel(windDirection, averageAlignment, intensite,
                  longueurOnde, hauteurVague, ListGerstnerWaves, nbWaves);
}


/*!
 * [Ocean::initializeOceanTypePhilips Methode de construction pour mieux
 * comprendre le fonctionnement de création de l'objet Ocean suivant le modèle,
 *  icie celui de Philips.]
 * @param windDirection    [Dvector (dim = 2) indiquant la direction de vent]
 * @param averageAlignment [double compris entre 0 et 1 correspondant au facteur
 *                          d'alignement des vagues avec le vent]
 * @param intensite        [double définissant l'intensité des vagues]
 * @param longueurOnde     [double décrivant la longueur d'onde des vagues]
 * @param hauteurVague     [double définissant la hauteur maximale des vagues]
 */
void Ocean::initializeOceanTypePhilips(Dvector windDirection,
            double averageAlignment, double intensite, double longueurOnde,
            double hauteurVague)
{
  this->Model = new PhilipsWaveModel(windDirection, averageAlignment, intensite,
                  longueurOnde, hauteurVague, nx, ny);
}


/*!
 * [Destructeur classique]
 */
Ocean::~Ocean()
{
  /* free the height attribute */
  /* free the model attribute */
}


/*!
 * [generateHeight Méthode permettant d'initialiser l'objet Heigth pour la
 * hauteur]
 */
Height Ocean::generateHeight(double setHeight)
{
  /* method created just for this purpose */
  H  = Height(nx, ny, setHeight, length, width);
  return H;
}


/*!
 * [compute Methode permettant de générer la hauteur en fonction du temps t]
 */
void Ocean::main_computation()
{
  clock_t temps_now = clock();
  /* change the attribute temps de Ocean */
  this->temps = ((double) temps_now - temps);
  /* compute height */
  for (int y = 0 ; y < ny ; y++)
  {
    for (int x = 0 ; x < nx ; x++)
    {
      /* access to the virtual operator to calculate the height according to
      the position (x, y) and the time t. Then place it into the attribute
      H. Here we work with DOUBLE. */
      H(x, y) = (*Model)(x, y, temps);
    }
  }
}


/* --------------------- GETTER (used in windows.cxx) -----------------------*/


/*!
 * [getTemps Getter classique pour le temps]
 * @return [Retourne le temps actuel attribut temps]
 */
double Ocean::getTemps()
{
  return temps;
}


/*!
 * [getLength Getter classique pour la length Lx]
 * @return [Retourne l'attribut length]
 */
double Ocean::get_lx()
{
  return length;
}


/*!
 * [getWidth description]
 * @return [Retourne l'attribut width]
 */
double Ocean::get_ly()
{
  return width;
}


/*!
 * [getNx description]
 * @return [Retourne l'attribut nx]
 */
int Ocean::getNx()
{
  return nx;
}


/*!
 * [getNy description]
 * @return [Retourne l'attribut ny]
 */
int Ocean::getNy()
{
  return ny;
}


/* ---------------------------- GIVEN METHODS ------------------------------ */

/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x]   = (length/nx)*x;
    vertices[3*x+2] = (width/ny)*y;
  }
  vertices[3*nx]   = length;
  vertices[3*nx+2] = (width/ny)*y;
}

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y]   = (length/nx)*x;
    vertices[3*y+2] = (width/ny)*y;
  }
  vertices[3*ny]   = (length/nx)*x;
  vertices[3*ny+2] = width;
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayX(const int y, double* const vertices) {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*H(x, y);
  }
  vertices[3*nx+1] = pow(-1, nx+y)*H(nx, y);
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayY(const int x, double* const vertices) {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y+1] = H(0, y);
  }
  vertices[3*ny+1]  = H(0,ny);
}
