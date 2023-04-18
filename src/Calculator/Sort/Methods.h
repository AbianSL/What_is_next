/**
 * @file Methods.h
 * @author AbianSL 
 * @brief That file is the header file from the Methods functions 
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright copyright (c) 2023
 * 
 */

#ifndef METHODS_H_
#define METHODS_H_

#include <cstdint>                // uint8_t
#include <vector>                 // std::vector

#include "Sort.h"                 // SortMethod
#include "Insertion/Insertion.h"  // Insertion

template <class Key>
std::vector<Key> InsertionSort (const std::vector<Key>&, unsigned);

#endif  // METHODS_H_
