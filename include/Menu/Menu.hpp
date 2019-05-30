/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <irrlicht.h>
#include <iostream>

#include "IMenu.hpp"
#include "IGraphical.hpp"
#include "Button.hpp"
#include "Volume.hpp"
#include "MenuSounds.hpp"

namespace IndieStudio
{
class Menu : public IMenu
{
public:
	Menu(IGraphical &, Volume *, MenuSounds *);

	virtual void setButtonSwitch(int, int) noexcept;
	virtual void setMenuActive(int) noexcept;
	virtual int getCurrentMenuActive(void) const noexcept;
	virtual void setButtonActive(int) noexcept;
	virtual int getCurrentButtonActive(void) const noexcept;

protected:
	int _renderStatus;
	int _buttonStatus;

	Volume *_volume;
	MenuSounds *_sounds;
	IGraphical &_graphical;
};
};	 // namespace IndieStudio
#endif /* !IMENU_HPP_ */
