#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string str ="a,b,c,d";
    vector<string> v;
    
    int previous = 0;
    int current = 0;

    while((current = str.find(",",previous)) != string::npos) {
        string substring = str.substr(previous,current-previous);
        v.push_back(substring);
        previous = current+1;
    }

    if(previous !=0) {
        v.push_back(str.substr(previous, current-previous));
    }
    for(auto a:v) {
        cout << a << endl;
    }
    return 0;
}w