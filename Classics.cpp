#include "Classics.h"

// constructor from a string with movie info
Classics::Classics(vector<string> &movieInfo) {
  genre = movieInfo[0][0];
  stock = stoi(movieInfo[1]);
  directorName = movieInfo[2];
  title = movieInfo[3];

  string threeInfos = movieInfo[4];
  vector<string> infoVector;
  stringstream ss(threeInfos);
  string word;
  while (ss >> word) {
    infoVector.push_back(word);
  }
  actorFirstName = infoVector[0];
  actorLastName = infoVector[1];
  releaseMonth = stoi(infoVector[2]);
  releaseYear = stoi(infoVector[3]);

  borrowedOnes = 0;

  sortKey = to_string(releaseYear) + " " + to_string(releaseMonth) + " " +
            actorFirstName + " " + actorLastName;
}

string Classics::display() const {
  string displaying = "Classics:  in stock: " + to_string(stock) + ", " +
                      +"borrowed: " + to_string(borrowedOnes) + ", " +
                      directorName + ", " + title + ", " +
                      to_string(releaseMonth) + " " + to_string(releaseYear) +
                      ", " + actorFirstName + " " + actorLastName;
  return displaying;
}

string Classics::identification() const {
  string identity = to_string(releaseMonth) + " " + to_string(releaseYear) +
                    " " + actorFirstName + " " + actorLastName;
  return identity;
}

Classics::~Classics() {}