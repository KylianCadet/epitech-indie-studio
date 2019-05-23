/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#include "Menu.hpp"

IndieStudio::Menu::Menu(irr::IrrlichtDevice * device, irr::scene::ISceneManager * scene, irr::video::IVideoDriver * driver)
{
	_device = device;
	_scene = scene;
	_driver = driver;
	int space = 400;
	_title = new IndieStudio::Image2d(driver, "assets/menu/title.png", -42, 50);
	_play = new IndieStudio::Image2d(driver, "assets/menu/play1.png", -42, space);
	_settings = new IndieStudio::Image2d(driver, "assets/menu/sett1.png", -42, space + 110);
	_exit = new IndieStudio::Image2d(driver, "assets/menu/exit1.png", -42, space + 220);
	device->getCursorControl()->setVisible(true);
	device->setEventReceiver(this);
}

IndieStudio::Menu::~Menu(){}

void IndieStudio::Menu::render()
{
	_title->draw();
	_play->draw();
	_settings->draw();
	_exit->draw();
}

bool IndieStudio::Menu::OnEvent(const irr::SEvent &event)
{
	bool ret = false;

	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.Key == irr::EKEY_CODE::KEY_UP) {
			this->_render = false;
			ret = true;
		}
		return (ret);
	}
	return (false);
}

bool IndieStudio::Menu::hasRender(void) const noexcept
{
	return (this->_render);
}

void IndieStudio::Menu::setEventReceiver(void) noexcept
{
	this->_device->setEventReceiver(this);
}
