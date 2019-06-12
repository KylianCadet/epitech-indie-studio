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

void IndieStudio::IaMouvement::Ia(std::shared_ptr<IndieStudio::Character> &characVec, std::vector<std::shared_ptr<IndieStudio::Bomb>> bombVec,
std::vector<std::shared_ptr<IndieStudio::Pos>> freePos)
{
        this->_characVec = characVec;
        this->_bombVec = bombVec;
        this->_freePos = freePos;
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        if (isMoving() == false) {
            resetMoving();
            setCenter();
            checkFreeMove();
            chooseDirection();
            this->_characVec->setMovingUp(_freeUp);
            this->_characVec->setMovingDown(_freeDown);
            this->_characVec->setMovingRight(_freeRight);
            this->_characVec->setMovingLeft(_freeLeft);
        }
}

bool checkBomb(int)
{

}

void IndieStudio::IaMouvement::resetMoving()
{
    this->_characVec->setMovingUp(false);
    this->_characVec->setMovingDown(false);
    this->_characVec->setMovingLeft(false);
    this->_characVec->setMovingRight(false);
    this->_freeUp = false;
    this->_freeDown = false;
    this->_freeLeft = false;
    this->_freeRight = false;
    this->_choiceDestination.clear();
}

void IndieStudio::IaMouvement::chooseDirection()
{
    if (this->_choiceDestination.size() > 0) {
        int choose = rand()%((this->_choiceDestination.size() - 1) -0 + 1) + 0;
        resetMoving();
        choose = this->_choiceDestination[choose];
        if (choose == Up) {
            this->_characVec->setMovingUp(true);
            _destination = _destinationUp;
            _freeUp = true;
        } 
        else if (choose == Down) {
            this->_characVec->setMovingDown(true);
            _destination = _destinationDown;
            _freeDown = true;
        }
        else if (choose == Right) {
            this->_characVec->setMovingRight(true);
            _destination = _destinationRight;
            _freeRight = true;
        }
        else if (choose == Left) {
            this->_characVec->setMovingLeft(true);
            _destination = _destinationLeft;
            _freeLeft = true;
        }
    }
}

///////// GET ///////////
bool IndieStudio::IaMouvement::isMoving()
{
    if (_freeUp == false && _freeDown == false && _freeLeft == false && _freeRight == false) {
        return (false);
    }
    if (this->_characVec->getPosition()._x >= _destination._x - ECART && this->_characVec->getPosition()._x <= _destination._x + ECART
    && this->_characVec->getPosition()._z >= _destination._z - ECART && this->_characVec->getPosition()._z <= _destination._z + ECART) {
        setCenter();
        resetMoving();
        return (false);
    }
    return (true);
}

///////// SET ////////////
void IndieStudio::IaMouvement::checkFreeMove()
{
    freeUp();
    freeDown();
    freeLeft();
    freeRight();
}

bool IndieStudio::IaMouvement::freeUp()
{
    float nb = 0;
    float pos = this->_characVec->getPosition()._x + 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb++);
    for (unsigned int i = 0; i != _freePos.size(); i++) {
        if (this->_characVec->getPosition()._z >= _freePos[i]->_z - ECART && this->_characVec->getPosition()._z <= _freePos[i]->_z + ECART && (this->_characVec->getPosition()._x + nb) >= _freePos[i]->_x - ECART && (this->_characVec->getPosition()._x + nb) <= _freePos[i]->_x + ECART) {
            this->_choiceDestination.push_back(Up);
            this->_destinationUp = *_freePos[i];
            this->_freeUp = true;
        }
    }
}
bool IndieStudio::IaMouvement::freeDown()
{
    float nb = 0;
    float pos = this->_characVec->getPosition()._x - 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb--);
    for (unsigned int i = 0; i != _freePos.size(); i++) {
        if (this->_characVec->getPosition()._z >= _freePos[i]->_z - ECART && this->_characVec->getPosition()._z <= _freePos[i]->_z + ECART && (this->_characVec->getPosition()._x + nb) >= _freePos[i]->_x - ECART && (this->_characVec->getPosition()._x + nb) <= _freePos[i]->_x + ECART) {
            this->_choiceDestination.push_back(Down);
            this->_destinationDown = *_freePos[i];
            this->_freeDown = true;
        }
    }
}
bool IndieStudio::IaMouvement::freeLeft()
{
    float nb = 0;
    float pos = this->_characVec->getPosition()._z + 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb++);
    for (unsigned int i = 0; i != _freePos.size(); i++) {
        if (this->_characVec->getPosition()._x >= (_freePos[i]->_x - ECART) && this->_characVec->getPosition()._x <= (_freePos[i]->_x + ECART) && (this->_characVec->getPosition()._z + nb) >= (_freePos[i]->_z - ECART) && (this->_characVec->getPosition()._z + nb) <= _freePos[i]->_z + ECART) {
            this->_choiceDestination.push_back(Left);
            this->_destinationLeft = *_freePos[i];
            this->_freeLeft = true;
        }
    }

}
bool IndieStudio::IaMouvement::freeRight()
{
    float nb = 0;
    float pos = this->_characVec->getPosition()._z - 1;
    for (nb = 0; (int)(pos + nb) % 40 != 0; nb--);
    for (unsigned int i = 0; i != _freePos.size(); i++) {
        if (this->_characVec->getPosition()._x >= _freePos[i]->_x - ECART && this->_characVec->getPosition()._x <= _freePos[i]->_x + ECART && (this->_characVec->getPosition()._z + nb) >= _freePos[i]->_z - ECART && (this->_characVec->getPosition()._z + nb) <= _freePos[i]->_z + ECART) {
            this->_choiceDestination.push_back(Right);
            this->_destinationRight = *_freePos[i];
            this->_freeRight = true;
        }
    }
}

void IndieStudio::IaMouvement::setCenter()
{
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    float pos_RIGHT_LEFT = this->_characVec->getPosition()._z;
    float pos_UP_DOWN = this->_characVec->getPosition()._x;
    for (up = 0; (int)(pos_UP_DOWN + up) % 40 != 0; up++);
    for (down = 0; (int)(pos_UP_DOWN + down) % 40 != 0; down--);
    for (right = 0; (int)(pos_RIGHT_LEFT + right) % 40 != 0; right--);
    for (left = 0; (int)(pos_RIGHT_LEFT + left) % 40 != 0; left++);
    int x = (up < -1*(down) ? up : down) + pos_UP_DOWN;
    int z = (left < -1*(right) ? left : right) + pos_RIGHT_LEFT;
    this->_characVec->setPosition(IndieStudio::Pos{(float)x,this->_characVec->getPosition()._y, (float)z});
}

IndieStudio::IaMouvement::~IaMouvement()
{
}
