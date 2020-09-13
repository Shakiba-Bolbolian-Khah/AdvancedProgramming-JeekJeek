#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_
#include <iostream>
#include <string>
#include <vector>
#include "user.hpp"
#include "jeek.hpp"
#include "message.hpp"
#include "notification.hpp"
#include "id_maker.hpp"

using namespace std;

class Management {
private:
	vector<User*> users;
	User* cur_user;
	Id_Maker id_maker;

public:
	Management() { cur_user = NULL; }
	void signup( string username , string display_name , string password );
	void login( string username , string password );
	void logout();
	void add_jeek( vector < vector < string > > data );
	void add_comment( string jeek_id , string comment_text );
	void add_reply( string rep_cm_id , string reply_text );
	void add_reply_notif( string rep_cm_id );
	void add_comment_notif( string jeek_id );
	void add_rejeek_notif(string jeek_id);
	void add_mention_notif( vector<string> mentions , string jeek_id );
	void rejeek( string jeek_id );
	void search_user(string username );
	void search_hash_tags(string hash_tag );
	void show_jeek(string jeek_id);
	void show_comment_reply(string message_id );
	void like(string jeek_id);
	void dislike(string jeek_id);
	void follow(string username);
	void unfollow(string username);
	void notification(){ cur_user->notification(); }
	bool check_username_repeat( string username );
	Jeek* find_jeek(string jeek_id );
	Message* find_rep_cm(string message_id);
	User* find_user( string username );

};

#endif