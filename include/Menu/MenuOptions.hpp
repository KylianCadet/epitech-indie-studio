/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuOptions
*/

#ifndef MENUOPTIONS_HPP_
#define MENUOPTIONS_HPP_

#define MENU_OPTIONS_MAIN 0
#define MENU_OPTIONS_AUDIO 1
#define MENU_OPTIONS_VIDEO 2
#define MENU_OPTIONS_CONTROLS 3
#define MENU_OPTIONS_BACK 4

#define BTN_OPTIONS_AUDIO 0
#define BTN_OPTIONS_VIDEO 1
#define BTN_OPTIONS_CONTROLS 2
#define BTN_OPTIONS_BACK 3

#include <irrlicht.h>
#include <iostream>

#include "Menu.hpp"
#include "MenuAudio.hpp"
#include "MenuVideo.hpp"
#include "MenuControls.hpp"
#include "MenuSounds.hpp"
#include "Audio.hpp"
#include "Button.hpp"
#include "Volume.hpp"

namespace IndieStudio
{
class MenuOptions : public Menu
{
public:
	MenuOptions(irr::video::IVideoDriver *, Volume *, MenuSounds *);
	~MenuOptions();

	virtual void drawMenu(void) noexcept;
	virtual void drawMenuManager(void) noexcept;
	virtual void createButtons(void) noexcept;
	virtual void drawButtons(void) noexcept;
	virtual void createImages(void) noexcept {};
	virtual void drawImages(void) noexcept {};

	virtual void checkActions(void) noexcept;
	virtual void returnAction(void) noexcept;
	virtual void returnActionManager(void) noexcept;
	virtual void escapeAction(void) noexcept;
	virtual void escapeActionManager(void) noexcept;
	virtual void leftAction(void) noexcept;
	virtual void leftActionManager(void) noexcept;
	virtual void rightAction(void) noexcept;
	virtual void rightActionManager(void) noexcept;
	virtual void upAction(void) noexcept;
	virtual void upActionManager(void) noexcept;
	virtual void downAction(void) noexcept;
	virtual void downActionManager(void) noexcept;

	virtual void refreshSkin(void) noexcept;

private:
	MenuAudio *_menuAudio;
	MenuVideo *_menuVideo;
	MenuVideo *_menuControls;

	Button *_audio;
	Button *_video;
	Button *_controls;
	Button *_back;
};
}; // namespace IndieStudio

#endif /* !MENUOPTIONS_HPP_ */
