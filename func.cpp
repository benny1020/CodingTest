#include <iostream>

using namespace std;

int main(void)
{
    int num = 7;
    int * ptr = &num;
    int ** dptr = &ptr;
    cout << **dptr << endl;
}
