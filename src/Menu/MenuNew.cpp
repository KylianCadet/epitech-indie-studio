/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuNew
*/

#include "MenuNew.hpp"

IndieStudio::MenuNew::MenuNew(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config)
	: Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_NEW_MAIN;
	this->_buttonStatus = BTN_NEW_GAMEMODE;
	this->_modeStatus = MODE_COOP;
	this->_player1Status = PLAYER1_STARFOX;
	this->_player2Status = PLAYER2_CARTMAN;
	this->_toolStatus = BTN_TOOL_PLAY;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuNew::~MenuNew()
{
}

void IndieStudio::MenuNew::createButtons(void) noexcept
{
	int x = 550;
	int pos = 400;
	int off = 110;

	this->_gamemode = new Button(this->_graphical, "assets/menu/game/gamemode.png", "assets/menu/game/gamemodeA.png", std::pair<int, int>(x, pos));
	this->_player1 = new Button(this->_graphical, "assets/menu/game/player1.png", "assets/menu/game/player1A.png", std::pair<int, int>(x - 50, (pos + 110)));
	this->_player2 = new Button(this->_graphical, "assets/menu/game/player2.png", "assets/menu/game/player2A.png", std::pair<int, int>(x - 45, (pos + 220)));

	this->_solo = new Button(this->_graphical, "assets/menu/game/solo.png", "assets/menu/game/soloA.png", std::pair<int, int>(x + 400, pos));
	this->_coop = new Button(this->_graphical, "assets/menu/game/coop.png", "assets/menu/game/coopA.png", std::pair<int, int>(x + 400, pos));
	this->_duel = new Button(this->_graphical, "assets/menu/game/duel.png", "assets/menu/game/duelA.png", std::pair<int, int>(x + 400, pos));

	this->_bob1 = new Button(this->_graphical, "assets/menu/game/bob.png", "assets/menu/game/bobA.png", std::pair<int, int>(x + 400, (pos + 110)));
	this->_cartman1 = new Button(this->_graphical, "assets/menu/game/cartman.png", "assets/menu/game/cartmanA.png", std::pair<int, int>(x + 400, (pos + 110)));
	this->_starfox1 = new Button(this->_graphical, "assets/menu/game/starfox.png", "assets/menu/game/starfoxA.png", std::pair<int, int>(x + 400, (pos + 110)));
	this->_yoshi1 = new Button(this->_graphical, "assets/menu/game/yoshi.png", "assets/menu/game/yoshiA.png", std::pair<int, int>(x + 400, (pos + 110)));

	this->_bob2 = new Button(this->_graphical, "assets/menu/game/bob.png", "assets/menu/game/bobA.png", std::pair<int, int>(x + 400, (pos + 220)));
	this->_cartman2 = new Button(this->_graphical, "assets/menu/game/cartman.png", "assets/menu/game/cartmanA.png", std::pair<int, int>(x + 400, (pos + 220)));
	this->_starfox2 = new Button(this->_graphical, "assets/menu/game/starfox.png", "assets/menu/game/starfoxA.png", std::pair<int, int>(x + 400, (pos + 220)));
	this->_yoshi2 = new Button(this->_graphical, "assets/menu/game/yoshi.png", "assets/menu/game/yoshiA.png", std::pair<int, int>(x + 400, (pos + 220)));

	this->_back = new Button(this->_graphical, "assets/menu/buttons/back.png", "assets/menu/buttons/backA.png", std::pair<int, int>(400, 750));
	this->_play = new Button(this->_graphical, "assets/menu/buttons/play.png", "assets/menu/buttons/playA.png", std::pair<int, int>(900, 750));
}

void IndieStudio::MenuNew::drawButtons(void) noexcept
{
	this->_gamemode->drawButton();
	this->_player1->drawButton();
	this->_player2->drawButton();
	this->_back->drawButton();
	this->_play->drawButton();
	if (this->_modeStatus == MODE_SOLO)
		this->_solo->drawButton();
	else if (this->_modeStatus == MODE_COOP)
		this->_coop->drawButton();
	else if (this->_modeStatus == MODE_DUEL)
		this->_duel->drawButton();
	if (this->_player1Status == PLAYER1_BOB)
		this->_bob1->drawButton();
	else if (this->_player1Status == PLAYER1_CARTMAN)
		this->_cartman1->drawButton();
	else if (this->_player1Status == PLAYER1_STARFOX)
		this->_starfox1->drawButton();
	else if (this->_player1Status == PLAYER1_YOSHI)
		this->_yoshi1->drawButton();
	if (this->_player2Status == PLAYER2_BOB)
		this->_bob2->drawButton();
	else if (this->_player2Status == PLAYER2_CARTMAN)
		this->_cartman2->drawButton();
	else if (this->_player2Status == PLAYER2_STARFOX)
		this->_starfox2->drawButton();
	else if (this->_player2Status == PLAYER2_YOSHI)
		this->_yoshi2->drawButton();
}

void IndieStudio::MenuNew::createImages(void) noexcept
{
}

