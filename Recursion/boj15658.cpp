#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxx = -1000000000;
int minn = 1000000000;

void solve();
void go(vector<int> &v, vector<int> &cal, int index, int cnt, int s, int total);



int main(void)
{
    solve();
}

void solve()
{
    int num;
    cin >> num;
    vector<int> arr(num);
    vector<int> cal;
    for(int i=0;i<num;i++)
        cin >> arr[i];
    maxx = arr[0];
    minn = arr[0];
    int plus, mino, mul,div;
    cin >> plus >> mino >> mul >> div;
    for(int i=0;i<plus;i++)
        cal.push_back(0);
    for(int i=0;i<mino;i++)
        cal.push_back(1);
    for(int i=0;i<mul;i++)
        cal.push_back(2);
    for(int i=0;i<div;i++)
        cal.push_back(3);

    go(arr,cal,0,0,num-1, arr[0]);
    cout << maxx << endl << minn << endl;
}
void go(vector<int> &v, vector<int> &cal, int index, int cnt, int s, int total)
{
    if(cnt == s)
    {
        if( minn > total)
            minn = total;
        if(maxx < total)
            maxx = total;
        return;
    }
    if(index == cal.size())
        return;

    if(cal[index] == 0)
    {
        go(v, cal, index+1, cnt+1, s, total+v[cnt+1]);
    }
    else if (cal[index] == 1)
    {
        go(v, cal, index+1, cnt+1, s, total-v[cnt+1]);

    }
    else if (cal[index] == 2)
    {
        go(v, cal, index+1, cnt+1, s, total*v[cnt+1]);

    }
    else if (cal[index] == 3)
    {
        go(v, cal, index+1, cnt+1, s, total / v[cnt+1]);

    }
    go(v, cal, index+1, cnt, s, total);
}
