#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int arr[13];
    arr[1] = 31;
    arr[2] = 29;
    arr[3] = 31;
    arr[4] = 30;
    arr[5] = 31;
    arr[6] = 30;
    arr[7] = 31;
    arr[8] = 31;
    arr[9] = 30;
    arr[10] = 31;
    arr[11] = 30;
    arr[12] = 31;
    int total = 0;
    for(int i=1;i<a;i++){
        total += arr[i];
    }
    total += b;

    string str[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    //cout  << str[total%7] << endl;
    int ans = total%7-1;
    if(ans == -1)
        ans = 6;

    string answer = str[ans];
    return answer;
}
