CXX = g++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lwinmm

TARGET = bin/program

SRC = Project2/main.cpp Project2/threads.cpp Project2/input.cpp Project2/array_utils.cpp
OBJ = $(SRC:Project2/%.cpp=obj/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

obj/%.o: Project2/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj bin
