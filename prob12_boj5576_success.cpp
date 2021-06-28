// BOJ 5576

/*
문제
최근 온라인에서의 프로그래밍 콘테스트가 열렸다. W 대학과 K 대학의 컴퓨터 클럽은
이전부터 라이벌 관계에있어,이 콘테스트를 이용하여 양자의 우열을 정하자라는 것이되었다.


이번이 두 대학에서 모두 10 명씩이 콘테스트에 참여했다. 긴 논의 끝에 참가한 10 명 중
득점이 높은 사람에서 3 명의 점수를 합산하여 대학의 득점으로하기로 했다.

W 대학 및 K 대학 참가자의 점수 데이터가 주어진다. 이때, 각각의 대학의 점수를 계산하는
프로그램을 작성하라.

입력
입력은 20 행으로 구성된다. 1 번째 줄부터 10 번째 줄에는 W 대학의 각 참가자의 점수를
나타내는 정수가 11 번째 줄부터 20 번째 줄에는 K 대학의 각 참가자의 점수를 나타내는 정수가
적혀있다. 이 정수는 모두 0 이상 100 이하이다.

출력
W 대학 점수와 K 대학의 점수를 순서대로 공백으로 구분하여 출력하라.


*/


#include <iostream>

using namespace std;

void sort(int * arr, int num)
{
    for(int i=0;i<num-1;i++)
        for(int j=0;j<num-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
}

int main(void)
{
    int num = 10;
    int total_w=0;
    int total_k=0;
    int w_arr[num];
    int k_arr[num];

    int input;
    for(int i=0;i<num;i++)
        cin >> w_arr[i];

    for(int i=0;i<num;i++)
        cin >> k_arr[i];

    sort(w_arr,num);
    sort(k_arr,num);

    total_w = w_arr[num-1]+w_arr[num-2]+w_arr[num-3];
    total_k = k_arr[num-1]+k_arr[num-2]+k_arr[num-3];

    cout << total_w << " " << total_k << endl;

    return 0;
}
