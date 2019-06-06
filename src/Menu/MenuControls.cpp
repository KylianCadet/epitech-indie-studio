/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuControls
*/

#include "MenuControls.hpp"

IndieStudio::MenuControls::MenuControls(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config)
	: Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_CONTROLS_MAIN;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuControls::~MenuControls()
{
}

void IndieStudio::MenuControls::createButtons(void) noexcept
{
}

void IndieStudio::MenuControls::drawButtons(void) noexcept
{
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
	this->_forward = this->_graphical.createImage("assets/menu/controls/up.png", std::pair<int, int>(x, (pos += off)));
	this->_back = this->_graphical.createImage("assets/menu/controls/down.png", std::pair<int, int>(x, (pos += off)));
	this->_left = this->_graphical.createImage("assets/menu/controls/left.png", std::pair<int, int>(x, (pos += off)));
	this->_right = this->_graphical.createImage("assets/menu/controls/right.png", std::pair<int, int>(x, (pos += off)));
	this->_action = this->_graphical.createImage("assets/menu/controls/bomb.png", std::pair<int, int>(x, (pos += off)));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
	this->_Z = this->_graphical.createImage("assets/menu/controls/letters/Z.png", std::pair<int, int>(x2, (pos2 += off2)));
	this->_S = this->_graphical.createImage("assets/menu/controls/letters/S.png", std::pair<int, int>(x2, (pos2 += off2)));
	this->_Q = this->_graphical.createImage("assets/menu/controls/letters/Q.png", std::pair<int, int>(x2, (pos2 += off2)));
	this->_D = this->_graphical.createImage("assets/menu/controls/letters/D.png", std::pair<int, int>(x2, (pos2 += off2)));
	this->_E = this->_graphical.createImage("assets/menu/controls/letters/E.png", std::pair<int, int>(x2, (pos2 += off2)));
}

void IndieStudio::MenuControls::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_player1);
	this->_graphical.drawImage(this->_forward);
	this->_graphical.drawImage(this->_back);
	this->_graphical.drawImage(this->_left);
	this->_graphical.drawImage(this->_right);
	this->_graphical.drawImage(this->_action);
	this->_graphical.drawImage(this->_escapeInfo);
	this->_graphical.drawImage(this->_Z);
	this->_graphical.drawImage(this->_S);
	this->_graphical.drawImage(this->_Q);
	this->_graphical.drawImage(this->_D);
	this->_graphical.drawImage(this->_E);
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
}

void IndieStudio::MenuControls::rightActionManager(void) noexcept
{
}

void IndieStudio::MenuControls::upActionManager(void) noexcept
{
}

void IndieStudio::MenuControls::downActionManager(void) noexcept
{
}