/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IRender
*/

#ifndef IRENDER_HPP_
#define IRENDER_HPP_

#include <irrlicht.h>

namespace IndieStudio {
	class IRender {
		public:
			virtual ~IRender() = default;
			virtual void render(void) = 0;
			virtual bool hasRender(void) const noexcept = 0;
			virtual void setEventReceiver(void) noexcept = 0;
		private:
	};
};

#endif