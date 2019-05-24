/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#include "Map.hpp"

IndieStudio::Map::Map(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver) : _device(device), _sceneManager(sceneManager), _driver(driver)
{
    srand(time(NULL));
    this->generate_map(SIZE_MAP);
    this->_sceneManager->addCameraSceneNode(
        0,
        irr::core::vector3df(0, 0, 1200),
        irr::core::vector3df(0, 0, 0)
    );
}

bool IndieStudio::Map::hasRender(void) const noexcept
{
	return (true);
}

void IndieStudio::Map::setEventReceiver(void) noexcept
{
	this->_device->setEventReceiver(this);
}

void IndieStudio::Map::generate_texture() noexcept
{
    for (unsigned int i = 0; i != _wall_Vec.size(); i++) {
        _wall_Vec.at(i)->setMaterialTexture(0, this->_driver->getTexture(WALL_TEXTURE));
    }
    for (unsigned int i = 0; i != _floor_Vec.size(); i++) {
        _floor_Vec.at(i)->setMaterialTexture(0, this->_driver->getTexture(FLOOR_TEXTURE));
    }
    for (unsigned int i = 0; i != _cube_Destruc_Vec.size(); i++) {
        _cube_Destruc_Vec.at(i)->setMaterialTexture(0, this->_driver->getTexture(BRICK_TEXTURE));
    }
}

void IndieStudio::Map::generate_map(int size) noexcept
{
    for (int j = 0; j < size; j++) {
        for (int i = 1; i < size+16; i++) {
            this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z - CUBE_SIDE));
            if (i == 1 || i == (size+16) - 1 || j == 0 || j == size - 1)
                this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z));
            else
                this->_cube_Destruc_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z));
        }
    }
    this->generate_texture();
    for (unsigned int i = 0; i != this->_cube_Destruc_Vec.size(); i++) {
        if (i < 3 || (i <= 27 && i > 24) || (i <= this->_cube_Destruc_Vec.size()- 1 && i > this->_cube_Destruc_Vec.size() - 4) || (i >= this->_cube_Destruc_Vec.size() - 28 && i < this->_cube_Destruc_Vec.size() - 25))
            this->_cube_Destruc_Vec.at(i)->remove();
        else if ((rand() % 2) == 0)
            this->_cube_Destruc_Vec.at(i)->remove();
    }

}

irr::scene::IMeshSceneNode *IndieStudio::Map::createCubes(irr::f32 x, irr::f32 y, irr::f32 z) noexcept
{
    irr::scene::IMeshSceneNode *cube =
        this->_sceneManager->addCubeSceneNode(
            CUBE_SIDE,
            0,
            -1,
            irr::core::vector3df(
                x,
                y,
                z
            )
        );
    cube->setMaterialType(irr::video::E_MATERIAL_TYPE::EMT_SOLID);
    cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    return (cube);
}

void IndieStudio::Map::render() noexcept
{
    this->_sceneManager->getActiveCamera()->bindTargetAndRotation(true);
    //this->_sceneManager->getActiveCamera()->setTarget(irr::core::vector3df(this->_rot_x, this->_rot_y, this->_rot_z));
    this->_sceneManager->getActiveCamera()->setRotation(irr::core::vector3df(200, 0, this->_counter));
    // this->_rot_x = cos(this->_counter) * 7;
	// this->_rot_y = sin(this->_counter) * 7;
    this->_sceneManager->drawAll();
    this->_counter += 1;
}

bool IndieStudio::Map::OnEvent(const irr::SEvent &event)
{
    return (false);
}

IndieStudio::Map::~Map()
{
}
