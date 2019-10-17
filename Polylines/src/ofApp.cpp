#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    m_straightSegmentPolyline.addVertex(100, 100); // Add a new point: (100, 100)
    m_straightSegmentPolyline.addVertex(150, 150); // Add a new point: (150, 150)
    m_straightSegmentPolyline.addVertex(200, 100); // etc...
    m_straightSegmentPolyline.addVertex(250, 150);
    m_straightSegmentPolyline.addVertex(300, 100);

    m_curvedSegmentPolyline.curveTo(350,
                                    100); // These curves are Catmull-Rom splines
    m_curvedSegmentPolyline.curveTo(350,
                                    100); // Necessary Duplicate for Control Point
    m_curvedSegmentPolyline.curveTo(400, 150);
    m_curvedSegmentPolyline.curveTo(450, 100);
    m_curvedSegmentPolyline.curveTo(500, 150);
    m_curvedSegmentPolyline.curveTo(550, 100);
    m_curvedSegmentPolyline.curveTo(550,
                                    100); // Necessary Duplicate for Control Point

    m_closedShapePolyline.addVertex(600, 125);
    m_closedShapePolyline.addVertex(700, 100);
    m_closedShapePolyline.addVertex(800, 125);
    m_closedShapePolyline.addVertex(700, 150);
    m_closedShapePolyline.close(); // Connect first and last vertices
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0);
    ofSetLineWidth(2.0); // Line widths apply to polylines
    ofSetColor(255, 100, 0);
    m_straightSegmentPolyline.draw(); // This is how we draw polylines
    m_curvedSegmentPolyline.draw();   // Nice and easy, right?
    m_closedShapePolyline.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

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
