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
    int x,sum,a = 0;
    char key[4];
    char key_2[3];
    std::map<int,string>suspected;
    vector<char>pos;
    pos.emplace_back('a');
    pos.emplace_back('a');
    pos.emplace_back('a');
    for (int i = 97; i < 123; i++) {
        for (int j = 97; j < 123; j++) {
            for (int k = 97; k < 123; k++) {
                for(int l = 0; l < cryptogram.size() / 3; l = l+3)
                {
                    pos[0] = (char)i ^ cryptogram[l];
                    pos[1] = (char)j ^ cryptogram[l+1];
                    pos[2] = (char)k ^ cryptogram[l+2];
                    x = IsInDic(dictionary,pos);
                    if(x != 0)
                    {
                        sum = sum + x;
                        x = 0;
                    }
                }
                key[0] = (char)i;
                key[1] = (char)j;
                key[2] = (char)k;
                suspected[sum] = (string)key;
                sum = 0;
            }
        }
    }
    for(auto & kv : suspected)
    {
        if(kv.first > a)
            a = kv.first;
    }
    key_2[0] = suspected[a][0];
    key_2[1] = suspected[a][1];
    key_2[2] = suspected[a][2];
    return (string)key_2;
}