#include "BeachBallManager.h"
#include <iostream>

BeachBallManager::BeachBallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	ballTex.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&ballTex);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BeachBallManager::~BeachBallManager()
{
}

void BeachBallManager::update(float dt)
{
	timeSinceCountPrinted += dt;
	int numberOfBallsAlive = 0;

	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			numberOfBallsAlive++;
			balls[i].update(dt);
		}
	}

	if (timeSinceCountPrinted > TIME_BETWEEN_PRINTING)
	{
		std::cout << numberOfBallsAlive << std::endl;
		timeSinceCountPrinted = 0.0f;
	}
	deathCheck();
}

// Spawn new ball
// Find a dead ball, make alive, move to spawn point, give random velocity
void BeachBallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
	// spawns when more then 20 balls are alive?

	balls.push_back(Ball());
	balls[balls.size() - 1].setAlive(true);
	balls[balls.size() - 1].setTexture(&ballTex);
	balls[balls.size() - 1].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
	balls[balls.size() - 1].setSize(sf::Vector2f(100, 100));
	balls[balls.size() - 1].setPosition(spawnPoint);
}

// Check all ALIVE balls to see if outscreen screen/range, if so make dead
void BeachBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > 800)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > 600)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

// Render all alive balls
void BeachBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}
