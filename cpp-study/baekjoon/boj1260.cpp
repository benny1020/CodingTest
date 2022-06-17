#include <iostream>
#include <queue>
#include <stack>

using namespace std;


queue<int > q;
stack<int> st;


int main(void) {
    int n, m, v;
    int x,y;
    
    cin >> n >> m >> v;

    bool graph[n+1][n+1];
    bool check[n+1];
    for(int i=0;i<=n;i++)
        check[i] = false;

    for(int i=0; i<m;i++) {
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }
    st.push(v);
    while(!st.empty()) {
        int tmp = st.top();
        if(check[tmp]==false)
            cout << tmp<<endl;
        check[tmp]=true;
        st.pop();
        for(int i=n;i>=1;i--) {
            if(check[i]==false && graph[tmp][i]==true) {
                st.push(i);
            }
        }
    }
    


    return 0;

}