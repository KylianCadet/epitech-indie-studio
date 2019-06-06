/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#include "MenuManager.hpp"

IndieStudio::MenuManager::MenuManager(Render &renderStatus, IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::Config *config)
	: _renderStatus(renderStatus), _graphical(graphical), _volume(volume), _config(config)
{
	this->_sounds = new IndieStudio::MenuSounds(this->_volume);
	this->_menuMain = new IndieStudio::MenuMain(this->_graphical, this->_volume, this->_sounds, this->_config);
	this->_menuPause = new IndieStudio::MenuPause(this->_graphical, this->_volume, this->_sounds, this->_config);
	this->_volume->refreshVolume();
}

IndieStudio::MenuManager::~MenuManager()
{
}

void IndieStudio::MenuManager::checkActions(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU) {
		if (_menuMain->getCurrentMenuActive() == MENU_MAIN_GAME_SOLO)
			_renderStatus = GAME_SOLO;                                               //SOLO MODE
		else if (_menuMain->getCurrentMenuActive() == MENU_MAIN_GAME_1V1)
			_renderStatus = GAME_1V1;                                     //1V1 MODE
		else if (_menuMain->getCurrentMenuActive() == MENU_MAIN_GAME_COOP)
			_renderStatus = GAME_COOP;                                    //COOP MODE
//		else if (this->_menuMain->getCurrentMenuActive() == MENU_MAIN_GAME)
//			this->_renderStatus = GAME_SOLO;                                         ///TO CHANGE
		else if (this->_menuMain->getCurrentMenuActive() == MENU_MAIN_EXIT) {
			usleep(100000);
			this->_graphical.drop();
			exit(0);
		}
	}
	else if (this->_renderStatus == PAUSE_MENU) {
		if (this->_menuPause->getCurrentMenuActive() == MENU_PAUSE_BACK) {
			this->_renderStatus = GAME_SOLO;	///CHANGES TO DO
			this->_menuPause->setMenuActive(MENU_PAUSE_MAIN);
		} else if (this->_menuPause->getCurrentMenuActive() == MENU_PAUSE_QUIT) {
			this->_renderStatus = MAIN_MENU;
			this->_menuPause->setButtonActive(BTN_PAUSE_BACK);
			this->_menuPause->setMenuActive(MENU_PAUSE_MAIN);
			this->_menuMain->setMenuActive(MENU_MAIN_MAIN);
		}
	}
}

void IndieStudio::MenuManager::render(void) noexcept
{
	this->checkEvent();
	this->checkActions();
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->drawMenuManager();
	else if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->drawMenuManager();
}

void IndieStudio::MenuManager::returnActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->returnActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->returnActionManager();
}

void IndieStudio::MenuManager::escapeActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->escapeActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->escapeActionManager();
}

void IndieStudio::MenuManager::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->leftActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->leftActionManager();
}

void IndieStudio::MenuManager::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->rightActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->rightActionManager();
}

void IndieStudio::MenuManager::upActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->upActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->upActionManager();
}

void IndieStudio::MenuManager::downActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->downActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->downActionManager();
}

void IndieStudio::MenuManager::checkEvent(void) noexcept
{
	bool returnKey = this->_event._key[IndieStudio::Key::RETURN];
	bool escKey = this->_event._key[IndieStudio::Key::ESC];
	bool leftKey = this->_event._key[IndieStudio::Key::KEY_LEFT];
	bool rightKey = this->_event._key[IndieStudio::Key::KEY_RIGHT];
	bool upKey = this->_event._key[IndieStudio::Key::KEY_UP];
	bool downKey = this->_event._key[IndieStudio::Key::KEY_DOWN];
	this->_event = this->_graphical.getEvent();

	if (this->_event._key[IndieStudio::Key::RETURN] != returnKey && returnKey == false)
		this->returnActionManager();
	if (this->_event._key[IndieStudio::Key::ESC] != escKey && escKey == false)
		this->escapeActionManager();
	if (this->_event._key[IndieStudio::Key::KEY_LEFT] != leftKey && leftKey == false)
		this->leftActionManager();
	if (this->_event._key[IndieStudio::Key::KEY_RIGHT] != rightKey && rightKey == false)
		this->rightActionManager();
	if (this->_event._key[IndieStudio::Key::KEY_UP] != upKey && upKey == false)
		this->upActionManager();
	if (this->_event._key[IndieStudio::Key::KEY_DOWN] != downKey && downKey == false)
		this->downActionManager();
}