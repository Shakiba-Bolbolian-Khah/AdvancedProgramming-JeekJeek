#ifndef _JEEK_H_
#define _JEEK_H_
#include <iostream>
#include <string>
#include <vector>
#include "content.hpp"
#include "message.hpp"
#include "error.hpp"

using namespace std;

class Jeek : public Message {
private:
	int numOfLikes;
	int numOfRejeeks;
	vector<string> likers;

public:
	Jeek(Content _content , User* _publisher , string _message_id );
	void increaseRejeeks() { numOfRejeeks++; }
	void like( string likerName );
	void dislike( string dislikerName );
	void addJeekInfo( string &jeekHtml , string likerUsername );
	void handleLike( string likerUsername );
	int findLiker( string username );

};

#endif