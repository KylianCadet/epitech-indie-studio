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
           void Ia(IndieStudio::Character &, std::vector<std::shared_ptr<IndieStudio::Bomb>>, std::vector<IndieStudio::Pos>);
        protected:
        private:
        enum direction {
            Up,
            Down,
            Right,
            Left
        };
        void checkFreeMove(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos);
        bool freeUp(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos);
        bool freeDown(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos);
        bool freeRight(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos);
        bool freeLeft(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos);
        void setCenter(IndieStudio::Character & character);
        bool isMoving(IndieStudio::Character & character);
        void resetMoving(IndieStudio::Character & character);
        void chooseDirection(IndieStudio::Character & character);
        void Move();
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
    };
}