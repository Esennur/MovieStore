/*Drama class is a subclass of movies, movies type of drama are stored as this
 * type */

#include "Drama.h"

// constructor from a string with movie info
Drama::Drama(vector<string> &movieInfo) {
  genre = movieInfo[0][0];
  stock = stoi(movieInfo[1]);
  directorName = movieInfo[2];
  title = movieInfo[3];
  releaseYear = stoi(movieInfo[4]);
  borrowedOnes = 0;
  sortKey = directorName + " " + title;
}

string Drama::display() const {
  string displaying = "Drama:  in stock: " + to_string(stock) +
                      ", "
                      "borrowed: " +
                      to_string(borrowedOnes) + ", " + directorName + ", " +
                      title + ", " + to_string(releaseYear);
  return displaying;
}

string Drama::identification() const {
  string identity = directorName + ", " + title + ",";
  return identity;
}

Drama::~Drama() {}