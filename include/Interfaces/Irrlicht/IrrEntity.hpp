/*
** EPITECH PROJECT, 2019
** test
** File description:
** IrrEntity
*/

#ifndef IRRENTITY_HPP_
#define IRRENTITY_HPP_

#include "IEntity.hpp"
#include <irr/irrlicht.h>

namespace IndieStudio {
	class IrrEntity : public IEntity {
		public:
			IrrEntity(irr::scene::IAnimatedMeshSceneNode *entity) : _entity(entity) {};
			IrrEntity(irr::scene::IMeshSceneNode *entity) : _entity((irr::scene::IAnimatedMeshSceneNode *)(entity)) {};
			~IrrEntity();
			virtual IndieStudio::Pos getPosition(void) const noexcept;
			virtual void setPosition(IndieStudio::Pos) noexcept;
		private:
			irr::scene::IAnimatedMeshSceneNode *_entity;
	};
};

#endif