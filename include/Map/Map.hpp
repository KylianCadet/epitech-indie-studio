/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#define CUBE_SIDE 20.f
#define CUBE_Y -140
#define CUBE_Z 990
#define CUBE_X -310
#define SIZE_MAP 15
#define FLOOR_TEXTURE "assets/map/bedrock.png"
#define WALL_TEXTURE "assets/map/black_concrete.png"
#define BRICK_TEXTURE "assets/map/bricks.png"

#include <irrlicht.h>
#include <iostream>
#include "IRender.hpp"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Game.hpp"
namespace IndieStudio {
    class Map : public IRender, public irr::IEventReceiver{
        public:
            Map(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *);
            ~Map();
            irr::scene::IMeshSceneNode *createCubes(irr::f32, irr::f32, irr::f32) noexcept;
            void generate_map(int) noexcept;
            void generate_texture() noexcept;
            virtual bool OnEvent(const irr::SEvent &event);
            void render() noexcept;
            virtual bool hasRender(void) const noexcept;
            virtual void setEventReceiver(void) noexcept;
        protected:
        private:
            irr::IrrlichtDevice *_device;
            irr::scene::ISceneManager *_sceneManager;
            irr::video::IVideoDriver *_driver;
            std::vector<irr::scene::IMeshSceneNode *> _cube_Destruc_Vec;
            std::vector<irr::scene::IMeshSceneNode *> _wall_Vec;
            std::vector<irr::scene::IMeshSceneNode *> _floor_Vec;
            float _rot_x = 0;
            float _rot_y = 0;
            float _rot_z = 0;
            float _counter = 0;
    };
};
void create_Map_Collision(IndieStudio::Map &, IndieStudio::Game &);

#endif /* !MAP_HPP_ */
