CXX = g++
SERVER = server
CLIENT = client
LOG = bgcc.log LXB.log
CFLAGS = -Wall -L.. -lbgcc -lpthread
#CFLAGS = -Wall -L.. -lbgcc -lpthread -luuid -ftime-report -O0

INC_PATH_PREFIX = ../../../output/include

INC_PATH += -I$(INC_PATH_PREFIX)
INC_PATH += -I../output-cpp

LD_PATH = -L../../../output/lib/

SRC += ../output-cpp/math.cpp
SRC += ../output-cpp/address.cpp

all: $(CLIENT) $(SERVER)

$(SERVER): server.cpp $(SRC)
	$(CXX) -g -o $@ $^ $(INC_PATH) $(LD_PATH)  $(CFLAGS)

$(CLIENT): client.cpp $(SRC)
	$(CXX) -g -o $@ $^ $(INC_PATH)  $(LD_PATH) $(CFLAGS)

clean:
	rm -rf $(CLIENT) $(SERVER) $(LOG)
	killall server
