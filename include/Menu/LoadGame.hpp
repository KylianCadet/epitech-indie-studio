/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** LoadGame
*/

#ifndef LOADGAME_HPP_
#define LOADGAME_HPP_

#include "Button.hpp"

namespace IndieStudio {
	class LoadGame : public Button {
		public:
			LoadGame(irr::video::IVideoDriver *, std::string, std::string, std::pair<int, int>);
			~LoadGame();
		private:
	};
};

#endif /* !LOADGAME_HPP_ */
