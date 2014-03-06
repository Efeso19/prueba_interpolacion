/* 
 * File:   PhysicsState.h
 * Author: linuxero
 *
 * Created on March 5, 2014, 8:32 AM
 */

#ifndef PHYSICSSTATE_H
#define	PHYSICSSTATE_H

#include <SFML/Graphics.hpp>

class PhysicsState {
public:
	PhysicsState();
	PhysicsState(const PhysicsState& orig);
	virtual ~PhysicsState();
	
	sf::Vector2f GetPreviousPosition() const { return posPrev; }
	sf::Vector2f GetPosition() const { return posNew; }
	sf::Vector2f GetNextPosition(sf::Time elapsedTime) const;
	sf::Vector2f GetSpeed() const { return speed; }
	sf::Vector2f GetMaxSpeed() const { return maxSpeed; }
	
	void SetSpeed(float vel_x, float vel_y);
	void SetPosition(float pos_x, float pos_y);
	void SetMaxSpeed(float speed_x, float speed_y);
	void Update(sf::Time elapsedTime);
	
	/*
	sf::Vector2f GetPreviousVelocity() const { return previousvelocity_; }
	sf::Vector2f GetAcceleration() const { return acceleration_; }
	void SetAcceleration(float acc_x, float acc_y);
	 */
	
private:
	sf::Vector2f posPrev;
	sf::Vector2f posNew;
	sf::Vector2f speed;
	sf::Vector2f maxSpeed;
	
	
	/*sf::Vector2f previousvelocity_;
	sf::Vector2f acceleration_;*/
	

};



#endif	/* PHYSICSSTATE_H */

