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
	int space = 400;
	_title = new IndieStudio::Image2d(driver, "assets/menu/title.png", -42, 100);
	_bomberman = new IndieStudio::Image2d(driver, "assets/menu/bomberman.png", 350, 0);
	_newgame = new IndieStudio::Image2d(driver, "assets/menu/buttons/newgame.png", -42, space);
	_loadgame = new IndieStudio::Image2d(driver, "assets/menu/buttons/loadgame.png", -42, space + 110);
	_options = new IndieStudio::Image2d(driver, "assets/menu/buttons/options.png", -42, space + 220);
	_exit = new IndieStudio::Image2d(driver, "assets/menu/buttons/exit.png", -42, space + 330);
	_device->setEventReceiver(this);
}

IndieStudio::Menu::~Menu(){}

void IndieStudio::Menu::render()
{
	_title->draw();
	//_bomberman->draw();
	_newgame->draw();
	_loadgame->draw();
	_options->draw();
	_exit->draw();
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
			this->_render = false;
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
