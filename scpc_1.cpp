#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int test_case;
    int num;
    int count;

    cin >> test_case;
    for(int i=0;i<test_case;i++)
    {
        count = 0;
        cin >> num;
        int arr[num];
        int check[num];
        for(int j=0;j<num;j++)
            cin >> arr[j];
        int dp[num];
        for(int j=0;j<num;j++)
        {
            dp[j] = 0;
            check[j] = 0;
        }
        for(int i=0;i<num;i++)
        {
            int k=i;
            if(dp[i] == 1)
                continue;
            dp[i] = 1;
            count++;
            while(arr[k]+k <= num-1)
            {
                if(dp[k] ==1)
                    count--; break;
                dp[k]=1;
                k=arr[k]+k;
            }
        }
        cout << count << endl;
    }
    return 0;
}
