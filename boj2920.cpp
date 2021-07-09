#include <iostream>

using namespace std;

int main(void)
{
    int arr[8];
    bool asc_flag = false;
    bool dsc_flag = false;

    for (int i=0;i<8;i++)
        cin >> arr[i];
    for(int i=0;i<7;i++)
    {
        if(arr[i]<arr[i+1])
            asc_flag = true;
        else
        {
            asc_flag = false;
            break;
        }
    }
    for(int i=0;i<7;i++)
    {
        if(arr[i]>arr[i+1])
            dsc_flag = true;
        else
        {
            dsc_flag = false;
            break;
        }
    }

    if( asc_flag == false && dsc_flag == false)
    {
        cout << "mixed" << endl;
        return 0;
    }
    if( asc_flag == true)
        cout << "ascending" << endl;
    if(dsc_flag == true)
        cout << "descending" << endl;
    return 0;
}
