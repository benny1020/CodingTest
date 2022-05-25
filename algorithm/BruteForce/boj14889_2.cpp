#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
int N;

int cal(int ** arr , vector<int>start, vector<int>link)
{
    int start_score = 0;
    int link_score = 0;
    for(int i=0;i<start.size();i++)
    {
        for(int j=0;j<start.size();j++)
        {
            start_score+=arr[start[i]][start[j]];
            link_score+=arr[link[i]][link[j]];
        }
    }
    return abs(start_score-link_score);
}

int main(void) {
    cin >> N;
    vector<int> v;
    for(int i=0;i<N/2;i++)
        v.push_back(1);
    for(int i=0;i<N/2;i++)
        v.push_back(0);

    int ** arr;
    arr = (int **)malloc(sizeof(int *)*N);
    for(int i=0;i<N;i++)
        arr[i] = (int *)malloc(sizeof(int)*N);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            arr[i][j]=0;
        }
    int score;
    int min_score = 999999999;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cin>>arr[i][j];
    }    

       


    do {
        vector<int> start;
        vector<int> link;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == 1)   
                start.push_back(i);
            else 
                link.push_back(i);
        }
        score = cal(arr,start,link);
        if(min_score>score)
            min_score = score;
    }while(prev_permutation(v.begin(),v.end()));

    cout << min_score << endl;
    
}