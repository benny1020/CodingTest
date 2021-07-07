#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(void)
{
    int num;
    string str;
    int error;
    int total;
    cin >> num;
    char ch;
    ch='1';

    for(int i=0;i<num;i++)
    {
        total = 0;
        error = 0;
        while(1)
        {
            cin >> ch;
            if(ch == '\n')
            {
                cin >> ch;
                ch = '1';
                break;
            }
            total++;
            if(ch == '#')
                error++;
        }
        ch='1';
        cout.precision(1);
        cout << "Efficiency ratio is "<<(double)error/(double)total << "%."<<endl;
    }


    /*
    for(int i=0;i<num;i++)
    {

    }

    while(str != "\n")
    {
        cin >> str;
        cout << str << endl;
    }
    */

    return 0;

}
