#include <iostream>
#include <string>
#include <vector>
#include "interface.hpp"

using namespace std;

int main(){
	string instruction;
	Interface in;
	while( getline(cin , instruction) ){
		try{
			in.check_instruction( instruction);
		}
		catch(...){}
	}
	return 0;
}
