#include <iostream> 
#include <vector> 
#include <set> 
#include <fstream> 
#include <string> 

// #define DEBUG

std::vector<std::string> input_lines; 
std::set<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '-', '+', '`', '~', '/', '?', '=', '(', ')', '[', ']', '{', '}', ';', ':', '<', '>'};

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

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

char toDigit(char c)
{
    return c - '0';
}

bool isSymbol(char c)
{
    return symbols.find(c) != symbols.end(); 
}

bool isSymbolAdjacent(int row, int col)
{
    for (int x = row - 1; x <= row + 1; ++x)
    {
        for (int y = col - 1; y <= col + 1; ++y)
        {
            if ((x >= 0 && x < input_lines.size()) && (y >= 0 && y < input_lines[0].size()))
            {
                if (isSymbol(input_lines[x][y])) 
                    return true; 
            }
        }
    }

    return false; 
}

int main() 
{
    const std::string FILE = "../inputs/day3.txt";
    int result = read_input(FILE);

    if (result != 0) 
    {
        std::cout << "Error grabbing file." << std::endl; 
        return -1; 
    }

    unsigned int sum = 0; 

    bool digitBlock = false; 
    bool symbolAdj = false; 
    unsigned int currNum = 0; 
    for (size_t row = 0; row < input_lines.size(); ++row)
    {
        for (size_t col = 0; col < input_lines[0].size(); ++col)
        {
            char curr = input_lines[row][col];

            if (isDigit(curr))
            {
                if (digitBlock) // continue number block 
                {
                    currNum *= 10; 
                    currNum += toDigit(curr); 
                }
                else // new number block 
                {
                    currNum = toDigit(curr);
                    digitBlock = true; 
                }

                bool isa = isSymbolAdjacent(row, col);
                symbolAdj |= isa; 

                #ifdef DEBUG
                // std::cout << "Digit " << curr << " symbolAdj Status: " << isa << std::endl; 
                #endif 
            }
            else
            {
                // end digit block 
                if (digitBlock)
                {
                    sum += symbolAdj ? currNum : 0; 
                    #ifdef DEBUG
                    if (symbolAdj)
                    {
                        std::cout << "Adding part " << currNum << std::endl; 
                    }
                    #endif 
                    digitBlock = false; 
                    currNum = 0; 
                    symbolAdj = false; 
                }
            }
        }
    }

    std::cout << sum << std::endl; 


    return 0; 
}