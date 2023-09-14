/*Drama class is a subclass of movies, movies type of drama are stored as this
 * type */

#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Drama : public Movie {
public:
  // constructor from a string with movie info
  explicit Drama(vector<string> &movieInfo);

  // destructor
  ~Drama();

  string identification() const override;

  // method for displaying
  string display() const override;
};

#endif