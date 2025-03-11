#pragma once
#include "Goomba.h"
#include <math.h>
#include <vector>

class GoombaManager
{
public:
	GoombaManager(sf::Vector2u windowSize);
	~GoombaManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	std::vector<Goomba> Goombas;
	float spawnY;
	sf::Texture GoombaTex;
	sf::Font font;
	sf::Text message;
	float timeSinceCountPrinted = 0.0f;
	sf::Vector2u sizeOfWindow;

	const float TIME_BETWEEN_PRINTING = 3.0f;
	const int GOOMBA_COUNT = 40;
};