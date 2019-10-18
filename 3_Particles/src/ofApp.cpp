#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    for (int i = 0; i < 1000; i++) {
        m_particles.emplace_back();
        m_particles.back().setInitialCondition(300, 300, ofRandom(-4, 4), ofRandom(-4, 4));
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (auto& particle : m_particles) {
        particle.resetForce();
        particle.addDampingForce();
        particle.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(0);
    for (auto& particle : m_particles) {
        particle.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    if (button == OF_MOUSE_BUTTON_LEFT) {
        for (auto& particle : m_particles) {
            particle.setInitialCondition(x, y, ofRandom(-4, 4), ofRandom(-4, 4));
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

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

