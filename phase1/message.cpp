#include "message.hpp"
#include "user.hpp"

Message:: Message(Content _content , User* _publisher , string _message_id ) : content(_content){
	publisher = _publisher;
	message_id = _message_id;
}

bool Message::find_hash_tags(string hash_tag ){
	if (content.find_hash_tags(hash_tag))
		return true;
	else 
		return false;
}

Message* Message::find_rep_cm(string _message_id){
	if(message_id == _message_id)
		return this;
	for (int i = 0 ; i < sub_message.size() ; i++){
		Message* found_message = sub_message[i]->find_rep_cm(_message_id);
		if( found_message != NULL )
			return found_message;
	}
	return NULL;
}

void Message::show_message(){
	cout << publisher->get_displayname() << endl;
	content.print();
	cout << "Replies:" << endl;
	for (int i = 0 ; i < sub_message.size() ; i++ )
		cout << sub_message[i]->get_id() << endl;

}