#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<pair<int,int> > a;
    for(int i=1;i<=9;i++) {
        for(int j=i+1;j<=9;j++) {
            pair<int,int> tmp(i,j);
            a.push_back(tmp);
        }
    }

    cout << a.size() << endl;
    return 0;
}
