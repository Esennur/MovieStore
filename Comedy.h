/*Drama class is a subclass of movies, movies type of drama are stored as this
 * type */

#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"
#include "customer.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Comedy : public Movie {
public:
  // constructor from a string with movie info
  explicit Comedy(vector<string> &movieInfo);

  // destructor
  ~Comedy();

  // constructor with movie info inputs
  Comedy(int stock, string directorName, string title, int releaseYear,
         char type, char genre);

  string identification() const override;

  // method for displaying
  virtual string display() const override;
};

#endif