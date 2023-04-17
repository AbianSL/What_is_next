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

#include "Menu.h"

/**
 * @brief Construct a new Menu:: Menu object
 * 
 */
Menu::Menu() : calculator_(), options_() {
  PrintHeader();

  if (IsNotVoid()) {
    std::tie(calculator_, options_) = ReadConfig();
  } else {
    if (WriteConfig()) {
      throw std::runtime_error("Error writing the config file");
    }
  }
  uint8_t option_ = 1;
  while (option_ != 0) {
    switch (option_) {
      case 1:
        PrintMainMenu();
        break;
      case 2:
        OptionInsert();
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
void Menu::OptionInsert() {
  std::cout << "Insert a new homework" << std::endl;
  std::cout << "Subject name: "; 
  std::string subject_name;
  std::cin >> subject_name;
  std::cout << "date to do: ";
  std::string date_to_do;
  std::cin >> date_to_do;
  std::cout << "Difficulty [Easy, Medium, Hard, I dont know]: ";
  std::string difficulty;
  std::cin >> difficulty;

  calculator_.AddSubjectPractise(Subject(subject_name, date_to_do, difficulty));
}
