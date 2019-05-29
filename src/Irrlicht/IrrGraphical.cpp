/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IrrGraphical
*/

#include "IrrGraphical.hpp"

IndieStudio::IrrGraphical::IrrGraphical()
{
	this->_device = irr::createDevice(
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(2000, 2000), 32);
	this->_sceneManager = this->_device->getSceneManager();
	this->_driver = this->_device->getVideoDriver();
	this->_sceneManager->addCameraSceneNode(
		0,
		irr::core::vector3df(-100, 300, 0),
		irr::core::vector3df(100, 0, 0)
	);
	this->setCursorVisible(false);
	this->_device->setEventReceiver(this);
}

IndieStudio::IrrGraphical::~IrrGraphical()
{
}

void IndieStudio::IrrGraphical::setCursorVisible(bool b) noexcept
{
	this->_device->getCursorControl()->setVisible(b);
}

IndieStudio::IEntity *IndieStudio::IrrGraphical::createMesh(std::string meshPath) const noexcept
{
	irr::scene::IMeshSceneNode *model = this->_sceneManager->addMeshSceneNode(this->_sceneManager->getMesh(meshPath.c_str()));

	if (model == NULL)
		exit(84);
	model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	IndieStudio::IrrEntity *obj = new IndieStudio::IrrEntity(model);
	return (obj);
}

IndieStudio::IEntity *IndieStudio::IrrGraphical::createAnimatedMesh(std::string meshPath, std::string texturePath) const noexcept
{
	irr::video::ITexture *texture = this->_driver->getTexture(texturePath.c_str());
	irr::scene::IAnimatedMeshSceneNode *model = this->_sceneManager->addAnimatedMeshSceneNode(this->_sceneManager->getMesh(meshPath.c_str()));

	if (model == nullptr || texture == nullptr)
		exit(84);
	model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	model->setMaterialTexture(0, texture);
	model->setMD2Animation(irr::scene::EMAT_STAND);
	IndieStudio::IrrEntity *obj = new IndieStudio::IrrEntity(model);
	return (obj);
}

IndieStudio::IEntity *IndieStudio::IrrGraphical::createCube(float size, std::string texturePath, IndieStudio::Pos pos, IndieStudio::Pos scale) const noexcept
{
	irr::video::ITexture *texture = this->_driver->getTexture(texturePath.c_str());
	irr::scene::IMeshSceneNode *cube = this->_sceneManager->addCubeSceneNode(
		size,
		0,
		-1,
		irr::core::vector3df(pos._x, pos._y, pos._z),
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(scale._x, scale._y, scale._z)
	);

	if (texture == nullptr || cube == nullptr)
		exit(84);
	cube->setMaterialTexture(0, texture);
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	IndieStudio::IEntity *obj = new IndieStudio::IrrEntity(cube);
	return (obj);
}

IndieStudio::IEntity *IndieStudio::IrrGraphical::createParticle(IndieStudio::Pos boxPos, IndieStudio::Pos dirPos, int min, int max, IndieStudio::Pos colorMin, IndieStudio::Pos colorMax) const noexcept
{
	irr::scene::IParticleSystemSceneNode *particle = this->_sceneManager->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter *emitter = particle->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(boxPos._x, boxPos._y, boxPos._z, boxPos._x, boxPos._y, boxPos._z),
		irr::core::vector3df(dirPos._x, dirPos._y, dirPos._z),
		min, max,
		irr::video::SColor(1, colorMin._x, colorMin._y, colorMin._z),
		irr::video::SColor(1, colorMax._x, colorMax._y, colorMax._z),
		1000, 1000,
		0,
		irr::core::dimension2df(13.0f, 13.0f),
		irr::core::dimension2df(13.0f, 13.0f)
	);
	particle->setEmitter(emitter);
	emitter->drop();
	particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	IndieStudio::IEntity *obj = new IndieStudio::IrrEntity(particle);
	return (obj);
}

bool IndieStudio::IrrGraphical::run(void) const noexcept
{
	return (this->_device->run());
}

void IndieStudio::IrrGraphical::render(void) const noexcept
{
	this->_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
	this->_sceneManager->drawAll();
	this->_driver->endScene();
}

void IndieStudio::IrrGraphical::drop(void) const noexcept
{
	this->_device->drop();
}

bool IndieStudio::IrrGraphical::OnEvent(const irr::SEvent &event)
{
	this->_event.update(event);
	return (false);
}

IndieStudio::IEvent IndieStudio::IrrGraphical::getEvent(void) const noexcept
{
	return (this->_event);
}

void IndieStudio::IrrGraphical::deleteEntity(IndieStudio::IEntity *entity) const noexcept
{
	IndieStudio::IrrEntity *irrEntity = static_cast<IndieStudio::IrrEntity *>(entity);

	if (irrEntity->getMesh() != nullptr)
		this->_sceneManager->addToDeletionQueue(irrEntity->getMesh());
	if (irrEntity->getParticle() != nullptr)
		this->_sceneManager->addToDeletionQueue(irrEntity->getParticle());
}