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
  */
Calculator::Calculator() {}

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
  * @brief Get the Value Of Subjects object
  * 
  * @return std::vector<long> 
  */
std::vector<long> Calculator::GetValueOfSubjects() const {
  return value_of_subjects_;
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

/**
  * @brief Remove a Subject Practise object
  * 
  * @param subject_practise 
  */
void Calculator::RemoveSubjectPractise(const Subject& subject_practise) {
  for (unsigned i = 0; i < subjects_practise_.size(); i++) {
    if (subjects_practise_[i]->name_ == subject_practise.name_) {
      RemoveSubjectPractise(i);
      break;
    }
  }
  CalculateValueOfSubjects();
}

/**
  * @brief Remove a Subject Practise object
  * 
  * @param index 
  */
void Calculator::RemoveSubjectPractise(const unsigned& index) {
  subjects_practise_.erase(subjects_practise_.begin() + index);
  value_of_subjects_.erase(value_of_subjects_.begin() + index);
}

/**
  * @brief Operator= of the class Calculator
  * 
  * @param other 
  * @return Calculator& 
  */
Calculator& Calculator::operator=(const Calculator& other) {
  subjects_practise_ = other.subjects_practise_;
  value_of_subjects_ = other.value_of_subjects_;
  return *this;
}

/**
  * @brief Calculate the value of all subjects
  * 
  */
void Calculator::CalculateValueOfSubjects() {
  for (unsigned i = 0; i < subjects_practise_.size(); i++) {
    CalculateValueOfSubjects(i);
  }
}


/**
  * @brief Calculate the value of a subject
  * 
  * @param index 
  */
void Calculator::CalculateValueOfSubjects(const unsigned& index) {
  auto actual_date = std::chrono::system_clock::now();
  if (value_of_subjects_.size() < index + 1) {
    value_of_subjects_.resize(index + 1);
  }
  if (actual_date > subjects_practise_[index]->date_) {
    subjects_practise_[index] = 0;
  }
  long long time_value = (subjects_practise_[index]->date_ - actual_date).count() 
                          / 10000000000000 * date_factor;
  time_value = 100 - time_value;
  if (time_value < 0) {
    time_value = std::abs(time_value);
  }
  value_of_subjects_[index] = subjects_practise_[index]->difficulty_ * difficulty_factor + 
                              time_value;
 
}
