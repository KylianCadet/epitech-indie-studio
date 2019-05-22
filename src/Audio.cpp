/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Audio
*/

#include "Audio.hpp"

IndieStudio::Audio::Audio(std::string audioPath)
{
	if (!this->_soundBuffer.loadFromFile(audioPath))
		exit(84);
	this->_sound.setBuffer(this->_soundBuffer);
}

IndieStudio::Audio::~Audio()
{
}

void IndieStudio::Audio::playSound() noexcept
{
	if (this->_sound.getStatus() == sf::SoundSource::Status::Stopped)
		this->_sound.play();
}

void IndieStudio::Audio::stopSound() noexcept
{
	this->_sound.stop();
}