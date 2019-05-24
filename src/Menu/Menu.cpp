/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#include "Menu.hpp"

IndieStudio::Menu::Menu(irr::IrrlichtDevice * device, irr::scene::ISceneManager * scene, irr::video::IVideoDriver * driver)
: _device(device), _scene(scene), _driver(driver)
{
	_menuMain = new IndieStudio::MenuMain(driver);
	_title = new IndieStudio::Image2d(driver, "assets/menu/title.png", std::pair<int, int> (-1, 100));
	_device->setEventReceiver(this);
}

IndieStudio::Menu::~Menu(){}

void IndieStudio::Menu::render()
{
	_title->draw();
	_menuMain->drawAll();
}

bool isKeyPress(const irr::SEvent & event, irr::EKEY_CODE key)
{
	if (event.KeyInput.Key == key)
		return true;
	else
		return false;
}

bool IndieStudio::Menu::OnEvent(const irr::SEvent & event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown) {
		if (isKeyPress(event, irr::EKEY_CODE::KEY_RETURN))
			returnMainMenu();
		if (isKeyPress(event, irr::EKEY_CODE::KEY_UP))
			_menuMain->setIncA(-1);
		if (isKeyPress(event, irr::EKEY_CODE::KEY_DOWN))
			_menuMain->setIncA(1);
		return true;
	}
	return false;
}

bool IndieStudio::Menu::hasRender(void) const noexcept
{
	return (this->_render);
}

void IndieStudio::Menu::setEventReceiver(void) noexcept
{
	this->_device->setEventReceiver(this);
}

void IndieStudio::Menu::setRender(bool s)
{
	this->_render = s;
}

void IndieStudio::Menu::returnMainMenu()
{
	if (_menuMain->getBtnA() == 0)
		_render = false;
	else if (_menuMain->getBtnA() == 1)
		printf("Menu load game pas fini, ta qua le faire si t pas content lol\n");
	else if (_menuMain->getBtnA() == 2)
		printf("Menu options game pas fini, ta qua le faire si t pas content lol\n");
	else if (_menuMain->getBtnA() == 3)
		_device->closeDevice();
}