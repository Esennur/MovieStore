/** Classics Class:
 * Subclass of Movie class
 * Classics: C, Stock, Director, Title, Major actor Release date
 * sorted by Release date, then Major actor
 *
 */
#ifndef CLASSICS_H
#define CLASSICS_H

#include "Movie.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Classics : public Movie {
public:
  // constructors
  explicit Classics(vector<string> &movieInfo);

  // destructor
  ~Classics();

  // method for displaying
  string display() const override;

  string identification() const override;

private:
  string actorFirstName;
  string actorLastName;
  int releaseMonth;
};

#endif