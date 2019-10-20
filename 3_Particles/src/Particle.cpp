#include "Particle.h"

Particle::Particle()
{
    setInitialCondition(0, 0, 0, 0);
    m_damping = ofRandom(0.01, 0.03);
    m_fixed = false;

}

void Particle::setInitialCondition(float px, float py, float vx, float vy)
{
    m_pos.set(px, py);
    m_vel.set(vx, vy);
}

void Particle::resetForce()
{
    m_frc.set(0, 0);
}

void Particle::addForce(float x, float y)
{
    addForce({ x, y });
}

void Particle::addForce(ofVec2f force)
{
    m_frc += force;
}

void Particle::addDampingForce()
{
    addForce(-1 * m_vel * m_damping);
}

void Particle::addRepulsionForce(float px, float py, float radius, float strength)
{
    ofVec2f posOfForce(px, py);
    ofVec2f diff = m_pos - posOfForce;

    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        addForce(diff * pct * strength);
    }
}

void Particle::addAttractionForce(float px, float py, float radius, float strength)
{
    addRepulsionForce(px, py, radius, -strength);
}

void Particle::addClockwiseForce(Particle &p, float radius, float scale)
{
    auto diff = m_pos - p.getPos();
    float length = diff.length();

    if (radius > 0 && length > radius)
        return;

    float pct = 1 - (length / radius);
    diff.normalize();
    ofVec2f force{ diff.y * scale * pct , -diff.y * scale * pct };

    addForce(-force);
    p.addForce(force);
}

void Particle::addCounterClockwiseForce(Particle &p, float radius, float strength)
{
    addClockwiseForce(p, radius, -strength);
}

void Particle::addRepulsionForce(Particle & p, float radius, float scale)
{
    auto pos = p.getPos();
    addRepulsionForce(pos.x, pos.y, radius, scale);
}

void Particle::addAttractionForce(Particle & p, float radius, float scale)
{
    auto pos = p.getPos();
    addAttractionForce(pos.x, pos.y, radius, scale);
}

void Particle::bounceOffWalls()
{
    bool bDampedOnCollition = true;
    bool bDidCollide = false;

    float minx = 0;
    float miny = 9;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();

    if (m_pos.x > maxx) {
        m_pos.x = maxx;
        m_vel.x *= -1;
        bDidCollide = true;
    }
    else if (m_pos.x < minx) {
        m_pos.x = minx;
        m_vel.x *= -1;
        bDidCollide = true;
    }

    if (m_pos.y > maxy) {
        m_pos.y = maxy;
        m_vel.y *= -1;
        bDidCollide = true;
    }
    else if (m_pos.y < miny) {
        m_pos.y = miny;
        m_vel.y *= -1;
        bDidCollide = true;
    }

    if (bDidCollide == true && bDampedOnCollition == true) {
        m_vel *= 0.3;
    }
}

void Particle::update()
{
    if ( !m_fixed ) {
        m_vel += m_frc;
        m_pos += m_vel;
    }
}

void Particle::draw()
{
    ofDrawCircle(m_pos, 3);
}
