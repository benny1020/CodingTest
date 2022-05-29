#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long long int n;
    long long int total = 1;
    long long int num = 1;
    int count = 0;

    while(cin >> n) {
        num = 1;
        count = 1;
        while(num % n != 0) {
            //num += pow(10,count++);
            //num %= n;
            num = (num*10) +1;
            num = num%n;
            //num %= n;
            count++;
            //cout << num << endl;

        }
        cout << count << endl;
    }
    return 0;


}
