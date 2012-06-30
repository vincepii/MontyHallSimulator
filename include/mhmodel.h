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


#ifndef MHMODEL_H
#define MHMODEL_H

#include "stdint.h"
#include <vector>

#include "mhdoor.h"
#include "mhplayer.h"
#include "mhresult.h"

/**
 * This class describes the Monty Hall problem
 */
class MHModel
{
  
  /**
   * Number of doors (redundant with the size of the _doors
   * vector
   */
  uint8_t _numberOfDoors;
  
  /**
   * Vector of doors to model the problem
   */
  std::vector<MHDoor> _doors;
  
  /**
   * The player
   */
  MHPlayer _player;
  
  /**
   * Index of the door hiding the car
   */
  int _carDoorIndex;
  
  /**
   * Verbose mode
   */
  bool _verbose;
  
public:
  
  /**
   * Default constructor
   */
  MHModel(uint8_t numberOfDoors = 3, bool verbose = false);
  
  MHResult theGame();
  
  /**
   * Destructor
   */
  ~MHModel();
  
private:
  
  /**
   * The model opens one doar hiding a goat
   */
  int openOneGoatDoor( int playerChoice );
  
  /**
   * The player decides to change its door, open another one
   */
  int openAnotherDoor(int playerChoice, int hostChoice);
  
  /**
   * Returns a vector containg the indexes of available doors, excluding
   * those passed as parameters
   */
  std::vector<int> getAvailableDoors(int exclude1, int exclude2);
  
  /**
   * Logs the game status
   */
  void gameLog( const std::string actor, const std::string action, int doorNumber ) const;
};

#endif // MHMODEL_H
