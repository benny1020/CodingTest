#include <iostream>

using namespace std;
int target_x, target_y, red_x, red_y, blue_x, blue_y;
int n,m;
int maxx = -1;
/*
 0 up
 1 down
 2 left
 3 right
*/
void run(char ** arr, int direction) {
    bool red = false;
    bool blue = false;

    // 빨간 구슬 이동
    while(true) {
        if(direction == 0)
        {
            if(red_x-1 >=0 && arr[red_x-1][red_y] != '#' ) {
                red_x--;
                red = true;
                if(red_x == target_x && red_y == target_y)
                    return;
            }
            if(blue_x-1 >=0 && arr[blue_x-1][blue_y] != '#') {
                blue_x--;
                blue = true;
                if(blue_x == target_x && blue_y == target_y)
                    return;
            } else {
                if(blue_x == red_x) {
                    red_x++;
                    red = false;
                }
            }
            if( red == false && blue == false )
                break;
            red=false;
            blue=false;
        }
        if(direction == 1)
        {
            if(red_x+1 <n && arr[red_x+1][red_y] != '#' ) {
                red_x++;
                red = true;
                if(red_x == target_x && red_y == target_y)
                    return;
            }
            if(blue_x+1 <n && arr[blue_x+1][blue_y] != '#') {
                blue_x++;
                blue = true;
                if(blue_x == target_x && blue_y == target_y)
                    return;
            } else {
                if(blue_x == red_x) {
                    red_x--;
                    red = false;
                }
            }
            if( red == false && blue == false )
                break;
            red=false;
            blue=false;
        }
        if(direction == 2)
        {
            if(red_y-1 >=0 && arr[red_x][red_y-1] != '#' ) {
                red_y--;
                red = true;
                if(red_x == target_x && red_y == target_y)
                    return;
            }
            if(blue_y-1 >=0 && arr[blue_x][blue_y-1] != '#') {
                blue_y--;
                blue = true;
                if(blue_x == target_x && blue_y == target_y)
                    return;
            } else {
                if(blue_y == red_y) {
                    red_y++;
                    red = false;
                }
            }
            if( red == false && blue == false )
                break;
            red=false;
            blue=false;
        }
        if(direction == 3)
        {
            if(red_y+1 <m && arr[red_x][red_y+1] != '#' ) {
                red_y++;
                red = true;
                if(red_x == target_x && red_y == target_y)
                    return;
            }
            if(blue_y+1 <m && arr[blue_x][blue_y+1] != '#') {
                blue_y++;
                blue = true;
                if(blue_x == target_x && blue_y == target_y)
                    return;
            } else {
                if(blue_y == red_y) {
                    red_y--;
                    red = false;
                }
            }
            if( red == false && blue == false )
                break;
            red=false;
            blue=false;
        }
    }


}
int check(char ** arr)
{
    if(target_x == red_x && target_y == red_y)
        return 2;
    if(target_x == blue_x && target_y == blue_y)
        return 1;
    else
        return 0;
}
void go(char ** arr, int direction,int cur)
{
    if(cur>10)
        return;
    if(direction == 0) { //x--
        run(arr,0)
        if(check(arr) == 0) {

        }else if(check(arr) == 1) {

        }else {
            if(minn > cur+1) {
                minn=cur+1;
            }
        }
        
        
    }else if(direction == 1) { //x++

    }else if(direction == 2) { //y--

    }else if(direction == 3) { //y++

    }
    
}
/*
 0 up
 1 down
 2 left
 3 right
*/

int main(void) {
    cin >> n >> m;

    char arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'B') {
                blue_x= i;
                blue_y = j;
                arr[i][j]='.';
            } else if(arr[i][j] == 'R') {
                red_x = i;
                red_y = j;
                arr[i][j]='.';
            }else if(arr[i][j] == 'O') {
                target_x = i;
                target_y = j;
                arr[i][j]='.';
            }
        }

    

}