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
static const int CUBE_Z = 15;
static const int CUBE_X = -220;
static const int SIZE_MAP = 15;
static const char *FLOOR_TEXTURE_256 = "assets/map/256/bedrock.png";
static const char *WALL_TEXTURE_256 = "assets/map/256/black_concrete.png";
static const char *BRICK_TEXTURE_256 = "assets/map/256/bricks.png";
static const char *FLOOR_TEXTURE_128 = "assets/map/128/bedrock.png";
static const char *WALL_TEXTURE_128 = "assets/map/128/black_concrete.png";
static const char *BRICK_TEXTURE_128 = "assets/map/128/bricks.png";
static const char *FLOOR_TEXTURE_64 = "assets/map/64/bedrock.png";
static const char *WALL_TEXTURE_64 = "assets/map/64/black_concrete.png";
static const char *BRICK_TEXTURE_64 = "assets/map/64/bricks.png";

#include "IGraphical.hpp"
#include "IRender.hpp"
#include <fstream>
#include <iostream>
#include <irrlicht.h>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <vector>

namespace IndieStudio {
	class Map {
	public:
		Map(IndieStudio::IGraphical &graphical, std::string graphisme = "64", int x = 15, int y = 32);
		Map(IndieStudio::IGraphical &graphical, std::string graphisme = "64", std::string map = NULL);
		~Map();
		IndieStudio::IEntity *createCubes(float, float, float, const std::string) noexcept;
		void generate_map(int, int, std::vector<std::string> texture_Path) noexcept;
		std::map<std::string, std::vector<IndieStudio::IEntity *>> get_All_Cube(void);
		void create_Start_Positon(void) noexcept;
		std::vector<IndieStudio::IEntity *> getBrickCube(void) noexcept;
		std::vector<IndieStudio::IEntity *> getWallCube(void) const noexcept;
		void delete_Cube(IndieStudio::IEntity *);
		void set_Texture_Cube(IndieStudio::IEntity *, std::string);
		std::vector<IndieStudio::Pos> get_Position_Start() const noexcept;
		std::vector<std::string> get_texture_64() const noexcept;
		std::vector<std::string> get_texture_128() const noexcept;
		std::vector<std::string> get_texture_256() const noexcept;
		void generate_map_by_txt(std::vector<std::string> texture_Path) noexcept;

	protected:
	private:
		void adjustment_Position_Start() noexcept;
		void save_Texture() noexcept;
		std::vector<std::string> set_Graphisme(const std::string path) const noexcept;
		int set_Txt_Map(const std::string);
		std::vector<std::string> get_Txt_Map(void) const noexcept;
		int check_format_map() noexcept;
		void adjustment_Map_Txt();
		std::string reverseStr(std::string &str);
		std::map<std::string, std::vector<IndieStudio::IEntity *>> _cube;
		IndieStudio::IGraphical &_graphical;
		std::vector<IndieStudio::Pos> _pos_start;
		std::vector<IndieStudio::IEntity *> _cube_Destruc_Vec;
		std::vector<IndieStudio::IEntity *> _wall_Vec;
		std::vector<IndieStudio::IEntity *> _floor_Vec;
		std::map<int, std::vector<IndieStudio::IEntity *>> _cube_Destruc_map;
		std::map<std::string, std::vector<std::string>> _texture_Path;
		std::vector<std::string> _map_txt_vec;
	};
}; // namespace IndieStudio

#endif /* !MAP_HPP_ */