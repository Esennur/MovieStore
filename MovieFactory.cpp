#include "MovieFactory.h"

Movie *MovieFactory::createMovie(vector<string> &v) {
  string genre = v[0];

  switch (v[0][0]) {
  case 'F':
    return new Comedy(v);
  case 'D':
    return new Drama(v);
  case 'C':
    return new Classics(v);
  default:
    cerr << "Invalid type: " << v[0] << endl;
    return nullptr;
  }
}