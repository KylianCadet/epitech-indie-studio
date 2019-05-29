/*
** EPITECH PROJECT, 2019
** test
** File description:
** IrrEntity
*/

#include "IrrEntity.hpp"

IndieStudio::IrrEntity::~IrrEntity()
{
}

IndieStudio::Pos IndieStudio::IrrEntity::getPosition(void) const noexcept
{
	const irr::core::vector3df &entityPos = this->_entity->getPosition();
	IndieStudio::Pos pos(entityPos.X, entityPos.Y, entityPos.Z);
	return (pos);
}

void IndieStudio::IrrEntity::setPosition(IndieStudio::Pos position) noexcept
{
	irr::core::vector3df entityPos(position._x, position._y, position._z);
	this->_entity->setPosition(entityPos);
}