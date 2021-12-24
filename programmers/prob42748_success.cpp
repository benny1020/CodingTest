// https://programmers.co.kr/learn/courses/30/lessons/42748
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;


    for(int i=0;i<commands.size();i++)
    {
        vector<int> temp;
        for(int j=0;j<array.size();j++)
            temp.push_back(array[j]);
        vector<int> tmp2;
        for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++)
            tmp2.push_back(temp[j]);
        sort(tmp2.begin(),tmp2.end());
        answer.push_back(tmp2[commands[i][2]-1]);


    }
    return answer;
}
