/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <irrlicht.h>
#include <iostream>

namespace IndieStudio {
	class Character {
		public:
			Character(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, char up, char left, char down, char right, char action, std::string meshPath, std::string texturePath, bool bot);
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

			irr::scene::IAnimatedMeshSceneNode *getMesh() noexcept;

		private:
			irr::scene::IAnimatedMeshSceneNode *_model;
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
	};
};

#endif