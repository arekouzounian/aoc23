#include <iostream> 
#include <set> 

#include "util.h"

std::vector<std::string> input_lines; 

int main() 
{
    const std::string FILE = "../inputs/day4.txt";
    int result = read_input(FILE, input_lines);

    if (result != 0) 
    {
        std::cout << "Error grabbing file." << std::endl; 
        return result; 
    }

    unsigned int sum = 0; 

    std::vector<std::string>::iterator it; 
    for (it = input_lines.begin(); it != input_lines.end(); ++it)
    {
        *it = it->substr(it->find(": ") + 2); // skip past the game label 

        // left half will be winning numbers, right half will be scratched nums
        std::vector<std::string> partition = ssplit(" | ", *it); 

        std::vector<std::string> winning_vec = ssplit(" ", partition[0]); 
        std::vector<std::string> scratched_vec = ssplit(" ", partition[1]);

        std::set<int> winning_nums;
        for (int i = 0; i < winning_vec.size(); ++i)
        {
            if (!isDigit(winning_vec[i][0])) continue; 
            winning_nums.insert(std::stoi(winning_vec[i]));
        }
        

        int curr = 0; 
        for (int i = 0; i < scratched_vec.size(); ++i)
        {
            // std::cout << scratched_vec[i] << std::endl; 
            if (!isDigit(scratched_vec[i][0])) continue; 

            int conv = std::stoi(scratched_vec[i]); 
            if (winning_nums.find(conv) != winning_nums.end())
            {
                curr <<= 1; 
                curr = curr == 0 ? 1 : curr; 
            }
        }

        sum += curr; 
    
    }

    std::cout << sum << std::endl; 
    
    return 0; 
}