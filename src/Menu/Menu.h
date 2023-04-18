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
#include <string>                        // std::string
#include <vector>                        // std::vector
#include <tuple>                         // std::tuple
#include <sstream>                       // std::stringstream

#include "../Calculator/Calculator.h"    // Calculator
#include "../Calculator/Subject/Subject.h"          // Subject

// struct Options {
//   std::string language_;
// };

class Menu {
 public:
  Menu();  
 private:
  void PrintHeader();
  void PrintMainMenu();
  void OptionInsert();
  // Select option comming soon
  // void PrintOptionShow();
  // void ShowOptions();
  bool IsNotVoid(const std::string& kFileName) const;
  Calculator ReadMemory() const;
  bool WriteMemory();
  // int WriteConfig();

  std::chrono::time_point<std::chrono::system_clock> CalculateDate(std::string date);
  Difficulty CalculateDifficulty(std::string difficulty);
    
  Calculator calculator_;
  // std::vector<Options> options_;
};

#endif  // MENU_H_
