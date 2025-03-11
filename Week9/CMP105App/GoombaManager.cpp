#include "GoombaManager.h"
#include <iostream>

GoombaManager::GoombaManager(sf::Vector2u windowSize)
{
	sizeOfWindow = windowSize;

	spawnY = 0 - 100.0f;
	GoombaTex.loadFromFile("gfx/Goomba.png");
	for (int i = 0; i < GOOMBA_COUNT; i++)
	{
		Goombas.push_back(Goomba());
		Goombas[i].setAlive(false);
		Goombas[i].setTexture(&GoombaTex);
		Goombas[i].setSize(sf::Vector2f(100, 100));
	}

	font.loadFromFile("font/arial.ttf");
	message.setFont(font);
	message.setCharacterSize(24);
	message.setPosition(300, 300);
}

GoombaManager::~GoombaManager()
{
}

void GoombaManager::update(float dt)
{
	timeSinceCountPrinted += dt;
	int numberOfGoombasAlive = 0;

	// call update on all ALIVE Goombas
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (Goombas[i].isAlive())
		{
			numberOfGoombasAlive++;
			Goombas[i].update(dt);
		}
	}

	if (timeSinceCountPrinted > TIME_BETWEEN_PRINTING)
	{
		std::cout << numberOfGoombasAlive << std::endl;
		timeSinceCountPrinted = 0.0f;
	}

	message.setString(std::to_string(numberOfGoombasAlive));

	deathCheck();
}

// Spawn new Goomba
// Find a dead Goomba, make alive, move to spawn point, give random velocity
void GoombaManager::spawn()
{
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (!Goombas[i].isAlive())
		{
			Goombas[i].setAlive(true);
			Goombas[i].setVelocity(0, 150);
			Goombas[i].setPosition(rand() % sizeOfWindow.y, spawnY);
			return;
		}
	}
	// USELESS BUT WHATEVER
	// spawns when more then 20 Goombas are alive?

	//Goombas.push_back(Goomba());
	//Goombas[Goombas.size() - 1].setAlive(true);
	//Goombas[Goombas.size() - 1].setTexture(&GoombaTex);
	//Goombas[Goombas.size() - 1].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
	//Goombas[Goombas.size() - 1].setSize(sf::Vector2f(100, 100));
	//Goombas[Goombas.size() - 1].setPosition(spawnY);
}

// Check all ALIVE Goombas to see if outscreen screen/range, if so make dead
void GoombaManager::deathCheck()
{
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (Goombas[i].getPosition().y > sizeOfWindow.y)
		{
			Goombas[i].setAlive(false);
		}
	}
}

// Render all alive Goombas
void GoombaManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (Goombas[i].isAlive())
		{
			window->draw(Goombas[i]);
		}
	}
	window->draw(message);
}