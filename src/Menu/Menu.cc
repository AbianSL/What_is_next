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
Menu::Menu() : calculator_() {
  PrintHeader();

  if (IsNotVoid()) {
    calculator_ = ReadMemory();
  } else {
    // if (WriteConfig()) {
    //   throw std::runtime_error("Error writing the config file");
    // }
  }
  int option_ = 1;
  while (option_ != 0) {
    PrintMainMenu();
    std::cin >> option_;
    switch (option_) { 
      case 1:
        OptionInsert();
        break;
      case 2:
        
        break;
      case 3:
        WriteMemory();
        break;
      // case 3:
      //   PrintOptionShow();
      //   break;
      default:
        break;
    }
    if (option_ == 0) {
      std::cout << "Are you sure you want to exit without saving? [Y/N]: ";
      std::string answer;
      std::cin >> answer;
      if (answer == "N" || answer == "n" || answer == "No" || answer == "no") { 
        option_ = 1;
      }
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
  std::cout << "3. Save" << std::endl;
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
  std::cout << "date to do [YY-MM-DD]: ";
  std::string date_to_do;
  std::cin >> date_to_do;
  std::cout << "Difficulty [Easy, Medium, Hard, I dont know]: ";
  std::string difficulty;
  std::cin >> difficulty; 

  auto time_point = CalculateDate(date_to_do);
  auto difficulty_selected = CalculateDifficulty(difficulty); 

  calculator_.AddSubjectPractise(Subject(subject_name, time_point, difficulty_selected));
}

/**
 * @brief Check if the config file is void
 * 
 * @return true 
 * @return false 
 */
bool Menu::IsNotVoid() {
  std::ifstream file("config.txt");
  return file.peek() != std::ifstream::traits_type::eof();
}


/**
 * @brief Read the config file
 * 
 * @return std::tuple<Calculator, std::vector<Options>> 
 */
Calculator Menu::ReadMemory() {
  std::ifstream file("../data/memory.txt");
  std::string line;
  std::vector<Subject> subjects;
  const char delimiter {','};
  while (std::getline(file, line)) {
    std::stringstream input(line); 
    std::string name, date, difficulty;
    std::getline(input, name, delimiter);
    std::getline(input, date, delimiter);
    std::getline(input, difficulty, delimiter);
    auto time_point = CalculateDate(date);
    auto difficulty_selected = CalculateDifficulty(difficulty);
    subjects.push_back(Subject(name, time_point, difficulty_selected));    
  }
  return Calculator(subjects);
}

/**
 * @brief Write the config file
 * 
 * @return true 
 * @return false 
 */
bool Menu::WriteMemory() {
  std::ofstream file("../data/memory.txt");
  if (!file.is_open()) {
    return false;
  }
  for (auto subject : calculator_.GetSubjectsPractise()) {
    file << subject->name_ << "," << subject->date_.time_since_epoch().count() << "," << subject->difficulty_ << std::endl;
  }
  return true;
}

/**
 * @brief Calculate the time point
 * 
 * @param date_to_do 
 * @return std::chrono::system_clock::time_point 
 */
std::chrono::time_point<std::chrono::system_clock> Menu::CalculateDate(std::string date) { 
  std::tm tm = {};
  std::stringstream input(date);
  int year, month, day;
  char delimiter {'-'};
  input >> year >> delimiter >> month >> delimiter >> day;
  tm.tm_year = year + 100;  // ajuste el año para que sea relativo a 1900
  tm.tm_mon = month - 1;    // ajuste el mes para que sea de 0 a 11
  tm.tm_mday = day;
  std::chrono::time_point<std::chrono::system_clock> time_point =
      std::chrono::system_clock::from_time_t(std::mktime(&tm));
  return time_point;
}

/**
 * @brief Calculate the difficulty
 * 
 * @param difficulty 
 * @return Difficulty 
 */
Difficulty Menu::CalculateDifficulty(std::string difficulty) {
  if (difficulty == "Easy") {
    return Difficulty::EASY;
  } else if (difficulty == "Medium") {
    return Difficulty::MEDIUM;
  } else if (difficulty == "Hard") {
    return Difficulty::HARD;
  } else if (difficulty == "I dont know") {
    return Difficulty::I_DONT_KNOW;
  } else {
    return Difficulty::I_DONT_KNOW;
  } 
}
