#pragma once

#include "ofMain.h"
#include "Particle.h"

class Spring {
public:
    void init(float length, float k, Particle* particleA, Particle* particleB);
    void update();
    void draw();

private:
    Particle* m_particleA = nullptr;
    Particle* m_particleB = nullptr;
    float m_length;
    float m_k;
};
