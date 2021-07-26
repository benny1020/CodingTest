#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string str)
{
    int answer = -1;
    bool ch = false;
    vector<char> st;
    for(int i=0;i<str.length();i++)
    {
        st.push_back(str[i]);
        if(st.size()>1)
        {
            while(st[st.size()-1] == st[st.size()-2])
            {
                st.pop_back();
                st.pop_back();
                if(st.size()==0 || st.size()==1)
                    break;
            }
        }
    }
    if(st.size()==0)
        return 1;
    else
        return 0;

    /*
    while(true)
    {
        if(str.length()==0)
            return 1;

        vector<int>idx;
        ch = false;
        for(int i=0;i<str.length()-1;i++)
        {
            if(str[i] ==str[i+1])
            {
                idx.push_back(i);
                i+=1;
                ch = true;
            }
        }
        if(ch == false)
            return 0;
        for(int i=idx.size()-1;i>=0;i--)
        {
            str.erase(idx[i],2);
        }
    }
    */
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
