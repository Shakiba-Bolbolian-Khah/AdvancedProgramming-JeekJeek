#include "id_maker.hpp"

Id_Maker::Id_Maker(){
	num_of_jeek = 0;
	num_of_rep = 0;
	num_of_cm = 0;
}

string Id_Maker::make_id(string message_type){
	string new_id;
	if ( message_type == "J"){
		num_of_jeek++;
		new_id = message_type + int_to_str(num_of_jeek);
	}
	else if ( message_type == "R"){
		num_of_rep++;
		new_id = message_type + int_to_str(num_of_rep);
	}
	else if( message_type == "C"){
		num_of_cm++;
		new_id = message_type + int_to_str(num_of_cm);
	}
	return new_id;
}

string int_to_str ( int number ){
	string str ;
	while ( number )
	{
		str.push_back ( '0' + number% 10 ) ;
		number /= 10 ;
	}
	reverse ( str.begin() , str.end() ) ;
	return str ;
}