#ifndef _CONTENT_H_
#define _CONTENT_H_
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Content{
private:
	string text;
	vector<string> hash_tags;
	vector<string> mentions;

public:
	Content( string _text , vector<string> _hash_tags , vector<string> _mentions );
	Content(string _text) : text( _text ){}
	void print();
	string get_text() { return text; }
	bool find_hash_tags(string hash_tag );
};


#endif