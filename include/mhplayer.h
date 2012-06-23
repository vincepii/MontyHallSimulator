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


#ifndef MHPLAYER_H
#define MHPLAYER_H

class MHPlayer
{
public:
  
  /**
   * Describes the second choice of the player, keep
   * the chosen door or choose the other one (if 3 doors)
   */
  enum SecondChoice {
    ERROR = -1,
    KEEP_DOOR = 0,
    CHANGE_DOOR,
  };
  
private:
  
  /**
   * Keeps track of the first choice
   */
  int _firstChoice;
  
  /**
   * Keeps track of the second choiche
   */
  SecondChoice _secondChoice;
  
public:
  
  /**
   * Default constructor
   */
  MHPlayer();
  
  /**
   * Player's first choice within the provided ranges
   * (door numbers)
   */
  int doFirstChoice(int min, int max);
  
  /**
   * Returs the first choice of the player
   */
  int getFirstChoice() const;
  
  /**
   * Player's second choice
   */
  SecondChoice doSecondChoice();
  
  /**
   * Returns the second choice made by the player
   */
  SecondChoice getSecondChoice() const;
  
private:
  
  /**
   * Utility function to convert from integer to
   * SecondChoice
   */
  SecondChoice intToSecondChoice(int value);
};

#endif // MHPLAYER_H
