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

irr::core::vector3df IndieStudio::Bomb::explosionDir(int i)
{
	switch (i) {
		case 0: {
			irr::core::vector3df up(0.05f, 0.0f, 0.0f);
			return (up);
		}
		case 1: {
			irr::core::vector3df down(-0.05f, 0.0f, 0.0f);
			return (down);
		}
		case 2: {
			irr::core::vector3df right(0.0f, 0.0f, 0.05f);
			return (right);
		}
		case 3: {
			irr::core::vector3df left(0.05f, 0.0f, -0.05f);
			return (left);
		}
		default: {
			irr::core::vector3df def(0.00f, 0.0f, 0.0f);
			return (def);
		}
	}
}

void IndieStudio::Bomb::explosion(irr::core::vector3df position)
{
	for (int i = 0; i < 4; i++) {
		irr::scene::IParticleSystemSceneNode *particleSystem = _sceneManager->addParticleSystemSceneNode(false);
		irr::scene::IParticleEmitter *emitter = particleSystem->createBoxEmitter(
			irr::core::aabbox3d<irr::f32>(position.X, position.Y, position.Z,position.X, position.Y, position.Z), // coordonnees de la boite
			irr::core::vector3df(explosionDir(i)),      // direction de diffusion
			0, 5,                                      // nb particules emises a la sec min / max
			irr::video::SColor(1, 205, 205,19),         // couleur la plus sombre
			irr::video::SColor(1, 192, 31, 31),         // couleur la plus claire
			1000, 1000,                                  // duree de vie min / max
			0,                                        // angle max d'ecart / direction prevue
			irr::core::dimension2df(13.0f, 13.0f),      // taille minimum
			irr::core::dimension2df(13.0f, 13.0f)       // taille maximum
		);
		particleSystem->setEmitter(emitter);
		emitter->drop();                                                   // plus besoin de ca
		particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false); // insensible a la lumiere
	}
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
	explosion(this->_bomb->getPosition());
	this->_sceneManager->addToDeletionQueue(this->_bomb);
	this->_sceneManager->addToDeletionQueue(this->_particle);
	this->_bomb->remove();
	this->_particle->remove();
}