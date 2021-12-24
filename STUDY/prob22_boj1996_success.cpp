/*
처음에 다 0으로 초기화하고
지뢰 주변 싹다 지뢰만큼 더해줌 (유효한 인덱스인지는 is_valid로 판단)
*/

#include <iostream>

using namespace std;

bool is_valid(int num,int i, int j)
{
    if( !(0<=i && i<=num-1) )
        return false;
    if( !(0<=j && j<=num-1) )
        return false;
    return true;
}

int main(void)
{
    int n;
    char ch;
    cin >> n;
    int in[n][n];
    int ans[n][n];


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
            cin >> ch;
            if(ch == '.')
                in[i][j] = 0;
            else
                in[i][j] = int(ch)-48;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(in[i][j]!=0)
            {
                if(is_valid(n,i-1,j))
                    ans[i-1][j]+=in[i][j];
                if(is_valid(n,i-1,j-1))
                    ans[i-1][j-1]+=in[i][j];
                if(is_valid(n,i-1,j+1))
                    ans[i-1][j+1]+=in[i][j];
                if(is_valid(n,i+1,j))
                    ans[i+1][j]+=in[i][j];
                if(is_valid(n,i+1,j-1))
                    ans[i+1][j-1]+=in[i][j];
                if(is_valid(n,i+1,j+1))
                    ans[i+1][j+1]+=in[i][j];
                if(is_valid(n,i,j+1))
                    ans[i][j+1]+=in[i][j];
                if(is_valid(n,i,j-1))
                    ans[i][j-1]+=in[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(in[i][j]!=0)
                cout <<"*";
            else
            {
                if(ans[i][j] >=10)
                    cout <<'M';
                else
                    cout << ans[i][j];
            }

        }
        cout << endl;
    }

}
