#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    string pre_str;
    string aft_str;
    string str;
    while(1)
    {
        cin >> str;
        if(str == "#")
            break;
        else
        {
            pre_str = str;
            bool ch = true;

            while(1)
            {
                int cnt = 0;
                cin >> str;
                if(str == "#")
                    break;
                aft_str  = pre_str;
                pre_str = str;
                if(aft_str.length() != pre_str.length())
                    ch = false;
                else
                {
                    for(int i=0;i<pre_str.length();i++)
                    {
                        if(pre_str[i] != aft_str[i])
                        {
                            //cout << pre_str[i] << " " << aft_str[i] << endl;
                            cnt++;
                        }
                    }
                    if(cnt != 1)
                        ch = false;
                }
            }
            if(ch == false)
                cout << "Incorrect" << endl;
            else
                cout << "Correct" << endl;
        }
    }
    return 0;
}
