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

namespace IndieStudio
{
	class MenuMain
	{
	public:
		MenuMain(irr::video::IVideoDriver *);
		~MenuMain();

		void drawMenu(void) noexcept;
		void refreshSkin(void) noexcept;
		void setButtonSwitch(int) noexcept;
		void setButtonActive(int) noexcept;
		int getButtonStatus(void) const noexcept;

	private:
		int _buttonStatus = NEWGAME;

		Button *_newGame;
		Button *_loadGame;
		Button *_options;
		Button *_exit;

		irr::video::IVideoDriver *_driver;
	};
}; // namespace IndieStudio

#endif /* !MENUMAIN_HPP_ */