void IndieStudio::MenuNew::drawImages(void) noexcept
{
}

void IndieStudio::MenuNew::checkActions(void) noexcept
{
}

void IndieStudio::MenuNew::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuNew::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->drawMenu();
}

void IndieStudio::MenuNew::refreshSkin(void) noexcept
{
	this->_gamemode->setDefaultSkin();
	this->_player1->setDefaultSkin();
	this->_player2->setDefaultSkin();

	this->_play->setDefaultSkin();
	this->_back->setDefaultSkin();

	this->_solo->setDefaultSkin();
	this->_coop->setDefaultSkin();
	this->_duel->setDefaultSkin();

	this->_bob1->setDefaultSkin();
	this->_cartman1->setDefaultSkin();
	this->_starfox1->setDefaultSkin();
	this->_yoshi1->setDefaultSkin();

	this->_bob2->setDefaultSkin();
	this->_cartman2->setDefaultSkin();
	this->_starfox2->setDefaultSkin();
	this->_yoshi2->setDefaultSkin();

	if (this->_buttonStatus == BTN_NEW_GAMEMODE)
	{
		this->_gamemode->setActiveSkin();
		if (this->_modeStatus == MODE_SOLO)
			this->_solo->setActiveSkin();
		else if (this->_modeStatus == MODE_COOP)
			this->_coop->setActiveSkin();
		else if (this->_modeStatus == MODE_DUEL)
			this->_duel->setActiveSkin();
	}
	else if (this->_buttonStatus == BTN_NEW_PLAYER1)
	{
		this->_player1->setActiveSkin();
		if (this->_player1Status == PLAYER1_BOB)
			this->_bob1->setActiveSkin();
		else if (this->_player1Status == PLAYER1_CARTMAN)
			this->_cartman1->setActiveSkin();
		else if (this->_player1Status == PLAYER1_STARFOX)
			this->_starfox1->setActiveSkin();
		else if (this->_player1Status == PLAYER1_YOSHI)
			this->_yoshi1->setActiveSkin();
	}
	else if (this->_buttonStatus == BTN_NEW_PLAYER2)
	{
		this->_player2->setActiveSkin();
		if (this->_player2Status == PLAYER2_BOB)
			this->_bob2->setActiveSkin();
		else if (this->_player2Status == PLAYER2_CARTMAN)
			this->_cartman2->setActiveSkin();
		else if (this->_player2Status == PLAYER2_STARFOX)
			this->_starfox2->setActiveSkin();
		else if (this->_player2Status == PLAYER2_YOSHI)
			this->_yoshi2->setActiveSkin();
	}
	else if (this->_buttonStatus == BTN_NEW_PLAY)
	{
		if (this->_toolStatus == BTN_TOOL_BACK)
			this->_back->setActiveSkin();
		else if (this->_toolStatus == BTN_TOOL_PLAY)
			this->_play->setActiveSkin();
	}
}

void IndieStudio::MenuNew::returnAction(void) noexcept
{
	if (this->_buttonStatus == BTN_NEW_PLAY)
	{
		this->_sounds->_buttonReturnSound->playSound();
		if (this->_toolStatus == BTN_TOOL_BACK)
			this->_renderStatus = MENU_NEW_BACK;
		else if (this->_toolStatus == BTN_TOOL_PLAY)
		{
			this->_renderStatus = MENU_NEW_GAME;
			if (this->_modeStatus == MODE_SOLO)
				this->_config->setMode(SOLO);
			else if (this->_modeStatus == MODE_COOP)
				this->_config->setMode(COOP);
			else if (this->_modeStatus == MODE_DUEL)
				this->_config->setMode(DUEL);
			if (this->_player1Status == PLAYER1_BOB)
				this->_config->setPlayer1Skin("Sponge Bob");
			else if (this->_player1Status == PLAYER1_CARTMAN)
				this->_config->setPlayer1Skin("Eric Cartman");
			else if (this->_player1Status == PLAYER1_STARFOX)
				this->_config->setPlayer1Skin("Fox");
			else if (this->_player1Status == PLAYER1_YOSHI)
				this->_config->setPlayer1Skin("Yoshi");
			if (this->_player2Status == PLAYER2_BOB)
				this->_config->setPlayer2Skin("Sponge Bob");
			else if (this->_player2Status == PLAYER2_CARTMAN)
				this->_config->setPlayer2Skin("Eric Cartman");
			else if (this->_player2Status == PLAYER2_STARFOX)
				this->_config->setPlayer2Skin("Fox");
			else if (this->_player2Status == PLAYER2_YOSHI)
				this->_config->setPlayer2Skin("Yoshi");
		}
	}
}

void IndieStudio::MenuNew::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_NEW_BACK;
}

