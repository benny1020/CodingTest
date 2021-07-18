#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lotto;

void solve();
void go();

int main(void)
{
    solve();
    return 0;
}

void go(vector<int> &a, int index, int cnt)
{
    //선택한 경우
    if(cnt == 6)
    {
        for(int i=0;i<6;i++)
            cout << lotto[i] << ' ';
        cout << endl;
        return;
    }
    if(index == a.size())
        return;
    lotto.push_back(a[index]);
    go(a,index+1,cnt+1);
    //선택 안한 경우
    lotto.pop_back();
    go(a,index+1,cnt);
}

void solve()
{
    int num;
    while(1)
    {
        cin >> num;
        if(num == 0)
            return;
        vector<int> arr(num);

        for(int i=0;i<num;i++)
            cin >> arr[i];

        go(arr,0,0);
        cout << endl;
    }

}
