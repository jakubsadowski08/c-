#include"Palindrome.h"
int main()
{
    int choice;
    std::string str;
    std::cout <<"1.Wyjscie" <<std::endl << "2.Sprawdz palindrom"<<std::endl;
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            break;
        case 2:
            std::cout <<"Podaj slowo: ";
            std::cin >>str;
            std::cout<<is_palindrome(str);
        default:
            break;
    }
    exit(0);
}