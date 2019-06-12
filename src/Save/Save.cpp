/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Save
*/

#include "Save.hpp"


IndieStudio::Save::Save()
{
}

IndieStudio::Save::Save(std::vector<IndieStudio::IEntity *> const & brick, std::vector<IndieStudio::IEntity *> const & outside, std::vector<IndieStudio::IEntity *> const & inside, std::vector<std::shared_ptr<IndieStudio::Character>> character, float x, float y, float cube_size)
{
    this->_brickVec = brick;
    this->_wallOutsideVec = outside;
    this->_wallInsideVec = inside;
    this->_characterVec = character;
    this->_x_map = x;
    this->_y_map = y;
    this->_cube_size = cube_size;
}

void IndieStudio::Save::creatSave() noexcept
{
    generateSave();
    std::ofstream mapFile(MAP_TXT_PATH);
    if (mapFile.is_open()) {
        for (unsigned int i = 0; i != this->_mapTxt.size(); i++)
            mapFile << this->_mapTxt[i] << "\n";
    }
    mapFile.close();
    std::ofstream playerFile(PLAYER_TXT_PATH);
    if (playerFile.is_open()) {
        for (unsigned int i = 0; i != this->_playerPosition.size(); i++)
            playerFile << this->_playerPosition[i];
    }
}

void IndieStudio::Save::generateSave() noexcept
{
    generateMap();
    generatePlayerPosition();
}

void IndieStudio::Save::generatePlayerPosition() noexcept
{
    std::string line = "";
    for (unsigned int i = 0; i != this->_characterVec.size(); i++) {
        line = "";
        line.append(this->_characterVec[i]->getName()); // NAME
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getPosition()._x)); // pos X
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getPosition()._y)); // pos Y
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getPosition()._z)); // pos Z
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getSpeed())); // SPEED
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getBombMax())); // BOMB MAX
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getBombSize())); // BOMB SIZE;
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getBot())); // BOT
        line.append(";");
        line.append(std::to_string(this->_characterVec[i]->getDeath())); // DEATH
        line.append(";\n");
        this->_playerPosition.push_back(line);
    }
}

void IndieStudio::Save::generateMap() noexcept
{
    std::vector<std::string> save_txt;
    std::string line = "";
    int ecart = this->_cube_size / 2;
    auto isCube = [](IndieStudio::Pos pos, std::vector<IndieStudio::IEntity*> cube) {
        for (unsigned int i = 0; i != cube.size(); i++) {
            if (cube[i]->getPosition() == pos)
                return (true);
        }
        return (false);
    };
    for (float y = 0, i = 0; y != this->_y_map * _cube_size; y += _cube_size, i++) {
        line = "";
        for (float x = 0, j = 0; x != this->_x_map * _cube_size; x += _cube_size, j++) {
            if (isCube(IndieStudio::Pos{y,_cube_size,x}, this->_wallOutsideVec) == true) {
                line.append("#");
            }
            else if (isCube(IndieStudio::Pos{y,_cube_size,x}, this->_wallInsideVec) == true) {
                line.append("#");
            }
            else if (isCube(IndieStudio::Pos{y,_cube_size,x}, this->_brickVec) == true) {
                line.append("B");
            }
            else {
                line.append(".");
            }
        }
        save_txt.push_back(reverseStr(line));
    }
}

std::string IndieStudio::Save::reverseStr(std::string &str) noexcept
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		std::swap(str[i], str[n - i - 1]);
	return (str);
}

//////////// GET ////////////

std::vector<std::string> IndieStudio::Save::getTxt(std::string path) noexcept
{
    std::string line;
    std::ifstream myfile (path);
    std::vector<std::string> txt;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) ) {
            txt.push_back(line);
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file"; 
    return (txt);
}

std::vector<std::string> IndieStudio::Save::getMapByTxt() noexcept
{
    return (getTxt(MAP_TXT_PATH));
}

std::string getMapFile() noexcept
{
    return (MAP_TXT_PATH);
}

std::vector<std::shared_ptr<IndieStudio::Character>> IndieStudio::Save::configPlayerByTxt(std::vector<std::shared_ptr<IndieStudio::Character>> &charac) noexcept
{
    std::vector<std::shared_ptr<IndieStudio::Character>> player;
    std::vector<std::string> playerTxt = getTxt(PLAYER_TXT_PATH);
    std::vector<std::string> tab;
    for (unsigned int i = 0; i != playerTxt.size(); i++) {
        tab = splitTxt(playerTxt[i], ";");
        for (unsigned int j = 0; j != charac.size(); j++) {
            if (charac[i]->getName() == tab[0]) {
                try {
                    charac[i]->setPosition(IndieStudio::Pos{float(std::stoi(tab[1])),float(std::stoi(tab[2])),float(std::stoi(tab[3]))});
                    charac[i]->setSpeed(float(std::stoi(tab[4])));
                    charac[i]->setBombMax(float(std::stoi(tab[5])));
                    charac[i]->setBombSize(float(std::stoi(tab[6])));
                    charac[i]->setBot(bool(std::stoi(tab[7])));
                    charac[i]->setDeath(bool(std::stoi(tab[8])));
                } catch (std::invalid_argument const &e) {
                    std::cout << "SAVE : ERROR DATA\n";
                } catch (std::out_of_range const &e) {
                    std::cout << "SAVE : OUT OF RANGE\n";
                }
            }
        }
    }
    return (player);
}

std::vector<std::string> IndieStudio::Save::splitTxt(std::string line, std::string delimiter) noexcept
{
    size_t pos = 0;
    std::string token;
    std::vector<std::string> tab;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        tab.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    return (tab);
}
//////////// SET ////////////

void IndieStudio::Save::setBrickVec(std::vector<IndieStudio::IEntity *> const &cube) noexcept
{
    this->_brickVec = cube;
}
void IndieStudio::Save::setWallOutsideVec(std::vector<IndieStudio::IEntity *> const &cube) noexcept
{
    this->_wallOutsideVec = cube;
}
void IndieStudio::Save::setWallInsideVec(std::vector<IndieStudio::IEntity *> const &cube) noexcept
{
    this->_wallInsideVec = cube;
}

void IndieStudio::Save::setDimensionMap(float x, float y, float cube_size) noexcept
{
    this->_x_map = x;
    this->_y_map = y;
    this->_cube_size = cube_size;
}

void IndieStudio::Save::setCharacterVec(std::vector<std::shared_ptr<IndieStudio::Character>> character) noexcept
{
    this->_characterVec = character;
}



IndieStudio::Save::~Save()
{
}
