/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IrrGraphical
*/

#ifndef IRRGRAPHICAL_HPP_
#define IRRGRAPHICAL_HPP_

#include "IGraphical.hpp"
#include "IrrEntity.hpp"
#include "IrrEvent.hpp"
#include <irr/irrlicht.h>

namespace IndieStudio {
	class IrrGraphical : public IGraphical, public irr::IEventReceiver {
		public:
			IrrGraphical();
			~IrrGraphical();
			virtual IndieStudio::IEntity *createMesh(std::string meshPath) const noexcept;
			virtual IndieStudio::IEntity *createAnimatedMesh(std::string meshPath, std::string texturePath) const noexcept;
			virtual IndieStudio::IEntity *createCube(float size, std::string texturePath, IndieStudio::Pos pos, IndieStudio::Pos scale) const noexcept;
			virtual IndieStudio::IEntity *createParticle(IndieStudio::Pos boxPos, IndieStudio::Pos dirPos, int min, int max, IndieStudio::Pos colorMin, IndieStudio::Pos colorMax) const noexcept;
			virtual void setCursorVisible(bool b) noexcept;
			virtual bool run(void) const noexcept;
			virtual void render(void) const noexcept;
			virtual void drop(void) const noexcept;
			virtual bool OnEvent(const irr::SEvent &event);
			virtual IndieStudio::IEvent getEvent(void) const noexcept;
			virtual void deleteEntity(IndieStudio::IEntity *) const noexcept;

		private:
			IndieStudio::IrrEvent _event;
			irr::IrrlichtDevice *_device;
			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_driver;
	};
};

#endif