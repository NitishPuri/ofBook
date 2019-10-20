#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    void setInitialCondition(float px, float py, float vx, float vy);

    void setPos(const ofVec2f& pos) { m_pos = pos; }
    ofVec2f getPos() { return m_pos; }
    void setVel(const ofVec2f& vel) { m_vel = vel; }
    ofVec2f getVel() { return m_vel; }
    void setFrc(const ofVec2f& frc) { m_frc = frc; }
    ofVec2f getFrc() { return m_frc; }

    bool isFixed() const { return m_fixed; }
    void setFixed(bool fixed) { m_fixed = fixed; }

    void resetForce();
    void addForce(float x, float y);
    void addForce(ofVec2f force);
    void addDampingForce();

    void addRepulsionForce(float px, float py, float radius, float strength);
    void addAttractionForce(float px, float py, float radius, float strength);

    void addRepulsionForce(Particle &p, float radius, float scale);
    void addAttractionForce(Particle &p, float radius, float scale);
    void addClockwiseForce(Particle &p, float radius, float strength);
    void addCounterClockwiseForce(Particle &p, float radius, float strength);


    void bounceOffWalls();
    
    void update();
    void draw();


private:
    ofVec2f m_pos;
    ofVec2f m_vel;
    ofVec2f m_frc;

    float m_fixed;

    float m_damping;
};
