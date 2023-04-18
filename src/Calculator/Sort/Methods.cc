/**
 * @file Methods.cc
 * @author AbianSL 
 * @brief That file is the definition file from thdefinitione Methods functions 
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright copyright (c) 2023
 * 
 */

#include "Methods.h"

template<class Key>
std::vector<Key> InsertionSort(const std::vector<Key>& vector, unsigned) {
  SortMethod<Key> *sort_method;
  sort_method = new Insertion<Key>(vector, vector.size());
  sort_method->Sort();
  return sort_method->GetSeq();
}

