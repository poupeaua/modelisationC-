#ifndef ERR_ALLOC
#define ERR_ALLOC

#include <exception>    // used for creating special exceptions (par heritage)


/*!
 * [ErreurAllocation Classe utilisée pour relié toutes les erreurs dûes à une
 * allocation que ce soit dans Dvector ou Height par exemple]
 */
class ErreurAllocation: public exception
{
  public:
    /*!
     * [ErreurAllocation descriptio]
     * @param phrase [string const& phrase est l'information qui peut varier
     * afin d'expliter les throw et de faciliter le débugage de l'utilisateur]
     */
    ErreurAllocation(string const& phrase="") throw() {
      m_phrase = phrase;
    }

    /*!
     * [what  Méthode utilisée pour afficher l'information de l'erreur.]
     * @return [const char* m_phrase.c_str()]
     */
    virtual const char* what() const throw () {
      return m_phrase.c_str();
    }

  private:
    string m_phrase; // description de l'erreur d'acces
};

#endif
