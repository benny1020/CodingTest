#include <iostream>

using namespace std;

int main(void) {
    int left=0, right = 0;
    int minLen = 100001;
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int sum=arr[0];
    while(left <=right && right < n) {
        if(sum < m) {
            sum+=arr[++right];
        }else if (sum == m) {
            if(minLen > right-left+1)
                minLen = right-left+1;
            sum+=arr[++right];
            
        }
        else { // m <=sum
            if(minLen > right-left+1)
                minLen = right-left+1;
            sum-=arr[left++];   
        } 
        
    }
    if(minLen == 100001)
        cout << 0 << endl;
    else
        cout << minLen << endl;

    return 0;
    

}


/*
int main(void) {
    int n, m;
    int minLen = 100001;
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++) 
        cin >> arr[i];
    
    int d[n];

    d[n-1]=arr[n-1];

    for(int i=n-2;i>=0;i--) {
        d[i]=d[i+1]+arr[i];
    }
    for(int i=0;i<n;i++) {
        int total = 0;
        int len = 0;
        for(int j=i;j<n;j++) {
            total+=arr[j];
            len++;
            if(len > minLen)
                break;
            if(total>=m) {
                if(minLen > len)
                    minLen = len;
                break;
            }
            
        }
     }
    if(minLen == 100001)
        cout << 0 <<endl;
    else
        cout << minLen << endl;
    
}

*/