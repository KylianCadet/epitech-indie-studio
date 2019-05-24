/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Image2d
*/

#include "Image2d.hpp"

IndieStudio::Image2d::Image2d(irr::video::IVideoDriver * driver, std::string str, std::pair<int, int> position)
: _driver(driver)
{
	setTexture(str);
	_position = irr::core::position2d<irr::s32>(position.first, position.second);
	setRectangle();
	if (position.first == -1)
		setPositionToMid();
}

IndieStudio::Image2d::~Image2d(){}

void IndieStudio::Image2d::setRectangle(void)
{
	irr::core::dimension2d<irr::u32> taille = _image->getSize();
	irr::core::position2d<irr::s32> position0;
	position0.X = 0;
	position0.Y = 0;
	irr::core::position2d<irr::s32> position1;
	position1.X = taille.Width;
	position1.Y = taille.Height;
	irr::core::rect<irr::s32> rectangle;
	rectangle.UpperLeftCorner = position0;
	rectangle.LowerRightCorner = position1;
	_rectangle = rectangle;
}

void IndieStudio::Image2d::setPositionToMid(void)
{
	irr::core::dimension2d<irr::u32> screen = _driver->getScreenSize();
	_position.X = screen.Width / 2 - _rectangle.LowerRightCorner.X / 2;;
}

void IndieStudio::Image2d::draw()
{
	_driver->draw2DImage(_image, _position, _rectangle, 0, irr::video::SColor (255, 255, 255, 255), true);
}

void IndieStudio::Image2d::setTexture(std::string skin)
{
	_image = _driver->getTexture(skin.c_str());
}