/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include <irrlicht.h>
#include "Game.hpp"
#include "MenuManager.hpp"
#include "MusicManager.hpp"
#include "Volume.hpp"
#include "Config.hpp"
#include "IrrGraphical.hpp"

int main()
{
	IndieStudio::IrrGraphical graphical;
	Render render = Render::MAIN_MENU;

	IndieStudio::Config *config = new IndieStudio::Config();
	IndieStudio::Volume *volume = new IndieStudio::Volume();
	IndieStudio::MusicManager musicManager(volume);
	IndieStudio::MenuManager menu(render, graphical, volume, config);
	IndieStudio::Game game(graphical, render);

	while (graphical.run())
	{
		graphical.startRender();
		musicManager.refreshMusic(render);
		if (render == Render::GAME_SOLO || render == Render::GAME_1V1 || render == Render::GAME_COOP)
			game.render();
		else if (render == Render::MAIN_MENU || Render::PAUSE_MENU)
			menu.render();
		graphical.endRender();
	}
	graphical.drop();
	return 0;
}