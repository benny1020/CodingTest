#include <iostream>
using namespace std;

int n,m;
char chArr[50][50];
bool check[50][50];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
bool go(int cur_x, int cur_y, int prev_x ,int prev_y,char color) {
    int nx, ny;
    if(check[cur_x][cur_y])
        return true;
    check[cur_x][cur_y] = true;
    for(int k=0;k<4;k++) {
        nx = cur_x+dx[k];
        ny = cur_y+dy[k];
        if(nx < n && nx >= 0 && ny < m && ny >= 0 && chArr[nx][ny] == color && !(nx == prev_x  && ny == prev_y) ) {
            if(go(nx,ny,cur_x,cur_y,color)){
                cout << go(nx,ny,cur_x,cur_y,color)<<endl;
                return true;
                }
        }   
    }
    return false;
}

int main(void) {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> chArr[n][m];
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(check[i][j] == false) {
                if(go(i,j,-1,-1,chArr[i][j])){
                    cout << "Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout <<  "No" << endl;
    return 0;
}


