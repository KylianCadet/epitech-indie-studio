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
#include "IRender.hpp"

namespace IndieStudio {
	class Menu : public IRender, public irr::IEventReceiver {
		public:
			Menu(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *);
			~Menu();
			virtual bool OnEvent(const irr::SEvent &event);
			void render();
			virtual bool hasRender(void) const noexcept;
			virtual void setEventReceiver(void) noexcept;
		private:
			IndieStudio::Image2d * _title;
			IndieStudio::Image2d * _play;
			IndieStudio::Image2d * _settings;
			IndieStudio::Image2d * _exit;
			irr::IrrlichtDevice * _device;
			irr::scene::ISceneManager * _scene;
			irr::video::IVideoDriver * _driver;
			irr::gui::IGUIEnvironment * _gui;
			bool _render = true;
	};
};

#endif /* !MENU_HPP_ */