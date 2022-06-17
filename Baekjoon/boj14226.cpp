#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int s;
queue<pair<int,int> > q;
queue<int> c;
int visit[1000] = {0, };
int visit_cp[1000] = {0,};



bool tmp = false;


int main(void) {
    cin >> s;

    q.push(make_pair(1,1));
    c.push(1);
    


    while(1) {
        if(q.empty())
            break;
        pair<int,int> p = q.front();
        int cp = c.front();
        


        q.pop();
        c.pop();
        //cout<<p.first << " " << p.second << " " << cp << endl;

        // 탈출 조건
        if(p.first == s) {
            cout<<p.second << endl;
            return 0;
        }

        if(p.first <= 0 || p.first>1001)
            continue;

        if(visit[p.first] < p.second && visit[p.first] != 0 && visit_cp[p.first] > cp && visit_cp[p.first]!=0) {
            continue;
        }

        if(cp>s*2)
            continue;

        if(visit[p.first]==0)
        {
            visit[p.first]=p.second;
            visit_cp[p.first]=cp;
        }
        if(visit[p.first] > p.second) {
            visit[p.first]=p.second;
            visit_cp[p.first]=cp;
            
        }

        //1. 복사해서 클립보드 저장
        if(s>p.first) {
            q.push(make_pair(p.first,p.second+1));
            c.push(p.first);


        }
        if(cp!=0 && s>p.first) {
            q.push(make_pair(p.first+cp,p.second+1));
            c.push(cp);
        }
        


        //3. 삭제하기
        if(s<p.first) {
            q.push(make_pair(p.first-1,p.second+1));
            c.push(cp);
        }
        
        
    }
    return 0;

}