#ifndef ERR_ALLOC
#define ERR_ALLOC

#include <exception>    // used for creating special exceptions (par heritage)

class ErreurAllocation: public exception
{
  public:
    virtual const char* what(void) const throw () {
      return "Erreur d'allocation mémoire.";
    }
};

#endif
