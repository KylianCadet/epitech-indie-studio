/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** irr
*/

#include <irrlicht.h>
#include <vector>
#include <tgmath.h>
#include "Character.hpp"
#include "CharacterEventListener.hpp"

int main(void)
{
	irr::IrrlichtDevice *device = irr::createDevice(
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(800, 800),
		32);
	irr::video::IVideoDriver *driver = device->getVideoDriver();
	irr::scene::ISceneManager *sceneManager = device->getSceneManager();
	irr::scene::ISceneManager *other = sceneManager->createNewSceneManager();
	device->getCursorControl()->setVisible(false);

	/* CREATE CHARACTERS */
	std::vector<IndieStudio::Character> characterVec;
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, "assets/rei/tris.md2", "assets/rei/rei.pcx", false, 'i', 'j', 'k', 'l', 'o')
	);
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, "assets/chun-li/tris.md2", "assets/chun-li/original.bmp", false, 'w', 'x', 'c', 'v', 'b')
	);
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, "assets/eric_c/tris.md2", "assets/eric_c/eric.pcx", true)
	);
	characterVec.push_back(
		IndieStudio::Character(other, driver, "assets/starfox/tris.md2", "assets/starfox/starfox.pcx", true)
	);

	/* CREATE EVENT LISTENER */
	IndieStudio::CharacterEventListener CharacterEventListener(characterVec);
	device->setEventReceiver(&CharacterEventListener);
	
	/* CREATE CUBE */
	std::vector<irr::scene::IMeshSceneNode *> cubeVec;
	for (int i = 0; i != 10; i++) {
		irr::scene::IMeshSceneNode *cube =
			sceneManager->addCubeSceneNode(
				30.0f,
				0,
				-1,
				irr::core::vector3df(
					0.0f,
					0.0f,
					(i * 30) + 100.0f));

		cube->setMaterialType(irr::video::E_MATERIAL_TYPE::EMT_SOLID);
		cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);

		/* CREATE TRIANGLE SELECTOR FOR THE CREATED CUBE */
		irr::scene::IMetaTriangleSelector* metaSelector = sceneManager->createMetaTriangleSelector();
		irr::scene::ITriangleSelector* selector = 0;
		selector = sceneManager->createTriangleSelectorFromBoundingBox(cube);
		cube->setTriangleSelector(selector);
		metaSelector->addTriangleSelector(selector);

		/* CREATE ANIMATOR RESPONSE FOR EACH OF THE CHARACTERS */
		for (auto character_it = characterVec.begin(); character_it != characterVec.end(); character_it++) {
			irr::scene::ISceneNode *node = character_it->getMesh();
			irr::scene::ISceneNodeAnimatorCollisionResponse* anim = sceneManager->createCollisionResponseAnimator(
				metaSelector,
				node,
				irr::core::vector3df(20, 20, 20),
				irr::core::vector3df(0, 0, 0)
			);
			node->addAnimator(anim);
			anim->drop();
		}
		cubeVec.push_back(cube);
	}

	/* CAMERA */
	sceneManager->addCameraSceneNode(
		0,
		irr::core::vector3df(-100, 300, 0),
		irr::core::vector3df(100, 0, 0)
	);

	/* RENDU */
	irr::video::SColor color(
		255,
		255,
		255,
		255);

	float rot_x = 100;
	float rot_y = 0;
	float rot_z = 0;
	float counter = 0;
	while (device->run()) {
		sceneManager->getActiveCamera()->setTarget(irr::core::vector3df(rot_x, rot_y, rot_z));
		rot_x = cos(counter) * 3;
		rot_z = sin(counter) * 3;
		driver->beginScene(true, true, color);
		CharacterEventListener.moveCharacter();
		sceneManager->drawAll();
		driver->endScene();
		counter += 0.05;
	}
	device->drop();
	return 0;
}
