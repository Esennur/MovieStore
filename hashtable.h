#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;
// #define HASHTABLESIZE 10

class HashTable {

public:
  // constructor
  explicit HashTable(int hashingNum);
  // destructor
  ~HashTable();

  //
  bool addCustomer(Customer *customer);
  void printAll() const;
  Customer *customerWithTheID(int ID) const;

private:
  int hashingNum;
  int hashing(int ID) const;
  vector<pair<int, Customer *>> customers;
};

#endif