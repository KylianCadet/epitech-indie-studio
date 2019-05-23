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
	_bg = new IndieStudio::Image2d(driver, "assets/menu/moon.png", 500, -250);
	_title = new IndieStudio::Image2d(driver, "assets/menu/title.png", -42, 50);
	_play = new IndieStudio::Image2d(driver, "assets/menu/play1.png", -42, space);
	_settings = new IndieStudio::Image2d(driver, "assets/menu/sett1.png", -42, space + 110);
	_exit = new IndieStudio::Image2d(driver, "assets/menu/exit1.png", -42, space + 220);
	device->getCursorControl()->setVisible(true);
}

IndieStudio::Menu::~Menu(){}

void IndieStudio::Menu::render()
{
	_bg->draw();
	_title->draw();
	_play->draw();
	_settings->draw();
	_exit->draw();
}

bool IndieStudio::Menu::OnEvent(const irr::SEvent &event)
{
	bool ret = false;

	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (!this->_keyPressed) {
			if (event.KeyInput.Key == irr::EKEY_CODE::KEY_UP) {
				this->_keyPressed = true;
				this->_keyUp = true;
				std::cout << "here" << std::endl;
				ret = true;
			} else {
				this->_keyUp = false;
				this->_keyPressed = false;
			}
		}
		return (ret);
	}
	return (false);
}