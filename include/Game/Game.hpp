/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Character.hpp"
#include "IEntity.hpp"
#include "IGraphical.hpp"
#include "Map.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"
#include <vector>

static const int SIZE_MAP_X = 15;
static const int SIZE_MAP_Y = 15;
static const int DENSITY_BRICK = 40;
static const int DENSITY_WALL = 100;
static const int DENSITY_BONUS = 33;

namespace IndieStudio {
	class Game {
	public:
		Game(IndieStudio::IGraphical &graphical, Render &render);
		~Game();
		void createCubes() noexcept;
		void createCharacters() noexcept;
		void render() noexcept;
		void createCubeColision(IndieStudio::IEntity *cube) noexcept;
		virtual int getRenderStatus(void) const noexcept;
		virtual void setRenderStatus(int) noexcept;
		virtual void checkEvent(void) noexcept;
		void moveCharacter() noexcept;
		void mapRender() noexcept;
		void bonusRender() noexcept;
		void setMapCollision() noexcept;
		void checkDeleteBomb() noexcept;
		void setCameraPosition(int x, int y) noexcept;

	private:
		std::shared_ptr<IndieStudio::Audio> _bombSound;
		IndieStudio::Map _map;
		IndieStudio::Bonus _bonus;
		int _renderStatus = MAIN_MENU;
		IndieStudio::IGraphical &_graphical;
		std::vector<IndieStudio::Character> _characterVec;
		std::vector<std::shared_ptr<IndieStudio::Bomb>> _bombVec;
		IndieStudio::IEvent _event;
		float _rot_x = 100;
		float _rot_y = 0;
		float _rot_z = 0;
		float _counter = 0;
		bool _bonus_bool = false;
		Render &_render;
	};
}; // namespace IndieStudio

#endif