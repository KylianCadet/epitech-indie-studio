/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Options
*/

#ifndef OPTIONS_HPP_
#define OPTIONS_HPP_

#include "Button.hpp"

namespace IndieStudio {
	class Options : public Button {
		public:
			Options(irr::video::IVideoDriver *, std::string, std::string, std::pair<int, int>);
			~Options();
		private:
	};
};

#endif /* !OPTIONS_HPP_ */
