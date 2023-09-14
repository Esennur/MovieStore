/*Movie factory allows the store to create different types of movies*/

#include "Classics.h"
#include "Comedy.h"
#include "Drama.h"
#include "Movie.h"

class MovieFactory {
public:
  static Movie *createMovie(vector<string> &v);
};