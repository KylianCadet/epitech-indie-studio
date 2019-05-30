/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#include "Map.hpp"
#include <thread>

IndieStudio::Map::Map(IndieStudio::IGraphical &graphical, std::string graphisme, int x, int y) : _graphical(graphical)
{
	srand(time(NULL));
	this->generate_map(x, y, set_Graphisme(graphisme));
}

void IndieStudio::Map::generate_map(int x, int y, std::vector<std::string> const texture_Path) noexcept
{
	bool check = false;
	for (int j = 0, k = 0; j < y; j++) {
		for (int i = 1; i < x; i++) {
			this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z - CUBE_SIDE, texture_Path.at(0)));
			if (i == 1 || i == x - 1 || j == 0 || j == y - 1)
				this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, texture_Path.at(1)));
			else {
				if (rand() % 3 == 0 && j > 3 && j < y - 3)
					this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, texture_Path.at(1)));
				else {
					check = true;
					this->_cube_Destruc_map[k].push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, texture_Path.at(2)));
				}
			}
		}
		if (check == true) {
			k++;
			check = false;
		}
	}
	create_Start_Positon();
}

void IndieStudio::Map::create_Start_Positon(void) noexcept
{
	delete_Cube(this->_cube_Destruc_map[1].at(0));
	delete_Cube(this->_cube_Destruc_map[0].at(1));
	_pos_start.push_back(this->_cube_Destruc_map[0].at(0)->getPosition());
	delete_Cube(this->_cube_Destruc_map[0].at(0));
	delete_Cube(this->_cube_Destruc_map[1].at(this->_cube_Destruc_map[1].size() - 1));
	delete_Cube(this->_cube_Destruc_map[0].at(this->_cube_Destruc_map[0].size() - 2));
	_pos_start.push_back(this->_cube_Destruc_map[0].at(this->_cube_Destruc_map[0].size() - 1)->getPosition());
	delete_Cube(this->_cube_Destruc_map[0].at(this->_cube_Destruc_map[0].size() - 1));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 2].at(0));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(1));
	_pos_start.push_back(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(0)->getPosition());
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(0));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 2].at(this->_cube_Destruc_map[1].size()));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(this->_cube_Destruc_map[0].size()));
	_pos_start.push_back(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(this->_cube_Destruc_map[0].size())->getPosition());
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(this->_cube_Destruc_map[0].size()));
	adjustment_Position_Start();
}

void IndieStudio::Map::delete_Cube(IndieStudio::IEntity *del)
{
	for (unsigned int j = 0; j != this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			if (*i == del) {
				this->_cube_Destruc_map[j].erase(i);
				break;
			}
		}
	}
	this->_graphical.deleteEntity(del);
}

IndieStudio::IEntity *IndieStudio::Map::createCubes(float x, float z, float y, std::string texturePath) noexcept
{
	z += -220;
	IndieStudio::IEntity *cube = this->_graphical.createCube(
		CUBE_SIDE,
		texturePath,
		IndieStudio::Pos(x, y, z)
	);
	return (cube);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::get_Destruc_Cube(void) noexcept
{
	std::vector<IndieStudio::IEntity *> cube;

	for (unsigned int j = 0; j != this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			cube.push_back(*i);
		}
	}
	return (cube);
}

std::map<std::string, std::vector<IndieStudio::IEntity *>> IndieStudio::Map::get_All_Cube(void)
{
	std::map<std::string, std::vector<IndieStudio::IEntity *>> cube;

	cube["Floor"] = this->_floor_Vec;
	cube["Wall"] = this->_wall_Vec;
	for (unsigned int j = 0; j != this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			cube["Destruc"].push_back(*i);
		}
	}
	return (cube);
}

std::vector<IndieStudio::Pos> IndieStudio::Map::get_Position_Start() const noexcept
{
	return (_pos_start);
}

void IndieStudio::Map::adjustment_Position_Start() noexcept
{
	for (auto i = _pos_start.begin(); i != _pos_start.end(); i++) {
		i->_y += 10;
		i->_x += 5;
	}
}

std::vector<std::string> IndieStudio::Map::get_texture_64() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(FLOOR_TEXTURE_64);
	texture.push_back(WALL_TEXTURE_64);
	texture.push_back(BRICK_TEXTURE_64);
	return (texture);
}
std::vector<std::string> IndieStudio::Map::get_texture_128() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(FLOOR_TEXTURE_128);
	texture.push_back(WALL_TEXTURE_128);
	texture.push_back(BRICK_TEXTURE_128);
	return (texture);
}
std::vector<std::string> IndieStudio::Map::get_texture_256() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(FLOOR_TEXTURE_256);
	texture.push_back(WALL_TEXTURE_256);
	texture.push_back(BRICK_TEXTURE_256);
	return (texture);
}

std::vector<std::string> IndieStudio::Map::set_Graphisme(std::string path) const noexcept
{
	if ("256" == path)
		return (get_texture_256());
	else if ("128" == path)
		return (get_texture_128());
	else if ("64" == path)
		return(get_texture_64());
	std::cout << "Graphism " << path << " doesnt exist, only 64, 128 and 256 exist. It set to 64 by default\n";
	return(get_texture_64());
}

IndieStudio::Map::~Map()
{
}
