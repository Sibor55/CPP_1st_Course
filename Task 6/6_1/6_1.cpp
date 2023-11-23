#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>

/*
Дан файл, содержащий русский текст.
Найти в тексте N<=2000 слов,
содержащих наибольшее количество одинаковых букв.
Записать найденные слова в текстовый файл в порядке
невозрастания количества одинаковых букв.
Для каждого слова вывести также это количество.
Все найденные слова должны быть разными!
*/

// В нижний регистр
char to_lower(char c)
{
    if (c >= 65 && c <= 91)
        c += 32;
    return c;
}

// форматируем строку, убираем пунктуацию, применяем to_lower()
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

// добавляем каждое слово в сет
void add_line(std::string s, std::unordered_set<std::string> &myset)
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

// int count(char c, std::string s)
// {
//     int res = 0;
//     for (size_t i = 0; i < s.size(); i++)
//     {
//         if (s[i] == c)
//         {
//             ++res;
//         }

//     }
//     return res;

// }

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
    std::map<std::string, int> hash;
    for (std::string i : text_set)
    {
        
        std::unordered_set<std::string> charset;
        for (size_t j = 0; j < i.size();j+=2)
        {
        
            charset.insert(i.substr(j,2));
        }
        

        int maxcounter = i.size()/2 - charset.size();
        
        // print(i,maxcounter);
        hash[i] = maxcounter;
    }

    for (auto it = hash.begin(); it != hash.end(); it++)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }

    return 0;
}