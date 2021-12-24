#include <iostream>

using namespace std;

int main(void)
{
    int woman, man, in, team;
    cin >> woman >> man >> in;
    if(woman + man < in)
    {
        cout << 0 << endl;
        return 0;
    }
    if( woman/2 > man)
    {
        woman = woman-man*2;
        team = man;
        man =0;
        while(in>woman+man &&in != 0)
        {
            man+=1;
            woman+=2;
            team--;
        }
        cout << team << endl;

    }
    else
    {
        man -= (woman/2);
        team = woman/2;
        woman %=2;
        while(in>woman+man && in != 0)
        {

            man+=1;
            woman+=2;
            team--;
        }
        cout << team << endl;
    }
    return 0;
}
