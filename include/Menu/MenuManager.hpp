/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** MenuManager
*/

#ifndef MENUMANAGER_HPP_
#define MENUMANAGER_HPP_

#define MAIN_MENU 0
#define NEWGAME_MENU 1
#define LOADGAME_MENU 2
#define OPTIONS_MENU 3

#include <irrlicht.h>
#include <iostream>
#include <unistd.h>
#include "Image2d.hpp"
#include "IRender.hpp"
#include "MenuMain.hpp"
#include "Audio.hpp"

namespace IndieStudio
{
	class MenuManager : public IRender, public irr::IEventReceiver
	{
	public:
		MenuManager(irr::IrrlichtDevice *, irr::scene::ISceneManager *, irr::video::IVideoDriver *);
		~MenuManager();

		void render(void) noexcept;
		void returnAction(void) noexcept;
		void setRenderStatus(bool) noexcept;

		virtual bool OnEvent(const irr::SEvent &event);
		virtual bool hasRender(void) const noexcept;
		virtual void setEventReceiver(void) noexcept;

	private:
		bool _render = true;
		int _menuRender = MAIN_MENU;

		MenuMain *_menuMain;

		irr::IrrlichtDevice *_device;
		irr::scene::ISceneManager *_scene;
		irr::video::IVideoDriver *_driver;

		IndieStudio::Audio *_buttonSwitchSound;
		IndieStudio::Audio *_buttonReturnSound;
		IndieStudio::Audio *_mainMusic;
		IndieStudio::Image2d *_frameMenu;
		IndieStudio::Image2d *_titleMenu;

	};
}; // namespace IndieStudio

#endif /* !MENUMANAGER_HPP_ */