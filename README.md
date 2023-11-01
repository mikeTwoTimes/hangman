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
  characters or lower there will be no heap allocation.

- The std::vector in the 'Hangman' class will always reserve a size of 6 in the
  constructor, And will	use 'emplace_back' in the	method 'update_wrong' instead of
  'push_back'. These optimizations will reduce the number of memory allocations to one.

# References

ASCII art: http://www.fssnip.net/mO/title/Hangman

Word generation: https://generate-random.org/word-generator?count=1&type=capital
