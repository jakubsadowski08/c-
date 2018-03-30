#include "XorCypherBreaker.h"
#include<map>
using std::find;
using std::vector;
using std::string;
int IsInDic(std::vector<std::string>dictionary,vector<char> a)
{
    int count = 0;
    for (auto const &value : dictionary) {
        if(value.length() < 3)
        {
            continue;
        }
        else
        {
            if((a[0] == value[0]) && (a[1] == value[1]) && (a[2] == value[2]))
            {
                count++;
            }
        }
    }
    return count;
}

string XorCypherBreaker(const vector<char> &cryptogram,int key_length, const vector<string> &dictionary)
{
    char element;
    string bufor;
    std::vector<string> words;
    std::vector<char> chars;
    string key;
    bool f = false;
    int is_in = 0;
    int is_not_in = 0;
    for (int i = 97; i < 123; i++) {
        for (int j = 97; j < 123; j++) {
            for (int k = 97; k < 123; k++) {
                char possible_key [] = {(char)i,(char)j,(char)k};
                unsigned long rozmiar=cryptogram.size();
                for(unsigned long x=0; x<rozmiar; x++)
                {
                    element=(cryptogram[x]^(possible_key[x%3]));
                    chars.push_back(element);
                }
                for(auto value : chars)
                {

                    if (isalpha(value)){
                        bufor += value;

                    } else if(bufor.length()>0)
                    {
                        words.push_back(bufor);
                        bufor = "";
                    } else
                    {
                        continue;
                    }
                }
                for(unsigned long x=0; x<words.size(); x++)
                {
                    if (find(dictionary.begin(),dictionary.end(),words[x]) != dictionary.end())
                    {
                        is_in++;
                    }
                    else
                    {
                        is_not_in++;
                    }
                }
                if(is_in>is_not_in)
                {
                    for(const auto & c : possible_key)
                    {
                        key+=c;
                    }
                    return key;
                }
                is_in = 0;
                is_not_in = 0;
                words.clear();
                chars.clear();
            }
        }
    }
    return nullptr;
}