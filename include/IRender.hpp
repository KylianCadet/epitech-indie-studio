/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IRender
*/

#ifndef IRENDER_HPP_
#define IRENDER_HPP_

namespace IndieStudio {
	class IRender {
		public:
			virtual ~IRender() = default;
			virtual void render(void) = 0;
			virtual int getRenderStatus(void) const noexcept = 0;
			virtual void setRenderStatus(int) noexcept = 0;
		private:
	};
};

#endif