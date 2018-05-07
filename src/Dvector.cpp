#include "Dvector.h"
#include "ErreurAcces.h"
#include "ErreurAllocation.h"

/*
--------------------------- CONSTRUCTOR ----------------------------------------
*/

/*!
 * [Dvector::Dvector constructeur par défaut]
 */
Dvector::Dvector()
{
  // créé un vecteur de taille 2 avec pour coordonnées (0, 0)
  int taille = 2;
  double val = 0.0;
  vect = new double[taille];
  for (int i = 0 ; i < taille ; i++)
  {
    vect[i] = val;
  }
  this->taille = taille;
}


/*!
 * [Dvector::Dvector constructeur précisant la taille et une option val
   permettant d'initialiser toute les coordonnées du vecteur à val]
 * @param taille [int définissant la taille du Dvector]
 * @param val    [double valeur qui sera associé à tous les éléments du Dvector]
 */
Dvector::Dvector(int taille, double val)
{
  if (taille <= 0) {
    // cout << "ERROR : negative size." << endl;
    // exit(EXIT_FAILURE)
    throw ErreurAllocation();
  }
  vect = new double[taille];
  for (int i = 0 ; i < taille ; i++)
  {
    vect[i] = val;
  }
  this->taille = taille;
}


/*!
 * [Dvector::Dvector constructeur par copie]
 * @param other [Dvector autre Dvector élément dont chaque caractéristique
 *               sera copiée]
 */
Dvector::Dvector(const Dvector & other)
{
  double *tmp = other.vect;
  int size = other.taille;
  vect = new double[size];
  for (int i = 0 ; i < size ; i++)
  {
    vect[i] = tmp[i];
  }
  this->taille = size;
}


/*!
 * [Dvector::Dvector constructeur utilisant un fichier pour lire les
 * coordonnées]
 * @param src [string désignant le nom d'un fichier. Le contenu de ce fichier
 *  sera ensuite copié dans le Dvector]
 */
Dvector::Dvector(string src)
{
  string line;
  ifstream myfile(src.c_str());

  /* premiere boucle pour compter le nombre d'elements
  */
  int nbr_element = 0;
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      nbr_element++;
    }
  }
  else {
    // cout << "ERROR : Unable to open file" << endl;
    // exit(EXIT_FAILURE);
    throw runtime_error("Impossible d'ouvrir le fichier.");
  }

  /* deuxieme boucle pour inserer les elements dans le vecteurs
  */
  if (nbr_element <= 0) {
    throw ErreurAllocation();
  }
  this->taille = nbr_element;
  vect = new double[nbr_element];
  int i = 0;
  // ces deux lignes permette de retourner au debut du fichier (et donc de le relire depuis le debut)
  myfile.clear();
  myfile.seekg(0, ios::beg);
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      vect[i] = atof(line.c_str());
      i++;
    }
    myfile.close();
  }
  // cout << "i = " << i << " et nbr_element = " << nbr_element << endl;
  assert(nbr_element == i);
}


/*
------------------------------------ METHOD -----------------------------------
*/


/*!
 * [Dvector Destructeur libérant la memoire]
 */
Dvector::~Dvector()
{
  delete[] vect;
}



/*!
 * [Dvector::display Methode permettant d'afficher le contenu d'un vecteur
 *  sur la sortie demandée]
 * @param str [ostream& objet définissant sur quelle sortie le contenu du
 *  Dvector sera copié]
 */
void Dvector::display(ostream& str)
{
  double *tmp = this->vect;
  for (int i = 0 ; i < this->taille ; i++)
  {
    // on peut mettre *(tmp + i) à la place de tmp[i]
    if ((int)tmp[i] == tmp[i]) {
      str << setprecision(1) << fixed << tmp[i] << endl;
    } else {
      // remet la percision par défaut
      str << setprecision(6) << tmp[i] << endl;
    }
  }
}


/*!
 * [Dvector::size Getter classique pour la taille du Dvector]
 * @return [int définissant le taille du Dvector]
 */
int Dvector::size()
{
  return this->taille;
}


