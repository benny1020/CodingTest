#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    char expression[51];
    cin >> expression;
    int total=0;
    int num=0;
    int digit =0;
    int sum = 0;
    for(int i=strlen(expression)-1;i>=0;i--)
    {
        if(expression[i] == '-')
        {
            sum+=num;
            num=0;
            total-=sum;
            sum=0;
            digit =0;
        }
        else if(expression[i] == '+')
        {
            sum+=num;
            num=0;
            digit =0;
        }
        else
        {
            num += (expression[i]-'0')*pow(10,digit);
            digit++;
        }
    }
    total+=(num+sum);
    cout << total << endl;
    return 0;
}
