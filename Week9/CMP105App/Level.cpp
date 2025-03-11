#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	tooManyGoombas = new GoombaManager(window->getSize());
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		THEManager.spawn();
		tooManyGoombas->spawn();
		input->setKeyUp(sf::Keyboard::Space);
	}
}

// Update game objects
void Level::update(float dt)
{
	THEManager.update(dt);
	THEManager.deathCheck();

	tooManyGoombas->update(dt);
	tooManyGoombas->deathCheck();

}

// Render level
void Level::render()
{
	beginDraw();

	//THEManager.render(window);
	tooManyGoombas->render(window);

	endDraw();
}
