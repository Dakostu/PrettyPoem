/** 
 * PrettyPoem
 * MAIN.CPP
 * @author Daniel Kostuj
 * 
 * This file contains the PrettyPoem main executable source code.
 * 
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "Poemifier.h"
#include <iostream>

int main(int argc, char** argv) {
    
    if (argc == 1) {
        std::cerr << "Usage: ./PrettyPoem [text file] [OPTIONAL:destination file name]" << std::endl;
        return 1;
    }
    
    try {
        Poemifier prettyPoem(argv[1]);
        
        if (argc > 2) {
            prettyPoem.setDestinationFileName(argv[2]);
        }
        
        std::cout << std::endl;
        std::cout << "[" << argv[1] << "] Parsing..." << std::endl;
        
        if (prettyPoem.poemifyUserText() != 0) {
            std::cerr << "[" << argv[1] << "] Could not be parsed. Quitting." << std::endl;
            return 1;
        } else {        
            std::cout << "[" << argv[1] << "] Successfully parsed to " << prettyPoem.getDestinationFileName() << "." << std::endl;
        }
    } catch (std::invalid_argument &e) {
        std::cerr << std::endl;
        std::cerr << "[" << argv[1] << "] " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
