TARGET = ops3
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

CXXFLAGS  = -g -std=c++11
CXXFLAGS += -Wall -Wextra -Werror -Wfatal-errors

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $*.o $<

clean:
	$(RM) $(TARGET) $(OBJECTS)
