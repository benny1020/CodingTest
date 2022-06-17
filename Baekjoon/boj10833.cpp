#include <iostream>

using namespace std;

int main(void) {
    int n;

    cin >> n;

    int total = 0;
    int students;
    int apples;

    while(n--) {
        cin >> students >> apples;
        total += (apples % students);
    }
    cout << total << endl;

    return 0;

}
