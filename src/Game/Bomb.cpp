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

std::vector<irr::core::vector3df> IndieStudio::Bomb::explosionDir(std::vector<irr::core::vector3df> vec)
{
	float size = 0.05 * _bombSize;
	irr::core::vector3df up(size, 0.0f, 0.0f);
	irr::core::vector3df down(size * -1, 0.0f, 0.0f);
	irr::core::vector3df right(0.0f, 0.0f, size);
	irr::core::vector3df left(0.0f, 0.0f, size * -1);
	vec.push_back(up);
	vec.push_back(down);
	vec.push_back(right);
	vec.push_back(left);
	return (vec);
}

void IndieStudio::Bomb::explosion(irr::core::vector3df position)
{
	std::vector<irr::core::vector3df> vec;
	vec = explosionDir(vec);
	for(std::vector<irr::core::vector3df>::iterator it = vec.begin(); it != vec.end(); ++it) {
		irr::scene::IParticleSystemSceneNode *particleSystem = _sceneManager->addParticleSystemSceneNode(false);
		irr::scene::IParticleEmitter *emitter = particleSystem->createBoxEmitter(
			irr::core::aabbox3d<irr::f32>(position.X, position.Y, position.Z,position.X, position.Y, position.Z), // coordonnees de la boite
			irr::core::vector3df(*it),      // direction de diffusion
			0, 5 * _bombSize,                                      // nb particules emises a la sec min / max
			irr::video::SColor(1, 205, 205,19),         // couleur la plus sombre
			irr::video::SColor(1, 192, 31, 31),         // couleur la plus claire
			1000, 1000,                                  // duree de vie min / max
			0,                                        // angle max d'ecart / direction prevue
			irr::core::dimension2df(13.0f, 13.0f),      // taille minimum
			irr::core::dimension2df(13.0f, 13.0f)       // taille maximum
		);
		particleSystem->setEmitter(emitter);
		emitter->drop();
		particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}
	this->playExplosionSound();
}

#include <iostream>
#include <unistd.h>
#include "Audio.hpp"

void IndieStudio::Bomb::playExplosionSound(void) noexcept
{
	this->_sound.playSound(true);
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
	this->explosion(this->_bomb->getPosition());
	this->_sceneManager->addToDeletionQueue(this->_bomb);
	this->_sceneManager->addToDeletionQueue(this->_particle);
	this->_sound.playSound(true);
	this->_alive = false;
}

bool IndieStudio::Bomb::getAlive() const noexcept
{
	return (this->_alive);
}