#include <iostream>
#include <cstring>
#include <math>
#define MAX_ALPHA 26
using namespace std;

int is_alpha(char ch)
{
    if ( ( (int)ch>=65 &&(int)ch<=90 ) || (int)ch>=97 && (int)ch<=122 )
        return 1;
    else
        return 0;
}
int main(void)
{
    string str1 = "FRANCE";
    string str2 = "french";
    int dp1[MAX_ALPHA][MAX_ALPHA];
    int dp2[MAX_ALPHA][MAX_ALPHA];
    double max = 0;
    double min = 0;
    int tmp_1,tmp_2;
    for(int i=0;i<MAX_ALPHA;i++)
    {
        for(int j=0;j<MAX_ALPHA;j++)
        {
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }
    for(int i=0;i<str1.length()-1;i++ )
    {
        if(  (is_alpha(str1[i]) && is_alpha(str1[i+1]))  ) // 둘다 알파벳이{}
        {
            tmp_1 = (int)str1[i];
            tmp_2 = (int)str1[i+1];
            if(tmp_1 <=90)
                tmp_1+=32;
            if(tmp_2 <=90)
                tmp_2+=32;
            tmp_1 -=97;
            tmp_2 -=97;
            dp1[tmp_1][tmp_2]++;
        }

    }
    for(int i=0;i<str2.length()-1;i++ )
    {
        if(  (is_alpha(str2[i]) && is_alpha(str2[i+1]))  ) // 둘다 알파벳이{}
        {
            tmp_1 = (int)str2[i];
            tmp_2 = (int)str2[i+1];
            if(tmp_1 <=90)
                tmp_1+=32;
            if(tmp_2 <=90)
                tmp_2+=32;
            tmp_1 -=97;
            tmp_2 -=97;
            dp2[tmp_1][tmp_2]++;
        }

    }

    for(int i=0;i<MAX_ALPHA;i++)
        for(int j=0;j<MAX_ALPHA;j++)
        {
            if(dp1[i][j] >= dp2[i][j] )
            {
                max+=dp1[i][j];
                min+=dp2[i][j];
            }
            else
            {
                max+=dp2[i][j];
                min+=dp1[i][j];
            }
        }

    int answer = 0;
    answer = (int)(min*65536/max);
    cout << answer << endl;
    return 0;
}
