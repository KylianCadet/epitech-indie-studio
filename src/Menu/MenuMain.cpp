/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#include "MenuMain.hpp"

IndieStudio::MenuMain::MenuMain(irr::video::IVideoDriver *driver)
	: _driver(driver)
{
	int pos = 400;
	_newGame = new Button(_driver, "assets/menu/buttons/newgame.png", "assets/menu/buttons/newgameA.png", std::pair<int, int>(-1, pos));
	_loadGame = new Button(_driver, "assets/menu/buttons/loadgame.png", "assets/menu/buttons/loadgameA.png", std::pair<int, int>(-1, pos + 110));
	_options = new Button(_driver, "assets/menu/buttons/options.png", "assets/menu/buttons/optionsA.png", std::pair<int, int>(-1, pos + 220));
	_exit = new Button(_driver, "assets/menu/buttons/exit.png", "assets/menu/buttons/exitA.png", std::pair<int, int>(-1, pos + 330));
}

IndieStudio::MenuMain::~MenuMain()
{
}

void IndieStudio::MenuMain::drawMenu() noexcept
{
	refreshSkin();
	_newGame->drawButton();
	_loadGame->drawButton();
	_options->drawButton();
	_exit->drawButton();
}

void IndieStudio::MenuMain::refreshSkin() noexcept
{
	if (_buttonStatus == NEWGAME)
	{
		_newGame->setActiveSkin();
		_loadGame->setDefaultSkin();
		_options->setDefaultSkin();
		_exit->setDefaultSkin();
	}
	else if (_buttonStatus == LOADGAME)
	{
		_newGame->setDefaultSkin();
		_loadGame->setActiveSkin();
		_options->setDefaultSkin();
		_exit->setDefaultSkin();
	}
	else if (_buttonStatus == OPTIONS)
	{
		_newGame->setDefaultSkin();
		_loadGame->setDefaultSkin();
		_options->setActiveSkin();
		_exit->setDefaultSkin();
	}
	else if (_buttonStatus == EXIT)
	{
		_newGame->setDefaultSkin();
		_loadGame->setDefaultSkin();
		_options->setDefaultSkin();
		_exit->setActiveSkin();
	}
}

void IndieStudio::MenuMain::setButtonSwitch(int incrementation) noexcept
{
	_buttonStatus += incrementation;
	if (_buttonStatus > 3)
		_buttonStatus = 0;
	else if (_buttonStatus < 0)
		_buttonStatus = 3;
}

void IndieStudio::MenuMain::setButtonActive(int newButtonStatus) noexcept
{
	_buttonStatus = newButtonStatus;
}

int IndieStudio::MenuMain::getButtonStatus() const noexcept
{
	return _buttonStatus;
}