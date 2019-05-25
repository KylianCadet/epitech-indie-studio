/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#ifndef MENUMAIN_HPP_
#define MENUMAIN_HPP_

#define NEWGAME 0
#define LOADGAME 1
#define OPTIONS 2
#define EXIT 3

#include <irrlicht.h>
#include <iostream>
#include "Audio.hpp"
#include "Button.hpp"
#include "IMenu.hpp"

namespace IndieStudio
{
	class MenuMain : public IMenu
	{
	public:
		MenuMain(irr::video::IVideoDriver *);
		~MenuMain();

		virtual void drawMenu(void) noexcept;
		virtual void drawButtons(void) noexcept;
		virtual void refreshSkin(void) noexcept;
		virtual void setButtonSwitch(int) noexcept;
		virtual void setButtonActive(int) noexcept;
		virtual int getCurrentButtonActive(void) const noexcept;

	private:
		int _buttonStatus = NEWGAME;

		IndieStudio::Button *_newGame;
		IndieStudio::Button *_loadGame;
		IndieStudio::Button *_options;
		IndieStudio::Button *_exit;

		irr::video::IVideoDriver *_driver;
	};
}; // namespace IndieStudio

#endif /* !MENUMAIN_HPP_ */