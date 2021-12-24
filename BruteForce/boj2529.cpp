#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

    int num;
    bool check = false;
    cin >> num;
    char ch[num];
    for(int i=0;i<num;i++)
        cin >>ch[i];
    vector<int> max(num+1);
    vector<int> min(num+1);

    for(int i=0;i<num+1;i++)
    {
        min[i] = i;
        max[i] = 9-i;
    }
    do
    {
        for(int i=0;i<num;i++)
        {
            if(ch[i] == '<')
            {
                if( !(min[i]<min[i+1]) )
                    break;
            }
            else
            {
                if( !(min[i]>min[i+1]) )
                    break;
            }
            if ( i==num-1)
                check = true;
        }
        if( check ==true )
            break;
    }while(next_permutation(min.begin(),min.end()));
    check = false;
    do
    {
        for(int i=0;i<num;i++)
        {
            if(ch[i] == '<')
            {
                if( !(max[i]<max[i+1]) )
                    break;
            }
            else
            {
                if( !(max[i]>max[i+1]) )
                    break;
            }
            if(i == num-1)
                check = true;
        }
        if( check ==true )
            break;
    }while(prev_permutation(max.begin(),max.end()));

    for(int i=0;i<num+1;i++)
        cout << max[i];
    cout << endl;
    for(int i=0;i<num+1;i++)
        cout << min[i];
    cout << endl;

    return 0;
}
