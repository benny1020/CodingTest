#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int total = 15;
    int arr[] = {3,2,7,2,4,6,5,1};

    vector<int> s;
    vector<int> e;

    int k =0;
    int t = 4;

    for(int i=0;i<8;i++) {
        int tt =0;
        for(int j=i;j<8;j++) {
            tt +=arr[j];
            if(tt==total)
            {
                s.push_back(i);
                e.push_back(j+1);
                cout << i << j << endl;
            }
            if(tt>total)
                break;
        }


    }
    int minn=9999;
    for(int i=0;i<s.size();i++){
        int p =0;
        p = p+s[i]-k;
        if(e[i]-t < 0)
            p = p + e[i]-t + 8;
        else
            p = p + e[i]-t;

        if(minn > p)
            minn = p;

        cout << p << endl;
        p=0;

        p = p+e[i]-k;
        if(s[i]-t < 0)
            p = p + s[i]-t + 8;
        else
            p = p + s[i]-t;

        if(minn > p)
            minn = p;
        cout << p << endl;

    }
    cout << minn << endl;

}
