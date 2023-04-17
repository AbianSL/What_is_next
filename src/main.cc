/**
 * @file main.cc
 * @author AbianSL
 * @brief is the main file of the project 
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "tools.h"
#include "Calculator/Calculator.h"

int main(int argc, char const *argv[]) {
  Usage(argc, argv); 
  std::cout << sizeof(Calculator);
  return 0;
}

