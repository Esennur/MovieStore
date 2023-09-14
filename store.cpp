/*Store class that holds information about the movie store
  and lets us do operations like adding a book or customer,
  as well as borrowing or returning books and getting inventory*/

#include "store.h"
#include "MovieFactory.h"
#include <algorithm>
#include <sstream>

Store::Store(int numOfCustomers) {
  customerList = new HashTable(numOfCustomers);
}

// reading the movies from ifstream and adding them to store
void Store::makeMovieList(ifstream &movies) {
  string line;
  vector<string> movieInfo;
  while (getline(movies, line)) {
    std::istringstream iss(line);
    std::string token;
    while (std::getline(iss, token, ',')) {
      token = token.substr(token.find_first_not_of(" "));
      movieInfo.push_back(token);
    }

    Movie *newMovie = MovieFactory::createMovie(movieInfo);
    if (newMovie != nullptr) {
      moviesList[movieInfo[0][0]].push_back(newMovie);
    }

    movieInfo.clear();
  }
}

// reading customers from ifstream and adding them as customers
void Store::makeCustomerList(ifstream &customers) {
  int id;
  string fname;
  string lname;
  while (customers) {
    customers >> id >> lname >> fname;
    // making a customer object and adding it to hashtable
    Customer *newCustomer = new Customer(id, fname, lname);
    if (!customerList->addCustomer(newCustomer)) {
      delete newCustomer;
    };
  }
  cerr << "Done reading customers" << endl;
}

// printing all the customers
void Store::printAllCustomers() const { customerList->printAll(); }

// reading commands from ifstream and executing them by calling borrow or return
void Store::executeCommand(ifstream &line) {
  string command;
  string movieInfo;
  int customerID;
  char mediaType;
  char movieType;
  while (line >> command) {
    cerr << "command " << command << endl;
    switch (command[0]) {
    case 'H':
      line >> customerID;
      showHistory(customerID);
      break;
    case 'B':
      line >> customerID;
      line >> mediaType;
      if (mediaType != 'D') {
        cerr << "No " << mediaType << " media type" << endl;
        break;
      }
      line >> movieType;
      getline(line, movieInfo);
      movieInfo = movieInfo.substr(movieInfo.find_first_not_of(" "));
      borrow(customerID, movieInfo, movieType);
      break;
    case 'R':
      line >> customerID;
      line >> mediaType;
      if (mediaType != 'D') {
        cerr << "No " << mediaType << " media type" << endl;
        break;
      }
      line >> movieType;
      getline(line, movieInfo);
      movieInfo = movieInfo.substr(movieInfo.find_first_not_of(" "));
      returnMovie(customerID, movieInfo, movieType);
      break;
    case 'I':
      printAllMovies();
      break;
    default:
      cerr << "invalid command " << command << endl;
      getline(line, command);
      break;
    }
  }
}

// showing the history of the customer with the given id
void Store::showHistory(int id) {
  cout << endl << "Transaction history of " << id << " " << endl;
  if (customerList->customerWithTheID(id) != nullptr) {
    customerList->customerWithTheID(id)->transactionHistory();
  }
}

// helper functions borrow and returnMovie are called in execute commands to
// execure borrowing and returning commands
bool Store::borrow(int customerid, string movie, char movieType) {
  Customer *cstmr = customerList->customerWithTheID(customerid);
  Movie *borrowedMovie = findMovie(movie, movieType);

  if (cstmr == nullptr || borrowedMovie == nullptr) {
    cerr << "borrowing " << movie << " unsuccessful" << endl;
    return false;
  }

  if (borrowedMovie->getStock() <= 0) {
    cerr << "movie " << movie << " is not in stock" << endl;
    return false;
  }

  if (cstmr->isInBorrowedMovies(borrowedMovie)) {
    cerr << "customer " << cstmr->getID() << " already borrowed the movie "
         << movie << endl;
    return false;
  }

  borrowedMovie->borrowMovie();
  cstmr->addToTransaction(borrowedMovie, "B");
  return true;
}

bool Store::returnMovie(int customerid, string movie, char movieType) {
  Customer *cstmr = customerList->customerWithTheID(customerid);
  Movie *borrowedMovie = findMovie(movie, movieType);
  if (cstmr == nullptr || borrowedMovie == nullptr) {
    cerr << "borrowing " << movie << " unsuccessful" << endl;
    return false;
  }

  if (!cstmr->isInBorrowedMovies(borrowedMovie)) {
    cerr << "customer " << cstmr->getID() << " didn't borrow this movie before"
         << endl;
  }

  borrowedMovie->returnMovie();
  cstmr->addToTransaction(borrowedMovie, "R");
  return true;
}

void sortByIdentification(vector<Movie *> &movies) {
  sort(movies.begin(), movies.end(),
       [](Movie *m1, Movie *m2) { return m1->sortKey < m2->sortKey; });
}

void Store::printAllMovies() {
  // sorting the vectors before printing inventory
  for (auto &n : moviesList) {
    sortByIdentification(n.second);
  }

  cout << endl << "Printing inventory..." << endl;
  for (auto &n : moviesList) {
    for (int i = 0; i < n.second.size(); i++) {
      cout << *n.second[i] << endl;
    }
  }
}

Movie *Store::findMovie(string movieInfo, char type) {
  if (!moviesList.count(type)) {
    cerr << "There is no movie type of " << type << endl;
    return nullptr;
  }

  for (auto &n : moviesList.at(type)) {
    if (movieInfo == n->identification()) {
      return n;
    }
  }

  cerr << "Movie not found in the store" << endl;
  return nullptr;
}

Store::~Store() {
  for (auto &n : moviesList) {
    for (Movie *mv : n.second) {
      delete mv;
      mv = nullptr;
    }
  }

  delete customerList;
}