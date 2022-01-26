#include <iostream>
#include <vector>

using namespace std;

int go(int * arr, int * check, int index, int x, int y,int n,int m,int sm)
{
    vector<int> v;

    if(check[y][x]==True || index>4)
        return sm;
    check[y][x]=True;

    if(x+1 < m) //x 축으로 1 이동
        v.push_pack(go(arr,check,index+1,x+1,y,sm+arr[y][x]));
    if(x-1>=0) // x 축으로 -1
        v.push_pack(go(arr,check,index+1,x-1,y,sm+arr[y][x]));
    if(y+1 < n)
        v.push_pack(go(arr,check,index+1,x,y+1,sm+arr[y][x]));
    if(y-1 >= 0)
        v.push_pack(go(arr,check,index+1,x,y-1,sm+arr[y][x]));

    auto ans = v[0];
    for(auto p : res) {
        if(p>ans) {
            ans = p;
        }

    }
    return ans;

}


int main(void)
{
    int n,m;
    cin >> n >> m;

    int arr[n][m];
    bool check[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            boo[i][j] = False;
        }
    }
    int maxx = 0;
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) {
        temp = go(arr, check, 1, j, i, n, m,arr[i][j])
        if(temp > maxx)
            maxx= temp;
        }
    }




    return 0;

}
