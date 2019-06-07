/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include "Character.hpp"

IndieStudio::Character::Character(IndieStudio::IGraphical &graphical, std::string meshPath, std::string texturePath, std::string deathSoundPath, bool bot, char up, char left, char down, char right, char action, IndieStudio::Pos position) :
	_graphical(graphical),
	_bot(bot),
	_up(std::toupper(up)),
	_left(std::toupper(left)),
	_down(std::toupper(down)),
	_right(std::toupper(right)),
	_action(std::toupper(action)),
	_spawnPos(position)
{
	this->_model = this->_graphical.createAnimatedMesh(meshPath, texturePath);
	this->_model->setPosition(position);
	this->_deathSound = std::shared_ptr<IndieStudio::Audio>(new IndieStudio::Audio(deathSoundPath));
}

IndieStudio::Character::~Character()
{
}

IndieStudio::Pos IndieStudio::Character::getPosition() noexcept
{
	return (_model->getPosition());
}

void IndieStudio::Character::setPosition(IndieStudio::Pos position) noexcept
{
	_model->setPosition(position);
}

IndieStudio::IEntity *IndieStudio::Character::getEntity() noexcept
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

void IndieStudio::Character::playDeathSound(bool b) noexcept
{
	this->_deathSound->playSound(b);
}

void IndieStudio::Character::set_Bomb_Current(int i) noexcept
{
	this->_bomb_current = i;
}

int IndieStudio::Character::get_Bomb_Current() const noexcept
{
	return (this->_bomb_current);
}

void IndieStudio::Character::setBombMax(int i) noexcept
{
	this->_bomb_Max = i;
}

int IndieStudio::Character::getBombMax() const noexcept
{
	return (this->_bomb_Max);
}

int IndieStudio::Character::getBombSize() const noexcept
{
	return (this->_bombSize);
}

void IndieStudio::Character::setBombSize(int i) noexcept
{
	this->_bombSize = i;
}

IndieStudio::Pos IndieStudio::Character::getSpawnPos() const noexcept
{
	return (this->_spawnPos);
}

void IndieStudio::Character::setBonus(float speed, int bombSize, int bombMax) noexcept
{
	if (speed != 0 || bombSize != 0 || bombMax != 0) {
		this->setSpeed(getSpeed() + speed / 4);
		this->setBombSize(getBombSize() + bombSize);
		this->setBombMax(getBombMax() + bombMax);
	}
	if (getSpeed() < SPEED)
		setSpeed(SPEED);
	if (getBombSize() < BOMBSIZE)
		setBombSize(BOMBSIZE);
	if (getBombMax() < BOMBMAX)
		setBombMax(BOMBMAX);
}