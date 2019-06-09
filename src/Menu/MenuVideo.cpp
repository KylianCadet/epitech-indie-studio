/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuVideo
*/

#include "MenuVideo.hpp"

IndieStudio::MenuVideo::MenuVideo(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(graphical, volume, sounds)
{
	this->_renderStatus = MENU_VIDEO_MAIN;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuVideo::~MenuVideo()
{
}

void IndieStudio::MenuVideo::createButtons(void) noexcept
{
}

void IndieStudio::MenuVideo::drawButtons(void) noexcept
{
}

void IndieStudio::MenuVideo::createImages(void) noexcept
{
	this->_comingsoon = this->_graphical.createImage("assets/menu/comingsoon.png", std::pair<int, int>(-1, 500));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuVideo::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_comingsoon);
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuVideo::checkActions(void) noexcept
{
}

void IndieStudio::MenuVideo::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuVideo::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_VIDEO_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_VIDEO_BACK)
		this->drawMenu();
}

void IndieStudio::MenuVideo::refreshSkin(void) noexcept
{
}

void IndieStudio::MenuVideo::returnAction(void) noexcept
{
}

void IndieStudio::MenuVideo::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_VIDEO_BACK;
}

void IndieStudio::MenuVideo::leftAction(void) noexcept
{
}

void IndieStudio::MenuVideo::rightAction(void) noexcept
{
}

void IndieStudio::MenuVideo::upAction(void) noexcept
{
}

void IndieStudio::MenuVideo::downAction(void) noexcept
{
}

void IndieStudio::MenuVideo::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuVideo::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_VIDEO_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_VIDEO_BACK)
		this->escapeAction();
}

void IndieStudio::MenuVideo::leftActionManager(void) noexcept
{
}

void IndieStudio::MenuVideo::rightActionManager(void) noexcept
{
}

void IndieStudio::MenuVideo::upActionManager(void) noexcept
{
}

void IndieStudio::MenuVideo::downActionManager(void) noexcept
{
}

void IndieStudio::MenuVideo::alphaActionManager(IndieStudio::Key key) noexcept
{
}

void IndieStudio::MenuVideo::alphaAction(IndieStudio::Key key) noexcept
{
}