#ifndef GERSTNER_WAVE_H
#define GERSTNER_WAVE_H
#include "Dvector.h"


/* global variable g*/
double G = 9.81;

class GerstnerWave
{
    public:

    Dvector getDirection();
    double getAmplitude();
    double getFrequence();
    double getPhase();
    ~GerstnerWave();
    GerstnerWave(Dvector direction, double amplitude,
                double phase, int ratioTypeFreq=1,  double D=5.0, double L=0.5);
    GerstnerWave(const GerstnerWave & other);
    GerstnerWave& operator=(const GerstnerWave&);
    double operator()(int x, int y, double t, Dvector windDirection,
                      double averageAlignment);


    private:

    Dvector direction;
    double amplitude;
    double frequence;
    double phase;
};

#endif
