/**
 * @file Menu_tools.cc 
 * @author AbianSL
 * @brief That file contains the definition of the 
 *        general functions for the Menu class.
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

#include "Menu_tools.h"

/**
 * @brief This function prints a character a number of times
 * 
 * @param times is the number of times the character is printed
 * @param character is the character to be printed
 * @return std::string the string with the character printed
 */
std::string PrintTimes(int times, char character) {
  std::string result = "";
  for (int i = 0; i < times; i++) {
    result += character;
  }
  return result;
}
