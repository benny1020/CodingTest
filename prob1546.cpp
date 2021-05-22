#include <iostream>

using namespace std;

int main(void)
{
    int num;
    cin >> num;
    double arr[num];
    double max = 0;
    double total = 0;
    for(int i=0;i<num;i++)
    {
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    for(int i=0;i<num;i++)
        arr[i] = (arr[i]/max)*100;


    for(int i=0;i<num;i++)
        total += arr[i];
        
    cout << total/(double)num << endl;

    return 0;


}
