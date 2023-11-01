CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
HEADERS = src/h
CPP = src/cpp
TARGET = Hangman

$(TARGET): Random.o File_In.o Hangman.o Display.o main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Display.o Hangman.o File_In.o Random.o

Random.o: $(CPP)/Random.cpp $(HEADERS)/Random.h
	$(CXX) $(CXXFLAGS) -c $(CPP)/Random.cpp -I$(HEADERS)/

File_In.o: $(CPP)/File_In.cpp $(HEADERS)/File_In.h
	$(CXX) $(CXXFLAGS) -c $(CPP)/File_In.cpp -I$(HEADERS)/

Hangman.o: $(CPP)/Hangman.cpp $(HEADERS)/Hangman.h
	$(CXX) $(CXXFLAGS) -c $(CPP)/Hangman.cpp -I$(HEADERS)/

Display.o: $(CPP)/Display.cpp $(HEADERS)/Display.h $(HEADERS)/Hangman.h
	$(CXX) $(CXXFLAGS) -c $(CPP)/Display.cpp -I$(HEADERS)/

main.o: $(CPP)/main.cpp $(HEADERS)/Display.h $(HEADERS)/File_In.h $(HEADERS)/Random.h
	$(CXX) $(CXXFLAGS) -c $(CPP)/main.cpp -I$(HEADERS)/

clean:
	rm -f *.o Hangman
