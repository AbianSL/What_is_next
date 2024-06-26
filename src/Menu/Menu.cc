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

  if (IsNotVoid("../data/memory.txt")) {
    calculator_ = ReadMemory();
  } else {
    // if (WriteConfig()) {
    //   throw std::runtime_error("Error writing the config file");
    // }
  }
  int option_ = 1;
  
  while (option_ != 0) {
    PrintMainMenu();
    std::cout << "Option: ";
    std::cin >> option_;
    std::cout << std::endl;

    switch (option_) { 
      case 1:
        OptionInsert();
        break;
      
      case 2:
        OptionShow();
        break;
      
      case 3:
        WriteMemory();
        break;
      
      case 4:
        std::cout << "Comming soon" << std::endl;
        break;
      
      case 5:
        system("clear");
        break;
      
      case 6: {
        unsigned position;
        std::cout << "Select the position of the homework to remove [1 - " 
                  << calculator_.GetSubjectsPractise().size() << "]: ";
        std::cin >> position;
        OptionRemove(position - 1);
        break;
      }
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
void Menu::PrintHeader() const {
  std::string title = "Welcome to the What is next, the program to journal your homework";
  std::cout << PrintTimes(title.size(), '=') << std::endl;
  std::cout << title << std::endl;
  std::cout << PrintTimes(title.size(), '=') << std::endl;
}

/**
 * @brief Print the main menu of the program
 * 
 */
void Menu::PrintMainMenu() const {
  std::cout << "What do you want to do?" << std::endl;
  std::cout << "1. Insert a new homework" << std::endl;
  std::cout << "2. Show the homework" << std::endl;
  std::cout << "3. Save" << std::endl;
  std::cout << "4. Clean the memory" << std::endl;
  std::cout << "5. Clear the screen" << std::endl;
  std::cout << "6. Remove a homework" << std::endl;
  std::cout << "0. Exit" << std::endl;
}

/**
 * @brief Print the option to insert a new homework
 * 
 */
void Menu::OptionInsert() {
  std::string difficulty; 
  std::string subject_name;
  std::string date_to_do;

  std::cout << "Insert a new homework" << std::endl;
  std::cout << "Subject name: ";
  std::cin >> subject_name;
  
  std::cout << "date to do [YY-MM-DD]: ";
  std::cin >> date_to_do;
  
  std::cout << "Difficulty [Easy, Medium, Hard, I dont know]: ";
  std::cin >> difficulty; 

  auto time_point = CalculateDate(date_to_do);
  auto difficulty_selected = CalculateDifficulty(difficulty); 

  calculator_.AddSubjectPractise(Subject(subject_name, time_point, difficulty_selected));
}

void Menu::OptionShow() const {
  unsigned i = 0;
  std::cout << "The homework to do are: " << std::endl;
  std::cout << "it - name - value" << std::endl;

  for (auto subject : calculator_.GetSubjectsPractise()) {
    std::cout << i + 1 << " - " << subject->name_ << " - " << calculator_.GetValueOfSubjects()[i];
    std::cout << " - " ;
    
    switch (subject->difficulty_) {  
      case Difficulty::EASY:
        std::cout << "Easy";
        break;

      case Difficulty::MEDIUM:
        std::cout << "Medium";
        break;

      case Difficulty::HARD:
        std::cout << "Hard";
        break;

      case Difficulty::I_DONT_KNOW:
        std::cout << "I dont know";
        break;

      default:
        break;
    }
    std::cout << std::endl;
    i++;
  }
  std::cout << std::endl;
}

/**
 * @brief Check if the config file is void
 * @return true 
 * 
 * @return false 
 */
bool Menu::IsNotVoid(const std::string& kFileName) const {
  std::ifstream file(kFileName);
  return file.peek() != std::ifstream::traits_type::eof();
}


/**
 * @brief Read the config file
 * 
 * @return std::tuple<Calculator, std::vector<Options>> 
 */
Calculator Menu::ReadMemory() const {
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
    
    std::chrono::system_clock::duration duration (std::stoll(date));
    auto time_point = std::chrono::system_clock::time_point(std::chrono::seconds(0)) + duration;
    
    auto difficulty_selected = Difficulty(std::stoi(difficulty));
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
std::chrono::time_point<std::chrono::system_clock> Menu::CalculateDate(std::string date) const { 
  std::tm tm = {};
  std::stringstream input(date);
  int year, month, day;
  char delimiter {'-'};

  input >> year >> delimiter >> month >> delimiter >> day;
  tm.tm_year = year + 100;  // ajuste el año para que sea relativo a 1900
  tm.tm_mon = month - 1;    // ajuste el mes para que sea de 0 a 11
  tm.tm_mday = day;
  tm.tm_hour = 24;
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
Difficulty Menu::CalculateDifficulty(std::string difficulty) const {
  switch(difficulty[0]) {
    case 'e':
      return Difficulty::EASY;

    case 'm':
      return Difficulty::MEDIUM;

    case 'h':
      return Difficulty::HARD;

    case 'i':
      return Difficulty::I_DONT_KNOW;

    default:
      return Difficulty::I_DONT_KNOW;
  }
}

/**
  * @brief remove a task from the list
  *
  * @param index
  */
void Menu::OptionRemove(const unsigned index) {
  calculator_.RemoveSubjectPractise(index);
}
