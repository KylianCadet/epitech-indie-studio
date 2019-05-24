/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#include "RenderManager.hpp"

IndieStudio::RenderManager::RenderManager(IndieStudio::IRender &menu, IndieStudio::IRender &game, IndieStudio::IRender &map) : _menu(menu), _game(game), _map(map)
{
	menu.setEventReceiver();
	this->_color = irr::video::SColor(255, 0, 0, 0);
}

IndieStudio::RenderManager::~RenderManager()
{
}

void IndieStudio::RenderManager::render()
{
	if (this->_menu.hasRender()) {
		
		this->_menu.render();
	} else {
		if (this->_counter == false) {
			this->_color = irr::video::SColor(255, 255, 255, 255);
			// this->_map.setEventReceiver();
			this->_game.setEventReceiver();
			this->_counter = true;
		}
		// this->_map.render();
		this->_game.render();
	}
}

irr::video::SColor IndieStudio::RenderManager::getColor() const noexcept
{
	return (this->_color);
}