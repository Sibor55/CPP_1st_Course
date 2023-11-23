#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

// char to_lower(char c)
// {
//     if (c >= 65 && c <= 91)
//         c += 32;
//     return c;
// }

// std::string string_format(std::string s)
// {
    
//     std::vector<int> delim_index;
//     for (size_t i = 0; i < s.size(); i++)
//     {
//         s[i] = to_lower(s[i]);
//         if ( s[i] > 20 && s[i] <= 40)
//         {
//             delim_index.push_back(i);
//         }
//     }

//     int a = 0;

//     for (size_t i = 0; i < delim_index.size(); i++)
//     {
//         s.erase(delim_index[i-a]);
//         a=+1;
//     }
    
//     return s;
// }


/* template <typename T, class... Args>
void print(const T& x, Args... args) {
    std::cout << x;
    ((std::cout << args), ...);
    std::cout << std::endl;
}

int main()
{
    std::string s = "принадлежащий или относящийся к русскому народу, русскому языку, русской культуре и другому";
    std::string delimiter = " ";
    std::vector<std::string> words;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        words.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    words.push_back(s);

    std::unordered_set<std::string> myset;

    for (std::string i : words)
    {
        myset.insert(i);
    }
    for (std::string i : myset)
    {
        print(i);
    } */
    // std::vector<int> delim_index;
    // for (size_t i = 0; i < s.size(); i++)
    // {
    //     s[i] = to_lower(s[i]);
    //     if ( s[i] > 20 && s[i] <= 40)
    //     {
    //         delim_index.push_back(i);
    //     }
    // }
    
    // // for (size_t i = 0; i < delim_index.size(); i++)
    // // {
    // //     print(delim_index[i]);
    // // }
    
    // int a = 0;

    // for (size_t i = 0; i < delim_index.size(); i++)
    // {
    //     s.erase(delim_index[i-a],1);
    //     a=+1;
    // }
// }
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

// Convert character to lowercase
char to_lower(char c)
{
    if (c >= 65 && c <= 91)
        c += 32;
    return c;
}

// Format string by converting all characters to lowercase and removing specified characters
std::string string_format(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        s[i] = to_lower(s[i]);
    }
    const std::string marks = "—-!.,:'\"?()*;";
    for (char i : marks)
    {
        while (s.find(i) != std::string::npos)
        {
            s.erase(s.find(i), 1);
        }
    }
    return s;
}

// Add each word in a line to the set
void add_line(std::string s, std::unordered_set<std::string>& myset)
{
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        myset.insert(token);
        s.erase(0, pos + delimiter.length());
    }
    myset.insert(s);
}

// Print function to output multiple arguments separated by spaces
template <typename T, class... Args>
void print(const T &x, Args... args)
{
    std::cout << x;
    ((std::cout << ' ' << args), ...);
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> text;
    std::unordered_set<std::string> text_set;
    std::vector<size_t> same_char_arr;
    std::string line;
    std::ifstream in("input.txt");
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            line = string_format(line);
            add_line(line, text_set);
        }
        in.close();
    }
    else
    {
        std::cerr << "File does not exist" << std::endl;
        return -1;
    }
    for (std::string i : text_set)
    {
        print(i);
    }
    return 0;
}