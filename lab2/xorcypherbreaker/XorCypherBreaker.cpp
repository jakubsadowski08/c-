
/*#include "XorCypherBreaker.h"
using std::find;
using std::vector;
using std::string;
std::string XorCypherBreaker(const vector<char> &cryptogram,int key_length = 3, const vector<string> &dictionary)
{
    vector<char[3]> key;
    char poss[3];
    int x = 0;
    for (string const &value : dictionary) {
        for (int i = 0; i < 3; i++) {
            for (int j = 95; j < 125; j++) {
                if (value[i] ^ j == cryptogram[x])
                    poss[i] = (char)j;
                x++;
            }
            key.emplace_back(poss);
        }
    }
    for (auto const &value : key)
    {
        printf("%s",value);
    }
}
vector<string> dictionary {"the","of"}; */