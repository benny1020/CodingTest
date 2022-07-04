#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 우선순위 큐 이용해서 다시해보기

/*

bool compare(pair<long long int,long long int> p1, pair<long long int,long long int> p2) {
    if(p1.first == p2.first)
        return p1.second>p2.second;
    return p1.first<p2.first;
}
bool compare2(pair<long long int, long long int> p1, pair<long long int, long long int> p2 ) {
    return p1.second > p2.second;
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

    //for(int i=0;i<cl.size();i++)
    //    cout << cl[i].first << " " << cl[i].second << endl;

    pair<long long int,long long int> last;

    vector<pair<int,int> > arr;
    last = cl[0];
    arr.push_back(cl[0]);
    cnt = 1;
    for(int i=1;i<cl.size();i++) {
        if(arr[0].second<=cl[i].first) {
            arr[0] = cl[i];
            break;
        }else {
            arr.push_back(cl[i]);
            sort(arr.begin(),arr.end(),compare2);
        }
    }
    cout << arr.size() << endl;
    return 0;
}

*/