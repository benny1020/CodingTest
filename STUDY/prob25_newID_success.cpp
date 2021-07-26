/* 프로그래머스 제출 답안
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
bool check(char ch)
{
    bool ck = false;
    if( 'a' <= ch && ch <= 'z' )
        ck = true;
    if('A' <= ch && ch <= 'Z')
        ck = true;
    if(ch == '-')
        ck = true;
    if(ch == '_')
        ck = true;
    if(ch == '.')
        ck = true;
    if( '0' <= ch && ch <= '9')
        ck = true;
    //cout << ch << " " << ck << endl;
    return ck;

}
string solution(string str) {

    //1단계 모든 대문자를 소문자로
    for(int i=0;i<str.size();i++)
        if(str[i]<='Z' && str[i] >= 'A')
            str[i] = tolower(str[i]);
    //2단계 소문자, 숫자, 빼기, 밑줄, 마침
    for(int i=0;i<str.size();i++)
    {
        if(!check(str[i]))
        {
            str.erase(i,1);
            i--;
        }
    }
    //3단계 마침표가 2번이상 연속되면 하나로
    bool check=false;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '.')
        {
            if(check == true)
                str.erase(i--,1);
            else
                check = true;
        }
        else
            check = false;
    }
    //4단계 마침표가 처음이나 끝 제거
    if(str[0]=='.')
        str.erase(0,1);
    if(str[str.size()-1]=='.')
        str.erase(str.size()-1,1);
    //5단계 빈 문자열이면 a대입
    if(str.empty())
        str.push_back('a');
    //6단계 문자열이 16자 이상이면 15개 빼고 제거
    if(str.size() >=16)
        str.erase(15,str.size()-15);
    if(str[str.size()-1]=='.')
        str.erase(str.size()-1,1);
    //7단계 2자 이하 마지막문자를 붙임
    if(str.size()<=2)
    {
        if(str.size() == 1)
        {
            char c = str.back();
            str.push_back(c);
            str.push_back(c);
        }
        if(str.size() == 2)
        {
            char c = str.back();
            str.push_back(c);
        }
    }

    return str;
}
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool check(char ch)
{
    bool ck = false;
    if( 'a' <= ch && ch <= 'z' )
        ck = true;
    if('A' <= ch && ch <= 'Z')
        ck = true;
    if(ch == '-')
        ck = true;
    if(ch == '_')
        ck = true;
    if(ch == '.')
        ck = true;
    if( '0' <= ch && ch <= '9')
        ck = true;
    //cout << ch << " " << ck << endl;
    return ck;

}

int main(void)
{
    int min_len = 3;
    int max_len = 15;
    // - _ . 알파벳 소문자
    string str = "...!@BaT#*..y.abcdefghijklm";
    //cin >> str;
    //1단계 모든 대문자를 소문자로
    for(int i=0;i<str.size();i++)
        if(str[i]<='Z' && str[i] >= 'A')
            str[i] = tolower(str[i]);
    //cout << "lv1 : " << str<<endl;
    //2단계 소문자, 숫자, 빼기, 밑줄, 마침
    for(int i=0;i<str.size();i++)
    {
        if(!check(str[i]))
        {
            str.erase(i,1);
            i--;
        }
    }

    //cout <<"lv2 : " <<  str<<endl;

    //3단계 마침표가 2번이상 연속되면 하나로
    bool check=false;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '.')
        {
            if(check == true)
                str.erase(i--,1);
            else
                check = true;
        }
        else
            check = false;
    }
    //4단계 마침표가 처음이나 끝 제거
    if(str[0]=='.')
        str.erase(0,1);
    if(str[str.size()-1]=='.')
        str.erase(str.size()-1,1);
    //5단계 빈 문자열이면 a대입
    if(str.empty())
        str.push_back('a');
    //6단계 문자열이 16자 이상이면 15개 빼고 제거
    if(str.size() >=16)
        str.erase(15,str.size()-15);
    if(str[str.size()-1]=='.')
        str.erase(str.size()-1,1);
    //7단계 2자 이하 마지막문자를 붙임
    if(str.size()<=2)
    {
        if(str.size() == 1)
        {
            char c = str.back();
            str.push_back(c);
            str.push_back(c);
        }
        if(str.size() == 2)
        {
            char c = str.back();
            str.push_back(c);
        }
    }
    //cout << str << endl;
}
