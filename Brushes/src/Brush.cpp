#include "Brush.h"
#include "ofMain.h"

Brush::Brush() {
  m_brushMap = {
      {0, [this]() { draw_SingleRect(); }},
      {1, [this]() { draw_MultiRect(); }},
      {2, [this]() { draw_FadedCircles(); }},
      {3, [this]() { draw_Stars(); }},
      {4, [this]() { draw_Triangles(); }}
  };
}

void Brush::draw() {
  m_brushMap[m_brushType]();
}

void Brush::nextBrush() {
  m_brushType = (m_brushType >= m_brushMap.size() - 1) ? 0 : m_brushType + 1;
}

void Brush::prevBrush() {
  m_brushType = (m_brushType <= 0) ? m_brushMap.size() - 1 : m_brushType - 1;
}

void Brush::draw_SingleRect() {
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetColor(ofRandom(50, 255));
  ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 50, 50);
}

void Brush::draw_MultiRect() {
  ofSetRectMode(OF_RECTMODE_CENTER);
  for (int i = 0; i < 10; i++) {
    auto r = ofRandom(50, 255);
    auto g = ofRandom(50, 255);
    auto b = ofRandom(50, 255);
    ofSetColor(r, g, b);
    float width = ofRandom(5, 20);
    float height = ofRandom(5, 20);
    float xOffset = ofRandom(-40, 40);
    float yOffset = ofRandom(-40, 40);
    ofDrawRectangle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, width,
                    height);
  }
}

void Brush::draw_FadedCircles() {
  int maxRadius = 100;
  int radiusStepSize = 5;
  int alpha = 3;
  int maxOffsetDistance = 100;
  for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
    float angle = ofRandom(ofDegToRad(360.0));
    float distance = ofRandom(maxOffsetDistance);
    float xOffset = cos(angle) * distance;
    float yOffset = sin(angle) * distance;
    ofColor inBetween = ofColor::orange.getLerped(ofColor::red, ofRandom(1.0));
    ofSetColor(inBetween, alpha);
    ofDrawCircle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, radius);
  }
}

void Brush::draw_Stars() {
  int numLines = 30;
  int minRadius = 25;
  int maxRadius = 125;
  for (int i = 0; i < numLines; i++) {
    float angle = ofRandom(ofDegToRad(360.0));
    float distance = ofRandom(minRadius, maxRadius);
    float xOffset = cos(angle) * distance;
    float yOffset = sin(angle) * distance;
    float alpha = ofMap(distance, minRadius, maxRadius, 50,
                        0); // Make shorter lines more opaque
    ofSetColor(255, alpha);
    ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + xOffset,
               ofGetMouseY() + yOffset);
  }
}

void Brush::draw_Triangles() {
  int numTriangles = 10;
  int minOffset = 5;
  int maxOffset = 70;
  int alpha = 150;
  for (int t = 0; t < numTriangles; t++) {
    float offsetDistance = ofRandom(minOffset, maxOffset);

    ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

    // Define a triangle at the origin (0,0) that points to the right
    ofVec2f p1(0, 6.25);
    ofVec2f p2(25, 0);
    ofVec2f p3(0, -6.25);

    float rotation = ofRandom(360); // The rotate function uses degrees!
    p1.rotate(rotation);
    p2.rotate(rotation);
    p3.rotate(rotation);

    ofVec2f triangleOffset(offsetDistance, 0.0);
    triangleOffset.rotate(rotation);

    p1 += mousePos + triangleOffset;
    p2 += mousePos + triangleOffset;
    p3 += mousePos + triangleOffset;

    ofColor inbetween = ofColor::aqua.getLerped(ofColor::purple, ofRandom(1.0));
    ofSetColor(inbetween, alpha);

    ofDrawTriangle(p1, p2, p3);
  }
}

