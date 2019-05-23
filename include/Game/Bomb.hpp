/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <irrlicht.h>

namespace IndieStudio {
	class Bomb {
		public:
			Bomb(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector);
			~Bomb();
			void createParticule(irr::core::vector3df vector) noexcept;
			void startCountdown(void);
		private:
			irr::scene::IAnimatedMeshSceneNode *_bomb;
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			irr::scene::IParticleSystemSceneNode *_particle;
	};
};

#endif