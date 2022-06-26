#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    long long int studentNum[n];
    for(int i=0;i<n;i++)
        cin >> studentNum[i];
    long long int mainNum,subNum;
    cin >> mainNum >> subNum;
    long long int totalNum = 0;
    long long int tmp;

    for(int i=0;i<n;i++) {
        tmp = studentNum[i] - mainNum;
        totalNum++;
        if(tmp<=0)
            continue;
        totalNum += (tmp/subNum);
        if(tmp%subNum >0)
            totalNum++;
    }
    cout << totalNum << endl;

    return 0;

    
}