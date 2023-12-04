#include <iostream> 
#include <vector> 
#include <fstream> 
#include <string> 

std::vector<std::string> input_lines; 

int read_input(std::string filename)
{
    std::ifstream file; 
    file.open(filename);

    if (!file.is_open()) return -1; 

    input_lines.clear(); 
    std::string curr; 
    while (std::getline(file, curr))
    {
        input_lines.push_back(curr); 
    }

    file.close(); 
    return 0; 
}

bool is_digit(const char& c)
{
    return c >= '0' && c <= '9'; 
}

char to_digit(const char& c)
{
    return c - '0'; 
}

int main() 
{
    const std::string FILE = "../inputs/day1.txt";
    int result = read_input(FILE);



    unsigned int sum = 0; 

    std::vector<std::string>::iterator it; 
    for (it = input_lines.begin(); it != input_lines.end(); ++it)
    {
        unsigned int first = 0, last = it->size() - 1; 

        while (!is_digit(it->at(first)) || !is_digit(it->at(last)))
        {
            if (!is_digit(it->at(first)))
            {
                first++; 
            }

            if (!is_digit(it->at(last)))
            {
                last--; 
            }
        }

        // std::cout << it->at(first) << ' ' << it->at(last) << std::endl; 

        int val = (to_digit(it->at(first)) * 10) + (to_digit(it->at(last)));
        // std::cout << val << std::endl; 
        sum += val; 
        
    }

    std::cout << sum << std::endl; 

    return 0; 
}