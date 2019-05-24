/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include <chrono>
#include <thread>
#include <iostream>

#define WALL_SIZE 20.0f

void setMiddle(float &vec)
{
	if ((int)vec % 30 != 0) {
		float f = (int)vec % 30;
		if (f >= 15)
			vec += (30 - f);
		else
			vec -= f;
	}
}

IndieStudio::Bomb::Bomb(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector, int bombSize) : _sceneManager(sceneManager), _driver(driver), _sound(IndieStudio::Audio("assets/bomb/bomb.wav")), _bombSize(bombSize)
{
	this->_bomb = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("assets/bomb/dinamite.obj"));
	setMiddle(vector.X);
	setMiddle(vector.Y);
	setMiddle(vector.Z);
	this->_bomb->setPosition(vector);
	this->_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_bomb->setScale(irr::core::vector3df(20, 20, 20));
	this->createParticule(vector);
	std::thread t1(&IndieStudio::Bomb::startCountdown, this);
	t1.detach();
}

IndieStudio::Bomb::~Bomb()
{
}

void IndieStudio::Bomb::createParticule(irr::core::vector3df vector) noexcept
{
	this->_particle = this->_sceneManager->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* emitter = this->_particle->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(vector.X, vector.Y, vector.Z, vector.X, vector.Y, vector.Z),
		irr::core::vector3df(0.0f,0.05f,0.0f),
		3,10,
		irr::video::SColor(0,255,255,255),
		irr::video::SColor(0,255,255,255),
		600, 1200,
		0,
		irr::core::dimension2df(8.0f,8.0f),
		irr::core::dimension2df(14.0f,14.0f)
	);
	this->_particle->setEmitter(emitter);
	emitter->drop();

	this->_particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_particle->setMaterialTexture(0, this->_driver->getTexture("assets/bomb/smoke.jpg"));

	irr::scene::IParticleAffector* affector =
		this->_particle->createFadeOutParticleAffector(
		irr::video::SColor(0,0,0,0),
		1200
	);
	this->_particle->addAffector(affector);
	affector->drop();
}

#include <unistd.h>
#include "Audio.hpp"

void IndieStudio::Bomb::playExplosionSound(void) noexcept
{
	this->_sound.playSound(true);
}

void IndieStudio::Bomb::exploseBomb(void) noexcept
{
	irr::core::vector3df pos = this->_bomb->getPosition();
	// int x = pos.X;
	// int z = pos.Z;

	// for (int i = 0; i != this->_bombSize; i++) {
	// 	this->createParticule(irr::core::vector3df(pos.X + (i * 30), pos.Y, pos.Z));
	// 	this->createParticule(irr::core::vector3df(pos.X, pos.Y, pos.Z + (i * 30)));
	// }
	sleep(1);
	
}

void IndieStudio::Bomb::startCountdown(void)
{
	sleep(1);
	this->_bomb->setScale(irr::core::vector3df(22, 22, 22));
	sleep(1);
	this->_bomb->setScale(irr::core::vector3df(24, 24, 24));
	sleep(1);
	this->_bomb->setScale(irr::core::vector3df(26, 26, 26));
	// std::thread t1(&IndieStudio::Bomb::playExplosionSound, this);
	// t1.detach();
	this->exploseBomb();
	this->_sceneManager->addToDeletionQueue(this->_bomb);
	this->_sceneManager->addToDeletionQueue(this->_particle);
	this->_sound.playSound(true);
	this->_alive = false;
}

bool IndieStudio::Bomb::getAlive() const noexcept
{
	return (this->_alive);
}