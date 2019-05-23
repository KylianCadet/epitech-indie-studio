/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#ifndef RENDERMANAGER_HPP_
#define RENDERMANAGER_HPP_

#include "IRender.hpp"
#include <irrlicht.h>

namespace IndieStudio {
	class RenderManager {
		public:
			RenderManager(IndieStudio::IRender &menu, IndieStudio::IRender &game, irr::video::IVideoDriver *driver);
			~RenderManager();
			void render();
		private:
			IndieStudio::IRender &_menu;
			IndieStudio::IRender &_game;
			irr::video::IVideoDriver *_driver;
			bool _counter = false;
	};
};

#endif