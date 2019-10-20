#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {


    m_gameState = GameState::START;
    m_Score = 0;

    max_enemy_amplitude = 3.0;
    max_enemy_shoot_interval = 1.5;

    player_image.load("player.png");
    enemy_image.loadImage("enemy0.png");
    player_bullet_image.load("player_bullet.png");
    enemy_bullet_image.load("enemy_bullet.png");

    player_1.setup(&player_image);
}

//--------------------------------------------------------------
void ofApp::update() {
    if (m_gameState == GameState::START) {

    }
    else if (m_gameState == GameState::GAME) {
        player_1.update();
        update_bullets();

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].update();
            if (enemies[i].time_to_shoot()) {
                Bullet b;
                b.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(b);
            }
        }
    }
    else if (m_gameState == GameState::END) {

    }
}

void ofApp::update_bullets() {
    for (unsigned int i = 0; i < bullets.size(); i++) {
        bullets[i].update();
        if (bullets[i].pos.y - bullets[i].width / 2 < 0 || bullets[i].pos.y + bullets[i].width / 2 > ofGetHeight()) {
            bullets.erase(bullets.begin() + i);
        }
    }
    // we'll call a collision check function here shortly
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (m_gameState == GameState::START) {

    }
    else if (m_gameState == GameState::GAME) {
        ofBackground(0, 0, 0);
        player_1.draw();
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].draw();
        }
        for (auto& bullet : bullets) {
            bullet.draw();
        }
    }
    else if (m_gameState == GameState::END) {

    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (m_gameState == GameState::GAME) {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = true;
        }
        else if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = true;
        }
        else if (key == OF_KEY_UP) {
            player_1.is_up_pressed = true;
        }
        else if (key == OF_KEY_DOWN) {
            player_1.is_down_pressed = true;
        }
        else if (key == ' ') {
            Bullet b;
            b.setup(true, player_1.pos, player_1.speed, &player_bullet_image);
            bullets.push_back(b);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (m_gameState == GameState::START) {
        if (key == 's') {
            m_gameState = GameState::GAME;
        }
    }
    else if (m_gameState == GameState::GAME) {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = false;
        }
        else if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = false;
        }
        else if (key == OF_KEY_UP) {
            player_1.is_up_pressed = false;
        }
        else if (key == OF_KEY_DOWN) {
            player_1.is_down_pressed = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

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

