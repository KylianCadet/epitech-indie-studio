/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuNew
*/

#ifndef MENUNEW_HPP_
#define MENUNEW_HPP_

static const int MENU_NEW_GAME = -1;
static const int MENU_NEW_MAIN = 0;
static const int MENU_NEW_BACK = 1;

static const int BTN_NEW_SOLO = 0;
static const int BTN_NEW_COOP = 1;
static const int BTN_NEW_1VS1 = 2;
static const int BTN_NEW_BACK = 3;

#include "Menu.hpp"

namespace IndieStudio
{
class MenuNew : public Menu
{
public:
	MenuNew(IGraphical &, Volume *, MenuSounds *);
	~MenuNew();

public:
	void drawMenuManager(void) noexcept override;
	void returnActionManager(void) noexcept override;
	void escapeActionManager(void) noexcept override;
	void leftActionManager(void) noexcept override;
	void rightActionManager(void) noexcept override;
	void upActionManager(void) noexcept override;
	void downActionManager(void) noexcept override;
	void alphaActionManager(IndieStudio::Key) noexcept override;

private:
	void drawMenu(void) noexcept override;
	void createButtons(void) noexcept override;
	void drawButtons(void) noexcept override;
	void createImages(void) noexcept override;
	void drawImages(void) noexcept override;

	void checkActions(void) noexcept override;
	void returnAction(void) noexcept override;
	void escapeAction(void) noexcept override;
	void leftAction(void) noexcept override;
	void rightAction(void) noexcept override;
	void upAction(void) noexcept override;
	void downAction(void) noexcept override;
	void alphaAction(IndieStudio::Key) noexcept override;

	void refreshSkin(void) noexcept override;

private:
	Button *_solomode;
	Button *_coopmode;
	Button *_1vs1mode;
	Button *_back;
};
}; // namespace IndieStudio

#endif /* !MENUNEW_HPP_ */
