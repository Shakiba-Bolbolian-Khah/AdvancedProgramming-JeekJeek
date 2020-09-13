#ifndef _NOTIFICATION_H_
#define _NOTIFICATION_H_
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Notification{
protected:
	string text;
	string username;
	string id;
public:
	Notification(string username_ , string id_ ): username(username_) , id(id_){} ;
	void print_notif(){ cout << username << text << id << endl; }

};

class Like_Notif : public Notification{
public:
	Like_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " liked "; }
};

class Dislike_Notif : public Notification{
public:
	Dislike_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " disliked "; }
};

class Comment_Notif : public Notification{
public:
	Comment_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " commented on "; }
};

class Reply_Notif : public Notification{
public:
	Reply_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " replied "; }
};

class Jeek_Notif : public Notification{
public:
	Jeek_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " jeeked "; }
};

class Mention_Notif : public Notification{
public:
	Mention_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " mentioned you in "; }
};

class Rejeek_Notif : public Notification{
public:
	Rejeek_Notif( string username_ , string id_ ) : Notification( username_ , id_ ){ text = " rejeeked "; }
};

#endif
