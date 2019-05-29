/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#include "RenderManager.hpp"

IndieStudio::RenderManager::RenderManager(IndieStudio::IRender &menu, IndieStudio::IRender &game) : _menu(menu), _game(game)
{
	this->_color = irr::video::SColor(255, 0, 0, 0);
	this->_menu.setRenderStatus(MAIN_MENU);
	this->_game.setRenderStatus(MAIN_MENU);
}

IndieStudio::RenderManager::~RenderManager()
{
}

void IndieStudio::RenderManager::render()
{
	if (this->_menu.getRenderStatus() == MAIN_MENU)
	{
		this->_game.setRenderStatus(MAIN_MENU);
		this->_menu.render();
	}
	else if (this->_game.getRenderStatus() == PAUSE_MENU)
	{
		this->_menu.setRenderStatus(PAUSE_MENU);
		this->_game.render();
		this->_menu.render();
	}
	else if (this->_menu.getRenderStatus() == GAME)
	{
		this->_game.setRenderStatus(GAME);
		this->_game.render();
	}
}

irr::video::SColor IndieStudio::RenderManager::getColor() const noexcept
{
	return (this->_color);
}