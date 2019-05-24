/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#include "RenderManager.hpp"

IndieStudio::RenderManager::RenderManager(IndieStudio::IRender &menu, IndieStudio::IRender &game) : _menu(menu), _game(game)
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
			this->_game.setEventReceiver();
			this->_counter = true;
		}
		this->_game.render();
	}
}

irr::video::SColor IndieStudio::RenderManager::getColor() const noexcept
{
	return (this->_color);
}