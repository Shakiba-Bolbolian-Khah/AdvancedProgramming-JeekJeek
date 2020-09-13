#include "id_maker.hpp"

IdMaker::IdMaker(){
	numOfJeek = 0;
	numOfRep = 0;
	numOfCm = 0;
}

string IdMaker::makeId(string messageType){
	string newId;
	if ( messageType == "J"){
		numOfJeek++;
		newId = messageType + intToStr(numOfJeek);
	}
	else if ( messageType == "R"){
		numOfRep++;
		newId = messageType + intToStr(numOfRep);
	}
	else if( messageType == "C"){
		numOfCm++;
		newId = messageType + intToStr(numOfCm);
	}
	return newId;
}

string intToStr ( int number ){
	string str ;
	while ( number )
	{
		str.push_back ( '0' + number% 10 ) ;
		number /= 10 ;
	}
	reverse ( str.begin() , str.end() ) ;
	return str ;
}