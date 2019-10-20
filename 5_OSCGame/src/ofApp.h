#pragma once

#include "ofMain.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Life.h"
#include "LevelController.h"

#include "LiveTesting.h"

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
    enum class GameState { START, GAME, END };
    GameState m_gameState;
    int score;

    Player player_1;
    LevelController level_controller;

    vector<Bullet> bullets;
    vector<Enemy> enemies;
    vector<Life> bonuses;

    float max_enemy_amplitude;
    float max_enemy_shoot_interval;

    ofImage player_image;
    ofImage enemy_image;
    ofImage enemy_bullet_image;
    ofImage player_bullet_image;    
    ofImage start_screen;
    ofImage end_screen;
    ofImage life_image;

    //LiveTesting liveTest;

    void update_bullets();
    void update_bonuses();
    void check_bullet_collisions();
    void draw_lives();
    void draw_score();

    ofTrueTypeFont score_font;
    bool testing;

};

