/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include "Character.hpp"

IndieStudio::Character::Character(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, char up, char left, char down, char right, char action, std::string meshPath, std::string texturePath, bool bot) : _bot(bot), _up(std::toupper(up)), _left(std::toupper(left)), _down(std::toupper(down)), _right(std::toupper(right)), _action(std::toupper(action))
{
	this->_model = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh(meshPath.c_str()));
	this->_model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_model->setMaterialTexture(0, driver->getTexture(texturePath.c_str()));
	this->_model->setMD2Animation(irr::scene::EMAT_STAND); // joue l'animation STAND en boucle
}

IndieStudio::Character::~Character()
{
}

irr::scene::IAnimatedMeshSceneNode *IndieStudio::Character::getMesh() noexcept
{
	return (this->_model);
}

char IndieStudio::Character::getUpKey() const noexcept
{
	return (this->_up);
}

char IndieStudio::Character::getLeftKey() const noexcept
{
	return (this->_left);
}

char IndieStudio::Character::getDownKey() const noexcept
{
	return (this->_down);
}

char IndieStudio::Character::getRightKey() const noexcept
{
	return (this->_right);
}

char IndieStudio::Character::getActionKey() const noexcept
{
	return (this->_action);
}

void IndieStudio::Character::setMovingUp(bool b) noexcept
{
	this->_movingUp = b;
}

void IndieStudio::Character::setMovingLeft(bool b) noexcept
{
	this->_movingLeft = b;
}

void IndieStudio::Character::setMovingDown(bool b) noexcept
{
	this->_movingDown = b;
}


void IndieStudio::Character::setMovingRight(bool b) noexcept
{
	this->_movingRight = b;
}


void IndieStudio::Character::setDoingAction(bool b) noexcept
{
	this->_doingAction = b;
}

bool IndieStudio::Character::getMovingUp(void) const noexcept
{
	return (this->_movingUp);
}

bool IndieStudio::Character::getMovingLeft(void) const noexcept
{
	return (this->_movingLeft);
}

bool IndieStudio::Character::getMovingDown(void) const noexcept
{
	return (this->_movingDown);
}

bool IndieStudio::Character::getMovingRight(void) const noexcept
{
	return (this->_movingRight);
}

bool IndieStudio::Character::getDoingAction(void) const noexcept
{
	return (this->_doingAction);
}

bool IndieStudio::Character::getIsMoving(void) const noexcept
{
	return (this->_isMoving);
}

void IndieStudio::Character::setIsMoving(bool b) noexcept
{
	this->_isMoving = b;
}