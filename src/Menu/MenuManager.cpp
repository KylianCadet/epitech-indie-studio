/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#include "MenuManager.hpp"

IndieStudio::MenuManager::MenuManager(irr::IrrlichtDevice *device, irr::scene::ISceneManager *scene, irr::video::IVideoDriver *driver, IndieStudio::Volume *volume)
	: _device(device), _scene(scene), _driver(driver), _volume(volume)
{
	this->_menuRender = MENU_MAIN;
	this->_device->setEventReceiver(this);
	this->_sounds = new IndieStudio::MenuSounds(this->_volume);
	this->_menuMain = new IndieStudio::MenuMain(this->_driver, this->_volume, this->_sounds);
	this->_sounds->_mainMusic->playSound();
	this->_volume->refreshVolume();
}

IndieStudio::MenuManager::~MenuManager()
{
}

void IndieStudio::MenuManager::checkActions(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
	{
		if (this->_menuMain->getCurrentMenuActive() == MENU_MAIN_NEWGAME)
		{
			this->_render = false;
		}
		else if (this->_menuMain->getCurrentMenuActive() == MENU_MAIN_EXIT)
		{
			usleep(100000);
			this->_device->closeDevice();
		}
	}
}

void IndieStudio::MenuManager::render(void) noexcept
{
	this->checkActions();
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->drawMenuManager();
	else if (this->_menuRender == MENU_PAUSE)
		this->_menuMain->drawMenuManager();
}

bool isKeyPress(const irr::SEvent &event, irr::EKEY_CODE key) noexcept
{
	if (event.KeyInput.Key == key)
		return true;
	else
		return false;
}

void IndieStudio::MenuManager::returnActionManager(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->returnActionManager();
}

void IndieStudio::MenuManager::escapeActionManager(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->escapeActionManager();
}

void IndieStudio::MenuManager::leftActionManager(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->leftActionManager();
}

void IndieStudio::MenuManager::rightActionManager(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->rightActionManager();
}

void IndieStudio::MenuManager::upActionManager(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->upActionManager();
}

void IndieStudio::MenuManager::downActionManager(void) noexcept
{
	if (this->_menuRender == MENU_MAIN)
		this->_menuMain->downActionManager();
}

bool IndieStudio::MenuManager::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
	{
		if (isKeyPress(event, irr::EKEY_CODE::KEY_RETURN))
			this->returnActionManager();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_ESCAPE))
			this->escapeActionManager();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_LEFT))
			this->leftActionManager();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_RIGHT))
			this->rightActionManager();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_UP))
			this->upActionManager();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_DOWN))
			this->downActionManager();
		return true;
	}
	return false;
}

bool IndieStudio::MenuManager::hasRender(void) const noexcept
{
	return (this->_render);
}

void IndieStudio::MenuManager::setEventReceiver(void) noexcept
{
	this->_device->setEventReceiver(this);
}

void IndieStudio::MenuManager::setRenderStatus(bool newRenderStatus) noexcept
{
	this->_render = newRenderStatus;
}