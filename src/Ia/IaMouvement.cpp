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
// IndieStudio::IaMouvement::IaMouvement(std::vector<IndieStudio::Character> &character) :
// _characVec(character)
// {
//     Move();
// }

void IndieStudio::IaMouvement::createIa()
{
    //static int j = 0;
    // std::cout << "charac size = " << _characVec.size() << "\n";
    // for (unsigned int i = 0; i != _characVec.size(); i++) {
    //     if (_characVec[i]->getBot() == true) {
    //         this->_th.emplace_back(&IndieStudio::IaMouvement::Ia, this, i);
    //     }
    // }
    //this->_th = std::thread(&IndieStudio::IaMouvement::Ia, this);
}


void IndieStudio::IaMouvement::updateIa(std::shared_ptr<IndieStudio::Character> &characVec, std::vector<std::shared_ptr<IndieStudio::Bomb>> bombVec,
std::vector<std::shared_ptr<IndieStudio::Pos>> freePos, bool Up_c, bool Down_c, bool Right_c, bool Left_c)
{
    this->_characVec = characVec;
    this->_bombVec = bombVec;
    this->_freePos = freePos;
    this->_freeUp = Up_c;
    this->_freeDown = Down_c;
    this->_freeRight = Right_c;
    this->_freeLeft = Left_c;
}

// void IndieStudio::IaMouvement::Ia(IndieStudio::Character & character, std::vector<std::shared_ptr<IndieStudio::Bomb>> bomb, std::vector<IndieStudio::Pos> freePos)
// {
//     //character.setMovingUp(isCenter(character.getPosition()));
// //    setfreePos(character.getPosition(), freePos);
//     if (isMoving(character) == false) {
//         // std::cout << "FALSE\n";
//         resetMoving(character);
//         setCenter(character);
//         checkFreeMove(character.getPosition(), freePos);
//         // std::cout << "UP " << this->_freeUp << "\n";
//         // std::cout << "UP POS " << this->_destinationUp._x << " " << _destinationUp._y << " " << _destinationUp._z << "\n";
//         // std::cout << "DOWN " << this->_freeDown << "\n";
//         // std::cout << "DOWN POS " << this->_destinationDown._x << " " << _destinationDown._y << " " << _destinationDown._z << "\n";
//         // std::cout << "RIGHT " << this->_freeRight << "\n";
//         // std::cout << "RIGHT POS " << this->_destinationRight._x << " " << _destinationRight._y << " " << _destinationRight._z << "\n";
//         // std::cout << "LEFT " << this->_freeLeft << "\n";
//         // std::cout << "LEFT POS " << this->_destinationLeft._x << " " << _destinationLeft._y << " " << _destinationLeft._z << "\n";
//         // std::cout << "POS " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
//         chooseDirection(character);
//     }
//     character.setMovingUp(_freeUp);
//     character.setMovingDown(_freeDown);
//     character.setMovingRight(_freeRight);
//     character.setMovingLeft(_freeLeft);
// //    std::cout << "DEST POS " << this->_destination._x << " " << _destination._y << " " << _destination._z << "\n";
// //    std::cout << "TRUE\n";
//     std::cout << "SIZE FREE POS " << freePos.size() << "\n";
// }
void IndieStudio::IaMouvement::Ia()
{
    //character.setMovingUp(isCenter(character.getPosition()));
//    setfreePos(character.getPosition(), freePos);
//   while(1) {
//        std::cout << "POS = " << this->_characVec->getPosition()._x << " " << this->_characVec->getPosition()._y << " " << this->_characVec->getPosition()._z << "\n";
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        if (isMoving() == false) {
            // std::cout << "FALSE\n";
            resetMoving();
            setCenter();
            checkFreeMove();
            // std::cout << "UP " << this->_freeUp << "\n";
            // std::cout << "UP POS " << this->_destinationUp._x << " " << _destinationUp._y << " " << _destinationUp._z << "\n";
            // std::cout << "DOWN " << this->_freeDown << "\n";
            // std::cout << "DOWN POS " << this->_destinationDown._x << " " << _destinationDown._y << " " << _destinationDown._z << "\n";
            // std::cout << "RIGHT " << this->_freeRight << "\n";
            // std::cout << "RIGHT POS " << this->_destinationRight._x << " " << _destinationRight._y << " " << _destinationRight._z << "\n";
            // std::cout << "LEFT " << this->_freeLeft << "\n";
            // std::cout << "LEFT POS " << this->_destinationLeft._x << " " << _destinationLeft._y << " " << _destinationLeft._z << "\n";
            // std::cout << "POS " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
            chooseDirection();
        }
//       _mutex.lock();
            this->_characVec->setMovingUp(_freeUp);
            this->_characVec->setMovingDown(_freeDown);
            this->_characVec->setMovingRight(_freeRight);
            this->_characVec->setMovingLeft(_freeLeft);
//        _mutex.unlock();
    //    this->_characVec[id]::cout << "DEST POS " << this->_destination._x << " " << _destination._y << " " << _destination._z << "\n";
    //    std::cout << "TRUE\n";
//        std::cout << "SIZE FREE POS " << _freePos.size() << "\n";
   //}
//    _th.join();
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
//    _destination = IndieStudio::Pos{0,0,0};
    // _destinationUp = IndieStudio::Pos{0,0,0};
    // _destinationDown = IndieStudio::Pos{0,0,0};
    // _destinationRight = IndieStudio::Pos{0,0,0};
    // _destinationLeft = IndieStudio::Pos{0,0,0};

}

