#include "GerstnerWave.h"


/*
-------------------------------- CONSTRUCTORS ---------------------------------
*/


/*!
 * [GerstnerWave::GerstnerWave Constructeur par défaut n'existe pas. Il est
 * nécessaire de passer par ce constructeur pour commencer.]
 * @param direction     [Dvector a deux dimensions pour décrire la direction
 *  de la vague]
 * @param amplitude     [double qui défini la hauteur maximum de la vague]
 * @param phase         [double utilisé pour décrire la phase de l'onde. Ce
 *                      paramètre servira notamment à décaler certaines ondes
 *                      entres-elles]
 * @param ratioTypeFreq [int qui permet à l'utilisateur de choisir le mode de
 *                      la vague. Il existe trois modes 1) ω 2 (k) = gk.
 *                      En eau peu profonde, le sol situé à une distance D du
 *                      niveau moyen modifie la relation de dispersion de la
 *                      manière suivante ω 2 (k) = gk tanh(kD).
 *                      Le troisième cas pouvant être simulé prend en compte la
 *                      tension de surface. ω 2 (k) = gk(1 + k 2 L 2 ). ]
 * @param D             [double initialement par défaut à 5.0 définissant la
 *                      distance moyenne de la vague par rapport au sol]
 * @param L             [double paramètre définissant la tension de la surface]
 */
GerstnerWave::GerstnerWave(Dvector direction, double amplitude,
            double phase, int ratioTypeFreq,  double D, double L)
{
  if (amplitude < 0 || phase < 0 || D < 0 || L < 0) {
    throw invalid_argument("Argument invalide : L'amplitude, la distance au"
        " sol ainsi que la tension de surface doivent être positifs.");
  } else if ( direction.size() != 2){
    throw invalid_argument("Argument invalide : La direction doit être de"
        " dimension deux.");
  }
  this->direction = direction;
  this->amplitude = amplitude;
  /* calcul de la fréquence car on peut écrire un relation entre f et la norme
  de la direction */
  double k = direction.norm(2);
  double frequence = sqrt(G*k);
  if (ratioTypeFreq == 2) {
    frequence *= tanh(k*D);
  } else if (ratioTypeFreq >= 3) {
    frequence *= (1 + pow(k*L, 2));
  }
  this->frequence = frequence;
  this->phase = phase;
}


/*!
 * [GerstnerWave::GerstnerWave Constructeur par copie]
 * @param other [const GerstnerWave & est un autre objet GertsnerWave]
 */
GerstnerWave::GerstnerWave(const GerstnerWave & other)
{
  this->direction = other.direction;
  this->amplitude = other.amplitude;
  this->frequence = other.frequence;
  this->phase = other.phase;
}

/*
---------------------------------- METHODS ------------------------------------
*/


/*!
 * [GerstnerWave::getAmplitude getter classique retournant l'amplitude de
 *  l'onde]
 * @return [this->amplitude est un double égal à l'amplitude de l'onde]
 */
double GerstnerWave::getAmplitude()
{
  return this->amplitude;
}


/*!
 * [GerstnerWave::getDirection retourne la direction de l'onde]
 * @return [Dvector définissant le direction de l'onde (dimension 2)]
 */
Dvector GerstnerWave::getDirection()
{
  return this->direction;
}


/*!
 * [GerstnerWave::getFrequence getter classique pour la fréquence]
 * @return [double définissant la fréquence de l'onde]
 */
double GerstnerWave::getFrequence()
{
  return this->frequence;
}


/*!
 * [GerstnerWave::getPhase getter classique pour la phase]
 * @return [double définissant la phase de la vague]
 */
double GerstnerWave::getPhase()
{
  return this->phase;
}


/*!
 * [GerstnerWave destructeur]
 */
GerstnerWave::~GerstnerWave()
{
  /*
    no new so there is nothing to delete
   */
}


/*
---------------------------------- OPERATOR -----------------------------------
*/


/*!
 * [GerstnerWave::operator = afin d'associer toutes les caractéristiques de
 *  gw passée en paramètre à l'objet this]
 * @return [*this]
 */
GerstnerWave& GerstnerWave::operator=(const GerstnerWave& gw)
{
  this->direction = gw.direction;
  this->amplitude = gw.amplitude;
  this->frequence = gw.frequence;
  this->phase = gw.phase;
  return *this;
}


/*!
 * [GerstnerWave::operator () permet de calculer la hauteur d'un point de la
 * surface via la position (x, y), le temps t ainsi que un Dvector
 *  de dimension 2 indiquant la direction du vent ainsi que un double
 *  définisant l'alignement moyen de la vague avec le vent]
 * @return [double définissant la hauteur au point (x, y) à l'instant t]
 */
double GerstnerWave::operator()(int x, int y, double t,
                                Dvector windDirection, double averageAlignment)
{
  Dvector tmp = windDirection*averageAlignment + direction*(1-averageAlignment);
  return amplitude*cos(x*tmp(0) + y*tmp(1) - frequence * t + phase);
}
