/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include <irrlicht.h>
#include "Game.hpp"
#include "Menu.hpp"
#include "Bomb.hpp"
#include "RenderManager.hpp"
#include "Map.hpp"
int main()
{
	sleep(1);
	irr::IrrlichtDevice *device = irr::createDevice(
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(2000, 2000), 32);
	irr::video::IVideoDriver *driver = device->getVideoDriver();
	irr::scene::ISceneManager *gameSceneManager = device->getSceneManager();
	irr::scene::ISceneManager *menuSceneManager = gameSceneManager->createNewSceneManager();
	irr::scene::ISceneManager *mapSceneManager = gameSceneManager->createNewSceneManager();
	device->getCursorControl()->setVisible(false);

	IndieStudio::Menu menu(device, menuSceneManager, driver);
	IndieStudio::Game game(device, gameSceneManager, driver);
	IndieStudio::Map map(device, mapSceneManager, driver);
	IndieStudio::RenderManager renderManager(menu, game, map);

	while (device->run()) {
		driver->beginScene(true, true, renderManager.getColor());
		renderManager.render();
		driver->endScene();
	}
	device->drop();
	return 0;
}