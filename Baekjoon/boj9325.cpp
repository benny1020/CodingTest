#include <iostream>

using namespace std;

int main(void) {
    int n, price;
    int tmp1, tmp2;
    cin >> n;
    int num;
    while(n--) {
        cin >> price;
        cin >> num;
        while(num--) {
            cin >> tmp1 >> tmp2;
            price+=(tmp1*tmp2);
        }
        cout <<  price  << endl;
        
    }
    return 0;
}