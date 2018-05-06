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

  /* juste pour noter que l'on peut travailler en coordonnee polaire */
  complex<double> testPolar = polar(2.0, 0.5);
  str1 << testPolar;
  assert(str1.str() == "(1.75517,0.958851)");
  str1.str("");

  /* test constrcution de trois TemplateDvector en complexe classique */
  complex<double> defaultComplex1(2.0, 2.0);
  TemplateDvector<complex<double>> tempVectComplex1(2, defaultComplex1);

  complex<double> defaultComplex3(1.665, -70.33);
  TemplateDvector<complex<double>> tempVectComplex3(2, defaultComplex3);

  complex<double> defaultComplex4(1.0, 1.0);
  TemplateDvector<complex<double>> tempVectComplex4(2, defaultComplex4);

  /* test constructeur par copie and operator == */
  TemplateDvector<complex<double>> copie(tempVectComplex1);
  assert(copie == tempVectComplex1);

  /* test size */
  assert(tempVectComplex1.size() == 2);

  /* test display  and << operator*/
  tempVectComplex1.display(str1);
  assert(str1.str() == "(2,2)\n(2,2)\n");
  str1.str("");
  str1 << tempVectComplex1;
  assert(str1.str() == "(2,2)\n(2,2)\n");
  str1.str("");

  /* test operator access [] */
  str1 << tempVectComplex1[1];
  assert(str1.str() == "(2,2)");
  str1.str("");

  /* test operator access () */
  str1 << tempVectComplex1(1);
  assert(str1.str() == "(2,2)");
  str1.str("");

  /* test operator =  and operator == */
  TemplateDvector<complex<double>> tempVectComplex2 = tempVectComplex1;
  assert(tempVectComplex2 == tempVectComplex1);

  /* test operator *= with a T */
  complex<double> iComplex(0, 1.0); // i
  tempVectComplex1 *= iComplex;
  str1 << tempVectComplex1;
  assert(str1.str() == "(-2,2)\n(-2,2)\n");
  str1.str("");

  /* test operator += with a TemplateDvector object */
  tempVectComplex1 += tempVectComplex3;
  str1 << tempVectComplex1;
  assert(str1.str() == "(-0.335,-68.33)\n(-0.335,-68.33)\n");
  str1.str("");

  /* test operator += with a T */
  complex<double> tmpComplex(3.0, 68);
  tempVectComplex1 += tmpComplex;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(2.665,-0.33)\n(2.665,-0.33)\n");
  str1.str("");

  /* test operator -= with a TemplateDvector object */
  tempVectComplex1 -= tempVectComplex4;
  str1 << tempVectComplex1;
  assert(str1.str() == "(1.665,-1.33)\n(1.665,-1.33)\n");
  str1.str("");

  /* test operator -= with a T */
  complex<double> tmpComplex2(1.0, -1.0);
  tempVectComplex1 -= tmpComplex2;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(0.665,-0.33)\n(0.665,-0.33)\n");
  str1.str("");

  /* test operator /= with a T */
  complex<double> tmpComplex3(0.5, 0.0);
  tempVectComplex1 /= tmpComplex3;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(1.33,-0.66)\n(1.33,-0.66)\n");
  str1.str("");

  /* test operator - */
  tempVectComplex1 = -tempVectComplex1;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(-1.33,0.66)\n(-1.33,0.66)\n");
  str1.str("");

  /* test operator + TemplateDvector + T */
  complex<double> tmpComplex4(1.0, 1.0);
  tempVectComplex1 = tempVectComplex1 + tmpComplex4;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(-0.33,1.66)\n(-0.33,1.66)\n");
  str1.str("");


  /* test operator + T + TemplateDvector */
  tempVectComplex1 = tmpComplex4 + tempVectComplex1;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(0.67,2.66)\n(0.67,2.66)\n");
  str1.str("");

  /* test operator + TemplateDvector + TemplateDvector */
  tempVectComplex1 = tempVectComplex4 + tempVectComplex4;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(2,2)\n(2,2)\n");
  str1.str("");

  /* test operator - TemplateDvector - T */
  tempVectComplex1 = tempVectComplex1 - tmpComplex3;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(1.5,2)\n(1.5,2)\n");
  str1.str("");

  /* test operator - T - TemplateDvector */
  tempVectComplex1 = tmpComplex3 - tempVectComplex1;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(-1,-2)\n(-1,-2)\n");
  str1.str("");

  /* test operator - TemplateDvector - TemplateDvector */
  tempVectComplex1 = tempVectComplex4 + tempVectComplex3;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(2.665,-69.33)\n(2.665,-69.33)\n");
  str1.str("");

  /* test operator * TemplateDvector * T */
  tempVectComplex1 = tempVectComplex1 * iComplex;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(69.33,2.665)\n(69.33,2.665)\n");
  str1.str("");

  /* test operator * T * TemplateDvector */
  tempVectComplex1 = tempVectComplex1 * tmpComplex;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(26.77,4722.43)\n(26.77,4722.43)\n");
  str1.str("");

  /* test operator / TemplateDvector / T */
  tempVectComplex1 = tempVectComplex1 / iComplex;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(4722.43,-26.77)\n(4722.43,-26.77)\n");
  str1.str("");

  /* test operator / T / TemplateDvector */
  complex<double> finalComplex(1.0, -1.0);
  TemplateDvector<complex<double>> tempVectComplex5(2.0, finalComplex);
  tempVectComplex1 = iComplex / tempVectComplex5;
  str1 << tempVectComplex1;
  // cout << str1.str();
  assert(str1.str() == "(-0.5,0.5)\n(-0.5,0.5)\n");
  str1.str("");



  /* -------------------------- EXCEPTIONS TEST ---------------------------- */

  cout << "OK" << endl;

  return 0;
}
