#include "ErreurAcces.h"
#include "ErreurAllocation.h"

/*!
 * [TemplateDvector::TemplateDvector constructeur par défaut]
 */
template<typename T>
TemplateDvector<T>::TemplateDvector()
{
  // créé un vecteur de taille 2 avec pour coordonnées (0, 0)
  int taille = 2;
  T val = 0.0;
  vect = new T[taille];
  for (int i = 0 ; i < taille ; i++)
  {
    vect[i] = val;
  }
  this->taille = taille;
}


/*!
 * [TemplateDvector::TemplateDvector constructeur précisant la taille et une option val
   permettant d'initialiser toute les coordonnées du vecteur à val]
 * @param taille [int définissant la taille du TemplateDvector]
 * @param val    [double valeur qui sera associé à tous les éléments du TemplateDvector]
 */
template<typename T>
TemplateDvector<T>::TemplateDvector(int taille, T val)
{
  if (taille <= 0) {
    throw ErreurAllocation();
  }
  vect = new T[taille];
  for (int i = 0 ; i < taille ; i++)
  {
    vect[i] = val;
  }
  this->taille = taille;
}


/*!
 * [TemplateDvector::TemplateDvector constructeur par copie]
 * @param other [TemplateDvector autre TemplateDvector élément dont chaque caractéristique
 *               sera copiée]
 */
template<typename T>
TemplateDvector<T>::TemplateDvector(const TemplateDvector<T> & other)
{
  T *tmp = other.vect;
  int size = other.taille;
  vect = new T[size];
  for (int i = 0 ; i < size ; i++)
  {
    vect[i] = tmp[i];
  }
  this->taille = size;
}


/*!
 * [TemplateDvector Destructeur libérant la memoire]
 */
template<typename T>
TemplateDvector<T>::~TemplateDvector()
{
  delete[] vect;
}


/*!
 * [TemplateDvector::display Methode permettant d'afficher le contenu d'un vecteur
 *  sur la sortie demandée]
 * @param str [ostream& objet définissant sur quelle sortie le contenu du
 *  TemplateDvector sera copié]
 */
template<typename T>
void TemplateDvector<T>::display(ostream& str)
{
  T *tmp = this->vect;
  for (int i = 0 ; i < this->taille ; i++)
  {
    // on peut mettre *(tmp + i) à la place de tmp[i]
    // remet la percision par défaut
    str << setprecision(6) << tmp[i] << endl;
  }
}


/*!
 * [TemplateDvector::size Getter classique pour la taille du TemplateDvector]
 * @return [int définissant le taille du TemplateDvector]
 */
template<typename T>
int TemplateDvector<T>::size()
{
  return this->taille;
}


/*!
 * [TemplateDvector::operator[] opérateur d'accession [] à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
template<typename T>
T& TemplateDvector<T>::operator[](int i)
{
  if ((i<0)||(i>=taille)) {
    throw ErreurAcces();
  }
  return vect[i];
}


/*!
 * [TemplateDvector::operator[] opérateur d'accession [] à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
template<typename T>
const T& TemplateDvector<T>::operator[](int i) const
{
  if ((i<0)||(i>=taille)) {
    throw ErreurAcces();
  }
  return vect[i];
}


/*!
 * [TemplateDvector::operator[] opérateur d'accession () à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
template<typename T>
T& TemplateDvector<T>::operator()(int i)
{
  if ((i<0)||(i>=taille)) {
    throw ErreurAcces();
  }
  return vect[i];
}


/*!
 * [TemplateDvector::operator[] opérateur d'accession () à un élément du vecteur]
 * @param  i [int définissant l'indice]
 * @return   [double représentant la valeur de l'objet à l'indice i]
 */
