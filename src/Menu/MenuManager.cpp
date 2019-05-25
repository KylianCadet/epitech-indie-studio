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
	_menuOptions = new IndieStudio::MenuOptions(driver);
	_titleMenu = new IndieStudio::Image2d(driver, "assets/menu/title2.png", std::pair<int, int>(-1, 100));
	_frameMenu = new IndieStudio::Image2d(driver, "assets/menu/frame.png", std::pair<int, int>(-1, 320));
	_buttonReturnSound = new IndieStudio::Audio("sounds/menu/turnoff.ogg");
	_buttonSwitchSound = new IndieStudio::Audio("sounds/menu/tick.ogg");
	_volumeSwitchSound = new IndieStudio::Audio("sounds/menu/vol.ogg");
	_mainMusic = new IndieStudio::Audio("sounds/menu/Stillness2.ogg", true);
	_mainMusic->playSound();
	refreshAudio();
	_menuOptions->setVolumeBar(_volume);
	_device->setEventReceiver(this);
}

IndieStudio::MenuManager::~MenuManager()
{
}

void IndieStudio::MenuManager::refreshAudio(void) noexcept
{
	if (_volume < 0)
		_volume = 0;
	else if (_volume > 10)
		_volume = 10;
	int vol = _volume * 10;
	_buttonReturnSound->setVolume(vol);
	_buttonSwitchSound->setVolume(vol);
	_volumeSwitchSound->setVolume(vol);
	_mainMusic->setVolume(vol);
}

void IndieStudio::MenuManager::render(void) noexcept
{
	_titleMenu->drawImage();
	_frameMenu->drawImage();
	if (_menuRender == MAIN_MENU)
		_menuMain->drawMenu();
	else if (_menuRender == OPTIONS_MENU)
		_menuOptions->drawMenu();
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
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	{
		if (!event.KeyInput.PressedDown)
		{
			if (isKeyPress(event, irr::EKEY_CODE::KEY_RETURN))
				returnAction();
			if (isKeyPress(event, irr::EKEY_CODE::KEY_ESCAPE))
				escapeAction();
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
			if (isKeyPress(event, irr::EKEY_CODE::KEY_LEFT) && _menuRender == OPTIONS_MENU)
			{
				_volumeSwitchSound->playSound();
				_menuOptions->setLeftArrowActive();
				_volume--;
				refreshAudio();
				_menuOptions->setVolumeBar(_volume);
			}
			if (isKeyPress(event, irr::EKEY_CODE::KEY_RIGHT) && _menuRender == OPTIONS_MENU)
			{
				_volumeSwitchSound->playSound();
				_menuOptions->setRightArrowActive();
				_volume++;
				refreshAudio();
				_menuOptions->setVolumeBar(_volume);
			}
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
	if (_menuRender == MAIN_MENU)
		_buttonReturnSound->playSound();
	if (_menuMain->getCurrentButtonActive() == NEWGAME)
	{
		_render = false;
	}
	else if (_menuMain->getCurrentButtonActive() == LOADGAME)
	{
		std::cout << "Load game menu is under construction..." << std::endl;
	}
	else if (_menuMain->getCurrentButtonActive() == OPTIONS)
	{
		_menuRender = OPTIONS_MENU;
	}
	else if (_menuMain->getCurrentButtonActive() == EXIT)
	{
		usleep(100000);
		_device->closeDevice();
	}
}

void IndieStudio::MenuManager::escapeAction(void) noexcept
{
	if (_menuRender == MAIN_MENU)
	{
		_buttonReturnSound->playSound();
		_render = true;
	}
	else if (_menuRender == LOADGAME_MENU)
	{
	}
	else if (_menuRender == OPTIONS_MENU)
	{
		_buttonReturnSound->playSound();
		_menuRender = MAIN_MENU;
	}
}