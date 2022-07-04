#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    int n,m;
    cin >> n >>m;
    int check[m][4];
    for(int i=0;i<m;i++) {
        for(int j=0;j<4;j++)
            check[i][j]=0;
    }
    string str[n];
    for(int i=0;i<n;i++) {
        cin >> str[i];
        for(int j=0;j<m;j++) {
            if(str[i][j] == 'A')
                check[j][0]++;
            else if(str[i][j] == 'C')
                check[j][1]++;
            else if(str[i][j] == 'G')
                check[j][2]++;
            else  
                check[j][3]++;
        }
    }

    char ch_arr[4] = {'A','C','G','T'};
    int hamming_distance = 0;
    for(int i=0;i<m;i++) {
        int max_count = 0;
        char max_ch;
        for(int j=0;j<4;j++) {
            if(max_count < check[i][j]) {
                max_count = check[i][j];
                max_ch = ch_arr[j];
            }

        }
        for(int a=0;a<n;a++) {
            if(str[a][i]!=max_ch)
                hamming_distance++;
        }
        
        cout << max_ch;
        
    }
    cout << endl;
    cout << hamming_distance << endl;
    return 0;

}