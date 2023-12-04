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

int main() 
{
    std::string in; 
    std::cout << "Enter filename: "; 
    std::cin >> in; 
    int result = read_input(in);

    if (result != 0) 
    {
        std::cout << "Error grabbing file." << std::endl; 
        return -1; 
    }

    std::cout << "Success!" << std::endl; 
    return 0; 
}