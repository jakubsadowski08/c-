#include <utility>
#include <string>
#include <array>
#include <memory>
#include<map>
#include<vector>
#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

int find_indice(std::string alphabet, char x)
{
    for(int i = 0;i < alphabet.length();i++)
    {
        if(alphabet[i] == x)
            return i;
    }
}
namespace tinyurl
{
    struct TinyUrlCodec
    {
        std::array<char, 6>hash;
    };
    std::unique_ptr<TinyUrlCodec> Init()
    {
       // auto p = std::make_unique<TinyUrlCodec>(new TinyUrlCodec);
       // return p;
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
        std::hash < std::string> hasz;
        auto hash = (int)hasz(url);
        std::array<char, 6>new_hash;
        for(int i = 0;i < 6;i++)
        {
            auto c = (char)hash / 10;
            hash = hash / 10;
            new_hash[i] = c;
        }
        NextHash(& new_hash);
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        return 0;
    }
}


#endif //JIMP_EXERCISES_TINYURL_H
