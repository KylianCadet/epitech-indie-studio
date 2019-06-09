/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#include "Game.hpp"
#include <thread>

IndieStudio::Game::Game(IndieStudio::IGraphical &graphical, Render &render) :
	_graphical(graphical),
	_render(render),
	_map(IndieStudio::Map(graphical, "64", SIZE_MAP_X, SIZE_MAP_Y, DENSITY_BRICK, DENSITY_WALL)),
	_bonus(IndieStudio::Bonus(graphical, DENSITY_BONUS)),
	_bombSound(std::shared_ptr<IndieStudio::Audio>(new IndieStudio::Audio("assets/bomb/bomb.wav")))
{
	this->_bonus.addFreePosition(this->_map.getFreePos());
	this->_map.clearFreePos();
	this->_bonus.create_Bonus();
	this->createCharacters();
	this->setMapCollision();
	this->setCameraPosition(SIZE_MAP_X < 6 ? 6 : SIZE_MAP_X, SIZE_MAP_Y < 6 ? 6 : SIZE_MAP_Y);
}

IndieStudio::Game::~Game()
{
}

void IndieStudio::Game::threadPool()
{
	// for (int i = 0; i != 4; i++) {
	// 	_th.emplace_back(std::thread(IndieStudio::IaMouvement::Ia,_characterVec[i], this->_bombVec, this->_map.getFree_Absolute_Pos())).detach();
	// }
	// 	for (auto i = _th.begin(); i != _th.end(); i++) {
	// 	i->join();
	// }
	// auto test = std::bind(&IndieStudio::IaMouvement::Ia, this->_bombVec, this->_map.getFree_Absolute_Pos());
	// //std::thread p1(test);
	// t1.detach();
}

void IndieStudio::Game::setCameraPosition(int x, int y) noexcept
{
	float div = ((x + y) / 2) * 32;
	auto cube = this->_map.getFloorCube().at(this->_map.getFloorCube().size() - 1);
	this->_graphical.setCameraPosition(IndieStudio::Pos{-10, div, cube->getPosition()._z / 2});
	this->_graphical.setCameraTarget(IndieStudio::Pos{cube->getPosition()._x / 2, 0, cube->getPosition()._z / 2});
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
		IndieStudio::Character(this->_graphical, "Yoshi", "assets/characters/yoshi/tris.md2", "assets/characters/yoshi/yoshi.pcx", "assets/characters/yoshi/death.wav", false, 'i', 'j', 'k', 'l', 'o', Pos_Vec.at(0)));
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "Sponge Bob", "assets/characters/spongebob/tris.md2", "assets/characters/spongebob/bob.pcx", "assets/characters/spongebob/death.wav", false, 'w', 'x', 'c', 'v', 'b', Pos_Vec.at(1)));
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "Eric Cartman", "assets/characters/eric_c/tris.md2", "assets/characters/eric_c/eric.pcx", "assets/characters/eric_c/death.wav", false, 't', 'f', 'g', 'h', 'y', Pos_Vec.at(2)));
	this->_characterVec.push_back(
		IndieStudio::Character(this->_graphical, "Fox", "assets/characters/starfox/tris.md2", "assets/characters/starfox/starfox.pcx", "assets/characters/starfox/death.wav", false, 'z', 'q', 's', 'd', 'e', Pos_Vec.at(3)));
	IndieStudio::IaMouvement a, b, c, d;
	this->_iaMouvement.push_back(a);
	this->_iaMouvement.push_back(b);
	this->_iaMouvement.push_back(c);
	this->_iaMouvement.push_back(d);
}

std::size_t IndieStudio::Game::getAliveCharacter() const noexcept
{
	std::size_t alive = 0;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		if (character_it->getDeath() == false)
			alive++;
	return (alive);
}

#define WIN_ANIM 8
#define DOWN_ROT 180

void IndieStudio::Game::playEnding()
{
	IndieStudio::Character *winner;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		if (character_it->getDeath() == false)
			winner = character_it.base();
	winner->getEntity()->setRotation(IndieStudio::Pos(0, DOWN_ROT, 0));
	winner->getEntity()->setAnimation(WIN_ANIM);
}

void IndieStudio::Game::render() noexcept
{
	if (this->getAliveCharacter() == 1 && this->_win == false) {
		this->_win = true;
		this->playEnding();
	} else if (this->_win == false)
		this->moveCharacter();
	this->bonusRender();
	this->checkEvent();
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
		if (bomb_it->get()->getTotalDeath() == true) {
			this->_bombVec.erase(bomb_it);
			this->checkDeleteBomb();
			return;
		}
}

