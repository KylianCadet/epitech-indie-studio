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
	this->createCubes();
	this->_sceneManager->addCameraSceneNode(
		0,
		irr::core::vector3df(-100, 300, 0),
		irr::core::vector3df(100, 0, 0)
	);
}

IndieStudio::Game::~Game()
{
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
	for (auto & character_it : this->_characterVec) {
		irr::scene::ISceneNode *node = character_it.getMesh();
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
	this->moveCharacter();
	this->_sceneManager->drawAll();
	this->_counter += 0.05;
}

bool IndieStudio::Game::hasRender(void) const noexcept
{
	return (true);
}

void IndieStudio::Game::setEventReceiver(void) noexcept
{
	this->_device->setEventReceiver(this);
}

#define UP_ROT 0
#define DOWN_ROT 180
#define RIGHT_ROT 90
#define LEFT_ROT 270

void checkMove(std::vector<IndieStudio::Character>::iterator character_it, bool isMoving,irr::f32 &coordinate, int rotation, bool sign)
{
	if (isMoving == true) {
		if (sign)
			coordinate += character_it->getSpeed();
		else
			coordinate -= character_it->getSpeed();
		character_it->getMesh()->setRotation(irr::core::vector3df(0, rotation, 0));
		character_it->setIsMoving(true);
	}
}

#include "Bomb.hpp"

void IndieStudio::Game::moveCharacter() noexcept
{
	bool isMoving = false;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		irr::core::vector3df v = character_it->getMesh()->getPosition();
		isMoving = character_it->getIsMoving();
		checkMove(character_it, character_it->getMovingUp(),v.X, UP_ROT, true);
		checkMove(character_it, character_it->getMovingDown(),v.X, DOWN_ROT, false);
		checkMove(character_it, character_it->getMovingLeft(),v.Z, LEFT_ROT, true);
		checkMove(character_it, character_it->getMovingRight(),v.Z, RIGHT_ROT, false);
		if (character_it->getMesh()->getPosition() != v && isMoving == false)
			character_it->getMesh()->setMD2Animation(irr::scene::EMAT_RUN);
		else if (character_it->getMesh()->getPosition() == v && isMoving == true) {
			character_it->setIsMoving(false);
			character_it->getMesh()->setMD2Animation(irr::scene::EMAT_STAND);
		}
		character_it->getMesh()->setPosition(v);
		if (character_it->getDoingAction() == true) {
			character_it->getDeathSound()->playSound();
		}
		if (character_it->getDoingAction() == true && this->_keyPressed == false) {
			character_it->checkDeleteBomb();
			if ((unsigned)character_it->getBombNb() > character_it->getLaidBomb()) {
				IndieStudio::Bomb *bomb = new IndieStudio::Bomb(this->_sceneManager, this->_driver, character_it->getMesh()->getPosition(), character_it->getBombSize());
				character_it->addBomb(bomb);
				this->_keyPressed = true;
			}
		}
	}
}

bool IndieStudio::Game::OnEvent(const irr::SEvent &event)
{
	bool ret = false;

	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
			if (event.KeyInput.Key == character_it->getUpKey()) {
				character_it->setMovingUp(event.KeyInput.PressedDown);
				ret = true;
			}
			if (event.KeyInput.Key == character_it->getLeftKey()) {
				character_it->setMovingLeft(event.KeyInput.PressedDown);
				ret = true;
			}
			if (event.KeyInput.Key == character_it->getDownKey()) {
				character_it->setMovingDown(event.KeyInput.PressedDown);
				ret = true;
			}
			if (event.KeyInput.Key == character_it->getRightKey()) {
				character_it->setMovingRight(event.KeyInput.PressedDown);
				ret = true;
			}
			if (event.KeyInput.Key == character_it->getActionKey()) {
				if (event.KeyInput.PressedDown == false)
					this->_keyPressed = false;
				character_it->setDoingAction(event.KeyInput.PressedDown);
				ret = true;
			}
		}
		return (ret);
	}
	return (false);
}