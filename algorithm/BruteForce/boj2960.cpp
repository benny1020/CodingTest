#include <iostream>

using namespace  std;

static int MAX_NUM = 1001;
int main(void) {
    int n, k;
    int total =  0;
    cin >> n >> k;
    bool check[MAX_NUM];
    for(int i=0;i<MAX_NUM;i++)
        check[i] = true;
    check[0]=false;
    check[1]=false;
    for(int i=2;i<MAX_NUM;i++) {
        if(check[i]==false)
            continue;
        int p=1;
        int tmp = i*p;
        while(tmp <=n) {
            if(check[tmp]==true) {
                check[tmp] =  false;
                total++;
            }
            if(total == k) {
                cout << tmp << endl;
                return  0;
            }
            p++;
            tmp = i*p;
        }
    }
    
}