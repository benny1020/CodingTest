#include <iostream>

using namespace std;

int main(void) {
    int total;
    int book;
    cin >> total;
    for(int i=0;i<9;i++) {
        cin >> book;
        total -= book;
    }
    cout << total << endl;
    return 0;
}
