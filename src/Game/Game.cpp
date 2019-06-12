/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#include "Game.hpp"
#include <thread>

IndieStudio::Game::Game(IndieStudio::IGraphical &graphical, Render &render, const IndieStudio::Config *config) :
	_graphical(graphical),
	_render(render),
	_map(IndieStudio::Map(graphical, "64", SIZE_MAP_X, SIZE_MAP_Y, DENSITY_BRICK, DENSITY_WALL)),
	_bonus(IndieStudio::Bonus(graphical, DENSITY_BONUS)),
	_bombSound(std::shared_ptr<IndieStudio::Audio>(new IndieStudio::Audio("assets/bomb/bomb.wav"))),
	_config(config)
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
		IndieStudio::IEntity *entity = character_it->get()->getEntity();
		this->_graphical.createCollision(cube, entity);
	}
}

void IndieStudio::Game::createCharacters() noexcept
{
	auto Pos_Vec = _map.get_Position_Start();
	std::list<std::string> players = {"Yoshi", "Sponge Bob", "Eric Cartman", "Fox"};
	bool player2 = false;

	if (this->_config->getMode() == Mode::SOLO)
		player2 = true;
	for (auto player_it = players.begin(); player_it != players.end(); player_it++)
		if (*player_it == this->_config->getPlayer1Skin() || *player_it == this->_config->getPlayer2Skin())
			player_it = players.erase(player_it);
	this->_characterVec.push_back(std::shared_ptr<IndieStudio::Character>(new IndieStudio::Character(this->_graphical, this->_config->getPlayer1Skin(), false, Pos_Vec.at(0), this->_config->getKeybinds1())));
	this->_characterVec.push_back(std::shared_ptr<IndieStudio::Character>(new IndieStudio::Character(this->_graphical, this->_config->getPlayer2Skin(), player2, Pos_Vec.at(1), this->_config->getKeybinds2())));
	if (this->_config->getMode() != Mode::DUEL) {
		this->_characterVec.push_back(std::shared_ptr<IndieStudio::Character>(new IndieStudio::Character(this->_graphical, *players.begin(), true, Pos_Vec.at(2))));
		players.pop_front();
		this->_characterVec.push_back(std::shared_ptr<IndieStudio::Character>(new IndieStudio::Character(this->_graphical, *players.begin(), true, Pos_Vec.at(3))));
	}
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
		if (character_it->get()->getDeath() == false)
			alive++;
	return (alive);
}

#define WIN_ANIM 8
#define DOWN_ROT 180

