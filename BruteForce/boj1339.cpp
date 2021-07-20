#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int str_to_num(string str, vector<char> v, vector<int> v_arr)
{
    int num=0;
    for(int i=0;i<str.length();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(str[i] == v[j])
            {
                num+= (pow(10,str.length()-i-1)*v_arr[j]);
                break;
            }
        }
    }
    //cout << num<<endl;
    return num;
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int max = 0;
    vector<int>max_idx;
    vector<char>max_ch;
    int max_len = 0;
    int total=0;
    vector<char> v;
    int num;
    bool check;
    cin >> num;
    string str_arr[num];
    for(int i=0;i<num;i++)
    {
        cin >> str_arr[i];
        if(max_len<str_arr[i].length())
        {
            max_len = str_arr[i].length();
        }
        //cout << str_arr[i]<<endl;
    }
    for(int k=0;k<num;k++)
    {
        check = true;
        if(str_arr[k].length() == max_len)
        {
            for(int i=0;i<max_ch.size();i++)
            {
                if(max_ch[i] == str_arr[k][0])
                    {
                        check=false;
                        break;
                    }
            }
            if(check == true)
                max_ch.push_back(str_arr[k][0]);
        }
    }



    for(int i=0;i<num;i++)
    {
        for(int j=0;j<str_arr[i].length();j++)
        {
            check=true;
            for(int k=0;k<v.size();k++)
            {
                if(v[k] == str_arr[i][j])
                {

                    check=false;
                    break;
                }
            }
            if(check == true) // 사전에 없으면
            {
                v.push_back(str_arr[i][j]);
                if(v[v.size()-1] == max_ch[max_idx.size()])
                    max_idx.push_back(v.size()-1);
            }
        }
    }
    vector<int> v_arr(v.size());
    for(int i=0;i<v.size();i++)
        v_arr[i]=9-i;

    do
    {
        check = true;
        for(int i=0;i<max_idx.size();i++)
        {
            if(v_arr[max_idx[i]] == 9)
            {
                check = false;
                break;
            }
        }


        if(check == true)
            continue;
        total=0;
        for(int i=0;i<num;i++)
        {
            total+=str_to_num(str_arr[i], v, v_arr);
        }
        if(max < total)
            max = total;

        if(max_idx.size() == 10)
        {
            cout << max << endl;
            return 0;
        }

    }while(prev_permutation(v_arr.begin(),v_arr.end()));
    cout << max << endl;
    return 0;

}
