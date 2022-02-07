#include <iostream>
#include <vector>

using namespace std;

int go(int score,int n, vector<int>arr)
{
    if(n==2)
        return score;
    int ans = -1;

    for(int i=1;i<n-1;i++)
    {
        vector<int>temp_arr = arr;
        temp_arr.erase(temp_arr.begin()+i);
        int temp = go(score+(arr[i-1]*arr[i+1]),n-1,temp_arr);
        if(ans<temp)
            ans = temp;
    }
    return ans;
}

int main(void) {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << go(0,n,arr) << endl;
    return 0;

}
