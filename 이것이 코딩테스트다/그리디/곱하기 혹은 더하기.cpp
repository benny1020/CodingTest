#include <iostream>
#include <cstring>
using namespace std;
/*
 * 0이거나 total이 0 인 경우에는 더하고
 * 그 이외의 경우에는 곱하기를 수행함

*/
int main(void) {
    string str;

    cin >> str;

    int total = 0;
    for(int i=0;i<str.length();i++) {
        if(str[i] == '0' || total == 0) {
            total += (int)str[i]-'0';
        }
        else {
            total *= (int)str[i]-'0';
        }
    }
    cout << total << endl;
    return 0;
}
