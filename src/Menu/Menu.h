/**
 * @file Menu.cch
 * @author AbianSL
 * @brief That file contains the declaration of the
 *        class Menu, which show the user ineterface 
 *        and can interact with it
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>                      // std::cout, std::endl
#include <cstdint>                       // uint8_t
#include <fstream>                       // std::ifstream, std::ofstream

#include "../Calculator/Calculator.h"    // Calculator
#include "../Subject/Subject.h"          // Subject

struct Options {
  std::string language_;
};

class Menu {
 public:
  Menu();  
 private:
  void PrintHeader();
  void PrintMainMenu();
  void OptionInsert();
  void PrintOptionShow();
  void ShowOptions();
  int ReadConfig();
  int WriteConfig();

  Calculator calculator_;
  std::vector<Options> options_;
};

#endif  // MENU_H_
