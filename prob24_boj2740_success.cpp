#include <iostream>
/*
1 2    -1 -2 0
3 4     0  0 3
5 6

0,0 0,0
1,0 0,1

0,1 1,0
1,1 1,1
0,2

*/
using namespace std;

void solve();
int main(void)
{
    solve();
    return 0;
}
void solve()
{
    int f_n,f_m;
    int s_n,s_m;
    int tmp;

    cin >> f_n >> f_m;



    int f_arr[f_n][f_m];

    for(int i=0;i<f_n;i++)
        for(int j=0;j<f_m;j++)
            cin >> f_arr[i][j];

    cin >> s_n >> s_m;
    int s_arr[s_n][s_m];
    for(int i=0;i<s_n;i++)
        for(int j=0;j<s_m;j++)
            cin >> s_arr[i][j];

    int ans[f_n][s_m];
    for(int i=0;i<f_n;i++)
        for(int j=0;j<s_m;j++)
            ans[i][j]=0;


    for(int k=0;k<f_n;k++)
    {
        for(int j=0;j<f_m;j++)
        {
            for(int t=0;t<s_m;t++)
            {
                ans[k][t]+=(f_arr[k][j]*s_arr[j][t]);
            }
        }
    }





    for(int i=0;i<f_n;i++)
    {
        for(int j=0;j<s_m;j++)
        {
            if( j== s_m-1)
                cout << ans[i][j];
            else
                cout << ans[i][j] <<' ';
        }
        cout << endl;
    }


}
