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
#include "IRender.hpp"
#include "Map.hpp"
#include <vector>

namespace IndieStudio {
	class Game : public IRender {
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
		void setMapCollision() noexcept;
		std::unique_ptr<IndieStudio::Map> _map;

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
		Render &_render;
	};
}; // namespace IndieStudio

#endif