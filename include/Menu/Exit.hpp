/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Exit
*/

#ifndef EXIT_HPP_
#define EXIT_HPP_

#include "Button.hpp"

namespace IndieStudio {
	class Exit : public Button {
		public:
			Exit(irr::video::IVideoDriver *, std::string, std::string, std::pair<int, int>);
			~Exit();
		private:
	};
};

#endif /* !EXIT_HPP_ */
