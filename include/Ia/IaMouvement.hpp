/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IaMouvement
*/

#pragma once

#include <stdlib.h>
#include <vector>
#include "Character.hpp"
#include "Bomb.hpp"
#include <thread>
static const float ECART = 2;

namespace IndieStudio {
    class IaMouvement {
        public:
            IaMouvement();
            ~IaMouvement();
            void Ia(std::shared_ptr<IndieStudio::Character> &characVec, std::vector<std::shared_ptr<IndieStudio::Bomb>> &bombVec, std::vector<std::shared_ptr<IndieStudio::Pos>> freePos);
        protected:
        private:
        enum direction {
            Up,
            Down,
            Right,
            Left
        };
        void checkFreeMove();
        bool freeUp();
        bool freeDown();
        bool freeRight();
        bool freeLeft();
        void setCenter();
        bool isMoving();
        void resetMoving();
        void chooseDirection();
        void Move();
        void checkBomb();
        void setBombPos();
        std::vector<int> _choiceDestination;
        IndieStudio::Pos _destination = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationUp = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationDown = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationRight = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationLeft = IndieStudio::Pos{0,0,0};
        bool _freeUp = false;
        bool _freeDown = false;
        bool _freeRight = false;
        bool _freeLeft = false;
        std::shared_ptr<IndieStudio::Character> _characVec;
        std::vector<std::shared_ptr<IndieStudio::Bomb>> _bombVec;
        std::vector<std::shared_ptr<IndieStudio::Pos>> _freePos;
        std::vector<IndieStudio::Pos> _bombPos;
    };
}