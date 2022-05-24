#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct room_member {
    int room;
    vector<string> name;
}room_member;

room_member setroom(string str) {
    room_member r;
    r.room = stoi(str.substr(1,str.find(']')-1));
    cout <<  r.room << endl;

    string n = str.substr(str.find(']')+1);
    int s=0;
    for(int i=0;i<n.length();i++) {

        if(n[i] == ',') {
            r.name.push_back(n.substr(s,i-s));
            s=i+1;
        }

    }

    r.name.push_back(n.substr(s,n.length()-s));



    return r;
}

int main(void) {
    string str[3] = {"[403]James", "[40433]Azad,Louis,Andy", "[101]Azad,Guard"};

    for(int i=0;i<3;i++)  {
        room_member m = setroom(str[i]);
    }
    //cout << str[1].find(']');
    //cout << str[1].substr(0,5);
    /*
    string room = str[1].substr(1,str[1].find(']')-1);
    cout << room << endl;

    string name = str[1].substr(str[1].find(']')+1);
    cout << name << endl;

    vector<string> res;

    int s=0;
    for(int i=0;i<name.length();i++) {
        if(name[i] == ',') {
            cout << name.substr(s,i-s) << endl;
            s=i+1;
        }

    }
    cout << name.substr(s,name.length()-s) << endl;
    */

    return 0;
}
