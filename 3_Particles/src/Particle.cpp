#include "Particle.h"

Particle::Particle()
{
    setInitialCondition(0, 0, 0, 0);
    damping = ofRandom(0.01, 0.03);
}

void Particle::setInitialCondition(float px, float py, float vx, float vy)
{
    pos.set(px, py);
    vel.set(vx, vy);
}

void Particle::resetForce()
{
    frc.set(0, 0);
}

void Particle::addForce(float x, float y)
{
    frc += ofVec2f(x, y);
}

void Particle::addDampingForce()
{
    frc -= (vel * damping);
}

void Particle::update()
{
    vel += frc;
    pos += vel;
}

void Particle::draw()
{
    ofDrawCircle(pos, 3);
}
