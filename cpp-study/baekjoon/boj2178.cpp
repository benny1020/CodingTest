#include <iostream>
#include <queue>
#include <string>
using namespace std;

int minn = 99999;

typedef struct {
    int x;
    int y;
    int count;
} pos;

queue<pos> q;

int main(void) {
    int n, m;
    cin >> n >> m;
    string str[n];
    for(int i=0;i<n;i++)
        cin >> str[i];

    for(int i=0;i<n;i++)
        cout<<  str[i]<<endl;
    pos p;
    p.x=0;
    p.y=0;
    p.count =1 ;

    int visit[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            visit[i][j]=0;
    }

    q.push(p);

    while(!q.empty()) {
        pos tmp = q.front();
        //cout << tmp.x << " "  << tmp.y << " " << tmp.count  << endl;
        q.pop();
        
        // 방문 체크
        if(visit[tmp.x][tmp.y] == 1 )
            continue;
        if(tmp.count > minn)
            continue;
        if(tmp.x == n-1 && tmp.y == m-1) {
            if(tmp.count < minn)
                minn = tmp.count;
            continue;
        }
        visit[tmp.x][tmp.y]=1;
        pos ans;
        //보내기
        if(tmp.x + 1 < n && str[tmp.x+1][tmp.y] ==  '1') {
            ans.x = tmp.x+1;
            ans.y = tmp.y;
            ans.count = tmp.count+1;
            q.push(ans);
        }

        if(tmp.x - 1 >= 0 && str[tmp.x-1][tmp.y] ==  '1') {
            ans.x = tmp.x-1;
            ans.y = tmp.y;
            ans.count = tmp.count+1;
            q.push(ans);
        }

        if(tmp.y + 1 < m && str[tmp.x][tmp.y+1] ==  '1') {
            ans.x = tmp.x;
            ans.y = tmp.y+1;
            ans.count = tmp.count+1;
            q.push(ans);
        }

        if(tmp.y - 1 >= 0 && str[tmp.x][tmp.y-1] ==  '1') {
            ans.x = tmp.x;
            ans.y = tmp.y-1;
            ans.count = tmp.count+1;
            q.push(ans);
        }

    }
    cout << minn << endl;

    return 0;
    
}