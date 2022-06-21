#include <iostream>

using namespace std;

int main(void) {
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    int ans;
    int maxx=0;
    for(int i=0;i<n;i++) {
        int tmp = arr[i][0];
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
            if(tmp>=arr[i][j]) {
                tmp = arr[i][j];
            }
        }
        if(maxx < tmp)
            maxx = tmp;
    }
    cout << maxx << endl;
    return 0;
}