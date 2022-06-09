#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int  maxx = 100001;
long long int n,k;
queue<pair<long long int,int> > q;
//queue<int> r;
#define MAXNUM 1000000

int visit[MAXNUM] = {0,};

int main(void) {
    cin >> n >>k;
    //cout << maxx << endl;
    q.push(make_pair(n,0));
    //r.push(100);
    
    while(1) {
        //cout << "a"<<endl;
        if(q.empty())
            break;
        pair<long long int,int> p = q.front();
        q.pop();
        
        //int tmp = r.back();
        //cout << p.first << " " << p.second << endl;
        //q.pop();
        if(p.first >= 100001)
            continue;
        if(p.first < 0)
            continue;
        if(p.second >= maxx)
            continue;
        if(p.second < maxx && p.first == k)
            maxx = p.second;

        if(p.first <MAXNUM ) {   
            if(visit[p.first] == 1)
                continue;
            visit[p.first]=1;
        }


        
        //cout << state2 << " " << state1 << endl;

        if(p.second < maxx) {
            q.push(make_pair(p.first*2,p.second+1));

                
            q.push(make_pair(p.first+1,p.second+1));
            q.push(make_pair(p.first-1,p.second+1));
            //cout << q.size() << endl;
        }
        
    }
    cout << maxx << endl;

    return 0;

}
