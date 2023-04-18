/**
 * @file Sort.h
 * @author AbianSL 
 * @brief That file contains the declaration of the class Sort
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright copyright (c) 2023
 * 
 */

#ifndef SORT_H
#define SORT_H

#include <vector> // std::vector

template<class Key>
class SortMethod {
 public:
  virtual void Sort() = 0;
  virtual std::vector<Key> GetSeq() const = 0;
 protected:
  unsigned size_;
  std::vector<Key> seq_;
};

#endif // SORT_H