void IndieStudio::IaMouvement::chooseDirection()
{
    if (this->_choiceDestination.size() > 0) {
//        std::cout << "SIZEEEEEE " << this->_choiceDestination.size() << "\n";
        int choose = rand()%((this->_choiceDestination.size() - 1) -0 + 1) + 0;
        // std::cout << "CHOOSE1 " << choose << "\n";
        resetMoving();
        choose = this->_choiceDestination[choose];
        // std::cout << "CHOOSE2 " << choose << "\n";
        if (choose == Up) {
            // std::cout << "UP\n";
            this->_characVec->setMovingUp(true);
            _destination = _destinationUp;
            _freeUp = true;
        } 
        else if (choose == Down) {
            // std::cout << "DOWN\n";
            this->_characVec->setMovingDown(true);
            _destination = _destinationDown;
            _freeDown = true;
        }
        else if (choose == Right) {
            // std::cout << "RIGHT\n";
            this->_characVec->setMovingRight(true);
            _destination = _destinationRight;
            _freeRight = true;
        }
        else if (choose == Left) {
            // std::cout << "LEFT\n";
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
        // std::cout << "ICIIIIIIIII\n";
        return (false);
    }
    // std::cout << "PLAYER " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
    // std::cout << "DESTIN " << _destination._x << " " << _destination._y << " " << _destination._z << "\n";
    if (this->_characVec->getPosition()._x >= _destination._x - ECART && this->_characVec->getPosition()._x <= _destination._x + ECART
    && this->_characVec->getPosition()._z >= _destination._z - ECART && this->_characVec->getPosition()._z <= _destination._z + ECART) {
        // std::cout << "Arrivedaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
        setCenter();
        resetMoving();
        // std::cout << "POS " << character.getPosition()._x << " " << character.getPosition()._y << " " << character.getPosition()._z << "\n";
        return (false);
    }
    return (true);
}

///////// SET ////////////
void IndieStudio::IaMouvement::checkFreeMove()
{
//   std::cout << "POSITION " << character_pos._x << " " << character_pos._y << " " << character_pos._z << "\n";
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
            // std::cout << "UP nb = " << nb << "\n";
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
            //  std::cout << "DOWN nb = " << nb << "\n";
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
            // std::cout << "LEFT nb = " << nb << "\n";
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
            //  std::cout << "RIGHT nb = " << nb << "\n";
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

void IndieStudio::IaMouvement::thJoin()
{
        _th.join();
}

IndieStudio::IaMouvement::~IaMouvement()
{
    // for (unsigned int i = 0; i != _th.size(); i++) {
    //     _th[i].join();
    // }
}
