/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Character.hpp"
#include "IRender.hpp"
#include <irrlicht.h>
#include <vector>
#include "Map.hpp"
#include "IGraphical.hpp"
#include "IEntity.hpp"

namespace IndieStudio {
	class Game : public IRender {
		public:
			Game(IndieStudio::IGraphical &graphical);
			~Game();
			void createCubes() noexcept;
			void createCharacters() noexcept;
			void render() noexcept;
			// void createCubeColision(irr::scene::IMeshSceneNode *cube) noexcept;
			virtual int getRenderStatus(void) const noexcept;
			virtual void setRenderStatus(int) noexcept;
			virtual void checkEvent(void) noexcept;
			void moveCharacter() noexcept;
			// void set_Map_Collision();
			IndieStudio::Map *_map;
		private:
			int _renderStatus = MAIN_MENU;
			IndieStudio::IGraphical &_graphical;
			std::vector<IndieStudio::Character> _characterVec;
			std::vector<IndieStudio::IEntity *> _cubeVec;
			float _rot_x = 100;
			float _rot_y = 0;
			float _rot_z = 0;
			float _counter = 0;
			bool _keyPressed = false;
	};
};

#endif