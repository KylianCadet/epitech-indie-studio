/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <irrlicht.h>
#include <iostream>
#include "Image2d.hpp"

namespace IndieStudio {
	class Menu : public irr::IEventReceiver {
		public:
			Menu(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *);
			~Menu();
			virtual bool OnEvent(const irr::SEvent &event);
			void render();
		private:
			IndieStudio::Image2d * _bg;
			IndieStudio::Image2d * _title;
			IndieStudio::Image2d * _play;
			IndieStudio::Image2d * _settings;
			IndieStudio::Image2d * _exit;
			irr::IrrlichtDevice * _device;
			irr::scene::ISceneManager * _scene;
			irr::video::IVideoDriver * _driver;
			irr::gui::IGUIEnvironment * _gui;
			bool _keyPressed = false;
			bool _keyUp = false;
	};
};

#endif /* !MENU_HPP_ */