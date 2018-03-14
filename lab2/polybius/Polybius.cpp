#include<map>
#include "Polybius.h"
using namespace std;
char index(string cypher)
{
    map <char,string> polybiustable = {{'a',"11"},{'b',"12"},{'c',"13"},{'d',"14"},{'e',"15"},{'f',"21"},{'g',"22"},{'h',"23"},{'i',"24"},{'j',"24"},{'k',"25"},{'l',"31"},{'m',"32"},{'n',"33"},{'o',"34"},{'p',"35"},{'q',"41"},{'r',"42"},{'s',"43"},{'t',"44"},{'u',"45"},{'v',"51"},{'w',"52"},{'x',"53"},{'y',"54"},{'z',"55"},{' ',""}};
    for( auto &i : polybiustable)
    {
        if (i.second ==cypher) {
            return i.first;
        }
    }
}

std::string PolybiusCrypt(std::string message)
{
    if(message.length())
    {
        map <char,string> polybiustable = {{'a',"11"},{'b',"12"},{'c',"13"},{'d',"14"},{'e',"15"},{'f',"21"},{'g',"22"},{'h',"23"},{'i',"24"},{'j',"24"},{'k',"25"},{'l',"31"},{'m',"32"},{'n',"33"},{'o',"34"},{'p',"35"},{'q',"41"},{'r',"42"},{'s',"43"},{'t',"44"},{'u',"45"},{'v',"51"},{'w',"52"},{'x',"53"},{'y',"54"},{'z',"55"},{' ',""}};
        string crypt ="";
        const char * characters = message.c_str();
        for(int i =0;i<message.length();i++)
        {
            crypt = crypt + polybiustable[tolower(characters[i])];
        }
        return crypt;
    }
    else
    {
        return "";
    }
}
std::string PolybiusDecrypt(std::string crypted)
{
    if(crypted.length())
    {
        string decrypt ="";
        for(int i =0;i<crypted.length()/2;i++)
        {
            decrypt = decrypt + index(crypted.substr(2 * i,2));
        }
        return decrypt;
    }
    else
    {
        return "";
    }
}