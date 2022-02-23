#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first>b.first;
}

int main(void) {
    int N, K;
    bool check[26] = {false,};
    cin >> N >> K;
    string str[N];
    vector< pair<int,int> > alpha;
    for(int i=0;i<26;i++)
    {
        pair<int,int> a;
        a.first = 0;
        a.second = i;
        alpha.push_back(a);
    }
    for(int i=0;i<N;i++)
    {
        cin >> str[i];
        for(int j=0;j<str[i].length();j++)
        {
            alpha[str[i][j]-'a'].first++;
        }
    }
    sort(&alpha[0],&alpha[26],compare);
    for(int i=0;i<K;i++)
        check[alpha[i].second] = true;
    int score = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<str[i].length();j++)
        {
            if(check[str[i][j]-'a']==false)
                break;
            if(j==str[i].length()-1)
                score++;

        }
    }
    cout << score << endl;
    return 0;

}
