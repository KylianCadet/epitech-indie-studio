/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Character.hpp"
#include "CharacterEventListener.hpp"
#include <irrlicht.h>
#include <vector>

namespace IndieStudio {
	class Game {
		public:
			Game(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver);
			~Game();
			void createCubes() noexcept;
			void createCharacters() noexcept;
			void render() noexcept;
		private:
			irr::IrrlichtDevice *_device;
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			std::vector<IndieStudio::Character> _characterVec;
			std::vector<irr::scene::IMeshSceneNode *> _cubeVec;
			IndieStudio::CharacterEventListener *_CharacterEventListener;
			float _rot_x = 100;
			float _rot_y = 0;
			float _rot_z = 0;
			float _counter = 0;
	};
};

#endif