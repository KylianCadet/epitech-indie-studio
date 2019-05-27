/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#define NOTHING -1

#include "Volume.hpp"
#include "IMenu.hpp"
#include "MenuSounds.hpp"
#include <irrlicht.h>

class Menu : public IMenu
{
public:
	Menu(irr::video::IVideoDriver *, IndieStudio::Volume *, IndieStudio::MenuSounds *);

	virtual void setButtonSwitch(int, int) noexcept;
	virtual void setMenuActive(int) noexcept;
	virtual int getCurrentMenuActive(void) const noexcept;
	virtual void setButtonActive(int) noexcept;
	virtual int getCurrentButtonActive(void) const noexcept;

protected:
	int _renderStatus;
	int _buttonStatus;

	IndieStudio::Volume *_volume;
	IndieStudio::MenuSounds *_sounds;
	irr::video::IVideoDriver *_driver;
};

#endif /* !IMENU_HPP_ */
