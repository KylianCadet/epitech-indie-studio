/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include <iostream>
#include <memory>
#include "IEntity.hpp"

namespace IndieStudio {
	class IGraphical {
		public:
			virtual ~IGraphical() = default;
			virtual IndieStudio::IEntity *createMesh(std::string meshPath, std::string texturePath) const noexcept = 0;
			virtual IndieStudio::IEntity *createAnimatedMesh(std::string meshPath, std::string texturePath) const noexcept = 0;
			virtual IndieStudio::IEntity *createCube(float size, std::string texturePath, IndieStudio::Pos pos = IndieStudio::Pos(0, 0, 0), IndieStudio::Pos scale = IndieStudio::Pos(1, 1, 1)) const noexcept = 0;
			virtual void setCursorVisible(bool b) noexcept = 0;
			virtual bool run(void) const noexcept = 0;
			virtual void render(void) const noexcept = 0;
	};
};

#endif