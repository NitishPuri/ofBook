#pragma once

#include "ofMain.h"

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

private:
    ofPolyline m_straightSegmentPolyline;
    ofPolyline m_curvedSegmentPolyline;
    ofPolyline m_closedShapePolyline;

    ofPolyline m_currentPolyline;
    bool m_leftMouseButtonPressed{ false };
    ofVec2f m_lastPoint;
    float m_minDistance{ 10.F };
    vector<ofPolyline> m_polylines;
    int m_drawMode{ 0 };

};
