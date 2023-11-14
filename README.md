# Hangman

A blazingly fast Hangman game written in C++ for UNIX terminals.

# Compilation

Enter 'make' in the cloned repo to generate the executable, and object files.

# Usage

You will have to pass the "words.txt" file around with the executable. Other than
that it works like a regular hangman game. The words aren't the best but it is still
pretty fun to mess around with especially if you're bored at work or class.

# Blazingly Fast?

The reason this	Hangman	implementation is blazingly fast is due	to two things,	
the optimized usage	of std::vector,	and the	usage of small strings.	

- std::string has	an optimization	for small strings. The default capacity is 15
  (depending on the STL implementation it could be higher), so if a string is 15
  characters or lower there will be no heap allocation. Therefore, the words in
  'words.txt' have been filtered to be 15 characters or less.

- The std::vector in the 'Hangman' class will always reserve a capacity of 6, and
  will	use 'emplace_back' to efficiently insert elements into the vector. With
  these optimizations the vector will only allocate 6 bytes of memory and will
  never resize.

# References

ASCII art: http://www.fssnip.net/mO/title/Hangman

Word generation: https://generate-random.org/word-generator?count=1&type=capital
