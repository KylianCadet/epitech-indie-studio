/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#include "Map.hpp"
#include <time.h>
#include <stdlib.h>

IndieStudio::Map::Map(IndieStudio::IGraphical &graphical) : _graphical(graphical)
{
	srand(time(NULL));
	this->generate_map(SIZE_MAP);
}

void IndieStudio::Map::generate_map(int size) noexcept
{
	for (int j = 0; j < size+16; j++) {
		for (int i = 1; i < size; i++) {
			this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z - CUBE_SIDE, FLOOR_TEXTURE));
			if (i == 1 || i == (size) - 1 || j == 0 || j == size+16 - 1) {
				this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, WALL_TEXTURE));
			}
			else
				this->_cube_Destruc_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, BRICK_TEXTURE));
			}
		}
	// for (unsigned int i = 0; i != this->_cube_Destruc_Vec.size(); i++) {
	// 	if (i < 3 || (i <= 27 && i > 24) || (i <= this->_cube_Destruc_Vec.size()- 1 && i > this->_cube_Destruc_Vec.size() - 4) || (i >= this->_cube_Destruc_Vec.size() - 28 && i < this->_cube_Destruc_Vec.size() - 25)) {
	// 		this->_graphical.deleteEntity(this->_cube_Destruc_Vec.at(i));
	// 		this->_cube_Destruc_Vec.erase(this->_cube_Destruc_Vec.begin() + i);
	// 	}
	// 	else if ((rand() % 2) == 0) {
	// 		this->_graphical.deleteEntity(this->_cube_Destruc_Vec.at(i));
	// 		this->_cube_Destruc_Vec.erase(this->_cube_Destruc_Vec.begin() + i);
	// 	}
	// }
}

IndieStudio::IEntity *IndieStudio::Map::createCubes(float x, float z, float y, std::string texturePath) noexcept
{
	IndieStudio::IEntity *cube = this->_graphical.createCube(
		CUBE_SIDE,
		texturePath,
		IndieStudio::Pos(x, y, z)
	);
	return (cube);
}

IndieStudio::Map::~Map()
{
}

std::vector<IndieStudio::IEntity *> &IndieStudio::Map::getWallCube(void) noexcept
{
	return (this->_wall_Vec);
}

void IndieStudio::Map::setWallCube(std::vector<IndieStudio::IEntity *> cube) noexcept
{
	this->_wall_Vec = cube;
}

std::vector<IndieStudio::IEntity *> &IndieStudio::Map::getFloorCube(void) noexcept
{
	return (this->_floor_Vec);
}

void IndieStudio::Map::setFloorCube(std::vector<IndieStudio::IEntity *> cube) noexcept
{
	this->_floor_Vec = cube;
}

std::vector<IndieStudio::IEntity *> &IndieStudio::Map::getBrickCube(void) noexcept
{
	return (this->_cube_Destruc_Vec);
}

void IndieStudio::Map::setBrickCube(std::vector<IndieStudio::IEntity *> cube) noexcept
{
	this->_cube_Destruc_Vec = cube;
}
