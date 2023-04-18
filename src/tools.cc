/**
 * @file tools.cc 
 * @author AbianSL
 * @brief that file contains general functions for the program
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "tools.h"
#include "Menu/Menu.h"

/**
 * @brief This function prints the usage of the program
 * 
 * @param argc is the number of arguments 
 * @param argv is the array of arguments
 * @return int 0 if the program is executed correctly
 */
int Usage(int argc, char const *argv[]) {
  if (argc != 1) {
    std::cerr << "Usage: " << argv[0] << std::endl;
    return 1;
  }
  return 0;
}

/**
 * @brief This function prints the menu of the program
 * 
 */
void Menu() {
  Menu main_menu(); 
}
