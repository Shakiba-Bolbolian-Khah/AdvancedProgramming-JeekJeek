#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include <string>
#include <vector>
#include "notification.hpp"
#include "message.hpp"
#include "jeek.hpp"
#include "error.hpp"
using namespace std;

class User{
private:
	string username;
	string display_name;
	string password;
	vector<Jeek*> jeeks;
	vector<User*> followers;
	vector<User*> followings;
	vector<Notification*> user_notifs;

public:
	User(string _username , string _display_name , string password );
	void add_jeek( vector < vector < string > > data , string jeek_id );
	bool add_rejeek( string text , string jeek_id );
	void add_jeek_notif(string jeek_id);
	void show_search_user_result();
	void find_hash_tags( string hash_tag );
	void follow(User* new_follower);
	void unfollow(User* pre_follower);
	void be_followed(User* follower_user);
	void be_unfollowed(User* unfollower_user);
	void add_notif(Notification* new_notif){ user_notifs.push_back(new_notif); }
	void notification();
	void clear_notification(){ user_notifs.clear(); }
	int find_follower(User* follower);
	int find_following(User* following);
	Jeek* find_jeek( string jeek_id );
	Message* find_rep_cm(string jeek_id);
	string get_username(){ return username; }
	string get_password(){ return password; }
	string get_displayname(){ return display_name; }
};

#endif