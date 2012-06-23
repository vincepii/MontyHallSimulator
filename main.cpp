#include <iostream>

#include "mhmodel.h"
#include "mhresult.h"
#include "mhstats.h"

int main(int argc, char **argv) {
    MHStats stats;
    MHModel montyHallGame(3);
    MHResult res;
    for (int i = 0; i < 10000000; i++) {
      res = montyHallGame.theGame();
      stats.addStatistic(res);
    }
    stats.printStats();
    return 0;
}
