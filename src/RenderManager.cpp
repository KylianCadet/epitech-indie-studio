/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#include "RenderManager.hpp"

IndieStudio::RenderManager::RenderManager(IndieStudio::IRender &menu, IndieStudio::IRender &game, irr::video::IVideoDriver *driver)
: _menu(menu), _game(game), _driver(driver)
{
	menu.setEventReceiver();
}

IndieStudio::RenderManager::~RenderManager()
{
}

void IndieStudio::RenderManager::render()
{
	if (this->_menu.hasRender()) {
		irr::video::SColor color(255, 0, 0, 0);
		this->_driver->beginScene(true, true, color);
		this->_menu.render();
	} else {
		irr::video::SColor color(255, 255, 255, 255);
		this->_driver->beginScene(true, true, color);
		if (this->_counter == false) {
			this->_game.setEventReceiver();
			this->_counter = true;
		}
		this->_game.render();
	}
}