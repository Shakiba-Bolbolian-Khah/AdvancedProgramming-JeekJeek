#include "jeek.hpp"
#include "user.hpp"

Jeek::Jeek(Content _content , User* _publisher , string _message_id ): Message(_content,_publisher,_message_id){
	num_of_likes = 0 ;
	num_of_rejeeks = 0 ;
}


void Jeek::show_message(){
	cout << publisher->get_displayname() << endl;
	content.print();
	cout << "Likes " << num_of_likes << endl;
	cout << "Rejeeks " << num_of_rejeeks << endl;
	cout << "comments:" << endl;
	for (int i = 0 ; i < sub_message.size() ; i++ )
		cout << sub_message[i]->get_id() << endl;
}

void Jeek::like( string liker_name ){
	if( find_liker(liker_name) != -1 )
		throw( Liked_Before() );

	num_of_likes++;
	likers.push_back( liker_name );
	add_like_notif( liker_name );
}

void Jeek::add_like_notif(string liker_name){
	Notification* new_notif = new Like_Notif( liker_name , message_id);
	publisher->add_notif( new_notif );
}

void Jeek::dislike( string disliker_name ){
	if( find_liker(disliker_name) == -1 )
		throw( No_Like_Before() );
	num_of_likes--;
	likers.erase( likers.begin()+find_liker(disliker_name) );
	add_dislike_notif( disliker_name );
}

void Jeek::add_dislike_notif( string disliker_name ){
	Notification* new_notif = new Dislike_Notif( disliker_name , message_id );
	publisher->add_notif( new_notif );
}

int Jeek::find_liker( string username ){
	for(int i = 0 ; i < likers.size() ; i++ )
		if( likers[i] == username )
			return i;
	return -1;
}