#include <iostream>

using namespace std;

void sol(int floor, int door)
{
    int arr[floor+1][door+1];
    for(int i=0;i<floor+1;i++)
        for(int j=0;j<door+1;j++)
            arr[i][j]=0;
    for(int i=1;i<door+1;i++)
        arr[0][i]=i;

    for(int i=1;i<=floor;i++)
    {
        for(int j=1;j<door+1;j++)
        {
            for(int k=1;k<=j;k++)
                arr[i][j]+=arr[i-1][k];
        }
    }
    cout << arr[floor][door]<<endl;
}

int main(void)
{
    int num, floor, door;


    cin >> num;
    while(num--)
    {
        cin >> floor >> door;
        sol(floor,door);
    }
}


//a층 b호 -> a-1층 1호 ~ b호
