#include "interface.hpp"

Management* InterFace::management = new Management;
InterFace::InterFace(int port) : server(port)
{
		server.get("/home_icon", new ShowImage("htmlFiles/home.png"));
		server.get("/home", new ShowPage("htmlFiles/home.html"));
		server.get("/signup_page", new ShowPage("htmlFiles/signup.html"));
		server.post("/signup" , new SignupHandler());
		server.get("/login_page", new ShowPage("htmlFiles/login.html"));
		server.post("/user_home", new LoginHandler());
		server.get("/logout" , new LogoutHandler());
		server.get("/search_icon" , new ShowImage("htmlFiles/search.png"));
		server.post("/search_page" , new SearchHandler() );
}