#include <iostream>

using namespace std;

int main(void) {
    long long int n;
    int k;
    cin >>k;
    int dp[1000000]={0,};
    dp[1] = 1;
    dp[2] = 3;
    for(int j=0;j<k;j++) {
        cin >> n;
        long long int total=0;
        for(long long int i=1;i<=n;i++){
            total+=i*(n/i);
        }
        cout << total <<endl;
    }

8
1 2 4 8

16
1 2 4 8 16
    return 0;

}
