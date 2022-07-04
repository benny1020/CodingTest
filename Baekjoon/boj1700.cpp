#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n,k;
    vector<int> mult;
    cin >> n >> k;
    int arr[k+1];
    int num[k+1];
    int ans=0;
    for(int i=0;i<k;i++)
        num[i] = 0;

    for(int i=0;i<k;i++) {
        cin >> arr[i];
        num[arr[i]]++;
    }
    
    for(int i=0;i<k;i++) {

        bool flag = false;
        int minn_count = 999999;
        int minn_index = 0;

        for(int j=0;j<mult.size();j++)
        {
            if(mult[j] == arr[i]) {
                flag = true;
                num[arr[i]]--;
                break;
            }
            
        }
        for(int j=0;j<mult.size();j++) {
            if(minn_count > num[mult[j]]){
                minn_count = num[mult[j]];
                minn_index = j;
            }
        }
        if(flag == true)
            continue;
        

        if(flag == false && mult.size() >=n) {
            mult.erase(mult.begin()+minn_index);
            ans++;
        }

        mult.push_back(arr[i]);
        
    }

    cout << ans << endl;
    return 0;
}