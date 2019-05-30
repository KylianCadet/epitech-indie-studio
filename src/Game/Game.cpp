/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#include "Game.hpp"

IndieStudio::Game::Game(IndieStudio::IGraphical &graphical, Render &render) : _graphical(graphical), _render(render)
{
	this->_map = std::unique_ptr<IndieStudio::Map>(new IndieStudio::Map(this->_graphical));
	this->createCharacters();
	this->set_Map_Collision();
}

IndieStudio::Game::~Game()
{
}

void IndieStudio::Game::set_Map_Collision() noexcept
{
	std::map<std::string, std::vector<IndieStudio::IEntity *>> cube;
	cube = _map->get_All_Cube();
	for (auto i = cube["Destruc"].begin(); i != cube["Destruc"].end(); i++)
		this->createCubeColision(*i);
	for (auto i = cube["Floor"].begin(); i != cube["Floor"].end(); i++)
		this->createCubeColision(*i);
	for (auto i = cube["Wall"].begin(); i != cube["Wall"].end(); i++)
		this->createCubeColision(*i);
}


void IndieStudio::Game::createCubeColision(IndieStudio::IEntity *cube) noexcept
{
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		IndieStudio::IEntity *entity = character_it->getEntity();
		this->_graphical.createColision(cube, entity);
	}
}

void IndieStudio::Game::createCharacters() noexcept
{
	auto Pos_Vec = _map->get_Position_Start();
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/yoshi/tris.md2", "assets/characters/yoshi/yoshi.pcx", "assets/characters/yoshi/death.wav", false, 'i', 'j', 'k', 'l', 'o', Pos_Vec.at(0))
	);
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/spongebob/tris.md2", "assets/characters/spongebob/bob.pcx", "assets/characters/spongebob/death.wav", false, 'w', 'x', 'c', 'v', 'b', Pos_Vec.at(1))
	);
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/eric_c/tris.md2", "assets/characters/eric_c/eric.pcx", "assets/characters/eric_c/death.wav", false, 't', 'f', 'g', 'h', 'y', Pos_Vec.at(2))
	);
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/starfox/tris.md2", "assets/characters/starfox/starfox.pcx", "assets/characters/starfox/death.wav", false, 'z', 'q', 's', 'd', 'e', Pos_Vec.at(3))
	);
}

void IndieStudio::Game::render() noexcept
{
	if (this->_render == GAME) {
		this->moveCharacter();
		this->checkEvent();
	}
	this->_graphical.drawScene();
}

int IndieStudio::Game::getRenderStatus(void) const noexcept
{
	return this->_renderStatus;
}

void IndieStudio::Game::setRenderStatus(int status) noexcept
{
	this->_renderStatus = status;
}

#define UP_ROT 0
#define DOWN_ROT 180
#define RIGHT_ROT 90
#define LEFT_ROT 270

void checkMove(std::vector<IndieStudio::Character>::iterator character_it, bool isMoving, float &coordinate, int rotation, bool sign)
{
	if (isMoving == true) {
		if (sign)
			coordinate += character_it->getSpeed();
		else
			coordinate -= character_it->getSpeed();
		character_it->getEntity()->setRotation(IndieStudio::Pos(0, rotation, 0));
		character_it->setIsMoving(true);
	}
}

#include "Bomb.hpp"
#define RUN 1
#define STAND 0

void IndieStudio::Game::moveCharacter() noexcept
{
	bool isMoving = false;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		IndieStudio::Pos v = character_it->getEntity()->getPosition();
		isMoving = character_it->getIsMoving();
		checkMove(character_it, character_it->getMovingUp(),v._x, UP_ROT, true);
		checkMove(character_it, character_it->getMovingDown(),v._x, DOWN_ROT, false);
		checkMove(character_it, character_it->getMovingLeft(),v._z, LEFT_ROT, true);
		checkMove(character_it, character_it->getMovingRight(),v._z, RIGHT_ROT, false);
		if (character_it->getEntity()->getPosition() != v && isMoving == false)
			character_it->getEntity()->setAnimation(RUN);
		else if (character_it->getEntity()->getPosition() == v && isMoving == true) {
			character_it->setIsMoving(false);
			character_it->getEntity()->setAnimation(STAND);
		}
		character_it->getEntity()->setPosition(v);
		if (character_it->getDoingAction() == true) {
			character_it->getDeathSound()->playSound();
		}
		if (character_it->getDoingAction() == true && this->_keyPressed == false) {
			this->_keyPressed = true;
			character_it->checkDeleteBomb();
			if ((unsigned)character_it->getBombNb() > character_it->getLaidBomb()) {
				IndieStudio::Bomb *bomb = new IndieStudio::Bomb(this->_graphical, character_it->getEntity()->getPosition(), character_it->getBombSize());
				character_it->addBomb(bomb);
			}
		}
	}
}

void IndieStudio::Game::checkEvent(void) noexcept
{
	IndieStudio::IEvent event = this->_graphical.getEvent();

	if (event._key[IndieStudio::Key::ESC] == true)
		this->_render = PAUSE_MENU;
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		character_it->setMovingUp(event._key[static_cast<IndieStudio::Key>(character_it->getUpKey())]);
		character_it->setMovingLeft(event._key[static_cast<IndieStudio::Key>(character_it->getLeftKey())]);
		character_it->setMovingDown(event._key[static_cast<IndieStudio::Key>(character_it->getDownKey())]);
		character_it->setMovingRight(event._key[static_cast<IndieStudio::Key>(character_it->getRightKey())]);
		character_it->setDoingAction(event._key[static_cast<IndieStudio::Key>(character_it->getActionKey())]);
		if (event._key[static_cast<IndieStudio::Key>(character_it->getActionKey())] == false)
			this->_keyPressed = false;
	}
}