/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include <chrono>
#include <thread>

IndieStudio::Bomb::Bomb(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector) : _sceneManager(sceneManager), _driver(driver)
{
	this->_bomb = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("assets/bomb/dinamite.obj"), 0, -1, vector);
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

#include <iostream>
#include <unistd.h>

void IndieStudio::Bomb::startCountdown(void)
{
	sleep(1);
	std::cout << "1 seconde elapsed" << std::endl;
	sleep(1);
	std::cout << "2 seconde elapsed" << std::endl;
	sleep(1);
	std::cout << "3 seconde elapsed" << std::endl;
	sleep(1);
	std::cout << "EXPLOSION" << std::endl;
	this->_sceneManager->addToDeletionQueue(this->_bomb);
	this->_sceneManager->addToDeletionQueue(this->_particle);
	// this->_bomb->remove();
	// this->_particle->remove();
}