/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#ifndef MENUMAIN_HPP_
#define MENUMAIN_HPP_

#define MENU_MAIN_MAIN 0
#define MENU_MAIN_NEWGAME 1
#define MENU_MAIN_LOADGAME 2
#define MENU_MAIN_OPTIONS 3
#define MENU_MAIN_EXIT 4

#define BTN_MAIN_NEWGAME 0
#define BTN_MAIN_LOADGAME 1
#define BTN_MAIN_OPTIONS 2
#define BTN_MAIN_EXIT 3

#include <irrlicht.h>
#include <iostream>

#include "Menu.hpp"
#include "MenuOptions.hpp"
#include "MenuSounds.hpp"
#include "Audio.hpp"
#include "Button.hpp"
#include "Volume.hpp"

namespace IndieStudio
{
class MenuMain : public Menu
{
public:
	MenuMain(irr::video::IVideoDriver *, Volume *, MenuSounds *);
	~MenuMain();

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
	MenuOptions *_menuOptions;

	Button *_newGame;
	Button *_loadGame;
	Button *_options;
	Button *_exit;

	Image2d *_frameMenu;
	Image2d *_titleMenu;

};
}; // namespace IndieStudio

#endif /* !MENUMAIN_HPP_ */