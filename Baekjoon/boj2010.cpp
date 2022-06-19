#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int total =0;    
    int tmp;
    for(int i=0;i<n;i++)   {
        cin  >>  tmp;
        total +=tmp;
    }
    total = total -n+1;
    cout << total<<endl;

    // return
    return 0;
         
}