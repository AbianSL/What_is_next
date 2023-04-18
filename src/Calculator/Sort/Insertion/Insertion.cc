/**
 * @file insert.cc
 * @author AbianSL
 * @brief That file contains the implementation of the Insert class
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright copyright (c) 2023
 * 
 */

#include "Insertion.h"

/**
  * @brief Construct a new Insertion<Key>:: Insertion object 
  * @param seq sequence of keys to sort 
  * @param size size of the sequence
  */
template <class Key>
Insertion<Key>::Insertion(const std::vector<Key>& seq, unsigned size) {
  this->seq_ = seq;
  this->size_ = size;
}

/**
  * @brief Sort the sequence of keys using the insertion sort method
  */
template <class Key>
void Insertion<Key>::Sort() {
  for (unsigned i {1}; i < GetSeq().size(); ++i) {
    Key key_to_move = this->seq_[i];
    int j = i - 1;
    while (j >= 0 && this->seq_[j] > key_to_move) {
      this->seq_[j + 1] = this->seq_[j];
      --j;
    }
    this->seq_[j + 1] = key_to_move;
  }
}

/**
  * @brief Get the Seq object
  * @return std::vector<Key> 
  */
template <class Key>
std::vector<Key> Insertion<Key>::GetSeq() const {
  return this->seq_;
}
