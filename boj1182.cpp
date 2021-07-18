#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cnt = 0;


void go(vector<int> &a,int index, int total,int s, bool check);

int main(void)
{
    int num, s;
    cin >> num >> s;
    vector<int> arr(num);
    for(int i=0;i<num;i++)
        cin >> arr[i];
    go(arr,0,0,s,false);
    cout << cnt << endl;
    return 0;
}

void go(vector<int> &a,int index, int total, int s, bool check)
{
    //cout << total << endl;

    if(total == s)
        if(index !=0 && check == true)
        {
            cnt++;
            check = false;
        }
    if(index == a.size())
        return;
    //if(index == a.size())
    //    return;
    //cout << total<<endl;
    //선택하는경우
    go(a,index+1,total+a[index],s,true);
    //선택 안하는 경우
    go(a,index+1, total, s,check);
}
