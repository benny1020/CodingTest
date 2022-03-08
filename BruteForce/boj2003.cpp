#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    int num=0;

    cin >> n >> m;

    int arr[n];
    for(int i=0;i<n;i++)  {
        cin >> arr[i];
    }
    
    for(int i=0;i<n;i++) {
        double total = 0;
        for(int j=i;j<n;j++) {
            total += arr[j];
            if(total == m) {
                num++;
                break;
            }
            if(total > m) 
                break;
        }
    }
    cout << num << endl;
    return 0;

} 