#include "hashtable.h"

HashTable::HashTable(int hashingNum) {
  this->hashingNum = hashingNum;
  for (int i = 0; i < hashingNum; i++) {
    customers.push_back({-1, nullptr});
  }
}

bool HashTable::addCustomer(Customer *pcustomer) {
  int index = hashing(pcustomer->getID());
  if (index != -1) {
    customers[index] = {pcustomer->getID(), pcustomer};
    return true;
  } else {
    // no place found
    return false;
  }
}

int HashTable::hashing(int id) const {
  int index = id % hashingNum;
  int i = 0;

  while (index < hashingNum) {
    if (customers[index].first == -1) {
      return index;
    }
    index += i * i;
    i++;
  }

  return -1;
}

void HashTable::printAll() const {
  for (auto &n : customers) {
    if (n.first != -1) {
      cout << n.second->getID() << " " << n.second->getFirstName() << " "
           << n.second->getLastName() << endl;
    }
  }
}

Customer *HashTable::customerWithTheID(int id) const {
  int index = id % hashingNum;

  int i = 0;

  while (index < hashingNum) {
    if (customers[index].first == id) {
      return customers[index].second;
    }
    index += i * i;
    i++;
  }

  cerr << "the customer with ID " << id << " is not registered" << endl;
  return nullptr;
}

HashTable::~HashTable() {
  for (auto &n : customers) {
    if (n.first != -1) {
      delete n.second;
      n.second = nullptr;
    }
  }
}