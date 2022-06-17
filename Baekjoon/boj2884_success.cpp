#include <iostream>

using namespace std;

int main(void)
{
    int hour, min;
    cin >> hour >> min;
    int total = hour*60 + min;
    total -= 45;
    if(total < 0)
        total+=60*24;
    hour = total/60;
    min = total - hour*60;
    cout << hour << " " << min << endl;
    return 0;
}
