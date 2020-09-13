#include "user.hpp"

User::User(string _username , string _displayName , string _password ){
	username = _username;
	displayName = _displayName;
	password = _password;
}

void User::addJeek( vector < vector < string > > data , string jeekId ){
	if( data[0][0].size() > 140 ){
		throw( BadJeekTextSize() );
	}

	Content newContent( data[0][0] , data[1] , data[2] );
	Jeek* newJeek = new Jeek( newContent , this , jeekId );
	jeeks.push_back(newJeek);
}

void User::findHashTags(vector<Jeek*> &searchResult , string hashTag ){
	for (int i = 0 ; i < jeeks.size() ; i++ )
		if( jeeks[i]->findHashTags(hashTag) )
			searchResult.push_back(jeeks[i]);
}

Jeek* User::findJeek( string jeekId ){
	for( int i =0 ; i < jeeks.size() ; i++ ){
		if( jeeks[i]->getId() == jeekId )
			return jeeks[i];
	}
	return NULL;
}

bool User::addRejeek( string text , string jeekId ){
	string rejeekText = "Rejeeked: " + text ;
	if ( rejeekText.size() > 140 )
		return false;

	Content rejeekContent(rejeekText);
	Jeek* newRejeek = new Jeek(rejeekContent , this , jeekId );
	jeeks.push_back(newRejeek);
	return true;
}

void User::addUserInfo(string &htmlFile ){
	int posOfDisplayName = htmlFile.find("$");
	htmlFile.replace(posOfDisplayName , 1 , displayName );
	for (int i = jeeks.size()-1 ; i >= 0 ; i-- ){
		int posOfUsername = htmlFile.find("*");
		htmlFile.replace(posOfUsername , 1 , username );
		int posOfJeekId = htmlFile.find("^");
		htmlFile.replace(posOfJeekId , 1 , jeeks[i]->getId() );
		string jeekText = jeeks[i]->getText() + jeeks[i]->getTags();
		int posOfJeekText = htmlFile.find("$");
		htmlFile.replace(posOfJeekText , 1 , jeekText);
	}	
}