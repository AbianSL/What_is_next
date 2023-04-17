/**
 * @file Calculator.h
 * @author AbianSL
 * @brief That file contains the declaration of the
 *        class Calculator, which calculate have all
 *        tha computation part from the program.
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>                 // std::vector

#include "Subject/Subject.h"      // Subject

class Calculator {
 public:
  Calculator();
  Calculator(const std::vector<Subject>& subjects_practise);
  Calculator(const Calculator& other);

  std::vector<Subject*> GetSubjectsPractise() const;
  void SetSubjectsPractise(const std::vector<Subject*>& subjects_practise);
  
  void AddSubjectPractise(const Subject& subject_practise);
  void RemoveSubjectPractise(const Subject& subject_practise);
  void RemoveSubjectPractise(const unsigned& index);

  Calculator& operator=(const Calculator& other);

 private:
  void CalculateValueOfSubjects();
  void CalculateValueOfSubjects(const unsigned& index);

  double difficulty_factor = 1;
  double date_factor = 1;
  std::vector<Subject*> subjects_practise_;
  std::vector<long> value_of_subjects_;
};


#endif        // CALCULATOR_H
