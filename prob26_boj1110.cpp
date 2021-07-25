#include <iostream>

using namespace std;

int cycle_num(int num)
{
    int k1 = num/10;
    int k2 = num - k1*10;

    int k3 = (k1+k2)%10;

    return k2*10+k3;
}



int main(void)
{
    int num;
    cin >> num;
    int tmp = num;
    int count = 0;
    //cout << cycle_num(num) << endl;
    tmp = cycle_num(tmp);
    count++;
    while(tmp!=num)
    {
        tmp = cycle_num(tmp);
        count++;
    }
    cout << count << endl;
    return 0;


}
