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
#include <unistd.h>
#include "Image2d.hpp"
#include "IRender.hpp"
#include "MenuMain.hpp"

namespace IndieStudio {
	class Menu : public IRender, public irr::IEventReceiver {
		public:
			Menu(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *);
			~Menu();
			void render();
			void setRender(bool);
			void returnMainMenu();
			virtual bool OnEvent(const irr::SEvent &event);
			virtual bool hasRender(void) const noexcept;
			virtual void setEventReceiver(void) noexcept;
		private:
			MenuMain * _menuMain;
			IndieStudio::Image2d * _title;
			irr::IrrlichtDevice * _device;
			irr::scene::ISceneManager * _scene;
			irr::video::IVideoDriver * _driver;
			bool _render = true;
	};
};

#endif /* !MENU_HPP_ */