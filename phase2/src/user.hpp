#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include <string>
#include <vector>
#include "message.hpp"
#include "jeek.hpp"
#include "error.hpp"
using namespace std;

class User{
private:
	string username;
	string displayName;
	string password;
	vector<Jeek*> jeeks;

public:
	User(string _username , string _displayName , string password );
	void addJeek( vector < vector < string > > data , string jeekId );
	bool addRejeek( string text , string jeekId );
	void findHashTags(vector<Jeek*> &searchResult , string hashTag );
	int getJeeksSize(){ return jeeks.size();}
	Jeek* findJeek( string jeekId );
	vector <Jeek*> getJeeks(){ return jeeks; }
	string getUsername(){ return username; }
	string getPassword(){ return password; }
	string getDisplayname(){ return displayName; }
	void addUserInfo(string &htmlFile );
};

#endif