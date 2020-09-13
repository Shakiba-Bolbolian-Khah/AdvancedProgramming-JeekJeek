#include "management.hpp"

void Management::signup( string username , string displayName , string password ) {
	if ( !checkUsernameRepeat( username ) )
		throw(RepetitiousUsername() );

	User* newUser = new User(username , displayName , password);
	users.push_back( newUser );
	return;
}

bool Management::checkUsernameRepeat( string username ) {
	for (int i = 0 ; i < users.size() ; i++ )
		if ( users[i]->getUsername() == username )
			return	false;
	return true;
}

User* Management::findUser( string username ) {
	for (int i = 0 ; i < users.size() ; i++ )
		if ( users[i]->getUsername() == username )
			return users[i];
	return NULL;
}

string Management::login( string username , string password ) {
	User* foundUser = findUser( username );
	if ( foundUser == NULL )
		throw( UserNotFound() );
	if ( foundUser->getPassword() == password ) {
		LoggedInUser newUser;
		string sessionId = makeSessionId();
		newUser.sessionId = sessionId ;
		newUser.loggedUser = foundUser;
		loggedInUsers.push_back( newUser );
		return sessionId;
	}
	else
		throw ( WrongPassword() );
}

void Management::logout( string sessionId ) {
	int posOfUser = checkSessionRepeat( sessionId );
	if (posOfUser != -1 )
		loggedInUsers.erase(loggedInUsers.begin() + posOfUser);
}

void Management::addJeek( vector < vector < string > > data , string sessionId ) {
	User* foundUser = findUser( findUsername(sessionId));
	string jeekId  = idMaker.makeId("J");
	foundUser->addJeek(data , jeekId);
}

vector<Jeek*> Management::searchUser(string username ) {
	User* foundUser = findUser(username);
	if ( foundUser != NULL )
		return foundUser->getJeeks();
}

vector<Jeek*> Management::searchHashTags(string hashTag ) {
	vector<Jeek*> searchResult;
	for (int i = 0 ; i < users.size() ; i++ )
		users[i]-> findHashTags(searchResult , hashTag);
	return searchResult;
}

Jeek* Management::findJeek(string jeekId ) {
	for (int i = 0 ; i < users.size() ; i++ )
		if (users[i]->findJeek(jeekId) != NULL )
			return users[i]->findJeek(jeekId);
}

string Management::makeSessionId() {
	srand(time(0));
	int newSessionId = rand() + 1 ;
	string sessionId = to_string( newSessionId );
	while ( checkSessionRepeat( sessionId ) != -1 ) {
		newSessionId = rand() + 1;
		sessionId = to_string( newSessionId );
	}

	return sessionId;
}

int Management::checkSessionRepeat(string newSessionId) {
	for ( int i = 0 ; i < loggedInUsers.size() ; i++ )
		if ( loggedInUsers[i].sessionId == newSessionId )
			return i;
	return -1;
}

int Management::returnNumOfJeeks( string username ) {
	User* foundUser = findUser(username);
	return foundUser->getJeeksSize();
}

void Management::addUserInfo( string username , string &htmlFile ) {
	User* foundUser = findUser(username);
	foundUser->addUserInfo(htmlFile);
}

void Management::addData( vector<Jeek*> searchResult , string &htmlFile ) {
	for (int i = 0 ; i < searchResult.size() ; i++ ) {
		int posOfUsername = htmlFile.find("*");
		htmlFile.replace(posOfUsername , 1 , searchResult[i]->getPublisherUsername() );
		int posOfJeekId = htmlFile.find("^");
		htmlFile.replace(posOfJeekId , 1 , searchResult[i]->getId() );
		string jeekText = searchResult[i]->getText() + searchResult[i]->getTags();
		int posOfJeekText = htmlFile.find("$");
		htmlFile.replace(posOfJeekText , 1 , jeekText);
	}
}

void Management::addSearchResult(string searchExp , string &htmlFile , string sessionId ) {
	vector< Jeek* > searchResult;
	if (searchExp[0] == '#') {
		searchExp.erase( searchExp.begin() );
		searchResult = searchHashTags( searchExp );
	}
	else if ( searchExp[0] == '@') {
		searchExp.erase( searchExp.begin() );
		searchResult = searchUser(searchExp);
	}
	int posOfDisplayName = htmlFile.find("$");
	string displayname = loggedInUsers[checkSessionRepeat(sessionId)].loggedUser->getDisplayname() ;
	htmlFile.replace(posOfDisplayName , 1 , displayname );
	addData( searchResult , htmlFile );
}

int Management::returnNumOfSearchResult( string searchExp ) {
	vector <Jeek*> results;
	results = searchHashTags ( searchExp );
	return results.size();
}

string Management::findUsername( string sessionId ) {
	for ( int i = 0 ; i < loggedInUsers.size() ; i++ )
		if ( sessionId == loggedInUsers[i].sessionId )
			return loggedInUsers[i].loggedUser->getUsername();
}

void Management::handleLike( string sessionId , string jeekId) {
	string likerUsername = findUsername(sessionId );
	findJeek( jeekId )->handleLike( likerUsername );
}

void Management::handleRejeek( string sessionId , string jeekId) {
	Jeek* foundJeek = findJeek( jeekId );
	User* rejeeker = findUser( findUsername(sessionId));
	string rejeekId = idMaker.makeId("J");
	if (rejeeker->addRejeek( foundJeek->getText() , rejeekId)) 
		foundJeek->increaseRejeeks();
	else
		throw(BadJeekTextSize());
}
