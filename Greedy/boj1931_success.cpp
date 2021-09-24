#include <iostream>
#include <algorithm>

using namespace std;

typedef struct meeting
{
    int start;
    int end;
}meeting;

bool compare(meeting a, meeting b)
{
    if (a.end == b.end)
    {
        return a.start<b.start;
    }
    return a.end < b.end;
}



int main(void)
{
    int num;
    cin >> num;
    meeting meet_arr[num];
    int meet_num;
    int tmp_end;

    for(int i=0;i<num;i++)
        cin >> meet_arr[i].start >> meet_arr[i].end;

    //sort_meeting(&meet_arr);
    sort(meet_arr,meet_arr+num,compare);

    tmp_end = meet_arr[0].end;
    meet_num=1;
    for(int i=1;i<num;i++)
    {
        if(meet_arr[i].start>=tmp_end)
        {
            tmp_end = meet_arr[i].end;
            meet_num+=1;
            //cout << start[i]<<endl;
        }
    }
    cout << meet_num << endl;

    return 0;


}
