/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <irrlicht.h>
#include "Audio.hpp"

namespace IndieStudio {
	class Bomb {
		public:
			Bomb(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector, int bombSize);
			~Bomb();
			void createParticule(irr::core::vector3df vector) noexcept;
			void startCountdown(void);
			void playExplosionSound(void) noexcept;
			bool getAlive(void) const noexcept;
			void exploseBomb(void) noexcept;

		private:
			irr::scene::IAnimatedMeshSceneNode *_bomb;
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
			irr::scene::IParticleSystemSceneNode *_particle;
			IndieStudio::Audio _sound;
			bool _alive = true;
			int _bombSize;

	};
};

#endif