void IndieStudio::MenuNew::leftAction(void) noexcept
{
	if (this->_buttonStatus == BTN_NEW_GAMEMODE)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_modeStatus--;
		if (this->_modeStatus > 2)
			this->_modeStatus = 0;
		else if (this->_modeStatus < 0)
			this->_modeStatus = 2;
	}
	else if (this->_buttonStatus == BTN_NEW_PLAYER1)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_player1Status--;
		if (this->_player1Status > 3)
			this->_player1Status = 0;
		else if (this->_player1Status < 0)
			this->_player1Status = 3;
		if ((this->_player1Status == PLAYER1_BOB && this->_player2Status == PLAYER2_BOB) || (this->_player1Status == PLAYER1_CARTMAN && this->_player2Status == PLAYER2_CARTMAN) || (this->_player1Status == PLAYER1_STARFOX && this->_player2Status == PLAYER2_STARFOX) || (this->_player1Status == PLAYER1_YOSHI && this->_player2Status == PLAYER2_YOSHI))
			this->_player1Status--;
		if (this->_player1Status > 3)
			this->_player1Status = 0;
		else if (this->_player1Status < 0)
			this->_player1Status = 3;
	}
	else if (this->_buttonStatus == BTN_NEW_PLAYER2)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_player2Status--;
		if (this->_player2Status > 3)
			this->_player2Status = 0;
		else if (this->_player2Status < 0)
			this->_player2Status = 3;
		if ((this->_player1Status == PLAYER1_BOB && this->_player2Status == PLAYER2_BOB) || (this->_player1Status == PLAYER1_CARTMAN && this->_player2Status == PLAYER2_CARTMAN) || (this->_player1Status == PLAYER1_STARFOX && this->_player2Status == PLAYER2_STARFOX) || (this->_player1Status == PLAYER1_YOSHI && this->_player2Status == PLAYER2_YOSHI))
			this->_player2Status--;
		if (this->_player2Status > 3)
			this->_player2Status = 0;
		else if (this->_player2Status < 0)
			this->_player2Status = 3;
	}
	else if (this->_buttonStatus == BTN_NEW_PLAY)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_toolStatus--;
		if (this->_toolStatus > 1)
			this->_toolStatus = 0;
		else if (this->_toolStatus < 0)
			this->_toolStatus = 1;
	}
}

void IndieStudio::MenuNew::rightAction(void) noexcept
{
	if (this->_buttonStatus == BTN_NEW_GAMEMODE)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_modeStatus++;
		if (this->_modeStatus > 2)
			this->_modeStatus = 0;
		else if (this->_modeStatus < 0)
			this->_modeStatus = 2;
	}
	else if (this->_buttonStatus == BTN_NEW_PLAYER1)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_player1Status++;
		if (this->_player1Status > 3)
			this->_player1Status = 0;
		else if (this->_player1Status < 0)
			this->_player1Status = 3;
		if ((this->_player1Status == PLAYER1_BOB && this->_player2Status == PLAYER2_BOB) || (this->_player1Status == PLAYER1_CARTMAN && this->_player2Status == PLAYER2_CARTMAN) || (this->_player1Status == PLAYER1_STARFOX && this->_player2Status == PLAYER2_STARFOX) || (this->_player1Status == PLAYER1_YOSHI && this->_player2Status == PLAYER2_YOSHI))
			this->_player1Status++;
		if (this->_player1Status > 3)
			this->_player1Status = 0;
		else if (this->_player1Status < 0)
			this->_player1Status = 3;
	}
	else if (this->_buttonStatus == BTN_NEW_PLAYER2)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_player2Status++;
		if (this->_player2Status > 3)
			this->_player2Status = 0;
		else if (this->_player2Status < 0)
			this->_player2Status = 3;
		if ((this->_player1Status == PLAYER1_BOB && this->_player2Status == PLAYER2_BOB) || (this->_player1Status == PLAYER1_CARTMAN && this->_player2Status == PLAYER2_CARTMAN) || (this->_player1Status == PLAYER1_STARFOX && this->_player2Status == PLAYER2_STARFOX) || (this->_player1Status == PLAYER1_YOSHI && this->_player2Status == PLAYER2_YOSHI))
			this->_player2Status++;
		if (this->_player2Status > 3)
			this->_player2Status = 0;
		else if (this->_player2Status < 0)
			this->_player2Status = 3;
	}
	else if (this->_buttonStatus == BTN_NEW_PLAY)
	{
		this->_sounds->_buttonSwitchSound->playSound();
		this->_toolStatus++;
		if (this->_toolStatus > 1)
			this->_toolStatus = 0;
		else if (this->_toolStatus < 0)
			this->_toolStatus = 1;
	}
}

void IndieStudio::MenuNew::upAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuNew::downAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuNew::returnActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->returnAction();
}

void IndieStudio::MenuNew::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->escapeAction();
}

void IndieStudio::MenuNew::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->leftAction();
}

void IndieStudio::MenuNew::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->rightAction();
}

void IndieStudio::MenuNew::upActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->upAction();
}

void IndieStudio::MenuNew::downActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_NEW_MAIN)
		this->downAction();
}

void IndieStudio::MenuNew::alphaActionManager(IndieStudio::Key key) noexcept
{
}

void IndieStudio::MenuNew::alphaAction(IndieStudio::Key key) noexcept
{
}