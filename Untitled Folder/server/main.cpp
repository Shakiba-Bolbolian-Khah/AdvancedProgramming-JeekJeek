#include "../utils/utilities.hpp"
#include "server.hpp"
#include "interface.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
   try{
      InterFace interface(argc > 1 ? atoi(argv[1]) : 5000);
      interface.run();
   }
   catch (Server::Exception e) {
      cout << e.getMessage() << endl;
   }
}
