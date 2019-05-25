/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuOptions
*/

#include "MenuOptions.hpp"

IndieStudio::MenuOptions::MenuOptions(irr::video::IVideoDriver *driver)
	: _driver(driver)
{
	_volumeBarEmpty = new IndieStudio::Image2d(driver, "assets/menu/options/empty.png", std::pair<int, int>(-1, 400));
	_volumeBarFilled = new IndieStudio::Image2d(driver, "assets/menu/options/filled.png", std::pair<int, int>(-1, 400));
	_escapeInfo = new IndieStudio::Image2d(driver, "assets/menu/options/esc.png", std::pair<int, int>(-1, 800));
	_leftArrow = new Button(_driver, "assets/menu/options/left.png", "assets/menu/options/leftA.png", std::pair<int, int>(-1, 435));
	_rightArrow = new Button(_driver, "assets/menu/options/right.png", "assets/menu/options/rightA.png", std::pair<int, int>(-1, 435));
}

IndieStudio::MenuOptions::~MenuOptions()
{
}

void IndieStudio::MenuOptions::drawMenu(void) noexcept
{
	refreshSkin();
	_volumeBarEmpty->drawImage();
	_volumeBarFilled->drawImage();
	_escapeInfo->drawImage();
	_leftArrow->drawButton();
	_rightArrow->drawButton();
}

void IndieStudio::MenuOptions::refreshSkin(void) noexcept
{
	if (_leftTime <= 0)
		_leftArrow->setDefaultSkin();
	else
		_leftTime--;
	if (_rightTime <= 0)
		_rightArrow->setDefaultSkin();
	else
		_rightTime--;
}

void IndieStudio::MenuOptions::setVolumeBar(int volume) noexcept
{
	int vol = 0;
	if (volume == 0)
		vol = 0;
	else if (volume == 1)
		vol = 50;
	else if (volume == 2)
		vol = 90;
	else if (volume == 3)
		vol = 130;
	else if (volume == 4)
		vol = 170;
	else if (volume == 5)
		vol = 200;
	else if (volume == 6)
		vol = 230;
	else if (volume == 7)
		vol = 270;
	else if (volume == 8)
		vol = 300;
	else if (volume == 9)
		vol = 330;
	else if (volume == 10)
		vol = 395;
	_volumeBarFilled->setCustomRectangle(0, 0, vol, 208);
}

void IndieStudio::MenuOptions::setLeftArrowActive(void) noexcept
{
	_leftTime = 50;
	_leftArrow->setActiveSkin();
}

void IndieStudio::MenuOptions::setRightArrowActive(void) noexcept
{
	_rightTime = 50;
	_rightArrow->setActiveSkin();
}