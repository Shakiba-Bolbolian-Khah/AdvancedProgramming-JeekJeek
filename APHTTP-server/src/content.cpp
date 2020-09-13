#include "content.hpp"

Content:: Content( string _text , vector<string> _hashTags , vector<string> _mentions ){
	text = _text;
	hashTags = _hashTags; 
	mentions = _mentions;
}

bool Content::findHashTags(string hashTag){
	for(int i = 0 ; i < hashTags.size() ; i++ )
		if (hashTags[i] == hashTag)
			return true;
	return false;
}

string Content::getTags(){
	string tags;
	for(int i = 0 ; i < hashTags.size() ; i++ )
		tags += "#" + hashTags[i];
	return tags;
}

string Content::getMentions(){
	string mentionsText;
	for(int i = 0 ; i < mentions.size() ; i++ )
		mentionsText += "@" + mentions[i];

	return mentionsText;
} 