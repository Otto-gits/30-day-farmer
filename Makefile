# Define the compiler
CXX = g++

# Define the target executable
TARGET = main

# Define the source files
SRCS = main.cpp Plot.cpp Farm.cpp Wheat.cpp Crop.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the compiler flags
CXXFLAGS = -I/usr/include

# Define the linker flags
LDFLAGS = -L/usr/include -lsfml-graphics -lsfml-window -lsfml-system

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
