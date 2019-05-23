/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Event
*/

#include "Event.hpp"

// IndieStudio::Event::Event(IndieStudio::Menu & menu) : _menu(menu)
// {

// }

// IndieStudio::Event::~Event(){}

// bool IndieStudio::CharacterEventListener::OnEvent(const irr::SEvent &event)
// {
// 	bool ret = false;

// 	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
// 			for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
// 				if (event.KeyInput.Key == character_it->getUpKey()) {
// 					character_it->setMovingUp(event.KeyInput.PressedDown);
// 					ret = true;
// 				}
// 				if (event.KeyInput.Key == character_it->getLeftKey()) {
// 					character_it->setMovingLeft(event.KeyInput.PressedDown);
// 					ret = true;
// 				}
// 				if (event.KeyInput.Key == character_it->getDownKey()) {
// 					character_it->setMovingDown(event.KeyInput.PressedDown);
// 					ret = true;
// 				}
// 				if (event.KeyInput.Key == character_it->getRightKey()) {
// 					character_it->setMovingRight(event.KeyInput.PressedDown);
// 					r
// 			}
// 			return (ret);
// 	}
// 	return (false);
// }