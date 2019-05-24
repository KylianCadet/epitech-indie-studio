/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** NewGame
*/

#include "NewGame.hpp"

IndieStudio::NewGame::NewGame(irr::video::IVideoDriver * driver, std::string skin, std::string skinA, std::pair<int, int> position)
: Button(driver, skin, skinA, position)
{

}

IndieStudio::NewGame::~NewGame()
{

}