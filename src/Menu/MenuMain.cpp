/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#include "MenuMain.hpp"

IndieStudio::MenuMain::MenuMain(irr::video::IVideoDriver * driver)
: _driver(driver)
{
	_btnA = NEWGAME;
	int pos = 400;
	_newGame = new NewGame(_driver, "assets/menu/buttons/newgame.png", "assets/menu/buttons/newgameA.png", std::pair<int, int> (-1, pos));
	_loadGame = new LoadGame(_driver, "assets/menu/buttons/loadgame.png", "assets/menu/buttons/loadgameA.png", std::pair<int, int> (-1, pos + 110));
	_options = new Options(_driver, "assets/menu/buttons/options.png", "assets/menu/buttons/optionsA.png", std::pair<int, int> (-1, pos + 220));
	_exit = new Exit(_driver, "assets/menu/buttons/exit.png", "assets/menu/buttons/exitA.png", std::pair<int, int> (-1, pos + 330));
	_frame = new IndieStudio::Image2d(driver, "assets/menu/frame.png", std::pair<int, int> (-1, 320));
	_tick = new IndieStudio::Audio("sounds/menu/tick.ogg");
	_music = new IndieStudio::Audio("sounds/menu/Stillness2.ogg", true);
	_music->playSound();
}

IndieStudio::MenuMain::~MenuMain()
{

}

void IndieStudio::MenuMain::drawAll()
{
	setSkin();
	_newGame->draw();
	_loadGame->draw();
	_options->draw();
	_exit->draw();
	_frame->draw();
}

void IndieStudio::MenuMain::setSkin()
{
	if (_btnA == NEWGAME) {
		_newGame->setActive();
		_loadGame->setDefault();
		_options->setDefault();
		_exit->setDefault();
	} else if (_btnA == LOADGAME) {
		_newGame->setDefault();
		_loadGame->setActive();
		_options->setDefault();
		_exit->setDefault();
	} else if (_btnA == OPTIONS) {
		_newGame->setDefault();
		_loadGame->setDefault();
		_options->setActive();
		_exit->setDefault();
	} else if (_btnA == EXIT) {
		_newGame->setDefault();
		_loadGame->setDefault();
		_options->setDefault();
		_exit->setActive();
	}
}

void IndieStudio::MenuMain::setIncA(int i)
{
	_tick->playSound();
	_btnA += i;
	if (_btnA > 3)
		_btnA = 0;
	else if (_btnA < 0)
		_btnA = 3;
}

void IndieStudio::MenuMain::setBtnA(int btn)
{
	_btnA = btn;
}

int IndieStudio::MenuMain::getBtnA() const noexcept
{
	return _btnA;
}