#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int num, min, t1, t2, temp;
    min = 99999999;
    cin >> num;
    int arr[num][num];
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> person;
    for(int i=0;i<num;i++)
        person.push_back(i);

    do
    {
        for(int i=0;i<num;i++)
        {
            if( !(person[i]==num-i-1) )
                break;
            if(i==num-1)
            {
                cout << min << endl;
                return 0;
            }
        }
        t1=0;
        t2=0;
        for(int i=0;i<num/2;i++)
        {
            for(int j=0;j<num/2;j++)
                t1+=arr[person[i]][person[j]];
        }
        for(int i=num/2;i<num;i++)
        {
            for(int j=num/2;j<num;j++)
                t2+=arr[person[i]][person[j]];
        }
        if(t1>t2)
            temp = t1-t2;
        else
            temp = t2-t1;

        if(min > temp)
            min = temp;

    }while(next_permutation(person.begin(),person.end()));
    cout << min << endl;
    return 0;
}
