#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {

    string str;
    for (int i = 0; i < s.size() ; ++i)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            str.push_back(tolower(s[i]));
    }
    int len = str.size();
    for (int i = 0; i < len / 2; ++i)
    {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;   
