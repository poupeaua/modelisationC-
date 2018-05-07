#ifndef ERR_ACCES
#define ERR_ACCES

#include <exception>    // used for creating special exceptions (par heritage)

class ErreurAcces: public exception
{
  public:
    virtual const char* what(void) const throw () {
      return "Erreur d'accés aux données.";
    }
};

#endif
