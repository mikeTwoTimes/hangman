# Hangman

A blazingly fast Hangman game written in C++.

# Compilation & Usage

Make sure you have your friendly neighborhood C++ compiler and double check to 
make sure it supports up to C++ 17. A makefile has been provided for compilation.

# Dependencies

You will have to pass the "words.txt" file around with the executable, and your 
terminal must have [ANSI escape code](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797) support.

# Blazingly Fast?

The reason this	Hangman	implementation is blazingly fast is due	to two things,	
the optimized usage	of std::vector,	and the	usage of small strings.	

- std::string has	an optimization	for small strings. The default capacity of
  a std::string is 15 (depending on the STL implementation it could be higher),
  so if a string is 15 characters or lower there will be no heap allocation.
  Therefore, the words in 'words.txt' have been filtered to be 15 characters or
  less.

- The std::vector in the 'Hangman' class will always reserve a capacity of 6, and
  will	use 'push_back' to efficiently insert elements into the vector. With
  these optimizations the vector will only allocate 6 bytes of memory and will
  never resize.

# Credits

ASCII art: http://www.fssnip.net/mO/title/Hangman

Word generation: https://generate-random.org/word-generator?count=1&type=capital
