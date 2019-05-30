/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

static const float CUBE_SIDE = 40.f;
static const int CUBE_Y = -400;
static const int CUBE_Z = 0;
static const int CUBE_X = -200;
static const int SIZE_MAP = 15;
static const char* FLOOR_TEXTURE = "assets/map/bedrock.png";
static const char* WALL_TEXTURE = "assets/map/black_concrete.png";
static const char* BRICK_TEXTURE = "assets/map/bricks.png";

#include <irrlicht.h>
#include <iostream>
#include "IRender.hpp"
#include "IGraphical.hpp"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <map>
namespace IndieStudio {
    class Map {
        public:
            Map(IndieStudio::IGraphical &graphical);
            ~Map();
            IndieStudio::IEntity *createCubes(float, float, float, std::string) noexcept;
            void generate_map(int, int) noexcept;
            std::map<std::string, std::vector<IndieStudio::IEntity *>> get_All_Cube(void);
            void create_Start_Positon(void) noexcept;
			std::vector<IndieStudio::IEntity *> get_Destruc_Cube(void) noexcept;
			void delete_Cube(IndieStudio::IEntity *);
			void set_Texture_Cube(IndieStudio::IEntity *, std::string);
			std::vector<IndieStudio::Pos> get_Position_Start() noexcept;
        protected:
        private:
			void adjustment_Position_Start() noexcept;
        	std::map<std::string, std::vector<IndieStudio::IEntity *>> _cube;
            IndieStudio::IGraphical &_graphical;
			std::vector<IndieStudio::Pos> _pos_start;
            std::vector<IndieStudio::IEntity *> _cube_Destruc_Vec;
            std::vector<IndieStudio::IEntity *> _wall_Vec;
            std::vector<IndieStudio::IEntity *> _floor_Vec;
            std::map<int, std::vector<IndieStudio::IEntity *>> _cube_Destruc_map;
    };
};

#endif /* !MAP_HPP_ */