CXX = g++
CXXFLAGS = -Wall -fPIC -g -DNDEBUG

INC_DIR += -I.
SRC_DIR += .
LIB_DIR +=

OUTPUT_DIR = ../$(OUTPUT_PATH)
OUTPUT_INCLUDE_DIR = $(OUTPUT_DIR)/include
OUTPUT_LIBRARY_DIR = $(OUTPUT_DIR)/lib
LIBRARY_NAME = libbgcc
SO_VERSION = 2.0
STATIC_LIBRARY_NAME = $(LIBRARY_NAME).a
SO_SUBVERSION = 0
DYNAMIC_LIBRARY_NAME = $(LIBRARY_NAME).so


SOURCE := $(foreach src,$(SRC_DIR), \
	$(wildcard \
	$(addprefix $(src)/*,.cpp .c) ) )

INCLUDES := $(foreach src, $(SRC_DIR), \
	$(wildcard \
	$(addprefix $(src), /*.h /*.hpp) ) )

INC_DIR += $(foreach src, $(SRC_DIR), \
	$(addprefix -I,$(src)) )

OBJECTS = $(patsubst %.cpp,%.o, \
	$(patsubst %.c,%.o,$(SOURCE)) )


all: lib inc
	
lib: $(OBJECTS)
	-rm -rf $(OUTPUT_LIBRARY_DIR)
	-mkdir -p $(OUTPUT_LIBRARY_DIR)
	ar cr $(OUTPUT_LIBRARY_DIR)/$(STATIC_LIBRARY_NAME).$(SO_VERSION) $^
	ln -s $(STATIC_LIBRARY_NAME).$(SO_VERSION) $(OUTPUT_LIBRARY_DIR)/$(STATIC_LIBRARY_NAME)

inc: 
	rm -rf $(OUTPUT_INCLUDE_DIR)
	mkdir -p $(OUTPUT_INCLUDE_DIR)
	cp $(INCLUDES) $(OUTPUT_INCLUDE_DIR)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c  -o $@ $(INC_DIR) $^

clean:
	rm -f $(OBJECTS)
	echo $(OUTPUT_DIR)
