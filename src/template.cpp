#include <iostream> 

#include "util.h"

std::vector<std::string> input_lines; 

int main() 
{
    const std::string FILE = "/path/to/file.txt";
    int result = read_input(FILE, input_lines);

    if (result != 0) 
    {
        std::cout << "Error grabbing file." << std::endl; 
        return result; 
    }

    
    return 0; 
}