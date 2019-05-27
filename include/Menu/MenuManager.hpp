/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** MenuManager
*/

#ifndef MENUMANAGER_HPP_
#define MENUMANAGER_HPP_

#define MENU_MAIN 0
#define MENU_PAUSE 1

#include <irrlicht.h>
#include <iostream>
#include <unistd.h>
#include "Image2d.hpp"
#include "IRender.hpp"
#include "MenuMain.hpp"
#include "Audio.hpp"
#include "Volume.hpp"
#include "MenuSounds.hpp"

namespace IndieStudio
{
class MenuManager : public IRender, public irr::IEventReceiver
{
public:
	MenuManager(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *, Volume *);
	~MenuManager();

	void checkActions(void) noexcept;
	void returnActionManager(void) noexcept;
	void escapeActionManager(void) noexcept;
	void leftActionManager(void) noexcept;
	void rightActionManager(void) noexcept;
	void upActionManager(void) noexcept;
	void downActionManager(void) noexcept;

	void render(void) noexcept;
	void setRenderStatus(bool) noexcept;

	virtual bool OnEvent(const irr::SEvent &event);
	virtual bool hasRender(void) const noexcept;
	virtual void setEventReceiver(void) noexcept;

private:
	bool _render = true;
	int _menuRender = MENU_MAIN;

	MenuMain *_menuMain;

	Volume *_volume;
	MenuSounds *_sounds;
	irr::IrrlichtDevice *_device;
	irr::scene::ISceneManager *_scene;
	irr::video::IVideoDriver *_driver;
};
}; // namespace IndieStudio

#endif /* !MENUMANAGER_HPP_ */