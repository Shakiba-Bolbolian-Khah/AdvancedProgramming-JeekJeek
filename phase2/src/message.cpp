#include "message.hpp"
#include "user.hpp"

Message:: Message(Content _content , User* _publisher , string _messageId ) : content(_content){
	publisher = _publisher;
	messageId = _messageId;
}

bool Message::findHashTags(string hashTag ){
	if (content.findHashTags(hashTag))
		return true;
	else 
		return false;
}

string Message::getPublisherUsername(){ return publisher->getUsername() ;}