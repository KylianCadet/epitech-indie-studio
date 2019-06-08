/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include "IEvent.hpp"

namespace IndieStudio
{
struct playerKeybinds
{
	Key up;
	Key down;
	Key left;
	Key right;
	Key bomb;
};

class Config
{
public:
	Config();
	~Config();

	playerKeybinds getKeybinds1(void) noexcept;
	playerKeybinds getKeybinds2(void) noexcept;

private:
	playerKeybinds _player1;
	playerKeybinds _player2;
};
}; // namespace IndieStudio

#endif /* !CONFIG_HPP_ */
