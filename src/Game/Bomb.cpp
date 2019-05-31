/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include <chrono>
#include <iostream>
#include <thread>

#define WALL_SIZE 40.0f

void setMiddle(float &vec)
{
	if ((int)vec % 40 != 0) {
		float f = (int)vec % 40;
		if (f > 0)
			vec += (20 - f);
		else
			vec -= (20 + f);
	}
	vec = static_cast<int>(vec);
}

IndieStudio::Bomb::Bomb(IndieStudio::IGraphical &graphical, IndieStudio::Pos vector, int bombSize) :
	_graphical(graphical), _sound(IndieStudio::Audio("assets/bomb/bomb.wav")), _bombSize(bombSize)
{
	this->_bomb = this->_graphical.createMesh("assets/bomb/dinamite.obj");
	setMiddle(vector._x);
	setMiddle(vector._z);
	this->_bomb->setPosition(vector);
	this->_bomb->setScale(IndieStudio::Pos(20, 20, 20));
	this->createParticule(vector);
	std::thread t1(&IndieStudio::Bomb::startCountdown, this);
	t1.detach();
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

#include <unistd.h>

void IndieStudio::Bomb::explosion(IndieStudio::Pos position)
{
	std::vector<IndieStudio::IEntity *> particleVec;
	float posX = position._x;
	float posY = position._y;
	float posZ = position._z;

	for (int i = 0; i != 5; i++) {
		particleVec.push_back(this->_graphical.createParticle(
			IndieStudio::Pos(
				posX + (i * WALL_SIZE),
				posY,
				posZ + (i * WALL_SIZE)),
			IndieStudio::Pos(
				0,
				0.01,
				0),
			0, 5 * _bombSize,
			IndieStudio::Pos(
				255,
				1,
				1),
			IndieStudio::Pos(
				255,
				255,
				255)));
	}
	sleep(1);
	for (auto particle_it = particleVec.begin(); particle_it != particleVec.end(); particle_it++)
		this->_graphical.deleteEntity(*particle_it);
}

#include "Audio.hpp"
#include <iostream>

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
	this->playExplosionSound();
	// std::thread t1(&IndieStudio::Bomb::explosion, this, this->_bomb->getPosition());
	// t1.detach();
	// this->explosion(this->_bomb->getPosition());
	this->_graphical.deleteEntity(this->_bomb);
	this->_graphical.deleteEntity(this->_particle);
	this->_alive = false;
}

bool IndieStudio::Bomb::getAlive() const noexcept
{
	return (this->_alive);
}