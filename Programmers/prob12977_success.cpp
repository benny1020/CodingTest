// https://programmers.co.kr/learn/courses/30/lessons/12977
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int num)
{
    for(int i=2;i<=num/2;i++)
    {
        if(num%i == 0 )
            return false;
    }
    return true;
}
max_cnt=0;
void go(int num[], size_t nums_len, int idx, int cnt,int total)
{

    if(cnt == 3)
    {
        if(is_prime(total))
            max_cnt++;
        return;
    }
    if(idx == nums_len)
        return;
    go(num,nums_len,idx+1,cnt+1,total+num[idx]);
    go(num,nums_len,idx+1,cnt,total);

}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = -1;
    go(nums,nums_len,0,0,0);
    answer = max_cnt;
    return answer;
}
