/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include <irrlicht.h>
#include "Game.hpp"
#include "MenuManager.hpp"
#include "Bomb.hpp"
#include "RenderManager.hpp"
#include "Volume.hpp"
#include "IrrGraphical.hpp"

int main()
{
	IndieStudio::IrrGraphical graphical;

	IndieStudio::Volume *volume = new IndieStudio::Volume();
	// IndieStudio::MenuManager menu(graphical, volume);
	// IndieStudio::Game game(graphical);
	//IndieStudio::Map map(device, mapSceneManager, driver);
	// IndieStudio::RenderManager renderManager(menu, game);

	IndieStudio::IEntity *image = graphical.createImage("assets/menu/title2.png", std::pair<int, int>(20, 20));
	while (graphical.run()) {
		graphical.render();
		// game.moveCharacter();
		// game.checkEvent();
	}
	graphical.drop();
	return 0;
}