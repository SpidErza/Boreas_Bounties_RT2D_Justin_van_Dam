/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	float speed = 600.0f;

	Point2 right = Point2(1, 0);
	Point2 up = Point2(0, 1);

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::W)) {
		velocity += polar.cartesian() * deltaTime; // thrust
	}
	if (input()->getKey(KeyCode::D)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::A)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	rotation.z = polar.angle;
	position += velocity * deltaTime;

	// Temporary for testing
	if (position.x < 0) { position.x = SWIDTH; }
	if (position.x > SWIDTH) { position.x = 0; }
	if (position.y < 0) { position.y = SHEIGHT; }
	if (position.y > SHEIGHT) { position.y = 0; }
}
