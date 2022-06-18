#include <iostream>
#include <string>
using namespace std;

#define MAX_NUM 2000001

bool isFelindron(int n) {
    string str = to_string(n);
    for(int i=0;i<str.length()/2;i++){
        if(str[i]!=str[str.length()-1-i])
            return false;
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    bool arr[MAX_NUM];

    for(int i=0;i<MAX_NUM;i++)
        arr[i] = true;

    arr[0] = false;
    arr[1] = false;

    for(int i=2;i<MAX_NUM;i++) {
        if(arr[i] == true) {
            for(int j=2;j<MAX_NUM/i;j++){
                arr[i*j]=false;
            }
        }
    }
    int start = n;
    while(!(isFelindron(start) && arr[start]==true)) {
        start = start+1;
    }
    cout << start << endl;;
    return 0;
}