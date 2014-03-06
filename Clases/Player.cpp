/* 
 * File:   Player.cpp
 * Author: linuxero
 * 
 * Created on March 5, 2014, 7:43 AM
 */

#include "Player.h"

Player::Player(): renderState(), physicsState() {
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::Init(const sf::Texture tex, float posX, float posY, float speedX, float speedY, float maxSpeedX, float maxSpeedY){

	renderState.SetTexture(tex);
	
	physicsState.SetPosition(sf::Vector2f(posX, posY));
	physicsState.SetSpeed(sf::Vector2f(speedX, speedY));
	physicsState.SetMaxSpeed(sf::Vector2f(maxSpeedX, maxSpeedY));
	physicsState.SetMaxSpeed(sf::Vector2f(maxSpeedX, maxSpeedY));
}