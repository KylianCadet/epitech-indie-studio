/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "Audio.hpp"
#include "IGraphical.hpp"
#include <iostream>
#include <list>

namespace IndieStudio {
	class Character {
	public:
		Character(IndieStudio::IGraphical &graphical, std::string meshPath, std::string texturePath, std::string deathSoundPath, bool bot, char up = ' ', char left = ' ', char down = ' ', char right = ' ', char action = ' ', IndieStudio::Pos position = IndieStudio::Pos(0, 0, 0));
		~Character();
		char getUpKey() const noexcept;
		char getLeftKey() const noexcept;
		char getDownKey() const noexcept;
		char getRightKey() const noexcept;
		char getActionKey() const noexcept;

		void setMovingUp(bool) noexcept;
		void setMovingLeft(bool) noexcept;
		void setMovingDown(bool) noexcept;
		void setMovingRight(bool) noexcept;
		void setDoingAction(bool) noexcept;

		bool getMovingUp() const noexcept;
		bool getMovingLeft() const noexcept;
		bool getMovingDown() const noexcept;
		bool getMovingRight() const noexcept;
		bool getDoingAction() const noexcept;

		bool getIsMoving() const noexcept;
		void setIsMoving(bool) noexcept;

		float getSpeed() const noexcept;
		void setSpeed(float) noexcept;

		int get_Bomb_Current() const noexcept;
		void set_Bomb_Current(int) noexcept;

		int getBombSize() const noexcept;
		void setBombSize(int) noexcept;

		int getBombMax() const noexcept;
		void setBombMax(int) noexcept;

		IndieStudio::IEntity *getEntity() noexcept;
		void playDeathSound() noexcept;

		void setPosition(IndieStudio::Pos) noexcept;
		IndieStudio::Pos getPosition() noexcept;

		IndieStudio::Pos getSpawnPos() const noexcept;

	private:
		IndieStudio::IGraphical &_graphical;
		IndieStudio::IEntity *_model;
		std::shared_ptr<IndieStudio::Audio> _deathSound;
		IndieStudio::Pos _spawnPos;

		bool _bot;
		char _up;
		char _left;
		char _down;
		char _right;
		char _action;
		bool _movingUp = false;
		bool _movingLeft = false;
		bool _movingDown = false;
		bool _movingRight = false;
		bool _doingAction = false;
		bool _isMoving = false;
		float _speed = 2.5f;
		int _bomb_Max = 2;
		int _bomb_current = 0;
		int _bombSize = 1;
	};
}; // namespace IndieStudio

#endif