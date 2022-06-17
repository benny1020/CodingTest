#include <iostream>
#include <queue>
#include <stack>
#include <vector>



using namespace std;


queue<int > q;
stack<int> st;


int main(void) {

    vector<int> dfs;
    vector<int> bfs;

    int n, m, v;
    int x,y;
    
    cin >> n >> m >> v;

    bool graph[n+1][n+1];
    bool visit[n+1];

    for(int i=0;i<=n;i++) {
        visit[i] = false;
    }
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++)
            graph[i][j] = false;
    }

    for(int i=0; i<m;i++) {
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }


    st.push(v);

    // dfs
    while(!st.empty()) {
        int tmp = st.top();
        st.pop();

        //cout << tmp<<endl;
        if(visit[tmp]==false)
            dfs.push_back(tmp);

        visit[tmp]=true;
        
        for(int i=n;i>=1;i--) {
            if(visit[i]==false && graph[tmp][i]==true ) {
                st.push(i);
            }
            
        }
    }
    for(int i=0;i<=n;i++) {
        visit[i] = false;
    }
    // bfs
    q.push(v);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        if(visit[tmp] == false)
            bfs.push_back(tmp);

        visit[tmp]=true;
        
        for(int i=1;i<=n;i++) {
            if(visit[i]==false && graph[tmp][i]==true ) {
                q.push(i);
            }
            
        }
    }
    

    for(int i=0;i<dfs.size();i++) {
        cout << dfs[i] << " ";
    }
    cout << endl;
    for(int i=0;i<bfs.size();i++)
        cout << bfs[i] << " ";
    cout << endl;
    return 0;

}