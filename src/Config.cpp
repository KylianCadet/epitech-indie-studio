/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Config
*/

#include "Config.hpp"

IndieStudio::Config::Config()
{
	this->_player1.up = Z;
	this->_player1.down = S;
	this->_player1.left = Q;
	this->_player1.right = D;
	this->_player1.bomb = E;
	this->_player2.up = I;
	this->_player2.down = K;
	this->_player2.left = J;
	this->_player2.right = L;
	this->_player2.bomb = O;
}

IndieStudio::Config::~Config()
{
}

IndieStudio::playerKeybinds IndieStudio::Config::getKeybinds1(void) const noexcept
{
	return this->_player1;
}

IndieStudio::playerKeybinds IndieStudio::Config::getKeybinds2(void) const noexcept
{
	return this->_player2;
}

void IndieStudio::Config::setKeybinds1(IndieStudio::playerKeybinds keyBinds) noexcept
{
	this->_player1 = keyBinds;
}

void IndieStudio::Config::setKeybinds2(IndieStudio::playerKeybinds keyBinds) noexcept
{
	this->_player2 = keyBinds;
}
