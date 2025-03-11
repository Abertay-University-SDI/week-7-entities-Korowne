#pragma once
#include "Framework/GameObject.h"

class Goomba : public GameObject
{
public:
	Goomba();
	~Goomba();
	void update(float dt) override;

private:

};

