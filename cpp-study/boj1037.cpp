#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    int num;
    int maxx = 1;
    int minn  = 1000000;
    cin >> n;
    vector<int> v;

    for(int i=0;i<n;i++) {
        cin >> num;
        v.push_back(num);
        if(maxx < num)
            maxx = num;

        if(minn > num)
            minn = num;
    }
    cout << minn*maxx << endl;

    return 0;

}
