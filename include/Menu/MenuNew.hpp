/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuNew
*/

#ifndef MENUNEW_HPP_
#define MENUNEW_HPP_

#define MENU_NEW_GAME -1
#define MENU_NEW_MAIN 0
#define MENU_NEW_BACK 1

#define BTN_NEW_SOLO 0
#define BTN_NEW_1VS1 1
#define BTN_NEW_2VS2 2
#define BTN_NEW_BACK 3

#include <irrlicht.h>
#include <iostream>

#include "Menu.hpp"
#include "MenuSounds.hpp"
#include "Audio.hpp"
#include "Button.hpp"
#include "Volume.hpp"

namespace IndieStudio
{
class MenuNew : public Menu
{
public:
	MenuNew(irr::video::IVideoDriver *, Volume *, MenuSounds *);
	~MenuNew();

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
	Button *_solomode;
	Button *_1vs1mode;
	Button *_2vs2mode;
	Button *_back;
};
}; // namespace IndieStudio

#endif /* !MENUNEW_HPP_ */
