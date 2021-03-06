#include "Dvector.h"
#include <ctime>
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
  Dvector vect6("../../test/test1.txt");
  // vect7 constructeur par lecture de fichire numéro 2
  Dvector vect7("../../test/test2.txt");

  //vect1 test
  vect1.display(cout);
  assert(vect1.size() == 2);


  // vect 2 test
  assert(vect2.size() == 5);
  vect2.fillRandomly();
  // vect2.display(cout);


  // vect3 test
  assert( vect3.size() == 3);
  stringstream str3;
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

  // vect6 test
  stringstream str6;
  vect6.display(str6);
  assert(str6.str() == "0.162182\n0.794285\n0.311215\n0.528533\n0.165649\n0.601982\n0.262971\n0.654079\n0.689214\n0.748152\n");


  /*-------------------------  EXCEPTIONS TESTS ------------------------- */

  stringstream str7;

  /* test creer un Dvector de taille 0 */
  try
  {
    Dvector vect8(0, 2.666);
  }
  catch (exception const& e)
  {
    /* il devrait etre ecrit la ligne suivante avec cerr pour un vrai prog */
    // cerr << "ERREUR : " << e.what() << endl;
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur d'allocation mémoire de Dvector.\n");
  str7.str("");


  /* test creer un Dvector de taille negative */
  try
  {
    Dvector vect8(-5);
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur d'allocation mémoire de Dvector.\n");
  str7.str("");


  /* test creer un Dvector de taille non entiere */
  try
  {
    Dvector vect8(5.99);
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "");
  str7.str("");


  /* test ouvrir un fichier qui n'existe pas */
  try
  {
    Dvector vect8("../../test/test.txt");
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Impossible d'ouvrir le fichier pour créer un Dvector.\n");
  str7.str("");


  cout << "OK" << endl;

}
