/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuOptions
*/

#ifndef MENUOPTIONS_HPP_
#define MENUOPTIONS_HPP_

#include <irrlicht.h>
#include <iostream>
#include "Audio.hpp"
#include "Button.hpp"
#include "IMenu.hpp"

namespace IndieStudio
{
	class MenuOptions
	{
	public:
		MenuOptions(irr::video::IVideoDriver *);
		~MenuOptions();

		void setVolumeBar(int) noexcept;
		void setLeftArrowActive(void) noexcept;
		void setRightArrowActive(void) noexcept;
		void setLeftArrowDefault(void) noexcept;
		void setRightArrowDefault(void) noexcept;

		virtual void drawMenu(void) noexcept;
		virtual void refreshSkin(void) noexcept;

	private:
		int _leftTime = 0;
		int _rightTime = 0;

		irr::video::IVideoDriver *_driver;

		IndieStudio::Button *_leftArrow;
		IndieStudio::Button *_rightArrow;

		IndieStudio::Image2d *_volumeBarEmpty;
		IndieStudio::Image2d *_volumeBarFilled;
		IndieStudio::Image2d *_escapeInfo;
	};
}; // namespace IndieStudio

#endif /* !MENUOPTIONS_HPP_ */
