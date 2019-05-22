/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <SFML/Audio.hpp>

namespace IndieStudio {
	class Audio {
		public:
			Audio(std::string audioPath);
			~Audio();
			void playSound() noexcept;
			void stopSound() noexcept;
		private:
			sf::SoundBuffer _soundBuffer;
			sf::Sound _sound;
	};
};

#endif