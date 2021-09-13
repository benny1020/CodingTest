#include <iostream>
using namespace std;

int main(void)
{
    int num;
    cin >> num;
    int tmp;
    int k=0;
    int a1;
    int a2;
    if(num==1)
    {
        cout << 1 <<'/'<<1<<endl;
        return 0;
    }
    while(tmp < num)
    {
        k+=1;
        tmp = k*(k+1)/2;
    }
    k-=1;

    int tmp2 = num-(k*(k+1)/2);
    //cout <<"k:"<<k<< "tmp :"<<tmp2<<endl;
    if((k+1)%2 == 0) //짝수
    {

        a2=k+1;
        a1=1;
        for(int i=0;i<tmp2-1;i++)
        {
            a2-=1;
            a1+=1;
        }
    }
    else //홀수
    {
        a1=k+1;
        a2=1;
        for(int i=0;i<tmp2-1;i++)
        {
            a1-=1;
            a2+=1;
        }
    }
    cout << a1 << '/'<<a2 <<endl;
    return 0;

}
