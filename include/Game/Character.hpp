/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "Audio.hpp"
#include "Bomb.hpp"
#include <vector>
#include <irrlicht.h>
#include <iostream>

namespace IndieStudio {
	class Character {
		public:
			Character(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, std::string meshPath, std::string texturePath, std::string deathSoundPath, bool bot, char up = ' ', char left = ' ', char down = ' ', char right = ' ', char action = ' ');
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

			int getBombNb() const noexcept;
			void setBombNb(int) noexcept;

			int getBombSize() const noexcept;
			void setBombSize(int) noexcept;

			std::size_t getLaidBomb(void) const noexcept;

			void addBomb(IndieStudio::Bomb *) noexcept;

			void checkDeleteBomb() noexcept;

			irr::scene::IAnimatedMeshSceneNode *getMesh() noexcept;
			IndieStudio::Audio *getDeathSound() noexcept;

		private:
			irr::scene::IAnimatedMeshSceneNode *_model;
			IndieStudio::Audio *_deathSound;
			std::vector<IndieStudio::Bomb *> _bombArr;

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
			float _speed = 1.0f;
			int _bombNb = 1;
			int _bombSize = 1;
	};
};

#endif