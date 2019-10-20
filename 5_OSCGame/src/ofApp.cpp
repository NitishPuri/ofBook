#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {


    m_gameState = GameState::START;
    score = 0;

    max_enemy_amplitude = 3.0;
    max_enemy_shoot_interval = 1.5;

    player_image.load("player.png");
    enemy_image.loadImage("enemy0.png");
    player_bullet_image.load("player_bullet.png");
    enemy_bullet_image.load("enemy_bullet.png");
    life_image.load("life_image.png");
    start_screen.load("start_screen.png");
    end_screen.load("end_screen.png");

    player_1.setup(&player_image);

    score_font.load("Gota_Light.otf", 48);
    //simply change this boolean to turn testing on and off
    //testing == false;
    //if (testing == true) {
    //    liveTest = LiveTesting();
    //}
}

//--------------------------------------------------------------
void ofApp::update() {
    if (m_gameState == GameState::START) {

    }
    else if (m_gameState == GameState::GAME) {
        player_1.update();
        update_bullets();
        update_bonuses();

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].update();
            if (enemies[i].time_to_shoot()) {
                Bullet b;
                b.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(b);
            }
        }

        if (level_controller.should_spawn()) {
            Enemy e;
            e.setup(max_enemy_amplitude, max_enemy_shoot_interval, &enemy_image);
            enemies.push_back(e);
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
    check_bullet_collisions();
}

void ofApp::update_bonuses()
{
    for (int i = bonuses.size() - 1; i > 0; i--) {
        bonuses[i].update();
        if (ofDist(player_1.pos.x, player_1.pos.y, bonuses[i].pos.x, bonuses[i].pos.y) < (player_1.width + bonuses[i].width) / 2) {
            player_1.lives++;
            bonuses.erase(bonuses.begin() + i);
        }

        if (bonuses[i].pos.y + bonuses[i].width / 2 > ofGetHeight()) {
            bonuses.erase(bonuses.begin() + i);
        }
    }
}

void ofApp::check_bullet_collisions()
{
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].from_player) {
            for (int e = enemies.size() - 1; e >= 0; e--) {
                if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) < (enemies[e].width + bullets[i].width) / 2) {
                    enemies.erase(enemies.begin() + e);
                    bullets.erase(bullets.begin() + i);
                    score += 10;
                }
            }
        }
        else {
            if (ofDist(bullets[i].pos.x, bullets[i].pos.y, player_1.pos.x, player_1.pos.y) < (bullets[i].width + player_1.width) / 2) {
                bullets.erase(bullets.begin() + i);
                player_1.lives--;

                if (player_1.lives <= 0) {
                    m_gameState = GameState::END;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (m_gameState == GameState::START) {
        start_screen.draw(0, 0);
    }
    else if (m_gameState == GameState::GAME) {
        ofBackground(0, 0, 0);
        player_1.draw();
        draw_lives();
        draw_score();

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].draw();
        }
        for (auto& bullet : bullets) {
            bullet.draw();
        }
        for (auto& bonus : bonuses) {
            bonus.draw();
        }
    }
    else if (m_gameState == GameState::END) {
        end_screen.draw(0, 0);
    }

}

void ofApp::draw_lives()
{
    for (int i = 0; i < player_1.lives; i++) {
        player_image.draw(ofGetWidth() - (i * player_image.getWidth()) - 100, 30);
    }
}

void ofApp::draw_score()
{
    if (m_gameState == GameState::GAME) {
        score_font.drawString(ofToString(score), 30, 72);
    }
    else if (m_gameState == GameState::END) {
        float w = score_font.stringWidth(ofToString(score));
        score_font.drawString(ofToString(score), ofGetWidth() / 2 - w / 2, ofGetHeight() / 2 + 100);
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
            level_controller.setup(ofGetElapsedTimeMillis());
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

