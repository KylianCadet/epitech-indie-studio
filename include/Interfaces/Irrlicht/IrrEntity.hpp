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
			IrrEntity(irr::scene::IParticleSystemSceneNode *particle) : _particle(particle) {};
			~IrrEntity();
			virtual IndieStudio::Pos getPosition(void) const noexcept;
			virtual void setPosition(IndieStudio::Pos) noexcept;
			virtual void setRotation(IndieStudio::Pos) noexcept;
			virtual void setAnimation(int) noexcept;
			virtual void setScale(IndieStudio::Pos) noexcept;
			irr::scene::IAnimatedMeshSceneNode *getMesh() const noexcept;
			irr::scene::IParticleSystemSceneNode *getParticle() const noexcept;

		private:
			irr::scene::IAnimatedMeshSceneNode *_entity = nullptr;
			irr::scene::IParticleSystemSceneNode *_particle = nullptr;
	};
};

#endif