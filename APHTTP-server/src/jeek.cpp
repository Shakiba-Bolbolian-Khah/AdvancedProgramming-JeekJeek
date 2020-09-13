#include "jeek.hpp"
#include "user.hpp"

Jeek::Jeek(Content _content , User* _publisher , string _messageId ): Message(_content, _publisher, _messageId) {
	numOfLikes = 0 ;
	numOfRejeeks = 0 ;
}


void Jeek::like( string likerName ) {
	numOfLikes++;
	likers.push_back( likerName );
}

void Jeek::dislike( string dislikerName ) {
	numOfLikes--;
	likers.erase( likers.begin() + findLiker(dislikerName) );
}

int Jeek::findLiker( string username ) {
	for (int i = 0 ; i < likers.size() ; i++ )
		if ( likers[i] == username )
			return i;
	return -1;
}

void Jeek::handleLike( string likerUsername ) {
	if( findLiker(likerUsername) == -1 )
		like( likerUsername );
	else
		dislike( likerUsername );

}

void Jeek::addJeekInfo( string &jeekHtml , string likerUsername ) {
	jeekHtml.replace( jeekHtml.find('*') , 1 , publisher->getUsername() );
	jeekHtml.replace( jeekHtml.find("TEXT") , 4 , content.getText());
	jeekHtml.replace( jeekHtml.find("TAGS") , 4 , content.getTags());
	jeekHtml.replace( jeekHtml.find("MTNS") , 4 , content.getMentions());
	jeekHtml.replace( jeekHtml.find('^') , 1 , to_string(numOfLikes) );
	jeekHtml.replace( jeekHtml.find('^') , 1 , to_string(numOfRejeeks) );

	if ( findLiker(likerUsername) == -1)
		jeekHtml.replace( jeekHtml.find('+') , 1 , "/dislike_logo");
	else
		jeekHtml.replace( jeekHtml.find('+') , 1 , "/like_logo");

	for ( int i=0 ; i<2 ; i++)
		jeekHtml.replace( jeekHtml.find('+'), 1 , messageId );
}