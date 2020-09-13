#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "user.hpp"
#include "jeek.hpp"
#include "message.hpp"
#include "id_maker.hpp"

using namespace std;

struct LoggedInUser{
	string sessionId;
	User* loggedUser;
};

class Management {
private:
	vector<User*> users;
	vector<LoggedInUser> loggedInUsers;
	IdMaker idMaker;

public:
	Management(){}
	void signup( string username , string displayName , string password );
	void logout( string sessionId);
	void addJeek( vector < vector < string > > data , string sessionId );
	void handleRejeek( string sessionId , string jeekId );
	void addUserInfo(string username , string &htmlFile );
	void addData( vector <Jeek*> searchResult , string &htmlFile );
	void addSearchResult(string searchExp , string &htmlFile , string sessionId);
	void handleLike( string sessionId , string jeekId );
	bool checkUsernameRepeat( string username );
	int returnNumOfSearchResult( string searchExp );
	int checkSessionRepeat(string newSessionId);
	int returnNumOfJeeks( string username );
	string login( string username , string password );
	string makeSessionId();
	string makeHomeHtml(string username);
	string findUsername( string sessionId );
	vector<Jeek*> searchUser(string username );
	vector<Jeek*> searchHashTags(string hashTag );
	Jeek* findJeek(string jeekId );
	User* findUser( string username );

};

#endif