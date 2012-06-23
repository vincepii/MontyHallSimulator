#include <iostream>
#include <boost/program_options.hpp>

#include "mhmodel.h"
#include "mhresult.h"
#include "mhstats.h"

namespace po = boost::program_options;

int main(int argc, char **argv) {

    /** <HANDLE_OPTIONS> **/
    int doors;
    int cycles;
    bool verbose = false;
    
    po::options_description desc("Program options");
    desc.add_options()
      ("help", "Help message")
      ("doors", po::value<int>(&doors)->default_value(3), "Number of doors (default: 3)")
      ("cycles", po::value<int>(&cycles)->default_value(1), "Number of runs of the game (default: 1)")
      ("verbose", "Verbose mode, prints player and host actions (default: false)");
      
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    if (vm.count("help")) {
      std::cout << desc << std::endl;
      return 0;
    }
    
    if (vm.count("verbose")) {
      verbose = true;
    }
    /** </HANDLE_OPTIONS> **/
    
    
    /** <MAIN> **/
    MHStats stats;
    MHModel montyHallGame(doors, verbose);
    MHResult res;
    for (int i = 0; i < cycles; i++) {
      res = montyHallGame.theGame();
      stats.addStatistic(res);
    }
    stats.printStats();
    return 0;
}
