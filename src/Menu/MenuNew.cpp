/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuNew
*/

#include "MenuNew.hpp"

IndieStudio::MenuNew::MenuNew(irr::video::IVideoDriver *driver, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(driver, volume, sounds)
{
	this->_renderStatus = MENU_NEW_MAIN;
	this->_buttonStatus = BTN_NEW_SOLO;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuNew::~MenuNew()
{
}

void IndieStudio::MenuNew::createButtons(void) noexcept
{
	this->_solomode = new Button(this->_driver, "assets/menu/buttons/solo.png", "assets/menu/buttons/soloA.png", std::pair<int, int>(-1, 400));
	this->_1vs1mode = new Button(this->_driver, "assets/menu/buttons/1vs1.png", "assets/menu/buttons/1vs1A.png", std::pair<int, int>(-1, 400 + 110));
	this->_2vs2mode = new Button(this->_driver, "assets/menu/buttons/2vs2.png", "assets/menu/buttons/2vs2A.png", std::pair<int, int>(-1, 400 + 220));
	this->_back = new Button(this->_driver, "assets/menu/buttons/back.png", "assets/menu/buttons/backA.png", std::pair<int, int>(-1, 400 + 330));
}

void IndieStudio::MenuNew::drawButtons(void) noexcept
{
	this->_solomode->drawButton();
	this->_1vs1mode->drawButton();
	this->_2vs2mode->drawButton();
	this->_back->drawButton();
}

void IndieStudio::MenuNew::createImages(void) noexcept
{
}

void IndieStudio::MenuNew::drawImages(void) noexcept
{
}

void IndieStudio::MenuNew::checkActions(void) noexcept
{
}

void IndieStudio::MenuNew::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuNew::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_NEW_BACK)
		this->drawMenu();
}

void IndieStudio::MenuNew::refreshSkin(void) noexcept
{
	if (this->_buttonStatus == BTN_NEW_SOLO)
	{
		this->_solomode->setActiveSkin();
		this->_1vs1mode->setDefaultSkin();
		this->_2vs2mode->setDefaultSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_NEW_1VS1)
	{
		this->_solomode->setDefaultSkin();
		this->_1vs1mode->setActiveSkin();
		this->_2vs2mode->setDefaultSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_NEW_2VS2)
	{
		this->_solomode->setDefaultSkin();
		this->_1vs1mode->setDefaultSkin();
		this->_2vs2mode->setActiveSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_NEW_BACK)
	{
		this->_solomode->setDefaultSkin();
		this->_1vs1mode->setDefaultSkin();
		this->_2vs2mode->setDefaultSkin();
		this->_back->setActiveSkin();
	}
}

void IndieStudio::MenuNew::returnAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_buttonStatus == BTN_NEW_SOLO)
		this->_renderStatus = MENU_NEW_GAME;
	else if (this->_buttonStatus == BTN_NEW_1VS1)
		this->_renderStatus = MENU_NEW_GAME;
	else if (this->_buttonStatus == BTN_NEW_2VS2)
		this->_renderStatus = MENU_NEW_GAME;
	else if (this->_buttonStatus == BTN_NEW_BACK)
		this->_renderStatus = MENU_NEW_BACK;
}

void IndieStudio::MenuNew::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_NEW_BACK;
}

void IndieStudio::MenuNew::leftAction(void) noexcept
{
}

void IndieStudio::MenuNew::rightAction(void) noexcept
{
}

void IndieStudio::MenuNew::upAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuNew::downAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuNew::returnActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->returnAction();
}

void IndieStudio::MenuNew::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_NEW_BACK)
		this->escapeAction();
}

void IndieStudio::MenuNew::leftActionManager(void) noexcept
{
}

void IndieStudio::MenuNew::rightActionManager(void) noexcept
{
}

void IndieStudio::MenuNew::upActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->upAction();
}

void IndieStudio::MenuNew::downActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->downAction();
}