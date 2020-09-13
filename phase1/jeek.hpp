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
	int num_of_likes;
	int num_of_rejeeks;
	vector<string> likers;

public:
	Jeek(Content _content , User* _publisher , string _message_id );
	void show_message();
	void increase_rejeeks(){ num_of_rejeeks++; }
	void like( string liker_name );
	void dislike( string disliker_name );
	void add_like_notif(string liker_name);
	void add_dislike_notif( string disliker_name );
	int find_liker( string username );

};

#endif