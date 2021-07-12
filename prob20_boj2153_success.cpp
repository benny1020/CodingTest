#include <iostream>
#include <cstring>

using namespace std;

void is_prime(int num)
{
    for(int i=2;i<num-1;i++)
    {
        if(num%i==0)//나눠지면
        {
            cout << "It is not a prime word." << endl;
            return;
        }
    }
    cout << "It is a prime word." << endl;
}

int main(void)
{
    string str;
    cin >> str;

    int total = 0;
    for(int i=0;i<str.length();i++)
    {
        if( int(str[i]) <= int('z') && int(str[i]) >= int('a') ) // 소문자인 경우
            total+= (int(str[i])-int('a')+1);
        else
            total+= (int(str[i])-int('A')+1);
    }
    is_prime(total);
    return 0;

}
