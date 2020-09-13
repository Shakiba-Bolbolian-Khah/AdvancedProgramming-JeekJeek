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
	string message_id;
	Content content;
	User* publisher;
	vector<Message*> sub_message;

public:
	Message(Content _content , User* _publisher , string _message_id );
	virtual void show_message();
	void print_search_result(){ cout<< content.get_text()<<endl; }
	void add_sub_message( Message* new_sub_message ){ sub_message.push_back(new_sub_message);}
	bool find_hash_tags(string hash_tag );
	string get_id(){ return message_id; }
	string get_text(){ return content.get_text(); }
	User* get_publisher(){ return publisher; }
	Message* find_rep_cm(string _message_id);
};

class Reply: public Message {

public:	
	Reply(Content _content , User* _publisher , string _message_id ):Message(_content,_publisher,_message_id){};

};

class Comment: public Message{

public:
	Comment(Content _content , User* _publisher , string _message_id ):Message(_content,_publisher,_message_id){};
};


#endif