#include <string>
#include <vector>

/*
vector 맨앞에꺼 제거 arr.erase(arr.begin());
vector 맨앞 추가 arr.insert(arr.begin(), 1);
vector 맨뒤 제거 arr.pop_back();
맨뒤 추가 arr.push_back()
*/

using namespace std;
int min_cost = 9999999;

vector<int>arr1;
vector<int>arr2;


void go(vector<int> queue1, vector<int> queue2, int cost,int total1,int total2) {

    if(queue1.size() == 1)
    {
        for(int i=0;i<arr1.size();i++)
        {
            if(arr1[i] == queue1[0])
                return;
        }
        arr1.push_back(queue1[0]);

    }
    if(queue2.size() == 1)
    {
        for(int i=0;i<arr2.size();i++)
        {
            if(arr2[i] == queue2[0])
                return;
        }
        arr2.push_back(queue2[0]);

    }


    if(cost !=0) {
        if (queue1.size() == 0 || queue2.size() == 0)
            return;
    }
    if(cost > min_cost)
        return;
    if(total1==total2) {
        if(min_cost > cost) {
            min_cost = cost;
            return;
        }

        else {
            return;
        }
    }
    int num;

    //1에서 빼서 2에 추가
    if(queue1.size() !=0) {
        num = queue1.front();
        queue1.erase(queue1.begin());
        queue2.push_back(num);
        go(queue1,queue2,cost+1,total1-num.total2+num);

        //원상태로
        queue2.pop_back();
        queue1.insert(queue1.begin(), num);

    }else {
        st1=true;
    }


    if(queue2.size() != 0) {
        //2에서 빼서 1에 추가

        num = queue2.front();
        queue2.erase(queue2.begin());
        queue1.push_back(num);
        go(queue1,queue2,cost+1,total1+num,total2-num);

        //원상태로
        queue1.pop_back();
        queue2.insert(queue2.begin(), num);
    }else {
        st2=true;
    }


}


int solution(vector<int> queue1, vector<int> queue2) {
    int total1=0;
    int total2=0;
    for(int i=0;i<queue1.size();i++)
        total1+=queue1[i];
    for(int j=0;j<queue2.size();j++)
        total2+=queue2[j];

    go(queue1,queue2,0,total1,total2);

    if(min_cost == 9999999)
        return -1;
    return min_cost;
}


int main(void) {
    vector<int> queue1 = {3, 2, 7, 2};
    vector<int> queue2 = {4, 6, 5, 1};

    solution(queue1,queue2);

    printf("%d",min_cost);
    return 0;
}
