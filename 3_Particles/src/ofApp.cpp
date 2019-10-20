#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundColor(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    for (int i = 0; i < 4; i++) {
        m_particles.emplace_back();
        m_particles.back().setInitialCondition(300, 300, ofRandom(-4, 4), ofRandom(-4, 4));
    }

    for (int i = 0; i < (m_particles.size() - 1); i++) {
        Spring spring;
        spring.init(10, 0.1f, &(m_particles[i]), &(m_particles[(i + 1) % m_particles.size()]));
        m_springs.push_back(spring);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (auto& particle : m_particles) {
        particle.resetForce();
    }

    for (auto& spring : m_springs) {
        spring.update();
    }

    for (int i = 0; i < m_particles.size(); i++) {
        m_particles[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
        for (int j = 0; j < i; j++) {
            m_particles[i].addRepulsionForce(m_particles[j], 10, 0.4);
            m_particles[i].addAttractionForce(m_particles[j], 500, 0.005);
        }
    }

    for (auto& particle : m_particles) {
        particle.addDampingForce();
        particle.update();
    }

    // trail
    trail.push_back(m_particles[3].getPos());
    if (trail.size() > 150) {
        trail.erase(trail.begin());
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255);
    for (auto& particle : m_particles) {
        particle.draw();
    }
    for (auto &spring : m_springs) {
        spring.draw();
    }

    ofNoFill();
    ofBeginShape();
    for (auto &pos: trail) {
        ofVertex(pos);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 's') {
        glReadBuffer(GL_FRONT);
        ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
    }
    else if (key == ' ') {
        for (auto& particle : m_particles) {
            particle.setInitialCondition(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    m_particles[0].setPos(ofVec2f( x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    m_particles[0].setFixed(true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    m_particles[0].setFixed(false);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

