CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O3
SRC = src
TARGET = Hangman

all: $(TARGET)
	rm -f *.o

$(TARGET): Random.o File_In.o Hangman.o Display.o main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Display.o Hangman.o File_In.o Random.o

Random.o: $(SRC)/Random.cpp $(SRC)/Random.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/Random.cpp

File_In.o: $(SRC)/File_In.cpp $(SRC)/File_In.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/File_In.cpp

Hangman.o: $(SRC)/Hangman.cpp $(SRC)/Hangman.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/Hangman.cpp

Display.o: $(SRC)/Display.cpp $(SRC)/Display.h $(SRC)/Hangman.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/Display.cpp

main.o: $(SRC)/main.cpp $(SRC)/Display.h $(SRC)/File_In.h $(SRC)/Random.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp
