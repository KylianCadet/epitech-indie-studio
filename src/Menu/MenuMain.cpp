/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#include "MenuMain.hpp"

IndieStudio::MenuMain::MenuMain(irr::video::IVideoDriver *driver, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(driver, volume, sounds)
{
	this->_renderStatus = MENU_MAIN_MAIN;
	this->_buttonStatus = BTN_MAIN_NEWGAME;
	this->createButtons();
	this->createImages();
	this->_menuNew = new IndieStudio::MenuNew(this->_driver, this->_volume, this->_sounds);
	this->_menuLoad = new IndieStudio::MenuLoad(this->_driver, this->_volume, this->_sounds);
	this->_menuOptions = new IndieStudio::MenuOptions(this->_driver, this->_volume, this->_sounds);
}

IndieStudio::MenuMain::~MenuMain()
{
}

void IndieStudio::MenuMain::createButtons(void) noexcept
{
	this->_newGame = new Button(this->_driver, "assets/menu/buttons/newgame.png", "assets/menu/buttons/newgameA.png", std::pair<int, int>(-1, 400));
	this->_loadGame = new Button(this->_driver, "assets/menu/buttons/loadgame.png", "assets/menu/buttons/loadgameA.png", std::pair<int, int>(-1, 400 + 110));
	this->_options = new Button(this->_driver, "assets/menu/buttons/options.png", "assets/menu/buttons/optionsA.png", std::pair<int, int>(-1, 400 + 220));
	this->_exit = new Button(this->_driver, "assets/menu/buttons/exit.png", "assets/menu/buttons/exitA.png", std::pair<int, int>(-1, 400 + 330));
}

void IndieStudio::MenuMain::drawButtons(void) noexcept
{
	this->_newGame->drawButton();
	this->_loadGame->drawButton();
	this->_options->drawButton();
	this->_exit->drawButton();
}

void IndieStudio::MenuMain::createImages(void) noexcept
{
	this->_titleMenu = new IndieStudio::Image2d(this->_driver, "assets/menu/title2.png", std::pair<int, int>(-1, 100));
	this->_frameMenu = new IndieStudio::Image2d(this->_driver, "assets/menu/frame.png", std::pair<int, int>(-1, 320));
}

void IndieStudio::MenuMain::drawImages(void) noexcept
{
	this->_titleMenu->drawImage();
	this->_titleMenu->drawImage();
	this->_frameMenu->drawImage();
}

void IndieStudio::MenuMain::checkActions(void) noexcept
{

	if (this->_menuOptions->getCurrentMenuActive() == MENU_OPTIONS_BACK)
	{
		this->_renderStatus = MENU_MAIN_MAIN;
		this->_menuOptions->setMenuActive(MENU_OPTIONS_MAIN);
	}
	else if (this->_menuLoad->getCurrentMenuActive() == MENU_LOAD_BACK)
	{
		this->_renderStatus = MENU_MAIN_MAIN;
		this->_menuLoad->setMenuActive(MENU_LOAD_MAIN);
	}
	else if (this->_menuNew->getCurrentMenuActive() == MENU_NEW_BACK)
	{
		this->_renderStatus = MENU_MAIN_MAIN;
		this->_menuNew->setMenuActive(MENU_NEW_MAIN);
	}
	else if (this->_menuNew->getCurrentMenuActive() == MENU_NEW_GAME)
	{
		this->_renderStatus = MENU_MAIN_GAME;
		this->_menuNew->setMenuActive(MENU_NEW_MAIN);
	}
}

void IndieStudio::MenuMain::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuMain::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus != MENU_MAIN_MAIN)
		this->drawImages();
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->_menuNew->drawMenuManager();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->_menuLoad->drawMenuManager();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->drawMenuManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->drawMenu();
}

void IndieStudio::MenuMain::refreshSkin(void) noexcept
{
	if (this->_buttonStatus == BTN_MAIN_NEWGAME)
	{
		this->_newGame->setActiveSkin();
		this->_loadGame->setDefaultSkin();
		this->_options->setDefaultSkin();
		this->_exit->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_MAIN_LOADGAME)
	{
		this->_newGame->setDefaultSkin();
		this->_loadGame->setActiveSkin();
		this->_options->setDefaultSkin();
		this->_exit->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_MAIN_OPTIONS)
	{
		this->_newGame->setDefaultSkin();
		this->_loadGame->setDefaultSkin();
		this->_options->setActiveSkin();
		this->_exit->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_MAIN_EXIT)
	{
		this->_newGame->setDefaultSkin();
		this->_loadGame->setDefaultSkin();
		this->_options->setDefaultSkin();
		this->_exit->setActiveSkin();
	}
}

void IndieStudio::MenuMain::returnAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_buttonStatus == BTN_MAIN_NEWGAME)
		this->_renderStatus = MENU_MAIN_NEWGAME;
	else if (this->_buttonStatus == BTN_MAIN_LOADGAME)
		this->_renderStatus = MENU_MAIN_LOADGAME;
	else if (this->_buttonStatus == BTN_MAIN_OPTIONS)
		this->_renderStatus = MENU_MAIN_OPTIONS;
	else if (this->_buttonStatus == BTN_MAIN_EXIT)
		this->_renderStatus = MENU_MAIN_EXIT;
}

void IndieStudio::MenuMain::escapeAction(void) noexcept
{
}

void IndieStudio::MenuMain::leftAction(void) noexcept
{
}

void IndieStudio::MenuMain::rightAction(void) noexcept
{
}

void IndieStudio::MenuMain::upAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuMain::downAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuMain::returnActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->returnAction();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->_menuNew->returnActionManager();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->returnAction();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->returnActionManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->returnAction();
}

void IndieStudio::MenuMain::escapeActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->_menuNew->escapeActionManager();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->_menuLoad->escapeActionManager();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->escapeActionManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->escapeAction();
}

void IndieStudio::MenuMain::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->leftAction();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->leftAction();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->leftAction();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->leftActionManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->leftAction();
}

void IndieStudio::MenuMain::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->rightAction();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->rightAction();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->rightAction();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->rightActionManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->rightAction();
}

void IndieStudio::MenuMain::upActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->upAction();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->_menuNew->upActionManager();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->upAction();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->upActionManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->upAction();
}

void IndieStudio::MenuMain::downActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_MAIN_MAIN)
		this->downAction();
	else if (this->_renderStatus == MENU_MAIN_NEWGAME)
		this->_menuNew->downActionManager();
	else if (this->_renderStatus == MENU_MAIN_LOADGAME)
		this->downAction();
	else if (this->_renderStatus == MENU_MAIN_OPTIONS)
		this->_menuOptions->downActionManager();
	else if (this->_renderStatus == MENU_MAIN_EXIT)
		this->downAction();
}