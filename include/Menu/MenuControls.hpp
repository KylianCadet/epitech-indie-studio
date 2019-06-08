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

static const int MENU_CONTROLS_PLY_1 = 0;
static const int MENU_CONTROLS_PLY_2 = 1;

#include "Menu.hpp"

namespace IndieStudio
{

struct letter
{
	std::string _str;
	Button *_btn;
	Key _key;
};

class MenuControls : public Menu
{
public:
	MenuControls(IGraphical &, Volume *, MenuSounds *, Config *);
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
	int _playerStatus;

	IEntity *_player1;
	IEntity *_player2;
	Button *_forward;
	Button *_back;
	Button *_left;
	Button *_right;
	Button *_bomb;
	IEntity *_escapeInfo;

	std::vector<letter> _letters;

	letter _upKey;
	letter _downKey;
	letter _leftKey;
	letter _rightKey;
	letter _bombKey;
};
}; // namespace IndieStudio

#endif /* !MENULOAD_HPP_ */
