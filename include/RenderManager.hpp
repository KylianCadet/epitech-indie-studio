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
#include "IGraphical.hpp"

namespace IndieStudio {
	class RenderManager {
		public:
			RenderManager(IndieStudio::IRender &menu, IndieStudio::IRender &game);
			~RenderManager();
			void render();
			irr::video::SColor getColor() const noexcept;
		private:
			IndieStudio::IRender &_menu;
			IndieStudio::IRender &_game;
			irr::video::SColor _color;
	};
};

#endif