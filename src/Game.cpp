/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#include "Game.hpp"

IndieStudio::Game::Game(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver) : _device(device), _sceneManager(sceneManager), _driver(driver)
{
	this->createCharacters();
	this->_CharacterEventListener = new IndieStudio::CharacterEventListener(this->_characterVec);
	this->_device->setEventReceiver(this->_CharacterEventListener);
	this->createCubes();
	this->_sceneManager->addCameraSceneNode(
		0,
		irr::core::vector3df(-100, 300, 0),
		irr::core::vector3df(100, 0, 0)
	);
}

IndieStudio::Game::~Game()
{
	delete this->_CharacterEventListener;
}

void IndieStudio::Game::createCubeColision(irr::scene::IMeshSceneNode *cube) noexcept
{
	/* CREATE TRIANGLE SELECTOR FOR THE CREATED CUBE */
	irr::scene::IMetaTriangleSelector* metaSelector = this->_sceneManager->createMetaTriangleSelector();
	irr::scene::ITriangleSelector* selector = 0;
	selector = this->_sceneManager->createTriangleSelectorFromBoundingBox(cube);
	cube->setTriangleSelector(selector);
	metaSelector->addTriangleSelector(selector);

	/* CREATE ANIMATOR RESPONSE FOR EACH OF THE CHARACTERS */
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		irr::scene::ISceneNode *node = character_it->getMesh();
		irr::scene::ISceneNodeAnimatorCollisionResponse* anim = this->_sceneManager->createCollisionResponseAnimator(
			metaSelector,
			node,
			irr::core::vector3df(20, 20, 20),
			irr::core::vector3df(0, 0, 0)
		);
		node->addAnimator(anim);
		anim->drop();
	}
}

#define CUBE_SIDE 30.f
void IndieStudio::Game::createCubes() noexcept
{
	for (int i = 0; i != 10; i++) {
		irr::scene::IMeshSceneNode *cube =
			this->_sceneManager->addCubeSceneNode(
				CUBE_SIDE,
				0,
				-1,
				irr::core::vector3df(
					0.0f,
					0.0f,
					(i * CUBE_SIDE) + 100.0f
				)
			);
		cube->setMaterialType(irr::video::E_MATERIAL_TYPE::EMT_SOLID);
		cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
		this->createCubeColision(cube);
		this->_cubeVec.push_back(cube);
	}
}

void IndieStudio::Game::createCharacters() noexcept
{
	this->_characterVec.push_back(
		IndieStudio::Character(this->_sceneManager, this->_driver, "assets/characters/yoshi/tris.md2", "assets/characters/yoshi/yoshi.pcx", "assets/characters/yoshi/death.wav", false, 'i', 'j', 'k', 'l', 'o')
	);
	this->_characterVec.push_back(
		IndieStudio::Character(this->_sceneManager, this->_driver, "assets/characters/spongebob/tris.md2", "assets/characters/spongebob/bob.pcx", "assets/characters/spongebob/death.wav", false, 'w', 'x', 'c', 'v', 'b')
	);
	this->_characterVec.push_back(
		IndieStudio::Character(this->_sceneManager, this->_driver, "assets/characters/eric_c/tris.md2", "assets/characters/eric_c/eric.pcx", "assets/characters/eric_c/death.wav", false, 't', 'f', 'g', 'h', 'y')
	);
	this->_characterVec.push_back(
		IndieStudio::Character(this->_sceneManager, this->_driver, "assets/characters/starfox/tris.md2", "assets/characters/starfox/starfox.pcx", "assets/characters/starfox/death.wav", false, 'z', 'q', 's', 'd', 'e')
	);
}

void IndieStudio::Game::render() noexcept
{
	this->_sceneManager->getActiveCamera()->setTarget(irr::core::vector3df(this->_rot_x, this->_rot_y, this->_rot_z));
	this->_rot_x = cos(this->_counter) * 3;
	this->_rot_z = sin(this->_counter) * 3;
	this->_CharacterEventListener->moveCharacter();
	this->_sceneManager->drawAll();
	this->_counter += 0.05;
}