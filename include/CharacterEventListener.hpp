/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventListener
*/

#ifndef EVENTLISTENER_HPP_
#define EVENTLISTENER_HPP_

#include <irrlicht.h>
#include <vector>
#include "Character.hpp"

namespace IndieStudio {
class CharacterEventListener : public irr::IEventReceiver {
		public:
			CharacterEventListener(std::vector<IndieStudio::Character> &characterVec);
			~CharacterEventListener();
			virtual bool OnEvent(const irr::SEvent &event);
			void moveCharacter() noexcept;

		protected:
		private:
			std::vector<IndieStudio::Character> &_characterVec;
	};
};

#endif