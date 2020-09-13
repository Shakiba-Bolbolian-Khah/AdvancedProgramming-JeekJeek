#ifndef _ERROR_H__
#define _ERROR_H__
#include <iostream>

using namespace std;

class Bad_Command_Size{
public:
	Bad_Command_Size(){ cout << "Command entered with wrong number of arguments!\n"; }
};

class Bad_Jeek_Text_Size{
public:
	Bad_Jeek_Text_Size(){ cout<< "Text has more than 140 characters!\n"; }
};

class Bad_Command{
public:
	Bad_Command(){ cout<<"Invalid command!\n"; }
};

class Bad_Search_Command{
public:
	Bad_Search_Command(){ cout<<"Invalid search command!\n"; }
};

class Logged_In_Before{
public:
	Logged_In_Before(){ cout<< "You've logged in before!\n"; }
};

class Repetitious_Username{
public:
	Repetitious_Username(){ cout<< "This username was chosen before!\n"; }
};

class Wrong_Password{
public:
	Wrong_Password(){ cout<< "Wrong password is entered!\n"; }
};

class User_Not_Found{
public:
	User_Not_Found(){ cout<< "User not found!\n"; }
};

class Message_Not_Found{
public:
	Message_Not_Found(){ cout<< "Message not found!\n"; }
};

class Followed_Before{
public:
	Followed_Before(){ cout << "You've followed this user before!\n"; }
};

class Not_Followed_Before{
public:
	Not_Followed_Before(){ cout<< "You've not followed this user before!\n"; }
};

class Liked_Before{
public:
	Liked_Before(){ cout<< "You liked this jeek before!\n"; }
};

class No_Like_Before{
public:
	No_Like_Before(){ cout<< "You didn't like this jeek before!\n"; }
};

#endif