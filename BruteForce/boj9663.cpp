#include <iostream>
#include <vector>

using namespace std;
int ans=0;
bool a[15][15];
int n;



bool check(int row, int col) {
    //세로로 없는지

    for(int i=0;i<row;i++){
        if(a[i][col]==true)
            return false;
    }
    //왼쪽 대각선
    int x=row-1;
    int y=col-1;
    while(x>=0 && y>=0) {
        if(a[x][y] == true)
            return false;
        x--; y--;
    }

    //오른쪽 대각선
    x=row-1;
    y=col+1;
    while(x>=0 && y<n) {
        if(a[x][y] == true)
            return false;
        x--; y++;
    }
    

    return true;
}

void calc(int row) {
    if(row == n) {
        ans+=1;
    }
    for(int col=0;col<n;col++) {
        a[row][col]=true;
        if(check(row,col)==true) {
            calc(row+1);
        }
        a[row][col]=false;
     }
}


int main(void)
{
    for(int i=0;i<15;i++) {
        for(int j=0;j<15;j++) {
            a[i][j]=false;
        }
    }
    cin >> n;
    calc(0);
    cout << ans << endl;

    return 0;
}
