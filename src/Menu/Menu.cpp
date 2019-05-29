/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(irr::video::IVideoDriver *driver, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
{
	this->_volume = volume;
	this->_sounds = sounds;
	this->_driver = driver;
}

void Menu::setButtonSwitch(int incrementation, int nbrOfButtons) noexcept
{
	this->_buttonStatus += incrementation;
	if (this->_buttonStatus > nbrOfButtons)
		this->_buttonStatus = 0;
	else if (this->_buttonStatus < 0)
		this->_buttonStatus = nbrOfButtons;
}

void Menu::setMenuActive(int newMenuStatus) noexcept
{
	this->_renderStatus = newMenuStatus;
}

int Menu::getCurrentMenuActive(void) const noexcept
{
	return this->_renderStatus;
}

void Menu::setButtonActive(int newButtonStatus) noexcept
{
	this->_buttonStatus = newButtonStatus;
}

int Menu::getCurrentButtonActive(void) const noexcept
{
	return this->_buttonStatus;
}