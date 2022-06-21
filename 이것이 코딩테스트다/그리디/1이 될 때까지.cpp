#include <iostream>

using namespace std;

int main(void) {
    int n,k;
    cin >> n >> k;
    int count=0;
    while(n != 1) {
        if(n%k == 0) {
            n = n/k;
        }else {
            n = n-1;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}