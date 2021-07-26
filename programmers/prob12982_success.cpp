// https://programmers.co.kr/learn/courses/30/lessons/12982
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
int max_cnt = 0;
void go(vector<int> &d, int idx, int total,int cnt)
{
    if(d.size()-idx < max_cnt-cnt)
        return;

    if(total<0)
        return;
    if(total >=0)
        if(max_cnt < cnt)
            max_cnt = cnt;
    if(idx >= d.size())
        return;

    go(d,idx+1,total-d[idx],cnt+1);
    go(d,idx+1,total,cnt);
}
*/
int solution(vector<int> d, int budget) {
    int answer = 0;
    /*
    go(d,0,budget,0);
    answer = max_cnt;
    */
    sort(d.begin(),d.end());
    for(int i=0;i<d.size();i++)
    {
        if(budget >= d[i])
        {
            budget -= d[i];
            answer++;
        }
        else
            break;

    }
    return answer;
}
