#ifndef ERR_ALLOC
#define ERR_ALLOC

#include <exception>    // used for creating special exceptions (par heritage)

class ErreurAllocation: public exception
{
  public:
    ErreurAllocation(string const& phrase="") throw() {
      m_phrase = phrase;
    }

    virtual const char* what() const throw () {
      return m_phrase.c_str();
    }

  private:
    string m_phrase; // description de l'erreur d'acces
};

#endif
