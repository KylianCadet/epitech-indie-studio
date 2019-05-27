/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuOptions
*/

#include "MenuOptions.hpp"

IndieStudio::MenuOptions::MenuOptions(irr::video::IVideoDriver *driver, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(driver, volume, sounds)
{
	this->_renderStatus = MENU_OPTIONS_MAIN;
	this->_buttonStatus = BTN_OPTIONS_AUDIO;
	this->createButtons();
	this->_menuAudio = new IndieStudio::MenuAudio(this->_driver, this->_volume, this->_sounds);
}

IndieStudio::MenuOptions::~MenuOptions()
{
}

void IndieStudio::MenuOptions::createButtons(void) noexcept
{
	this->_audio = new Button(this->_driver, "assets/menu/buttons/audio.png", "assets/menu/buttons/audioA.png", std::pair<int, int>(-1, 400));
	this->_video = new Button(this->_driver, "assets/menu/buttons/video.png", "assets/menu/buttons/videoA.png", std::pair<int, int>(-1, 400 + 110));
	this->_controls = new Button(this->_driver, "assets/menu/buttons/controls.png", "assets/menu/buttons/controlsA.png", std::pair<int, int>(-1, 400 + 220));
	this->_back = new Button(this->_driver, "assets/menu/buttons/back.png", "assets/menu/buttons/backA.png", std::pair<int, int>(-1, 400 + 330));
}

void IndieStudio::MenuOptions::drawButtons(void) noexcept
{
	this->_audio->drawButton();
	this->_video->drawButton();
	this->_controls->drawButton();
	this->_back->drawButton();
}

void IndieStudio::MenuOptions::checkActions(void) noexcept
{
	if (this->_menuAudio->getCurrentMenuActive() == MENU_AUDIO_BACK)
	{
		this->_renderStatus = MENU_OPTIONS_MAIN;
		this->_menuAudio->setMenuActive(MENU_OPTIONS_MAIN);
		// this->_menuOptions->setButtonActive(BTN_OPTIONS_AUDIO);
	}
}

void IndieStudio::MenuOptions::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
}

void IndieStudio::MenuOptions::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->drawMenuManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->drawMenu();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->drawMenu();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->drawMenu();
}

void IndieStudio::MenuOptions::refreshSkin(void) noexcept
{
	if (this->_buttonStatus == BTN_OPTIONS_AUDIO)
	{
		this->_audio->setActiveSkin();
		this->_video->setDefaultSkin();
		this->_controls->setDefaultSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_OPTIONS_VIDEO)
	{
		this->_audio->setDefaultSkin();
		this->_video->setActiveSkin();
		this->_controls->setDefaultSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_OPTIONS_CONTROLS)
	{
		this->_audio->setDefaultSkin();
		this->_video->setDefaultSkin();
		this->_controls->setActiveSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_OPTIONS_BACK)
	{
		this->_audio->setDefaultSkin();
		this->_video->setDefaultSkin();
		this->_controls->setDefaultSkin();
		this->_back->setActiveSkin();
	}
}

void IndieStudio::MenuOptions::returnAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_buttonStatus == BTN_OPTIONS_AUDIO)
		this->_renderStatus = MENU_OPTIONS_AUDIO;
	else if (this->_buttonStatus == BTN_OPTIONS_VIDEO)
		this->_renderStatus = MENU_OPTIONS_VIDEO;
	else if (this->_buttonStatus == BTN_OPTIONS_CONTROLS)
		this->_renderStatus = MENU_OPTIONS_CONTROLS;
	else if (this->_buttonStatus == BTN_OPTIONS_BACK)
		this->_renderStatus = MENU_OPTIONS_BACK;
}

void IndieStudio::MenuOptions::escapeAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	this->_renderStatus = MENU_OPTIONS_BACK;
}

void IndieStudio::MenuOptions::leftAction(void) noexcept
{
}

void IndieStudio::MenuOptions::rightAction(void) noexcept
{
}

void IndieStudio::MenuOptions::upAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuOptions::downAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuOptions::returnActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->returnAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->returnActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->returnAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->returnAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->returnAction();
}

void IndieStudio::MenuOptions::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->escapeActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->escapeAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->escapeAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->escapeAction();
}

void IndieStudio::MenuOptions::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->leftAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->leftActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->leftAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->leftAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->leftAction();
}

void IndieStudio::MenuOptions::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->rightAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->rightActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->rightAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->rightAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->rightAction();
}

void IndieStudio::MenuOptions::upActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->upAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->upActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->upAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->upAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->upAction();
}

void IndieStudio::MenuOptions::downActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->downAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->downActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->downAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->downAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->downAction();
}