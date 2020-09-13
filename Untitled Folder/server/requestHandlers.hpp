#ifndef _REQUEST_HANDLER_H__
#define _REQUEST_HANDLER_H__
#include "interface.hpp"
#include "../src/management.hpp"
#include <string>
#include <vector>
#include <iostream>

class ShowPage : public RequestHandler {

	string filePath;

public:
	ShowPage(string _filePath) { filePath = _filePath; }
	Response *callback(Request *req);

};

class ShowImage : public RequestHandler {

	string filePath;

public:
	ShowImage(string _filePath) { filePath = _filePath; }
	Response *callback(Request *req);

};

class LoginHandler : public RequestHandler {

public:
	Response *callback(Request *req);
	string makeHomeHtml(string username);

};

class SignupHandler : public RequestHandler {

public:
	Response *callback(Request *req);

};

class LogoutHandler : public RequestHandler {

public:
	Response *callback(Request *req);
};

class SearchHandler : public RequestHandler {

public:
	Response *callback(Request *req);
};

#endif
