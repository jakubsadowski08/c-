#include"DoubleBasePalindromes.h"
#include<cmath>
bool is_pal_in_bin(int x)
{
    char rest;
    int bin_size = (int)log2(x) + 1;
    char in_bin[bin_size];
    for(int i = 0;i < bin_size;i++)
    {
        rest = x % 2;
        x = x / 2;
        in_bin[bin_size - 1 - i] = rest;
    }
    for(int i = 0;i < bin_size;i++)
    {
        if(in_bin[i] != in_bin[bin_size - i - 1])
            return false;
    }
    return true;

}
bool is_pal_in_dec(int x)
{
    char rest;
    int bin_size = (int)log10(x) + 1;
    char in_bin[bin_size];
    for(int i = 0;i < bin_size;i++)
    {
        rest = x % 10;
        x = x / 10;
        in_bin[bin_size - 1 - i] = rest;
    }
    for(int i = 0;i < bin_size;i++)
    {
        if(in_bin[i] != in_bin[bin_size - i - 1])
            return false;
    }
    return true;
}
uint64_t DoubleBasePalindromes(int max_value_exculsive)
{
    uint64_t sum = 0;
    for(int i = 0;i<max_value_exculsive;i++)
    {
        if(is_pal_in_bin(i) && is_pal_in_dec(i))
        {
            sum += i;
        }
    }
    return sum;
}
