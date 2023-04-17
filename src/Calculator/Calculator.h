/**
 * @file Calculator.h
 * @author AbianSL
 * @brief That file contains the declaration of the
 *        class Calculator, which calculate the sum
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>

class Calculator {
 public:
  Calculator(std::vector<Subject> subjects_practise);

  std::vector<Subject> GetSubjectsPractise() const;
  void SetSubjectsPractise(std::vector<Subject> subjects_practise);
  void AddSubjectPractise(Subject subject_practise);
  void RemoveSubjectPractise(Subject subject_practise);
  
 private:
  std::vector<Subject> subjects_practise_;
};


#endif        // CALCULATOR_H
