#include<fstream>
#include<cstring>
#include"Polybius.h"
using namespace std;
int main(int argc,char * argv[])
{
    char line[256];
    if (argc != 4)
    {
        cerr << "Podaj 3 parametry - nazwe pliku wejsciowego, wyjsciowego i 1 do zaszyfrowania lub 0 do odszyfrowania";
    }
    fstream inputfile(argv[4],ios_base::in |ios_base::out | ios_base::app);
    fstream outputfile(argv[2],ios_base::in |ios_base::out | ios_base::app);
    if(!inputfile || !outputfile)
        cerr << "Nie można otworzyć pliku!" << endl;
    if(strcmp("0",argv[3]) == 0)
    {
        while(!inputfile.eof())
        {
             inputfile.getline(line,256);
             outputfile << PolybiusDecrypt(line);
        }
    }
    else if(strcmp("1",argv[3]) == 0)
    {
        while(!inputfile.eof())
        {
            inputfile.getline(line,256);
            outputfile << PolybiusCrypt(line);
        }
    }
    else
    {
        cerr << "Podaj 0 lub 1";
    }

    inputfile.close();
    outputfile.close();
    return 0;
}
