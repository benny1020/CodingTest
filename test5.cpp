#include <string>
#include <vector>

/*
vector 맨앞에꺼 제거 arr.erase(arr.begin());
vector 맨앞 추가 arr.insert(arr.begin(), 1);
vector 맨뒤 제거 arr.pop_back();
맨뒤 추가 arr.push_back()
*/

using namespace std;
lo min_cost = 9999999;

vector<int>arr1;
vector<int>arr2;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> arr;
    int tot = 0;
    for(int i=0;i<queue1.size();i++) {
        arr.push_back(queue1[i]);
        tot +=queue1[i];
    }
    for(int i=0;i<queue2.size();i++) {
        arr.push_back(queue2[i]);
        tot+=queue2[i];
    }

    if(tot%2 == 1)
        return -1;


    tot = tot/2;

    vector<int> s;
    vector<int> e;

    int k = 0;
    int t = queue1.size();

    for(int i=0;i<arr.size();i++) {
        int tt = 0;
        for(int j=i;j<arr.size();j++) {
            tt += arr[j];
            if(tt == tot) {
                s.push_back(i);
                e.push_back(j+1);
            }
            if(tt>tot)
                break;
        }
    }

    int minn = 999999;
    for(int i=0;i<s.size();i++) {
        int p = 0;
        p = p+s[i]-k;
        if(e[i]-t<0)
            p = p+e[i]-t+arr.size();
        else
            p = p + e[i] - t;

        if(minn > p )
            minn = p;

        p = 0;
        p = p+e[i]-k;
        if(s[i]-t < 0)
            p = p + s[i]-t + arr.size();
        else
            p = p + s[i]-t;

        if(minn > p)
            minn = p;
    }
    //return -1;
    return minn;

}


int main(void) {
    vector<int> queue1 = {3, 2, 7, 2};
    vector<int> queue2 = {4, 6, 5, 1};

    printf("%d",solution(queue1,queue2));

    return 0;
}
