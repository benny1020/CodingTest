// https://programmers.co.kr/learn/courses/30/lessons/42862
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int arr[n+1];

    for(int i=1;i<=n;i++)
        arr[i]=1;

    for(int j=0;j<lost.size();j++)
        arr[lost[j]] = 0;

    for(int i=0;i<reserve.size();i++)
        arr[reserve[i]]+=1;

    sort(lost.begin(),lost.end());

    for(int i=0;i<lost.size();i++)
    {
        if(lost[i] == 0)
        {
            if(arr[1]==2)
            {
                arr[0] = 1;
                arr[1] = 1;
            }
        }
        else if(lost[i] == n)
        {
            if(arr[n-1]==2)
            {
                arr[n]=1;
                arr[n-1]=1;
            }
        }
        else
        {
            if(arr[lost[i]-1]==2)
            {
                arr[lost[i]-1]=1;
                arr[lost[i]]=1;
            }
            else if(arr[lost[i]+1]==2)
            {
                arr[lost[i]+1]=1;
                arr[lost[i]]=1;
            }
        }
    }
    //return arr[1];
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i] == 1 || arr[i] == 2)
            answer++;
    }

    return answer;
}
