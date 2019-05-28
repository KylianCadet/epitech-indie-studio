/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** MenuManager
*/

#ifndef MENUMANAGER_HPP_
#define MENUMANAGER_HPP_

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

	void render(void) noexcept;

	virtual bool OnEvent(const irr::SEvent &event);
	virtual int getRenderStatus(void) const noexcept;
	virtual void setRenderStatus(int) noexcept;
	virtual void setEventReceiver(void) noexcept;

private:
	void checkActions(void) noexcept;
	void returnActionManager(void) noexcept;
	void escapeActionManager(void) noexcept;
	void leftActionManager(void) noexcept;
	void rightActionManager(void) noexcept;
	void upActionManager(void) noexcept;
	void downActionManager(void) noexcept;


private:
	int _renderStatus = MAIN_MENU;

	MenuMain *_menuMain;

	Volume *_volume;
	MenuSounds *_sounds;
	irr::IrrlichtDevice *_device;
	irr::scene::ISceneManager *_scene;
	irr::video::IVideoDriver *_driver;
};
}; // namespace IndieStudio

#endif /* !MENUMANAGER_HPP_ */