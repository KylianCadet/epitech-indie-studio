/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Button
*/

#include "Button.hpp"

IndieStudio::Button::Button(irr::video::IVideoDriver * driver, std::string skin, std::string skinA, std::pair<int, int> position)
: _image2d(driver, skin, position), _active(false), _skin(skin), _skinA(skinA)
{

}

IndieStudio::Button::~Button()
{

}

void IndieStudio::Button::draw()
{
	_image2d.draw();
}

void IndieStudio::Button::setActive()
{
	_image2d.setTexture(_skinA);
}

void IndieStudio::Button::setDefault()
{
	_image2d.setTexture(_skin);
}