#include <iostream>

using namespace std;

int main(void) {
    int maxx = 0;
    int n;
    int inp;
    cin >> n;
    int total = 0;
    for(int i=0;i<n;i++) {
        cin >> inp;
        if(inp > maxx)
            maxx = inp;
        total += inp;

    }
    total += maxx*(n-2);
    cout << total << endl;
    return 0;

}