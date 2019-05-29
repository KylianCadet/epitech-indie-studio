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

namespace IndieStudio
{
class Button
{
public:
	Button(irr::video::IVideoDriver *, std::string, std::string, std::pair<int, int>);
	~Button();

	void drawButton(void) noexcept;
	void setDefaultSkin(void) noexcept;
	void setActiveSkin(void) noexcept;

private:
	bool _active;

	Image2d _image2d;

	std::string _skinDefault;
	std::string _skinActive;
};
}; // namespace IndieStudio

#endif /* !BUTTON_HPP_ */
