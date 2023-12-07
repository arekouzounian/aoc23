#include <iostream> 
#include <vector> 
#include <set> 
#include <fstream> 
#include <string> 

// #define DEBUG

std::vector<std::string> input_lines; 
std::set<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '-', '+', '`', '~', '/', '?', '=', '(', ')', '[', ']', '{', '}', ';', ':', '<', '>'};

const char GEAR = '*'; 

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

// search left and right on index 
int getNumber(int row, int col)
{
    std::string num_string = ""; 

    char curr = input_lines[row][col]; 

    int currCol = col; 

    // go left 
    while (isDigit(curr) && currCol >= 0)
    {
        num_string.push_back(curr); 

        curr = input_lines[row][--currCol]; 
    }

    // reverse 
    num_string = std::string(num_string.rbegin(), num_string.rend()); 

    currCol = col + 1; 
    curr = input_lines[row][currCol]; 

    // go right 
    while (isDigit(curr) && currCol < input_lines.size())
    {
        num_string.push_back(curr); 

        curr = input_lines[row][++currCol];
    }

    return std::stoi(num_string);
}

std::set<int> getAdjNums(int row, int col)
{
    std::set<int> ret;  

    for (int x = row - 1; x <= row + 1; ++x)
    {
        for (int y = col - 1; y <= col + 1; ++y)
        {
            if ((x >= 0 && x < input_lines.size()) && (y >= 0 && y < input_lines[0].size()))
            {
                if (isDigit(input_lines[x][y]))
                {
                    ret.insert(getNumber(x, y)); 
                }
            }
        }
    }

    return ret; 
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

            if (curr == GEAR)
            {
                std::set<int> adjNumbers = getAdjNums(row, col);
                if (adjNumbers.size() == 2)
                {
                    // this is fucked 
                    sum += *(adjNumbers.begin()) * *(++(adjNumbers.begin())); 
                }
            }
        }
    }

    std::cout << sum << std::endl; 


    return 0; 
}