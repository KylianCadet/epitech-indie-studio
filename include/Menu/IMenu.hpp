/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IMenu
*/

#ifndef IMENU_HPP_
#define IMENU_HPP_

class IMenu
{
	public:
		virtual ~IMenu() = default;
		virtual void drawMenu(void) noexcept = 0;
		virtual void refreshSkin(void) noexcept = 0;
		virtual void setButtonSwitch(int) noexcept = 0;
		virtual void setButtonActive(int) noexcept = 0;
		virtual int getCurrentButtonActive(void) const noexcept = 0;

	protected:
	private:
};

#endif /* !IMENU_HPP_ */
