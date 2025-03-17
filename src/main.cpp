#include <cstring>
#include <iostream>

#include "i18n.h"
#include "input.h"
#include "scene.h"
#include "system_env.hpp"
#include "utilty.inl"

static void printHelp() {
    std::cout << std::endl;
    std::cout << "sudoku - a little game in command line" << std::endl
              << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "\t sudoku [-l <progressFile>]" << std::endl << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "\t -l <path> \t specify path of progress file to load, optional." << std::endl
              << std::endl;
}

int main(int argc, char **argv)
{
    SetSystemENV();

    
    return 0;
}