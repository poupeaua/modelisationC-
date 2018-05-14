#ifndef ERR_ACCES
#define ERR_ACCES

#include <exception>    // used for creating special exceptions (par heritage)

class ErreurAcces: public exception
{
  public:
    ErreurAcces(string const& phrase="") throw() {
      m_phrase = phrase;;
    }

    virtual const char* what() const throw () {
      return m_phrase.c_str();
    }


  private:
    string m_phrase; // description de l'erreur d'acces
};

#endif
