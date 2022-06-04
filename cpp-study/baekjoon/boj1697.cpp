#include <iostream>

using namespace std;

int  maxx = 100000;

void go(int n, int k, int count) {
    if(count > maxx)
        return;
    if(n==k)  {
        if(maxx>count) {
            maxx = count;
        }
        return;
    }

    if(n<0) {
        return;
    }
    if(n==0) {
        go(n+1,k,count+1);
    }
    if(n > 0) {
        go(n+1,k,count+1);
        go(2*n,k,count+1);
        go(n-1,k,count+1);
    }

}

int main(void) {
    int n, k;
    cin >> n >>k;
    go(n,k,0);
    cout << maxx << endl;
    return 0;

}
