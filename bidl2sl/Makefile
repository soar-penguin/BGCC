.PHONY: bidl2sl

VERSION = \"1.4\"
CC = g++
CFLAGS = -Wall -W -pipe -Wno-unused -Wreorder -Wwrite-strings -Wswitch -Wno-sign-compare \
		 -finline-functions -Winline -Wreturn-type -Wtrigraphs -Wformat -Wparentheses -Wpointer-arith -Werror \
		 -g -DVERSION=$(VERSION) -D_BIDL_DEBUG=1
EXE = bidl2sl

SRC_DIR= .
INC = -I.

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))

SCANNER = scaner
GRAMMAR = grammar

$(EXE): $(OBJS)
	#$(EXE): $(GRAMMAR).y $(SCANNER).l $(OBJS)
	#bison -d $(GRAMMAR).y
	#flex -o$(SCANNER).c $(SCANNER).l
	$(CC) -o $@ $(OBJS) $(GRAMMAR).tab.c $(SCANNER).c $(CFLAGS)

$(OBJS): %.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_PATH)

clean:
	rm -rf $(EXE) $(OBJS)
