#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
    int hour;
    int minute;
    int second;
    int total;

}tt;

tt setTime(string str) {
    int previous = 0;
    int current = 0;

    tt t;
    vector<string> v;

    while( (current=str.find(":",previous)) != string::npos) {
        string substring = str.substr(previous,current-previous);
        previous = current+1;
        v.push_back(substring);
    }
    v.push_back(str.substr(previous,current-previous));
    t.hour = stoi(v[0]);
    t.minute = stoi(v[1]);
    t.second = stoi(v[2]);
    t.total = 0;
    t.total += t.hour*60*60 + t.second + t.minute*60;
    
    return t;
}

int compare(tt cur, tt st) {
    if(cur.hour > st.hour){
        return 1;

    }else if(cur.hour < st.hour) {
        return 0;

    }else {
        if(cur.minute > st.minute){
            return 1;
        }else if(cur.minute < st.minute) {
            return 0;
        }else {
            if(cur.second > st.second){
                return 1;
            }else if(cur.second < st.second) {
                return 0;
            }else {
                return 2;
            }
        
        }
    }
    
}


int main(void) {
    string current_time, start_time;
    cin >> current_time >> start_time;
    tt cur = setTime(current_time);
    tt st = setTime(start_time);
    int diff;

    
    diff = st.total - cur.total;
    if(diff <0 )
        diff += 60*60*24;
    int hour = diff / (60*60);
    diff -= hour*3600;

    int minute = diff/60;
    diff -= minute*60;
    int second = diff;
    if(hour<10) {
        cout << "0";
    }
    cout <<hour<<":";
    if(minute<10) {
        cout<<"0";
    }
    cout <<minute<<":";
    if(second<10) {
        cout <<"0";
    }
    cout<<second<<endl;
    
    return 0;
    

    
}