CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/server_main.o: server/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/main.cpp -o $(BUILD_DIR)/server_main.o

$(BUILD_DIR)/management.o: src/management.cpp src/management.hpp
	$(CC) $(CF) -c src/management.cpp -o $(BUILD_DIR)/management.o

$(BUILD_DIR)/user.o: src/user.cpp src/user.hpp
	$(CC) $(CF) -c src/user.cpp -o $(BUILD_DIR)/user.o

$(BUILD_DIR)/message.o: src/message.cpp src/message.hpp
	$(CC) $(CF) -c src/message.cpp -o $(BUILD_DIR)/message.o

$(BUILD_DIR)/content.o: src/content.cpp src/content.hpp
	$(CC) $(CF) -c src/content.cpp -o $(BUILD_DIR)/content.o

$(BUILD_DIR)/id_maker.o: src/id_maker.cpp src/id_maker.hpp
	$(CC) $(CF) -c src/id_maker.cpp -o $(BUILD_DIR)/id_maker.o

$(BUILD_DIR)/jeek.o: src/jeek.cpp src/jeek.hpp
	$(CC) $(CF) -c src/jeek.cpp -o $(BUILD_DIR)/jeek.o

$(BUILD_DIR)/interface.o: server/interface.cpp server/interface.hpp
	$(CC) $(CF) -c server/interface.cpp -o $(BUILD_DIR)/interface.o

$(BUILD_DIR)/requestHandlers.o: server/requestHandlers.cpp server/requestHandlers.hpp
	$(CC) $(CF) -c server/requestHandlers.cpp -o $(BUILD_DIR)/requestHandlers.o

server.out: $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/management.o $(BUILD_DIR)/user.o $(BUILD_DIR)/message.o $(BUILD_DIR)/content.o $(BUILD_DIR)/id_maker.o $(BUILD_DIR)/jeek.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/requestHandlers.o
	$(CC) $(CF) $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/management.o $(BUILD_DIR)/user.o $(BUILD_DIR)/message.o $(BUILD_DIR)/content.o $(BUILD_DIR)/id_maker.o $(BUILD_DIR)/jeek.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/requestHandlers.o -o server.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null