void IndieStudio::Game::moveCharacter() noexcept
{
	bool isMoving = false;
	int ia_Id = 0;
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, ia_Id++) {
		if (character_it->getDeath() == true)
			continue;
		IndieStudio::Pos newPos = character_it->getEntity()->getPosition();
		if (character_it->getBot() == true) {
			// auto test = new IndieStudio::IaMouvement();
			// std::thread([this, test, character_it](){
			// 	while (character_it->getPosition()._x != 80)
			// 		character_it->setMovingUp(true);
			// 	character_it->setMovingUp(false);
			// 	//test->Ia(*character_it, this->_bombVec, this->_map.getFree_Absolute_Pos());
			// }).detach();
			// if (character_it->th == true) {
			// 	character_it->th = false;
			// 	std::thread([this, ia_Id, character_it](){
			this->_iaMouvement[ia_Id].Ia(*character_it, this->_bombVec, this->_map.getFree_Absolute_Pos());
			// character_it->th = true;
			// }).detach();
			// }
		}
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
				std::shared_ptr<IndieStudio::Bomb> newBomb(new IndieStudio::Bomb(this->_graphical, character_it->getEntity()->getPosition(), character_it->getBombSize(), this->_map, this->_bombVec, this->_characterVec, this->_bombSound));
				this->_bombVec.push_back(newBomb);
				character_it->set_Bomb_Current(character_it->get_Bomb_Current() + 1);
				std::thread([character_it, newBomb]() {
					newBomb->startCountdown();
					character_it->set_Bomb_Current(character_it->get_Bomb_Current() - 1);
				})
					.detach();
			}
		}
		character_it->setBonus(this->_bonus.getBonus(character_it->getPosition(), this->_bonus.getRedBonusSpeed()), this->_bonus.getBonus(character_it->getPosition(), this->_bonus.getRedBonusFire()), this->_bonus.getBonus(character_it->getPosition(), this->_bonus.getRedBonusBomb()));
		character_it->setBonus(this->_bonus.getMalus(character_it->getPosition(), this->_bonus.getBlueBonusSpeed()), this->_bonus.getMalus(character_it->getPosition(), this->_bonus.getBlueBonusFire()), this->_bonus.getMalus(character_it->getPosition(), this->_bonus.getBlueBonusBomb()));
	}
}

void IndieStudio::Game::reset(void) noexcept
{
	auto posVec = _map.get_Position_Start();
	std::size_t i = 0;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, i++)
		character_it->setPosition(posVec.at(i));
}

void IndieStudio::Game::checkEvent(void) noexcept
{
	std::vector<bool> ActionKey;
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		ActionKey.push_back(this->_event._key[static_cast<IndieStudio::Key>(character_it->getActionKey())]);

	this->_event = this->_graphical.getEvent();

	if (this->_event._key[IndieStudio::Key::ESC] == true)
		this->_render = PAUSE_MENU;

	if (this->_event._key[IndieStudio::Key::RETURN] == true && this->_win == true) {
		this->_isOver = true;
		this->_render = MAIN_MENU;
	}
	auto ActionKey_it = ActionKey.begin();
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, ActionKey_it++) {
		if (character_it->getDeath() == true)
			continue;
		character_it->setMovingUp(this->_event._key[static_cast<IndieStudio::Key>(character_it->getUpKey())]);
		character_it->setMovingLeft(this->_event._key[static_cast<IndieStudio::Key>(character_it->getLeftKey())]);
		character_it->setMovingDown(this->_event._key[static_cast<IndieStudio::Key>(character_it->getDownKey())]);
		character_it->setMovingRight(this->_event._key[static_cast<IndieStudio::Key>(character_it->getRightKey())]);
		if (this->_event._key[static_cast<IndieStudio::Key>(character_it->getActionKey())] == true && *ActionKey_it == false)
			character_it->setDoingAction(true);
	}
}

void IndieStudio::Game::bonusRender() noexcept
{
	this->_bonus.addFreePosition(this->_map.getFreePos());
	this->_map.clearFreePos();
	if (this->_bonus_bool == false) {
		this->_bonus_bool = true;
		this->_bonus.create_Bonus();
		std::thread([this]() {
			std::this_thread::sleep_for(std::chrono::seconds(7));
			this->_bonus_bool = false;
		})
			.detach();
	}
	this->_bonus.animeBonus();
}

bool IndieStudio::Game::isOver(void) const noexcept
{
	return (this->_isOver);
}

void IndieStudio::Game::destroy(void) noexcept
{
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		this->_graphical.deleteEntity(character_it->getEntity());
	auto brickVec = this->_map.getBrickCube();
	for (auto brick_it = brickVec.begin(); brick_it != brickVec.end(); brick_it++)
		this->_graphical.deleteEntity(brick_it[0]);
	auto wallVec = this->_map.getWallCube();
	for (auto wall_it = wallVec.begin(); wall_it != wallVec.end(); wall_it++)
		this->_graphical.deleteEntity(wall_it[0]);
	auto floorVec = this->_map.getFloorCube();
	for (auto floor_it = floorVec.begin(); floor_it != floorVec.end(); floor_it++)
		this->_graphical.deleteEntity(floor_it[0]);
}