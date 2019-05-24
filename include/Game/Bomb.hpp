/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <irrlicht.h>

#define EXPLOSION_UP 0.05f, 0.0f, 0.0f
#define EXPLOSION_DOWN -0.05f, 0.0f, 0.0f
#define EXPLOSION_RIGHT 0.0f, 0.0f, -0.05f
#define EXPLOSION_LEFT -0.05f, 0.0f, 0.05f

namespace IndieStudio {
	class Bomb {
		public:
			Bomb(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector);
			~Bomb();
			void createParticule(irr::core::vector3df vector) noexcept;
			void startCountdown(void);
			void explosion(irr::core::vector3df position);
			irr::core::vector3df explosionDir(int i);
		private:
			irr::scene::IAnimatedMeshSceneNode *_bomb;
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			irr::scene::IParticleSystemSceneNode *_particle;
	};
};

#endif