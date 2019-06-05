/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bonus
*/

#include "Bonus.hpp"
#include <thread>
#include <functional>

IndieStudio::Bonus::Bonus(IndieStudio::IGraphical &graphical): _graphical(graphical)
{
}

IndieStudio::Bonus::~Bonus()
{
}

IndieStudio::IEntity *IndieStudio::Bonus::createCubes(float x, float z, float y, float size, std::string texturePath) noexcept
{
	IndieStudio::IEntity *cube = this->_graphical.createCube(
		size,
		texturePath,
		IndieStudio::Pos(x, y, z));
	return (cube);
}


void IndieStudio::Bonus::create_Bonus(void) noexcept
{
	auto texture = get_texture_Bonus();
		while (_Bonus_Red_Bomb_Vec.size() + _Bonus_Red_Speed_Vec.size() +
	_Bonus_Red_Fire_Vec.size() + _Bonus_Blue_Bomb_Vec.size() +
	_Bonus_Blue_Fire_Vec.size() + _Bonus_Blue_Speed_Vec.size() < NB_BONUS) {
			auto max = this->_free_Pos.size() - 1;
			auto min = 0;
			auto randPos = rand()%(max-min + 1) + min;
			auto randTexture = rand()%(5-0 + 1) + 0;
			auto pos = this->_free_Pos.at(randPos);
			if (randTexture == RED_BOMB)
				this->_Bonus_Red_Bomb_Vec.push_back(createCubes(pos._x, pos._z, pos._y, (float) 20, texture.at(randTexture)));
			else if (randTexture == RED_FIRE)
				this->_Bonus_Red_Fire_Vec.push_back(createCubes(pos._x, pos._z, pos._y, (float) 20, texture.at(randTexture)));
			else if (randTexture == RED_SPEED)
				this->_Bonus_Red_Speed_Vec.push_back(createCubes(pos._x, pos._z, pos._y, (float) 20, texture.at(randTexture)));
			else if (randTexture == BLUE_BOMB)
				this->_Bonus_Blue_Bomb_Vec.push_back(createCubes(pos._x, pos._z, pos._y, (float) 20, texture.at(randTexture)));
			else if (randTexture == BLUE_FIRE)
				this->_Bonus_Blue_Fire_Vec.push_back(createCubes(pos._x, pos._z, pos._y, (float) 20, texture.at(randTexture)));
			else if (randTexture == BLUE_SPEED)
				this->_Bonus_Blue_Speed_Vec.push_back(createCubes(pos._x, pos._z, pos._y, (float) 20, texture.at(randTexture)));
			this->_free_Pos.erase(this->_free_Pos.begin()+randPos);
		}
}

void IndieStudio::Bonus::delete_Cube(IndieStudio::IEntity *del)
{
	auto delBonus = [this, &del](std::vector<IndieStudio::IEntity *> &cube) {
		for (unsigned int i = 0; i < cube.size(); i++) {
			if (cube.at(i) == del) {
                this->_free_Pos.push_back(del->getPosition());
				this->_graphical.deleteEntity(del);
				cube.erase(cube.begin()+i);
				return (cube);
			}
		}
		return(cube);
	};
	auto bonus = getRedBonusBomb();
	this->_Bonus_Red_Bomb_Vec = delBonus(bonus);
	bonus = getRedBonusSpeed();
	this->_Bonus_Red_Speed_Vec = delBonus(bonus);
	bonus = getRedBonusFire();
	this->_Bonus_Red_Fire_Vec = delBonus(bonus);
	bonus = getBlueBonusBomb();
	this->_Bonus_Blue_Bomb_Vec = delBonus(bonus);
	bonus = getBlueBonusSpeed();
	this->_Bonus_Blue_Speed_Vec = delBonus(bonus);
	bonus = getBlueBonusFire();
	this->_Bonus_Blue_Fire_Vec = delBonus(bonus);
}

//////// GET ///////////

