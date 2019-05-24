/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <irrlicht.h>
#include <iostream>
#include "Image2d.hpp"

namespace IndieStudio {
	class Button {
		public:
			Button(irr::video::IVideoDriver *, std::string, std::string, std::pair<int, int>);
			~Button();
			void setDefault();
			void setActive();
			void draw();
		protected:
			std::string _skin;
			std::string _skinA;
			Image2d _image2d;
			bool _active;
	};
};

#endif /* !BUTTON_HPP_ */
