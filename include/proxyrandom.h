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


#ifndef PROXYRANDOM_H
#define PROXYRANDOM_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

class ProxyRandom
{
  /**
   * Pseudo-random number generator
   */
  boost::mt19937 _prng;
  
  /**
   * Singleton pointer
   */
  static ProxyRandom *_singleInstance;
  
private:
  
  /**
   * Default constructor, uses a time-dependent seed
   */
  ProxyRandom();
  
  /**
   * Constructor with explicit seed
   * @param seed the seed to initialize the prng
   */
  ProxyRandom(unsigned int seed);
  
public:
  
  /**
   * Singleton get
   */
  static ProxyRandom *get();
  
  /**
   * Returns a uniformly distributed number in the interval
   * [min, max] (closed interval).
   * @param min Min of the closed interval
   * @param max Max of the closed interval
   */
  int getUniformlyDistributedRandomBetween(unsigned int min, unsigned int max);
  
};

#endif // PROXYRANDOM_H
