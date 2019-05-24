/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Image2d
*/

#ifndef IMAGE2D_HPP_
#define IMAGE2D_HPP_

#include <irrlicht.h>
#include <iostream>

namespace IndieStudio {
	class Image2d {
		public:
			Image2d(irr::video::IVideoDriver *, std::string, std::pair<int, int>);
			~Image2d();
			void setRectangle(void);
			void setPositionToMid(void);
			void setTexture(std::string);
			void draw(void);
		public:
			irr::video::ITexture * _image;
			irr::core::position2d<irr::s32> _position;
			irr::core::rect<irr::s32> _rectangle;
			irr::video::IVideoDriver * _driver;
	};
};

#endif /* !IMAGE2D_HPP_ */
