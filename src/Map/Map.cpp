/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#include "Map.hpp"
#include <thread>

IndieStudio::Map::Map(IndieStudio::IGraphical &graphical, std::string graphisme, int x, int y, int densityBrick, int densityWall) :
	_graphical(graphical)
{
	init_pos_start();
	this->generate_map(x, y, set_Graphisme(graphisme));
	set_Density_Brick(getBrickCube(), 100 - densityBrick);
	set_Density_Wall(getWallInsideCube(), 100 - densityWall);
	std::cout << _floor_Vec.at(_floor_Vec.size() - 1)->getPosition()._x << "  " << _floor_Vec.at(_floor_Vec.size() - 1)->getPosition()._y << "  " << _floor_Vec.at(_floor_Vec.size() - 1)->getPosition()._z << "\n";
}

IndieStudio::Map::Map(IndieStudio::IGraphical &graphical, std::string graphisme, std::string map) :
	_graphical(graphical)
{
	if (set_Txt_Map(map) == 0)
		generate_map_by_txt(set_Graphisme(graphisme));
	else
		generate_map(15, 32, get_texture_64());
	std::cout << _pos_start.at(0)._x << "  " << _pos_start.at(0)._y << "  " << _pos_start.at(0)._z << "\n";
}

//          GENERATION

void IndieStudio::Map::generate_map(int x, int y, std::vector<std::string> const texture_Path) noexcept
{
	bool check = false;
	srand(time(NULL));
	for (int j = 0, k = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, texture_Path.at(0)));
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, texture_Path.at(1)));
			else {
				if (i % 2 == 0 && j > 1 && j < y - 2 && j % 2 == 0 && i > 0 && i < x - 2)
					this->_wall_inside_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, texture_Path.at(1)));
				else {
					check = true;
					this->_cube_Destruc_map[k].push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, texture_Path.at(2)));
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

void IndieStudio::Map::generate_map_by_txt(std::vector<std::string> texture_Path) noexcept
{
	bool check = false;
	for (unsigned int j = 0, k = 0; j != _map_txt_vec.size(); j++) {
		for (unsigned int i = 0; i < _map_txt_vec[j].size(); i++) {
			this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, texture_Path.at(0)));
			if (_map_txt_vec[j][i] == '#')
				this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, texture_Path.at(1)));
			if (_map_txt_vec[j][i] == 'B') {
				check = true;
				this->_cube_Destruc_map[k].push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, texture_Path.at(2)));
			}
			if (_map_txt_vec[j][i] == 'P') {
				_pos_start.push_back({CUBE_X + (i * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_Y + (j * CUBE_SIDE)}); // A refaire.
			}
		}
		if (check == true) {
			k++;
			check = false;
		}
	}
	adjustment_Position_Start();
}

IndieStudio::IEntity *IndieStudio::Map::createCubes(float x, float z, float y, std::string texturePath) noexcept
{
	IndieStudio::IEntity *cube = this->_graphical.createCube(
		CUBE_SIDE,
		texturePath,
		IndieStudio::Pos(x, y, z));
	return (cube);
}

void IndieStudio::Map::delete_Wall(IndieStudio::IEntity *del)
{
	for (auto i = _wall_inside_Vec.begin(); i != _wall_inside_Vec.end(); i++) {
		if (*i == del) {
			this->_graphical.deleteEntity(del);
			this->_wall_inside_Vec.erase(i);
			return;
		}
	}
}

void IndieStudio::Map::delete_Cube(IndieStudio::IEntity *del)
{
	for (unsigned int j = 0; j != this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			if (*i == del) {
				this->_graphical.deleteEntity(del);
				this->_cube_Destruc_map[j].erase(i);
				return;
			}
		}
	}
}


