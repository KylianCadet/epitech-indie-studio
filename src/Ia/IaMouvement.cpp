/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IaMouvement
*/

#include "IaMouvement.hpp"

IndieStudio::IaMouvement::IaMouvement()
{
}
// IndieStudio::IaMouvement::IaMouvement(IndieStudio::Character &character, std::vector<std::shared_ptr<IndieStudio::Bomb>> bomb) :
// _character(character), _bombPos(bomb)
// {
//     Move();
// }

void IndieStudio::IaMouvement::Ia(IndieStudio::Character & character, std::vector<std::shared_ptr<IndieStudio::Bomb>> bomb, std::vector<IndieStudio::Pos> freePos)
{
    //character.setMovingUp(isCenter(character.getPosition()));
//    setfreePos(character.getPosition(), freePos);
//    std::cout << "SIZE FREE POS " << freePos.size() << "\n";
    if (isMoving(character) == false) {
        // std::cout << "FALSE\n";
        resetMoving(character);
        setCenter(character);
        checkFreeMove(character.getPosition(), freePos);
        // std::cout << "UP " << this->_freeUp << "\n";
        // std::cout << "UP POS " << this->_destinationUp._x << " " << _destinationUp._y << " " << _destinationUp._z << "\n";
        // std::cout << "DOWN " << this->_freeDown << "\n";
        // std::cout << "DOWN POS " << this->_destinationDown._x << " " << _destinationDown._y << " " << _destinationDown._z << "\n";
        // std::cout << "RIGHT " << this->_freeRight << "\n";
        // std::cout << "RIGHT POS " << this->_destinationRight._x << " " << _destinationRight._y << " " << _destinationRight._z << "\n";
        // std::cout << "LEFT " << this->_freeLeft << "\n";
        // std::cout << "LEFT POS " << this->_destinationLeft._x << " " << _destinationLeft._y << " " << _destinationLeft._z << "\n";
        // std::cout << "POS " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
        chooseDirection(character);
    }
    character.setMovingUp(_freeUp);
    character.setMovingDown(_freeDown);
    character.setMovingRight(_freeRight);
    character.setMovingLeft(_freeLeft);
//    std::cout << "DEST POS " << this->_destination._x << " " << _destination._y << " " << _destination._z << "\n";
//    std::cout << "TRUE\n";
}
bool checkBomb(int)
{

}

void IndieStudio::IaMouvement::resetMoving(IndieStudio::Character & character)
{
    character.setMovingUp(false);
    character.setMovingDown(false);
    character.setMovingLeft(false);
    character.setMovingRight(false);
    this->_freeUp = false;
    this->_freeDown = false;
    this->_freeLeft = false;
    this->_freeRight = false;
    this->_choiceDestination.clear();
//    _destination = IndieStudio::Pos{0,0,0};
    // _destinationUp = IndieStudio::Pos{0,0,0};
    // _destinationDown = IndieStudio::Pos{0,0,0};
    // _destinationRight = IndieStudio::Pos{0,0,0};
    // _destinationLeft = IndieStudio::Pos{0,0,0};

}

void IndieStudio::IaMouvement::chooseDirection(IndieStudio::Character & character)
{
    if (this->_choiceDestination.size() > 0) {
//        std::cout << "SIZEEEEEE " << this->_choiceDestination.size() << "\n";
        int choose = rand()%((this->_choiceDestination.size() - 1) -0 + 1) + 0;
        // std::cout << "CHOOSE1 " << choose << "\n";
        resetMoving(character);
        choose = this->_choiceDestination[choose];
        // std::cout << "CHOOSE2 " << choose << "\n";
        if (choose == Up) {
            // std::cout << "UP\n";
            character.setMovingUp(true);
            _destination = _destinationUp;
            _freeUp = true;
        } 
        else if (choose == Down) {
            // std::cout << "DOWN\n";
            character.setMovingDown(true);
            _destination = _destinationDown;
            _freeDown = true;
        }
        else if (choose == Right) {
            // std::cout << "RIGHT\n";
            character.setMovingRight(true);
            _destination = _destinationRight;
            _freeRight = true;
        }
        else if (choose == Left) {
            // std::cout << "LEFT\n";
            character.setMovingLeft(true);
            _destination = _destinationLeft;
            _freeLeft = true;
        }
    }
}

