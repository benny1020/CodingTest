#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// first : location, second : count
queue<pair<int,int> > q;

queue<vector<int> > v;

int visit[100001]={0,};

int n,k;
int minn=100001;

vector<int> minn_v;

int main(void) {
    cin >> n >> k;
    if(k<n) {
        cout << n-k <<endl;
        for(int i=n;i>=k;i--)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    q.push(make_pair(n,0));
    vector<int> tmp;
    tmp.push_back(n);
    v.push(tmp);
    while(1) {
        if(q.empty())
            break;
        pair<int,int> p = q.front();
        q.pop();
        tmp = v.front();
        v.pop();

        if(p.first<0 || p.first > 100001 || p.second >= minn)
            continue;
        if(p.first>=0 && p.first <100001) {
            if(visit[p.first]==1)
                continue;
        }
            
        if(minn > p.second && p.first == k) {
            minn = p.second;
            minn_v = tmp;
        }
            

        visit[p.first]=1;

        vector<int> t = tmp;
        q.push(make_pair(p.first+1,p.second+1));
        t.push_back(p.first+1);
        v.push(t);

        t = tmp;
        q.push(make_pair(p.first*2,p.second+1));
        t.push_back(p.first*2);
        v.push(t);

        t = tmp;
        q.push(make_pair(p.first-1,p.second+1));
        t.push_back(p.first-1);
        v.push(t);


            
    }
    cout << minn << endl;
    for(int i=0;i<minn_v.size();i++)
        cout << minn_v[i] << " ";
    cout << endl;
    return 0;
}