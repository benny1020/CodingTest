#include <iostream>

using namespace std;


int main(void)  {
    int l,p,v;
    int tmp;
    int ans;
    int round = 1;
    cin >> l >> p >> v;
    while(l != 0 && p != 0 && v != 0) {
        ans = 0;
        tmp = v/p;
        //cout << tmp << endl;
        ans += tmp*l;
        tmp = v%p;
        
        if(l<tmp)
            ans += l;
        else 
            ans += tmp;
        printf("Case %d: %d\n",round,ans);
        round++;
        cin >> l >> p >> v;
    }
    return 0;
}