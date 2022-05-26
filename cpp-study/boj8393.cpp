#include <iostream>

using namespace std;

int main(void)  {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    cout << n*(n+1)/2<<endl;
    return 0;
}
