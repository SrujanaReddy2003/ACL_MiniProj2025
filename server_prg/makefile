# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# Source files
SRCS = main.cpp ServerTCP.cpp ServerUDP.cpp CommandProcessor.cpp

# Executable name
EXEC = iftp_server

# Target for the executable
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

# Clean target to remove compiled executable
clean:
	rm -f $(EXEC)

