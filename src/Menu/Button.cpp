/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Button
*/

#include "Button.hpp"

IndieStudio::Button::Button(irr::video::IVideoDriver * driver, std::string skinDefault, std::string skinActive, std::pair<int, int> position)
: _image2d(driver, skinDefault, position), _active(false), _skinDefault(skinDefault), _skinActive(skinActive)
{
	
}

IndieStudio::Button::~Button()
{

}

void IndieStudio::Button::drawButton(void) noexcept
{
	_image2d.drawImage();
}

void IndieStudio::Button::setActiveSkin(void) noexcept
{
	_image2d.setTexture(_skinActive);
}

void IndieStudio::Button::setDefaultSkin(void) noexcept
{
	_image2d.setTexture(_skinDefault);
}