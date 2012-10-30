ifndef JAVA_HOME
		$(error Variable 'JAVA_HOME' does not set.)
endif

LIB = libbgcc4j.so
CXX = g++
CXXFLAGS = -shared -W -fPIC -Wno-format-security
SRC_DIR = .
INC_PATH = -I$(JAVA_HOME)/include/ \
 		   -I$(JAVA_HOME)/include/linux/ \
		   -I../../../output/include/

LIB_PATH= -L../../../output/lib/
LDFLAGS = -lbgcc

SOURCES= $(wildcard $(SRC_DIR)/*.cpp)
OBJS= $(patsubst %.cpp,%.o,$(SOURCES))

all: output

output: $(LIB)
	cp libbgcc4j.so ../output
$(LIB): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIB_PATH) $(LDFLAGS)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_PATH)

clean:
	rm -f $(OBJS)
	rm -f $(LIB)
	rm -f ../output/libbgcc4j.so
