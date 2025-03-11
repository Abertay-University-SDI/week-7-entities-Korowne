#include "Goomba.h"

Goomba::Goomba()
{
}
Goomba::~Goomba()
{
}
void Goomba::update(float dt)
{
	move(velocity * dt);
}