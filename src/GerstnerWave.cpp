#include "GerstnerWave.h"

/*
--------------------------- CONSTRUCTOR ----------------------------------------
*/

/* constructeur par défaut
*/

GerstnerWave::GerstnerWave(Dvector direction, double amplitude,
            double frequence, double phase)
{
  // créé une onde de Gerstner avec les parametres donnés
  // A implementer verifier que la relation frequence norme du vecteur d'onde est consevé
  this->direction = direction;
  this->amplitude = amplitude;
  this->frequence = frequence;
  this->phase = phase;
}

GerstnerWave::GerstnerWave(const GerstnerWave & other)
{
  // constructeur par recopie
  this->direction = other.direction;
  this->amplitude = other.amplitude;
  this->frequence = other.frequence;
  this->phase = other.phase;
}

/*
------------------------------ METHOD ------------------------------------------
*/

/* retoune l'amplitude de l'onde
*/
double GerstnerWave::getAmplitude()
{
  return this->amplitude;
}

/* retourne la direction de l'onde
*/
Dvector GerstnerWave::getDirection()
{
  return this->direction;
}

/* retourne la frequence de l'onde
*/
double GerstnerWave::getFrequence()
{
  return this->frequence;
}

/* retourne la phase de l'onde
*/
double GerstnerWave::getPhase()
{
  return this->phase;
}

/* Destructeur libérant la memoire
*/
GerstnerWave::~GerstnerWave()
{
  /*
    no new so there is nothing to delete
   */
}


/*
--------------------------- OPERATOR -------------------------------------------
*/

/*
à reimplemente duplication de code
*/
GerstnerWave& GerstnerWave::operator=(const GerstnerWave& gw)
{
  this->direction = gw.direction;
  this->amplitude = gw.amplitude;
  this->frequence = gw.frequence;
  this->phase = gw.phase;
  return *this;
}

double GerstnerWave::operator()(int x, int y, double t)
{
  return amplitude*cos(x*direction(0) + y*direction(1) - frequence * t + phase);
}
