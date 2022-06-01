#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int num = 1;
    int total = 0;
    int minn = 10000;
    while(num*num<=10000)
    {
        if(num*num >= n && num*num <= m)  {
            total += num*num;
            if(minn > num*num)
                minn = num*num;
        }
        num++;
    }
    if(total == 0) {
        cout << -1  << endl;
        return 0;
    }
    cout << total << endl << minn << endl;
    return 0;
}