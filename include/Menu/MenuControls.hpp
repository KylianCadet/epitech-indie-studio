/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuLoad
*/

#ifndef MENUCONTROLS_HPP_
#define MENUCONTROLS_HPP_

static const int MENU_CONTROLS_MAIN = 0;
static const int MENU_CONTROLS_BACK = 1;

#include "Menu.hpp"

namespace IndieStudio
{
class MenuControls : public Menu
{
public:
	MenuControls(IGraphical &, Volume *, MenuSounds *);
	~MenuControls();

public:
	void drawMenuManager(void) noexcept override;
	void returnActionManager(void) noexcept override;
	void escapeActionManager(void) noexcept override;
	void leftActionManager(void) noexcept override;
	void rightActionManager(void) noexcept override;
	void upActionManager(void) noexcept override;
	void downActionManager(void) noexcept override;

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

	void refreshSkin(void) noexcept override;

private:
	IEntity *_player1;
	IEntity *_forward;
	IEntity *_back;
	IEntity *_left;
	IEntity *_right;
	IEntity *_action;
	IEntity *_escapeInfo;

	IEntity *_Z;
	IEntity *_S;
	IEntity *_Q;
	IEntity *_D;
	IEntity *_E;
};
}; // namespace IndieStudio

#endif /* !MENULOAD_HPP_ */
