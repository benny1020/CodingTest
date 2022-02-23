#include <iostream>
#include <vector>

using namespace std;

int max_total = 0;


bool check(string s, bool * arr)
{
    for(int i=0;i<s.length();i++)
    {
        if(arr[s[i]-'a']==false)
            return false;
    }
    return true;
}
void go(string * str,int n, int k, int cur, bool * arr)
{
    if(cur == 26 && k !=0)
        return;
    if(k==0)
    {
        int total = 0;
        for(int i=0;i<n;i++)
        {
            if(check(str[i],arr) == true)
                total++;
        }
        if(max_total < total)
            max_total = total;
        return;
    }
    else {
        if(cur=='a'-'a' || cur == 'n'-'a' || cur == 't'-'a' || cur == 'i'-'a' || cur == 'c'-'a' )
            go(str,n,k,cur+1,arr);
        else {
            arr[cur]=true;
            go(str,n,k-1,cur+1,arr);
            arr[cur]=false;
            go(str,n,k,cur+1,arr);
        }
        
    }
    
}

void run(string * str,int n, int k, int cur, bool * arr)
{
    if(cur == 26 && k !=0)
        return;
    if(k==0)
    {
        int total = 0;
        for(int i=0;i<n;i++)
        {
            if(check(str[i],arr) == true)
                total++;
        }
        if(max_total < total)
            max_total = total;
        return;
    }
    else {
        
        arr[cur]=true;
        run(str,n,k-1,cur+1,arr);
        arr[cur]=false;
        run(str,n,k,cur+1,arr);
        
    }
    
}


int main(void)
{
    int n, k;
    cin >> n >>k;
    string str[n];
    for(int i=0;i<n;i++)
        cin >> str[i];

    bool arr[26] = {false,};
    if(k>=5)
    {
        arr['a'-'a']=true;
        arr['n'-'a']=true;
        arr['t'-'a']=true;
        arr['i'-'a']=true;
        arr['c'-'a']=true;
        go(str,n,k-5,0,arr);
    }
    else {
        run(str,n,k,0,arr);
    }

    

    go(str,n,k-5,0,arr);

    cout << max_total << endl;

    return 0;



}
