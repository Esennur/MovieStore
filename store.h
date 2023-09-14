/*Store class that holds information about the movie store
  and lets us do operations like adding a book or customer,
  as well as borrowing or returning books and getting inventory*/

#ifndef STORE_H
#define STORE_H

#include "Movie.h"
#include "customer.h"
#include "hashtable.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Store {
public:
  // constructor
  explicit Store(int numOfCustomers);

  // destructor
  ~Store();

  // reading the movies from ifstream and adding them to store
  void makeMovieList(ifstream &movies);

  // reading customers from ifstream and adding them as customers
  void makeCustomerList(ifstream &customers);

  // getting the number of customers
  int getCustomerSize();

  // printing all the customers
  void printAllCustomers() const;

  // printing all the movies
  void printAllMovies();

  // reading commands from ifstream and executing them by calling borrow or
  // return
  void executeCommand(ifstream &line);

  // showing the history of the customer with the given id
  void showHistory(int id);

  // helper functions borrow and returnMovie are called in execute commands to
  // execure borrowing and returning commands
  bool borrow(int customerid, string movie, char movietype);
  bool returnMovie(int customerid, string movie, char movieType);

  Movie *findMovie(string movieInfo, char type);

private:
  // hashtable object to use for hashing
  HashTable *customerList;

  // map that holds movies
  map<char, vector<Movie *>, greater<char>> moviesList;

  // helper method that is called in borrow function
  bool addToStock(int stockCount, Movie *movie);
};

#endif