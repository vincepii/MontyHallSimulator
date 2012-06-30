/*
    Copyright (c) 2012, <Vincenzo Pii> <vinc.pii@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY <Vincenzo Pii> <vinc.pii@gmail.com> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <Vincenzo Pii> <vinc.pii@gmail.com> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "mhmodel.h"

#include <set>

#include "proxyrandom.h"
#include "mhdoor.h"

MHModel::MHModel( uint8_t numberOfDoors, bool verbose ) :
  _numberOfDoors(numberOfDoors),
  _verbose(verbose)
{
  if (numberOfDoors < 3) {
    // Cannot play with less than 3 doors
    throw std::invalid_argument("There must be at least 3 doors");
  }
  
  // Determine the index of the door containing the car
  int doorCar = ProxyRandom::get()->getUniformlyDistributedRandomBetween(0, _numberOfDoors - 1);
  
  // Store the index of the winning door
  _carDoorIndex = doorCar;
  
  // For each door to be created
  for (int i = 0; i < _numberOfDoors; i++) {
    MHDoor::ContentType ct;
    
    // Determine the content type
    if (i == doorCar) {
      ct = MHDoor::CAR;
    }
    else {
      ct = MHDoor::GOAT;
    }
    
    // Create the door
    MHDoor mhdoor(ct);
    
    _doors.push_back(mhdoor);
  }
}

MHResult MHModel::theGame()
{
  MHResult result;
  
  int playerChoice = _player.doFirstChoice(0, _numberOfDoors - 1);
  gameLog("The player", "Chose door", playerChoice);
  
  int hostChoice = openOneGoatDoor(playerChoice);
  gameLog("The host", "Chose door", hostChoice);
  
  MHPlayer::SecondChoice sc = _player.doSecondChoice();
  
  result.setPlayerChangedDecision(false);
  if (sc == MHPlayer::CHANGE_DOOR) {
    playerChoice = openAnotherDoor(playerChoice, hostChoice);
    gameLog("The Player", "Changed its door and picked door", playerChoice);
    result.setPlayerChangedDecision(true);
  }
  
  if (_doors[playerChoice].showContent() == MHDoor::CAR) {
    gameLog("The Player", "Won the game, car behind door", _carDoorIndex);
    result.setPlayerWonTheGame(true);
    return result;
  }
  else {
    gameLog("The Player", "Lost the game, car behind door", _carDoorIndex);
    result.setPlayerWonTheGame(false);
    return result;
  }
}

MHModel::~MHModel()
{
  delete ProxyRandom::get();
}

int MHModel::openOneGoatDoor(int playerChoice)
{
  return openAnotherDoor(playerChoice, _carDoorIndex);
}

int MHModel::openAnotherDoor (int playerChoice, int hostChoice)
{
  std::vector<int> avDoos = getAvailableDoors(playerChoice, hostChoice);
  
  int size = avDoos.size();
  
  int randIndex = ProxyRandom::get()->getUniformlyDistributedRandomBetween(0, size - 1);
  
  return avDoos[randIndex];
}

std::vector< int > MHModel::getAvailableDoors (int exclude1, int exclude2)
{
  std::vector<int> availableIndexes;
  
  for (int i = 0; i < _numberOfDoors; i++) {
    if (i == exclude1 || i == exclude2) {
      continue;
    }
    availableIndexes.push_back(i);
  }
  
  return availableIndexes;
}

void MHModel::gameLog(const std::string actor, const std::string action, int doorNumber) const
{
  if (_verbose == false) {
    return;
  }
  
  std::cout << actor << " " << action << " number " << doorNumber << std::endl;
}