#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector> 
#include <string> 
#include <fstream> 

/// @brief splits a string into a vector given a separator
/// @param sep the separating character sequence
/// @param src the string to be split 
/// @return a vector containing every subsequence in the string split on each occurrence of 'sep'
std::vector<std::string> ssplit(std::string sep, std::string src); 

/// @brief reads the input of a file and stores lines into the passed vector
/// @param filename the path to the file 
/// @param ret a vector to store lines in. Will be cleared before storage.
/// @return -1 if there was an error, 0 otherwise. 
int read_input(std::string filename, std::vector<std::string>& ret); 


/// @brief Checks whether the character is an ASCII digit
/// @param c the given character
/// @return true if the character is an ASCII digit, false otherwise
bool isDigit(char c);


/// @brief Attempts to convert the character from an ASCII digit to the digit value 
/// @param c the given character
/// @return the digit value of an ASCII digit, if 'c' was a valid ASCII digit.
char toDigit(char c);



#endif