std::vector<std::string> IndieStudio::Bonus::get_texture_Bonus() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(RED_BOMB_BONUS);
	texture.push_back(RED_FIRE_BONUS);
	texture.push_back(RED_SPEED_BONUS);
	texture.push_back(BLUE_BOMB_BONUS);
	texture.push_back(BLUE_FIRE_BONUS);
	texture.push_back(BLUE_SPEED_BONUS);
	return (texture);
}
std::vector<IndieStudio::IEntity *> IndieStudio::Bonus::getRedBonusFire() noexcept
{
	return (this->_Bonus_Red_Fire_Vec);
}
std::vector<IndieStudio::IEntity *> IndieStudio::Bonus::getRedBonusBomb() noexcept
{
	return (this->_Bonus_Red_Bomb_Vec);
}
std::vector<IndieStudio::IEntity *> IndieStudio::Bonus::getRedBonusSpeed() noexcept
{
	return (this->_Bonus_Red_Speed_Vec);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Bonus::getBlueBonusFire() noexcept
{
	return (this->_Bonus_Blue_Fire_Vec);
}
std::vector<IndieStudio::IEntity *> IndieStudio::Bonus::getBlueBonusBomb() noexcept
{
	return (this->_Bonus_Blue_Bomb_Vec);
}
std::vector<IndieStudio::IEntity *> IndieStudio::Bonus::getBlueBonusSpeed() noexcept
{
	return (this->_Bonus_Blue_Speed_Vec);
}

int IndieStudio::Bonus::getBonus(IndieStudio::Pos pos, std::vector<IndieStudio::IEntity *> bonus) noexcept
{
	std::function<bool(IndieStudio::Pos, IndieStudio::Pos)> isTrue = [](IndieStudio::Pos posA, IndieStudio::Pos posB) {
		if (posB._x >= posA._x - 10 && posB._x < posA._x + 10 && posB._z > posA._z - 10 && posB._z < posA._z + 10)
			return (true);
		return (false);
	};
	for (auto i = bonus.begin(); i != bonus.end(); i++) {
		auto bonusPos = (*i)->getPosition();
		if (isTrue(bonusPos, pos) == true) {
			delete_Cube((*i));
			return (1);
		}
	}
	return (0);
}

int IndieStudio::Bonus::getMalus(IndieStudio::Pos pos, std::vector<IndieStudio::IEntity *> bonus) noexcept
{
	std::function<bool(IndieStudio::Pos, IndieStudio::Pos)> isTrue = [](IndieStudio::Pos posA, IndieStudio::Pos posB) {
		if (posB._x >= posA._x - 10 && posB._x < posA._x + 10 && posB._z > posA._z - 10 && posB._z < posA._z + 10)
			return (true);
		return (false);
	};
	for (auto i = bonus.begin(); i != bonus.end(); i++) {
		auto bonusPos = (*i)->getPosition();
		if (isTrue(bonusPos, pos) == true) {
			delete_Cube((*i));
			return (-1);
		}
	}
	return (0);
}

std::vector<IndieStudio::Pos> IndieStudio::Bonus::getFreePosition() noexcept
{
    return(this->_free_Pos);
}

//////// SET ///////////

void IndieStudio::Bonus::addFreePosition(std::vector<IndieStudio::Pos> pos) noexcept
{
    for (unsigned i = 0; i < pos.size(); i++) {
        this->_free_Pos.push_back(pos.at(i));
    }
}

//////// OTHER /////////

void IndieStudio::Bonus::animeBonus() noexcept
{
	static bool direction = false;
	float high = _Bonus_Red_Bomb_Vec.at(0)->getPosition()._y;
	auto parser = [&](std::vector<IndieStudio::IEntity *> bonus, bool direction) {
		for (auto i = bonus.begin(); i != bonus.end(); i++) {
			if (direction == false)
				(*i)->setPosition(IndieStudio::Pos{(*i)->getPosition()._x, (*i)->getPosition()._y + (float)0.05, (*i)->getPosition()._z});
			else
				(*i)->setPosition(IndieStudio::Pos{(*i)->getPosition()._x, (*i)->getPosition()._y - (float)0.05, (*i)->getPosition()._z});
		}
		return (bonus);
	};
	if (high >= 67)
		direction = true;
	else if (high <= 60)
		direction = false;
	this->_Bonus_Red_Bomb_Vec = parser(this->_Bonus_Red_Bomb_Vec, direction);
	this->_Bonus_Red_Fire_Vec = parser(this->_Bonus_Red_Fire_Vec, direction);
	this->_Bonus_Red_Speed_Vec = parser(this->_Bonus_Red_Speed_Vec, direction);
	this->_Bonus_Blue_Bomb_Vec = parser(this->_Bonus_Blue_Bomb_Vec, direction);
	this->_Bonus_Blue_Fire_Vec = parser(this->_Bonus_Blue_Fire_Vec, direction);
	this->_Bonus_Blue_Speed_Vec = parser(this->_Bonus_Blue_Speed_Vec, direction);
}