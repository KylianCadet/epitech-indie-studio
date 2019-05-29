/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Audio.hpp"
#include "IGraphical.hpp"
#include "IEntity.hpp"

namespace IndieStudio {
	class Bomb {
		public:
			Bomb(IndieStudio::IGraphical &graphical, IndieStudio::Pos vector, int bombSize);
			~Bomb();
			void createParticule(IndieStudio::Pos vector) noexcept;
			void startCountdown(void);
			void explosion(IndieStudio::Pos position);
			std::vector<IndieStudio::Pos> explosionDir(std::vector<IndieStudio::Pos> vec);
			void playExplosionSound(void) noexcept;
			bool getAlive(void) const noexcept;

		private:
			IndieStudio::IGraphical &_graphical;
			IndieStudio::IEntity *_bomb;
			IndieStudio::IEntity *_particle;
			IndieStudio::Audio _sound;
			bool _alive = true;
			int _bombSize;
	};
};

#endif