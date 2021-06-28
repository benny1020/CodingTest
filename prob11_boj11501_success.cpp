//boj11501
/*
문제
홍준이는 요즘 주식에 빠져있다. 그는 미래를 내다보는 눈이 뛰어나, 날 별로 주가를 예상하고 언제나 그게 맞아떨어진다.
매일 그는 아래 세 가지 중 한 행동을 한다.

주식 하나를 산다.
원하는 만큼 가지고 있는 주식을 판다.
아무것도 안한다.
홍준이는 미래를 예상하는 뛰어난 안목을 가졌지만, 어떻게 해야 자신이 최대 이익을 얻을 수 있는지 모른다.
따라서 당신에게 날 별로 주식의 가격을 알려주었을 때, 최대 이익이 얼마나 되는지 계산을 해달라고 부탁했다.

예를 들어 날 수가 3일이고 날 별로 주가가 10, 7, 6일 때, 주가가 계속 감소하므로 최대 이익은 0이 된다.
그러나 만약 날 별로 주가가 3, 5, 9일 때는 처음 두 날에 주식을 하나씩 사고, 마지막날 다 팔아 버리면 이익이 10이 된다.

입력
입력의 첫 줄에는 테스트케이스 수를 나타내는 자연수 T가 주어진다. 각 테스트케이스 별로 첫 줄에는 날의 수를
나타내는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고, 둘째 줄에는 날 별 주가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.
날 별 주가는 10,000이하다.

출력
각 테스트케이스 별로 최대 이익을 나타내는 정수 하나를 출력한다. 답은 부호있는 64bit 정수형으로 표현 가능하다.

*/

#include <iostream>

using namespace std;

void sol(void)
{
    long long int k;
    cin >> k;
    long long int * dp = (long long int *)malloc(sizeof(long long int)*k);
    for(long long int i=0;i<k;i++)
        cin >> dp[i];
    long long int total = 0;

    long long int max = dp[k-1];
    long long int end = k-2;

    for (int i=k-2;i>=0;i--)
    {
        if(dp[i]>max )
        {
            for(int j=i+1;j<=end;j++)
                total +=(max-dp[j]);
            max = dp[i];
            end = i-1;
        }
        if(i==0)
        {
            for(int j=i;j<=end;j++)
                total +=(max-dp[j]);
        }
    }
    cout << total<<endl;

}
/*
떨어질때 파는 전략
void sol(void)
{
    long long int k;
    cin >> k;
    long long int * dp = (long long int *)malloc(sizeof(long long int)*k);
    for(long long int i=0;i<k;i++)
        cin >> dp[i];
    long long int start = 0;
    long long int total = 0;

    for (long long int i=1;i<k;i++)
    {
        if(dp[i-1]>dp[i]) // 작아지는 경우
        {
            for(long long int j=start;j<i-1;j++)
                total += (dp[i-1]-dp[j]);
            start = i;
        }
        else
        {
            if(i==k-1)
            {
                for(long long int j=start;j<i;j++)
                    total += (dp[i]-dp[j]);
                start = i;
            }
        }

    }
    cout << total<< endl;
}
*/

int main(void)
{
    long long int n;
    cin >> n;
    for(long long int i=0;i<n;i++)
        sol();
}
