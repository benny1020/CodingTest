#include <iostream>

using namespace std;

typedef struct  {
    string name;
    int day;
    int month;
    int year;
} student;

int main(void) {
    int n;
    cin >> n;
    student s_arr[n];
    for(int i=0;i<n;i++) {
        cin >> s_arr[i].name;
        cin >> s_arr[i].day;
        cin >> s_arr[i].month;
        cin >> s_arr[i].year;
    }
    student maxx = s_arr[0];
    student minn = s_arr[0];

    for(int i=1;i<n;i++) {
        if(maxx.year>s_arr[i].year) {
            maxx = s_arr[i];
            continue;
        }
        if(maxx.year<s_arr[i].year)
            continue;
        if(maxx.month>s_arr[i].month) {
            maxx = s_arr[i];
            continue;
        }
        if(maxx.month<s_arr[i].month)
            continue;
        if(maxx.day>s_arr[i].day) {
            maxx = s_arr[i];
            continue;
        }
        if(maxx.day<s_arr[i].day)
            continue;
        //---------
    }
        for(int i=1;i<n;i++) {
            if(minn.year<s_arr[i].year) {
                minn = s_arr[i];
                continue;
            }
            if(minn.year>s_arr[i].year)
                continue;
            if(minn.month<s_arr[i].month) {
                minn = s_arr[i];
                continue;
            }
            if(minn.month>s_arr[i].month)
                continue;
            if(minn.day<s_arr[i].day) {
                minn = s_arr[i];
                continue;
            }
            if(minn.day>s_arr[i].day)
                continue;
        }
    cout << minn.name << endl << maxx.name << endl;
    return  0;
}