#include "requestHandlers.hpp"


Response* ShowPage::callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body = readFile(filePath.c_str());
    res->setBody(readFile(filePath.c_str()));
    return res;
}

Response* ShowImage::callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "image/png");
    string body = readFile(filePath.c_str());
    res->setBody(body);
    return res;
}

Response *LoginHandler::callback(Request *req) {
	string sessionId;
    Response *res = new Response;
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    cout << "Received Data: " << username << " - " << password << endl;
    res->setHeader("Content-Type", "text/html");
    try{
		sessionId = InterFace::management->login( username , password );





		vector < vector < string > > data(3);
    	data[0].push_back("hello world!");
    	data[1].push_back("theNewOne");
    	data[1].push_back("hashtags");
    	data[2].push_back("ssss");
    	data[2].push_back("aaa");
    	InterFace::management->setCurUser( sessionId );
    	InterFace::management->add_jeek(data);




	}
    catch(...){
	    res->setBody(readFile("htmlFiles/relogin.html"));
	    return res;
    }
    res->setBody(makeHomeHtml(username));
    res->setSessionId(sessionId);
    return res;
}


Response * SignupHandler::callback(Request *req) {
    Response *res = new Response;
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    string displayname = req->getBodyParam("displayname");
    cout << "Received Data: " << username << " - " << password << endl;
    res->setHeader("Content-Type", "text/html");
    try{
    	InterFace::management->signup( username , displayname , password );
    }
    catch(...){
	    res->setBody(readFile("htmlFiles/resignup.html"));	
	    return res;    	
    }
    res->setBody(readFile("htmlFiles/login.html"));
    return res;
}

string  LoginHandler::makeHomeHtml(string username){
	string homeHtml = makeHtmlFile( username );
	InterFace::management->addUserInfo(username , homeHtml);
	return homeHtml;
}

Response* LogoutHandler::callback(Request *req){
	Response *res = new Response;
	string sessionId = req->getSessionId();
    res->setHeader("Content-Type", "text/html");
    InterFace::management->logout( sessionId );
    res->setBody(readFile("htmlFiles/login.html"));
    res->setSessionId("");
    return res;
}

Response* SearchHandler::callback(Request *req){
    Response *res = new Response;
    string searchText = req->getBodyParam("searchText");
    cout << "Received Data: " << searchText << endl;
    res->setHeader("Content-Type", "text/html");
    res->setBody(makeSearchHtml( searchText ));
    return res;
}

string SearchHandler::makeSearchHtml( string searchText ){
    if(searchText[0] == "#")
}
