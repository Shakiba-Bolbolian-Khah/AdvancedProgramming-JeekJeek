#include "user.hpp"

User::User(string _username , string _display_name , string _password ){
	username = _username;
	display_name = _display_name;
	password = _password;
}

void User::add_jeek( vector < vector < string > > data , string jeek_id ){
	if( data[0][0].size() > 140 ){
		throw( Bad_Jeek_Text_Size() );
	}

	Content new_content( data[0][0] , data[1] , data[2] );
	Jeek* new_jeek = new Jeek( new_content , this , jeek_id );

	jeeks.push_back(new_jeek);

	add_jeek_notif( jeek_id );
}

void User::add_jeek_notif(string jeek_id){
	for (int i = 0 ;i < followers.size() ; i++ ){
		Notification* new_notif = new Jeek_Notif( this->username , jeek_id );
		followers[i]->user_notifs.push_back( new_notif );
	}
}

void User::show_search_user_result(){
	for(int i = 0 ; i < jeeks.size() ; i++ ){
		cout << jeeks[i]->get_id() << '\t' << display_name << endl;
		jeeks[i]->print_search_result();
		if ( i < jeeks.size()-1 )
			cout << endl;
	}
}

void User::find_hash_tags( string hash_tag ){
	for (int i = 0 ; i < jeeks.size() ; i++ ){
		if( jeeks[i]->find_hash_tags(hash_tag) ){
			cout << jeeks[i]->get_id() << '\t' << display_name << endl;
			jeeks[i]->print_search_result();
			if ( i < jeeks.size()-1 )
				cout << endl; 
		}
	}
}

Jeek* User::find_jeek( string jeek_id ){
	for( int i =0 ; i < jeeks.size() ; i++ ){
		if( jeeks[i]->get_id() == jeek_id )
			return jeeks[i];
	}
	return NULL;
}

bool User::add_rejeek( string text , string jeek_id ){
	string rejeek_text = "Rejeeked: " + text ;
	if ( rejeek_text.size() > 140 )
		throw(Bad_Jeek_Text_Size());

	Content rejeek_content(rejeek_text);
	Jeek* new_rejeek = new Jeek(rejeek_content , this , jeek_id );
	jeeks.push_back(new_rejeek);
	return true;
}

Message* User::find_rep_cm(string message_id){
	for( int i = 0 ; i < jeeks.size() ; i++ ){
		Message* found_message = jeeks[i]->find_rep_cm( message_id );
		if ( found_message != NULL )
			return found_message;
	}
	return NULL;
}

void User::follow(User* new_following){
	if(find_following(new_following) != -1 )
		throw(Followed_Before() );

	followings.push_back(new_following);
	new_following->be_followed(this);

}

void User::unfollow(User* pre_following){
	if( find_following(pre_following) == -1 )
		throw( Not_Followed_Before() );

	followings.erase(followings.begin()+find_following(pre_following));
	pre_following->be_unfollowed(this);

}

void User::be_followed(User* follower_user){
	followers.push_back(follower_user);
}

void User::be_unfollowed(User* unfollower_user){
	followers.erase(followers.begin()+find_follower(unfollower_user));
}

int User::find_follower(User* follower){
	for(int i = 0 ; i < followers.size() ; i++)
		if( follower->username == followers[i]->username )
			return i;

	return -1;
}

int User::find_following(User* following){
	for(int i = 0 ; i < followings.size() ; i++)
		if( following->username == followings[i]->username )
			return i;

	return -1;	
}

void User::notification(){
	for(int i=0 ; i < user_notifs.size() ; i++ )
		user_notifs[i]->print_notif();
	clear_notification();
}