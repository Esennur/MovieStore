/** Movie Class:
 * parent class of comendy, drama, classics
 */

#include "Movie.h"

using namespace std;

bool Movie::borrowMovie() {
  stock--;
  borrowedOnes++;
  return false;
}

void Movie::returnMovie() {
  stock++;
  borrowedOnes--;
}

// getters
int Movie::getStock() const { return stock; }

ostream &operator<<(ostream &out, const Movie &movie) {
  out << movie.display();
  return out;
}

Movie::~Movie() {}