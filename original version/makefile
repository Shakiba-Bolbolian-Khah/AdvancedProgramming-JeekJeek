all: clean jeek_jeek.out

jeek_jeek.out:	main.o user.o notification.o message.o jeek.o interface.o id_maker.o content.o management.o error.o
	g++ main.o user.o notification.o message.o jeek.o interface.o id_maker.o content.o management.o error.o

main.o:	main.cpp
	g++ -c main.cpp

user.o:	user.cpp user.hpp
	g++ -c user.cpp

notification.o:	notification.cpp notification.hpp
	g++ -c notification.cpp

message.o:	message.cpp message.hpp
	g++ -c message.cpp

jeek.o:	jeek.cpp jeek.hpp
	g++ -c jeek.cpp

interface.o: interface.cpp interface.hpp
	g++ -c interface.cpp

id_maker.o:	id_maker.cpp id_maker.hpp
	g++ -c id_maker.cpp

content.o: content.cpp content.hpp
	g++ -c content.cpp

management.o: management.cpp management.hpp
	g++ -c management.cpp

error.o: error.cpp error.hpp 
	g++ -c error.cpp

clean:
	rm -rf *o jeek_jeek
