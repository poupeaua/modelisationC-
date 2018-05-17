#include "Height.h"

int main() {

  /* simple square with */
  Height h1(3, 3);

  /* one-dimentionnal height axis x*/
  Height h2(5, 1, 3.0);

  Height h3(h2);

  /* one-dimentionnal height axis y*/
  Height h4(1, 5, 5.0);

  Height h5(h4);

  /* two dimenstionnal height ~ normal square */
  Height h6(2, 2);

  /* serie of tests on HEIGHT objects*/
  std::stringstream str1;
  str1 << h1 << endl;
  assert(str1.str() == "0 0 0 \n0 0 0 \n0 0 0 \n\n");

  std::stringstream str2;
  str2 << h2 << endl;
  assert(str2.str() == "3 3 3 3 3 \n\n");

  std::stringstream str3;
  str3 << h3 << endl;
  assert(str3.str() == "3 3 3 3 3 \n\n");

  std::stringstream str4;
  str4 << h4 << endl;
  assert(str4.str() == "5 \n5 \n5 \n5 \n5 \n\n");

  std::stringstream str5;
  str5 << h5 << endl;
  assert(str5.str() == "5 \n5 \n5 \n5 \n5 \n\n");

  std::stringstream str6;
  /* width is Ly */
  str6 << h2.getWidth() << endl;
  assert(str6.str() == "1\n");

  /* access to elements tests */
  double value = h1(0, 0);
  assert(value == 0);
  value += 5;
  h1(1, 1) += value;
  assert(h1(1, 1) == 5);


  /* --------------------------- TESTS EXCEPTIONS ---------------------------*/

  stringstream str7;

  /* test longueur negative */
  try
  {
    Height h1(-3, 3);
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur d'allocation mémoire de Height.\n");
  str7.str("");


  /* test largeur negative */
  try
  {
    Height h1(3, -3);
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur d'allocation mémoire de Height.\n");
  str7.str("");


  /* test length negative */
  try
  {
    Height h1(3, 3, 5.0, -7.6);
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur paramètre length ou width négatif ou nul.\n");
  str7.str("");


  /* test width negative */
  try
  {
    Height h1(3, 3, 5.0, 7.6, -9.3);
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur paramètre length ou width négatif ou nul.\n");
  str7.str("");


  /* test acces negatif */
  try
  {
    Height h1(3, 3, 5.0, 7.6, 9.3);
    h1(-1, 0) += 2;
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Height.\n");
  str7.str("");


  /* test acces trop positif */
  try
  {
    Height h1(3, 3, 5.0, 7.6, 9.3);
    h1(3, 3) += 2;
  }
  catch (exception const& e)
  {
    str7 << "ERREUR : " << e.what() << endl;
  }
  assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Height.\n");
  str7.str("");


  cout << "OK" << endl;
}
