#ifndef _ID_MAKER_H_
#define _ID_MAKER_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class IdMaker{
private:
	int numOfJeek;
	int numOfRep;
	int numOfCm;

public:
	IdMaker();
	string makeId(string messageType);

};

string intToStr ( int number );

#endif