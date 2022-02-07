/*

정답을 찾은 경우 - 하나만 떨어짐
불가능한 경우 - 둘다 떨어짐 or step==11

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
string a[20];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans= -1;



int go(int step, int x1, int y1, int x2, int y2)
{
    if(step == 11)
        return -1;
    bool fall1,fall2;
    fall1=fall2=false;
    if(x1>=n || x1<0 || y1>=m || y1<0)
        fall1=true;
    if(x2>=n || x2<0 || y2>=m || y2<0)
        fall2=true;

    if(fall1 && fall2) return -1;
    if(fall1 || fall2) return step;

    for(int i=0;i<4;i++)
    {
        int nx1 = x1+dx[i];
        int ny1 = y1+dy[i];
        int nx2 = x2+dx[i];
        int ny2 = y2+dy[i];
        if(0<=nx1 && nx1<n && 0<=ny1 && ny1<m && a[nx1][ny1]=='#') {
            nx1=x1;
            ny1=y1;
        }
        if(0<=nx2 && nx2<n && 0<=ny2 && ny2<m && a[nx2][ny2]=='#') {
            nx2=x2;
            ny2=y2;
        }
        int temp = go(step+1,nx1,ny1,nx2,ny2);
        if(temp != -1) {
            if(ans == -1)
                ans = temp;
            else {
                if(ans>temp)
                    ans=temp;
            }
        }
    }
    return ans;
}

int main(void)
{
    int x1,x2,y1,y2;
    x1=x2=y1=y2=-1;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='o') {
                if(x1==-1) {
                    x1=i;
                    y1=j;
                } else {
                    x2=i;
                    y2=j;
                }
                a[i][j]='.';
            }
        }
    }
    cout <<  go(0,x1,y1,x2,y2) << endl;
    return 0;
}


/*
-1 벽
0 빈칸
1 동전
*/
