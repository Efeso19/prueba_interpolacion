/* 
 * File:   Player.h
 * Author: linuxero
 *
 * Created on March 5, 2014, 7:43 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "PhysicsState.h"
#include "Render.h"

class Player {
public:
	Player();
	Player(const Player& orig);
	virtual ~Player();
	
	void Init(const sf::Texture tex, float posX, float posY, float speedX, float speedY, float maxSpeedX, float maxSpeedY);
	
	// UPDATE DEL PLAYER (controlar velocidades y posiciones)
	
	// DRAW
	
private:
	Render			renderState;
	PhysicsState	physicsState;
};

#endif	/* PLAYER_H */

