#include "Dvector.h"


/* constructeur par défaut
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


/* constructeur précisant la taille et une option val
  permettant d'initialiser toute les coordonnées du vecteur à val
*/
Dvector::Dvector(int taille, double val = 0.0)
{
  if (taille < 0) {
    cout << "ERROR : negative size." << endl;
    return;
  }
  vect = new double[taille];
  for (int i = 0 ; i < taille ; i++)
  {
    vect[i] = val;
  }
  this->taille = taille;
}


/* constructeur par copie
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


/* constructeur utilisant un fichier pour lire les coordonnées
*/
Dvector::Dvector(string src)
{
  string line;
  ifstream myfile (src.c_str());
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      line.c_str();
    }
    myfile.close();
  }
  else {
    cout << "ERROR : Unable to open file" << endl;
  }
}


/* Destructeur libérant la mémoire
*/
Dvector::~Dvector()
{
  delete[] vect;
}


/* Methode permettant d'afficher le contenu d'un vecteur sur la sortie demandée
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


/* Retourne la taille du vecteur considere
  Methode Getter
*/
int Dvector::size()
{
  return this->taille;
}


/* Methode permettant de remplir toutes les coordonnées d'un vecteur avec
des double compris entre 0 et 1
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

/*implementation de l'operateur d'accession [] à un element du vecteur
*/
double& Dvector::operator[](int i)
{
  if ((i<0)||(i>taille)) {
    exit(1);
  }
  return vect[i];
}

/*implementation de l'operateur d'accession () à un element du vecteur
*/
double& Dvector::operator()(int i)
{
  return vect[i];
}

/*implemenation de l'operateur d'affection avec memcpy
*/

Dvector& Dvector::operator=(const Dvector& dv)
{
  taille = dv.taille;
  vect = new double[taille];
  memcpy(vect, dv.vect, taille*sizeof(double));
  return *this;
}

/*implemetation de l'operateur d'affection avec le constructeur par copie
NON TESTE
*/

/*
Dvector& Dvector::operator=(const Dvector& dv)
{
  return this(dv);
}
*/

/*implementation de l'operateur += avec un autre vecteur
*/
Dvector& Dvector::operator+=(const Dvector& dv)
{
  if (taille!=dv.taille) {
    exit(-1);//dimension incompatible
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
    exit(-1);//dimension incompatible
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
  if (d == 0) {
    exit(-1);//dimension incompatible
  }
  Dvector& vct = *this;
  vct *= 1/d;
  return vct;
}

/*implementation de l'operateur + entre un reel et un vecteur
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

/*implementation de l'operateur - entre un reel et un vecteur
*/
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
  for (int i = 0;i<v0.size();i++)
      v0[i] = 1/v0[i];
  return v0 *= d;
}

Dvector operator/(const Dvector& v1, const double d)
{
  Dvector v0(v1);
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
    in>>dv(i);
}

/*implementation de l'operateur ==
*/

bool Dvector::operator==(Dvector &dv)
{
  if (this->taille == dv.size()) {
      int a = 0;
      for (size_t i = 0; i < dv.size(); i++) {
          if (dv(i) != (*this)(i)) {
              a+=1;
          }
      }
      if (a == 0) {
         return true;
      } else {
         return false;
      }
  } else {
      return false;
  }

}
