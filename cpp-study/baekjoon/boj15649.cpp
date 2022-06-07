#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr(9);
bool visited[9]={0,};
void go(int cnt) {
    if(cnt == m) {
        for(int i=0;i<m;i++)
            cout << arr[i] << " ";
        cout << '\n';
    }

    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            visited[i]=true;
            arr[cnt]=i;
            go(cnt+1);
            visited[i]=false;
        }

    }



}
int main(void) {
    cin >> n >> m;
    go(0);
    return 0;
}
