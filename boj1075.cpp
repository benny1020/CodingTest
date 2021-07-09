#include <iostream>

using namespace std;

int main(void)
{
    int num, div, rest;

    cin >> num >> div;

    rest = num%100;

    num -=rest;
    for(int i=0;i<div;i++)
    {
        if(num%div == 0)
            break;
        num+=1;
    }

    rest = num%100;
    if(rest <= 9)
        cout << 0 << rest << endl;
    else
        cout << rest<<endl;

    return 0;



}
