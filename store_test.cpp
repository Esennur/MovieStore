/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */
#include "store.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;

  cout << " ------- Testing cases of borrowing a movie twice, borrowing an "
          "unexisting movie, and returning a movie that wasn't borrowed-----"
       << endl;
  cout << "Expecting 4 error messages" << endl;
  string cfile = "test2movies.txt";
  ifstream fs(cfile);
  Store newStore(19);

  cerr << "before making list" << endl;
  newStore.makeMovieList(fs);
  cerr << "after making list" << endl;

  string lfile = "test2customers.txt";
  ifstream cs(lfile);

  newStore.makeCustomerList(cs);

  string commandFile = "test2commands.txt";
  ifstream commands(commandFile);

  newStore.executeCommand(commands);
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  string cfile = "data4movies.txt";
  ifstream fs(cfile);
  Store newStore(19);

  newStore.makeMovieList(fs);

  string lfile = "data4customers.txt";
  ifstream cs(lfile);

  newStore.makeCustomerList(cs);

  cout<<endl<<"printing customers..."<<endl;
  newStore.printAllCustomers();

  string commandFile = "data4commands.txt";
  ifstream commands(commandFile);

  newStore.executeCommand(commands);
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
