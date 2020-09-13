#include "content.hpp"

Content:: Content( string _text , vector<string> _hash_tags , vector<string> _mentions ){
	text = _text;
	hash_tags = _hash_tags; 
	mentions = _mentions;
}

bool Content::find_hash_tags(string hash_tag){
	for(int i = 0 ; i < hash_tags.size() ; i++ )
		if (hash_tags[i] == hash_tag)
			return true;
	return false;
}

void Content::print(){
	cout << text << endl;
	for (int i = 0 ; i < hash_tags.size() ; i++ )
		cout << "#" << hash_tags[i] << endl;
	for (int i = 0 ; i < mentions.size() ; i++ )
		cout << "@" << mentions[i] << endl;
}