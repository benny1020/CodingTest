#include <iostream>

using  namespace std;

int main(void) {
    int n, m;
    cin >> n  >> m;
    int minn = m;


    int * arr = new int[m+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=0;i<m;i++) {
        arr[i]=0;
    }
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<=m/2;i++) {
        if(arr[i]==0){
            for(int j=2;j<=m/i;j++){
                arr[j*i]=1;
            }
        }
    }
    int total = 0;
    for(int i=n;i<=m;i++) {
        if(arr[i] == 0) {
            total += i;
            if(minn>i)
                minn = i;
        }
    }
    if(total ==0) {
        cout << -1 << endl;
    } else {
        cout  << total << endl;
        cout << minn << endl;
    }

    return 0;

}
