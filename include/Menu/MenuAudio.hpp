/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuAudio
*/

#ifndef MENUAUDIO_HPP_
#define MENUAUDIO_HPP_

#define MENU_AUDIO_MAIN 0
#define MENU_AUDIO_BACK 1

#include <irrlicht.h>
#include <iostream>

#include "Menu.hpp"
#include "MenuSounds.hpp"
#include "Audio.hpp"
#include "Button.hpp"
#include "Volume.hpp"

namespace IndieStudio
{
class MenuAudio : public Menu
{
public:
	MenuAudio(irr::video::IVideoDriver *, Volume *, MenuSounds *);
	~MenuAudio();

	void setVolumeBar(void) noexcept;

	virtual void drawMenu(void) noexcept {};
	virtual void drawMenuManager(void) noexcept;
	virtual void createButtons(void) noexcept;
	virtual void drawButtons(void) noexcept;
	virtual void createImages(void) noexcept;
	virtual void drawImages(void) noexcept;

	virtual void checkActions(void) noexcept {};
	virtual void returnAction(void) noexcept {};
	virtual void returnActionManager(void) noexcept;
	virtual void escapeAction(void) noexcept {};
	virtual void escapeActionManager(void) noexcept;
	virtual void leftAction(void) noexcept {};
	virtual void leftActionManager(void) noexcept;
	virtual void rightAction(void) noexcept {};
	virtual void rightActionManager(void) noexcept;
	virtual void upAction(void) noexcept {};
	virtual void upActionManager(void) noexcept;
	virtual void downAction(void) noexcept {};
	virtual void downActionManager(void) noexcept;

	virtual void refreshSkin(void) noexcept;

private:
	int _leftTime = 0;
	int _rightTime = 0;

	Button *_leftArrow;
	Button *_rightArrow;

	Image2d *_volumeBarEmpty;
	Image2d *_volumeBarFilled;
	Image2d *_escapeInfo;
};
}; // namespace IndieStudio

#endif /* !MENUAUDIO_HPP_ */
