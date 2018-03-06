#include "ReverseString.h"
std::string reverse(std::string str)
{
    if( str.length() == 0 )
        return "";

    std::string last(1,str[str.length()-1]);  // create string with last character
    std::string reversed = reverse(str.substr(0,str.length()-1));
    return last+reversed;
    }