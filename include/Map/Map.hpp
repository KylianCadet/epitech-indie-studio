/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#define CUBE_SIDE 30.f
#define CUBE_Y -400
#define CUBE_Z 0
#define CUBE_X -200
#define SIZE_MAP 15
#define FLOOR_TEXTURE "assets/map/bedrock.png"
#define WALL_TEXTURE "assets/map/black_concrete.png"
#define BRICK_TEXTURE "assets/map/bricks.png"

#include "IGraphical.hpp"
#include <vector>
#include <map>

namespace IndieStudio {
	class Map {
		public:
			Map(IndieStudio::IGraphical &graphical);
			~Map();
			IndieStudio::IEntity *createCubes(float, float, float, std::string) noexcept;
			void generate_map(int) noexcept;
			std::vector<IndieStudio::IEntity *> &getWallCube(void) noexcept;
			void setWallCube(std::vector<IndieStudio::IEntity *> wall) noexcept;

			std::vector<IndieStudio::IEntity *> &getFloorCube(void) noexcept;
			void setFloorCube(std::vector<IndieStudio::IEntity *> wall) noexcept;

			std::vector<IndieStudio::IEntity *> &getBrickCube(void) noexcept;
			void setBrickCube(std::vector<IndieStudio::IEntity *> wall) noexcept;


		protected:
		private:
			std::map<std::string, std::vector<IndieStudio::IEntity *>> _cube;
			IndieStudio::IGraphical &_graphical;
			std::vector<IndieStudio::IEntity *> _cube_Destruc_Vec;
			std::vector<IndieStudio::IEntity *> _wall_Vec;
			std::vector<IndieStudio::IEntity *> _floor_Vec;
	};
};

#endif