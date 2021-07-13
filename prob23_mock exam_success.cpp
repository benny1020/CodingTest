
/*
그냥 순서 다 써주고
하나하나 비교함
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one_ans=0;
    int two_ans=0;
    int thr_ans=0;

    int one[] ={1,2,3,4,5};
    int two[] ={2,1,2,3,2,4,2,5};
    int three[] ={3,3,1,1,2,2,4,4,5,5};
    int max = 0;
    for(int i=0;i<answers.size();i++)
    {
        //one 계산
        if( one[i%5] == answers[i])
            one_ans++;
        if( two[i%8] == answers[i])
            two_ans++;
        if( three[i%10] == answers[i])
            thr_ans++;
    }
    if(max < one_ans)
        max = one_ans;
    if(max < two_ans)
        max = two_ans;
    if(max < thr_ans)
        max = thr_ans;
    if(max == one_ans)
        answer.push_back(1);
    if(max == two_ans)
        answer.push_back(2);
    if(max == thr_ans)
        answer.push_back(3);

    return answer;
}