//             GET

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getBrickCube(void) noexcept
{
	std::vector<IndieStudio::IEntity *> cube;

	for (unsigned int j = 0; j != this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			cube.push_back(*i);
		}
	}
	return (cube);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getWallCube(void) const noexcept
{
	auto cube = this->_wall_Vec;
	for (auto i = _wall_inside_Vec.begin(); i != _wall_inside_Vec.end(); i++) {
		cube.push_back(*i);
	}
	return (cube);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getWallInsideCube(void) noexcept 
{
	return (_wall_inside_Vec);
}

std::vector<IndieStudio::Pos> IndieStudio::Map::get_Position_Start() const noexcept
{
	return (_pos_start);
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

IndieStudio::IEntity *IndieStudio::Map::get_Cube_By_Position(IndieStudio::Pos pos)
{
	auto brick = getBrickCube();
	for (unsigned int i = 0; i != brick.size(); i++) {
		if (brick.at(i)->getPosition() == pos)
			return (brick.at(i));
	}
	for (unsigned int i = 0; i != _wall_Vec.size(); i++) {
		if (_wall_Vec.at(i)->getPosition() == pos)
			return (_wall_Vec.at(i));
	}
	return(nullptr);
}

//              SET

int IndieStudio::Map::set_Txt_Map(std::string map)
{
	std::ifstream file(map);
	std::string line;
	if (file.is_open()) {
		while (getline(file, line))
			_map_txt_vec.push_back(reverseStr(line));
		file.close();
		adjustment_Map_Txt();
		return (check_format_map());
	} else {
		std::cout << "Can't open file, " << map << ". Random generation map used\n";
		return (-1);
	}
	return (0);
}

std::vector<std::string> IndieStudio::Map::set_Graphisme(std::string const path) const noexcept
{
	if ("256" == path)
		return (get_texture_256());
	else if ("128" == path)
		return (get_texture_128());
	else if ("64" == path)
		return (get_texture_64());
	std::cout << "Graphism " << path << " doesnt exist, only 64, 128 and 256 exist. It set to 64 by default\n";
	return (get_texture_64());
}

void IndieStudio::Map::set_Density_Brick(std::vector<IndieStudio::IEntity *> cube, int percent)
{
	int density = 100 / percent;
	for (unsigned int i = 0; i != cube.size(); i++) {
		if (rand() % density == 0) {
			delete_Cube(cube[i]);
		}
	}
}

void IndieStudio::Map::set_Density_Wall(std::vector<IndieStudio::IEntity *> cube, int percent)
{
	if (percent == 0)
		return;
	int density = 100 / percent;
	if (density == 0)
		return;
	for (unsigned int i = 0; i != cube.size(); i++) {
		if (rand() % density == 0) {
			delete_Wall(cube[i]);
		}
	}
}

void IndieStudio::Map::init_pos_start() noexcept
{
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
}

//              CHECK

int IndieStudio::Map::check_format_map() noexcept
{
	for (unsigned int j = 0; j != _map_txt_vec.size(); j++) {
		for (unsigned int i = 0; i != _map_txt_vec[j].size() - 1; i++) {
			if (_map_txt_vec[j][i] == ' ' || _map_txt_vec[j][i] == '#' || _map_txt_vec[j][i] == 'B' || _map_txt_vec[j][i] == 'P')
				;
			else {
				std::cout << "Bad Format, Format : Wall = '#', Brick = 'B', Other = ' ', Positon Player = 'P'. Random generation Used\n";
				return (-1);
			}
		}
	}
	return (0);
}

//            OTHER

void IndieStudio::Map::adjustment_Position_Start() noexcept
{
	if (_pos_start.size() < 4) {
		for (int i = _pos_start.size() - 1; i != 4; i++) {
			_pos_start.push_back({0, 0, 0});
		}
	}
	for (auto i = _pos_start.begin(); i != _pos_start.end(); i++) {
		i->_y += 10;
		i->_x += 5;
	}
}

void IndieStudio::Map::adjustment_Map_Txt()
{
	std::vector<std::string> res = _map_txt_vec;
	std::string line;
	std::string letter;

	_map_txt_vec.clear();
	for (int i = res.size() - 1; i != -1; i--) {
		_map_txt_vec.push_back(res.at(i));
	}
	res.clear();
	for (unsigned int i = 0; i != _map_txt_vec[0].size(); i++) {
		for (unsigned int j = 0; j != _map_txt_vec.size(); j++) {
			letter = _map_txt_vec[j][i];
			line.append(letter);
		}
		res.push_back(line);
		line = "";
	}
	_map_txt_vec.clear();
	_map_txt_vec = res;
}

std::string IndieStudio::Map::reverseStr(std::string &str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		std::swap(str[i], str[n - i - 1]);
	return (str);
}

void IndieStudio::Map::create_Start_Positon(void) noexcept
{
	_pos_start.clear();
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

IndieStudio::Map::~Map()
{
}
