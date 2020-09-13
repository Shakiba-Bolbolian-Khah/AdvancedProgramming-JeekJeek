#ifndef __INTERFACE_H_
#define __INTERFACE_H_
#include "../utils/utilities.hpp"
#include "server.hpp"
#include "requestHandlers.hpp"
#include "../src/management.hpp"
#include <iostream>

using namespace std;

class InterFace{
private:
   Server server;
public:
	static Management* management; 
	InterFace(int port);
	void run(){
		server.run();
   }
};



#endif