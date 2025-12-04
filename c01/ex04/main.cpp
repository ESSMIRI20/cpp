#include <iostream>
#include <fstream>
#include <string>

void check_and_replace(std::ifstream &file, std::ofstream &file2, std::string line, std::string s1, std::string s2)
{
    while (std::getline(file, line))
    {
        std::string newLine;
        size_t i = 0;

        while (i < line.length())
        {
            if (line.substr(i, s1.length()) == s1)
            {
                newLine += s2;
                i += s1.length();
            }
            else
            {
                newLine += line[i];
                i++;
            }
        }
        file2 << newLine << '\n';
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./program filename s1 s2\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty\n";
        return 1;
    }
    std::ifstream file(filename.c_str());
    std::ofstream file2((filename + ".replace").c_str());
    if (!file.is_open() || !file2.is_open()) {
        std::cerr << "Error: cannot open input file\n";
        return 1;
    }

    std::string line;
    check_and_replace(file, file2, line, s1, s2);
    file.close();
    file2.close();

    return 0;
}
