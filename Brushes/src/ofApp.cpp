#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundAuto(false);
  ofBackground(0);

  ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {

  if (ofGetMousePressed()) {
    m_brush.draw();
  }

  if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
    ofBackground(0);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  // From section 1.ii.f, allowing you to save a screenshot by pressing the 's'
  // key:
  if (key == 's') {
    // HACK: only needed on windows, when using ofSetAutoBackground(false)
    glReadBuffer(GL_FRONT);

    // We use the timestamp here so that you can save multiple images without
    // overriding previous screenshots (i.e. each file has a unique name)
    ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
  } else if (key == '1') {
    m_brush.prevBrush();
  } else if (key == '2') {
    m_brush.nextBrush();
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
