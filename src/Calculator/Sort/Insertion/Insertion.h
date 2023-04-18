/**
 * @file insert.h
 * @author AbianSL 
 * @brief That file contains the declaration of the class Insert
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright copyright (c) 2023
 * 
 */

#ifndef INSERT_H
#define INSERT_H

#include "../Sort.h"

template<class Key>
class Insertion : public SortMethod<Key> {
 public:
  Insertion(const std::vector<Key>& seq, unsigned size);
  virtual void Sort() override;
  virtual std::vector<Key> GetSeq() const override;
};


#endif // INSERT_H
