#include <iostream> 
#include <vector> 
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <string> 

std::vector<std::string> input_lines; 
#define PART1 

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

std::vector<std::string> ssplit(std::string sep, std::string src)
{
    std::vector<std::string> ret; 

    size_t pos = src.find(sep); 

    while (pos != std::string::npos)
    {
        ret.push_back(src.substr(0, pos)); 
        
        src = pos + sep.size() > src.size() ? src : src.substr(pos+sep.size());
        pos = src.find(sep);
    }
    if (!src.empty()) ret.push_back(src);

    return ret; 
}

int main() 
{
    const std::string FILE = "../inputs/day2.txt";
    int result = read_input(FILE);

    if (result != 0) 
    {
        std::cout << "Error grabbing file." << std::endl; 
        return -1; 
    }

    #ifdef PART1

    const unsigned int RED = 12, GREEN = 13, BLUE = 14; 
    unsigned int sum = 0; 

    // triple for loop !? I hate text. 
    std::vector<std::string>::iterator it; 
    for (it = input_lines.begin(); it != input_lines.end(); ++it)
    {
        unsigned int id; char rest[160]; 
        sscanf(it->c_str(), "Game %u: %[^\n]", &id, rest);

        std::vector<std::string> trials = ssplit("; ", rest);
        std::vector<std::string>::iterator jt; 

        int red_max = -1, green_max = -1, blue_max = -1; 

        for (jt = trials.begin(); jt != trials.end(); ++jt)
        {
            std::vector<std::string> ball_info = ssplit(", ", *jt);
            // no more iterators. 
            for (size_t i = 0; i < ball_info.size(); ++i)
            {
                int num; char color[6];

                sscanf(ball_info[i].c_str(), "%d %s", &num, color);

                std::string sColor(color); // wrap for string compare 

                if (sColor == "red")
                {
                    red_max = std::max(red_max, num);
                }
                else if (sColor == "blue")
                {
                    blue_max = std::max(blue_max, num);
                }
                else if (sColor == "green")
                {
                    green_max = std::max(green_max, num);
                }
            }
        }

        // std::cout << red_max << '|' << green_max << '|' << blue_max << std::endl; 
        if (red_max <= RED && green_max <= GREEN && blue_max <= BLUE)
        {
            sum += id; 
        }
    }

    std::cout << sum << std::endl; 

    #endif

    return 0; 
}