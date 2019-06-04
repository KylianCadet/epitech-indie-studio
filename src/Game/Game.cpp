/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#include "Game.hpp"
#include <thread>

IndieStudio::Game::Game(IndieStudio::IGraphical &graphical, Render &render) :
	_graphical(graphical), _render(render), _map(IndieStudio::Map(graphical, "64", 16, 17, 50, 100))
{
	this->createCharacters();
	this->setMapCollision();
}

IndieStudio::Game::~Game()
{
}

void IndieStudio::Game::setMapCollision() noexcept
{
	auto brick_vec = this->_map.getBrickCube();
	auto wall_vec = this->_map.getWallCube();

	for (auto brick_it = brick_vec.begin(); brick_it != brick_vec.end(); brick_it++)
		this->createCubeColision(*brick_it);
	for (auto wall_it = wall_vec.begin(); wall_it != wall_vec.end(); wall_it++)
		this->createCubeColision(*wall_it);
}

void IndieStudio::Game::createCubeColision(IndieStudio::IEntity *cube) noexcept
{
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		IndieStudio::IEntity *entity = character_it->getEntity();
		this->_graphical.createCollision(cube, entity);
	}
}

void IndieStudio::Game::createCharacters() noexcept
{
	auto Pos_Vec = _map.get_Position_Start();
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/yoshi/tris.md2", "assets/characters/yoshi/yoshi.pcx", "assets/characters/yoshi/death.wav", false, 'i', 'j', 'k', 'l', 'o', Pos_Vec.at(0)));
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/spongebob/tris.md2", "assets/characters/spongebob/bob.pcx", "assets/characters/spongebob/death.wav", false, 'w', 'x', 'c', 'v', 'b', Pos_Vec.at(1)));
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/eric_c/tris.md2", "assets/characters/eric_c/eric.pcx", "assets/characters/eric_c/death.wav", false, 't', 'f', 'g', 'h', 'y', Pos_Vec.at(2)));
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "assets/characters/starfox/tris.md2", "assets/characters/starfox/starfox.pcx", "assets/characters/starfox/death.wav", false, 'z', 'q', 's', 'd', 'e', Pos_Vec.at(3)));
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

void IndieStudio::Game::checkDeleteBomb() noexcept
{
	for (auto bomb_it = this->_bombVec.begin(); bomb_it != this->_bombVec.end(); bomb_it++)
		if (bomb_it->get()->getAlive() == false) {
			this->_bombVec.erase(bomb_it);
			this->checkDeleteBomb();
			return;
		}
}

void IndieStudio::Game::moveCharacter() noexcept
{
	bool isMoving = false;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		IndieStudio::Pos newPos = character_it->getEntity()->getPosition();
		isMoving = character_it->getIsMoving();
		checkMove(character_it, character_it->getMovingUp(), newPos._x, UP_ROT, true);
		checkMove(character_it, character_it->getMovingDown(), newPos._x, DOWN_ROT, false);
		checkMove(character_it, character_it->getMovingLeft(), newPos._z, LEFT_ROT, true);
		checkMove(character_it, character_it->getMovingRight(), newPos._z, RIGHT_ROT, false);
		if (character_it->getEntity()->getPosition() != newPos && isMoving == false)
			character_it->getEntity()->setAnimation(RUN);
		else if (character_it->getEntity()->getPosition() == newPos && isMoving == true) {
			character_it->setIsMoving(false);
			character_it->getEntity()->setAnimation(STAND);
		}
		character_it->getEntity()->setPosition(newPos);
		if (character_it->getDoingAction() == true) {
			character_it->setDoingAction(false);
			this->checkDeleteBomb();
			if (character_it->getBombMax() > character_it->get_Bomb_Current()) {
				std::shared_ptr<IndieStudio::Bomb> newBomb(new IndieStudio::Bomb(this->_graphical, character_it->getEntity()->getPosition(), character_it->getBombSize(), this->_map, this->_bombVec, this->_characterVec));
				this->_bombVec.push_back(newBomb);
				character_it->set_Bomb_Current(character_it->get_Bomb_Current() + 1);
				std::thread([character_it, newBomb]() {
					newBomb->startCountdown();
					character_it->set_Bomb_Current(character_it->get_Bomb_Current() - 1);
				}).detach();
			}
		}
	}
}

void IndieStudio::Game::checkEvent(void) noexcept
{
	std::vector<bool> ActionKey;
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		ActionKey.push_back(this->_event._key[static_cast<IndieStudio::Key>(character_it->getActionKey())]);

	this->_event = this->_graphical.getEvent();

	if (this->_event._key[IndieStudio::Key::ESC] == true)
		this->_render = PAUSE_MENU;

	auto ActionKey_it = ActionKey.begin();
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, ActionKey_it++) {
		character_it->setMovingUp(this->_event._key[static_cast<IndieStudio::Key>(character_it->getUpKey())]);
		character_it->setMovingLeft(this->_event._key[static_cast<IndieStudio::Key>(character_it->getLeftKey())]);
		character_it->setMovingDown(this->_event._key[static_cast<IndieStudio::Key>(character_it->getDownKey())]);
		character_it->setMovingRight(this->_event._key[static_cast<IndieStudio::Key>(character_it->getRightKey())]);
		if (this->_event._key[static_cast<IndieStudio::Key>(character_it->getActionKey())] == true && *ActionKey_it == false)
			character_it->setDoingAction(true);
	}
}