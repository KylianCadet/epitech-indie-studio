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

#include "Audio.hpp"
#include "IRender.hpp"
#include "MenuMain.hpp"

namespace IndieStudio
{
class MenuManager : public IRender, public irr::IEventReceiver
{
public:
	MenuManager(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *, Volume *);
	~MenuManager();

	void render(void) noexcept;

	bool OnEvent(const irr::SEvent &event) override;
	int getRenderStatus(void) const noexcept override;
	void setRenderStatus(int) noexcept override;
	void setEventReceiver(void) noexcept override;

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