///////// GET ///////////
bool IndieStudio::IaMouvement::isMoving(IndieStudio::Character &character)
{
    if (_freeUp == false && _freeDown == false && _freeLeft == false && _freeRight == false) {
        // std::cout << "ICIIIIIIIII\n";
        return (false);
    }
    // std::cout << "PLAYER " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
    // std::cout << "DESTIN " << _destination._x << " " << _destination._y << " " << _destination._z << "\n";
    if (character.getPosition()._x >= _destination._x - ECART && character.getPosition()._x <= _destination._x + ECART
    && character.getPosition()._z >= _destination._z - ECART && character.getPosition()._z <= _destination._z + ECART) {
        // std::cout << "Arrivedaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
        setCenter(character);
        resetMoving(character);
        // std::cout << "POS " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
        return (false);
    }
    return (true);
}

///////// SET ////////////
void IndieStudio::IaMouvement::checkFreeMove(IndieStudio::Pos character_pos,std::vector<IndieStudio::Pos> freePos)
{
//   std::cout << "POSITION " << character_pos._x << " " << character_pos._y << " " << character_pos._z << "\n";
    freeUp(character_pos, freePos);
    freeDown(character_pos, freePos);
    freeLeft(character_pos, freePos);
    freeRight(character_pos, freePos);
}

bool IndieStudio::IaMouvement::freeUp(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos)
{
    float nb = 0;
    float pos = character_pos._x + 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb++);
    for (unsigned int i = 0; i != freePos.size(); i++) {
        if (character_pos._z >= freePos[i]._z - ECART && character_pos._z <= freePos[i]._z + ECART && (character_pos._x + nb) >= freePos[i]._x - ECART && (character_pos._x + nb) <= freePos[i]._x + ECART) {
            // std::cout << "UP nb = " << nb << "\n";
            this->_choiceDestination.push_back(Up);
            this->_destinationUp = freePos[i];
            this->_freeUp = true;
        }
    }
}
bool IndieStudio::IaMouvement::freeDown(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos)
{
    float nb = 0;
    float pos = character_pos._x - 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb--);
    for (unsigned int i = 0; i != freePos.size(); i++) {
        if (character_pos._z >= freePos[i]._z - ECART && character_pos._z <= freePos[i]._z + ECART && (character_pos._x + nb) >= freePos[i]._x - ECART && (character_pos._x + nb) <= freePos[i]._x + ECART) {
            //  std::cout << "DOWN nb = " << nb << "\n";
            this->_choiceDestination.push_back(Down);
            this->_destinationDown = freePos[i];
            this->_freeDown = true;
        }
    }
}
bool IndieStudio::IaMouvement::freeLeft(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos)
{
    float nb = 0;
    float pos = character_pos._z + 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb++);
    for (unsigned int i = 0; i != freePos.size(); i++) {
        if (character_pos._x >= (freePos[i]._x - ECART) && character_pos._x <= (freePos[i]._x + ECART) && (character_pos._z + nb) >= (freePos[i]._z - ECART) && (character_pos._z + nb) <= freePos[i]._z + ECART) {
            // std::cout << "LEFT nb = " << nb << "\n";
            this->_choiceDestination.push_back(Left);
            this->_destinationLeft = freePos[i];
            this->_freeLeft = true;
        }
    }

}
bool IndieStudio::IaMouvement::freeRight(IndieStudio::Pos character_pos, std::vector<IndieStudio::Pos> freePos)
{
    float nb = 0;
    float pos = character_pos._z - 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb--);
    for (unsigned int i = 0; i != freePos.size(); i++) {
        if (character_pos._x >= freePos[i]._x - ECART && character_pos._x <= freePos[i]._x + ECART && (character_pos._z + nb) >= freePos[i]._z - ECART && (character_pos._z + nb) <= freePos[i]._z + ECART) {
            //  std::cout << "RIGHT nb = " << nb << "\n";
            this->_choiceDestination.push_back(Right);
            this->_destinationRight = freePos[i];
            this->_freeRight = true;
        }
    }
}

void IndieStudio::IaMouvement::setCenter(IndieStudio::Character & character)
{
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    float pos_RIGHT_LEFT = character.getPosition()._z;
    float pos_UP_DOWN = character.getPosition()._x;
    for (up = 0; (int)(pos_UP_DOWN + up) % 40 != 0; up++);
    for (down = 0; (int)(pos_UP_DOWN + down) % 40 != 0; down--);
    for (right = 0; (int)(pos_RIGHT_LEFT + right) % 40 != 0; right--);
    for (left = 0; (int)(pos_RIGHT_LEFT + left) % 40 != 0; left++);
    int x = (up < -1*(down) ? up : down) + pos_UP_DOWN;
    int z = (left < -1*(right) ? left : right) + pos_RIGHT_LEFT;
    character.setPosition(IndieStudio::Pos{(float)x,character.getPosition()._y, (float)z});
}

IndieStudio::IaMouvement::~IaMouvement()
{
}
