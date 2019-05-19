/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventListener
*/

#include "EventListener.hpp"
#include <iostream>

IndieStudio::EventListener::EventListener(std::vector<IndieStudio::Character> &characterVec) : _characterVec(characterVec)
{
	std::cout << "in event listener constructor" << std::endl;
}

IndieStudio::EventListener::~EventListener()
{
}

#define MOV 1.0f

void IndieStudio::EventListener::checkEvent()
{
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		irr::core::vector3df v = character_it->getMesh()->getPosition();
		if (character_it->getMovingUp() == true)
			v.X += MOV;
		if (character_it->getMovingDown() == true)
			v.X -= MOV;
		if (character_it->getMovingLeft() == true)
			v.Z += MOV;
		if (character_it->getMovingRight() == true)
			v.Z -= MOV;
		character_it->getMesh()->setPosition(v);
	}
}

bool IndieStudio::EventListener::OnEvent(const irr::SEvent &event)
{
	bool ret = false;

	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
			for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
				if (event.KeyInput.Key == character_it->getUpKey()) {
					character_it->setMovingUp(event.KeyInput.PressedDown);
					ret = true;
				}
				if (event.KeyInput.Key == character_it->getLeftKey()) {
					character_it->setMovingLeft(event.KeyInput.PressedDown);
					ret = true;
				}
				if (event.KeyInput.Key == character_it->getDownKey()) {
					character_it->setMovingDown(event.KeyInput.PressedDown);
					ret = true;
				}
				if (event.KeyInput.Key == character_it->getRightKey()) {
					character_it->setMovingRight(event.KeyInput.PressedDown);
					ret = true;
				}
				if (event.KeyInput.Key == character_it->getActionKey()) {
					character_it->setDoingAction(event.KeyInput.PressedDown);
					ret = true;
				}
			}
			return (ret);
	}
	return (false);
}