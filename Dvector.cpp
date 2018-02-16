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


int main()
{
  // vect1 par défaut
  Dvector vect1;
  // vect2 option du constructeur principal
  Dvector vect2(5);
  // vect3 constructeur principal
  Dvector vect3(3, 2.5);
  // vect4 exemple poly
  Dvector vect4(3, 2.0);
  // vect5 constructeur copie
  Dvector vect5(vect3);
  // vect6 constructeur par lecture de fichier
  Dvector vect6("test1.txt");


  //vect1 test
  vect1.display(cout);
  printf("Taille vect1 = %d\n", vect1.size());
  assert(vect1.size() == 2);


  // vect 2 test
  assert(vect2.size() == 5);
  vect2.fillRandomly();
  vect2.display(cout);


  // vect3 test
  assert( vect3.size() == 3);
  std::stringstream str3;
  vect3.display(str3);
  assert(str3.str() == "2.5\n2.5\n2.5\n");


  // vect4 test
  assert(vect4.size() == 3);
  std::stringstream str4;
  vect4.display(str4);
  assert(str4.str() == "2.0\n2.0\n2.0\n");


  // vect5 test
  std::stringstream str5;
  vect5.display(str5);
  assert(str5.str() == "2.5\n2.5\n2.5\n");

  std::cout << "OK\n";
}
