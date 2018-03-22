#include <utility>
#include <string>
#include <array>
#include <memory>
#include<map>
#include<vector>
#include<iostream>
#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H


namespace tinyurl
{
    struct TinyUrlCodec
    {
        std::array<char, 6>state;
    };
    struct ids
    {

    };
    int find_indice(std::string alphabet, char x)
    {
        for(int i = 0;i < alphabet.length();i++)
        {
            if(alphabet[i] == x)
                return i;
        }
    }
    std::unique_ptr<TinyUrlCodec> Init()
    {
       auto p = std::unique_ptr<TinyUrlCodec>();
       return p;
    }
    void NextHash(std::array<char, 6> *state)
    {
        bool change_next = true;
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(auto r = (*state).rbegin(); r < (*state).rend();r++)
        {
            int x = find_indice(alphabet,*r);
            if(x == 61 && change_next)
            {
                *r = 'a';
                change_next = false;
            }
            else if(x == 25 && change_next)
            {
                *r = alphabet[x + 1];
                change_next = true;
            }
            else if(change_next)
            {
                *r = alphabet[x + 1];
                change_next = false;
            }
        }
    }
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
    {
        std::string tinyurl;
        std::string key = "vga";
        int x = 0;
        for(int i = 0;i < url.length();i++)
        {
            tinyurl.push_back((url[i] ^ key[x % 3]));
            x++;
        }
        return tinyurl;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        int x = 0;
        std::string url;
        std::string key = "vga";
        for(int i =0; i < hash.length();i++)
        {
            url.push_back(hash[i] ^ key[x % 3]);
            x++;
        }
        return url;
    }
}


#endif //JIMP_EXERCISES_TINYURL_H
