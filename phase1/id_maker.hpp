#ifndef _ID_MAKER_H_
#define _ID_MAKER_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Id_Maker{
private:
	int num_of_jeek;
	int num_of_rep;
	int num_of_cm;

public:
	Id_Maker();
	string make_id(string message_type);

};

string int_to_str ( int number );

#endif