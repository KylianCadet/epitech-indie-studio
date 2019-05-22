/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventListener
*/

#include "CharacterEventListener.hpp"
#include <iostream>

IndieStudio::CharacterEventListener::CharacterEventListener(std::vector<IndieStudio::Character> &characterVec) : _characterVec(characterVec)
{
}

IndieStudio::CharacterEventListener::~CharacterEventListener()
{
}

#define UP_ROT 0
#define DOWN_ROT 180
#define RIGHT_ROT 90
#define LEFT_ROT 270

void checkMove(std::vector<IndieStudio::Character>::iterator character_it, bool isMoving,irr::f32 &coordinate, int rotation, bool sign)
{
	if (isMoving == true) {
		if (sign)
			coordinate += character_it->getSpeed();
		else
			coordinate -= character_it->getSpeed();
		character_it->getMesh()->setRotation(irr::core::vector3df(0, rotation, 0));
		character_it->setIsMoving(true);
	}
}

void IndieStudio::CharacterEventListener::moveCharacter() noexcept
{
	bool isMoving = false;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		irr::core::vector3df v = character_it->getMesh()->getPosition();
		isMoving = character_it->getIsMoving();
		checkMove(character_it, character_it->getMovingUp(),v.X, UP_ROT, true);
		checkMove(character_it, character_it->getMovingDown(),v.X, DOWN_ROT, false);
		checkMove(character_it, character_it->getMovingLeft(),v.Z, LEFT_ROT, true);
		checkMove(character_it, character_it->getMovingRight(),v.Z, RIGHT_ROT, false);
		if (character_it->getMesh()->getPosition() != v && isMoving == false)
			character_it->getMesh()->setMD2Animation(irr::scene::EMAT_RUN);
		else if (character_it->getMesh()->getPosition() == v && isMoving == true) {
			character_it->setIsMoving(false);
			character_it->getMesh()->setMD2Animation(irr::scene::EMAT_STAND);
		}
		character_it->getMesh()->setPosition(v);
		if (character_it->getDoingAction() == true) {
			character_it->getDeathSound()->playSound();
		}
	}
}

bool IndieStudio::CharacterEventListener::OnEvent(const irr::SEvent &event)
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