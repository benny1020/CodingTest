#include <iostream>

using namespace std;

int main(void) {
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    int d[n][m];
    int dx[] = {1,0,1};
    int dy[] = {0,1,1};
    int bx[] = {-1,0,-1};
    int by[] = {0,-1,-1};
    

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
            d[i][j]=0;
        }
    }
    d[0][0] = arr[0][0];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp_x = i+bx[0];
            int tmp_y = j+by[0];
            if(tmp_x >=0 && tmp_x < n && tmp_y >=0 && tmp_y < m) {
                if(d[i][j] < d[tmp_x][tmp_y]+arr[i][j]) {
                    d[i][j] = d[tmp_x][tmp_y]+arr[i][j];
                }
            }
            tmp_x = i+bx[1];
            tmp_y = j+by[1];
            if(tmp_x >=0 && tmp_x < n && tmp_y >=0 && tmp_y < m) {
                if(d[i][j] < d[tmp_x][tmp_y]+arr[i][j]) {
                    d[i][j] = d[tmp_x][tmp_y]+arr[i][j];
                }
            }
            tmp_x = i+bx[2];
            tmp_y = j+by[2];
            if(tmp_x >=0 && tmp_x < n && tmp_y >=0 && tmp_y < m) {
                if(d[i][j] < d[tmp_x][tmp_y]+arr[i][j]) {
                    d[i][j] = d[tmp_x][tmp_y]+arr[i][j];
                }
            }
        }
    }
    cout << d[n-1][m-1] << endl;
    
    return 0;



}