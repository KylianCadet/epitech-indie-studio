/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#include "MenuManager.hpp"

IndieStudio::MenuManager::MenuManager(irr::IrrlichtDevice *device, irr::scene::ISceneManager *scene, irr::video::IVideoDriver *driver)
	: _device(device), _scene(scene), _driver(driver)
{
	_menuMain = new IndieStudio::MenuMain(driver);
	_titleMenu = new IndieStudio::Image2d(driver, "assets/menu/title2.png", std::pair<int, int>(-1, 100));
	_frameMenu = new IndieStudio::Image2d(driver, "assets/menu/frame.png", std::pair<int, int>(-1, 320));
	_buttonReturnSound = new IndieStudio::Audio("sounds/menu/turnoff.ogg");
	_buttonSwitchSound = new IndieStudio::Audio("sounds/menu/tick.ogg");
	_mainMusic = new IndieStudio::Audio("sounds/menu/Stillness2.ogg", true);
	_mainMusic->playSound();
	_device->setEventReceiver(this);
}

IndieStudio::MenuManager::~MenuManager()
{
}

void IndieStudio::MenuManager::render(void) noexcept
{
	_titleMenu->drawImage();
	_frameMenu->drawImage();
	if (_menuRender == MAIN_MENU)
		_menuMain->drawMenu();
	// else if (_menuRender == OPTIONS_MENU)
	// 	_menuOptions->drawAll();
}

bool isKeyPress(const irr::SEvent &event, irr::EKEY_CODE key) noexcept
{
	if (event.KeyInput.Key == key)
		return true;
	else
		return false;
}

bool IndieStudio::MenuManager::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
	{
		if (isKeyPress(event, irr::EKEY_CODE::KEY_RETURN))
			returnAction();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_UP) && _menuRender == MAIN_MENU)
		{
			_buttonSwitchSound->playSound();
			_menuMain->setButtonSwitch(-1);
		}
		if (isKeyPress(event, irr::EKEY_CODE::KEY_DOWN) && _menuRender == MAIN_MENU)
		{
			_buttonSwitchSound->playSound();
			_menuMain->setButtonSwitch(1);
		}
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

void IndieStudio::MenuManager::returnAction(void) noexcept
{
	_buttonReturnSound->playSound();
	if (_menuMain->getButtonStatus() == 0)
		_render = false;
	else if (_menuMain->getButtonStatus() == 1)
		std::cout << "Load game menu is under construction..." << std::endl;
	else if (_menuMain->getButtonStatus() == 2)
		_menuRender = OPTIONS_MENU;
	else if (_menuMain->getButtonStatus() == 3)
		_device->closeDevice();
}