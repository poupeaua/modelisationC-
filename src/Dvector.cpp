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
Dvector::Dvector(int taille, double val)
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
    cout << "ERROR : Unable to open file" << endl;
  }

  /* deuxieme boucle pour inserer les elements dans le vecteurs
  */
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


/* Destructeur libérant la memoire
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
