#include <iostream>
#include <cstring>
using namespace std;

int is_valid(int num, int len, int t)
{
    if( num<0 || num>=len)
        return 0;
    return 1;
}

int main(void)
{
    int test_case;
    int len;
    int t;
    cin >> test_case;
    string str_b;
    for(int i=0;i<test_case;i++)
    {
        cin >> len;
        cin >> t;
        int a[len];
        for(int j=0;j<len;j++)
            a[j] = 0;
        cin >> str_b;
    
        for(int j=0;j<len;j++)
        {
            if(str_b[j] == '1')
            {

                if(j>t && j<=len-1-t) // 둘다 만족하는경우
                {
                    if(j+t >=len)
                    {
                        if(j-2*t>=0)
                        {
                            if(str_b[j-2*t] == '1')
                                a[j-t]=1;
                        }
                        else
                            a[j-t]=1;
                    }
                    else
                    {
                        if(a[j-t] == 0)
                        {
                            if(j+2*t<len)
                            {
                                if(str_b[j+2*t]=='1')
                                    a[j+t]=1;
                                else
                                    a[j-t]=1;
                            }
                            else
                                a[j+t]=1;

                        }

                    }

                    continue;
                }
                if(j>t)
                {
                    if(j-2*t >=0)
                    {
                        if(str_b[j-2*t]=='1')
                            a[j-t]=1;
                    }
                    else
                        a[j-t] = 1;
                }
                if(j<=len-1-t)
                {
                    if(j+2*t <len)
                    {
                        if(str_b[j+2*t]=='1')
                            a[j+t]=1;
                    }
                    else
                        a[j+t] = 1;
                }
            }

        }
        for(int k=0;k<len;k++)
            cout << a[k];
        cout << endl;

    }

}
