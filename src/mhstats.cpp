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


#include "mhstats.h"

#include <iostream>

MHStats::MHStats() : 
  _numberOfGames(0),
  _doorChanges(0),
  _won(0),
  _lost(0),
  _wonWhenChanged(0),
  _wonWhenNotChanged(0)
{
  ;
}

void MHStats::addStatistic ( const MHResult& result )
{
  _numberOfGames++;
  
  if (result.playerChangedDecision() == true) {
    _doorChanges++;
  }
  
  if (result.playerWonTheGame() == true) {
    _won++;
  }
  else {
    _lost++;
  }
  
  if (result.playerChangedDecision() == true && result.playerWonTheGame() == true) {
    _wonWhenChanged++;
  }
  
  if (result.playerChangedDecision() == false && result.playerWonTheGame() == true) {
    _wonWhenNotChanged++;
  }
}

void MHStats::printStats() const
{
  double wonPct = 100 * (double) _won / (double) _numberOfGames;
  double wonWhenChangedPct = 100 * (double) _wonWhenChanged / (double) _doorChanges;
  uint32_t doorNotChanges = (_numberOfGames - _doorChanges);
  double wonWhenNotChangedPct = 100 * (double) _wonWhenNotChanged / (double) doorNotChanges;
  
  std::cout << "Number of games (total): " << _numberOfGames << std::endl;
  std::cout << "Number of times the player changed doors: " << _doorChanges << std::endl;
  std::cout << "Games result (WON/TOTAL): " << _won << "/" << _numberOfGames << " (" << wonPct << "\%)" << std::endl;
  std::cout << "Winning rate when changing door: " << _wonWhenChanged << "/" << _doorChanges << " (" << wonWhenChangedPct << "\%)" << std::endl;
  std::cout << "Winning rate when NOT changing door: " << _wonWhenNotChanged << "/" << doorNotChanges << " (" << wonWhenNotChangedPct << "\%)" << std::endl;
  std::cout << std::endl;
}
