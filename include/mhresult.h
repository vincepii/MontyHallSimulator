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


#ifndef MHRESULT_H
#define MHRESULT_H

/**
 * This class describes the result of one instance of the MH game
 */
class MHResult
{
private:
  
  /**
   * True if the player changed its decision, false otherwise
   */
  bool _playerChangedDecision;
  
  /**
   * True if the player won the game, false otherwise
   */
  bool _playerWonTheGame;
  
public:
  
  /**
   * Default constructor
   */
  MHResult();
  
  /**
   * Constructor
   */
  MHResult( bool playerChangedDecision, bool playerWonTheGame );
  
  /**
   * Setter for decision changement
   */
  void setPlayerChangedDecision(bool value);
  
  /**
   * Setter for game outcome
   */
  void setPlayerWonTheGame(bool value);
  
  /**
   * Getter for decision changement
   */
  bool playerChangedDecision() const;
  
  /**
   * Getter for game outcome
   */
  bool playerWonTheGame() const;
};

#endif // MHRESULT_H
