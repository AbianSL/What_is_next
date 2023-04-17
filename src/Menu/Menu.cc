/**
 * @file Menu.cc
 * @author AbianSL
 * @brief That file contains the definition of the
 *        class Menu, which show the user ineterface 
 *        and can interact with it
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cstdint>                        // uint8_t
#include <iostream>                       // std::cout, std::endl

#include "Menu.h"
#include "../Calculator/Calculator.h"     // Calculator

/**
 * @brief Construct a new Menu:: Menu object
 * 
 */
Menu::Menu() {
  PrintHeader();

  uint8_t option_ = 1;
  while (option_ != 0) {
    switch (option_) {
      case 1:
        PrintMainMenu();
        break;
      case 2:
        PrintOptionInsert();
        break;
      case 3:
        PrintOptionShow();
        break;
      default:
        break;
    }
  }
}

/**
 * @brief Print the header of the program
 * 
 */
void Menu::PrintHeader() {
  std::cout << "=================================================================" << std::endl;
  std::cout << "Welcome to the What is next, the program to journal your homework" << std::endl;
  std::cout << "=================================================================" << std::endl;
}

/**
 * @brief Print the main menu of the program
 * 
 */
void Menu::PrintMainMenu() {
  std::cout << "What do you want to do?" << std::endl;
  std::cout << "1. Insert a new homework" << std::endl;
  std::cout << "2. Show the homework" << std::endl;
  std::cout << "3. Options" << std::endl;
  std::cout << "0. Exit" << std::endl;
}

/**
 * @brief Print the option to insert a new homework
 * 
 */

