/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuControls
*/

#include "MenuControls.hpp"

IndieStudio::MenuControls::MenuControls(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(graphical, volume, sounds)
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
	this->_comingsoon = this->_graphical.createImage("assets/menu/comingsoon.png", std::pair<int, int>(-1, 500));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuControls::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_comingsoon);
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