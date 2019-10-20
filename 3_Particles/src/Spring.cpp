#include "Spring.h"

void Spring::init(float length, float k, Particle * particleA, Particle * particleB)
{
    m_length = length;
    m_k = k;
    m_particleA = particleA;
    m_particleB = particleB;
}

void Spring::update()
{
    if (m_particleA == nullptr && m_particleB == nullptr) {
        return;
    }

    auto diff = (m_particleA->getPos() - m_particleB->getPos());

    auto distance = diff.length();
    auto force = diff.getNormalized() * (m_k * (m_length - distance));

    m_particleA->addForce( force.x,  force.y);
    m_particleA->addForce(-force.x, -force.y);
}

void Spring::draw()
{
    if (m_particleA == nullptr && m_particleB == nullptr) {
        return;
    }

    ofDrawLine(m_particleA->getPos(), m_particleB->getPos());
}
