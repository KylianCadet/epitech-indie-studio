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
#include "NewGame.hpp"
#include "LoadGame.hpp"
#include "Options.hpp"
#include "Exit.hpp"
#include "Audio.hpp"

namespace IndieStudio {
	class MenuMain {
		public:
			MenuMain(irr::video::IVideoDriver *);
			~MenuMain();
			void setSkin();
			void setIncA(int);
			void setBtnA(int);
			int getBtnA() const noexcept;
			void drawAll();
		private:
			IndieStudio::Audio *_tick;
			IndieStudio::Audio *_music;
			IndieStudio::Image2d * _frame;
			NewGame * _newGame;
			LoadGame * _loadGame;
			Options * _options;
			Exit * _exit;
			int _btnA;
			irr::video::IVideoDriver * _driver;
	};
};

#endif /* !MENUMAIN_HPP_ */