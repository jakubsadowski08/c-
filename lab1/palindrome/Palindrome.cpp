#include<string>
#include"Palindrome.h"
bool is_palindrome(std::string str)
{
    if(str.length() == 0)
    {
        return true;
    }
    const char *characters = str.c_str();
    bool is_palindromes = true;
    for(int i = 0;i<str.length() - 1;i++)
    {
        if(characters[i] != characters[str.length() - 1 - i])
            is_palindromes = false;
    }
    return is_palindromes;
}
