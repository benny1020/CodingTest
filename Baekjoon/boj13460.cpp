#include <iostream>
#include <cstring>

using namespace std;
int max_num = -1;
int n,m;
void go(char ** arr, int cur, int red_x, int red_y, int blue_x, int blue_y, int target_x, int target_y)
{
    bool red=false;
    bool blue=false;
    if(cur == 11) {
        return;
    }
    if(red_x == target_x && red_y == target_y)
    {
        if(max_num < cur)
            max_num = cur;
    }

    // up
    if(arr[red_x+1][red_y] != '#'&& red_x+1<n)
        red = true;
    if(arr[blue_x+1][blue_y] != '#'&& blue_x+1<n)
        blue = true;
    int tmpRedX = red_x;
    int tmpRedY = red_y;
    int tmpBlueX = blue_x;
    int tmpBlueY = blue_y;
    if(red == true)
        tmpRedX++;
    if(blue == true)
        tmpBlueX++;
    go(arr,cur+1,tmpRedX,tmpRedY,tmpBlueX,tmpBlueY,target_x,target_y);
    
    red = false;
    blue = false;
    // down

    //


}

int main(void) {
    int red_x, red_y;
    int blue_x, blue_y;
    int target_x, target_y;
    cin >> n >> m;
    char arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'B') {
                blue_x = i;
                blue_y = j;
            }
            if(arr[i][j] == 'R') {
                red_x = i;
                red_y = j;
            }
            if(arr[i][j] == 'O') {
                target_x = i;
                target_y = j;
            }
        }
            
    }

}