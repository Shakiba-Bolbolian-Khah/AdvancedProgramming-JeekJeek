#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "management.hpp"
#include "error.hpp"

using namespace std;

class Interface{
private:
	Management management;
	vector<string> instruction;
	stringstream ins;
public:
	string read_command( string instruct );
	void read_arguments();
	void check_instruction( string instruct );
	void check_instruction_for_other_instruction( string command );
	void check_instruction_for_search();
	void read_instruction_for_cm_reply();
	void read_instruction_for_jeek();
	void organize_info( string command , vector<vector< string> > &data );
	void edit_text(string &text);
	bool check_instruction_for_message( string command );
};


#endif