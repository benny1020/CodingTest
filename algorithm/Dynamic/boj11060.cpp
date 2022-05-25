#include <iostream>

using namespace std;

int MAX_NUM = 10000;
int main(void) {
    int n;
    cin >> n;
    int arr[n];
    int d[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        d[i]=MAX_NUM;
    }
    d[0]=0;
    for(int i=0;i<arr[0];i++) {
        d[i+1] = 1;
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<arr[i];j++)
        {
            if(d[i+j+1]>d[i]+1) {
                d[i+j+1] = d[i]+1;
            }
        }
    }
    if( d[n-1]==MAX_NUM)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << d[n-1]<<endl;
    return 0;

    
    
 }