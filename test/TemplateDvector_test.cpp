#include "TemplateDvector.h"


int  main() {

  /* ----------------------- T = DOUBLE TESTS ------------------------------ */

  /* test de base */
  TemplateDvector<double> tempVectDouble1(2);

  stringstream str1;
  tempVectDouble1.display(str1);
  assert(str1.str() == "0\n0\n");
  str1.str("");


  /* test du par T par defaut (en double) */
  TemplateDvector<> tempVectDouble2(2);

  tempVectDouble2.display(str1);
  assert(str1.str() == "0\n0\n");
  str1.str("");



  /* ----------------------- T = COMPLEX TESTS ----------------------------- */


  /* test TemplateDvector en complexe classique */
  complex<double> defaultComplex(2.0, 2.0);
  TemplateDvector<complex<double>> tempVectComplex1(2, defaultComplex);

  tempVectComplex1.display(str1);
  assert(str1.str() == "(2,2)\n(2,2)\n");
  str1.str("");

  /* 
  complex<double> iComplex(0, 1.0); // i
  tempVectComplex1 *= iComplex;
  str1 << tempVectComplex1;
  assert(str1.str() == "(-2,2)\n(-2,2)\n");


  /* -------------------------- EXCEPTIONS TEST ---------------------------- */

  cout << "OK" << endl;

  return 0;
}
