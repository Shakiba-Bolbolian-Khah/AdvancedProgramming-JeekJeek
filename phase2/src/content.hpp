#ifndef _CONTENT_H_
#define _CONTENT_H_
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Content{
private:
	string text;
	vector<string> hashTags;
	vector<string> mentions;

public:
	Content( string _text , vector<string> _hashTags , vector<string> _mentions );
	Content(string _text) : text( _text ){}
	bool findHashTags(string hashTag );
	string getText() { return text; }
	string getTags();
	string getMentions(); 
};


#endif