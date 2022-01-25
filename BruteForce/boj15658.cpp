#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_num = -999999999;
int min_num = 999999999;

void go(vector<int> a, int index, int cur, int plus, int minus, int mul, int div)
{
    if(index == a.size()-1)
    {

        if( cur < min_num)
            min_num = cur;

        if(cur > max_num)
            max_num = cur;

        return;
    }

    else
    {


        if(minus != 0 )
            go(a,index+1,cur-a[index+1],plus,minus-1,mul,div);

        if(div != 0)
            go(a,index+1,cur/a[index+1],plus,minus,mul,div-1);

        if(plus != 0)
            go(a,index+1,cur+a[index+1],plus-1,minus,mul,div);

        if(mul != 0)
            go(a,index+1,cur*a[index+1],plus,minus,mul-1,div);

    }
}

int main(void)
{
    int num,plus,minus,mul,div;
    cin >> num;

    vector<int> a(num);

    for(int i=0;i<num;i++)
        cin >> a[i];

    cin >> plus >> minus >> mul >> div;

    go(a,0,a[0],plus,minus,mul,div);


    cout << max_num << endl << min_num<<endl;
    return 0;




}
