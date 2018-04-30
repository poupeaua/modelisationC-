#ifndef GERSTNER_WAVE_H
#define GERSTNER_WAVE_H
#include <cmath>
#include "Dvector.h"



using namespace std;

class GerstnerWave
{
    public:

    Dvector getDirection();
    double getAmplitude();
    double getFrequence();
    double getPhase();
    ~GerstnerWave();

    GerstnerWave(Dvector direction, double amplitude,
                double frequence, double phase);
    GerstnerWave(const GerstnerWave & other);

    GerstnerWave& operator=(const GerstnerWave&);
    double operator()(int x, int y, double t);

    private:

    Dvector direction;
    double amplitude;
    double frequence;
    double phase;
};

#endif
