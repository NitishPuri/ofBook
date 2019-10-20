#pragma once

#include "ofMain.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Life.h"
#include "LevelController.h"

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

    void update_bullets();

private:
    enum class GameState { START, GAME, END };
    GameState m_gameState;
    int m_Score;
    Player player_1;
    vector<Bullet> bullets;
    vector<Enemy> enemies;

    float max_enemy_amplitude;
    float max_enemy_shoot_interval;

    ofImage player_image;
    ofImage enemy_image;
    ofImage enemy_bullet_image;
    ofImage player_bullet_image;

};

