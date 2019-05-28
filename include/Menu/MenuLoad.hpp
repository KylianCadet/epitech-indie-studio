/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuLoad
*/

#ifndef MENULOAD_HPP_
#define MENULOAD_HPP_

#define MENU_LOAD_MAIN 0
#define MENU_LOAD_BACK 1

#include <irrlicht.h>
#include <iostream>

#include "Menu.hpp"
#include "MenuSounds.hpp"
#include "Audio.hpp"
#include "Button.hpp"
#include "Volume.hpp"

namespace IndieStudio
{
class MenuLoad : public Menu
{
public:
	MenuLoad(irr::video::IVideoDriver *, Volume *, MenuSounds *);
	~MenuLoad();

	virtual void drawMenu(void) noexcept;
	virtual void drawMenuManager(void) noexcept;
	virtual void createButtons(void) noexcept;
	virtual void drawButtons(void) noexcept;
	virtual void createImages(void) noexcept;
	virtual void drawImages(void) noexcept;

	virtual void checkActions(void) noexcept;
	virtual void returnAction(void) noexcept;
	virtual void returnActionManager(void) noexcept;
	virtual void escapeAction(void) noexcept;
	virtual void escapeActionManager(void) noexcept;
	virtual void leftAction(void) noexcept;
	virtual void leftActionManager(void) noexcept;
	virtual void rightAction(void) noexcept;
	virtual void rightActionManager(void) noexcept;
	virtual void upAction(void) noexcept;
	virtual void upActionManager(void) noexcept;
	virtual void downAction(void) noexcept;
	virtual void downActionManager(void) noexcept;

	virtual void refreshSkin(void) noexcept;

private:
	Image2d *_comingsoon;
	Image2d *_escapeInfo;
};
}; // namespace IndieStudio

#endif /* !MENULOAD_HPP_ */
