#include <iostream>
#include <queue>


using namespace std;

int main(void) {
    int testCase;
    int n, m, num, x, y;

    cin >> testCase;
    while(testCase--) {

        cin >> n >> m  >> num;
        bool check[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                check[i][j]=false;

        int arr[n][m];

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr[i][j] = 0;
        
        for(int i=0;i<num;i++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }


    }

}
