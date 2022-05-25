#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_IDX 2000000

using namespace std;
int minn=1;
bool check = false;
int dp[MAX_IDX]={0,};



void solve();
void go(vector<int> &v, int index, int total );

int main(void)
{
    solve();
    return 0;
}

void solve()
{
    int num;
    cin >> num;
    vector<int> arr(num);

    for(int i=0;i<num;i++)
        cin >> arr[i];
    //sort(arr.begin(),arr.end());
    go(arr,0,0);
    for(int i=1;i<=MAX_IDX;i++)
        if(dp[i] == 0)
        {
            cout << i << endl;
            return;
        }

}

void go(vector<int> &v, int index, int total)
{
    //cout << total << endl;
    dp[total]=1;
    if(index == v.size())
        return;

    go(v, index+1, total+v[index]);
    go(v, index+1, total);
}
