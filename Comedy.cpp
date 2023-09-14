#include "Comedy.h"

// constructor from a string with movie info
Comedy::Comedy(vector<string> &movieInfo) {
  genre = movieInfo[0][0];
  stock = stoi(movieInfo[1]);
  directorName = movieInfo[2];
  title = movieInfo[3];
  releaseYear = stoi(movieInfo[4]);
  borrowedOnes = 0;
  sortKey = title + " " + to_string(releaseYear);
}

string Comedy::display() const {
  string displaying = "Comedy:  in stock: " + to_string(stock) + ", " +
                      "borrowed: " + to_string(borrowedOnes) + ", " +
                      directorName + ", " + title + " " +
                      to_string(releaseYear) + " ";
  return displaying;
}

string Comedy::identification() const {
  string identity = title + ", " + to_string(releaseYear);
  return identity;
}

Comedy::~Comedy() {}