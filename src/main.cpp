/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include <irrlicht.h>
#include "Game.hpp"

int main()
{
	irr::IrrlichtDevice *device = irr::createDevice(
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(800, 800),
		32);
	irr::video::IVideoDriver *driver = device->getVideoDriver();
	irr::scene::ISceneManager *gameSceneManager = device->getSceneManager();
	irr::scene::ISceneManager *menuSceneManager = gameSceneManager->createNewSceneManager();
	device->getCursorControl()->setVisible(false);

	IndieStudio::Game game(device, gameSceneManager, driver);

	/* RENDU */
	irr::video::SColor color(
		255,
		255,
		255,
		255);

	while (device->run()) {
		driver->beginScene(true, true, color);
		game.render();
		driver->endScene();
	}
	device->drop();
	return 0;
}