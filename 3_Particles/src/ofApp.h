#pragma once

#include "ofMain.h"

#include "Particle.h"
#include "Spring.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    vector<Particle> m_particles;
    vector<Spring> m_springs;
    vector<ofPoint> trail;

    //bool m_repel;
    //int m_radius;
    //float m_strength;
};

