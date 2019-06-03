/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Audio.hpp"
#include "IEntity.hpp"
#include "IGraphical.hpp"
#include "Map.hpp"

namespace IndieStudio {
	class Bomb {
	public:
		Bomb(IndieStudio::IGraphical &graphical, IndieStudio::Pos vector, int bombSize, IndieStudio::Map &map, std::vector<std::shared_ptr<IndieStudio::Bomb>> bombVec);
		~Bomb();
		void createParticule(IndieStudio::Pos vector) noexcept;
		void startCountdown(void);
		void explosion(IndieStudio::Pos position);
		std::vector<IndieStudio::Pos> explosionDir(std::vector<IndieStudio::Pos> vec);
		void playExplosionSound(void) noexcept;
		bool getAlive(void) const noexcept;
		void destroyExplosionParticle(void);
		IndieStudio::Pos getPosition(void) const noexcept;

	private:
		void hit_Cube(IndieStudio::Pos position);
		IndieStudio::IGraphical &_graphical;
		IndieStudio::Map &_map;
		IndieStudio::IEntity *_bomb;
		IndieStudio::IEntity *_particle;
		IndieStudio::Audio _sound;
		std::vector<IndieStudio::IEntity *> _explosionParticule;
		std::vector<std::shared_ptr<IndieStudio::Bomb>> _bombVec;
		bool _alive = true;
		int _bombSize;
	};
}; // namespace IndieStudio

#endif