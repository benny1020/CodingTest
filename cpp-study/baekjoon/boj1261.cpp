#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int minn =999999;

typedef struct point {
    int x;
    int y;
    int count;
} point;

queue<point> q;
int main(void) {
    int n, m;

    cin >> n >> m;
    string arr[m];
    int visit[n][m];
    for(int i=0;i<m;i++) {
        cin >> arr[i];
    
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visit[i][j]=0;
        }
    }
    point t;
    t.x=0;
    t.y=0;
    t.count=0;
    q.push(t);
    while(!q.empty()) {
        point p = q.front();
        q.pop();
        
        if(p.x<0 || p.x>n-1 || p.y < 0 || p.y > m-1 )
            continue;

        
        if(arr[p.x][p.y]=='1')
            p.count++;
        if(p.x==n-1 && p.y == m-1){
            if(minn > p.count)
                minn = p.count;
        }

        if(visit[p.x][p.y] != 0 && visit[p.x][p.y] <= p.count) {
            //cout << p.x << " "<<p.y << " "<<p.count << endl;
            continue;
        }
        if(minn <= p.count)
            continue;
        //cout << p.x << " "<<p.y << " "<<p.count << endl;


            
        if(p.count == 0)
            visit[p.x][p.y]=1;
        else 
            visit[p.x][p.y] = p.count;

        point tmp;
        tmp.count = p.count;
        tmp.x = p.x+1;
        tmp.y = p.y;
        q.push(tmp);
        tmp.x = p.x-1;
        tmp.y = p.y;
        q.push(tmp);
        tmp.x = p.x;
        tmp.y = p.y+1;
        q.push(tmp);
        tmp.x = p.x;
        tmp.y = p.y-1;
        q.push(tmp);
    }
    cout << minn << endl;
}