/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#include "RenderManager.hpp"
#include "Config.hpp"
#include "Game.hpp"
#include "MenuManager.hpp"
#include "MusicManager.hpp"
#include "Volume.hpp"

IndieStudio::RenderManager::RenderManager(IndieStudio::IGraphical &graphical) :
	_graphical(graphical),
	_musicManager(this->_volume),
	_menu(this->_render, this->_graphical, this->_volume, this->_config),
	_game(this->_graphical, this->_render)
{
}

IndieStudio::RenderManager::~RenderManager()
{
}

void IndieStudio::RenderManager::render(void) noexcept
{
	this->_musicManager.refreshMusic(this->_render);
	if (this->_render == Render::GAME)
		this->_game.render();
	else if (this->_render == Render::MAIN_MENU || Render::PAUSE_MENU)
		this->_menu.render();
}