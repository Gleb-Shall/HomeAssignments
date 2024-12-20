# Project name
PROJECT = start

# Compiler
CXX = g++

# Source files
SRC = main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable target
$(PROJECT): $(OBJ)
	$(CXX) -o $(PROJECT) $(OBJ) $(GTEST_LIBS)

# Compile object files
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(PROJECT)