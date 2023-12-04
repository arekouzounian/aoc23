#include <iostream> 
#include <vector> 
#include <fstream> 
#include <string> 
#include <map> 
#include <algorithm> 

std::vector<std::string> input_lines; 
#define PART2

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
    #ifdef PART1
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
    #endif 

    #ifdef PART2
    std::vector<std::string> digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
    std::map<std::string, char> conv = {
        {"0", 0},
        {"1", 1}, 
        {"2", 2}, 
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6}, 
        {"7", 7}, 
        {"8", 8}, 
        {"9", 9},
        {"zero", 0},
        {"one", 1}, 
        {"two", 2}, 
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6}, 
        {"seven", 7}, 
        {"eight", 8}, 
        {"nine", 9},
    };
    
    std::vector<std::string>::iterator it; 
    for (it = input_lines.begin(); it != input_lines.end(); ++it)
    {
        int first = it->size(), last = -1; 
        std::string f, l; 

        for (size_t i = 0; i < digits.size(); ++i)
        {
            int top = it->find(digits[i]); 
            int bottom = it->rfind(digits[i]);
            
            if (top != std::string::npos)
            {
                int old = first; 
                first = std::min(first, top);

                if (first != old) f = digits[i];
            }

            if (bottom != std::string::npos)
            {
                int old = last; 
                last = std::max(last, bottom);

                if (last != old) l = digits[i];
            }
        }

        // std::cout << f << ' ' << l << std::endl; 
        sum += (conv[f] * 10) + (conv[l]); 
    }
    

    #endif

    std::cout << sum << std::endl; 

    return 0; 
}