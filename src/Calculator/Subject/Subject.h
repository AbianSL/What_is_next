/**
 * @file Subject.h
 * @author AbianSL
 * @brief That file contains the Subject struct
 *        and the enum Difficulty
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>     // std::string
#include <chrono>     // std::chrono::time_point

enum Difficulty {
  EASY,
  MEDIUM,
  HARD,
  I_DONT_KNOW
};

struct Subject {
  std::string name_;
  std::string description_;
  std::chrono::time_point<std::chrono::system_clock> date_;
  Difficulty difficulty_;ç
  long id_;
};

#endif      // SUBJECT_H
