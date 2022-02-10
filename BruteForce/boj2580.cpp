#include <iostream>
#include <vector>
using namespace std;

int a[9][9];

bool check(int row, int col) {
    //가로 확인
    for(int i=0;i<9;i++) {
        if(a[row][i]== a[row][col] && col != i) {
            return false;
        }
    }
    //세로 확인
    for(int i=0;i<9;i++) {
        if(a[i][col] == a[row][col] && row != i) {
            return false;
        }
    }

    int x = (row/3)*3;
    int y = (col/3)*3;
    for(int i=x;i<x+3;i++) {
        for(int j=y;j<y+3;j++) {
            if(a[i][j] == a[row][col] && row!=i && col !=j) {
                return false;
            }
        }
    }
    return true;


}

bool go(int curCount, vector<int> x_arr, vector<int> y_arr) {
    if(curCount == x_arr.size())
        return true;


    for(int i=1;i<=9;i++)
    {
        a[x_arr[curCount]][y_arr[curCount]]=i;
        bool tmp;
        if(check(x_arr[curCount],y_arr[curCount])==true) {
            bool tmp = go(curCount+1,x_arr,y_arr);
            if(tmp==true)
                return true;

        }
        a[x_arr[curCount]][y_arr[curCount]]=0;
    }
    return false;

}


int main(void) {
    vector<int> x_arr;
    vector<int> y_arr;

    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cin >>a[i][j];
            //a[i][j]=0;
            if(a[i][j] == 0){
                x_arr.push_back(i);
                y_arr.push_back(j);
            }
        }
    }


    go(0,x_arr,y_arr);

    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout <<a[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}