/*!
 * [Dvector::norm Retourne la p-norme du Dvector.
 * Si p = 2, c'est la norme Euclidienne => qu'on utilisera mais on permet
 * une souplesse au cas où.]
 * @param  p [int définissant ainsi la p-norme. La norme Euclidienne se définit
 * pour p=2]
 * @return   [p-norme du Dvector]
 */
double Dvector::norm(int p)
{
  double norm = 0;
  for (int i = 0 ; i < this->taille ; i++)
  {
    norm += pow(vect[i], p);
  }
  return pow(norm, 1/p);
}


/*!
 * [Dvector::fillRandomly Methode permettant de remplir toutes les coordonnées
 * d'un vecteur avec des double compris entre 0 et 1]
 */
void Dvector::fillRandomly()
{
  srand(time(NULL));
  double *tmp = this->vect;
  for (int i = 0 ; i < this->taille ; i++)
  {
    tmp[i] = (static_cast <float> (rand()))/ static_cast <float> (RAND_MAX);
  }
}


/*!
 * [Dvector::resize Méthode permettant de redimensionner un Dvector]
 * @param new_taille [int définissant la nouvelle taille du Dvector qui peut
 *                    être plus grande ou plus petite que celle initiale]
 * @param new_ele    [double définissant la valeur des nouveaux éléments
 *                    dans le Dvector si la nouvelle taille est plus grande.]
 */
void Dvector::resize(int new_taille, double new_ele)
{
  double *new_vect = new double[new_taille];
  // new_vect = (double *) realloc(vect, new_taille * sizeof(double));
  for (int i = 0 ; i < min(taille, new_taille) ; i++) {
    new_vect[i] = vect[i];
  }

  // delete[] this->vect;
  if (new_taille > taille) {
    for (int i = taille ; i < new_taille ; i++) {
      new_vect[i] = new_ele;
    }
  }

  delete[] vect;
  this->vect = new_vect;
  this->taille = new_taille;
}


/*
----------------------------------- OPERATOR ---------------------------------
*/


/*!
 * [Dvector::operator[] opérateur d'accession [] à un élément du vecteur]
 * @param  i [description]
 * @return   [description]
 */
double& Dvector::operator[](int i)
{
  if ((i<0)||(i>=taille)) {
    // exit(1);
    throw ErreurAcces();
  }
  return vect[i];
}


/*!
 * [Dvector::operator[] opérateur d'accession [] à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
const double& Dvector::operator[](int i) const
{
  if ((i<0)||(i>=taille)) {
    // exit(1);
    throw ErreurAcces();
  }
  return vect[i];
}


/*!
 * [Dvector::operator[] opérateur d'accession () à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
double& Dvector::operator()(int i)
{
  if ((i<0)||(i>=taille)) {
    // exit(1);
    throw ErreurAcces();
  }
  return vect[i];
}


/*!
 * [Dvector::operator[] opérateur d'accession () à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
const double& Dvector::operator()(int i) const
{
  if ((i<0)||(i>=taille)) {
    // exit(1);
    throw ErreurAcces();
  }
  return vect[i];
}


Dvector& Dvector::operator=(const Dvector& dv)
{
  taille = dv.taille;
  /*
  BEWARE !!! => don't forget to delete[] before making a new vect
  LONG Debug to find that !
  */
  delete[] vect;
  vect = new double[taille];
  // memcpy(vect, dv.vect, taille*sizeof(double));
  for (int i = 0 ; i < taille ; i++) {
    vect[i] = dv[i];
  }
  return *this;
}


Dvector& Dvector::operator+=(const Dvector& dv)
{
  if (taille!=dv.taille) {
    // exit(1);//dimension incompatible
    throw ErreurAcces();
  }
  Dvector& vct = *this;
  for (int i=0;i<taille;i++)
    vct.vect[i] += dv.vect[i];
  return vct;
}


/*implementation de l'operateur += avec un reel
*/
Dvector& Dvector::operator+=(const double d)
{
  Dvector& vct = *this;
  for (int i=0;i<taille;i++)
    vct.vect[i] += d;
  return vct;
}


