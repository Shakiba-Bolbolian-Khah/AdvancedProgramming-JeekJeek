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
	}
    catch(...){
	    res->setBody(readFile("htmlFiles/login1.html") 
            + readFile("htmlFiles/loginAlert.html"));
	    return res;
    }
    res->setBody(makeHomeHtml(sessionId));
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
	    res->setBody(readFile("htmlFiles/signup1.html") + readFile("htmlFiles/signupAlert.html"));	
	    return res;    	
    }
    res->setBody(readFile("htmlFiles/login1.html"));
    return res;
}

Response* LogoutHandler::callback(Request *req){
	Response *res = new Response;
	string sessionId = req->getSessionId();
    res->setHeader("Content-Type", "text/html");
    InterFace::management->logout( sessionId );
    res->setBody(readFile("htmlFiles/login1.html"));
    res->setSessionId("");
    return res;
}

Response* SearchHandler::callback(Request *req){
    Response *res = new Response;
    string sessionId = req->getSessionId();
    string searchText = req->getBodyParam("searchText");
    cout << "Received Data: " << searchText << endl;
    res->setHeader("Content-Type", "text/html");
    res->setBody(makeSearchHtml( searchText , sessionId ));
    return res;
}

Response* JeekHandler::callback(Request *req){
    cerr << "here " << endl;
    Response *res = new Response;
    string jeekId = req->getQueryParam("jeekId");
    string sessionId = req->getSessionId();
    cout << "Received Data:" << jeekId << endl;
    res->setHeader("Content-Type", "text/html");
    res->setBody(makeJeekHtml( sessionId , jeekId ));
    return res;
}

Response* UserHomeHandler::callback(Request *req){
    Response *res = new Response;
    string sessionId = req->getSessionId();
    res->setHeader("Content-Type", "text/html");
    res->setBody(makeHomeHtml(sessionId));
    return res;  
}

Response* LikeHandler::callback(Request *req){
    Response *res = new Response;
    string jeekId = req->getQueryParam("jeekId");
    string sessionId = req->getSessionId();
    InterFace::management->handleLike( sessionId , jeekId );
    res->setHeader("Content-Type", "text/html");
    res->setBody(makeJeekHtml( sessionId , jeekId ));
    return res;
}

Response* RejeekHandler::callback(Request *req){
    Response *res = new Response;
    string jeekId = req->getQueryParam("jeekId_");
    string sessionId = req->getSessionId();
    res->setHeader("Content-Type", "text/html");
    try{
        InterFace::management->handleRejeek( sessionId , jeekId );
    }
    catch(...){
        res->setBody(makeJeekHtml(sessionId ,jeekId ) + readFile("htmlFiles/rejeekAlert.html"));
        return res;
    }
    res->setBody(makeJeekHtml( sessionId , jeekId ));
    return res;
}

Response* AddJeekHandler::callback(Request *req){
    Response *res = new Response;
    vector< vector<string> > content(3);
    cout << "Received Data: " ;
    content[0].push_back(req->getBodyParam("text"));
    cout << content[0][0] ;
    if ( req->getBodyParam("tag") != "" ){
        cerr << "////" << endl;
        content[1].push_back(req->getBodyParam("tag"));
        cout << "-" << content[1][0];
    }
    if( req->getBodyParam("mention") != "" ){
        content[2].push_back(req->getBodyParam("mention"));
        cout << "-" << content[2][0] ;
    }
    cout << endl;
    string sessionId = req->getSessionId();
    res->setHeader("Content-Type", "text/html");
    if(content[1].size() != 0 && content[1][0].find(' ') != string::npos){
        res->setBody(readFile("htmlFiles/add_jeek.html")+readFile("htmlFiles/add_jeek_alert.html"));
        return res;
    }
    else{
        InterFace::management->addJeek( content , sessionId );
        res->setBody(readFile("htmlFiles/add_jeek.html")+readFile("htmlFiles/add_jeek_notif.html"));
        return res;
    }
}

string SearchHandler::makeSearchHtml( string searchText , string sessionId){
    string searchHtml = makeHtmlFile( searchText , true );
    InterFace::management->addSearchResult( searchText , searchHtml , sessionId);
    return searchHtml;
}

string JeekHandler::makeJeekHtml( string sessionId , string jeekId ){
    string jeekHtml = readFile("htmlFiles/jeekDetail.html");
    string username = InterFace::management->findUsername(sessionId);
    string displayname = InterFace::management->findUser(username)->getDisplayname();
    int posOfDisplayname = jeekHtml.find('$');
    jeekHtml.replace(posOfDisplayname , 1, displayname );
    InterFace::management->findJeek(jeekId)->addJeekInfo( jeekHtml , username );
    return jeekHtml;
}
