#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>

class BeachBallManager
{
public:
	BeachBallManager();
	~BeachBallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture ballTex;
	float timeSinceCountPrinted = 0.0f;

	const float TIME_BETWEEN_PRINTING = 3.0f;

};

