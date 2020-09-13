#include "interface.hpp"

Management* InterFace::management = new Management;
InterFace::InterFace(int port) : server(port)
{

	// vector < vector < string > > data(3);
	// data[0].push_back("It's not a faith in technology. It's faith in people!");
	// data[1].push_back("Technology");
	// data[1].push_back("Programming");
	// data[2].push_back("SteveJobs");
	// InterFace::management->signup("Shakiba_99" , "Shakiba" , "123456");
	// InterFace::management->addJeek( data , "Shakiba_99");

	server.get("/home_icon", new ShowImage("htmlFiles/home.png"));
	server.get("/home", new ShowPage("htmlFiles/home.html"));
	server.post("/signup_page", new ShowPage("htmlFiles/signup1.html"));
	server.get("/signup_page", new ShowPage("htmlFiles/signup1.html"));
	server.post("/login" , new SignupHandler());
	server.get("/login_bg" , new ShowImage("htmlFiles/login.png"));
	server.post("/login_page", new ShowPage("htmlFiles/login1.html"));
	server.get("/login_page", new ShowPage("htmlFiles/login1.html"));
	server.post("/user_home", new LoginHandler());
	server.get("/user_bg", new ShowImage("htmlFiles/user.png"));
	server.get("/back_user_home" , new UserHomeHandler() );
	server.get("/logout" , new LogoutHandler());
	server.get("/search_icon" , new ShowImage("htmlFiles/search.png"));
	server.post("/search_page" , new SearchHandler() );
	server.get("/jeek_detail" , new JeekHandler() );
	server.get("/jeek_detail_bg" , new ShowImage("htmlFiles/jeekDetail.png"));
	server.get("/like" , new LikeHandler() );
	server.get("/rejeek" , new RejeekHandler() );
	server.get("/like_logo" , new ShowImage("htmlFiles/like.png"));
	server.get("/dislike_logo" , new ShowImage("htmlFiles/dislike.png"));
	server.get("/logo" , new ShowImage("htmlFiles/Logo.png"));
	server.get("/bg" , new ShowImage("htmlFiles/bg.png"));
	server.post("/menu" , new ShowPage("htmlFiles/menu.html"));
	server.get("/menu_page" , new ShowImage("htmlFiles/menu1.png"));
	server.get("/add_jeek_bg" , new ShowImage("htmlFiles/addJeek.png"));
	server.get("/add_jeek" , new ShowPage("htmlFiles/add_jeek.html"));
	server.post("/add_jeek" , new AddJeekHandler() );
}