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
void ofApp::update() {
  if (m_leftMouseButtonPressed) {
    ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
    if (m_lastPoint.distance(mousePos) >= m_minDistance) {
      m_currentPolyline.curveTo(mousePos);
      m_lastPoint = mousePos;
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0);
    ofSetLineWidth(2.0); // Line widths apply to polylines
    ofSetColor(255, 100, 0);
    m_straightSegmentPolyline.draw(); // This is how we draw polylines
    m_curvedSegmentPolyline.draw();   // Nice and easy, right?
    m_closedShapePolyline.draw();


    ofSetColor(20, 150, 80, 100);

    constexpr float normalLength = 50;
    constexpr int increment = 1;
    constexpr int divisons = 500;

    constexpr float tangentLength = 80;

    for (const auto& polyline : m_polylines) {
      if (m_drawMode == 0) {
        polyline.draw();
      }      
      else {
        for (int p = 0; p < divisons; p += increment) {
          auto point = polyline.getPointAtPercent(p / float(divisons));
          auto indexInterpolated = polyline.getIndexAtPercent(p / float(divisons));
          if (m_drawMode == 1) {
            auto normal = polyline.getNormalAtIndexInterpolated(indexInterpolated) * normalLength;
            ofDrawLine(point - normal / 2, point + normal / 2);
          }
          else if (m_drawMode == 2) {
            auto tangent = polyline.getTangentAtIndexInterpolated(indexInterpolated) * tangentLength;
            ofDrawLine(point - tangent / 2, point + tangent / 2);
          }
        }
      }
    }

    ofSetColor(255, 100, 80);
    m_currentPolyline.draw();
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
  }
  else if (key == 'z') {
    if(!m_polylines.empty())
      m_polylines.pop_back();
  }
  else if (key == '1') {
    m_drawMode = std::max(0, m_drawMode - 1);
  } 
  else if (key == '2') {
    m_drawMode = std::min(m_drawMode + 1, 2);
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  if (button == OF_MOUSE_BUTTON_LEFT) {
    m_leftMouseButtonPressed = true;
    m_currentPolyline.curveTo(x, y);
    m_currentPolyline.curveTo(x, y);
    m_lastPoint.set(x, y);
  }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
  if (button == OF_MOUSE_BUTTON_LEFT) {
    m_leftMouseButtonPressed = false;
    m_currentPolyline.curveTo(x, y);
    m_currentPolyline.simplify(0.75);
    m_polylines.push_back(m_currentPolyline);
    m_currentPolyline.clear();
  }
}

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
