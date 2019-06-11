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
#include <mutex>
static const float ECART = 2;

namespace IndieStudio {
    class IaMouvement {
        public:
            IaMouvement();
            ~IaMouvement();
            //IaMouvement(std::vector<IndieStudio::Character> &);
            void Ia();
            void updateIa(std::shared_ptr<IndieStudio::Character> &, std::vector<std::shared_ptr<IndieStudio::Bomb>>, std::vector<std::shared_ptr<IndieStudio::Pos>>, bool, bool, bool, bool);
            void createIa();
            void thJoin();
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
        std::thread _th;
        std::mutex _mutex;
    };
}