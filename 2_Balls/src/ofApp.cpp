#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (auto& ball : m_balls) { ball.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())); }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto& ball : m_balls) { ball.update(); }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto& ball : m_balls) { ball.draw(); }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // From section 1.ii.f, allowing you to save a screenshot by pressing the 's'
    // key:
    if (key == 's') {
        // HACK: only needed on windows, when using ofSetAutoBackground(false)
        glReadBuffer(GL_FRONT);

        // We use the timestamp here so that you can save multiple images without
        // overriding previous screenshots (i.e. each file has a unique name)
        ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    m_balls.emplace_back();
    m_balls.back().setup(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

