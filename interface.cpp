#include "interface.hpp"

string Interface::read_command( string instruct ){
	ins.clear();
	ins << instruct;
	string command;
	ins >> command;
	return command; 
}

void Interface::read_arguments(){
	instruction.clear();
	while( !ins.eof() ){
		string temp;
		ins >> temp;
		instruction.push_back(temp);
	}
}

void Interface::check_instruction( string instruct ){
	string command = read_command( instruct );
	if( check_instruction_for_message( command ))
		check_instruction_for_other_instruction( command );
}

bool Interface::check_instruction_for_message( string command ){
	if ( command == "jeek" ){
		read_instruction_for_jeek();
		return false;
	}

	else if ( command == "reply" ){
		read_instruction_for_cm_reply();
		management.add_reply( instruction[0] , instruction[1] );
		return false;
	}
	else if( command == "comment"){
		read_instruction_for_cm_reply();
		management.add_comment(instruction[0] , instruction[1] );
		return false;
	}
	return true;
}

void Interface::check_instruction_for_other_instruction( string command ){
	read_arguments();
	if( command == "signup" ){
		if(instruction.size() == 3 )
			management.signup(instruction[0] , instruction[1] , instruction[2] );
		else
			throw( Bad_Command_Size() );
	}
	else if( command == "login" ){
		if(instruction.size() == 2 )
			management.login(instruction[0] , instruction[1] );
		else
			throw( Bad_Command_Size() );
	}
	else if( command == "logout" ){
		if(instruction.size() == 0 )
			management.logout();
		else
			throw( Bad_Command_Size() );
	}
	else if(instruction.size() == 1){

		if( command == "search" )
			check_instruction_for_search();

		else if( command == "showJeek" )
			management.show_jeek(instruction[0]);

		else if( command == "showReply" || command == "showComment" )
			management.show_comment_reply(instruction[0]);

		else if( command == "rejeek" )
			management.rejeek(instruction[0] );

		else if( command == "like" )
			management.like(instruction[0]);

		else if( command == "dislike" )
			management.dislike(instruction[0] );

		else if( command == "follow" )
			management.follow(instruction[0]);

		else if( command == "unfollow" )
			management.unfollow(instruction[0]);

		else if( command == "notification" )
			management.notification();

		else
			throw (Bad_Command());
	}
	else if(instruction.size() != 1 )
		throw( Bad_Command_Size() );

	else
		throw ( Bad_Command() );
}

void Interface::check_instruction_for_search(){
	if( instruction[0][0] == '#' ){
		instruction[0].erase(instruction[0].begin());
		management.search_hash_tags(instruction[0]);
	}
	else if( instruction[0][0] == '@' ){
		instruction[0].erase(instruction[0].begin());
		management.search_user(instruction[0]);
	}
	else
		throw ( Bad_Search_Command() );
}

void Interface::read_instruction_for_cm_reply(){
	string id , content ;
	if( ins >> id )
		instruction.push_back(id);
	if( getline(ins , content ))
		instruction.push_back(content);
	if( instruction.size() != 2 )
		throw (Bad_Command_Size());
}

void Interface::read_instruction_for_jeek(){
	vector < vector < string> > data(3);
	string check_jeek_command_size , instruct ;
	if( ins >> check_jeek_command_size )
		throw( Bad_Command_Size() );

	getline( cin , instruct );
	while( instruct!= "publish" && instruct!="abort" ){
		string command = read_command( instruct );
		organize_info( command , data );
		getline( cin , instruct );
	}

	if(instruct == "publish" )
		management.add_jeek( data );
}

void Interface::organize_info( string command , vector<vector< string> > &data ){
	if( command == "text" ){
		string text;
		getline(ins , text);
		edit_text(text);

		if(data[0].size()==0)
			data[0].push_back(text);
		else
			data[0][0] = text;
		return;
	}
	read_arguments();
	if(instruction.size() != 1 )
		throw(Bad_Command_Size());
	if( command == "mention" )
		data[2].push_back(instruction[0]);
	else if( command == "tag" )
		data[1].push_back(instruction[0]);
	else
		throw( Bad_Command() );
}


void Interface::edit_text(string &text){
	while( text[0] == ' ' || text[0] == '\t' ){
		text.erase(text.begin() );
	}
}
