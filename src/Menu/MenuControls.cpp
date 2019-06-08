/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuControls
*/

#include "MenuControls.hpp"

IndieStudio::Key operator++(IndieStudio::Key other, int i)
{
	return (static_cast<IndieStudio::Key>(static_cast<char>(other) + i));
}

IndieStudio::MenuControls::MenuControls(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config)
	: Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_CONTROLS_MAIN;
	this->_playerStatus = MENU_CONTROLS_PLY_1;
	this->createButtons();
	this->createImages();
	for (auto it = this->_letters.begin(); it != this->_letters.end(); it++)
		std::cout << (*it)._str << std::endl;
}

IndieStudio::MenuControls::~MenuControls()
{
}

void IndieStudio::MenuControls::createButtons(void) noexcept
{
	IndieStudio::Key key = A;
	letter tmp;
	std::string def = "assets/menu/controls/letters/";
	std::string act = "assets/menu/controls/letters/#";
	for (char c = 'A'; c <= 'Z'; c++)
	{
		tmp._str = c;
		tmp._btn = new Button(this->_graphical, def + c + ".png", act + c + ".png", std::pair<int, int>(-1, 500));
		tmp._key = key++;
		this->_letters.push_back(tmp);
	}
}

void IndieStudio::MenuControls::drawButtons(void) noexcept
{
	// for (auto it = this->_letters.begin(); it != this->_letters.end(); it++)
	// 	(*it)._btn->drawButton();
}

void IndieStudio::MenuControls::createImages(void) noexcept
{
	int x = 875;
	int pos = 385;
	int off = 70;
	int x2 = 970;
	int pos2 = 385;
	int off2 = 70;
	this->_player1 = this->_graphical.createImage("assets/menu/controls/player1.png", std::pair<int, int>(-1, 362.5));
	this->_player2 = this->_graphical.createImage("assets/menu/controls/player2.png", std::pair<int, int>(-1, 362.5));
	this->_forward = new Button(this->_graphical, "assets/menu/controls/up.png", "assets/menu/controls/upA.png", std::pair<int, int>(x, (pos += off)));
	this->_left = new Button(this->_graphical, "assets/menu/controls/down.png", "assets/menu/controls/downA.png", std::pair<int, int>(x, (pos += off)));
	this->_right = new Button(this->_graphical, "assets/menu/controls/left.png", "assets/menu/controls/leftA.png", std::pair<int, int>(x, (pos += off)));
	this->_bomb = new Button(this->_graphical, "assets/menu/controls/right.png", "assets/menu/controls/rightA.png", std::pair<int, int>(x, (pos += off)));
	this->_back = new Button(this->_graphical, "assets/menu/controls/bomb.png", "assets/menu/controls/bombA.png", std::pair<int, int>(x, (pos += off)));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
	// this->_D = this->_graphical.createImage("assets/menu/controls/letters/D.png", std::pair<int, int>(x2, (pos2 += off2)));
}

void IndieStudio::MenuControls::drawImages(void) noexcept
{
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
	{
		this->_graphical.drawImage(this->_player1);
	}
	else if (this->_playerStatus == MENU_CONTROLS_PLY_2)
	{
		this->_graphical.drawImage(this->_player2);
	}
	this->_forward->drawButton();
	this->_back->drawButton();
	this->_left->drawButton();
	this->_right->drawButton();
	this->_bomb->drawButton();
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuControls::checkActions(void) noexcept
{
}

void IndieStudio::MenuControls::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuControls::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_CONTROLS_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_CONTROLS_BACK)
		this->drawMenu();
}

void IndieStudio::MenuControls::refreshSkin(void) noexcept
{
}

void IndieStudio::MenuControls::returnAction(void) noexcept
{
}

void IndieStudio::MenuControls::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_CONTROLS_BACK;
}

void IndieStudio::MenuControls::leftAction(void) noexcept
{
}

void IndieStudio::MenuControls::rightAction(void) noexcept
{
}

void IndieStudio::MenuControls::upAction(void) noexcept
{
}

void IndieStudio::MenuControls::downAction(void) noexcept
{
}

void IndieStudio::MenuControls::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuControls::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_CONTROLS_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_CONTROLS_BACK)
		this->escapeAction();
}

void IndieStudio::MenuControls::leftActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
		this->_playerStatus = MENU_CONTROLS_PLY_2;
	else
		this->_playerStatus = MENU_CONTROLS_PLY_1;
}

void IndieStudio::MenuControls::rightActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
		this->_playerStatus = MENU_CONTROLS_PLY_2;
	else
		this->_playerStatus = MENU_CONTROLS_PLY_1;
}

void IndieStudio::MenuControls::upActionManager(void) noexcept
{
}

void IndieStudio::MenuControls::downActionManager(void) noexcept
{
}