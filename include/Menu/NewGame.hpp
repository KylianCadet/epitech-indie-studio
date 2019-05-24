/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** NewGame
*/

#ifndef NEWGAME_HPP_
#define NEWGAME_HPP_

#include "Button.hpp"

namespace IndieStudio {
	class NewGame : public Button {
		public:
			NewGame(irr::video::IVideoDriver *, std::string, std::string, std::pair<int, int>);
			~NewGame();
	};
};

#endif /* !NEWGAME_HPP_ */
