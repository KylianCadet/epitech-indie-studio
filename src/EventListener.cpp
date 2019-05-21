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
#define UP_ROT 0
#define DOWN_ROT 180
#define RIGHT_ROT 90
#define LEFT_ROT 270

void IndieStudio::EventListener::moveCharacter() noexcept
{
	bool isMoving = false;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		irr::core::vector3df v = character_it->getMesh()->getPosition();
		isMoving = character_it->getIsMoving();
		if (character_it->getMovingUp() == true) {
			v.X += MOV;
			character_it->getMesh()->setRotation(irr::core::vector3df(0, UP_ROT, 0));
			character_it->setIsMoving(true);
		}
		if (character_it->getMovingDown() == true) {
			v.X -= MOV;
			character_it->getMesh()->setRotation(irr::core::vector3df(0, DOWN_ROT, 0));
			character_it->setIsMoving(true);
		}
		if (character_it->getMovingLeft() == true) {
			v.Z += MOV;
			character_it->getMesh()->setRotation(irr::core::vector3df(0, LEFT_ROT, 0));
			character_it->setIsMoving(true);
		}
		if (character_it->getMovingRight() == true) {
			v.Z -= MOV;
			character_it->getMesh()->setRotation(irr::core::vector3df(0, RIGHT_ROT, 0));
			character_it->setIsMoving(true);
		}
		if (character_it->getMesh()->getPosition() != v && isMoving == false)
			character_it->getMesh()->setMD2Animation(irr::scene::EMAT_RUN);
		else if (character_it->getMesh()->getPosition() == v && isMoving == true) {
			character_it->setIsMoving(false);
			character_it->getMesh()->setMD2Animation(irr::scene::EMAT_STAND);
		}
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