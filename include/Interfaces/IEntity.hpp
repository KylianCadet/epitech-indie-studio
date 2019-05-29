/*
** EPITECH PROJECT, 2019
** test
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include "IEntity.hpp"

namespace IndieStudio {
	class Pos {
		public:
			Pos(float x, float y, float z) : _x(x), _y(y), _z(z) {};
			float _x;
			float _y;
			float _z;
	};
	class IEntity {
		public:
			virtual ~IEntity() = default;
			virtual IndieStudio::Pos getPosition(void) const noexcept = 0;
			virtual void setPosition(IndieStudio::Pos) noexcept = 0;
	};
};

#endif