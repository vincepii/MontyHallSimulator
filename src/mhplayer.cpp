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


#include "mhplayer.h"

#include "proxyrandom.h"

MHPlayer::MHPlayer() : 
  _firstChoice(-1),
  _secondChoice(ERROR)
{
  ; // do nothing
}

int MHPlayer::doFirstChoice ( int min, int max )
{
  int choice = ProxyRandom::get()->getUniformlyDistributedRandomBetween(min, max);
  _firstChoice = choice;
  return _firstChoice;
}

int MHPlayer::getFirstChoice() const
{
  if (_firstChoice == -1) {
    throw std::range_error("FirstChoice value was not initialized");
  }
  
  return _firstChoice;
}

MHPlayer::SecondChoice MHPlayer::doSecondChoice()
{
  int choice = ProxyRandom::get()->getUniformlyDistributedRandomBetween(KEEP_DOOR, CHANGE_DOOR);
  _secondChoice = intToSecondChoice(choice);
  return _secondChoice;
}

MHPlayer::SecondChoice MHPlayer::getSecondChoice() const
{
  if (_secondChoice == ERROR) {
    throw std::out_of_range("SecondChoice value was not initialized");
  }
  
  return _secondChoice;
}

MHPlayer::SecondChoice MHPlayer::intToSecondChoice ( int value )
{
  switch(value) {
    case KEEP_DOOR:
      return KEEP_DOOR;
      break;
    case CHANGE_DOOR:
      return CHANGE_DOOR;
      break;
    default:
      throw std::out_of_range("Error while converting integer to SecondChoice type");
      break;
  }
}