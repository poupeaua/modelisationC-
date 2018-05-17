#include "Dvector.h"

int main()
{
    // vect1 par défaut
    Dvector vect1;
    // vect2 option du constructeur principal
    Dvector vect2(2, 0);
    // vect3 constructeur principal
    Dvector vect3(3, 3);
    // vect4 exemple poly
    Dvector vect4(3, 1);
    // vect5 resize test
    Dvector vect5(5, 3);

    // test erreur 2) dans verifier.py a ete corrige
    // Dvector v1(1);
	  // v1(0) = 0.0;
	  // const Dvector v2(1);
	  // double val = v2(0);
    // printf("%f\n", val);

    //operateur += test
    std::stringstream str;
    vect3 += vect4;
    vect3.display(str);
    assert(str.str() == "4.0\n4.0\n4.0\n");

    str.str(std::string());
    vect3 += 1;
    vect3.display(str);
    assert(str.str() == "5.0\n5.0\n5.0\n");

    //operateur *= test
    str.str(std::string());
    vect3 *= 0.5;
    vect3.display(str);
    assert(str.str() == "2.500000\n2.500000\n2.500000\n");

    //operateur -= test
    str.str(std::string());
    vect3 -= vect4;
    vect3.display(str);
    assert(str.str() == "1.500000\n1.500000\n1.500000\n");
    vect3 += vect4;

    str.str(std::string());
    vect3 -= 0.5;
    vect3.display(str);
    assert(str.str() == "2.0\n2.0\n2.0\n");

    //operateur /= test
    str.str(std::string());
    vect3 /= 0.5;
    vect3.display(str);
    assert(str.str() == "4.0\n4.0\n4.0\n");

    //operateur + entre vecteur et reel
    str.str(std::string());
    vect3 = vect3 + 1;
    vect3.display(str);
    assert(str.str() == "5.0\n5.0\n5.0\n");

    str.str(std::string());
    vect1 = 2 + vect3;
    vect1.display(str);
    assert(str.str() == "7.0\n7.0\n7.0\n");

    //operateur - entre vecteur et reel
    str.str(std::string());
    vect3 = vect3 - 1;
    vect3.display(str);
    assert(str.str() == "4.0\n4.0\n4.0\n");

    str.str(std::string());
    vect1 = 7 - vect3;
    vect1.display(str);
    assert(str.str() == "3.0\n3.0\n3.0\n");

    //operateur * entre vecteur et reel
    str.str(std::string());
    vect3 = vect3 * 2;
    vect3.display(str);
    assert(str.str() == "8.0\n8.0\n8.0\n");

    str.str(std::string());
    vect1 = 1.5 * vect3;
    vect1.display(str);
    assert(str.str() == "12.0\n12.0\n12.0\n");

    //operateur * entre vecteur et reel
    str.str(std::string());
    vect3 = vect3/2;
    vect3.display(str);
    assert(str.str() == "4.0\n4.0\n4.0\n");

    str.str(std::string());
    vect1 = 2/vect3;
    vect1.display(str);
    assert(str.str() == "0.500000\n0.500000\n0.500000\n");

    //operateur + entre vecteur test
    str.str(std::string());
    vect3 = vect3 + vect4;
    vect3.display(str);
    assert(str.str() == "5.0\n5.0\n5.0\n");

    //operateur - netre vecteur test
    str.str(std::string());
    vect1 = vect3 - vect4;
    vect1.display(str);
    assert(str.str() == "4.0\n4.0\n4.0\n");

    //operateur - unaire test
    str.str(std::string());
    (-vect3).display(str);
    assert(str.str() == "-5.0\n-5.0\n-5.0\n");
    str.str(std::string());
    vect3.display(str);
    assert(str.str() == "5.0\n5.0\n5.0\n");

    //operateur << test
    str.str(std::string());
    str<<vect3;
    assert(str.str() == "5.0\n5.0\n5.0\n");

    //operateur == test et operator in >>
    assert(vect3 == vect3);
    assert(!(vect3 == vect4));
    stringstream str_in;
    str_in << "2.0\n2.0\n";
    str_in>>vect2;
    str.str(std::string());
    str<<vect2;
    assert(str.str() == "2.0\n2.0\n");

    // resize test larger
    vect5.resize(10);
    str.str(std::string());
    str << vect5;
    assert(str.str() == "3.0\n3.0\n3.0\n3.0\n3.0\n0.0\n0.0\n0.0\n0.0\n0.0\n");

    // resize test larger
    vect5.resize(3);
    str.str(std::string());
    str << vect5;
    assert(str.str() == "3.0\n3.0\n3.0\n");

    // resize test larger avec choix de la valeur des nouveaux elements
    vect5.resize(8,2);
    str.str(std::string());
    str << vect5;
    assert(str.str() == "3.0\n3.0\n3.0\n2.0\n2.0\n2.0\n2.0\n2.0\n");

    // resize test meme taille avec choix de la valeur des nouveaux elements
    vect5.resize(8, 9);
    str.str(std::string());
    str << vect5;
    assert(str.str() == "3.0\n3.0\n3.0\n2.0\n2.0\n2.0\n2.0\n2.0\n");


    /*-------------------------  EXCEPTIONS TESTS ------------------------- */


    stringstream str7;

    /* test accesseur () */
    try
    {
      Dvector vect8(5, 3.9);
      double value = vect8(5);
      value *= 2;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Dvector.\n");
    str7.str("");


    /* test accesseur [] */
    try
    {
      Dvector vect8(4, 2.3);
      double value = vect8(-8);
      value *= 2;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Dvector.\n");
    str7.str("");


    /* test accesseur [] */
    try
    {
      Dvector vect8(4, 2.3);
      double value = vect8(-8);
      value *= 2;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Dvector.\n");
    str7.str("");


    /* test addition par Dvector de taille differentes */
    try
    {
      Dvector vect8(4, 2);
      Dvector vect9(5, 2);
      vect8 += vect9;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Dvector.\n");
    str7.str("");


    /* test addition par Dvector de taille differentes */
    try
    {
      Dvector vect8(4, 2);
      Dvector vect9(5, 2);
      vect8 -= vect9;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Erreur d'accès à un élément de Dvector.\n");
    str7.str("");


    /* test division par 0 */
    try
    {
      Dvector vect8(4, 2.3);
      vect8 /= 0;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Division par zéro d'un Dvector.\n");
    str7.str("");


    /* test division par 0 */
    try
    {
      Dvector vect8(4, 2.3);
      vect8 = vect8 / 0;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Division par zéro d'un Dvector.\n");
    str7.str("");


    /* test division par 0 */
    try
    {
      Dvector vect8(4);
      vect8 = 1 / vect8;
    }
    catch (exception const& e)
    {
      str7 << "ERREUR : " << e.what() << endl;
    }
    assert(str7.str() == "ERREUR : Division par zéro. Un élément de Dvector est nul.\n");
    str7.str("");

    std::cout << "OK\n";
}
