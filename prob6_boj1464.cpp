#include <iostream>
#define MAX_NUM 1000001
using namespace std;

int main(void)
{
    int num;
    int time = 0;
    cin >> num;

    int * arr = new int[MAX_NUM];
    for(int i=0;i<MAX_NUM; i++)
        arr[i]=0;

    for(int i=2;i<MAX_NUM;i++)
    {
        if(i%6 == 0)
        {
            arr[i]=arr[i-1]+1;
            if(arr[i] > arr[i/2]+1)
                arr[i] = arr[i/2]+1;
            if(arr[i] > arr[i/3]+1)
                arr[i] = arr[i/3]+1;
        }
        else if(i%2 == 0)
            if(arr[i-1] < arr[(i/2)])
                arr[i]=arr[i-1]+1;
            else
                arr[i]=arr[i/2]+1;
        else if(i%3 == 0)
            if(arr[i-1] < arr[(i/3)])
                arr[i]=arr[i-1]+1;
            else
                arr[i]=arr[i/3]+1;
        else
            arr[i]=arr[i-1]+1;
    }
    cout << arr[num]<< '\n';
    return 0;
}
