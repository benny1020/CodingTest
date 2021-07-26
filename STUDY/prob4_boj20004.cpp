#include <iostream>

using namespace std;

int is_win(int num)
{

    int temp=30;
    while(1)
    {
        temp-=(num+1);
        if(temp <=0)
        {
            if( num<temp+num+1)
                    return 1;
                else
                    return 0;
        }
    }
}

int main(void)
{
    int num;
    cin >> num;
    for(int i=1;i<=num;i++)
    {
        if(is_win(i))
            cout << i<<endl;
    }
    return 0;
}
