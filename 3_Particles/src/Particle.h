#pragma once

#include "ofMain.h"

class Particle {
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;

    Particle();
    void setInitialCondition(float px, float py, float vx, float vy);

    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();

    void update();
    void draw();

    float damping;
};
