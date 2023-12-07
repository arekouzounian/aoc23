#include "util.h"

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

int read_input(std::string filename, std::vector<std::string>& ret)
{
    std::ifstream file; 
    file.open(filename);

    if (!file.is_open()) return -1; 

    ret.clear(); 
    std::string curr; 
    while (std::getline(file, curr))
    {
        ret.push_back(curr); 
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