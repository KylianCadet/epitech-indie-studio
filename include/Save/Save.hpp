/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Save
*/

#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Character.hpp"
#include "IGraphical.hpp"

static const std::string MAP_TXT_PATH = "save/map.txt";
static const std::string PLAYER_TXT_PATH = "save/player.txt";

namespace IndieStudio {
    class Save {
        public:
            Save();
            Save(std::vector<IndieStudio::IEntity *> const &, std::vector<IndieStudio::IEntity *> const &, std::vector<IndieStudio::IEntity *> const &, std::vector<std::shared_ptr<IndieStudio::Character>>, float, float, float);
            ~Save();
            void setBrickVec(std::vector<IndieStudio::IEntity *> const &) noexcept;
            void setWallOutsideVec(std::vector<IndieStudio::IEntity *> const &) noexcept;
            void setWallInsideVec(std::vector<IndieStudio::IEntity *> const &) noexcept;
            void setDimensionMap(float, float, float) noexcept;
            void setCharacterVec(std::vector<std::shared_ptr<IndieStudio::Character>>) noexcept;
            std::vector<std::string> getMap() noexcept;
            void create_file() noexcept;
            std::vector<std::string> getMapByTxt() noexcept;
            std::vector<std::shared_ptr<IndieStudio::Character>> getPlayerPositionByTxt() noexcept;
        protected:
        private:
        void generateSave() noexcept;
        void generateMap() noexcept;
        void generatePlayerPosition() noexcept;
        std::vector<std::string> getTxt(std::string) noexcept;
        private:
        std::vector<std::string> _mapTxt;
        std::vector<std::string> _playerPosition;
        std::vector<IndieStudio::IEntity *> _brickVec;
        std::vector<IndieStudio::IEntity *> _wallOutsideVec;
        std::vector<IndieStudio::IEntity *> _wallInsideVec;
        std::vector<std::shared_ptr<IndieStudio::Character>> _characterVec;
        float _x_map = 0;
        float _y_map = 0;
        float _cube_size = 0;
    };
}