void IndieStudio::Game::playEnding()
{
	std::shared_ptr<IndieStudio::Character> *winner;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		if (character_it->get()->getDeath() == false)
			winner = character_it.base();
	winner->get()->getEntity()->setRotation(IndieStudio::Pos(0, DOWN_ROT, 0));
	winner->get()->getEntity()->setAnimation(WIN_ANIM);
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

void checkMove(std::vector<std::shared_ptr<IndieStudio::Character>>::iterator character_it, bool isMoving, float &coordinate, int rotation, bool sign)
{
	if (isMoving == true) {
		if (sign)
			coordinate += character_it->get()->getSpeed();
		else
			coordinate -= character_it->get()->getSpeed();
		character_it->get()->getEntity()->setRotation(IndieStudio::Pos(0, rotation, 0));
		character_it->get()->setIsMoving(true);
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
	int id_IA = 0;
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, id_IA++) {
		if (character_it->get()->getBot() == true) {
			this->_iaMouvement[id_IA].Ia(*character_it, this->_bombVec, this->_map.getFree_Absolute_Pos());
		}
	}
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++) {
		if (character_it->get()->getDeath() == true)
			continue;
		IndieStudio::Pos newPos = character_it->get()->getEntity()->getPosition();
		isMoving = character_it->get()->getIsMoving();
		checkMove(character_it, character_it->get()->getMovingUp(), newPos._x, UP_ROT, true);
		checkMove(character_it, character_it->get()->getMovingDown(), newPos._x, DOWN_ROT, false);
		checkMove(character_it, character_it->get()->getMovingLeft(), newPos._z, LEFT_ROT, true);
		checkMove(character_it, character_it->get()->getMovingRight(), newPos._z, RIGHT_ROT, false);
		if (character_it->get()->getEntity()->getPosition() != newPos && isMoving == false)
			character_it->get()->getEntity()->setAnimation(RUN);
		else if (character_it->get()->getEntity()->getPosition() == newPos && isMoving == true) {
			character_it->get()->setIsMoving(false);
			character_it->get()->getEntity()->setAnimation(STAND);
		}
		character_it->get()->getEntity()->setPosition(newPos);
		if (character_it->get()->getDoingAction() == true) {
			character_it->get()->setDoingAction(false);
			this->checkDeleteBomb();
			if (character_it->get()->getBombMax() > character_it->get()->get_Bomb_Current()) {
				std::shared_ptr<IndieStudio::Bomb> newBomb(new IndieStudio::Bomb(this->_graphical, character_it->get()->getEntity()->getPosition(), character_it->get()->getBombSize(), this->_map, this->_bombVec, this->_characterVec, this->_bombSound));
				this->_bombVec.push_back(newBomb);
				character_it->get()->set_Bomb_Current(character_it->get()->get_Bomb_Current() + 1);
				std::thread([character_it, newBomb]() {
					newBomb->startCountdown();
					character_it->get()->set_Bomb_Current(character_it->get()->get_Bomb_Current() - 1);
				})
					.detach();
			}
		}
		character_it->get()->setBonus(this->_bonus.getBonus(character_it->get()->getPosition(), this->_bonus.getRedBonusSpeed()), this->_bonus.getBonus(character_it->get()->getPosition(), this->_bonus.getRedBonusFire()), this->_bonus.getBonus(character_it->get()->getPosition(), this->_bonus.getRedBonusBomb()));
		character_it->get()->setBonus(this->_bonus.getMalus(character_it->get()->getPosition(), this->_bonus.getBlueBonusSpeed()), this->_bonus.getMalus(character_it->get()->getPosition(), this->_bonus.getBlueBonusFire()), this->_bonus.getMalus(character_it->get()->getPosition(), this->_bonus.getBlueBonusBomb()));
	}
}

void IndieStudio::Game::reset(void) noexcept
{
	auto posVec = _map.get_Position_Start();
	std::size_t i = 0;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, i++)
		character_it->get()->setPosition(posVec.at(i));
}

void IndieStudio::Game::checkEvent(void) noexcept
{
	std::vector<bool> ActionKey;
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		ActionKey.push_back(this->_event._key[static_cast<IndieStudio::Key>(character_it->get()->getActionKey())]);

	this->_event = this->_graphical.getEvent();

	if (this->_event._key[IndieStudio::Key::ESC] == true)
		this->_render = PAUSE_MENU;

	if (this->_event._key[IndieStudio::Key::RETURN] == true && this->_win == true) {
		this->_isOver = true;
		this->_render = MAIN_MENU;
	}
	auto ActionKey_it = ActionKey.begin();
	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++, ActionKey_it++) {
		if (character_it->get()->getDeath() == true || character_it->get()->getBot() == true)
			continue;
		character_it->get()->setMovingUp(this->_event._key[static_cast<IndieStudio::Key>(character_it->get()->getUpKey())]);
		character_it->get()->setMovingLeft(this->_event._key[static_cast<IndieStudio::Key>(character_it->get()->getLeftKey())]);
		character_it->get()->setMovingDown(this->_event._key[static_cast<IndieStudio::Key>(character_it->get()->getDownKey())]);
		character_it->get()->setMovingRight(this->_event._key[static_cast<IndieStudio::Key>(character_it->get()->getRightKey())]);
		if (this->_event._key[static_cast<IndieStudio::Key>(character_it->get()->getActionKey())] == true && *ActionKey_it == false)
			character_it->get()->setDoingAction(true);
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
		this->_graphical.deleteEntity(character_it->get()->getEntity());
	auto brickVec = this->_map.getBrickCube();
	for (auto brick_it = brickVec.begin(); brick_it != brickVec.end(); brick_it++)
		this->_graphical.deleteEntity(brick_it[0]);
	auto wallVec = this->_map.getWallCube();
	for (auto wall_it = wallVec.begin(); wall_it != wallVec.end(); wall_it++)
		this->_graphical.deleteEntity(wall_it[0]);
	auto floorVec = this->_map.getFloorCube();
	for (auto floor_it = floorVec.begin(); floor_it != floorVec.end(); floor_it++)
		this->_graphical.deleteEntity(floor_it[0]);
	this->_bonus.destroy_Bonus();
}