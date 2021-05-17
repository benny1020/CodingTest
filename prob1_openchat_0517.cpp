#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> mp;
    string uid;
    string name;
    string com;
    string str;
    for(int i=0;i<record.size();i++)
    {
        istringstream ss(record[i]);
        ss >> com;
        ss >> uid;
        if( !com.compare("Enter") || !com.compare("Change"))
        {
            ss>>name;
            mp[uid] = name;
        }
    }
    for(int i=0;i<record.size();i++)
    {
        istringstream ss(record[i]);
        ss >> com;
        if( !com.compare("Enter") )
        {
            ss >> uid;
            ss >> name;
            str = mp[uid] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        if( !com.compare("Leave") )
        {
            ss >> uid;
            str = mp[uid] + "님이 나가셨습니다.";
            answer.push_back(str);
        }
    }

    return answer;
}

int main(void)
{
    vector<string> str;
    str.push_back("Enter uid1234 Muzi");
    str.push_back("Enter uid4567 Prodo");
    str.push_back("Leave uid1234");
    str.push_back("Enter uid1234 Ryan");

    vector<string> sol = solution(str);

    for(int i=0;i<sol.size();i++)
    {
        cout << sol[i]<<endl;
    }
    return 0;

}
