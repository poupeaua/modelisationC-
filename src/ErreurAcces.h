#ifndef ERR_ACCES
#define ERR_ACCES

#include <exception>    // used for creating special exceptions (par heritage)

/*!
 * [ErreurAcces Classe utilisée pour relié toutes les erreurs dûes à un accès
 * que ce soit dans Dvector ou Height par exemple]
 */
class ErreurAcces: public exception
{
  public:
    /*!
     * [ErreurAcces Constructeur de la classe]
     * @param phrase [string const& phrase est l'information qui peut varier
     * afin d'expliter les throw et de faciliter le débugage de l'utilisateur]
     */
    ErreurAcces(string const& phrase="") throw() {
      m_phrase = phrase;;
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