/*implementation de l'operateur *= avec un reel
*/
Dvector& Dvector::operator*=(const double d)
{
  Dvector& vct = *this;
  for (int i=0;i<taille;i++)
    vct.vect[i] *= d;
  return vct;
}


/*implementation de l'operateur -= avec un autre vecteur
*/
Dvector& Dvector::operator-=(const Dvector& dv)
{
  if (taille!=dv.taille) {
    // exit(-1);//dimension incompatible
    throw ErreurAcces();
  }
  Dvector& vct = *this;
  vct += -1*dv;
  return vct;
}


/*implementation de l'operateur -= avec un reel
*/
Dvector& Dvector::operator-=(const double d)
{
  Dvector& vct = *this;
  vct += -d;
  return vct;
}


/*implementation de l'operateur /= avec un reel
*/
Dvector& Dvector::operator/=(const double d)
{
  if (d == 0.0) {
    // exit(-1);//dimension incompatible
    throw domain_error("Division par zéro.");
  }
  Dvector& vct = *this;
  vct *= 1.0/d;
  return vct;
}


/*implementation de l'operateur + entre un reel
*/
Dvector operator+(const double d, const Dvector& v1)
{
  Dvector v0(v1);
  return v0 += d;
}

Dvector operator+(const Dvector& v1, const double d)
{
  Dvector v0(v1);
  return v0 += d;
}


Dvector operator-(const double d, const Dvector& v1)
{
  Dvector v0(-1*v1);
  return v0 += d;
}


Dvector operator-(const Dvector& v1, const double d)
{
  Dvector v0(v1);
  return v0 -= d;
}


/*implementation de l'operateur * entre un reel et un vecteur
*/
Dvector operator*(const double d, const Dvector& v1)
{
  Dvector v0(v1);
  return v0 *= d;
}

Dvector operator*(const Dvector& v1, const double d)
{
  Dvector v0(v1);
  return v0 *= d;
}


/*implementation de l'operateur / entre un reel et un vecteur
*/
Dvector operator/(const double d, const Dvector& v1)
{
  Dvector v0(v1);
  for (int i = 0;i<v0.size();i++) {
      if (v0[i] == 0.0) {
        throw domain_error("Division par zéro.");
      }
      v0[i] = 1/v0[i];
  }
  return v0 *= d;
}

Dvector operator/(const Dvector& v1, const double d)
{
  Dvector v0(v1);
  if (d == 0.0) {
    throw domain_error("Division par zéro.");
  }
  return v0 /= d;
}


/*implementation de l'operateur + entre deux vecteurs
*/
Dvector operator+(const Dvector& v1, const Dvector& v2)
{
  Dvector v0(v1);
  return v0 += v2;
}


/*implementation de l'operateur - entre deux vecteurs
*/
Dvector operator-(const Dvector& v1, const Dvector& v2)
{
  Dvector v0(v1);
  return v0 -= v2;
}


/*implementation de l'operateur - unaire
*/
Dvector Dvector::operator-()
{
  Dvector vct(*this);
  return vct*=-1;
}


/*implementation de l'operateur de flux <<
*/
ostream& operator<<(ostream &Out, Dvector &dv)
{
  for(int i=0;i<dv.size();i++)
  {
    // on peut mettre *(tmp + i) à la place de tmp[i]
    if ((int)dv(i) == dv(i)) {
      Out << setprecision(1) << fixed << dv[i] << endl;
    } else {
      // remet la percision par défaut
      Out << setprecision(6) << dv[i] << endl;
    }
  }
  return Out;
}


/*implementation de l'operateur de flux >>
*/
istream& operator>>(istream &in, Dvector &dv)
{
  for(int i=0;i<dv.size();i++)
    in >> dv(i);
  return in;
}


/*implementation de l'operateur ==
*/

bool Dvector::operator==(Dvector &dv)
{
  if (this->taille == dv.size()) {
      for (int i = 0; i < dv.size(); i++) {
          if (dv(i) != (*this)(i)) {
            return false;
          }
      }
      return true;
  } else {
      return false;
  }

}
