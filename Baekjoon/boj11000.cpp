#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<long long int,long long int> p1, pair<long long int,long long int> p2) {
    if(p1.second == p2.second)
        return p1.first>p2.first;
    return p1.second<p2.second;
}

int main(void) {
    vector< pair<long long int,long long int> > cl;
    int n;
    long long int inp1,inp2;
    int cnt = 0;
    cin >> n;
    while(n--) {
        cin >> inp1 >> inp2;
        cl.push_back(make_pair(inp1,inp2));
    }
    sort(cl.begin(),cl.end(),compare);


    pair<long long int,long long int> last;

    vector<pair<int,int> > arr;
    last = cl[0];
    arr.push_back(cl[0]);
    cnt = 1;
    for(int i=1;i<cl.size();i++) {
        for(int j=0;j<arr.size();j++){
            if(arr[j].second<=cl[i].first) {
                arr[j] = cl[i];
                break;
            }
            if(j==arr.size()-1) {
                arr.push_back(cl[i]);
                break;
            }
        }
    }
    cout << arr.size() << endl;
    return 0;
}