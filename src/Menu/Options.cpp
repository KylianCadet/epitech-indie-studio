/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Options
*/

#include "Options.hpp"

IndieStudio::Options::Options(irr::video::IVideoDriver * driver, std::string skin, std::string skinA, std::pair<int, int> position)
: Button(driver, skin, skinA, position)
{
}

IndieStudio::Options::~Options()
{
}
