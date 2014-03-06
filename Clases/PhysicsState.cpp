/* 
 * File:   PhysicsState.cpp
 * Author: linuxero
 * 
 * Created on March 5, 2014, 8:32 AM
 */
#include "PhysicsState.h"
PhysicsState::PhysicsState() {
}
PhysicsState::PhysicsState(const PhysicsState& orig) {
}
PhysicsState::~PhysicsState() {
}
PhysicsState::PhysicsState() : posPrev(0), posNew(0), speed(0), maxSpeed(0)
{
}

void PhysicsState::SetPosition(float pos_x, float pos_y)
{
	posPrev = sf::Vector2f(pos_x, pos_y);
	posNew = sf::Vector2f(pos_x, pos_y);
}

void PhysicsState::SetSpeed(float vel_x, float vel_y)
{
	speed = sf::Vector2f(vel_x, vel_y);
	//previousvelocity_ = sf::Vector2f(vel_x, vel_y);
}



void PhysicsState::SetMaxSpeed(float speed_x, float speed_y)
{
	maxSpeed = sf::Vector2f(speed_x, speed_y);
}


void PhysicsState::Update(sf::Time elapsedTime)
{

	/*  COLISIONES  */
	
	posPrev = posNew;
	posNew.x += speed.x * elapsedTime;
	posNew.y += speed.y * elapsedTime;
}


/*
void PhysicsState::SetAcceleration(float acc_x, float acc_y)
{
	acceleration_ = sf::Vector2f(acc_x, acc_y);
}
 * */