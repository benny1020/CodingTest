#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;


int main(void) {
    int n;
    int inp;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n;i++) {
        cin >> inp;
        v1.push_back(inp);
    }

    for(int i=0;i<n;i++) {
        cin >> inp;
        v2.push_back(inp);
    }
    sort(v1.begin(),v1.end());
    sort(v2.rbegin(),v2.rend());

    int total = 0;
    for(int i=0;i<n;i++) {
        total += v1[i]*v2[i];
    }

    cout  << total  <<endl;
    return 0;






}
