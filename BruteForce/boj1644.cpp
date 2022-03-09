#include <iostream>
#include <vector>
using namespace std;
int MAX_NUM =4000001;
int main(void) {

    int n;
    cin >> n;
    bool * arr = new bool[MAX_NUM];
    vector<int> primeArray;
    bool check=true;
    for(int i=0; i<MAX_NUM;i++)
        arr[i] = true;
    
    arr[0]=false;
    arr[1]=false;

    for(int i=2;i<=n;i++) {
        check = true;
        if(arr[i] == false)
            continue;
        
        int tmp = i;
        if(check == true) {
            int k=2;
            tmp = i*k;
            while(tmp<=n) {
                arr[tmp]=false;
                k++;
                tmp = i*k;
            }
        } else {
            arr[i]=false;
        }
    }
    for(int i=0;i<=n;i++) {
        if(arr[i] == true) {
            primeArray.push_back(i);
        }
    }
    
    int right = 0;
    int left = 0;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int sum=primeArray[0];
    int total = 0;
    while(left<=right && right <= primeArray.size()) {
        if(sum == n) {
            total++;
            sum-=primeArray[left++];
        } else if(sum >n) {
            sum-=primeArray[left++];
        }else {
            sum+=primeArray[++right];
        }
    }
    cout <<total << endl;
    return 0;

    

}