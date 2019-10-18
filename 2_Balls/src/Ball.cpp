#include "Ball.h"

void Ball::setup(float _x, float _y) {
    x = _x;
    y = _y;

    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);

    dim = ofRandom(10, 40);

    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::update() {
    if (x < 0) {
        x = 0;
        speedX *= -1;
    }
    else if (x > ofGetWidth()) {
        x = ofGetWidth();
        speedX *= -1;
    }

    if (y < 0) {
        y = 0;
        speedY *= -1;
    }
    else if (y > ofGetHeight()) {
        y = ofGetHeight();
        speedY *= -1;
    }

    x += speedX;
    y += speedY;
}

void Ball::draw() {
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}