template<typename T>
const T& TemplateDvector<T>::operator()(int i) const
{
  if ((i<0)||(i>=taille)) {
    throw ErreurAcces();
  }
  return vect[i];
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator=(const TemplateDvector<T>& dv)
{
  taille = dv.taille;
  /*
  BEWARE !!! => don't forget to delete[] before making a new vect
  */
  delete[] vect;
  vect = new T[taille];
  for (int i = 0 ; i < taille ; i++) {
    vect[i] = dv[i];
  }
  return *this;
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator+=(const TemplateDvector<T>& dv)
{
  if (taille!=dv.taille) {
    //dimension incompatible
    throw ErreurAcces();
  }

  TemplateDvector<T>& vct = *this;
  for (int i=0;i<taille;i++)
    vct.vect[i] += dv.vect[i];
  return vct;
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator+=(const T d)
{
  TemplateDvector<T>& vct = *this;
  for (int i=0;i<taille;i++)
    vct.vect[i] += d;
  return vct;
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator*=(const T d)
{
  TemplateDvector<T>& vct = *this;
  for (int i=0;i<taille;i++)
    vct.vect[i] *= d;
  return vct;
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator-=(const TemplateDvector<T>& dv)
{
  if (taille!=dv.taille) {
    //dimension incompatible
    throw ErreurAcces();
  }
  TemplateDvector<T>& vct = *this;
  vct += -1.0*dv;
  return vct;
}


/*implementation de l'operateur * entre un double pour l'operateur
-= juste au dessus qui realise l'operation -1.0*dv
*/
template<typename T>
TemplateDvector<T> operator*(const double d, const TemplateDvector<T>& v1)
{
  TemplateDvector<T> v0(v1);
  return v0 *= d;
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator-=(const T d)
{
  TemplateDvector<T>& vct = *this;
  vct += -d;
  return vct;
}


template<typename T>
TemplateDvector<T>& TemplateDvector<T>::operator/=(const T d)
{
  if (d == 0.0) {
    throw domain_error("Division par zéro.");
  }
  TemplateDvector<T>& vct = *this;
  vct *= 1.0/d;
  return vct;
}

/* specialization du la methode pour les complexes */
template<>
TemplateDvector<complex<double>>& TemplateDvector<complex<double>>::operator/=(const complex<double> d)
{
  if (d.real() == 0.0 && d.imag() == 0.0) {
    throw domain_error("Division par zéro.");
  }
  TemplateDvector<complex<double>>& vct = *this;
  vct *= 1.0/d;
  return vct;
}


template<typename T>
TemplateDvector<T> operator+(const T d, const TemplateDvector<T>& v1)
{
  TemplateDvector<T> v0(v1);
  return v0 += d;
}


template<typename T>
TemplateDvector<T> operator+(const TemplateDvector<T>& v1, const T d)
{
  TemplateDvector<T> v0(v1);
  return v0 += d;
}


template<typename T>
TemplateDvector<T> operator-(const T d, const TemplateDvector<T>& v1)
{
  TemplateDvector<T> v0(-1*v1);
  return v0 += d;
}


template<typename T>
TemplateDvector<T> operator-(const TemplateDvector<T>& v1, const T d)
{
  TemplateDvector<T> v0(v1);
  return v0 -= d;
}


/*implementation de l'operateur * entre un reel et un vecteur
*/
template<typename T>
TemplateDvector<T> operator*(const T d, const TemplateDvector<T>& v1)
{
  TemplateDvector<T> v0(v1);
  return v0 *= d;
}


template<typename T>
TemplateDvector<T> operator*(const TemplateDvector<T>& v1, const T d)
{
  TemplateDvector<T> v0(v1);
  return v0 *= d;
}


/*implementation de l'operateur / entre un reel et un vecteur
*/
template<typename T>
TemplateDvector<T> operator/(const T d, const TemplateDvector<T>& v1)
{
  TemplateDvector<T> v0(v1);
  for (int i = 0;i<v0.size();i++) {
      if (v0[i] == 0.0) {
        throw domain_error("Division par zéro.");
      }
      v0[i] = 1/v0[i];
  }
  return v0 *= d;
}


/* specialisation de l'operateur / pour les nombres complexes */
template<>
TemplateDvector<complex<double>> operator/(const complex<double> d, const TemplateDvector<complex<double>>& v1)
{
  TemplateDvector<complex<double>> v0(v1);
  for (int i = 0;i<v0.size();i++) {
      if (v0[i].real() == 0.0 && v0[i].imag() == 0.0) {
        throw domain_error("Division par zéro.");
      }
      v0[i] = 1.0/v0[i];
  }
  return v0 *= d;
}


template<typename T>
TemplateDvector<T> operator/(const TemplateDvector<T>& v1, const T d)
{
  TemplateDvector<T> v0(v1);
  if (d == 0.0) {
    throw domain_error("Division par zéro.");
  }
  return v0 /= d;
}


/* specialisation de l'operateur / pour les nombres complexes */
template<>
TemplateDvector<complex<double>> operator/(const TemplateDvector<complex<double>>& v1, const complex<double> d)
{
  TemplateDvector<complex<double>> v0(v1);
  if (d.real() == 0 && d.imag() == 0) {
    throw domain_error("Division par zéro.");
  }
  return v0 /= d;
}


/*implementation de l'operateur + entre deux vecteurs
*/
template<typename T>
TemplateDvector<T> operator+(const TemplateDvector<T>& v1, const TemplateDvector<T>& v2)
{
  TemplateDvector<T> v0(v1);
  return v0 += v2;
}


/*implementation de l'operateur - entre deux vecteurs
*/
template<typename T>
TemplateDvector<T> operator-(const TemplateDvector<T>& v1, const TemplateDvector<T>& v2)
{
  TemplateDvector<T> v0(v1);
  return v0 -= v2;
}


/*implementation de l'operateur - unaire
*/
template<typename T>
TemplateDvector<T> TemplateDvector<T>::operator-()
{
  TemplateDvector<T> vct(*this);
  return vct*=-1;
}


template<typename T>
ostream& operator<<(ostream &Out, TemplateDvector<T> &dv)
{
  for(int i=0;i<dv.size();i++)
  {
    // on peut mettre *(tmp + i) à la place de tmp[i]
    // remet la percision par défaut
    Out << setprecision(6) << dv[i] << endl;
  }
  return Out;
}


template<typename T>
istream& operator>>(istream &in, TemplateDvector<T> & dv)
{
  for(int i=0;i<dv.size();i++)
    in >> dv(i);
  return in;
}


template<typename T>
bool TemplateDvector<T>::operator==(TemplateDvector<T> &dv)
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
