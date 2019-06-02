/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "Audio.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>

#define WALL_SIZE 40

void setMiddle(float &vec)
{
	if ((int)vec % WALL_SIZE != 0) {
		float f = (int)vec % WALL_SIZE;
		if (f > 0)
			vec += (WALL_SIZE / 2 - f);
		else
			vec -= (WALL_SIZE / 2 + f);
	}
	vec = static_cast<int>(vec);
}

IndieStudio::Bomb::Bomb(IndieStudio::IGraphical &graphical, IndieStudio::Pos vector, int bombSize, IndieStudio::Map &map, std::vector<std::shared_ptr<IndieStudio::Bomb>> bombVec) :
	_graphical(graphical), _map(map), _sound(IndieStudio::Audio("assets/bomb/bomb.wav")), _bombSize(bombSize), _bombVec(bombVec)
{
	std::cout << "NEW BOM CREATED" << std::endl;
	for (auto bomb_it = this->_bombVec.begin(); bomb_it != this->_bombVec.end(); bomb_it++)
		std::cout << "other bomb pos : " << std::endl << "\tx : " << bomb_it->get()->getPosition()._x << std::endl << "\tz : " << bomb_it->get()->getPosition()._z << std::endl;
	this->_bomb = this->_graphical.createMesh("assets/bomb/dinamite.obj");
	setMiddle(vector._x);
	setMiddle(vector._z);
	this->_bomb->setPosition(vector);
	this->_bomb->setScale(IndieStudio::Pos(20, 20, 20));
	this->createParticule(vector);
	std::thread t1(&IndieStudio::Bomb::startCountdown, this);
	t1.detach();
}

IndieStudio::Pos IndieStudio::Bomb::getPosition() const noexcept
{
	return (this->_bomb->getPosition());
}

IndieStudio::Bomb::~Bomb()
{
}

void IndieStudio::Bomb::createParticule(IndieStudio::Pos vector) noexcept
{
	this->_particle = this->_graphical.createParticle(
		IndieStudio::Pos(vector._x, vector._y, vector._z),
		IndieStudio::Pos(0.0f, 0.05f, 0.0f),
		3, 10,
		IndieStudio::Pos(0, 0, 0),
		IndieStudio::Pos(30, 30, 30));
}

std::vector<IndieStudio::Pos> IndieStudio::Bomb::explosionDir(std::vector<IndieStudio::Pos> vec)
{
	float size = 0.05 * _bombSize;
	IndieStudio::Pos up(size, 0.0f, 0.0f);
	IndieStudio::Pos down(size * -1, 0.0f, 0.0f);
	IndieStudio::Pos right(0.0f, 0.0f, size);
	IndieStudio::Pos left(0.0f, 0.0f, size * -1);
	vec.push_back(up);
	vec.push_back(down);
	vec.push_back(right);
	vec.push_back(left);
	return (vec);
}

void IndieStudio::Bomb::explosion(IndieStudio::Pos position)
{
	std::vector<IndieStudio::Pos> vec;
	vec = explosionDir(vec);
	for (std::vector<IndieStudio::Pos>::iterator it = vec.begin(); it != vec.end(); ++it) {
		IndieStudio::IEntity *particleSystem = this->_graphical.createParticle(
			IndieStudio::Pos(
				position._x,
				position._y,
				position._z),
			IndieStudio::Pos(
				it->_x,
				it->_y,
				it->_z),
			0, 5 * _bombSize,
			IndieStudio::Pos(
				255,
				1,
				1),
			IndieStudio::Pos(
				255,
				255,
				255));
		this->_explosionParticule.push_back(particleSystem);
	}
	this->playExplosionSound();
}

void IndieStudio::Bomb::destroyExplosionParticle()
{
	for (std::vector<IndieStudio::IEntity *>::iterator it = this->_explosionParticule.begin();
		 it != this->_explosionParticule.end(); ++it) {
		this->_graphical.deleteEntity(*it);
	}
}

void IndieStudio::Bomb::playExplosionSound(void) noexcept
{
	this->_sound.playSound(true);
}

void IndieStudio::Bomb::startCountdown(void)
{
	sleep(1);
	this->_bomb->setScale(IndieStudio::Pos(22, 22, 22));
	sleep(1);
	this->_bomb->setScale(IndieStudio::Pos(24, 24, 24));
	sleep(1);
	this->_bomb->setScale(IndieStudio::Pos(26, 26, 26));
	this->explosion(this->_bomb->getPosition());
	this->_graphical.deleteEntity(this->_bomb);
	this->_graphical.deleteEntity(this->_particle);
	this->_sound.playSound(true);
	this->_alive = false;
	sleep(2);
	this->destroyExplosionParticle();
}

bool IndieStudio::Bomb::getAlive() const noexcept
{
	return (this->_alive);
}