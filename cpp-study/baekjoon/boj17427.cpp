#include <iostream>

using namespace std;

int main(void) {
    long long int n;
    cin >> n;
    long long int total=0;
    for(long long int i=1;i<=n;i++){
        total+=i*(n/i);
    }
    cout << total <<endl;
    return 0;

}
