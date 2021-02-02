#include <string>
#include <iostream>
#include <vector>
using namespace std;
string mostCommonWord(string paragraph, vector<string>& banned) {
    string str;
    for (int i = 0; i < paragraph.size(); ++i)
    {
        if ((paragraph[i] >= 'a' && paragraph[i] <= 'z') || (paragraph[i] >= 'A' && paragraph[i] <= 'Z'))
            str.push_back(tolower(paragraph[i]));
        else
            str.push_back(' ');
    }
    vector<std::string> strings;
    int i = 0;
    while (i < str.size())
    {
        string sub;
        size_t found = str.find(' ', i);
        if (found != string::npos)
            sub = str.substr(i, found - i);
        else
        {
            sub = str.substr(i);
            strings.push_back(sub);
            break ;
        }

        strings.push_back(sub);
        i = found + 1;
        while (str[i] == ' ')
            ++i;
    }
    vector<int> counts(strings.size(), 0);
    for (int i = 0; i < strings.size(); ++i)
    {
        int is_banned = 0;
        for (int j = 0; j < banned.size(); ++j)
        {
            if (strings[i] == banned[j])
            {
                is_banned = 1;
                break ;
            }
        }
        if (is_banned)
            continue ;

        for (int k = i; k < strings.size(); ++k)
        {
            if (strings[i] == strings[k])
            {
                counts[i] += 1;
            }
        }
    }
    int max = 0;
    int idx = 0;
    for (int i = 0; i < counts.size(); ++i)
    {
        if (counts[i] > max)
        {
            max = counts[i];
            idx = i;
        }
    }
    return strings[idx];
}