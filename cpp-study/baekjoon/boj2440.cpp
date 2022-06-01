#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int p=0;p<i;p++)
            cout << " ";
        for(int j=0;j<n-i;j++)
            cout <<"*";
        cout << endl;

    }
    return 0;
}
