#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool compare(const pair<int,int>& a, const pair<int,int> &b) {
    //cout <<"a"<<endl;
    //if(a.first == b.first)
    //    return a.second < b.second;
    return a.first < b.first;
}


int main(void) {
    int num;
    int cnt=0;
    int alpha[26];
    cin >> num;
    bool check[10];
    
    vector< pair<int,int> > arr(10);
    for(int i=0;i<10;i++) {
        arr[i].first = 0;
        arr[i].second=0;
    }
    for(int i=0;i<26;i++)
        alpha[i]= -1;
        
    string str[num];
    for(int i=0;i<num;i++)
        cin >> str[i];
    
    int tmp=0;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<str[i].length();j++)
        {
            if(alpha[str[i][j]-'A']== -1)
            {
                alpha[str[i][j]-'A'] = tmp++;
            }
        }
    }
    
    for(int i=0;i<num;i++)
    {
        arr[i].second = 1;
        for(int j=0;j<str[i].length();j++) {
            if(arr[ alpha[str[i][j]-'A']].first==0)
                cnt++;
            arr[alpha[str[i][j]-'A']].first+= pow(10,str[i].length()-1-j);
            
            
        }
    }
    
    sort(&arr[0],&arr[10],compare);
    
    //cout<<"start"<<endl;
    //for(int i=0;i<10;i++)
        // cout << arr[i].first << endl;    
  
    int total=0;
    int k=9;
    for(int i=9;i>=0;i--) {
            if(arr[i].first !=0 )
                total+=int(arr[i].first*k--);
        }
 
    /*
      if(num==10)
    {
        cout << 45 << endl;
        return 0;
    }
    int k=9-cnt+1;
    bool b = false;
    if(cnt == 10)
        k+=1;
    else
        b=true;
    int total=0;

    
    
    for(int i=0;i<10;i++) {
        if(arr[i].first !=0 ) {
            if( b == false) {
                if(i==9)
                    break;
                if(arr[i].second==1) {
                    total+=k*arr[i].first;
                    k++;
                }
                else
                    b=true;
            }
            else {
                total+=k*arr[i].first;
                k++;
            }

        }
    }
*/

    
    cout << total << endl;

    return 0;
    
}