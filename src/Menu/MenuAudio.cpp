/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuAudio
*/

#include "MenuAudio.hpp"

IndieStudio::MenuAudio::MenuAudio(irr::video::IVideoDriver *driver, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(driver, volume, sounds)
{
	this->createButtons();
	this->createImages();
	this->setVolumeBar();
}

IndieStudio::MenuAudio::~MenuAudio()
{
}

void IndieStudio::MenuAudio::createButtons(void) noexcept
{
	this->_leftArrow = new Button(this->_driver, "assets/menu/options/left.png", "assets/menu/options/leftA.png", std::pair<int, int>(-1, 435));
	this->_rightArrow = new Button(this->_driver, "assets/menu/options/right.png", "assets/menu/options/rightA.png", std::pair<int, int>(-1, 435));
}

void IndieStudio::MenuAudio::drawButtons(void) noexcept
{
	this->_leftArrow->drawButton();
	this->_rightArrow->drawButton();
}

void IndieStudio::MenuAudio::createImages(void) noexcept
{
	this->_volumeBarEmpty = new IndieStudio::Image2d(this->_driver, "assets/menu/options/empty2.png", std::pair<int, int>(-1, 400));
	this->_volumeBarFilled = new IndieStudio::Image2d(this->_driver, "assets/menu/options/filled.png", std::pair<int, int>(-1, 400));
	this->_escapeInfo = new IndieStudio::Image2d(this->_driver, "assets/menu/options/esc.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuAudio::drawImages(void) noexcept
{
	this->_volumeBarEmpty->drawImage();
	this->_volumeBarFilled->drawImage();
	this->_escapeInfo->drawImage();
}

void IndieStudio::MenuAudio::drawMenuManager(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuAudio::refreshSkin(void) noexcept
{
	if (this->_leftTime <= 0)
		this->_leftArrow->setDefaultSkin();
	else
		this->_leftTime--;
	if (this->_rightTime <= 0)
		this->_rightArrow->setDefaultSkin();
	else
		this->_rightTime--;
}

void IndieStudio::MenuAudio::setVolumeBar(void) noexcept
{
	int vol = 0;
	int volume = this->_volume->getVolumeMusics() / 10;
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
	this->_volumeBarFilled->setCustomRectangle(0, 0, vol, 208);
}

void IndieStudio::MenuAudio::returnActionManager(void) noexcept
{

}

void IndieStudio::MenuAudio::escapeActionManager(void) noexcept
{
	this->_renderStatus = MENU_AUDIO_BACK;
}

void IndieStudio::MenuAudio::leftActionManager(void) noexcept
{
	this->_leftTime = 50;
	this->_leftArrow->setActiveSkin();
	this->_sounds->_volumeSwitchSound->playSound();
	this->_volume->setVolumeMusics(this->_volume->getVolumeMusics() - 10);
	this->setVolumeBar();
}

void IndieStudio::MenuAudio::rightActionManager(void) noexcept
{
	this->_rightTime = 50;
	this->_rightArrow->setActiveSkin();
	this->_sounds->_volumeSwitchSound->playSound();
	this->_volume->setVolumeMusics(this->_volume->getVolumeMusics() + 10);
	this->setVolumeBar();
}

void IndieStudio::MenuAudio::upActionManager(void) noexcept
{

}

void IndieStudio::MenuAudio::downActionManager(void) noexcept
{

}