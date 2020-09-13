#ifndef _ERROR_H__
#define _ERROR_H__
#include <iostream>

using namespace std;

class BadJeekTextSize{
public:
	BadJeekTextSize(){ cout<< "Text has more than 140 characters!\n"; }
};

class BadSearchCommand{
public:
	BadSearchCommand(){ cout<<"Invalid search command!\n"; }
};

class LoggedInBefore{
public:
	LoggedInBefore(){ cout<< "You've logged in before!\n"; }
};

class RepetitiousUsername{
public:
	RepetitiousUsername(){ cout<< "This username was chosen before!\n"; }
};

class WrongPassword{
public:
	WrongPassword(){ cout<< "Wrong password is entered!\n"; }
};

class UserNotFound{
public:
	UserNotFound(){ cout<< "User not found!\n"; }
};

class MessageNotFound{
public:
	MessageNotFound(){ cout<< "Message not found!\n"; }
};


#endif