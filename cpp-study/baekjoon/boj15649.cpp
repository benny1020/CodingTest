#include <iostream>

using namespace std;

int n,m;
void go(int * arr, int cnt,int cur) {
    if(cnt==m)
    {
        for(int i=0;i<n;i++){
            if(arr[i] == 1)
                cout << i+1 << " ";
        }
        cout << endl;
        return;
    }
    if(cur == n) {
        return;
    }
    arr[cur] = 1;
    go(arr,cnt+1,cur+1);
    arr[cur] = 0;
    go(arr,cnt,cur+1);

}

int main(void) {

    cin >> n >> m;

    int * arr = new int[n];
    for(int i=0;i<n;i++)
        arr[i] = 0;

    go(arr,0,0);

}
