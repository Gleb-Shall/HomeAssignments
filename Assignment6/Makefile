PROJECT = classes

LIBPROJECT = $(PROJECT).a

TESTPROJECT = test

CXX = g++

A = ar

AFLAGS = rsv

CXXFLAGS = -I. -std=c++11 -Wall -Wextra -g -pthread

LDXXFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT)

LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

DEPS = $(wildcard *.h)

OBJ = Class1.o Class2.o Class3.o Transformer.o TransformerTest.o

# Test object files (just the test file for now)
TEST-OBJ = TransformerTest.o

.PHONY: default

default: all cleanall

# Rule to compile .cpp files to .o files
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Create static library
$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

# Build the test executable
$(TESTPROJECT): $(LIBPROJECT) $(TEST-OBJ)
	$(CXX) -o $@ $(TEST-OBJ) $(LDGTESTFLAGS)

# Run the tests
tests: $(TESTPROJECT)
	./$(TESTPROJECT)

# Build all targets
all: tests

# Clean up object files
clean:
	rm -f *.o

# Clean up all build artifacts
cleanall: clean
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
