/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#ifndef MENUMAIN_HPP_
#define MENUMAIN_HPP_

#include <irrlicht.h>
#include <iostream>

namespace IndieStudio {
	class MenuMain {
		public:
			MenuMain(irr::video::IVideoDriver *);
			~MenuMain();
		private:
			irr::video::IVideoDriver * _driver;
	};
};

#endif /* !MENUMAIN_HPP_ */