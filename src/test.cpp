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
	irr::IrrlichtDevice *device = irr::createDevice( // creation du device
		irr::video::EDT_OPENGL,						 // API = OpenGL
		irr::core::dimension2d<irr::u32>(800, 800),  // taille fenetre 640x480p
		32);										 // 32 bits par pixel

	irr::video::IVideoDriver *driver = // video driver
		device->getVideoDriver();
	irr::scene::ISceneManager *sceneManager = // scene manager
		device->getSceneManager();

	device->getCursorControl()->setVisible(false); // curseur invisible

	/* CREATE CHARACTERS */
	std::vector<IndieStudio::Character> characterVec;
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, 'i', 'j', 'k', 'l', 'o', "model/rei/tris.md2", "model/rei/rei.pcx", false)
	);
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, 'w', 'x', 'c', 'v', 'b', "model/chun-li/tris.md2", "model/chun-li/original.bmp", false)
	);
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, 't', 'f', 'g', 'h', 'y', "model/eric_c/tris.md2", "model/eric_c/eric.pcx", true)
	);
	characterVec.push_back(
		IndieStudio::Character(sceneManager, driver, 'z', 'q', 's', 'd', 'e', "model/starfox/tris.md2", "model/starfox/starfox.pcx", true)
	);

	/* CREATE EVENT LISTENER */
	IndieStudio::CharacterEventListener CharacterEventListener(characterVec);
	device->setEventReceiver(&CharacterEventListener);
	
	/* CREATE CUBE */
	std::vector<irr::scene::IMeshSceneNode *> cubeVec;
	for (int i = 0; i != 10; i++) {
		irr::scene::IMeshSceneNode *cube =				 // pointeur vers le node
			sceneManager->addCubeSceneNode(				 // la creation du cube
				30.0f,									 // cote de 10 unites
				0,										 // parent = racine
				-1,										 // pas d'ID
				irr::core::vector3df(					 // le vecteur de position
					0.0f,								 // origine en X
					0.0f,								 // origine en Y
					(i * 30) + 100.0f));					 // +20 unites en Z

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
	irr::SKeyMap keyMap[5];					   // re-assigne les commandes
	keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
	keyMap[0].KeyCode = irr::KEY_UP;		   // w
	keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
	keyMap[1].KeyCode = irr::KEY_DOWN;		   // s
	keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
	keyMap[2].KeyCode = irr::KEY_LEFT;		   // a
	keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
	keyMap[3].KeyCode = irr::KEY_RIGHT;		   // d
	keyMap[4].Action = irr::EKA_JUMP_UP;	   // saut
	keyMap[4].KeyCode = irr::KEY_SPACE;		   // barre espace

	sceneManager->addCameraSceneNode(
		0,
		irr::core::vector3df(-100, 300, 0),
		irr::core::vector3df(100, 0, 0)
	);
	// sceneManager->addCameraSceneNodeFPS( // ajout de la camera FPS
	// 	0,								 // pas de noeud parent
	// 	100.0f,							 // vitesse de rotation
	// 	0.1f,							 // vitesse de deplacement
	// 	-1,								 // pas de numero d'ID
	// 	keyMap,							 // on change la keymap
	// 	5);								 // avec une taille de 5

	/* RENDU */

	irr::video::SColor color( // contient la couleur blanc
		255,				  // composante A alpha (transparence)
		255,				  // composante R rouge
		255,				  // composante G verte
		255);				  // composante B bleue

	float rot_x = 100;
	float rot_y = 0;
	float rot_z = 0;
	float counter = 0;
	while (device->run())
	{										   // la boucle de rendu
		sceneManager->getActiveCamera()->setTarget(irr::core::vector3df(rot_x, rot_y, rot_z));
		rot_x = cos(counter) * 3;
		rot_z = sin(counter) * 3;
		driver->beginScene(true, true, color); // demarre le rendu
		CharacterEventListener.moveCharacter();
		sceneManager->drawAll();			   // calcule le rendu
		driver->endScene();					   // affiche le rendu
		counter += 0.05;
	}

	device->drop(); // libere la memoire
	return 0;
}
