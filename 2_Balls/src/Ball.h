#pragma once

#include "ofMain.h"

class Ball
{
public:
    void setup(float _x, float _y);
    void update();
    void draw();

    float x;
    float y;
    float speedX;
    float speedY;
    int dim;
    ofColor color;

    Ball() = default;

};

