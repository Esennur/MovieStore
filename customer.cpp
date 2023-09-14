#include "customer.h"

Customer::Customer(int pID, string fName, string lName) {
  id = pID;
  firstName = fName;
  lastName = lName;
}

int Customer::getID() const { return id; }

string Customer::getFirstName() const { return firstName; }

string Customer::getLastName() const { return lastName; }

void Customer::addToTransaction(Movie *mv, string action) {
  if (action == "B") {
    history.push_back(mv);
    borrowedMovies.insert(mv);
  } else if (action == "R") {
    borrowedMovies.erase(mv);
  }
}

void Customer::transactionHistory() const {
  for (int i = history.size() - 1; i >= 0; i--) {
    string status =
        (borrowedMovies.count(history[i])) ? "Borrowed  " : "Returned  ";
    cout << "status: " << status << " " << history[i]->identification() << endl;
  }
  cout << endl;
}

bool Customer::isInBorrowedMovies(Movie *borrowedMovie) {
  return (borrowedMovies.count(borrowedMovie));
}