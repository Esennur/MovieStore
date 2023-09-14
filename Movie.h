/** Movie Class:
 * parent class of comendy, drama, classics
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {

  friend ostream &operator<<(ostream &out, const Movie &movie);

public:
  // virtual destructor
  virtual ~Movie() = 0;
  // virtual methods for child classes
  virtual string display() const = 0;
  virtual string identification() const = 0;

  bool borrowMovie();
  void returnMovie();

  // getters
  string getDirectorName() const;
  string getTitle() const;
  int getReleaseYear() const;
  int getStock() const;
  char getTypeofMedia() const;
  char getGenre() const;

  string sortKey;

protected:
  string directorName;
  string actorNameAndReleaseYear;
  string title;
  int releaseYear;
  int stock;
  char typeofMedia;
  char genre;
  int borrowedOnes;
};
#endif