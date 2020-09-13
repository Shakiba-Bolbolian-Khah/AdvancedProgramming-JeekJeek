#include "management.hpp"

void Management::signup( string username , string display_name , string password ){
	if ( !check_username_repeat( username ) )
		throw(Repetitious_Username() );

	User* new_user = new User(username , display_name , password);
	users.push_back( new_user );
	return;
}

bool Management::check_username_repeat( string username ){
	for (int i = 0 ; i < users.size() ; i++ )
		if( users[i]->get_username() == username )
			return	false;
	return true;
}

User* Management::find_user( string username ){
	for (int i = 0 ; i < users.size() ; i++ )
		if( users[i]->get_username() == username )
			return users[i];
	return NULL;
}

void Management::login( string username , string password ){
	User* found_user = find_user( username );
	if( found_user == NULL )
		throw( User_Not_Found() );

	if( cur_user != NULL )
		throw( Logged_In_Before() );

	if ( found_user->get_password() == password )
		cur_user = found_user;
	else
		throw( Wrong_Password() );
}

void Management::logout(){
	if( cur_user != NULL )
		cur_user = NULL;
}

void Management::add_jeek( vector < vector < string > > data ){
	if (cur_user != NULL){
		string jeek_id  = id_maker.make_id("J");
		cur_user->add_jeek(	data , jeek_id);
		add_mention_notif( data[2] , jeek_id );	
	}
}

void Management::add_mention_notif( vector<string> mentions , string jeek_id ){
	Notification* new_notif = new Mention_Notif( cur_user->get_username() , jeek_id );
	for(int i = 0 ; i < mentions.size() ; i++ ){
		User* found_user = find_user(mentions[i]);
		if ( found_user != NULL )
			found_user->add_notif( new_notif );
	}
}

void Management::search_user(string username ){
	for(int i = 0 ; i< users.size() ; i++ ){
		if (users[i]->get_username() == username )
			users[i]->show_search_user_result();
	}
}

void Management::search_hash_tags(string hash_tag ){
	for(int i = 0 ; i < users.size() ; i++ )
		users[i]-> find_hash_tags(hash_tag);
}

Jeek* Management::find_jeek(string jeek_id ){
	for (int i = 0 ; i<users.size() ; i++ )
		if(users[i]->find_jeek(jeek_id) != NULL )
			return users[i]->find_jeek(jeek_id);
}

void Management::add_comment( string jeek_id , string comment_text ){
	Jeek* found_jeek = find_jeek(jeek_id);
	if (found_jeek == NULL )
		throw( Message_Not_Found() );

	if (cur_user != NULL){
		string cm_id = id_maker.make_id("C");
		Content content( comment_text );
		Message* new_comment = new Comment(content , cur_user , cm_id );
		found_jeek->add_sub_message(new_comment );
		add_comment_notif( jeek_id );
	}
}

void Management::add_comment_notif( string jeek_id ){
	Notification* new_notif = new Comment_Notif(cur_user->get_username() , jeek_id );
	find_jeek(jeek_id)->get_publisher()->add_notif( new_notif );
}

void Management::show_comment_reply(string message_id){
	Message* found_message = find_rep_cm(message_id);
	if (found_message == NULL )
		throw( Message_Not_Found() );
	found_message->show_message();
}

void Management::show_jeek(string jeek_id){
	Jeek* found_jeek = find_jeek(jeek_id);
	if (found_jeek == NULL )
		throw ( Message_Not_Found() );

	found_jeek->show_message();
}

void Management::rejeek( string jeek_id ){
	Jeek* found_jeek = find_jeek( jeek_id );
	if (found_jeek == NULL )
		throw( Message_Not_Found() );

	if (cur_user != NULL){
		string rejeek_id = id_maker.make_id("J");
		if(cur_user->add_rejeek( found_jeek->get_text() , rejeek_id)){
			found_jeek->increase_rejeeks();
			add_rejeek_notif( jeek_id );
		}
	}
}

void Management::add_rejeek_notif(string jeek_id){
	Notification* new_notif = new Rejeek_Notif(cur_user->get_username() , jeek_id );
	find_jeek(jeek_id)->get_publisher()->add_notif(new_notif);
}

Message* Management::find_rep_cm(string message_id){
	for (int i = 0; i < users.size() ; i++ ){
		Message* found_message = users[i]->find_rep_cm(message_id);
		if ( found_message != NULL )
			return found_message;
	}
	return NULL;
}

void Management::add_reply( string rep_cm_id , string reply_text ){
	Message* found_message = find_rep_cm(rep_cm_id);
	if (found_message == NULL )
		throw( Message_Not_Found() );

	if (cur_user != NULL){
		string rep_id = id_maker.make_id("R");
		Content content(reply_text);
		Message* new_reply = new Reply(content , cur_user , rep_id);
		found_message->add_sub_message(new_reply);
		add_reply_notif( rep_cm_id );
	}
}

void Management::add_reply_notif( string rep_cm_id ){
	Notification* new_notif = new Reply_Notif(cur_user->get_username() , rep_cm_id );
	find_rep_cm(rep_cm_id)->get_publisher()->add_notif( new_notif );
}

void Management::like(string jeek_id){
	Jeek* found_jeek = find_jeek(jeek_id);
	if (found_jeek == NULL )
		throw( Message_Not_Found() );

	if( cur_user!= NULL )
		found_jeek->like(cur_user->get_username());
}

void Management::dislike(string jeek_id){
	Jeek* found_jeek = find_jeek(jeek_id);
	if (found_jeek == NULL )
		throw( Message_Not_Found() );

	if( cur_user!= NULL)
		found_jeek->dislike(cur_user->get_username());	
}

void Management::follow(string username){
	User* found_user = find_user(username);
	if( found_user == NULL )
		throw( User_Not_Found() );

	if(cur_user!=NULL )
		cur_user->follow(found_user);	
}

void Management::unfollow(string username){
	User* found_user = find_user(username);
	if( found_user == NULL )
		throw( User_Not_Found() );
	
	if( cur_user!= NULL )
		cur_user->unfollow(found_user);

}