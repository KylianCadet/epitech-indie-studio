/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include "Character.hpp"

IndieStudio::Character::Character(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, std::string meshPath, std::string texturePath, std::string deathSoundPath, bool bot, char up, char left, char down, char right, char action) : _bot(bot), _up(std::toupper(up)), _left(std::toupper(left)), _down(std::toupper(down)), _right(std::toupper(right)), _action(std::toupper(action))
{
	irr::video::ITexture *texture = driver->getTexture(texturePath.c_str());

	this->_model = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh(meshPath.c_str()));
	if (this->_model == NULL || texture == NULL)
		exit(84);
	this->_model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_model->setMaterialTexture(0, texture);
	this->_model->setMD2Animation(irr::scene::EMAT_STAND);
	this->_deathSound = new IndieStudio::Audio(deathSoundPath);
}

IndieStudio::Character::~Character()
{
	// delete this->_deathSound;
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

float IndieStudio::Character::getSpeed(void) const noexcept
{
	return (this->_speed);
}

void IndieStudio::Character::setSpeed(float speed) noexcept
{
	this->_speed = speed;
}

IndieStudio::Audio *IndieStudio::Character::getDeathSound() noexcept
{
	return (this->_deathSound);
}
