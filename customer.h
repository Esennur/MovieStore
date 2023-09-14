#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Movie.h"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
// #define MAXLOG 1000

class Customer {

public:
  Customer(int pID, string fName, string lName);
  int getID() const;
  string getFirstName() const;
  string getLastName() const;
  void addToTransaction(Movie *mv, string action);
  void transactionHistory() const;
  bool isInBorrowedMovies(Movie *borrowedMovie);

private:
  int id;
  string firstName;
  string lastName;
  vector<Movie *> history;
  unordered_set<Movie *> borrowedMovies;
};

#endif