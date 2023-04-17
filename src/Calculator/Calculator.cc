/**
 * @file Calculator.h
 * @author AbianSL
 * @brief That file contains the definition of the
 *        class Calculator, which calculate have all
 *        tha computation part from the program.
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Calculator.h"

/**
  * @brief Construct a new Calculator:: Calculator object
  * 
  * @param subjects_practise 
  */
Calculator::Calculator(const std::vector<Subject>& subjects_practise) {
  for (const Subject& subject : subjects_practise) {
    subjects_practise_.push_back(new Subject(subject));
  }
  CalculateValueOfSubjects();
}

/**
  * @brief Construct a new Calculator:: Calculator object
  * 
  * @param other 
  */
Calculator::Calculator(const Calculator& other) {
  subjects_practise_ = other.subjects_practise_;
  value_of_subjects_ = other.value_of_subjects_;
}

/**
  * @brief Get the Subjects Practise object
  *
  * @return std::vector<Subject*> 
  */
std::vector<Subject*> Calculator::GetSubjectsPractise() const {
  return subjects_practise_;
}

/**
  * @brief Set the Subjects Practise object
  * 
  * @param subjects_practise 
  */
void Calculator::SetSubjectsPractise(const std::vector<Subject*>& subjects_practise) {
  subjects_practise_ = subjects_practise;
  CalculateValueOfSubjects();
}

/**
  * @brief Add a Subject Practise object
  * 
  * @param subject_practise 
  */
void Calculator::AddSubjectPractise(const Subject& subject_practise) {
  subjects_practise_.push_back(new Subject(subject_practise));
  CalculateValueOfSubjects(subjects_practise_.size() - 1);
}

