#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include <iostream>
#include <string>
#include <vector>
#include "content.hpp"
using namespace std;

class User;

class Message{
protected:
	string messageId;
	Content content;
	User* publisher;

public:
	Message(Content _content , User* _publisher , string _messageId );
	bool findHashTags(string hashTag );
	string getId(){ return messageId; }
	string getText(){ return content.getText(); }
	string getTags(){ return content.getTags(); }
	string getPublisherUsername();
	User* getPublisher(){ return publisher; }
};


#endif