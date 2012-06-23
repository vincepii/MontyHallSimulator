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


#ifndef MHSTATS_H
#define MHSTATS_H

#include <stdint.h>

#include "mhresult.h"

/**
 * Class to collect statistics of more runs of the Monty Hall game.
 */
class MHStats
{
  /**
   * Total number of games
   */
  uint32_t _numberOfGames;
  
  /**
   * Number of games in which the player decided to change the door
   */
  uint32_t _doorChanges;
  
  /**
   * Number of won games
   */
  uint32_t _won;
  
  /**
   * Number of lost games
   */
  uint32_t _lost;
  
  /**
   * Number of games won when the player changed the door
   */
  uint32_t _wonWhenChanged;
  
  /**
   * Number of times won when the player didn't change the door
   */
  uint32_t _wonWhenNotChanged;
  
public:
  
  /**
   * Default constructor
   */
  MHStats();
  
  /**
   * Adds a statistic from one game
   */
  void addStatistic(const MHResult& result);
  
  /**
   * Prints statistics
   */
  void printStats() const;
};

#endif // MHSTATS_H
