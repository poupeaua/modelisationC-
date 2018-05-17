#ifndef GERSTNER_WAVE_H
#define GERSTNER_WAVE_H
#include "Dvector.h"


/* global variable g*/
double G = 9.81;


/*!
 * [GerstnerWave Classe permettant de générer des objets vagues selon le modèle de Gertsner]
 */
class GerstnerWave
{
    public:

    /*!
     * [GerstnerWave::GerstnerWave Constructeur par défaut. Choisi alors une
     * direction, une amplitude ainsi qu'une phase par défaut pour l'utilisateur.]
     */
    GerstnerWave();


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
    GerstnerWave(Dvector direction, double amplitude,
                double phase, int ratioTypeFreq=1,  double D=5.0, double L=0.5);

    /*!
     * [GerstnerWave::GerstnerWave Constructeur par copie]
     * @param other [const GerstnerWave & est un autre objet GertsnerWave]
     */
    GerstnerWave(const GerstnerWave & other);

    /*!
     * [GerstnerWave::getDirection retourne la direction de l'onde]
     * @return [Dvector définissant le direction de l'onde (dimension 2)]
     */
    Dvector getDirection();

    /*!
     * [GerstnerWave::getAmplitude getter classique retournant l'amplitude de
     *  l'onde]
     * @return [this->amplitude est un double égal à l'amplitude de l'onde]
     */
    double getAmplitude();

    /*!
     * [GerstnerWave::getFrequence getter classique pour la fréquence]
     * @return [double définissant la fréquence de l'onde]
     */
    double getFrequence();

    /*!
     * [GerstnerWave::getPhase getter classique pour la phase]
     * @return [double définissant la phase de la vague]
     */
    double getPhase();

    /*!
     * [GerstnerWave destructeur]
     */
    ~GerstnerWave();

    /*!
     * [GerstnerWave::operator = afin d'associer toutes les caractéristiques de
     *  gw passée en paramètre à l'objet this]
     * @return [*this]
     */
    GerstnerWave& operator=(const GerstnerWave&);

    /*!
     * [GerstnerWave::operator () permet de calculer la hauteur d'un point de la
     * surface via la position (x, y), le temps t ainsi que un Dvector
     *  de dimension 2 indiquant la direction du vent ainsi que un double
     *  définisant l'alignement moyen de la vague avec le vent]
     * @return [double définissant la hauteur au point (x, y) à l'instant t]
     */
    double operator()(int x, int y, double t, Dvector windDirection,
                      double averageAlignment);


    private:

    Dvector direction;
    double amplitude;
    double frequence;
    double phase;
};

#endif
